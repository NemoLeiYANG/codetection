(MODULE
  CODETECTION
  (WITH
    QOBISCHEME
    XLIB
    PARSER
    PREGEXP
    CODETECTIONLIB-SC
    TOOLLIB-MATLAB
    TOOLLIB-C-BINDINGS
    EASY-FFI)
  (MAIN MAIN))

(include "QobiScheme.sch")
(include "toollib-c-macros.sch")
(include "codetection.sch")
(c-include "codetectionlib-c.h")
(c-include "inference.h")

(set! *program* "codetection")
(set! *panic?* #f)

(define *try-hard?* #f)
(define *single-video?* #f)
(define *n-orientations* 4)
(define *sample-frames-n* 20)
(define *objects* '())

;;;;;;;;; timing

(define (time-thunk format-string thunk)
 (let* ((start (current-time))
	(result (thunk))
	(end (current-time))
	(precision 2)
	(length
	 (if (< (- end start) 1) ;; 0.xx
	     (+ 2 precision)
	     (inexact->exact
	      (floor (+ (+ (/ (log (- end start))
			      (log 10)) 1) 1 precision))))))
  (format #t format-string
	  (number->string-of-length-and-precision (- end start) length precision))
  result))

(define *time-depth* 0)

(define-macro time
 (lambda (form expander)
  (expander `(time-thunk ,(second form) (lambda () ,(third form))) expander)))

(define-macro time-code
 (lambda (form expander)
  (expander `(time-thunk (format #f "~a~~a : ~a~%"
				 (make-string *time-depth* #\+)
				 ,(format #f "~a" (second form)))
			 (lambda ()
			  (set! *time-depth* (+ *time-depth* 1))
			  (let ((ret ,(second form)))
			   (set! *time-depth* (- *time-depth* 1))
			   ret)))
	    expander)))

(define (frames->video frames video-path downsample)
 (unless (file-exists? "/tmp/buffer")
  (system "mkdir -p /tmp/buffer"))
 (for-each-indexed
  (lambda (frame i)
   (when (zero? (modulo i downsample))
    (let ((buffer-path (format #f "/tmp/buffer/frame-~a-~a.png"
			       (getpid) (number->padded-string-of-length (quotient i downsample) 6))))
     (imlib:save-image frame buffer-path))))
  frames)
 (system
  (format
   #f
   "ffmpeg -y -framerate 30 -i /tmp/buffer/frame-~a-%06d.png -r 30 -pix_fmt yuv420p ~a.mp4 > /dev/null 2>&1"
   (getpid) video-path))
 (system "rm -f /tmp/buffer/frame-*.png"))

;;;;;;;;; compute proposals from matlab functions ;;;;;;;;;;;;

(define (video->frames video-path)
 (let ((ffmpeg-video (ffmpeg-open-video video-path)))
  (let loop ((frames '())
	     (start #t))
   (if (or start (ffmpeg-next-frame! ffmpeg-video))
       (loop (cons (ffmpeg-video-frame-data-as-imlib ffmpeg-video) frames) #f)
       (begin
	(ffmpeg-close-video ffmpeg-video)
	(reverse frames))))))

(define (imlib-frames->matlab-matrices frames matrices-name)
 (let* ((one-frame (first frames))
	(height (imlib:height one-frame))
	(width (imlib:width one-frame)))
 (start-matlab!)
 (matlab (format #f "~a=zeros(~a,~a,~a,~a,'uint8');"
		 matrices-name height width 3 (length frames)))
 (for-each-indexed
  (lambda (frame i)
   ;;(format #t "converting imlib ~a/~a to matlab matrix...~%" i tt)
   (with-temporary-file
    "/tmp/imlib-frame.ppm"
    (lambda (tmp-frame)
     ;; write scheme frame to file
     (imlib:save-image frame tmp-frame)  ;; much more efficient than (write-pnm)
     ;; read file as matlab frame
     (matlab (format #f "frame=imread('~a');" tmp-frame))   
     (matlab (format #f "~a(:,:,:,~a)=uint8(frame);" matrices-name (+ i 1))))))
  frames)))

(define (proposals-with-frames top-k frames video-dir on-the-fly? write?)
 (start-matlab!)
 ;; check whether precomputed boxes are available
 ;; if yes, just read them from disk
 (unless on-the-fly?
  (matlab
   (format
    #f
    "[computed,bboxes_t,bboxes]=check_proposals(~a,'~a');"
    top-k video-dir)))
 ;; otherwise  
 (when (or on-the-fly?
	   (zero? (x (x (matlab-get-variable "computed")))))
  (imlib-frames->matlab-matrices frames "frames")
  ;; call proposals
  (format #t "computing proposals on the fly (matlab) for video ~a...~%" (strip-directory video-dir))
  (matlab (format #f "[bboxes_t,bboxes]=proposals(~a,frames,'~a',~a);"
		  top-k video-dir (if write? 1 0))))
 ;; convert matlab variables to scheme
 (map-n (lambda (t)
	 ;; box coordinates minus 1 because matlab index starts from 1
	 (matlab (format #f "tmp=bboxes(:,:,~a);tmp(:,1:4)=tmp(:,1:4)-1;" (+ t 1)))
	 (matlab-get-variable "tmp"))
	(x (x (matlab-get-variable "bboxes_t")))))

(define (reselect-boxes-and-tracking boxes frames pool-size top-k video-path tracks-on-the-fly?)
 (let* ((video-dir (strip-extension video-path))
	(tracks-path (string-append video-dir "/codetection-data/tracks.sc"))
	(tracks (if (file-exists? tracks-path)
		    (read-object-from-file tracks-path)
		    #f))
	(tracks
	 (if (or tracks-on-the-fly?
		 (or (not tracks)
		     (not (list? tracks))) ;; end-of-file
		 (< (length (first tracks)) top-k))
	     (begin
	      (format #t "reselecting boxes for ~a...~%" video-path)
	      ;; sampling top-k boxes and propogating them across the video
	      (let* ((boxes-c (easy-ffi:double-to-c 3 boxes))
		     (entry-n 7)
		     (new-boxes (map-n (lambda _ (make-matrix top-k entry-n 0)) (length boxes)))
		     (new-boxes-c (easy-ffi:double-to-c 3 new-boxes))
		     (frames-c (easy-ffi:longunsigned-to-c 1 frames))
		     (_ ((c-function void ("reselect_proposals" pointer pointer int int int int pointer))
			 boxes-c frames-c (length boxes) pool-size top-k entry-n new-boxes-c))
		     ;; each box has 6 entries: x1 y1 x2 y2 flow saliency
		     (new-boxes (easy-ffi:double-from-c (list (length boxes) top-k entry-n) 
							'(list list list) new-boxes-c)))
	       (easy-ffi:free 3 boxes boxes-c)
	       (easy-ffi:free 3 new-boxes new-boxes-c)
	       (easy-ffi:free 1 frames frames-c)
	       ;; this will overwrite the old tracks
	       (write-object-to-file new-boxes tracks-path)
	       new-boxes))
	     (begin
	      (format #t "reading precomputed tracks for ~a...~%" video-path)
	      (map (lambda (boxes) (take top-k boxes)) tracks)))))
  ;; only for debugging
  (when *single-video?*
   (format #t "rendering boxes video...~%")
   (frames->video
    (map (lambda (boxes frame)
	  (begin
	   (for-each
	    (lambda (box)	  
	     (let* ((x (first box))
		    (y (second box))
		    (w (+ (- (third box) x) 1))
		    (h (+ (- (fourth box) y) 1)))
	      (imlib:draw-rectangle frame x y w h '#(0 0 0) 3)))
	    boxes)
	   frame))
	 ;; (transpose-list-of-lists
	 ;;  (map
	 ;;   (lambda (track)
	 ;;    (let* ((frames-n (length track))
	 ;; 	   (top-lefts (map (lambda (b) (take 2 b)) track))
	 ;; 	   (bottom-rights (map (lambda (b) (take 2 (drop 2 b))) track))
	 ;; 	   (smoothed-top-lefts
	 ;; 	    (map (lambda (pt) (list (inexact->exact (round (first pt)))
	 ;; 				    (inexact->exact (round (second pt)))))
	 ;; 		 (evenly-pick-m (trace->splines top-lefts (* 10 frames-n)) frames-n)))
	 ;; 	   (smoothed-bottom-rights
	 ;; 	    (map (lambda (pt) (list (inexact->exact (round (first pt)))
	 ;; 				    (inexact->exact (round (second pt)))))
	 ;; 		 (evenly-pick-m (trace->splines bottom-rights (* 10 frames-n)) frames-n))))
	 ;;     (map append smoothed-top-lefts smoothed-bottom-rights)))
	 ;;   (transpose-list-of-lists tracks)))
	 tracks
	 frames)
    "/tmp/buffer/boxes"
    1)
   (exit))
  tracks))

(define (get-pairs nn)
 (sort (all-pairs (map-n identity nn))
       (lambda (p q)
	(cond
	 ((< (first p) (first q)) #t)
	 ((= (first p) (first q)) (< (second p) (second q)))
	 (else #f)))
       identity))

(define (similarity-between-videos-matlab frames-movie1 frames-movie2 boxes-movie1 boxes-movie2
					  video-dir1 video-dir2 frames-n top-k)
 (if *try-hard?*
     (begin
      (start-matlab!)
      ;; first check if the similarity is precomputed
      (matlab (format #f "[computed,simi] = check_similarity_between_videos('~a','~a',~a,~a,~a);"
		      video-dir1 video-dir2 frames-n top-k *n-orientations*))
      (when (zero? (x (x (matlab-get-variable "computed"))))
       
       (format #t "computing matlab similarity on the fly between ~a and ~a...~%" video-dir1 video-dir2)
       (imlib-frames->matlab-matrices frames-movie1 "frames1") ;; frames-n by 1
       (imlib-frames->matlab-matrices frames-movie2 "frames2") ;; frames-n by 1
       (scheme->matlab! "boxes1" (list-of-lists->matrix (join boxes-movie1)))  ;; (frames-n)*(top-k) by 4
       (scheme->matlab! "boxes2" (list-of-lists->matrix (join boxes-movie2)))  ;; (frames-n)*(top-k) by 4
       (matlab (format #f "simi=similarity_between_videos(frames1,frames2,boxes1,boxes2,'~a','~a',~a,~a,~a);"
		       video-dir1 video-dir2 frames-n top-k *n-orientations*)))
      (map-n (lambda (t)
	      (map-n (lambda (i)	 
		      (matlab (format #f "tmp=simi(:,:,~a,~a);" (+ i 1) (+ t 1)))
		      (matlab-get-variable "tmp"))
		     *n-orientations*))
	     frames-n))
     (map-n
      (lambda _
       (map-n
	(lambda _
	 (make-matrix top-k top-k 0))
	*n-orientations*))
      frames-n)))
     
(define (similarity-between-videos-c frames-movie1 frames-movie2 boxes-movie1 boxes-movie2
				     video-dir1 video-dir2 frames-n top-k)
 (let* ((similarities-zero (map-n
			    (lambda _
			     (map-n
			      (lambda _
			       (make-matrix top-k top-k 0))
			      *n-orientations*))
			    frames-n))
	(similarities-c (easy-ffi:double-to-c 4 similarities-zero))
	(computed? ((c-function int ("check_similarity_between_videos"
				     string string int int pointer))
		    video-dir1 video-dir2 frames-n top-k similarities-c)))
  (when (zero? computed?)
   (format #t "computing c similarity on the fly between ~a and ~a...~%" video-dir1 video-dir2)
   (let* ((frames-movie1-c (easy-ffi:longunsigned-to-c 1 frames-movie1))
	  (frames-movie2-c (easy-ffi:longunsigned-to-c 1 frames-movie2))	   
	  (boxes-movie1-c (easy-ffi:double-to-c 3 boxes-movie1))
	  (boxes-movie2-c (easy-ffi:double-to-c 3 boxes-movie2)))
    ((c-function void ("similarity_between_videos"
		       pointer pointer pointer pointer string string int int pointer))
     frames-movie1-c frames-movie2-c boxes-movie1-c boxes-movie2-c
     video-dir1 video-dir2 frames-n top-k similarities-c)
    (easy-ffi:free 1 frames-movie1 frames-movie1-c)
    (easy-ffi:free 1 frames-movie2 frames-movie2-c)     
    (easy-ffi:free 3 boxes-movie1 boxes-movie1-c)
    (easy-ffi:free 3 boxes-movie2 boxes-movie2-c)))

  (let ((similarities (easy-ffi:double-from-c (list frames-n *n-orientations* top-k top-k)
					      '(list list vector vector)
					      similarities-c)))    
   (easy-ffi:free 4 similarities similarities-c)
   similarities)))

(define (similarity-among-videos-sampled similarity-function frames-menu
					 boxes-menu video-dirs-menu frames-n top-k mode)
 (let* ((nn (length frames-menu))
	(pairs (case mode
		((1) (append (map-n (lambda (i) (list i (+ i 1))) (- nn 1))
			     (list (list 0 (- nn 1)))))
		(else (get-pairs nn)))))
  (map
   (lambda (pair)
    (similarity-function
     (list-ref frames-menu (first pair))
     (list-ref frames-menu (second pair))
     (list-ref boxes-menu (first pair))
     (list-ref boxes-menu (second pair))
     (list-ref video-dirs-menu (first pair))
     (list-ref video-dirs-menu (second pair))
     frames-n
     top-k))
   pairs)))

(define (similarity-among-videos frames-menu boxes-menu video-dirs-menu frames-n top-k mode)
 (if (= (length frames-menu) 1)
     (list '() '() 0)
     (begin
      (let* ((nn (length frames-menu))
	     (mm (case mode
		  ((1) nn)
		  (else (/ (* nn (- nn 1)) 2))))
	     (tts (map length frames-menu))
	     (frames-n (if (> frames-n (apply min tts))
			   (panic "fuck up")
			   frames-n))
	     (indices-menu (map (lambda (tt)
				 (evenly-pick-m (map-n identity tt) frames-n)) tts))
	     (sampled-frames-menu
	      (map (lambda (frames-movie indices)
		    (map (lambda (idx) (list-ref frames-movie idx)) indices))
		   frames-menu indices-menu))
	     (sampled-boxes-menu
	      (map (lambda (boxes-movie indices)
		    (map (lambda (idx) (list-ref boxes-movie idx)) indices))
		   boxes-menu indices-menu)))
       (format #t "mm = ~a~%" mm)
       (format #t "~a~%" indices-menu)
       (format #t "~a~%" (map length sampled-frames-menu))
     
       (list (map (lambda (sim sim-matlab) ;; per pair
		   (map (lambda (m1 m2) ;; per timestamp
			 ;; element-wise maximum
			 (reduce elementwise-matrix-max
				 (map (lambda (m1-i m2-i) ;; per orientation		       
				       (k*m
					(if *try-hard?* 0.5 1)					
					(m+ m1-i m2-i)))
				      m1 m2)
				 '#()))
			sim sim-matlab))
		  (similarity-among-videos-sampled
		   similarity-between-videos-c
		   sampled-frames-menu
		   sampled-boxes-menu
		   video-dirs-menu
		   frames-n
		   top-k
		   mode)	   
		  (similarity-among-videos-sampled
		   similarity-between-videos-matlab
		   sampled-frames-menu
		   sampled-boxes-menu
		   video-dirs-menu
		   frames-n
		   top-k
		   mode))
	     indices-menu
	     frames-n)))))

(define (get-average-object-appearance boxes ts proposals-menu frames-menu)
 (let* ((boxes-menu (let loop ((idx 0)
			       (boxes-menu '())
			       (ts ts))
		     (if (null? ts)
			 (reverse boxes-menu)
			 (loop (+ idx (first ts))
			       (cons (sublist boxes idx (+ idx (first ts))) boxes-menu)
			       (rest ts)))))
	(boxes-menu (map (lambda (boxes proposals)
			  (map (lambda (box proposals-per-frame)
				(list-ref proposals-per-frame box))
			       boxes proposals))
			 boxes-menu proposals-menu))
	(frames-menu-c (easy-ffi:longunsigned-to-c 2 frames-menu))
	(boxes-menu-c (easy-ffi:double-to-c 3 boxes-menu))
	(ts-c (easy-ffi:int-to-c 1 ts)))
  
  ((c-function void ("average_object_appearance" pointer pointer int pointer))
   frames-menu-c boxes-menu-c (length frames-menu) ts-c)
  (easy-ffi:free 2 frames-menu frames-menu-c)
  (easy-ffi:free 3 boxes-menu boxes-menu-c)
  (easy-ffi:free 1 ts ts-c)))

;;;;;;;;;; codetection inference with BP ;;;;;;;;;;

(define bp-sentences-inference
 (c-function double ("bp_sentences_inference"
		     pointer pointer pointer pointer pointer int pointer pointer pointer
		     pointer int pointer pointer pointer int int pointer))) 

;; \theta*flow+\gamma*similarity+1*predicate
;; darpa-wrap ./codetection -video /aux/yu239/new4/MVI_0469.mov

(define-command
 (main (exactly-one
	;; for generating proposals
	("video" single-video?
	 (video-path "video-path" string-argument ""))
	;; for generating similarity
	("video2" two-videos?
	 (video-path1 "video-path1" string-argument "")
	 (video-path2 "video-path2" string-argument ""))
	;; for codetection
	("videos" multiple-videos?
	 (videos-input-file "file" string-argument "")
	 (mode "mode" string-argument "complete")) ;; support "loop" and "complete"
	)
       (at-most-one
	("top-k" top-k? (top-k "top-k" integer-argument 240)))
       ;; needswork: the quality of first pool-size boxes is ordered by the proposal score
       ;; pool-size is NOT the bottleneck for the efficiency
       (at-most-one
	("pool-size" pool-size? (pool-size "pool-size" integer-argument 500)))
       (at-most-one
	("alpha" alpha? (alpha "weightalpha" real-argument 0)))
       (at-most-one
	("theta" theta? (theta "weighttheta" real-argument 1)))
       (at-most-one
	;; average per frame 1;  aggeragate over video 2
	("gamma" gamma? (gamma "weightgamma" real-argument 2))) 
       (at-most-one ("no-track-constraint" no-track-constraint?))
       (at-most-one ("on-the-fly" on-the-fly?))
       (at-most-one ("tracks-on-the-fly" tracks-on-the-fly?))
       (at-most-one ("up-right" up-right-objects?))
       (at-most-one ("write" write?))
       (at-most-one ("try-hard" try-hard?))
       (at-most-one ("only-proposals" only-proposals?))
       (exactly-one
	("with-sentence" with-sentence?)
	("with-movement" with-movement?)
	("without-sentence" without-sentence?))       
       (at-most-one
	("output-tracks-dir" write-tracks? (output-tracks-dir "directory" string-argument ""))))

 ;;;;;;;;;;;;;;;;;;;;;; set global variables according to input arguments ;;;;;;;;;;;;;;;;;; 
 (set! *n-orientations* (if up-right-objects? 1 4))
 ((c-function void ("set_n_orientations" int)) *n-orientations*)
 (set! *try-hard?* try-hard?) ;; try hard with phow similarity from matlab (slow)
 (set! *single-video?* single-video?)
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  

 (newline)
 (format #t "only-proposals?                 ~a~%" only-proposals?)
 (format #t "pool-size:                      ~a~%" pool-size)
 (format #t "top-k:                          ~a~%" top-k)
 (format #t "theta (f score):                ~a~%" theta)
 (format #t "alpha (temporal coherence):     ~a~%" alpha)
 (format #t "gamma (similarity):             ~a~%" gamma)
 (format #t "sentence-directed?:             ~a~%" (cond
						    (with-sentence? "with-sentence")
						    (with-movement? "with-movement")
						    (else "without-sentence")))
 (format #t "track-constraint?:              ~a~%" (not no-track-constraint?))
 (format #t "proposals-on-the-fly?:          ~a~%" on-the-fly?)
 (format #t "tracks-on-the-fly?:             ~a~%" tracks-on-the-fly?)
 (format #t "write-proposals?:               ~a~%" write?)
 (format #t "try-hard?:                      ~a~%" try-hard?)
 (format #t "handle-rotation?:               ~a~%" (not up-right-objects?))
 (format #t "output-tracks-dir:              ~a~%" output-tracks-dir)
 (newline)

 ;;;; to get random result everytime, uncomment this line;
 ;;;; comment it for the same result every running
 ;;(randomize)

 ((c-function void ("set_track_constraint" int))
  (if no-track-constraint? 0 1))

 ((c-function void ("set_sentence_directed" int))
  (cond
   (with-sentence? 0)
   (with-movement? 1)
   (else 2)))

 ((c-function void ("set_gamma" double)) gamma)

 (set! mode (cond
	     ((equal? mode "loop") 1)
	     ((equal? mode "complete") 2)
	     (else (panic "wrong mode"))))

 (let* ((video-paths-and-sentences
	 (sort
	  (cond
	   (single-video? `((,video-path "" "")))
	   (two-videos? `((,video-path1 "" "")
			  (,video-path2 "" "")))
	   (else
	    ;; videos-input-file: (e.g.) house-1_1
	    (let* ((dataset-id (first (pregexp-split "-" videos-input-file)))		   
		   (corpus (second (pregexp-split "-" videos-input-file)))
		   (set (first (pregexp-split "_" corpus)))
		   (fold (second (pregexp-split "_" corpus)))
		   (dir "/home/yu239/darpa-collaboration/sentence-codetection/videos-files/")
		   (corpus
		    (read-object-from-file (format #f "~a/videos-~a-amt-~a.sc" dir dataset-id set))))
	     (set! *objects* (if (string=? dataset-id "house")
				 *objects-house*
				 *objects-cad*))
	     (map (lambda (v)
		   (assoc (format #f "/net/zhineng/aux/yu239/~a/~a.avi" dataset-id v)
			  corpus))			 
		  (read-file (format #f "~a/~a/folds/~a.txt" dir dataset-id fold)))
	     )))
	  string<?
	  first))
	(_ (begin
	    ;; sort the videos by names so that we don't
	    ;; compute and store duplicate similarities
	    (format #t "VIDEOS (sorted in alphabet order):~%")
	    (pp video-paths-and-sentences)
	    (newline)))
	(video-paths (map first video-paths-and-sentences))
	(sentences (map second video-paths-and-sentences))
	(plain-sentences (map third video-paths-and-sentences))
	(frames-menu
	 (map (lambda (path) (video->frames path)) video-paths))
	(_ (let* ((one-frame (first (first frames-menu)))
		  (height (exact->inexact (imlib:height one-frame)))
		  (width (exact->inexact (imlib:width one-frame))))
	    ((c-function void ("set_imw" double)) width)
	    ((c-function void ("set_imh" double)) height)))
	(proposals-menu
	 (time-code
	  (map (lambda (frames-movie video-path)
		(proposals-with-frames
		 pool-size frames-movie (strip-extension video-path) on-the-fly? write?))
	       frames-menu video-paths))))

  ;; only-proposals? is used to generate and store proposals only
  (unless only-proposals?
   (let* ((proposals-menu
	   (map (lambda (proposals-movie frames-movie video-path)
		 (reselect-boxes-and-tracking proposals-movie frames-movie pool-size top-k
					      video-path tracks-on-the-fly?))
		proposals-menu frames-menu video-paths))

	  (_ (when two-videos?
	      (similarity-among-videos
	       frames-menu proposals-menu (map strip-extension video-paths)
	       *sample-frames-n* top-k mode)
	      (exit)))
	  
	  (f-menu
	   (map (lambda (proposals-movie)
		 (map (lambda (proposals) (map (lambda (p) (* theta (fifth p))) proposals))
		      proposals-movie))
		proposals-menu))
	  (u-menu
	   (map (lambda (proposals-movie)
		 (map (lambda (proposals) (map sixth proposals))
		      proposals-movie))
		proposals-menu))
	  (h-menu
	   (map (lambda (proposals-movie)
		 (map (lambda (proposals) (map seventh proposals))
		      proposals-movie))
		proposals-menu))	  
	  (f-menu-c (easy-ffi:double-to-c 3 f-menu))
	  (u-menu-c (easy-ffi:double-to-c 3 u-menu))
	  (h-menu-c (easy-ffi:double-to-c 3 h-menu))
	  (ts (map length f-menu))
	  (ts-c (easy-ffi:int-to-c 1 ts))
	  ;; (predicates-and-objects
	  ;;  (sentences->universal-predicates-and-objects sentences))
	  (predicates-and-objects
	   (theta-roles->universal-predicates-and-objects sentences *objects*))
	  (_ (format #t "~a ~%" predicates-and-objects))
	  (predicates (first predicates-and-objects))
	  (objects (second predicates-and-objects))
	  (video-ids (map last objects))
	  (grouped-objects
	   ;; remove object names
	   (map (lambda (group) (map (lambda (o) (list (first o) (third o))) group))
		(group-by second objects)))
	  
	  ;;;;;;;;;;;;;;;;;;;;; similarity between tracks ;;;;;;;;;;;;;;;;;;;;;
	  (ns (map length grouped-objects))
	  (g2-indices-framesn-groups
	   (map (lambda (object-group)
		 (;;similarity-among-frame-movies ;; (the old interface)
		  similarity-among-videos
		  (map (lambda (obj) (list-ref frames-menu (second obj))) object-group)
		  (map (lambda (obj) (list-ref proposals-menu (second obj))) object-group)
		  (map (lambda (obj) (strip-extension (list-ref video-paths (second obj)))) object-group)
		  *sample-frames-n*
		  top-k
		  mode))
		grouped-objects))
	  (mm-groups
	   (map (lambda (g2-indices-framesn-menu)
		 (length (first g2-indices-framesn-menu)))
		g2-indices-framesn-groups))
	  (g2-groups
	   (map (lambda (g2-indices-framesn-menu mm nn)
		 (map (lambda (pair)
		       (map (lambda (m)
			     ;; gamma is specified for the case when f and g2 has approximately
			     ;; same frequency in the cost function
			     (matrix->list-of-lists (k*m (* gamma (/ nn mm)
							    ) m))) pair))
		      (first g2-indices-framesn-menu)))
		g2-indices-framesn-groups mm-groups ns))

	  (_ (and #t
		  (format
		   #t
		   " f-max:~a f-median:~a f-min:~a~% u-max:~a u-median:~a u-min:~a~% h-max:~a h-median:~a h-min:~a~%"
		   (apply max (join (join f-menu)))
		   (median (join (join f-menu)))
		   (apply min (join (join f-menu)))
		   (apply max (join (join u-menu)))
		   (median (join (join u-menu)))
		   (apply min (join (join u-menu)))
		   (apply max (join (join h-menu)))
		   (median (join (join h-menu)))
		   (apply min (join (join h-menu)))
		   )))
	  (_ (and #f (format #t "g2-median:~a~%"
			     (median (join (join (join (join g2-groups)))))
			     )))
	  
	  ;;(indices-group (map second g2-indices-framesn-groups))
	  (framesn-group (map third g2-indices-framesn-groups))  
	  (g2-c (easy-ffi:double-to-c 5 g2-groups))
	  (mm-c (easy-ffi:int-to-c 1 mm-groups))
	  (ns-c (easy-ffi:int-to-c 1 ns))
	  (video-ids-c (easy-ffi:int-to-c 1 video-ids))
	  ;;(indices-group-c (easy-ffi:int-to-c 3 indices-group))
	  (frames-n-c (easy-ffi:int-to-c 1 framesn-group))
	  (predicates-c (easy-ffi:int-to-c 2 predicates))
	  (grouped-objects (map (lambda (group) (map first group)) grouped-objects))
	  (grouped-objects-c (easy-ffi:int-to-c 2 grouped-objects))
	  (boxes (join (map (lambda (obj)
			     (map-n (lambda _ 0)
				    (list-ref ts (last obj)))) objects)))
	  (boxes-c (easy-ffi:int-to-c 1 boxes))
	  (boxes-menu-c (easy-ffi:double-to-c 4 proposals-menu))
	  (score (bp-sentences-inference
		  f-menu-c u-menu-c h-menu-c boxes-menu-c g2-c (length grouped-objects) ts-c
		  mm-c frames-n-c predicates-c (length predicates) video-ids-c
		  grouped-objects-c ns-c mode top-k boxes-c)) 
	  (boxes
	   (easy-ffi:int-from-c (list (length boxes)) '(list) boxes-c)))

    ;; free memory
    (easy-ffi:free 3 f-menu f-menu-c)
    (easy-ffi:free 3 u-menu u-menu-c)
    (easy-ffi:free 3 h-menu h-menu-c)
    (easy-ffi:free 1 boxes boxes-c)
    (easy-ffi:free 1 ts ts-c)
    (easy-ffi:free 5 g2-groups g2-c)
    (easy-ffi:free 1 mm-groups mm-c)
    (easy-ffi:free 1 ns ns-c)
    (easy-ffi:free 1 video-ids video-ids-c)
    ;;(easy-ffi:free 3 indices-group indices-group-c)
    (easy-ffi:free 1 framesn-group frames-n-c)
    (easy-ffi:free 4 proposals-menu boxes-menu-c)
    (easy-ffi:free 2 predicates predicates-c)
    (easy-ffi:free 2 grouped-objects grouped-objects-c)
    
    ;; ;; render object appearance
    ;; (get-average-object-appearance boxes ts proposals-menu frames-menu)

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;; draw tracks on video frames ;;;;;;;;;;;;;;;;;;;;;
    (let ((colors (map (lambda _ (vector (modulo (rand) 256)
					 (modulo (rand) 256)
					 (modulo (rand) 256)))
		       grouped-objects)))
     (let loop ((objects objects)
		(boxes boxes))
      (unless (null? objects)
       (let* ((object (first objects))
	      (group-id
	       (position (find-if (lambda (g) (member (first object) g))
				  grouped-objects)
			 grouped-objects))
	      (video-id (third object))
	      (color (list-ref colors group-id))
	      (name (symbol->c-string (second object))))
	(for-each (lambda (frame pool b)
		   (let* ((box (list-ref pool b))
			  (x (first box))
			  (y (second box))
			  (w (+ (- (third box) x) 1))
			  (h (+ (- (fourth box) y) 1)))
		    (imlib:draw-rectangle frame x y w h color 3)
		    (imlib:text-draw frame x y name color 15)
		    (imlib:text-draw frame 10 10 (strip-directory (list-ref video-paths video-id))
				     '#(0 0 0) 10)
		    (imlib:text-draw frame 10 30 (list-ref plain-sentences video-id) '#(0 0 0) 10)
		    ))
		  (list-ref frames-menu video-id)
		  (list-ref proposals-menu video-id)
		  (take (list-ref ts video-id) boxes))
       (loop (rest objects)
	     (drop (list-ref ts video-id) boxes))))))

    ;;;;;;;;;;;;;;;;;;;;;;;;;;; write tracks and video ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    (let ((local-result-dir
	   (if (not write-tracks?)
	       "/tmp/buffer"
	       (format #f "~a/~a-~a-~a-~a" output-tracks-dir (hostname) (getpid) gamma theta))))
     (system (format #f "mkdir -p ~a" local-result-dir))
     ;; write track-rendered video
     (format #t "generating result video...~%")
     (frames->video (join frames-menu)
		    (format #f "~a/tracked" local-result-dir)
		    1)
     ;; write tracks
     (format #t "writing tracks to file...~%")     
     (write-object-to-file            
      (let loop ((objects objects)
		 (boxes boxes)
		 (tracks-menu (map-n (lambda _ '()) (length frames-menu))))
       (if (null? objects)
	   tracks-menu
	   (let* ((object (first objects))
		  (video-id (third object))
		  (name (second object))
		  (track
		   (map (lambda (pool b)
			 ;; (x1 y1 x2 y2)
			 (take 4 (list-ref pool b)))
			(list-ref proposals-menu video-id)
			(take (list-ref ts video-id) boxes)))
		  (tracks (list-ref tracks-menu video-id)))	    	    
	    (loop (rest objects)
		  (drop (list-ref ts video-id) boxes)
		  (list-replace tracks-menu
				video-id
				(append tracks (list (vector name track)))
				)))))
      (format #f "~a/tracks.sc" local-result-dir)))
        
    ;; free frames
    (for-each imlib:free-image-and-decache (join frames-menu))))))


       