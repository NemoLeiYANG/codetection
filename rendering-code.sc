;; this is copied from scotts folder some place
;; (define frame-data (read-object-from-file "/tmp/frame-data.sc"))


;; (define detections-movie (map (lambda (frame-boxes) (map-vector (lambda (b) (vector (vector-ref b 5) (vector-ref b 6))) frame-boxes)) (first frame-data)))


;; (define file-path "/net/seykhl/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation-testing/plan0/2014-11-20-02:32:22/")

;; (define (visualize-proposals path dummy-f dummy-g outpath)
;;  (let* (;; (data (read-object-from-file (format #f "~a/frame-data-new3.sc" path)))
;; 	(data frame-data )
;; 	;;(read-object-from-file (format #f "~a/frame-data-~a-~a.sc" path dummy-f dummy-g)))
;; 	(img-path (format #f "~a/images-~a-~a" outpath
;; 			  (number->padded-string-of-length dummy-f 3)
;; 			  (number->padded-string-of-length dummy-g 3)))
;; 	(boxes (first data))
;; 	(max-score (maximum (map (lambda (x) (vector-ref x 4)) (join (map vector->list boxes)))))
;; 	(video-path (format #f "~a/video_front.avi" path))
;; 	(frames (video->frames 1 video-path))
;; 	)
  
;;   (mkdir-p img-path)
;;   (let loop ((images (map (lambda (f) (imlib:clone f)) frames))
;; 	     (boxes boxes)
;; 	     (n 0))
;;    (if (or (null? images)
;; 	   (null? boxes))
;;        (dtrace (format #f "finished in ~a" path) #f)
;;        (begin
;; 	(for-each-vector
;; 	(lambda (box)
;; 	 (let* ((x1 (first box)) ;;we have a real box
;; 		(y1 (second box))
;; 		(w (- (third box) (first box)))
;; 		(h (- (fourth box) (second box))))
;; 	  (imlib:draw-rectangle
;; 	   (first images) x1 y1 w h
;; 	   (vector (* (/ (fifth box) max-score) 255) 0 0))
;; 	  ;; (imlib:draw-rectangle
;; 	  ;;  (first images) (+ x1 1) (+ y1 1) w h
;; 	  ;;  (vector (* (/ (fifth box) max-score) 255) 0 0))
;; 	  ;; (imlib:draw-rectangle
;; 	  ;;  (first images) (- x1 1) (- y1 1) w h
;; 	  ;;  (vector (* (/ (fifth box) max-score) 255) 0 0))
;; 	  ))
;; 	(map-vector vector->list (first boxes)))
;;        (imlib:save (first images) (format #f "~a/rendered-proposals-~a.png"
;; 				 img-path
;; 				 (number->padded-string-of-length n 5)))
;; 	(dtrace "saved image" n)
;; 	(loop (rest images) (rest boxes) (+ n 1)))))))
;;new version copied from Dan's ralicra2016/supplementary-material
(define (visualize-proposals path dummy-f dummy-g outdir)
 (let* ((outpath (format #f "~a/~a" path outdir))
	(data (read-object-from-file
	       (format #f "~a/frame-data-~a-~a.sc" outpath
		       (number->padded-string-of-length dummy-f 3)
		       (number->padded-string-of-length dummy-g 3))))
	(img-path (format #f "~a/images-~a-~a" outpath
			  (number->padded-string-of-length dummy-f 3)
			  (number->padded-string-of-length dummy-g 3)))
	(boxes (first data))
	(scores (map (lambda (x) (vector-ref x 4)) (join (map vector->list boxes))))
	(score-mean (list-mean scores))
	(score-variance (list-variance scores))
	(score-std (sqrt score-variance))
	(max-score (+ score-mean (* 1 score-std)))
	(min-score (- score-mean (* 1 score-std)))
	(video-path (format #f "~a/video_front.avi" path))
	(frames (video->frames 1 video-path))
	)
  
  (mkdir-p img-path)
  (let loop ((images (map (lambda (f) (imlib:clone f)) frames))
	     (boxes boxes)
	     (n 0))
   (if (or (null? images)
	   (null? boxes))
       (dtrace (format #f "finished in ~a" path) #f)
       (begin
       ;; (let* ((scores
       ;; 	       (map (lambda (x) (vector-ref x 4)) (vector->list (first boxes))))
       ;; 	      (max-score (maximum scores))
       ;; 	      (min-score (minimum scores)))
	;; (dtrace "max-score " max-score)
	;; (dtrace "min-score " min-score)
	(for-each
	 (lambda (box)
	  (let* ((x1 (first box)) ;;we have a real box
		 (y1 (second box))
		 (w (- (third box) (first box)))
		 (h (- (fourth box) (second box)))
;;		 (red (* (/ (fifth box) max-score) 255))
;;		 (blue (* (- 1 (/ (fifth box) max-score)) 255)))
		 (red (* (minimum
			  (list 1
				(/ (- (fifth box) min-score)
				   (- max-score min-score))))
			 255))
		 (blue
		  ;; (* (- 1 (minimum
		  ;; 	   (list 1
		  ;; 		 (/ (- (fifth box) min-score)
		  ;; 		    (- max-score min-score)))) 255))
		  (* 255
		     (maximum
		      (list 0
			    (- 1
			       (/ (- (fifth box) min-score)
				  (- max-score min-score))))))
		  ))
	   (imlib:draw-rectangle
	    (first images) x1 y1 w h
	    (vector red 0 blue))
	   (imlib:draw-rectangle
	    (first images) (+ x1 1) (+ y1 1) w h
	    (vector red 0 blue))
	   (imlib:draw-rectangle
	    (first images) (- x1 1) (- y1 1) w h
	    (vector red 0 blue))
	   ))
	 (map vector->list (sort (vector->list (first boxes))
				 <
				 (lambda (b) (vector-ref b 4)))))
	(imlib:save (first images) (format #f "~a/rendered-proposals-~a.png"
					   img-path
					   (number->padded-string-of-length n 5)))
	(dtrace "saved image" n)
	(loop (rest images) (rest boxes) (+ n 1)))))))
				      

(define (make-4-by-video-house-one-run path)
 (let ((outdir "test20151117")
       (dummy-f 0.6)
       (dummy-g 0.6))
  ;;abort if files aren't there
  (if (not (file-exists? (format #f "~a/track.sc" path)))
      (dtrace
       (format #f "missing ~a/track.sc, make-4-by-video-house-one-run aborted" path)
       #f))
  (if (not (file-exists? (format #f "~a/~a/frame-data-~a-~a.sc"
				 path
				 outdir
				 (number->padded-string-of-length dummy-f 3)
				 (number->padded-string-of-length dummy-g 3))))
      (dtrace
       (format #f "missing ~a/~a/frame-data-*.sc, make-4-by-video-house-one-run aborted"
	       path
	       outdir)
       #f))
  (if (not (file-exists? (format #f "~a/~a/results-~a-~a.sc"
				 path
				 outdir
				 (number->padded-string-of-length dummy-f 3)
				 (number->padded-string-of-length dummy-g 3))))
      (dtrace
       (format #f "missing ~a/~a/results-*.sc, make-4-by-video-house-one-run aborted"
	       path
	       outdir)
       #f))
  (let* ((width 640)
	 (height 640))
   ;;THINK ABOUT reading in frame-data and results just once here then passing to each function-->should speed things up over reading the files multiple times
   
   ;;visualize all proposals
   (visualize-proposals path dummy-f dummy-g outdir) 
   ;;make joined plots of traces w/ all and winning proposals
   (new-animate-track-with-boxes path outdir width height)
   ;;stitch visualizations together
   ;;stitch visualizations to joined plots
   ;;make video
   ;;clean up images
   (rm (format #f "~a/~a/images-~a-~a/rendered-proposals*.png" path outdir dummy-f dummy-g))
   
  )))


(define (visualize-results-improved path dummy-f dummy-g data-output-dir)
 (let* (;; (data (read-object-from-file (format #f "~a/frame-data-new3.sc" path)))
	(data (read-object-from-file (format #f "~a/~a/frame-data-~a-~a.sc"
					     path data-output-dir dummy-f dummy-g)))
	(img-path (format #f "~a/~a/images-~a-~a" path data-output-dir
			  (number->padded-string-of-length dummy-f 3)
			  (number->padded-string-of-length dummy-g 3)))
	(results (run-codetection-with-proposals-similarity data
							    dummy-f
							    dummy-g))
	(boxes (third results))
	(video-path (format #f "~a/video_front.avi" path))
	(frames (video->frames 1 video-path))
	)
  (write-object-to-file results (format #f "~a/~a/results-~a-~a.sc"
					path
					data-output-dir
					(number->padded-string-of-length dummy-f 3)
					(number->padded-string-of-length dummy-g 3)))
 ;; (dtrace "img-path" img-path)
  (mkdir-p img-path)
  (let loop ((images (map (lambda (f) (imlib:clone f)) frames))
	     (boxes boxes)
	     (n 0))
   (if (or (null? images)
	   (null? boxes))
       (dtrace (format #f "finished in ~a" path) #f)
       (let* ((box (first boxes))
	      (image (first images)))
	(if (null? box)
	    (imlib-draw-text-on-image image ;;we have a dummy box
				      "DUMMY BOX" ;;string
				      (vector 255 0 0) ;;text color
				      18 ;;font size?
				      320 ;; x?
				      240 ;; y?
				      (vector 255 255 255) ;;bg color
				      ) 
	    (let* ((x1 (first box)) ;;we have a real box
		   (y1 (second box))
		   (w (- (third box) (first box)))
		   (h (- (fourth box) (second box))))
	     (imlib:draw-rectangle image x1 y1 w h (vector 255 0 0))))
	(imlib:save image (format #f "~a/~a.png"
				  img-path
				  (number->padded-string-of-length n 5)))
	(dtrace "saved image" n)
	(loop (rest images) (rest boxes) (+ n 1)))))))

(define (video->frames downsample video-path)
 (let ((ffmpeg-video (ffmpeg-open-video video-path)))
  (let loop ((frames '())
	     (start #t)
	     (i 0))
   (if (or start (ffmpeg-next-frame! ffmpeg-video))
       (if (zero? (modulo i downsample))
	   (loop (cons (ffmpeg-video-frame-data-as-imlib ffmpeg-video) frames) #f (+ i 1))
	   (loop frames #f (+ i 1)))
       (begin
	(ffmpeg-close-video ffmpeg-video)
	(reverse frames))))))


(define (world->pixel world-xy width height minx maxx miny maxy)
  (vector (+ (* width (/ (x world-xy) (- maxx minx)))
	     (* width (/ (abs minx) (- maxx minx))));;(/ width 2))
	  (+ (- (* height (/ (y world-xy) (- maxy miny))))
	     (* height (/ (abs maxy) (- maxy miny))))));;(/ height 2))))

(define (draw-world-line line image width height minx maxx miny maxy color)
(imlib:draw-line image color 
		 (x (world->pixel (first line) width height minx maxx miny maxy))
		 (y (world->pixel (first line)  width height minx maxx miny maxy))
		 (x (world->pixel (second line) width height minx maxx miny maxy))
		 (y (world->pixel (second line)  width height minx maxx miny maxy))))

(define (draw-object-on-floorplan obj image width height minx maxx miny maxy)
  (let* ((world-xy (second obj))
	 (pix-xy (world->pixel world-xy width height minx maxx miny maxy)
	  ;; (vector (+ (* width (/ (x world-xy) (- maxx minx)))
	  ;; 	    (/ width 2))
	  ;; 	 (+ (- (* height (/ (y world-xy) (- maxy miny))))
	  ;; 	    (/ height 2)))
		 ))
    (imlib-draw-text-on-image image 
			      (symbol->string (remove-the (first obj)))
			      `#(0 0 0) 12 (x pix-xy) (y pix-xy) `#(255 255 255))
                              ;;`#(0 0 0) 6 (x pix-xy) (y pix-xy) `#(255 255 255))
    (imlib:fill-ellipse image (x pix-xy) (y pix-xy) 2 2 `#(255 0 255))
    ;; (imlib:draw-ellipse image (x pix-xy) (y pix-xy) 1 1 `#(255 0 255))
    ;; (imlib:draw-ellipse image (x pix-xy) (y pix-xy) .5 .5 `#(255 0 255))
    ;; (imlib:draw-ellipse image (x pix-xy) (y pix-xy) .25 .25 `#(255 0 255))
    ;; (imlib:draw-ellipse image (x pix-xy) (y pix-xy) 3 3 `#(255 0 255))
    ))


(define (draw-trace points image width height minx maxx miny maxy)
  (let loop ((points points))
    (if (< (length points) 2)
	(imlib:draw-ellipse image 
			    (x (world->pixel (first points) width height minx maxx miny maxy))
			    (y (world->pixel (first points) width height minx maxx miny maxy))
			    2 2 `#(0 0 255))
	(begin (draw-world-line (sublist points 0 2) image width height minx maxx miny maxy `#(0 0 255))
	       (imlib:draw-ellipse image 
				   (x (world->pixel (first points) width height minx maxx miny maxy))
				   (y (world->pixel (first points) width height minx maxx miny maxy))
				   2 2 `#(0 0 255))
	       (imlib:draw-ellipse image 
				   (x (world->pixel (second points) width height minx maxx miny maxy))
				   (y (world->pixel (second points) width height minx maxx miny maxy))
				   2 2 `#(0 0 255))
	       (loop (rest points))))))

(define (draw-trace2 points image width height minx maxx miny maxy)
  (let loop ((points points))
    (if (< (length points) 2)
	(imlib:draw-ellipse image 
			    (x (world->pixel (first points) width height minx maxx miny maxy))
			    (y (world->pixel (first points) width height minx maxx miny maxy))
			    2 2 `#(0 255 255))
	(begin (draw-world-line (sublist points 0 2) image width height minx maxx miny maxy `#(0 255 255))
	       
	       (loop (rest points))))))

(define (draw-floorplan-and-sentence dataset trace floorplan-index sentence-index)
  (let* ((image (imlib:create 1300 240)))
    (imlib:fill-rectangle image 0 0 1300 240 `#(255 255 255)) 
    (let* ((sentence (second (vector-ref (vector-ref dataset floorplan-index)
						  sentence-index)))
	   (sub-clauses (map-indexed (lambda (c i)
				       (if (= i 0)
					   c
					   (string-append "then" c)))
				     (pregexp-split "then" sentence))))
      (for-each-indexed
       (lambda (c i)
	 (imlib-draw-text-on-image image 
				   c
				   `#(0 0 0) 8 340 (+ 10 (* i 14)) `#(255 255 255)))
       sub-clauses))
(for-each
 (lambda (obj)
   (draw-object-on-floorplan obj image 320 240 -4 4 -4 4))
 (first (vector-ref (vector-ref dataset floorplan-index)
		    sentence-index)))

(draw-object-on-floorplan (list 'origin (vector 0 0)) image 320 240 -4 4 -4 4)

(for-each 
 (lambda (pair)
(imlib:draw-line image `#(0 0 0) 
		 (x (world->pixel (first pair) 320 240 -4 4 -4 4))
		 (y (world->pixel (first pair)  320 240 -4 4 -4 4))
		 (x (world->pixel (second pair) 320 240 -4 4 -4 4))
		 (y (world->pixel (second pair)  320 240 -4 4 -4 4))))
(list (list `#(-3 -2.62) `#(-3 3.93))
      (list `#(-3 -2.62) `#(3.05 -2.62))
      (list `#(3.05 3.93) `#(3.05 -2.62))
      (list `#(3.05 3.93) `#(-3.0 3.93))
      (list `#(-1.37 -2.62) `#(-1.37 3.93))
      (list `#(0 -2.62) `#(0 3.93))
      (list `#(1.37 -2.62) `#(1.37 3.93))
      (list `#(-3 -1.31) `#(3.05 -1.31))
      (list `#(-3 0) `#(3.05 0))
      (list `#(-3 1.31) `#(3.05 1.31))
      (list `#(-3 2.62) `#(3.05 2.62))))

(when trace
(draw-trace trace image 320 240 -4 4 -4 4))

(draw-robot image (vector 100 100) 0 10)
(draw-robot image (vector 150 100) .2 10)
(draw-robot image (vector 200 100) .4 10)
(draw-robot image (vector 250 100) .6 10)
(draw-robot image (vector 300 100) .8 10)
(draw-robot image (vector 350 100) 1 10)

(show-image image)
;;(draw-imlib-pixmap image 0 250)
(imlib:free image)))



(define (draw-robot image p theta scale)
 (let* ((front (v+ p (k*v scale (vector (cos theta) (- (sin theta))))))
	(back (v- p (k*v scale (vector (cos theta) (- (sin theta))))))
	(back1 (v- back (k*v (* scale .6) (vector (cos (+ theta half-pi))
					   (- (sin (+ theta half-pi)))))))
	(back2 (v+ back (k*v (* scale .6) (vector (cos (+ theta half-pi))
					   (- (sin (+ theta half-pi)))))))
	)
 (imlib:draw-line image `#(0 0 255) (x front) (y front) (x back1) (y back1))
 (imlib:draw-line image `#(0 0 255) (x front) (y front) (x back2) (y back2))
 (imlib:draw-line image `#(0 0 255) (x back2) (y back2) (x back1) (y back1))))

(define (draw-world-robot image p theta scale width height minx maxx miny maxy)
 (let* ((front (v+ p (k*v scale (vector (cos theta) (sin theta)))))
	(back (v- p (k*v scale (vector (cos theta) (sin theta)))))
	(back1 (v- back (k*v (* scale .6) (vector (cos (+ theta half-pi))
					    (sin (+ theta half-pi))))))
	(back2 (v+ back (k*v (* scale .6) (vector (cos (+ theta half-pi))
					   (sin (+ theta half-pi))))))
	)
 (draw-world-line (list front back1) image width height minx maxx miny maxy `#(0 0 255))
 (draw-world-line (list front back2) image width height minx maxx miny maxy `#(0 0 255))
 (draw-world-line (list back2 back1) image width height minx maxx miny maxy `#(0 0 255))
 ))

(define (draw-world-line line image width height minx maxx miny maxy color)
(imlib:draw-line image color 
		 (x (world->pixel (first line) width height minx maxx miny maxy))
		 (y (world->pixel (first line)  width height minx maxx miny maxy))
		 (x (world->pixel (second line) width height minx maxx miny maxy))
		 (y (world->pixel (second line)  width height minx maxx miny maxy)))
(imlib:draw-line image color 
		 (+ 1 (x (world->pixel (first line) width height minx maxx miny maxy)))
		 (y (world->pixel (first line)  width height minx maxx miny maxy))
		 (+ 1 (x (world->pixel (second line) width height minx maxx miny maxy)))
		 (y (world->pixel (second line)  width height minx maxx miny maxy)))
(imlib:draw-line image color 
		 (x (world->pixel (first line) width height minx maxx miny maxy))
		 (+ 1 (y (world->pixel (first line)  width height minx maxx miny maxy)))
		 (x (world->pixel (second line) width height minx maxx miny maxy))
		 (+ 1 (y (world->pixel (second line)  width height minx maxx miny maxy))))
(imlib:draw-line image color 
		 (- (x (world->pixel (first line) width height minx maxx miny maxy)) 1)
		 (y (world->pixel (first line)  width height minx maxx miny maxy))
		 (- (x (world->pixel (second line) width height minx maxx miny maxy)) 1)
		 (y (world->pixel (second line)  width height minx maxx miny maxy)))
(imlib:draw-line image color 
		 (- (x (world->pixel (first line) width height minx maxx miny maxy)) 0)
		 (- (y (world->pixel (first line)  width height minx maxx miny maxy)) 1)
		 (- (x (world->pixel (second line) width height minx maxx miny maxy)) 0)
		 (- (y (world->pixel (second line)  width height minx maxx miny maxy)) 1)))

(define (remove-the symbol) (string->symbol (second (pregexp-split "-" (symbol->string symbol)))))


(define (animate-track track objects width height)
 (let loop ((track track)
	    (trace '())
	    (frame 0))
  (if (null? track)
      '()
  (let* ((image (imlib:create width height)))
   (imlib:fill-rectangle image 0 0 width height `#(255 255 255)) 
   (for-each
    (lambda (obj)
     (draw-object-on-floorplan obj image width height -4.1 4.1 -4.1 4.1))
    objects)
   (draw-object-on-floorplan (list 'the-start (vector 0 0)) image width height -4.1 4.1 -4.1 4.1)
   (for-each 
    (lambda (pair)
     (imlib:draw-line image `#(0 0 0) 
		      (x (world->pixel (first pair) width height -4.1 4.1 -4.1 4.1))
		      (y (world->pixel (first pair)  width height -4.1 4.1 -4.1 4.1))
		      (x (world->pixel (second pair) width height -4.1 4.1 -4.1 4.1))
		      (y (world->pixel (second pair)  width height -4.1 4.1 -4.1 4.1))))
    (list (list `#(-4 -4) `#(-4 4))
     (list `#(-4 4) `#(4 4))
     (list `#(4 4) `#(4 -4))
     (list `#(4 -4) `#(-4 -4))

     ;; (list `#(-3 -2.62) `#(-3 3.93))
     ;; 	  (list `#(-3 -2.62) `#(3.05 -2.62))
     ;; 	  (list `#(3.05 3.93) `#(3.05 -2.62))
     ;; 	  (list `#(3.05 3.93) `#(-3.0 3.93))
     ;; 	  (list `#(-1.37 -2.62) `#(-1.37 3.93))
     ;; 	  (list `#(0 -2.62) `#(0 3.93))
     ;; 	  (list `#(1.37 -2.62) `#(1.37 3.93))
     ;; 	  (list `#(-3 -1.31) `#(3.05 -1.31))
     ;; 	  (list `#(-3 0) `#(3.05 0))
     ;; 	  (list `#(-3 1.31) `#(3.05 1.31))
     ;; 	  (list `#(-3 2.62) `#(3.05 2.62))
	  ))
   (draw-world-robot image
		     (vector (first (first track))
			     (second (first track)))
		     (third (first track))
		     .2
		     width height -4.1 4.1 -4.1 4.1)
(when (not (null? trace))
 (draw-trace2 trace image width height -4.1 4.1 -4.1 4.1))
   (imlib:save image (format #f "/tmp/animation/frame-~a.png" (number->padded-string-of-length frame 4)))
   (imlib:free image)
;;(show-image image)
(loop (rest track) (cons (list->vector (first track)) trace) (+ frame 1))))))



(define (animate-track-with-boxes track detections-movie objects width height)
 (let ((max-score (maximum (map z (join (map vector->list detections-movie))))))
 (let loop ((track track)
	    (trace '())
	    (frame 0)
	    (detections-movie detections-movie))
  (if (null? track)
      '()
  (let* ((image (imlib:create width height)))
   (imlib:fill-rectangle image 0 0 width height `#(255 255 255)) 
   (for-each
    (lambda (obj)
     (draw-object-on-floorplan obj image width height -4.1 4.1 -4.1 4.1))
    objects)
   (draw-object-on-floorplan (list 'the-start (vector 0 0)) image width height -4 4 -4 4)
   (for-each 
    (lambda (pair)
     (imlib:draw-line image `#(0 0 0) 
   		      (x (world->pixel (first pair) width height -4.1 4.1 -4.1 4.1))
   		      (y (world->pixel (first pair)  width height -4.1 4.1 -4.1 4.1))
   		      (x (world->pixel (second pair) width height -4.1 4.1 -4.1 4.1))
   		      (y (world->pixel (second pair)  width height -4.1 4.1 -4.1 4.1))))
    (list
     (list `#(-4 -4) `#(-4 4))
     (list `#(-4 4) `#(4 4))
     (list `#(4 4) `#(4 -4))
     (list `#(4 -4) `#(-4 -4))
     
     ;; (list `#(-3 -2.62) `#(-3 3.93))
     ;; 	  (list `#(-3 -2.62) `#(3.05 -2.62))
     ;; 	  (list `#(3.05 3.93) `#(3.05 -2.62))
     ;; 	  (list `#(3.05 3.93) `#(-3.0 3.93))
   	  ;; (list `#(-1.37 -2.62) `#(-1.37 3.93))
   	  ;; (list `#(0 -2.62) `#(0 3.93))
   	  ;; (list `#(1.37 -2.62) `#(1.37 3.93))
   	  ;; (list `#(-3 -1.31) `#(3.05 -1.31))
   	  ;; (list `#(-3 0) `#(3.05 0))
   	  ;; (list `#(-3 1.31) `#(3.05 1.31))
   	  ;; (list `#(-3 2.62) `#(3.05 2.62))
	  ))
   (draw-world-robot image
		     (vector (first (first track))
			     (second (first track)))
		     (third (first track))
		     .2
		     width height -4.1 4.1 -4.1 4.1)
   (for-each-vector
    (lambda (b)
     (let* ((w (dtrace "w"(vector-ref b 3)))
	   (pw (dtrace "pw" (magnitude (v- (vector (/ width 2) (/ height 2)) (world->pixel (vector w 0) width height -4.1 4.1 -4.1 4.1))))))
     (imlib:draw-rectangle image
			   (- (x (world->pixel (vector (x b) (y b)) width height -4.1 4.1 -4.1 4.1)) 0)
			   (- (y (world->pixel (vector (x b) (y b)) width height -4.1 4.1 -4.1 4.1)) 0)
			   pw
			   pw
			   (vector (* (/ (z b) max-score) 255) 0 0))))
    (first detections-movie))
(when (not (null? trace))
 (draw-trace2 trace image width height -4.1 4.1 -4.1 4.1))
   (imlib:save image (format #f "/tmp/animation/frame-~a.png" (number->padded-string-of-length frame 4)))
   (imlib:free image)
;;(show-image image)
(loop (rest track) (cons (list->vector (first track)) trace) (+ frame 1) (rest detections-movie)))))))

(define (new-animate-track-with-boxes path  ;;path=main floorplan path
				      testdir  ;;testdir=dir under path where frame-data and results are
				      outdir
				      width
				      height
				      dummy-f
				      dummy-g
				      min-x
				      max-x
				      min-y
				      max-y)
 ;;abort if files aren't there
 (if (not (file-exists? (format #f "~a/track.sc" path)))
     (dtrace
      (format #f "missing ~a/track.sc, new-animate-track-with-boxes aborted" path) #f))
 (if (not (file-exists? (format #f "~a/~a/frame-data-~a-~a.sc"
				path
				testdir
				(number->padded-string-of-length dummy-f 3)
				(number->padded-string-of-length dummy-g 3))))
     (dtrace
      (format #f "missing ~a/~a/frame-data-*.sc, new-animate-track-with-boxes aborted"
	      path
	      testdir) #f))
 (if (not (file-exists? (format #f "~a/~a/results-~a-~a.sc"
				path
				testdir
				(number->padded-string-of-length dummy-f 3)
				(number->padded-string-of-length dummy-g 3))))
     (dtrace
      (format #f "missing ~a/~a/results-*.sc, new-animate-track-with-boxes aborted"
	      path
	      testdir) #f))
 ;;if we get here, we have the data files we need
 (rm (format #f "/tmp/~a" outdir))
 (mkdir-p (format #f "/tmp/~a" outdir))
 (let ((track (downsample-list-by-factor
	       (read-object-from-file (format #f "~a/track.sc" path))
		5))
       (boxes (first (read-object-from-file
		      (format #f "~a/~a/frame-data-~a-~a.sc"
			      path
			      testdir
			      (number->padded-string-of-length dummy-f 3)
			      (number->padded-string-of-length dummy-g 3)))))
       (detections-movie
	(map (lambda (frame-boxes)
	      (map-vector (lambda (b)
			   (vector (vector-ref b 5)
				   (vector-ref b 6)
				   (vector-ref b 4)
				   (vector-ref b 7)))
			  frame-boxes))
	     boxes)) ;;SORT THESE before drawing on image
       (scores (map (lambda (x) (vector-ref x 4)) (join (map vector->list boxes))))
       (score-mean (list-mean scores))
       (score-variance (list-variance scores))
       (score-std (sqrt score-variance))
       (max-score (+ score-mean (* 1 score-std)))
       (min-score (- score-mean (* 1 score-std)))

       (selected-index (first (read-object-from-file
			       (format #f "~a/~a/frame-data-~a-~a.sc"
				       path
				       testdir
				       (number->padded-string-of-length dummy-f 3)
				       (number->padded-string-of-length dummy-g 3)))))
       )
  ;;START HERE-->combine inner loop of animate-house-tracks with animate-track-with-boxes
  (let loop ((track track)
	     (trace '())
	     (frame 0)
	     (detections-movie detections-movie)) 
   (if (null? track)
       '()
       (let* ((image (imlib:create width height)))
	(imlib:fill-rectangle image 0 0 width height `#(255 255 255)) 
	(draw-object-on-floorplan (list 'the-start (vector 0 0)) image width height -4 4 -4 4)
	(for-each 
	 (lambda (pair)
	  (imlib:draw-line image `#(0 0 0) 
			   (x (world->pixel (first pair) width height -4.1 4.1 -4.1 4.1))
			   (y (world->pixel (first pair)  width height -4.1 4.1 -4.1 4.1))
			   (x (world->pixel (second pair) width height -4.1 4.1 -4.1 4.1))
			   (y (world->pixel (second pair)  width height -4.1 4.1 -4.1 4.1))))
	 (list
	  (list `#(-4 -4) `#(-4 4))
	  (list `#(-4 4) `#(4 4))
	  (list `#(4 4) `#(4 -4))
	  (list `#(4 -4) `#(-4 -4))
     
     ;; (list `#(-3 -2.62) `#(-3 3.93))
     ;; 	  (list `#(-3 -2.62) `#(3.05 -2.62))
     ;; 	  (list `#(3.05 3.93) `#(3.05 -2.62))
     ;; 	  (list `#(3.05 3.93) `#(-3.0 3.93))
   	  ;; (list `#(-1.37 -2.62) `#(-1.37 3.93))
   	  ;; (list `#(0 -2.62) `#(0 3.93))
   	  ;; (list `#(1.37 -2.62) `#(1.37 3.93))
   	  ;; (list `#(-3 -1.31) `#(3.05 -1.31))
   	  ;; (list `#(-3 0) `#(3.05 0))
   	  ;; (list `#(-3 1.31) `#(3.05 1.31))
   	  ;; (list `#(-3 2.62) `#(3.05 2.62))
	  ))
   (draw-world-robot image
		     (vector (first (first track))
			     (second (first track)))
		     (third (first track))
		     .2
		     width height -4.1 4.1 -4.1 4.1)
   (for-each-vector
    (lambda (b)
     (let* ((w (dtrace "w"(vector-ref b 3)))
	   (pw (dtrace "pw" (magnitude (v- (vector (/ width 2) (/ height 2)) (world->pixel (vector w 0) width height -4.1 4.1 -4.1 4.1))))))
     (imlib:draw-rectangle image
			   (- (x (world->pixel (vector (x b) (y b)) width height -4.1 4.1 -4.1 4.1)) 0)
			   (- (y (world->pixel (vector (x b) (y b)) width height -4.1 4.1 -4.1 4.1)) 0)
			   pw
			   pw
			   (vector (* (/ (z b) max-score) 255) 0 0))))
    (first detections-movie))
(when (not (null? trace))
 (draw-trace2 trace image width height -4.1 4.1 -4.1 4.1))
   (imlib:save image (format #f "/tmp/~a/frame-~a.png" outdir (number->padded-string-of-length frame 4)))
   (imlib:free image)
;;(show-image image)
(loop (rest track) (cons (list->vector (first track)) trace) (+ frame 1) (rest detections-movie)))))))

(define (downsample-to-length l l2)
 (let ((l1 (length l)))
 (let loop ((e .5)
	    (l l))
  (dtrace "e" e)
  (if (null? l)
      '()
      (if (> (+ e (/ l2 l1)) 1)
	  (cons (first l) (loop (- (+ e (/ l2 l1)) 1) (rest l)))
	  (loop (+ e (/ l2 l1)) (rest l)))))))


;; (define (make-animation-with-boxes)
;;  (define detections-movie (map (lambda (frame-boxes) (map-vector (lambda (b) (vector (vector-ref b 5) (vector-ref b 6) (vector-ref b 4) (vector-ref b 7))) frame-boxes)) (first frame-data)))
;;  ;; (define detections-movie (map (lambda (frame-boxes) (map-vector (lambda (b) (vector (vector-ref b 5) (vector-ref b 6) (vector-ref b 4))) frame-boxes)) (first frame-data)))
;;  (animate-track-with-boxes (downsample-to-length (sublist track 120 1991) 365)  detections-movie (first (first (first gen))) 400 400))

;; (define (make-animation)
;;  (define detections-movie (map (lambda (frame-boxes) (map-vector (lambda (b) (vector (vector-ref b 5) (vector-ref b 6) (vector-ref b 4))) frame-boxes)) (first frame-data)))
;;  (animate-track (sublist (downsample-to-length (sublist track 120 1991) 365) 0 339)  (first (first (first gen))) 400 400))

(define (get-x-y-max-min tracks)
 (let ((x (map first (map vector->list (join (map vector->list tracks)))))
       (y (map second (map vector->list (join (map vector->list tracks))))))
  (list (list (maximum x) (minimum x)) (list (maximum y) (minimum y)))))

(define *house-x-y* (read-object-from-file "/aux/sbroniko/vader-rover/logs/house-test-12nov15/house-x-y.sc"))
        ;;(get-x-y-max-min (dataset-read-house-tracks)))

(define (animate-house-tracks tracks width height)
 (rm "/tmp/animation/*/")
 (let* ((x-y-max-min *house-x-y*);;(get-x-y-max-min tracks))
	(the-max (* 1.1 (max (first (first x-y-max-min))
			     (first (second x-y-max-min)))))
	(the-min (* 1.1 (min (second (first x-y-max-min))
			     (second (second x-y-max-min)))))
	(max-x the-max)
	(max-y the-max)
	(min-x the-min)
	(min-y the-min))
  (let outer-loop ((tracks tracks)
		   (i 0))
   (if (null? tracks)
       #f
       (begin
	(mkdir-p (format #f "/tmp/animation/~a"
			 (number->padded-string-of-length i 2)))
	(let* ((track (downsample-list-by-factor
		       (map vector->list (vector->list (first tracks)))
		       5)))
	 (let loop ((track track)
		    (trace '())
		    (frame 0))
	  (if (null? track)
	      '()
	      (let* ((image (imlib:create width height)))
	       (imlib:fill-rectangle image 0 0 width height `#(255 255 255)) 
	       (draw-object-on-floorplan (list 'the-start (vector 0 0))
					 image width height min-x max-x min-y max-y)
	       (draw-world-robot image
				 (vector (first (first track))
					 (second (first track)))
				 (third (first track))
				 .2
				 width height min-x max-x min-y max-y)
	       (when (not (null? trace))
		(draw-trace2 trace image width height min-x max-x min-y max-y))
	       (imlib:save image (format #f "/tmp/animation/~a/frame-~a.png"
					 (number->padded-string-of-length i 2)
					 (number->padded-string-of-length frame 4)))
	       (imlib:free image)
	       ;;(show-image image)
	       (loop (rest track) (cons (list->vector (first track)) trace) (+ frame 1))))))
	(outer-loop (rest tracks) (+ i 1)))))))

(define (split-videos-to-frames basedir fps)
 (let* ((rundirs (system-output (format #f "ls -d ~a/*/" basedir)))
	(tempdir (format #f "~a/../tmp" basedir)))
  (for-each-indexed
   (lambda (dir i)
    (mkdir-p (format #f "~a/~a" tempdir
		     (number->padded-string-of-length i 2)))
    (system (format #f
		    "ffmpeg -i ~a/video_front.avi -r ~a ~a/~a/cam_front0%05d.png"
		    dir fps tempdir
		    (number->padded-string-of-length i 2)))
    (system (format #f
		    "ffmpeg -i ~a/video_pano.avi -r ~a ~a/~a/cam_pano0%05d.png"
		    dir fps tempdir
		    (number->padded-string-of-length i 2))))
    rundirs)))


;;need to convert trace images to same height as video (480px) and move to tempdir
(define (resize-and-move basedir height)
 (let* ((tempdir (format #f "~a/../tmp" basedir))
	(camdirs (system-output (format #f "ls -d ~a/*/" tempdir)))
	(framedirs (system-output (format #f "ls -d /tmp/animation/*/")))
	)
  (for-each
   (lambda (framedir camdir)
    (dtrace "camdir: " camdir)
    (let* ((imgs (system-output (format #f "ls ~a" framedir))))
     (for-each
      (lambda (img)
       (system (format #f "convert ~a/~a -resize x~a ~a/~a"
		       framedir img height camdir img)))
      imgs)))
    framedirs camdirs)))

(define (move-traces basedir)
 (let* ((tempdir (format #f "~a/../tmp" basedir))
	(camdirs (system-output (format #f "ls -d ~a/*/" tempdir)))
	(framedirs (system-output (format #f "ls -d /tmp/animation/*/")))
	)
  (for-each
   (lambda (framedir camdir)
    (dtrace "moving from: " framedir)
    (dtrace "to: " camdir)
    (let* ((imgs (system-output (format #f "ls ~a" framedir))))
     (for-each
      (lambda (img)
       (system (format #f "cp ~a/~a ~a/~a"
		       framedir img camdir img)))
      imgs)))
    framedirs camdirs)))


(define (join-3-images img1 img2 img3 num outdir)
 (system (format #f "montage -tile 3x1 -geometry +0+0 ~a ~a ~a ~a/joined-~a.png"
		 img1 img2 img3 outdir (number->padded-string-of-length num 6))))

;; ;;this makes frames of front-pano-trace
(define (make-3-panel-frames basedir)
 (let* ((tempdir (format #f "~a/../tmp" basedir))
	(camdirs (system-output (format #f "ls -d ~a/*/" tempdir))))
  (for-each
   (lambda (camdir)
    (dtrace "camdir: " camdir)
    (let* ((fronts (system-output (format #f "ls ~a/cam_front*" camdir)))
	   (panos (system-output (format #f "ls ~a/cam_pano*" camdir)))
	   (traces (system-output (format #f "ls ~a/frame*" camdir)))
	   ;; (numfronts (length fronts))
	   ;; (numtraces (length traces))
	   )
     (let loop ((fronts fronts)
		 (panos panos)
		 (traces traces)
		 (i 0))
     	     (if (or (null? fronts) (null? panos) (null? traces))
     		 (dtrace "complete" #f)
     		 (begin
     		  (join-3-images (first fronts)
     				 (first panos)
     				 (first traces)
     				 i
     				 camdir)
     		  (loop (rest fronts)
			(rest panos)
			(rest traces)
			(+ i 1)))))
     
     ;; (cond ((< numfronts numtraces)
     ;; 	    (let loop1 ((fronts fronts)
     ;; 			(panos panos)
     ;; 			(traces (sublist traces 0 numfronts))
     ;; 			(i 0))
     ;; 	     (if (or (null? fronts) (null? panos))
     ;; 		 (dtrace "complete in cond #1" #f)
     ;; 		 (begin
     ;; 		  (join-3-images (first fronts)
     ;; 				 (first panos)
     ;; 				 (first traces)
     ;; 				 i
     ;; 				 camdir)
     ;; 		  (loop1 (rest fronts)
     ;; 			 (rest panos)
     ;; 			 (rest traces)
     ;; 			 (+ i 1))))))
     ;; 	   ((< numtraces numfronts)
     ;; 	    (let loop2 ((fronts (sublist fronts 0 numtraces))
     ;; 			(panos panos)
     ;; 			(traces traces)
     ;; 			(i 0))
     ;; 	     (if (or (null? fronts) (null? panos))
     ;; 		 (dtrace "complete in cond #2" #f)
     ;; 		 (begin
     ;; 		  (join-3-images (first fronts)
     ;; 				 (first panos)
     ;; 				 (first traces)
     ;; 				 i
     ;; 				 camdir)
     ;; 		  (loop2 (rest fronts)
     ;; 			 (rest panos)
     ;; 			 (rest traces)
     ;; 			 (+ i 1))))))
     ;; 	   (else ;;if we get here, numfronts = numtraces
     ;; 	    (let loop3 ((fronts fronts)
     ;; 			(panos panos)
     ;; 			(traces traces)
     ;; 			(i 0))
     ;; 	     (if (or (null? fronts) (null? panos))
     ;; 		 (dtrace "complete in else" #f)
     ;; 		 (begin
     ;; 		  (join-3-images (first fronts)
     ;; 				 (first panos)
     ;; 				 (first traces)
     ;; 				 i
     ;; 				 camdir)
     ;; 		  (loop3 (rest fronts)
     ;; 			 (rest panos)
     ;; 			 (rest traces)
     ;; 			 (+ i 1)))))))
     ))
   camdirs)))

;;this takes frames and makes video
;;ffmpeg -framerate 25 -i 0%04d.png -b 2048k -r 25 out.avi
(define (make-frames-into-video basedir fps)
 (let* ((rundirs (system-output (format #f "ls -d ~a/*/" basedir)))
	(tempdir (format #f "~a/../tmp" basedir))
	(camdirs (system-output (format #f "ls -d ~a/*/" tempdir))))
  (if (not (= (length rundirs) (length camdirs)))
      (dtrace "error: (length rundirs) != (length camdirs) in make-frames-into-video" #f)
      (let loop ((rundirs rundirs)
		 (camdirs camdirs))
       (if (null? rundirs)
	   (dtrace "make-frames-into-video complete" #f)
	   (begin
	    (system
	     (format #f
		     "ffmpeg -framerate ~a -i ~a/joined-0%05d.png -b 2048k -r ~a ~a/merged.avi"
		     fps (first camdirs) fps (first rundirs)))
	    (loop (rest rundirs) (rest camdirs))))))))

(define (partial-wrapper basedir fps)
 ;;(split-videos-to-frames basedir fps)
 ;;(move-traces basedir)
 (make-3-panel-frames basedir)
 (make-frames-into-video basedir fps)
 (rm "/tmp/animation/*/")
 (rm (format #f "~a/../tmp" basedir))
 )

;;FIXME--***THINK ABOUT restructuring the above stuff so that it instead does all
;; steps on a single video in one shot, then doing a wrapper that sends it multiple
;; videos to do sequentially.  Don't forget to clean up as well.  Probably also
;; need to read all tracks to determine max and min x and y (LOOK AT THIS--might
;; be doing it wrong).


;;functions copied from generate-msee1-dataset.sc (renamed to avoid conflicts)
;;for reading tracks

(define (downsample-list-by-factor l f)
 (removeq #f
	  (map-indexed
	   (lambda (e i)
	    (if (= (modulo i f) 0)
		e
		#f))
	   l)))

;;FIXME--NEED TO RENAME THESE

(define (read-robot-estimated-track-from-log-file filename)
 (let* ((lines (read-file filename))
	(valid (remove-if-not (lambda (line)
				      (let*
					((split-line (pregexp-split ":" line)))
				       (and (> (length split-line) 6)
					    (equal? (first split-line) "ESTIMATE"))))
				     lines))
	(pose (map (lambda (line)
		    (let*
		      ((split-line (pregexp-split ":" line)))
		     (vector (string->number (third split-line))
			     (string->number (fifth split-line)))))
		   valid)))
pose))


(define (read-robot-estimated-track-from-log-file-lists filename)
 (let* ((lines (read-file filename))
	(valid (remove-if-not (lambda (line)
				      (let*
					((split-line (pregexp-split ":" line)))
				       (and (> (length split-line) 6)
					    (equal? (first split-line) "ESTIMATE"))))
				     lines))
	(pose (map (lambda (line)
		    (let*
		      ((split-line (pregexp-split ":" line)))
		     (list (string->number (third split-line))
			   (string->number (fifth split-line))
			   (string->number (seventh split-line)))))
		   valid)))
pose))

(define (read-house-tracks) ;;rewrite to do just 1 at a time??
 (map
  (lambda (run-dir)
   (let* ((logfile
	   (format #f
		   "/aux/sbroniko/vader-rover/logs/house-test-12nov15/~a/imu-log.txt"
		     run-dir))
	    (trackfile
	     ;;(dtrace "trackfile"
		     (format #f
			     "/aux/sbroniko/vader-rover/logs/house-test-12nov15/~a/track.sc"
			     run-dir)))
      (dtrace "floorplan:" (list run-dir))
      (if (file-exists? logfile)
	  (write-object-to-file
	   (read-robot-estimated-track-from-log-file-lists logfile)
	   trackfile)
	  (dtrace "no valid trace found"
		  (write-object-to-file
		   (map-n (lambda (i) (list 0.000000 0.000000 1.570796)) 100)
		   trackfile))
	  )
	  ))
    (system-output
     (format #f "ls /aux/sbroniko/vader-rover/logs/house-test-12nov15"))))

(define (dataset-read-house-tracks) 
 (let* ((directory "/aux/sbroniko/vader-rover/logs/house-test-12nov15")
	 ;;"/home/sbroniko/vader-rover/logs/house-test-12nov15")
	(run-dirs (system-output (format #f "ls -d ~a/*/" directory ))))
  (map
   (lambda (run-dir)
    (dtrace "run-dir:" run-dir)
    (when (file-exists? (dtrace "" (format #f "~a/track.sc" run-dir)))
     (let* ((track (list->vector (map list->vector (read-object-from-file (format #f "~a/track.sc" run-dir))))))
      track)))
   run-dirs)))
;;end functions to rename/rewrite from generate-msee1-dataset.sc

