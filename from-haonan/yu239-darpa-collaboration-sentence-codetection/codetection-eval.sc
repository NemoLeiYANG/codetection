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
		    bucket))

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

;; e.g., (render-annotations-per-video-object (first (parse-amt-results (read-file "codetection.results"))))
(define (render-annotations-per-video-object annotation-per-video)
 (let* ((video-and-object-names (webpage->video-and-object-names (x annotation-per-video)))
	(frames (video->frames (string-append "/aux/yu239/house/" (first video-and-object-names) ".avi")))
	(object-name (second video-and-object-names))
	(tracks (y annotation-per-video)))
  (for-each
   (lambda (t)
     (for-each
      (lambda (frame box)
       (let* ((x (first box))
	      (y (second box))
	      (w (+ (- (third box) x) 1))
	      (h (+ (- (fourth box) y) 1)))
	(imlib:draw-rectangle frame x y w h '#(0 0 0) 3)
	(imlib:text-draw2 frame x y object-name '#(0 0 0) 15)
	(imlib:text-draw2 frame 10 10 (vector-ref annotation-per-video 0)
			  '#(0 0 0) 10)
       ))
      frames
      t))
   tracks)
  
  (frames->video frames
		 "/tmp/buffer/annotation"
		 1)

  (for-each (lambda (frame)
	     (imlib-context-set-image! frame)
	     (imlib-free-image-and-decache))
	    frames)))

(define (render-annotations-per-video video-name)
 (let* ((annotations (read-object-from-file "/aux/yu239/house/AMT/codetection.results.parsed"))
	(related-annotations
	 (remove-if-not
	  (lambda (a)
	   (substring? video-name
		       (x a)))
	  annotations))
	(frames (video->frames (string-append "/aux/yu239/house/" video-name ".avi"))))

  (for-each
   (lambda (annotation)
    (let* ((object-name (second (webpage->video-and-object-names (x annotation))))
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

(define (render-codetection-results-per-video results-dir foldi video-name)
 (let* ((result-dir
	 (format #f "/aux/yu239/~a/videos-house~a/~a" results-dir foldi (get-running-job-label results-dir foldi)))
	(codetections (read-object-from-file (string-append result-dir "/new-tracks.sc")))	
	(related-codetections
	 (remove-if-not
	  (lambda (a)
	   (substring? video-name
		       (x a)))
	  codetections))
	(frames (video->frames (string-append "/aux/yu239/house/" video-name ".avi"))))  
  (for-each
   (lambda (codetection)
    (let* ((object-name (second (webpage->video-and-object-names (x codetection))))
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
  
(define (get-running-job-label results-dir foldi)
 (with-temporary-file
  "/tmp/running-job.label"
  (lambda (tmp)
   (system (format #f "cd /aux/yu239/~a/videos-house~a; ls > ~a; cd -;"
		   results-dir foldi tmp))
   (first (read-file tmp)))))

(define (tag-video-names-on-tracks results-dir foldi)
 (let* ((videos-file (format #f "/home/yu239/darpa-collaboration/sentence-codetection/videos-files/videos-house~a.sc" foldi))
	(videos-and-sentences
	 (sort
	  (read-object-from-file videos-file)
	  string<?
	  first))
	(videos
	 (map (lambda (e)
	       (strip-extension (strip-directory (first e))))
	      videos-and-sentences))
	(sentences (map third videos-and-sentences))
	(result-dir
	 (format #f "/aux/yu239/~a/videos-house~a/~a" results-dir foldi (get-running-job-label results-dir foldi)))
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

  (tagged-tracks->tracked-video detected-tracks videos)

  (write-object-to-file detected-tracks (string-append result-dir "/new-tracks.sc"))
  (system (format #f "cp /tmp/buffer/tracked.mp4 ~a" (string-append result-dir "/new-tracked.mp4")))
  
  ))

(define (tagged-tracks->tracked-video tracks videos)
 (let ((frames-menu
	(map (lambda (v)
	      (video->frames (string-append "/aux/yu239/house/" v ".avi")))
	     videos)))

  (for-each
   (lambda (t)
    (let* ((video-and-object-names
	    (webpage->video-and-object-names (x t)))
	   (video-id (position (first video-and-object-names) videos))
	   (object-name (second video-and-object-names))
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

;; only for codetection-results
(define (tracks->codetection-patches foldi)
 (define im-w 768)
 (define im-h 432)
 (define (resize-box x y w h scale)
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
 (let* ((videos-file (format #f "/home/yu239/darpa-collaboration/sentence-codetection/videos-files/videos-house~a.sc" foldi))
	(videos-and-sentences
	 (sort
	  (read-object-from-file videos-file)
	  string<?
	  first))
	(videos
	 (map (lambda (e)
	       (strip-extension (strip-directory (first e))))
	      videos-and-sentences))
	(tracks (read-object-from-file
		 (format #f "/aux/yu239/codetection-results/videos-house~a/~a/new-tracks.sc"
			 foldi (get-running-job-label "codetection-results" foldi))))
	(frames-menu
	 (map (lambda (v)
	       (video->frames (string-append "/aux/yu239/house/" v ".avi")))
	      videos)))
  (for-each
   (lambda (t)
    (let* ((video-and-object-names
	    (webpage->video-and-object-names (x t)))
	   (video-id (position (first video-and-object-names) videos))
	   (object-name (second video-and-object-names))
	   (dir (format #f "/aux/yu239/codetection-results/examples/~a"
			(first video-and-object-names))))
     (system (format #f "mkdir -p ~a" dir))
     (format #t "~a~%" dir)
     (for-each-indexed
      (lambda (frame-box i)
       (let* ((frame (first frame-box))
	      (box (second frame-box))
	      (x (first box))
	      (y (second box))
	      (w (+ (- (third box) x) 1))
	      (h (+ (- (fourth box) y) 1)))
	(let* ((resized-box (resize-box x y w h 1.5))
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

;;;;;;;;;;;;;;;; experiment eval functions ;;;;;;;;;;;;;;;

;;;;;;;;;;;; for IoU score of machine vs. human ;;;;;;;;;;;;
(define (compute-track-IoU detected-track annotated-tracks)
 (let ((annotated-track (apply zip annotated-tracks)))
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

(define (compute-fold-IoU tracks-per-fold annotation)
 (list-mean
  (map (lambda (track)
	(let* ((label (x track))
	       (detected-track (y track))
	       (annotated-tracks
		(y (find-if (lambda (gt) (string=? label (x gt))) annotation))))
	 (compute-track-IoU detected-track annotated-tracks)))
       tracks-per-fold)))

;;;;;;;;;;;;; for IoU score of human vs. human ;;;;;;;;;;;;;;
(define (compute-human-human-IoU annotated-tracks)
 (let ((annotated-track (apply zip annotated-tracks)))
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
	       (detected-track (y track))
	       (annotated-tracks
		(y (find-if (lambda (gt) (string=? label (x gt))) annotation))))
	 (compute-human-human-IoU annotated-tracks)))
       tracks-per-fold)))

;;;;;;;;;;;;;;; for accuracy of a detected track ;;;;;;;;;;;;
(define (compute-track-accuracy detected-track annotated-tracks threshold)
 (let ((annotated-track (apply zip annotated-tracks)))
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

(define (compute-fold-accuracy tracks-per-fold annotation threshold)
 (unless (and (<= 0 threshold) (<= threshold 1))
  (panic "threshold error"))
 (list-mean
  (map (lambda (track)
	(let* ((label (x track))
	       (detected-track (y track))
	       (annotated-tracks
		(y (find-if (lambda (gt) (string=? label (x gt))) annotation))))
	 (compute-track-accuracy detected-track annotated-tracks threshold)))
       tracks-per-fold)))

;;;;;;;;;;;;;;;;;;;;;; get results on all the folds ;;;;;;;;;;;;;;;;;;;;;;;
;; comparison methods
;; codetection-jobs-without-sentence     <-> SIM         <-> -without-sentence
;; codetection-jobs-withonly-movement    <-> SIM+FLOW    <-> -with-movement 
;; codetection-jobs-withonly-flow        <-> FLOW        <-> -with-movement -gamma 0
;; codetection-jobs-without-similarity   <-> SEN         <-> -with-sentence -gamma 0
;; codetection-jobs                      <-> SIM+SEN     <-> -with-sentence 


;; codetection-results
;; IoUs scores on the 10 folds:
;; (0.3921224382359987 0.4738040011832503 0.3599599481296524 0.3498784046347937 0.40326180312121 0.524028981184592 0.5027130917262526 0.3733404259816005 0.4552823467999568 0.4281021870188925)
;; Average over the folds:0.4262493628016199

;; codetection-results-withonly-movement
;; IoUs scores on the 10 folds:
;; (0.3073937223599189 0.3740291763678528 0.2827898052381316 0.1914754397707463 0.3772800008971885 0.4355877305414698 0.5017806131137573 0.2858869901955768 0.4632646511074187 0.2308902701263694)
;; Average over the folds:0.345037839971843

;; evaluate-IoU-all-folds for codetection-results-without-similarity
;; IoUs scores on the 10 folds:
;; (0.2500083590467067 0.2884954869839881 0.361295252863196 0.2486125135506526 0.2268472414471139 0.3744807570452586 0.3058166471277699 0.3237758461506786 0.2874406962549054 0.2653989105353127)
;; Average over the folds:0.2932171711005583

;; evaluate-IoU-all-folds for codetection-results-withonly-flow
;; IoUs scores on the 10 folds:
;; (0.1881166906855034 0.2395965597094316 0.2251697541706933 0.1003328890989592 0.21507670631758 0.3175768803620848 0.2430762817521218 0.1852882519538444 0.2307707381623857 0.1528370283878465)
;; Average over the folds:0.2097841780600451

;; codetection-results-without-sentence
;; IoUs scores on the 10 folds:
;; (0.001102061599576508 0 0.0002553924694160482 3.395249095845166e-09 0.0005217256338933797 0.002669818709209413 0 0.003569781093498462 0.0003413215062397486 0.001325660308814234)
;; Average over the folds:0.0009785764715896888

(define (evaluate-IoU-all-folds results-dir)
 (define folds-n 10)
 (format #t "evaluate-IoU-all-folds for ~a~%" results-dir)
 (let* ((parsed-annotation-path "/aux/yu239/house/AMT/codetection.results.parsed")
	(annotation
	 (if (file-exists? parsed-annotation-path)
	     (read-object-from-file parsed-annotation-path)
	     (let ((anno (parse-amt-results (read-file "/aux/yu239/house/AMT/codetection.results"))))
	      (write-object-to-file anno parsed-annotation-path)
	      anno)))	       
	(IoUs-all-folds
	 (map-n
	  (lambda (i)
	   (compute-fold-IoU
	    (read-object-from-file (format #f "/aux/yu239/~a/videos-house~a/~a/new-tracks.sc"
					   results-dir (+ i 1) (get-running-job-label results-dir (+ i 1))))
	    annotation))
	  folds-n)))
  (format #t "IoUs scores on the ~a folds:~%" (length IoUs-all-folds))
  (format #t "~a~%" IoUs-all-folds)
  (format #t "Average over the folds:~a~%" (list-mean IoUs-all-folds))
  #t))

;; Human-Human IoUs scores on the 10 folds:
;; (0.6938881182185468 0.7023504628335758 0.7820047466672722 0.6546403712431409 0.6916086970610514 0.7861442214032953 0.7757094881799725 0.7590155990533665 0.7294883648680548 0.7186731050092251)
;; Average over the folds:0.7293523174537502

(define (evaluate-human-human-IoU-all-folds results-dir)
 (define folds-n 10)
 (format #t "evaluate-human-human-IoU-all-folds for ~a~%" results-dir)
 (let* ((parsed-annotation-path "/aux/yu239/house/AMT/codetection.results.parsed")
	(annotation
	 (if (file-exists? parsed-annotation-path)
	     (read-object-from-file parsed-annotation-path)
	     (let ((anno (parse-amt-results (read-file "/aux/yu239/house/AMT/codetection.results"))))
	      (write-object-to-file anno parsed-annotation-path)
	      anno)))	       
	(human-human-IoUs-all-folds
	 (map-n
	  (lambda (i)
	   (compute-fold-human-human-IoU
	    (read-object-from-file (format #f "/aux/yu239/~a/videos-house~a/~a/new-tracks.sc"
					   results-dir (+ i 1) (get-running-job-label results-dir (+ i 1))))
	    annotation))
	  folds-n)))
  (format #t "Human-Human IoUs scores on the ~a folds:~%" (length human-human-IoUs-all-folds))
  (format #t "~a~%" human-human-IoUs-all-folds)
  (format #t "Average over the folds:~a~%" (list-mean human-human-IoUs-all-folds))
  #t))

;; 0.7173051527295963
(define (evaluate-human-human-IoU-dataset)
 (let* ((parsed-annotation-path "/aux/yu239/house/AMT/codetection.results.parsed")
	(annotation
	 (if (file-exists? parsed-annotation-path)
	     (read-object-from-file parsed-annotation-path)
	     (let ((anno (parse-amt-results (read-file "/aux/yu239/house/AMT/codetection.results"))))
	      (write-object-to-file anno parsed-annotation-path)
	      anno)))	       
	(human-human-IoUs-dataset
	 (map
	  (lambda (anno)
	   (compute-human-human-IoU	    
	    (y anno)))
	  annotation)))
  (list-mean human-human-IoUs-dataset)))

(define (evaluate-accuracy-all-folds results-dir threshold)
 (define folds-n 10)
 (format #t "evaluate-accuracy-all-folds for ~a~%" results-dir)
 (let* ((parsed-annotation-path "/aux/yu239/house/AMT/codetection.results.parsed")
	(annotation
	 (if (file-exists? parsed-annotation-path)
	     (read-object-from-file parsed-annotation-path)
	     (let ((anno (parse-amt-results (read-file "/aux/yu239/house/AMT/codetection.results"))))
	      (write-object-to-file anno parsed-annotation-path)
	      anno)))	       
	(accuracy-all-folds
	 (map-n
	  (lambda (i)
	   (compute-fold-accuracy
	    (read-object-from-file (format #f "/aux/yu239/~a/videos-house~a/~a/new-tracks.sc"
					   results-dir (+ i 1) (get-running-job-label results-dir (+ i 1))))
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
(define (evaluate-accuracy-curve results-dir points-n)
 (let ((step (/ 1 points-n)))
 (map-n (lambda (i) (list (* i step)
			  (evaluate-accuracy-all-folds results-dir (* i step))))
	points-n)))