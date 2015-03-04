(load "/home/sbroniko/codetection/source/rover-projection.sc")
;;(load "/home/sbroniko/codetection/source/toollib-perspective-projection.sc")
;;(load "/home/sbroniko/codetection/source/sentence-codetection/codetection.sc")

;; (define-command
;;  (main (at-most-one
;; 	("video" video? (video-path "video-path" string-argument "")))
;;        (at-most-one
;; 	("top-k" top-k? (top-k "top-k" integer-argument 100)))
;;        (at-most-one
;; 	("downsample" downsample? (downsample "rate" integer-argument 1)))
;;        (at-most-one
;; 	("box-size" box-size? (box-size "size" integer-argument 64))))

(define (select-frames video-path first-frame num-frames)
 (let ((video (video->frames 1 video-path)))
  (if (> (+ first-frame num-frames) (length video))
      (error 'select-frames "select-frames: too many frames requested")
      (let loop ((frames '())
		 (vid video)
		 (count 0)
		 (idx 0))
       (if (= count num-frames)
	   (reverse frames) ;;done
	   (if (< idx first-frame)
	       (loop frames (rest vid) count (+ 1 idx)) ;;move to first frame
	       ;;add current frame in vid to frames
	       (loop (cons (first vid) frames) (rest vid) (+ 1 count) (+ 1 idx))))))))
 
(define (run-codetection-with-frames frames top-k box-size)
 (let* ((proposals-similarity (proposals&similarity-with-frames top-k box-size frames))
	(proposals (map (lambda (boxes) (map (lambda (x) (but-last x))
					     (matrix->list-of-lists boxes)))
			(first proposals-similarity)))
	(f (map (lambda (boxes) (map fifth (matrix->list-of-lists boxes)))
		(first proposals-similarity)))
	(g (map (lambda (sim) (matrix->list-of-lists sim))
		(second proposals-similarity)))
	(f-c (easy-ffi:double-to-c 2 f))
	(g-c (easy-ffi:double-to-c 3 g))
	(boxes-c (list->c-exact-array (malloc (* c-sizeof-int (length f)))
				      (map-n (lambda _ 0) (length f))
				      c-sizeof-int #t))	
	(score (bp-object-inference f-c g-c (length f) top-k boxes-c))
	(boxes (c-exact-array->list boxes-c c-sizeof-int (length f) #t)))
  (free boxes-c)
  (easy-ffi:free 2 f f-c)
  (easy-ffi:free 3 g g-c)
  ;; (pp (map (lambda (b pool) (list b (list-ref pool b)))
  ;; 	   boxes proposals))
  (map (lambda (b pool) (list-ref pool b))
       boxes proposals)
  ))

(define (run-codetection-with-video video-path top-k downsample box-size)
 (let* ((proposals-similarity (proposals&similarity top-k box-size downsample video-path))
	(proposals (map (lambda (boxes) (map (lambda (x) (but-last x))
					     (matrix->list-of-lists boxes)))
			(first proposals-similarity)))
	(f (map (lambda (boxes) (map fifth (matrix->list-of-lists boxes)))
		(first proposals-similarity)))
	(g (map (lambda (sim) (matrix->list-of-lists sim))
		(second proposals-similarity)))
	(f-c (easy-ffi:double-to-c 2 f))
	(g-c (easy-ffi:double-to-c 3 g))
	(boxes-c (list->c-exact-array (malloc (* c-sizeof-int (length f)))
				      (map-n (lambda _ 0) (length f))
				      c-sizeof-int #t))	
	(score (bp-object-inference f-c g-c (length f) top-k boxes-c))
	(boxes (c-exact-array->list boxes-c c-sizeof-int (length f) #t)))
  (free boxes-c)
  (easy-ffi:free 2 f f-c)
  (easy-ffi:free 3 g g-c)
  ;; (pp (map (lambda (b pool) (list b (list-ref pool b)))
  ;; 	   boxes proposals))
  (map (lambda (b pool) (list-ref pool b))
	   boxes proposals)
  ))

(define (align-frames-with-poses datapath num-frames)
 (let* (;;(frames (video->frames 1 (format #f "~a/video_front.avi" datapath)))
	(cam-timing (read-camera-timing
		     (format #f "~a/camera_front.txt" datapath)))
	(timing-file (if (file-exists? (format #f "~a/imu-log-with-estimates.txt"
					       datapath))
			 (format #f "~a/imu-log-with-estimates.txt" datapath)
			 (format #f "~a/imu-log.txt" datapath)))
	(poses-with-timing (read-robot-estimated-pose-from-log-file timing-file)))
  (if (not (= num-frames (length cam-timing)))
      (dtrace "error: num-frames != cam-timing" #f)
      (let loop ((cam-timing cam-timing)
		 (poses poses-with-timing)
		 (previous-pose #f)
		 (frame-poses '()))
       (if (or (null? poses) (null? cam-timing))
	   (begin
	   ;;;need to error check length of pose list here
	    ;;(dtrace "length = " (length frame-poses))
	    (if (not (= num-frames (length frame-poses)))
		(dtrace "error: num-frames != frame-poses" #f)
		(reverse frame-poses)))
	   ;; (if (< (first cam-timing) (first (first poses)))
	   ;;     ;;(dtrace "error: first frame earlier than first pose" frame-poses)  
	   (if previous-pose
	       (if (< (abs (- (first previous-pose) (first cam-timing)))
		      (abs (- (first (first poses)) (first cam-timing))))
		    (loop (rest cam-timing)
			  (rest poses)
			  (first poses)
			  (cons (second (first poses)) frame-poses))
		   (loop cam-timing
			 (rest poses)
			 (first poses)
			 frame-poses))
	       (loop cam-timing
		     (rest poses)
		     (first poses)
		     frame-poses)))))))
	       
       
			    
       
(define (frame-test)
 (let* ((video-path "/home/sbroniko/codetection/test-run-data/video_front.avi")
	(starting-frame 12)
	(num-frames 18)
	(top-k 100)
	(box-size 64)
	(frames (select-frames video-path starting-frame num-frames))
	(boxes (run-codetection-with-frames frames top-k box-size))
	(frame-number 0))
  (if (= (length frames) (length boxes))
      (let loop ((images (select-frames video-path starting-frame num-frames))
		 (boxes boxes)
		 (n frame-number))
       (if (or (null? images)
	       (null? boxes))
	   (dtrace "done" #f)
	   (let* ((box (first boxes))
		  (image (first images))
		  (x1 (first box))
		  (y1 (second box))
		  (w (- (third box) (first box)))
		  (h (- (fourth box) (second box))))
	    (imlib:draw-rectangle image x1 y1 w h (vector 0 255 0))
	    ;;(show-image image)
	    ;; ((c-function void ("imlib_context_set_image" imlib-image))
	    ;;  (imlib-image-handle image))
	    ;; ((c-function void ("imlib_save_image" string)) "/tmp/foo.ppm")
	    (imlib:save image (format #f "/tmp/detection-images-~a.png"
	    			      (number->padded-string-of-length n 5)))
	    (dtrace "saved image" n)
	    ;;mlib:free-image-and-decache image)
	    (loop (rest images) (rest boxes) (+ n 1)))))
      (dtrace "error: frames != boxes" #f))))


(define (scott-proposals&similarity-with-frames
	 top-k box-size alpha beta frames poses tt)
 (let* ((one-frame (first frames))
	(height (imlib:height one-frame))
	(width (imlib:width one-frame)))
  (start-matlab!)
  (scheme->matlab! "poses" poses)
  (matlab (format #f "frames=zeros(~a,~a,~a,~a,'uint8');" height width 3 tt))
  ;; convert frames to matlab matrix
  ;;(format #f "before for-each-indexed")
  (for-each-indexed
   (lambda (frame i)
    ;;(format #t "converting imlib ~a/~a to matlab matrix...~%" i tt)
    (with-temporary-file
     "/tmp/imlib-frame.ppm"
     (lambda (tmp-frame)
      ;; write scheme frame to file
      (imlib:save-image frame tmp-frame)
      ;; read file as matlab frame
      (matlab (format #f "frame=imread('~a');" tmp-frame))
      (matlab (format #f "frames(:,:,:,~a)=uint8(frame);" (+ i 1)))))
    (imlib:free-image-and-decache frame) ;;might want to comment this out
              ;;but could cause a memory leak if I don't free image elsewhere
    )    
   frames)
  ;;(matlab (format #f "imshow(frames(:,:,:,20));"))
  ;; call proposals_and_similarity
  ;; (matlab (format #f "[bboxes,simi]=proposals_and_similarity(~a,frames,~a);"
  ;; 		  top-k box-size))
  (matlab (format #f "[bboxes,simi]=scott_proposals_similarity2(~a,~a,frames,poses);";,~a,~a);";dropping alpha and beta
		  top-k box-size)); alpha beta))
  ;; convert matlab variables to scheme
  (list (map-n (lambda (t)
		(matlab (format #f "tmp=bboxes(:,:,~a);" (+ t 1)))
		(matlab-get-variable "tmp"))
	       tt)
	(map-n (lambda (t)
		(matlab (format #f "tmp=simi(:,:,~a);" (+ t 1)))
		(matlab-get-variable "tmp"))
	       (- tt 1)))))


(define (scott-run-codetection-full-video data-path top-k box-size alpha beta)
 (let* ((video-path (format #f "~a/video_front.avi" data-path))
	(frames (video->frames 1 video-path))
	(tt (length frames))
	(poses (align-frames-with-poses data-path tt))
	;;NEED REPLACEMENT CALL FOR LINE BELOW WITH MY PROP-SIM CODE
	;;(proposals-similarity (proposals&similarity top-k box-size downsample video-path))
	(proposals-similarity
	 (scott-proposals&similarity-with-frames top-k
						 box-size
						 alpha
						 beta
						 frames
						 poses
						 tt))
	(proposals (map (lambda (boxes) (map (lambda (x) (but-last x))
					     (matrix->list-of-lists boxes)))
			(first proposals-similarity)))
	(f (map (lambda (boxes) (map fifth (matrix->list-of-lists boxes)))
		(first proposals-similarity)))
	(g (map (lambda (sim) (matrix->list-of-lists sim))
		(second proposals-similarity)))
	(f-c (easy-ffi:double-to-c 2 f))
	(g-c (easy-ffi:double-to-c 3 g))
	(boxes-c (list->c-exact-array (malloc (* c-sizeof-int (length f)))
				      (map-n (lambda _ 0) (length f))
				      c-sizeof-int #t))	
	(score (bp-object-inference f-c g-c (length f) top-k boxes-c))
	(boxes (c-exact-array->list boxes-c c-sizeof-int (length f) #t)))
  (free boxes-c)
  (easy-ffi:free 2 f f-c)
  (easy-ffi:free 3 g g-c)
  ;; (pp (map (lambda (b pool) (list b (list-ref pool b)))
  ;; 	   boxes proposals))
  (map (lambda (b pool) (list-ref pool b))
	   boxes proposals)
  ))	
 
  
(define (frame-test2)
 (let* (;;(data-path "/home/sbroniko/codetection/training-videos/short")
	;;(data-path "/home/sbroniko/codetection/test-run-data")
	(data-path "/home/sbroniko/codetection/testing-data")
	(video-path (format #f "~a/video_front.avi" data-path))
	(top-k 100)
	(box-size 64)
	(alpha 0.2)
	(beta 0.8)
	(boxes (scott-run-codetection-full-video data-path
						 top-k
						 box-size
						 alpha
						 beta)))
  (let loop ((images (video->frames 1 video-path))
	     (boxes boxes)
	     (n 0))
   (if (or (null? images)
	   (null? boxes))
       (dtrace "done" #f)
       (let* ((box (first boxes))
	      (image (first images))
	      (x1 (first box))
	      (y1 (second box))
	      (w (- (third box) (first box)))
	      (h (- (fourth box) (second box))))
	(imlib:draw-rectangle image x1 y1 w h (vector 0 0 255))
	;;(show-image image)
	;; ((c-function void ("imlib_context_set_image" imlib-image))
	;;  (imlib-image-handle image))
	;; ((c-function void ("imlib_save_image" string)) "/tmp/foo.ppm")
	(imlib:save image (format #f "~a/detection-images-~a.png"
				  data-path
				  (number->padded-string-of-length n 5)))
	(dtrace "saved image" n)
	;;(imlib:free-image-and-decache image)
	(loop (rest images) (rest boxes) (+ n 1)))))
      ))

(define (make-frames video-path)
 (let* ((video (format #f "~a/video_front.avi" video-path))
	(output-path (format #f "~a/video-frames" video-path)))
  (let loop ((images (video->frames 1 video))
	     (n 1))
   (if (null? images)
       (dtrace "done" #f)
       (let* ((image (first images)))
	(imlib:save image (format #f "~a/frame-~a.ppm"
				  output-path
				  (number->padded-string-of-length n 4)))
	(loop (rest images) (+ n 1)))))))