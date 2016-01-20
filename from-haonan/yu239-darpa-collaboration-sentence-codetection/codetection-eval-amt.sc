(define *objects* '(bowl
		    cabbage
		    squash
		    pineapple
		    cleaner
		    coffee
		    ketchup
		    milk
		    juice
		    cup
		    cooler
		    box
		    watering-pot
		    gas-can
		    bucket
		    jar
		    microwave
		    cereal))

(define *name-mapping*
 '(("jar" "jug")
   ("coffee" "coffee grinder")
   ("cleaner" "mouthwash")))

(define *colors* (map (lambda _ (vector (modulo (rand) 256)
					(modulo (rand) 256)
					(modulo (rand) 256)))
		      *objects*))

;; A frame-IoU measure is defined as a ratio of areas of intersection over
;; union of the ground truth and inferred bounding boxes. A video-IoU is
;; defined as the average of all frame-IoUs. Similarly, a class-IoU is defined
;; as the average of all inferred video-IoUs.

;; b1 - (x11 y11 x12 y12)
;; b2 - (x21 y21 x22 y22)
(define (get-IoU b1 b2)
 (let* ((x11 (first b1))
	(y11 (second b1))
	(x12 (third b1))
	(y12 (fourth b1))
	(x21 (first b2))
	(y21 (second b2))
	(x22 (third b2))
	(y22 (fourth b2))
	(max-x1 (max x11 x21))
	(min-x2 (min x12 x22))
	(max-y1 (max y11 y21))
	(min-y2 (min y12 y22)))
  (if (or (> max-x1 min-x2)
	  (> max-y1 min-y2))
      0
      (let ((intersection-area
	     (* (- min-x2 max-x1) (- min-y2 max-y1)))
	    (b1-area
	     (* (- x12 x11) (- y12 y11)))
	    (b2-area
	     (* (- x22 x21) (- y22 y21))))
       (/ intersection-area 
	  (- (+ b1-area b2-area) intersection-area))))))

;; return the major number in the list
(define (vote lst)
 (if (null? lst)
     '()
     (first (first (sort (group-by identity lst) > length)))))

(define (video->frames video-path)
 (let ((ffmpeg-video (ffmpeg-open-video video-path)))
  (let loop ((frames '())
	     (start #t))
   (if (or start (ffmpeg-next-frame! ffmpeg-video))
       (loop (cons (ffmpeg-video-frame-data-as-imlib ffmpeg-video) frames) #f)
       (begin
	(ffmpeg-close-video ffmpeg-video)
	(reverse frames))))))

(define (frames->video frames video-path downsample)
 (unless (file-exists? "/tmp/buffer")
  (system "mkdir -p /tmp/buffer"))
 (for-each-indexed
  (lambda (frame i)
   (when (zero? (modulo i downsample))
    (let ((buffer-path (format #f "/tmp/buffer/frame-~a-~a.png"
			       (getpid) (number->padded-string-of-length (quotient i downsample) 6))))
     (imlib:save frame buffer-path))))
  frames)
 (system
  (format
   #f
   "ffmpeg -y -framerate 30 -i /tmp/buffer/frame-~a-%06d.png -r 30 -pix_fmt yuv420p ~a.mp4 > /dev/null 2>&1"
   (getpid) video-path))
 (system "rm -f /tmp/buffer/frame-*.png"))

(define (videos-sentences->annotation-pages videos-sentences)
 (join (map (lambda (video-and-sentence)
	     (let* ((video (strip-directory (first video-and-sentence)))
		    (objects
		     (remove-if
		      (lambda (obj)
		       (equal? (x obj) 'person))
		      (remove-duplicates
		       (join (map (o rest rest) (second video-and-sentence))))))
		    (words (pregexp-split " " (third video-and-sentence))))
	      (join
	       (map (lambda (obj)
		     (let* ((word (string-downcase (symbol->string (x obj))))
			    (index (list-ref (all-positions word words) (y obj)))
			    (new-words (list-replace
					words
					index
					(string-append "<mark><strong>" word "</strong></mark>"))))
		      (list (string-append video " " word (number->string (y obj)))
			    (string-join " " new-words))))
		    objects))
	      ))
	    videos-sentences)))

;; aws-raw-results get by ./getResults.sh
(define (parse-amt-results aws-raw-results)
 (let* ((processed-data
	 (rest ;; the first line is data names
	  (map
	   (lambda (line)
	    (remove-if (lambda (e) (null? (fields e)))
		       (pregexp-split "\"" line)))
	   aws-raw-results)))
	(pages-and-annotations
	 (group-by x
		   (map (lambda (data)
			 (vector
			  (strip-extension (strip-directory (find-if (lambda (e) (substring? "html" e)) data)))
			  (split-n 4 (map string->number (fields (last data))))))
			processed-data)))
	(pages-and-annotations
	 (map (lambda (g)
	       (vector (x (first g))
		       (map y g)))
	      pages-and-annotations)))
  ;; check
  ;; each video-object pair should have exactly five annotations
  (for-each
   (lambda (page-and-annotation)
    (unless (= (length (y page-and-annotation)) 5) ;; hard-coded 5 subjects
     (panic "annotation missing"))
    (for-each (lambda (a)
	       (unless (first a) (panic "annotaiton missing")))
	      (y page-and-annotation)))
   pages-and-annotations)
  ;; no problem 
  pages-and-annotations))

(define (webpage->video-and-object-names page)
 (let* ((last-token (last (pregexp-split "-" page)))
	;; hardcoded
	(dash-in-name? (or (substring? "can" last-token)
			   (substring? "pot" last-token)))
	(video-name (string-join
		     "-"
		     (reverse (drop (if dash-in-name? 2 1) (reverse (pregexp-split "-" page))))))
	(object-name (string-join "" (but-last (pregexp-split
						""
						(string-join "-" (reverse (take (if dash-in-name? 2 1)
										(reverse (pregexp-split "-" page)))))
						)))))
  (list video-name object-name)))

(define (render-annotations-per-video video-name dataset)
 (let* ((annotations
	 (read-object-from-file
	  (if (string=? dataset "house")
	      "/net/zhineng/aux/yu239/house/AMT/codetection.results.parsed"
	      "/net/zhineng/aux/yu239/CAD/annotation.sc")))
	(related-annotations
	 (remove-if-not
	  (lambda (a)
	   (substring? video-name
		       (x a)))
	  annotations))
	(frames (video->frames (format #f "/net/zhineng/aux/yu239/~a/~a.avi" dataset video-name))))
  (for-each
   (lambda (annotation)
    (let* ((object-name (second (webpage->video-and-object-names (x annotation))))
	   (object-name
	     (pregexp-replace*
	      "-"
	      (if (assoc object-name *name-mapping*)
		  (second (assoc object-name *name-mapping*))
		  object-name)
	      " "))
	   (tracks (y annotation)))
     (for-each
      (lambda (t)
       (for-each
	(lambda (frame box)
	 (let* ((x (first box))
		(y (second box))
		(w (+ (- (third box) x) 1))
		(h (+ (- (fourth box) y) 1)))
	  (imlib:draw-rectangle frame x y w h '#(0 255 0) 3)
	  (imlib:text-draw2 frame x y object-name '#(0 255 0) 15)
	  ))
	frames
	t))
      tracks)))
   related-annotations)
  (frames->video frames
		 "/tmp/buffer/annotation"
		 1)
  (for-each (lambda (frame)
	     (imlib-context-set-image! frame)
	     (imlib-free-image-and-decache))
	    frames)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define (get-running-job-label results-dir fold-name)
 (with-temporary-file
  "/tmp/running-job.label"
  (lambda (tmp)
   (system (format #f "cd /net/zhineng/aux/yu239/~a/~a; ls > ~a; cd -;"
		   results-dir fold-name tmp))
   (first (read-file tmp)))))

(define (corpus-from-foldname fold-name dataset)
 (let* ((corpus-name
	 (if (substring? dataset fold-name)
	     (last (pregexp-split "-" (first (pregexp-split "_" fold-name))))
	     (first (pregexp-split "_" fold-name))))
	(fold (second (pregexp-split "_" fold-name)))
	(dir "/home/yu239/darpa-collaboration/sentence-codetection/videos-files")
	(corpus (read-object-from-file (format #f "~a/videos-~a-amt-~a.sc" dir dataset corpus-name))))
  (map (lambda (v)
	(assoc (format #f "/net/zhineng/aux/yu239/~a/~a.avi" dataset v)
	       corpus))
       (read-file (format #f "~a/~a/folds/~a.txt" dir dataset fold)))))

(define (tag-video-names-on-tracks results-dir fold-name dataset render-video?)
 (define (tagged-tracks->tracked-video tracks videos)
  (let ((frames-menu
	 (map (lambda (v)
	       (video->frames (format #f "/net/zhineng/aux/yu239/~a/~a.avi" dataset v)))
	      videos)))
   (for-each
    (lambda (t)
     (let* ((video-and-object-names
	     (webpage->video-and-object-names (x t)))
	    (video-id (position (first video-and-object-names) videos))
	    (object-name
	     (pregexp-replace*
	      "-"
	      (if (assoc (second video-and-object-names) *name-mapping*)
		  (second (assoc (second video-and-object-names) *name-mapping*))
		  (second video-and-object-names))
	      " "))
	    ;;	   (color (list-ref *colors* (position (c-string->symbol object-name) *objects*)))
	    (color '#(255 0 0)))
      (for-each
       (lambda (frame box)
	(let* ((x (first box))
	       (y (second box))
	       (w (+ (- (third box) x) 1))
	       (h (+ (- (fourth box) y) 1)))
	 (imlib:draw-rectangle frame x y w h color 3)
	 (imlib:text-draw2 frame x y object-name color 15)
	 ;; (imlib:text-draw2 frame 10 10 (list-ref videos video-id)
	 ;; 		 '#(0 0 255) 10)
	 (imlib:fill-rectangle frame 10 10 748 20 '#(0 0 0))
	 (imlib:text-draw2 frame 15 10 (z t) '#(255 255 255) 10)
	 ))
       (list-ref frames-menu video-id)
       (y t))))
    tracks)   
   (frames->video (join frames-menu)
		  "/tmp/buffer/tracked"
		  1)
   (for-each (lambda (frame)
	      (imlib-context-set-image! frame)
	      (imlib-free-image-and-decache))
	     (join frames-menu))))

 (let* ((result-dir (format #f "/net/zhineng/aux/yu239/~a" results-dir))
	(videos-and-sentences (sort
			       (corpus-from-foldname fold-name dataset)
			       string<?
			       first))
	(videos
	 (map (lambda (e)
	       (strip-extension (strip-directory (first e))))
	      videos-and-sentences))
	(sentences (map third videos-and-sentences))
	(result-dir
	 (format #f "~a/~a/~a" result-dir fold-name (get-running-job-label results-dir fold-name)))
	(tracks-menu
	 (read-object-from-file
	  (string-append result-dir "/tracks.sc")))
	(detected-tracks
	 (map
	  (lambda (tracks video sentence)
	   (let* ((tracks (remove-if string? tracks))
		  (grouped-tracks (group-by x tracks))
		  (ids (join (map (lambda (g) (map-n identity (length g))) grouped-tracks))))
	    (map (lambda (t id)
		  (vector (string-append
			   video
			   "-"
			   (string-downcase (symbol->string (x t)))
			   (number->string id))
			  (y t)
			  sentence
			  ))
		 tracks ids)))
	  tracks-menu videos sentences))
	(detected-tracks (sort (join detected-tracks) string<? x)))

  (write-object-to-file detected-tracks (string-append result-dir "/new-tracks.sc"))

  (when render-video?
   (tagged-tracks->tracked-video detected-tracks videos)
   (system (format #f "cp /tmp/buffer/tracked.mp4 ~a" (string-append result-dir "/new-tracked.mp4"))))))

;; only render ONE particular video
(define (render-codetection-results-per-video results-dir fold-name video-name)
 (let* ((result-dir (format #f "/net/zhineng/aux/yu239/~a" results-dir))
	(result-dir (format #f "~a/~a/~a" result-dir fold-name (get-running-job-label results-dir fold-name)))
	(codetections (read-object-from-file (string-append result-dir "/new-tracks.sc")))
	(related-codetections
	 (remove-if-not
	  (lambda (a)
	   (substring? video-name
		       (x a)))
	  codetections))
	(frames (video->frames (string-append "/net/zhineng/aux/yu239/house/" video-name ".avi"))))  
  (for-each
   (lambda (codetection)
    (let* ((object-name (second (webpage->video-and-object-names (x codetection))))
	   (object-name
	     (pregexp-replace*
	      "-"
	      (if (assoc object-name *name-mapping*)
		  (second (assoc object-name *name-mapping*))
		  object-name)
	      " "))
	   (track (y codetection)))
       (for-each
	(lambda (frame box)
	 (let* ((x (first box))
		(y (second box))
		(w (+ (- (third box) x) 1))
		(h (+ (- (fourth box) y) 1)))
	  (imlib:draw-rectangle frame x y w h '#(255 0 0) 3)
	  (imlib:text-draw2 frame x y object-name '#(255 0 0) 15)
	  ))
	frames
	track)))
   related-codetections)
  (frames->video frames
		 "/tmp/buffer/tracked"
		 1)
  (for-each (lambda (frame)
	     (imlib-context-set-image! frame)
	     (imlib-free-image-and-decache))
	    frames)))
 
;; extract all the detected object image regions for a particular fold
(define (tracks->codetection-patches results-dir fold-name)
 (define dataset (if (substring? "house" results-dir) "house" "CAD")) 
 (define (resize-box x y w h im-w im-h scale)
  (let* ((cx (/ (+ x x w -1) 2))
	 (cy (/ (+ y y h -1) 2))
	 (new-w (* w scale))
	 (new-h (* h scale))
	 (x1 (max 0 (- cx (/ new-w 2))))
	 (y1 (max 0 (- cy (/ new-h 2))))
	 (x2 (min (- im-w 1) (+ cx (/ new-w 2))))
	 (y2 (min (- im-h 1) (+ cy (/ new-h 2)))))
   (list (inexact->exact x1)
	 (inexact->exact y1)
	 (inexact->exact (- x2 x1 -1))
	 (inexact->exact (- y2 y1 -1))))) 
 (let* ((videos-and-sentences
	 (sort (corpus-from-foldname fold-name dataset) string<? first))
	(videos
	 (map (lambda (e)
	       (strip-extension (strip-directory (first e))))
	      videos-and-sentences))
	(tracks (read-object-from-file
		 (format #f "/net/zhineng/aux/yu239/~a/~a/~a/new-tracks.sc"
			 results-dir fold-name (get-running-job-label results-dir fold-name))))
	(frames-menu
	 (map (lambda (v)
	       (video->frames (format #f "/net/zhineng/aux/yu239/~a/~a.avi" dataset v)))
	      videos)))
  (for-each
   (lambda (t)
    (let* ((video-and-object-names
	    (webpage->video-and-object-names (x t)))
	   (video-id (position (first video-and-object-names) videos))
	   (object-name (second video-and-object-names))
	   (dir (format #f "/net/zhineng/aux/yu239/~a/examples/~a"
			results-dir (first video-and-object-names))))
     (system (format #f "mkdir -p ~a" dir))
     (format #t "~a~%" dir)
     (for-each-indexed
      (lambda (frame-box i)
       (let* ((frame (first frame-box))
	      (im-w (imlib:width frame))
	      (im-h (imlib:height frame))
	      (box (second frame-box))
	      (x (first box))
	      (y (second box))
	      (w (+ (- (third box) x) 1))
	      (h (+ (- (fourth box) y) 1)))
	(let* ((resized-box (resize-box x y w h im-w im-h 1.5))
	       (cropped-img
		(imlib:create-cropped-scaled
		 frame
		 (first resized-box)
		 (second resized-box)
		 (third resized-box)
		 (fourth resized-box)
		 (third resized-box)
		 (fourth resized-box))
		))
	 (imlib-context-set-image! cropped-img)
	 ;; Warning: will CRASH if the file format is jpg
	 ;; the reason might be libjpeg
	 (imlib-save-image (format #f "~a/~a-~a.png" dir object-name i))
	 (imlib-free-image-and-decache))))
      (zip
       (list-ref frames-menu video-id)
       (y t))
      )))
   tracks)

  (for-each (lambda (frame)
	     (imlib-context-set-image! frame)
	     (imlib-free-image-and-decache))
	    (join frames-menu))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;; experiment eval functions ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;; for IoU score of machine vs. human ;;;;;;;;;;;;
(define (compute-track-IoU detected-track annotated-tracks-multiple)
 (apply
  max
  (map ;; for each possible object instance appearing in the video
   (lambda (annotated-tracks)
    (let ((annotated-track (transpose-list-of-lists annotated-tracks)))
     (unless (= (length detected-track)
		(length annotated-track))
      (panic "compute-IoU error"))
     (list-mean
      (map (lambda (detection annotations)
	    (;;apply max	  
	     list-mean
	     (map (lambda (gt)
		   (get-IoU detection gt))
		 annotations)))
	   detected-track annotated-track))))
   annotated-tracks-multiple)))

(define (compute-fold-IoU tracks-per-fold annotation)
 (list-mean
  (map (lambda (track)
	(let* ((label (list->string (but-last (string->list (x track))))) ;; remove the instance idx
	       (detected-track (y track))
	       (annotated-tracks-multiple
		(map y (remove-if-not (lambda (gt) (substring? label (x gt))) annotation))))
	 (compute-track-IoU detected-track annotated-tracks-multiple)))
       tracks-per-fold)))

;;;;;;;;;;;;; for IoU score of human vs. human ;;;;;;;;;;;;;;
(define (compute-human-human-IoU annotated-tracks)
 (let ((annotated-track (transpose-list-of-lists annotated-tracks)))
  (list-mean
   (map (lambda (annotations)
	 (;;apply min
	  list-mean
		(map (lambda (gt-pair)
		      (get-IoU (first gt-pair) (second gt-pair)))
		     (all-pairs annotations))))
	annotated-track))))

(define (compute-fold-human-human-IoU tracks-per-fold annotation)
 (list-mean
  (map (lambda (track)
	(let* ((label (x track))
	       (annotated-tracks
		(y (find-if (lambda (gt) (string=? label (x gt))) annotation))))
	 (compute-human-human-IoU annotated-tracks)))
       tracks-per-fold)))

;;;;;;;;;;;;;;; for accuracy of a detected track ;;;;;;;;;;;;
(define (compute-track-accuracy detected-track annotated-tracks-multiple threshold)
 (apply
  max 
  (map
   (lambda (annotated-tracks)
    (let ((annotated-track (transpose-list-of-lists annotated-tracks)))
     (unless (= (length detected-track)
		(length annotated-track))
      (panic "compute-track-accuracy error"))
     (list-mean
      (map (lambda (detection annotations)
	    (apply max
		   (map (lambda (gt)
			 (if (>= (get-IoU detection gt) threshold)
			     1
			     0))
			annotations)))
	   detected-track annotated-track))))
   annotated-tracks-multiple)))

(define (compute-fold-accuracy tracks-per-fold annotation threshold)
 (unless (and (<= 0 threshold) (<= threshold 1))
  (panic "threshold error"))
 (list-mean
  (map (lambda (track)
	(let* ((label (list->string (but-last (string->list (x track))))) ;; remove the instance idx
	       (detected-track (y track))
	       (annotated-tracks-multiple
		(map y (remove-if-not (lambda (gt) (substring? label (x gt))) annotation))))
	 (compute-track-accuracy detected-track annotated-tracks-multiple threshold)))
       tracks-per-fold)))

;;;;;;;;;;;;;;;;;;;;;; get results on all the folds ;;;;;;;;;;;;;;;;;;;;;;;
;; comparison methods
;; codetection-jobs-without-sentence     <-> SIM         <-> -without-sentence
;; codetection-jobs-withonly-movement    <-> SIM+FLOW    <-> -with-movement
;; codetection-jobs-withonly-flow        <-> FLOW        <-> -with-movement -gamma 0
;; codetection-jobs-without-similarity   <-> SEN         <-> -with-sentence -gamma 0
;; codetection-jobs                      <-> SIM+SEN     <-> -with-sentence

;; see results in ./eval-results.sc

(define (evaluate-IoU-all-folds results-dir set-name render-video?)
 (define dataset (if (substring? "house" results-dir) "house" "CAD"))
 (define folds-n (if (equal? dataset "house") 10 5))
 (format #t "evaluate-IoU-all-folds for ~a ~a~%" dataset set-name)
 (let* ((parsed-annotation-path
	 (if (equal? dataset "house")
	     "/net/zhineng/aux/yu239/house/AMT/codetection.results.parsed"
	     "/net/zhineng/aux/yu239/CAD/annotation.sc"))
	(annotation (read-object-from-file parsed-annotation-path))
	(IoUs-all-folds
	 (map-n
	  (lambda (i)
	   (let ((fold-name (format #f "~a_~a" set-name (+ i 1))))
	    (display fold-name) (newline)
	    (tag-video-names-on-tracks results-dir fold-name dataset render-video?)
	    (compute-fold-IoU
	     (read-object-from-file (format #f "/net/zhineng/aux/yu239/~a/~a/~a/new-tracks.sc"
					    results-dir fold-name (get-running-job-label
								   results-dir fold-name)))
	     annotation)))
	  folds-n)))
  (format #t "IoUs scores on the ~a folds:~%" (length IoUs-all-folds))
  (format #t "~a~%" IoUs-all-folds)
  (format #t "Average over the folds:~a~%" (list-mean IoUs-all-folds))
  #t))

;; only for the "house" dataset
;; Human-Human IoUs scores on the 10 folds:
;; ??
;; Average over the folds: ??

(define (evaluate-human-human-IoU-all-folds results-dir set-name)
 (define dataset (if (substring? "house" results-dir) "house" "CAD"))
 (define folds-n (if (equal? dataset "house") 10 5))
 (format #t "evaluate-human-human-IoU-all-folds for ~a ~a~%" dataset set-name)
 (let* ((parsed-annotation-path
	 (if (equal? dataset "house")
	     "/net/zhineng/aux/yu239/house/AMT/codetection.results.parsed"
	     "/net/zhineng/aux/yu239/CAD/annotation.sc"))
	(annotation (read-object-from-file parsed-annotation-path))
	(human-human-IoUs-all-folds
	 (map-n
	  (lambda (i)
	   (compute-fold-human-human-IoU
	    (read-object-from-file (format #f "/net/zhineng/aux/yu239/~a/~a_~a/~a/new-tracks.sc"
					   results-dir set-name (+ i 1)
					   (get-running-job-label
					    results-dir
					    (format #f "~a_~a" set-name (+ i 1)))))
	    annotation))
	  folds-n)))
  (format #t "Human-Human IoUs scores on the ~a folds:~%" (length human-human-IoUs-all-folds))
  (format #t "~a~%" human-human-IoUs-all-folds)
  (format #t "Average over the folds:~a~%" (list-mean human-human-IoUs-all-folds))
  #t))

;; only for the "house" dataset: 0.7153286750730471
(define (evaluate-human-human-IoU-dataset dataset)
 (let* ((parsed-annotation-path
	 (if (equal? dataset "house")
	     "/net/zhineng/aux/yu239/house/AMT/codetection.results.parsed"
	     "/net/zhineng/aux/yu239/CAD/annotation.sc"))
	(annotation (read-object-from-file parsed-annotation-path))
	(human-human-IoUs-dataset
	 (map
	  (lambda (anno)
	   (compute-human-human-IoU	    
	    (y anno)))
	  annotation)))
  (list-mean human-human-IoUs-dataset)))

(define (evaluate-accuracy-all-folds results-dir set-name threshold)
 (define dataset (if (substring? "house" results-dir) "house" "CAD"))
 (define folds-n (if (equal? dataset "house") 10 5))
 (format #t "evaluate-accuracy-all-folds for ~a ~a~%" dataset set-name)
 (let* ((parsed-annotation-path
	 (if (equal? dataset "house")
	     "/net/zhineng/aux/yu239/house/AMT/codetection.results.parsed"
	     "/net/zhineng/aux/yu239/CAD/annotation.sc"))
	(annotation (read-object-from-file parsed-annotation-path))
	(accuracy-all-folds
	 (map-n
	  (lambda (i)
	   (compute-fold-accuracy
	    (read-object-from-file (format #f "/net/zhineng/aux/yu239/~a/~a_~a/~a/new-tracks.sc"
					   results-dir set-name (+ i 1)
					   (get-running-job-label
					    results-dir
					    (format #f "~a_~a" set-name (+ i 1)))))	    
	    annotation
	    threshold))
	  folds-n)))
  (format #t "accuracy on the ~a folds:~%" (length accuracy-all-folds))
  (format #t "~a~%" accuracy-all-folds)
  (format #t "Average over the folds:~a~%" (list-mean accuracy-all-folds))
  (list-mean accuracy-all-folds)))

;; /aux/yu239/codetection-results/accuracy-vs-IoU.sc=SIM+SENT\(Our\)
;; /aux/yu239/codetection-results-withonly-movement/accuracy-vs-IoU.sc=SIM+FLOW
;; /aux/yu239/codetection-results-without-sentence/accuracy-vs-IoU.sc=SIM
;; /aux/yu239/codetection-results-without-similarity/accuracy-vs-IoU.sc=SENT
;; /aux/yu239/codetection-results-withonly-flow/accuracy-vs-IoU.sc=FLOW
;;
;; ./plot-accuracy.py /aux/yu239/codetection-results/accuracy-vs-IoU.sc=SIM+SENT\(Our\) /aux/yu239/codetection-results-withonly-movement/accuracy-vs-IoU.sc=SIM+FLOW /aux/yu239/codetection-results-without-sentence/accuracy-vs-IoU.sc=SIM /aux/yu239/codetection-results-without-similarity/accuracy-vs-IoU.sc=SENT /aux/yu239/codetection-results-withonly-flow/accuracy-vs-IoU.sc=FLOW

(define (evaluate-accuracy-curve-all dataset)
 (for-each (lambda (name)
	    (for-each-n
	     (lambda (i)
	      (evaluate-accuracy-curve (if (string=? name "")
					   (format #f "codetection-results-amt-~a" dataset)
					   (format #f "codetection-results-amt-~a-~a" dataset name))
				       (format #f (if (string=? dataset "house")
						      "videos-house-amt-~a"
						      "~a")
					       (+ i 1))
				       500))
	     3))
	   '("" "FLOW" "SENT" "SIM+FLOW" "SIM")))

;; points-n = 500
(define (evaluate-accuracy-curve results-dir set-name points-n)
 (let ((step (/ 1 points-n)))
  (write-file
   (map-n (lambda (i)
	   (format #f "~a ~a"
		   (* i step)
		   (evaluate-accuracy-all-folds results-dir set-name (* i step))))
	  points-n)
   (format #f "/net/zhineng/aux/yu239/~a/roc-~a.sc" results-dir set-name))))

(define (render-examples-for-demo)
 (let ((videos '("00000-000051-000003-cleaner"
		 "00001-000155-000004-squash"
		 "00002-000143-000002-cabbage"
		 "00001-000009-000003-pineapple"))
       (folds (map-n
	       (lambda (i)
		(read-file
		 (format #f "/home/yu239/darpa-collaboration/sentence-codetection/videos-files/house/folds/~a.txt"
			 (+ i 1))))
	       10)))
  (system "rm -rf /tmp/examples; mkdir -p /tmp/examples")
  (for-each
   (lambda (v)
    ;; render annotations	 
    (render-annotations-per-video v "house")
    (system (format #f "mv /tmp/buffer/annotation.mp4 /tmp/examples/~a-annotation.mp4" v))
    (let ((fold-i (position (find-if (lambda (fold) (member v fold)) folds) folds)))
     ;; render our results
     (render-codetection-results-per-video "codetection-results"
					   (format #f "videos-house~a" (+ fold-i 1)) v)
     (system (format #f "mv /tmp/buffer/tracked.mp4 /tmp/examples/~a-tracked.mp4" v))
     ;; render SENT results
     (render-codetection-results-per-video "codetection-results-SENT"
					   (format #f "videos-house~a" (+ fold-i 1)) v)
     (system (format #f "mv /tmp/buffer/tracked.mp4 /tmp/examples/~a-b3.mp4" v))
     ;; render SIM+FLOW results
     (render-codetection-results-per-video "codetection-results-SIM+FLOW"
					   (format #f "videos-house~a" (+ fold-i 1)) v)
     (system (format #f "mv /tmp/buffer/tracked.mp4 /tmp/examples/~a-b4.mp4" v))))
   videos)))

(define (scheme-annotation->plain-format dataset)
 (let* ((annotations
	 (read-object-from-file
	  (if (string=? dataset "house")
	      "/net/zhineng/aux/yu239/house/AMT/codetection.results.parsed"
	      "/net/zhineng/aux/yu239/CAD/annotation.sc")))
	(plain-format
	 (join 
	  (map
	   (lambda (annotation)
	    (let* ((video-and-object (webpage->video-and-object-names (x annotation)))		 
		   (coordinates (y annotation)))
	     (cons (format #f "~a ~a"
			   (first video-and-object)
			   (second video-and-object))
		   (map (lambda (turkers)
			 (string-join " " (map number->string (join turkers))))
			(transpose-list-of-lists coordinates)))))
	   annotations))))
  (write-file plain-format
	      (if (string=? dataset "house")
		  "/aux/yu239/pami2016-dataset/ours/box-annotation.txt"
		  "/aux/yu239/pami2016-dataset/CAD/box-annotation.txt"))))