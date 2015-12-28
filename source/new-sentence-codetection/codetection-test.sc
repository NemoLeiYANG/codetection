(load "/home/sbroniko/darpa-collaboration/ideas/toollib-multi-process.sc")
;; made edits to this file in rsync-directory-to-server in order to NOT exclude image files
(load "/home/sbroniko/codetection/source/rover-projection.sc")
;;(load "/home/sbroniko/codetection/source/toollib-perspective-projection.sc")
;;(load "/home/sbroniko/codetection/source/sentence-codetection/codetection.sc")
(load "/home/dpbarret/darpa-collaboration/pose-retraining/felz-baum-welch-plotting.sc") ;;for plotting stuff in matlab
(load "/home/sbroniko/codetection/source/new-sentence-codetection/viterbi.sc")


;; (define-command
;;  (main (at-most-one
;; 	("video" video? (video-path "video-path" string-argument "")))
;;        (at-most-one
;; 	("top-k" top-k? (top-k "top-k" integer-argument 100)))
;;        (at-most-one
;; 	("downsample" downsample? (downsample "rate" integer-argument 1)))
;;        (at-most-one
;; 	("box-size" box-size? (box-size "size" integer-argument 64))))


;;CAMERA CALIBRATION INFO
(define *camera-offset* (vector -0.03 0.16 -0.2))
(define *camera-offset-matrix*
 (vector
  (vector 1. 0. 0. -0.03)
  (vector 0. 1. 0. 0.16)
  (vector 0. 0. 1. -0.2)
  (vector 0. 0. 0. 1.)))
(define *camera-k-matrix*
 (vector
  (vector 724.34508362823397 0. 312.32994017160644)
  (vector 0. 724.12307134397406 203.10961045807585)
  (vector 0. 0. 1.)))

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
		(second proposals-similarity)));;change
	(f-c (easy-ffi:double-to-c 2 f))
	(g-c (easy-ffi:double-to-c 3 g));;change
	(boxes-c (list->c-exact-array (malloc (* c-sizeof-int (length f)))
				      (map-n (lambda _ 0) (length f))
				      c-sizeof-int #t))	
	(score (bp-object-inference f-c g-c (length f) top-k boxes-c))
	(boxes (c-exact-array->list boxes-c c-sizeof-int (length f) #t)))
  (free boxes-c)
  (easy-ffi:free 2 f f-c)
  (easy-ffi:free 3 g g-c);;
  ;; (pp (map (lambda (b pool) (list b (list-ref pool b)))
  ;; 	   boxes proposals))
  (map (lambda (b pool) (list-ref pool b))
	   boxes proposals)
  ))

(define (align-frames-with-poses datapath num-frames)
 (let* ((cam-timing (read-camera-timing-new
		     (format #f "~a/camera_front.txt" datapath)))
	(timing-file (format #f "~a/imu-log.txt" datapath))
	(poses-with-timing (read-robot-estimated-pose-from-log-file timing-file)))
  (begin
   ;; (dtrace "in align-frames-with-poses" #f)
   ;; (dtrace (format #f "num-frames = ~a, (length cam-timing) = ~a"
   ;; 		   num-frames (length cam-timing)) #f)
   (if (> num-frames (length cam-timing))
       (dtrace "error: num-frames > cam-timing" #f)
       (let loop ((cam-timing cam-timing)
		  (poses poses-with-timing)
		  (previous-pose #f)
		  (frame-poses '()))
	(if (or (null? poses) (null? cam-timing))
	    (begin
	   ;;;need to error check length of pose list here
	     ;;(dtrace "length = " (length frame-poses))
	     ;; (dtrace (format #f "num-frames = ~a, (length frame-poses) = ~a"
   	     ;; 	   num-frames (length frame-poses)) #f)
	     (if (not (= num-frames (length frame-poses)))
		 ;; (begin
		 ;;  (dtrace "error: num-frames != frame-poses" #f)
		  (if (> num-frames (length frame-poses))
		      (begin
		       (dtrace (format #f
				       "copying poses to end of list: num-frames = ~a, (length frame-poses) = ~a"
				       num-frames (length frame-poses )) #f)
		       (loop cam-timing
			     poses
			     previous-pose
			     (cons (first frame-poses) frame-poses))
		       )
		      (dtrace "error: num-frames < frame-poses" #f))
		  ;; )
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
		      frame-poses))))))))

(define (get-poses-that-match-frames datapath)
 (let* ((cam-timing (read-camera-timing
		     (format #f "~a/camera_front.txt" datapath)))
	(timing-file (if (file-exists? (format #f "~a/imu-log-with-estimates.txt"
					       datapath))
			 (format #f "~a/imu-log-with-estimates.txt" datapath)
			 (format #f "~a/imu-log.txt" datapath)))
	(poses-with-timing (read-robot-estimated-pose-from-log-file timing-file)))
  (let loop ((cam-timing cam-timing)
	     (poses poses-with-timing)
	     (previous-pose #f)
	     (frame-poses '()))
   (if (or (null? poses) (null? cam-timing))
       (reverse frame-poses) ;; done
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
		 frame-poses))))))
       
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

(define (get-matlab-proposals-similarity top-k
					 box-size
					 frames
					 poses
					 alpha-norm
					 beta-norm
					 gamma-norm
					 delta-norm)
 (let* ((num-frames (length frames))
	(one-frame (first frames))
	(height (imlib:height one-frame))
	(width (imlib:width one-frame)))
  ;;(list frames poses)
  (start-matlab!)
  (matlab "addpath(genpath('/home/sbroniko/codetection/source/new-sentence-codetection/'))")
  (scheme->matlab! "poses" poses)
  (matlab (format #f "frames = zeros(~a,~a,~a,~a,'uint8');" height width 3 num-frames))
  ;; convert frames to matlab matrix
  (for-each-indexed
   (lambda (frame i)
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
  ;; call matlab function
  (dtrace "calling new-sentence-codetection/scott_proposals_similarity2" #f)
  (matlab
   (format
    #f
    "[boxes_w_fscore,gscore,num_gscore] = scott_proposals_similarity2(~a,~a,frames,poses,~a,~a,~a);"
    top-k box-size alpha-norm beta-norm gamma-norm))
  ;; convert matlab variables to scheme
  (list (map-n (lambda (t)
		(matlab (format #f "tmp=boxes_w_fscore(:,:,~a);" (+ t 1)))
		(matlab-get-variable "tmp"))
	       num-frames)
	  (matlab-get-variable "gscore")
	  (matlab-get-variable "num_gscore"))

  ))

(define (get-matlab-proposals-similarity-by-frame top-k
						  box-size
						  data-path
						  first-frame;;here first-frame and last-frame
						  last-frame;;start at 1, not 0
						  alpha
						  beta
						  gamma
						  delta)
 (let* ((video-path (format #f "~a/video_front.avi" data-path))
	(all-frames (video->frames 1 video-path))
	(all-poses (align-frames-with-poses data-path (length all-frames)))
	(frames (sublist all-frames (- first-frame 1) last-frame))
	(poses (sublist all-poses (- first-frame 1) last-frame))
	(coeff-sum (+ alpha beta gamma delta))
	(alpha-norm (/ alpha coeff-sum))
	(beta-norm (/ beta coeff-sum))
	(gamma-norm (/ gamma coeff-sum))
	(delta-norm (/ delta coeff-sum)))
  (get-matlab-proposals-similarity top-k
				   box-size
				   frames
				   poses
				   alpha-norm
				   beta-norm
				   gamma-norm
				   delta-norm)))

(define (get-matlab-proposals-similarity-full-video top-k
						    box-size
						    data-path
						    alpha
						    beta
						    gamma
						    delta)
 (let* ((video-path (format #f "~a/video_front.avi" data-path))
	(frames (video->frames 1 video-path))
	(poses (align-frames-with-poses data-path (length frames)))
	(coeff-sum (+ alpha beta gamma delta))
	(alpha-norm (/ alpha coeff-sum))
	(beta-norm (/ beta coeff-sum))
	(gamma-norm (/ gamma coeff-sum))
	(delta-norm (/ delta coeff-sum)))
  (dtrace
   "in new-sentence-codetection/get-matlab-proposals-similarity-full-video" #f)
  (get-matlab-proposals-similarity top-k
				   box-size
				   frames
				   poses
				   alpha-norm
				   beta-norm
				   gamma-norm
				   delta-norm)))

(define (run-codetection-with-proposals-similarity proposals-similarity
						   dummy-f
						   dummy-g)
 ;;(run-codetection-with-video video-path top-k downsample box-size)
 (let* ((top-k (vector-length (first (first proposals-similarity))))
	(proposals-boxes (map (lambda (boxes) (map (lambda (x) (sublist x 0 4))
						   (matrix->list-of-lists boxes)))
			      (first proposals-similarity)))
	(proposals-xy (map (lambda (boxes) (map (lambda (x) (sublist x 5 7))
						(matrix->list-of-lists boxes)))
			   (first proposals-similarity)))
	(f (map (lambda (boxes) (map fifth (matrix->list-of-lists boxes)))
		(first proposals-similarity)))
	(g (matrix->list-of-lists (second proposals-similarity)))
	(f-c (easy-ffi:double-to-c 2 f))
	(g-c (easy-ffi:double-to-c 2 g))
	(num-g (exact-round (x (x (third proposals-similarity)))))
	(boxes-c (list->c-exact-array (malloc (* c-sizeof-int (length f)))
				      (map-n (lambda _ 0) (length f))
				      c-sizeof-int #t))	
	(score (bp-object-inference-new f-c g-c (length f)
					top-k dummy-f dummy-g num-g boxes-c))
	(boxes (c-exact-array->list boxes-c c-sizeof-int (length f) #t))
	;;START HERE
	)
  ;;  (dtrace "before (free boxes-c)" #f)
  (free boxes-c)
  ;;  (dtrace "before (easy-ffi:free 2 f f-c)" #f)
  (easy-ffi:free 2 f f-c)
  ;;  (dtrace "before (easy-ffi:free 2 g g-c)" #f)
  (easy-ffi:free 2 g g-c);;

  ;;output
  (list boxes ;;box numbers
	(map (lambda  ;;xy locations as list (empty list if dummy)
	       (b prop-xy) (list-ref prop-xy b))
	     boxes
	     (map (lambda (prop-xy) (append prop-xy '(())))
		  proposals-xy))
	(map (lambda ;;pixel locations as list (empty list if dummy)
	       (b prop-boxes) (list-ref prop-boxes b))
	     boxes
	     (map (lambda (prop-boxes) (append prop-boxes '(())))
		  proposals-boxes))
	;;(ensure-scores ) is the function to make sure that the below list is
	;;included in the results file
	(map (lambda ;;f-score value (NOT A LIST) (dummy-f, not empty list, if dummy)
	       (b scores) (list-ref scores b))
	     boxes 
	     ;;(map (lambda (scores) (append scores '(())))
	     (map (lambda (scores) (append scores (list dummy-f)))
		  f))
	
	     )

  ;;(list boxes) ;;just box indices
  ))

(define (get-matlab-data-house-test-new2
	 path top-k ssize dummy-f dummy-g
	 data-output-dir min-x max-x min-y max-y proposal-file discount-factor)
 (mkdir-p (format #f "~a/~a" path data-output-dir))
 (write-object-to-file
  (get-matlab-proposals-similarity-full-video-new2
   top-k ssize path data-output-dir min-x max-x min-y max-y
   proposal-file discount-factor)
  (format #f "~a/~a/frame-data-~a-~a.sc" path data-output-dir ;;dummy-f dummy-g))
	  (number->padded-string-of-length dummy-f 3)
	  (number->padded-string-of-length dummy-g 3)))
 (dtrace (format #f "wrote ~a/~a/frame-data-~a-~a.sc" path data-output-dir
;;		 dummy-f dummy-g
		 (number->padded-string-of-length dummy-f 3)
		 (number->padded-string-of-length dummy-g 3)
		 ) #f))


(define (run-codetection-viterbi path
				 top-k
				 ssize
				 data-output-dir
				 min-x
				 max-x
				 min-y
				 max-y
				 proposal-file
				 discount-factor
				 world-weight)
 (mkdir-p (format #f "~a/~a" path data-output-dir))
 (let* ((proposals-similarity
	 (get-matlab-proposals-similarity-viterbi
	  top-k ssize path data-output-dir min-x max-x min-y max-y
	  proposal-file discount-factor world-weight))
	(proposals-boxes (map (lambda (boxes) (map (lambda (x) (sublist x 0 4))
						   (matrix->list-of-lists boxes)))
			      (first proposals-similarity)))
	(proposals-xy (map (lambda (boxes) (map (lambda (x) (sublist x 5 7))
						(matrix->list-of-lists boxes)))
			   (first proposals-similarity)))
	(f (map (lambda (boxes) (map fifth (matrix->list-of-lists boxes)))
		(first proposals-similarity)))
	(g-mat
	 (begin
	  (start-matlab!)
	  (matlab (format #f "load('~a/~a/binary_score_data.mat');"
			  path data-output-dir))
	  (dtrace (format #f "loaded ~a/~a/binary_score_data.mat"
			  path data-output-dir) #f)
	  (transpose (matlab-get-variable "binary_scores"))))
	(g (vector->list (map-vector (lambda (v) (vector->list v)) g-mat)))
;;	(foo (dtrace "length f,g" (list (length f) (length g))))
	(viterbi-output (viterbi-boxes f g))
	(score (first viterbi-output))
	(boxes (second viterbi-output)))
  ;;output
  (write-object-to-file proposals-similarity
			(format #f "~a/~a/frame-data.sc"
				path data-output-dir))
  (list boxes ;;box numbers
	(map (lambda  ;;xy locations as list (empty list if dummy)
	       (b prop-xy) (list-ref prop-xy b))
	     boxes
	     (map (lambda (prop-xy) (append prop-xy '(())))
		  proposals-xy))
	(map (lambda ;;pixel locations as list (empty list if dummy)
	       (b prop-boxes) (list-ref prop-boxes b))
	     boxes
	     (map (lambda (prop-boxes) (append prop-boxes '(())))
		  proposals-boxes))
	(map (lambda ;;f-score value (NOT A LIST) (dummy-f, not empty list, if dummy)
	       (b scores) (list-ref scores b))
	     boxes 
	     (map (lambda (scores) (append scores '(())))
	     ;;(map (lambda (scores) (append scores (list dummy-f)))
		  f)))))

(define (run-codetection-viterbi-multiple path
					  top-k
					  ssize
					  data-output-dir
					  min-x
					  max-x
					  min-y
					  max-y
					  proposal-file
					  discount-factor
					  world-weight
					  num-tubes
					  reduce-factor)
 (mkdir-p (format #f "~a/~a" path data-output-dir))
 (let* ((proposals-similarity
	 (get-matlab-proposals-similarity-viterbi
	  top-k ssize path data-output-dir min-x max-x min-y max-y
	  proposal-file discount-factor world-weight))
	(proposals-boxes (map (lambda (boxes) (map (lambda (x) (sublist x 0 4))
						   (matrix->list-of-lists boxes)))
			      (first proposals-similarity)))
	(proposals-xy (map (lambda (boxes) (map (lambda (x) (sublist x 5 7))
						(matrix->list-of-lists boxes)))
			   (first proposals-similarity)))
	(f (map (lambda (boxes) (map fifth (matrix->list-of-lists boxes)))
		(first proposals-similarity)))
	(g-mat
	 (begin
	  (start-matlab!)
	  (matlab (format #f "load('~a/~a/binary_score_data.mat');"
			  path data-output-dir))
	  (dtrace (format #f "loaded ~a/~a/binary_score_data.mat"
			  path data-output-dir) #f)
	  (transpose (matlab-get-variable "binary_scores"))))
	(g (vector->list (map-vector (lambda (v) (vector->list v)) g-mat)))
;;	(foo (dtrace "length f,g" (list (length f) (length g))))
	(viterbi-output (viterbi-multiple f g num-tubes reduce-factor))
	;; (scores (map first viterbi-output))
	;; (boxes-lists (map second viterbi-output))
	(winner (last viterbi-output))
	(score (first winner))
	(boxes (second winner))
	)
  ;;output
  (dtrace "viterbi-multiple output:" viterbi-output)
  (write-object-to-file proposals-similarity
  			(format #f "~a/~a/frame-data.sc"
  				path data-output-dir))
  (list boxes ;;box numbers
	(map (lambda  ;;xy locations as list (empty list if dummy)
	       (b prop-xy) (list-ref prop-xy b))
	     boxes
	     (map (lambda (prop-xy) (append prop-xy '(())))
		  proposals-xy))
	(map (lambda ;;pixel locations as list (empty list if dummy)
	       (b prop-boxes) (list-ref prop-boxes b))
	     boxes
	     (map (lambda (prop-boxes) (append prop-boxes '(())))
		  proposals-boxes))
	(map (lambda ;;f-score value (NOT A LIST) (dummy-f, not empty list, if dummy)
	       (b scores) (list-ref scores b))
	     boxes 
	     (map (lambda (scores) (append scores '(())))
	     ;;(map (lambda (scores) (append scores (list dummy-f)))
		  f)))
	       ))

(define (visualize-results-test data frames path name-prefix dummy-f dummy-g)
 (let* ((results (run-codetection-with-proposals-similarity data
							    dummy-f
							    dummy-g))
	(boxes (third results)))
  (let loop ((images (map (lambda (f) (imlib:clone f)) frames))
	     (boxes boxes)
	     (n 0))
   (if (or (null? images)
	   (null? boxes))
       (dtrace "done" #f)
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
	(imlib:save image (format #f "~a/~a-~a.png"
				  path name-prefix
				  (number->padded-string-of-length n 5)))
	(dtrace "saved image" n)
	(loop (rest images) (rest boxes) (+ n 1)))))))

(define (visualize-results path dummy-f dummy-g)
 (let* (;; (data (read-object-from-file (format #f "~a/frame-data-new3.sc" path)))
	(data (read-object-from-file (format #f "~a/frame-data-~a-~a.sc" path dummy-f dummy-g)))
	(img-path (format #f "~a/images-~a-~a" path
			  (number->padded-string-of-length dummy-f 3)
			  (number->padded-string-of-length dummy-g 3)))
	(results (run-codetection-with-proposals-similarity data
							    dummy-f
							    dummy-g))
	(boxes (third results))
	(video-path (format #f "~a/video_front.avi" path))
	(frames (video->frames 1 video-path))
	)
  (write-object-to-file results (format #f "~a/results-~a-~a.sc" path
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
	     (imlib:draw-rectangle image x1 y1 w h (vector 255 0 0))
	     (imlib:draw-rectangle image (- x1 1) (- y1 1)
				   (+ w 2) (+ h 2) (vector 255 0 0))
	     (imlib:draw-rectangle image (- x1 2) (- y1 2)
				   (+ w 4) (+ h 4) (vector 255 0 0))
	     ))
	(imlib:save image (format #f "~a/~a.png"
				  img-path
				  (number->padded-string-of-length n 5)))
	(dtrace "saved image" n)
	(loop (rest images) (rest boxes) (+ n 1)))))))

(define (visualize-results-improved-new path
					dummy-f
					dummy-g
					data-output-dir
					discount-factor)
 (let* (;; (data (read-object-from-file (format #f "~a/frame-data-new3.sc" path)))
	(data (read-object-from-file (format #f "~a/~a/frame-data-~a-~a.sc"
					     path data-output-dir
					     ;; dummy-f dummy-g
					     (number->padded-string-of-length dummy-f 3)
					     (number->padded-string-of-length dummy-g 3)
					     )))
	(img-path (format #f "~a/~a/images-~a-~a" path data-output-dir
			  (number->padded-string-of-length dummy-f 3)
			  (number->padded-string-of-length dummy-g 3)))
	(results (run-codetection-with-proposals-similarity data
							    (* discount-factor
							       dummy-f)
					    ;;ensures dummy scaled same as real boxes
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
	     (imlib:draw-rectangle image x1 y1 w h (vector 255 0 0))
	     (imlib:draw-rectangle image (- x1 1) (- y1 1)
				   (+ w 2) (+ h 2) (vector 255 0 0))
	     (imlib:draw-rectangle image (- x1 2) (- y1 2)
				   (+ w 4) (+ h 4) (vector 255 0 0))
	     ))
	(imlib:save image (format #f "~a/~a.png"
				  img-path
				  (number->padded-string-of-length n 5)))
	;;(dtrace "saved image" n)
	(loop (rest images) (rest boxes) (+ n 1)))))))

(define (visualize-results-viterbi path
				   top-k
				   ssize
				   data-output-dir
				   min-x
				   max-x
				   min-y
				   max-y
				   proposal-file
				   discount-factor
				   world-weight)
 (let* ((img-path (format #f "~a/~a/images" path data-output-dir))
	(results (run-codetection-viterbi path
					  top-k
					  ssize
					  data-output-dir
					  min-x
					  max-x
					  min-y
					  max-y
					  proposal-file
					  discount-factor
					  world-weight))

	(boxes (third results))
	(video-path (format #f "~a/video_front.avi" path))
	(frames (video->frames 1 video-path)))
  (write-object-to-file results (format #f "~a/~a/results.sc"
					path
					data-output-dir))
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
	     (imlib:draw-rectangle image x1 y1 w h (vector 255 0 0))
	     (imlib:draw-rectangle image (- x1 1) (- y1 1)
				   (+ w 2) (+ h 2) (vector 255 0 0))
	     (imlib:draw-rectangle image (- x1 2) (- y1 2)
				   (+ w 4) (+ h 4) (vector 255 0 0))
	     ))
	(imlib:save image (format #f "~a/~a.png"
				  img-path
				  (number->padded-string-of-length n 5)))
	;;(dtrace "saved image" n)
	(loop (rest images) (rest boxes) (+ n 1)))))))

(define (visualize-results-viterbi-multiple path
					    top-k
					    ssize
					    data-output-dir
					    min-x
					    max-x
					    min-y
					    max-y
					    proposal-file
					    discount-factor
					    world-weight
					    num-tracks
					    reduce-factor)
 (let* ((img-path (format #f "~a/~a/images" path data-output-dir))
	(results (run-codetection-viterbi-multiple path
						   top-k
						   ssize
						   data-output-dir
						   min-x
						   max-x
						   min-y
						   max-y
						   proposal-file
						   discount-factor
						   world-weight
						   num-tracks
						   reduce-factor))

	(boxes (third results))
	(video-path (format #f "~a/video_front.avi" path))
	(frames (video->frames 1 video-path)))
  (write-object-to-file results (format #f "~a/~a/results.sc"
					path
					data-output-dir))
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
	     (imlib:draw-rectangle image x1 y1 w h (vector 255 0 0))
	     (imlib:draw-rectangle image (- x1 1) (- y1 1)
				   (+ w 2) (+ h 2) (vector 255 0 0))
	     (imlib:draw-rectangle image (- x1 2) (- y1 2)
				   (+ w 4) (+ h 4) (vector 255 0 0))
	     ))
	(imlib:save image (format #f "~a/~a.png"
				  img-path
				  (number->padded-string-of-length n 5)))
	;;(dtrace "saved image" n)
	(loop (rest images) (rest boxes) (+ n 1)))))))


(define (run-full-results dummy-f dummy-g output-directory)
 (let* ((servers (list "jalitusteabe" "cuddwybodaeth" "istihbarat" "wywiad"))
	(source "jalitusteabe")
	(cpus-per-job 1)
	(rsync-directory "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/training/")
	(plandirs (list "plan9"));;(system-output (format #f "ls ~a | grep plan" rsync-directory)))
	(arg-list (join
		   (map
		    (lambda (p)
		     (map (lambda (d) (format #f "~a/~a/~a" rsync-directory p d))
			  (system-output (format #f "ls ~a/~a" rsync-directory
						 p)))) plandirs)))
	(commands (map (lambda (arg) (format #f "(load \"/home/sbroniko/codetection/source/sentence-codetection/codetection-test.sc\") (visualize-results \"~a\" ~a ~a) :n :n :n :n :b"
					     arg
					     dummy-f
					     dummy-g)) arg-list))
	)
 ;; (first arg-list)
  (system "date")
  (synchronous-run-commands-in-parallel-with-queueing commands
  						      servers
  						      cpus-per-job
  						      output-directory
  						      source
  						      rsync-directory)
  (for-each (lambda (server)
	     (rsync-directory-to-server server rsync-directory source))
	    servers) ;;copy results back to source
  (system "date")
  ))


;;this does the matlab stuff with given parameters and saves it in the same directory as the original data.
(define (matlab-data-to-files top-k ssize alpha beta gamma delta)
 (let* ((basedir "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation")
	(log-to-track "/home/sbroniko/vader-rover/position/log-to-track.out")
	(baseplans (system-output (format #f "ls ~a | grep plan" basedir)));;`("plan9"));;"plan4" "plan5" "plan6" "plan7" "plan8" "plan9"));;(system-output (format #f "ls ~a | grep plan" basedir)))
	)
  (for-each
   (lambda (plan)
    (for-each
     (lambda (dir)
      (unless
	(file-exists? (format
		       #f
		       "~a/~a/~a/imu-log-with-estimates.txt"
		       basedir plan dir))
       (system (format
		#f
		"~a none ~a/~a/~a/imu-log.txt ~a/~a/~a/imu-log-with-estimates.txt ~a/~a/~a/imu-log-with-estimates.sc"
		log-to-track basedir plan dir basedir plan dir basedir plan dir)))
      (write-object-to-file
       (get-matlab-proposals-similarity-full-video
	top-k ssize (format #f "~a/~a/~a" basedir plan dir) alpha beta gamma delta)
       (format #f "~a/~a/~a/frame-data.sc" basedir plan dir))
      (dtrace (format #f "wrote ~a/~a/~a/frame-data.sc" basedir plan dir) #f)
      )
     ;;(sublist
      (system-output (format #f "ls ~a/~a" basedir plan))
     ;; 0 1)
     ))
   ;;(sublist
    baseplans
   ;; 0 1)
    )))

;;just like get-matlab-data-training-or-generation, but puts output into data-output-dir (under path)
(define (get-matlab-data-training-or-generation-improved
	 path top-k ssize alpha beta gamma delta dummy-f dummy-g data-output-dir)
 (let* ((log-to-track "/home/sbroniko/vader-rover/position/log-to-track.out"))
  (unless ;;comment out this unless if doing autodrive
    (file-exists? (format #f "~a/imu-log-with-estimates.txt" path))
   (system (format #f "~a none ~a/imu-log.txt ~a/imu-log-with-estimates.txt ~a/imu-log-with-estimates.sc" log-to-track path path path)))
  (mkdir-p (format #f "~a/~a" path data-output-dir))
  (write-object-to-file
   (get-matlab-proposals-similarity-full-video
    top-k ssize (format #f "~a" path) alpha beta gamma delta)
   (format #f "~a/~a/frame-data-~a-~a.sc" path data-output-dir
	   (number->padded-string-of-length dummy-f 3)
	   (number->padded-string-of-length dummy-g 3)))
      ;; (format #f "~a/frame-data-new4.sc" path)) ;;NEW HERE TO PREVENT OVERWRITE
   ;; (format #f "~a/frame-data-new3.sc" path)) ;;NEW HERE TO PREVENT OVERWRITE
  (dtrace (format #f "wrote ~a/~a/frame-data-~a-~a.sc" path data-output-dir
		  (number->padded-string-of-length dummy-f 3)
		  (number->padded-string-of-length dummy-g 3)) #f)))

(define (get-matlab-data-auto-drive-improved
	 path top-k ssize alpha beta gamma delta dummy-f dummy-g data-output-dir)
 (let* ((log-to-track "/home/sbroniko/vader-rover/position/log-to-track.out"))
  ;; (unless ;;comment out this unless if doing autodrive
  ;;   (file-exists? (format #f "~a/imu-log-with-estimates.txt" path))
  ;;  (system (format #f "~a none ~a/imu-log.txt ~a/imu-log-with-estimates.txt ~a/imu-log-with-estimates.sc" log-to-track path path path)))
  (mkdir-p (format #f "~a/~a" path data-output-dir))
  (write-object-to-file
   (get-matlab-proposals-similarity-full-video
    top-k ssize (format #f "~a" path) alpha beta gamma delta)
   (format #f "~a/~a/frame-data-~a-~a.sc" path data-output-dir
	   (number->padded-string-of-length dummy-f 3)
	   (number->padded-string-of-length dummy-g 3)))
      ;; (format #f "~a/frame-data-new4.sc" path)) ;;NEW HERE TO PREVENT OVERWRITE
   ;; (format #f "~a/frame-data-new3.sc" path)) ;;NEW HERE TO PREVENT OVERWRITE
  (dtrace (format #f "wrote ~a/~a/frame-data-~a-~a.sc" path data-output-dir
		  (number->padded-string-of-length dummy-f 3)
		  (number->padded-string-of-length dummy-g 3)) #f)))


;;NEEDS REWRITE TO MATCH ABOVE/BELOW WITH DUMMY-F AND DUMMY-G
;; (define (get-matlab-data-auto-drive path top-k ssize alpha beta gamma delta)
;;  (begin
;;   (write-object-to-file
;;    (get-matlab-proposals-similarity-full-video
;;     top-k ssize (format #f "~a" path) alpha beta gamma delta)
;;    (format #f "~a/frame-data-new.sc" path)) ;;NEW HERE TO PREVENT OVERWRITE
;;   (dtrace (format #f "wrote ~a/frame-data-new.sc" path) #f)))


(define (get-matlab-data-training-or-generation
	 path top-k ssize alpha beta gamma delta dummy-f dummy-g)
 (let* ((log-to-track "/home/sbroniko/vader-rover/position/log-to-track.out"))
  (unless ;;comment out this unless if doing autodrive
    (file-exists? (format #f "~a/imu-log-with-estimates.txt" path))
   (system (format #f "~a none ~a/imu-log.txt ~a/imu-log-with-estimates.txt ~a/imu-log-with-estimates.sc" log-to-track path path path)))
  (write-object-to-file
   (get-matlab-proposals-similarity-full-video
    top-k ssize (format #f "~a" path) alpha beta gamma delta)
   (format #f "~a/frame-data-~a-~a.sc" path
	   (number->padded-string-of-length dummy-f 3)
	   (number->padded-string-of-length dummy-g 3)))
      ;; (format #f "~a/frame-data-new4.sc" path)) ;;NEW HERE TO PREVENT OVERWRITE
   ;; (format #f "~a/frame-data-new3.sc" path)) ;;NEW HERE TO PREVENT OVERWRITE
  (dtrace (format #f "wrote ~a/frame-data-~a-~a.sc" path
		  (number->padded-string-of-length dummy-f 3)
		  (number->padded-string-of-length dummy-g 3)) #f)))

(define (results-end-to-end data-directory ;; NEED slash on data-dir
			    top-k
			    ssize
			    alpha
			    beta
			    gamma
			    delta
			    dummy-f
			    dummy-g
			    output-directory) ;;NO slash on output-dir
 (let* ((servers (list "chino" "maniishaa" "alykkyys" "seulki" "faisneis" "buddhi" "rongovosai"));; "cuddwybodaeth" "istihbarat"));;)) ;;*2g-servers*)  "zhineng" "wywiad" "jalitusteabe"
	(source "seykhl");;"jalitusteabe")
	(matlab-cpus-per-job 1);; 7) ;;if using parfor
	(c-cpus-per-job 1)
	(output-matlab (format #f "~a-matlab/" output-directory))
	(output-c (format #f "~a-c/" output-directory))
	;; (plandirs (system-output (format #f "ls ~a | grep plan" data-directory)))
	;; (plandirs (list "plan4" "plan7" "plan8")) ;;these are the only plans with visible objects in the TRAINING corpus
	(plandirs (list "plan0" "plan1" "plan2")) ;;for testing dummy-f and dummy-g changes
	(dir-list (join
		   (map
		    (lambda (p)
		     (map (lambda (d) (format #f "~a/~a/~a" data-directory p d))
			  (system-output (format #f "ls ~a/~a" data-directory p))))
		    plandirs)))
	(commands-matlab (map
			  (lambda (dir) ;;change get-matlab... command if using auto-drive
			   (format #f "(load \"/home/sbroniko/codetection/source/sentence-codetection/codetection-test.sc\") (get-matlab-data-training-or-generation \"~a\" ~a ~a ~a ~a ~a ~a ~a ~a) :n :n :n :n :b" dir top-k ssize alpha beta gamma delta dummy-f dummy-g)) dir-list))
	(commands-c (map
		     (lambda (dir)
		      (format #f "(load \"/home/sbroniko/codetection/source/sentence-codetection/codetection-test.sc\") (visualize-results \"~a\" ~a ~a) :n :n :n :n :b"
					     dir
					     dummy-f
					     dummy-g)) dir-list))
	)
  (dtrace "starting results-end-to-end" #f)
  (system "date")
  ;; (for-each (lambda (server dir) (mkdir-p (format #f "/net/~a~a" server dir)))
  ;; 	    servers (list output-matlab output-c)) ;;this had problems using /net
  (for-each (lambda (dir) (mkdir-p dir)) (list output-matlab output-c))
  ;; (for-each (lambda (dir)
  ;; 	     (for-each (lambda (server) (rsync-directory-to-server source dir server))
  ;; 		       servers))
  ;; 	    (list output-matlab output-c))
  (for-each (lambda (dir)
	     (for-each (lambda (server) (run-unix-command-on-server
					 (format #f "mkdir -p ~a" dir) server))
		       servers))
	    (list output-matlab output-c))
  (dtrace "starting matlab processing" #f)
  (system "date")
  (synchronous-run-commands-in-parallel-with-queueing commands-matlab
  						      servers
  						      matlab-cpus-per-job
  						      output-matlab
  						      source
  						      data-directory)
  (dtrace "matlab processing complete" #f)
  (system "date")
  (for-each (lambda (server)
	     (rsync-directory-to-server server data-directory source))
	    servers) ;;copy results back to source
  (dtrace "matlab results rsync'd, starting c processing" #f)
  (system "date")
  (synchronous-run-commands-in-parallel-with-queueing commands-c
  						      servers
  						      c-cpus-per-job
  						      output-c
  						      source
  						      data-directory)
  (for-each (lambda (server)
	     (rsync-directory-to-server server data-directory source))
	    servers) ;;copy results back to source
  (dtrace "processing complete for results-end-to-end" #f)
  (system "date")))


(define (join-images basedir subdir1 subdir2 dir-suffix)
 (let* ((images (system-output (format #f "ls ~a/~a" basedir subdir1)))
	(joindir (format #f "~a/joined-~a" basedir dir-suffix)))
  (mkdir-p joindir)
  (for-each (lambda (img)
	     (system (format #f "montage -tile 2x1 -geometry +0+0 \"~a\"/\"~a\"/\"~a\" \"~a\"/\"~a\"/\"~a\" \"~a\"/\"~a\""
			     basedir subdir1 img basedir subdir2 img joindir img)))
	    images)
  (dtrace (format #f "wrote images in ~a" joindir) #f)))

(define (join-all-images datasetdir subdir1 subdir2 dir-suffix)
 (let* (;;(plandirs (system-output (format #f "ls ~a | grep plan" datasetdir)))
	(plandirs (list "plan0" "plan1" "plan2")) ;;for testing dummy-f and dummy-g changes
	(dir-list (join
		   (map
		    (lambda (p)
		     (map (lambda (d) (format #f "~a/~a/~a" datasetdir p d))
			  (system-output (format #f "ls ~a/~a" datasetdir p))))
		    plandirs))))
  (for-each (lambda (dir) (join-images dir subdir1 subdir2 dir-suffix)) dir-list)
  (dtrace "join-all-images complete" #f)))


;;NEEDS REWRITE TO MATCH ABOVE WRT DUMMY-F AND DUMMY-G
;; This was what was used to generate results (boxes & scores) for the testing portion of MSEE1 dataset
;; (define (join-all-images-training datasetdir subdir1 subdir2)
;;  (let* ((plandirs (list "plan4" "plan7" "plan8"));;(system-output (format #f "ls ~a | grep plan" datasetdir)))
;; 	(dir-list (join
;; 		   (map
;; 		    (lambda (p)
;; 		     (map (lambda (d) (format #f "~a/~a/~a" datasetdir p d))
;; 			  (system-output (format #f "ls ~a/~a" datasetdir p))))
;; 		    plandirs))))
;;   (for-each (lambda (dir) (join-images dir subdir1 subdir2)) dir-list)
;;   (dtrace "join-all-images-training complete" #f)))

(define (run-my-shit)
 ;; ;; (results-end-to-end "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation/" 10 64 1 1 1 0 0.6 0.6 "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/results20150331")
 ;; (results-end-to-end "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/training/" 10 64 1 1 1 0 0.6 0.6 "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/results20150402")
 ;; ;; (join-all-images "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation" "joined" "images-0.6-0.6-new4")
 ;;  (join-all-images-training "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/training" "images-0.6-0.6" "images-0.6-0.6-new4")
 (let* ((data-path "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation/")
	(top-k 10)
	(ssize 64)
	(alpha 1)
	(beta 1)
	(gamma 1)
	(delta 0)
	(dummy-f 0.3)
	(dummy-g 0.6)
	(output-path "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/results20150420a"))
  (results-end-to-end data-path top-k ssize alpha beta gamma delta dummy-f dummy-g output-path)
  (join-all-images data-path
		   "images-0.6-0.6-new4"
		   (format #f "images-~a-~a"
			   (number->padded-string-of-length dummy-f 3)
			   (number->padded-string-of-length dummy-g 3))
		   (format #f "~a-~a"
			   (number->padded-string-of-length dummy-f 3)
			   (number->padded-string-of-length dummy-g 3)))
  (system "date")))

(define (run-my-shit-2)
 (let* ((path "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation/plan0/2014-11-20-02:31:11")
	(top-k 10)
	(ssize 64)
	(alpha 1)
	(beta 1)
	(gamma 1)
	(delta 0)
	(dummy-f 0.6)
	(dummy-g 0.6))
  (get-matlab-data-training-or-generation path top-k ssize alpha beta gamma delta)
  (visualize-results path dummy-f dummy-g)))

;;;--------------plotting stuff----------------------

(define (get-xy-from-results-file file)
 (let* ((filedata (read-object-from-file file))
	(raw-xys (second filedata)))
  (let loop ((xys '())
	     (raw-xys raw-xys))
   (if (null? raw-xys)
       xys ;; done
       (if (null? (first raw-xys))
	   (loop xys (rest raw-xys))
	   (loop (cons (first raw-xys) xys) (rest raw-xys)))))))

(define (plot-objects-from-file file)
 (let* ((xys (get-xy-from-results-file file))
	(xs (map first xys))
	(ys (map second xys)))
  (start-matlab!)
  (plot-lines-in-matlab (list xs) (list ys) (list "'foo'") "x")))

;;(define *boundaries* '((-3 -2.62) (-3 3.93) (3.05 3.93) (3.05 -2.62) (-3 -2.62)))
(define *xmin* -3)
(define *xmax* 3.05)
(define *ymin* -2.62)
(define *ymax* 3.93)
(define *boundaries* (list (list *xmin* *ymin*)
			   (list *xmin* *ymax*)
			   (list *xmax* *ymax*)
			   (list *xmax* *ymin*)
			   (list *xmin* *ymin*)))
(define *x-1* -1.37)
(define *x0* 0)
(define *x+1* 1.37)
(define *y-1* -1.31)
(define *y0* 0)
(define *y+1* 1.31)
(define *y+2* 2.62)

(define (point-locations x1 x2 cm-between)
 (let* ((distance (- x2 x1))
	(num-points (+ 1 (exact-round (/ distance (/ cm-between 100))))))
  (linspace x1 x2 num-points)))

(define (plot-grid)
 (start-matlab!)
 (plot-lines-in-matlab (list (list *xmin* *xmin* *xmax* *xmax* *xmin*)
			     (list *xmin* *xmax*)
			     (list *x0* *x0*))
		       (list (list *ymin* *ymax* *ymax* *ymin* *ymin*)
			     (list *y0* *y0*)
			     (list *ymin* *ymax*))
		       (list "'boundaries'")
		       "k-")
 (matlab "hold on;")
 (plot-lines-in-matlab (list (list *xmin* *xmax*)
			     (list *xmin* *xmax*)
			     (list *xmin* *xmax*)
			     (list *x-1* *x-1*)
			     (list *x+1* *x+1*)
			     )
 		       (list (list *y-1* *y-1*)
			     (list *y+1* *y+1*)
			     (list *y+2* *y+2*)
			     (list *ymin* *ymax*)
			     (list *ymin* *ymax*)
			     )
 		       (list "'hash marks'")
 		       "k--")
 (matlab "axis([-4 4 -3 4.5])")
 (matlab "ylabel('world Y (in m)')")
 (matlab "xlabel('world X (in m)')")
 )


(define (plot-objects-from-floorplan floorplan-dir filename)
 (let* (;;(rundirs (system-output (format #f "ls -d ~a/*/" floorplan-dir)))
	(rundirs (system-output (format #f "ls -d ~a/20*/" floorplan-dir)))
	(xys (join
	      (map
	       (lambda (f)
		(get-xy-from-results-file
		 (format #f "~a~a" f filename)))
	       rundirs)))
	(xs (map first xys))
	(ys (map second xys)))
  (plot-grid)
  (matlab "hold on;")
  (plot-lines-in-matlab (list xs) (list ys) (list "'detections'") "o")))

(define (plot-objects-from-floorplan-multicolor floorplan-dir filename)
 (let* ((rundirs (system-output (format #f "ls -d ~a/*/" floorplan-dir)))
	(xys 
	 (map
	  (lambda (f)
	   (get-xy-from-results-file
	    (format #f "~a~a" f filename)))
	  rundirs))
	(xs (map (lambda (f) (map first f)) xys))
	(ys (map (lambda (f) (map second f ))xys)))
  (plot-grid)
  (matlab "hold on;")
  (plot-lines-in-matlab-with-symbols xs ys
				     (map-indexed (lambda (f i) (format #f "'run ~a'" i)) xys)
				     (map-indexed (lambda (f i) (format #f "o")) xys))))

;;OLD VERSION--worked as of 2 Jun 15
;; (define (ensure-scores results-file frame-data-file)
;;  ;;this makes sure that results have the fscores of winning boxes as 4th list
;;  (let* ((results (read-object-from-file results-file))
;; 	(frame-data (read-object-from-file frame-data-file))
;; 	(fscores (map (lambda (boxes)
;; 		       (map fifth (matrix->list-of-lists boxes)))
;; 		      (first frame-data)))
;; 	(boxes (first results))
;; 	(winning-fscores (map (lambda (b scores)
;; 			       (list-ref scores b))
;; 			      boxes
;; 			      (map (lambda (scores) (append scores '(())))
;; 				   fscores)))
;; 	)
;;   (if (= (length results) 4)
;;       results
;;       (append results (list winning-fscores)))))

(define (ensure-scores results-file frame-data-file)
 ;;this makes sure that results have the fscores of winning boxes as 4th list
 (let* ((results (read-object-from-file results-file)))
  (if (= (length results) 4)
      results
      (let* ((frame-data (read-object-from-file frame-data-file))
	     (fscores (map (lambda (boxes)
			    (map fifth (matrix->list-of-lists boxes)))
			   (first frame-data)))
	     (boxes (first results))
	     (winning-fscores (map (lambda (b scores)
				    (list-ref scores b))
				   boxes
				   (map (lambda (scores) (append scores '(())))
					fscores))))
       (append results (list winning-fscores))))))


(define (get-scores-from-results-and-frame-data-files results-file frame-data-file)
 (let* ((raw-scores (fourth (ensure-scores results-file frame-data-file))))
  (let loop ((scores '())
	     (raw-scores raw-scores))
   (if (null? raw-scores)
       scores ;; done
       (if (null? (first raw-scores))
	   (loop scores (rest raw-scores))
	   (loop (cons (first raw-scores) scores) (rest raw-scores)))))))

(define (get-detection-images run-path results-file)
 ;;returns a list of imlib handles to cropped detection images from a single run
 (let* ((video-path (format #f "~a/video_front.avi" run-path))
	(frames (video->frames 1 video-path))
	(results-file-with-path (format #f "~a/~a" run-path results-file))
	(results (read-object-from-file results-file-with-path))
	(detection-pixels (third results)))
  (let loop ((images '())
	     (detection-pixels detection-pixels)
	     (frames frames))
   (if (null? detection-pixels)
       images ;;done
       (if (null? (first detection-pixels))
	   (begin ;;no detection this frame
	    (imlib:free-image-and-decache (first frames))
	    (loop images (rest detection-pixels) (rest frames)))
	   (let* ((x1 (first (first detection-pixels)))
		  (y1 (second (first detection-pixels)))
		  (width (- (third (first detection-pixels)) x1))
		  (height (- (fourth (first detection-pixels)) y1))
		  (det-image (imlib:create-cropped
			      (first frames) x1 y1 width height)))
	    (imlib:free-image-and-decache (first frames))
	    (loop (cons det-image images) (rest detection-pixels) (rest frames))))))))

(define (make-test-file floorplan-dir results-file frame-data-file output-file)
 (let* ((rundirs (system-output (format #f "ls -d ~a/*/" floorplan-dir)))
	(xys (join
	      (map
	       (lambda (f)
		(get-xy-from-results-file
		 (format #f "~a~a" f results-file)))
	       rundirs)))
	(scores (join
		 (map
		  (lambda (f)
		   (get-scores-from-results-and-frame-data-files
		    (format #f "~a~a" f results-file)
		    (format #f "~a~a" f frame-data-file)))
		  rundirs)))
	(mydata (map (lambda (xy score)
  			      (list->vector (append xy (list score))))
  			     xys
  			     scores)))
  ;;use most of what's above here to pass this data back into matlab
  (start-matlab!)
  (scheme->matlab! "detection_data" mydata)
  (matlab (format #f "save('~a','detection_data')" output-file))
  ;; (scheme->matlab! "detection_data_reduced" mydata)
  ;; (matlab (format #f "save('~a','detection_data_reduced')" output-file))
  
  ))

(define (get-detection-data-for-floorplan floorplan-dir
					  results-filename
					  frame-data-filename
					  output-dirname ;;under floorplan-dir
					  matlab-output-filename)
;;(define (make-test-file-new floorplan-dir results-file frame-data-file output-file)
 (let* ((rundirs (system-output (format #f "ls -d ~a/20*/" floorplan-dir)))
	(xys ;;(dtrace "xys"
	 (join
	      (map
	       (lambda (f)
		(get-xy-from-results-file
		 (format #f "~a~a" f results-filename)))
	       rundirs)))
	    ;; )
	(scores ;;(dtrace "scores"
	 (join
		 (map
		  (lambda (f)
		   (get-scores-from-results-and-frame-data-files
		    (format #f "~a~a" f results-filename)
		    (format #f "~a~a" f frame-data-filename)))
		  rundirs)))
		;;)
	;; (matlab-data ;;(dtrace "matlab-data"
	;;  (map (lambda (xy score)
	;; 		   (list->vector (append xy (list score))))
	;; 		  xys
	;; 		  scores))
		    ;; )
	;;use most of what's above here to pass this data back into matlab
	(image-list ;;(dtrace "image-list"
	 (join
		     (map
		      (lambda (f)
		       (get-detection-images f results-filename))
		      rundirs)))
	;;put new triangle stuff here--want 1/visible to be 4th column of matlab-data
	(all-poses (join (map (lambda (dir)
			       (get-poses-that-match-frames dir)) rundirs)))
	(left-limits
	 (map
	  (lambda (p)
	   (pixel-and-height->world
	    '#(0 205)
	    (robot-pose-to-camera->world-txf p
					     *camera-offset-matrix*)
	    *camera-k-matrix* 0))
	  all-poses))

	(right-limits
	 (map
	  (lambda (p)
	   (pixel-and-height->world
	    '#(639 205)
	    (robot-pose-to-camera->world-txf p
					     *camera-offset-matrix*)
	    *camera-k-matrix* 0))
	  all-poses))

	(triangles
	 (map (lambda (c l r) (list
			       (subvector c 0 2)
			       (subvector l 0 2)
			       (subvector r 0 2)))
	      all-poses left-limits right-limits))
	(frequencies
	 (map (lambda (ll)
	       (if (= ll 0)
		   (dtrace "Error in get-detection-data-for-floorplan: detected box with count = 0" 0) ;;this shouldn't happen, since it means that a detected box was never counted as being in the field of view
		   (/ 1 ll)))
	      (map (lambda (l)
		    (reduce + l 0))
		   (map (lambda (p)
			 (map (lambda (t)
			       (point-in-triangle (list->vector p) t))
			      triangles))
			xys))))
	(matlab-data ;;(dtrace "matlab-data"
	 (map (lambda (xy score freq)
			   (list->vector (append xy (list score freq))))
			  xys
			  scores
			  frequencies))
	)
  (mkdir-p (format #f "~a/~a" floorplan-dir output-dirname))
  (for-each-indexed
   (lambda (image i)    
    (imlib:save image (format #f
			      "~a/~a/~a.png"
			      floorplan-dir
			      output-dirname
			      (number->padded-string-of-length (+ i 1) 5)))
    (imlib:free-image-and-decache image))
    ;;(dtrace "saved image" (+ i 1)))
   image-list)		     			
  (start-matlab!)
  (scheme->matlab! "detection_data" matlab-data)
  (matlab (format #f
		  "save('~a/~a/~a','detection_data')"
		  floorplan-dir
		  output-dirname
		  matlab-output-filename))))

(define (point-in-triangle point triangle)
 ;;returns 0 if point NOT in triangle, 1 if point IS in triangle
 ;;point is a single vector of xy
 ;;triangle is a list of 3 xy vectors
 ;;This uses the Barycentric weight formula from
 ;;http://math.stackexchange.com/questions/51326/determining-if-an-arbitrary-point-lies-inside-a-triangle-defined-by-three-points
 (let* ((A (first triangle))
	(B (v- (second triangle) A))
	(C (v- (third triangle) A))
	(P (v- point A))
	(x (vector-ref P 0))
	(y (vector-ref P 1))
	(xB (vector-ref B 0))
	(yB (vector-ref B 1))
	(xC (vector-ref C 0))
	(yC (vector-ref C 1))
	(d (- (* xB yC) (* yB xC)))
	(WA (/ (+ (* x (- yB yC)) (* y (- xC xB)) (* xB yC) (- (* xC yB))) d))
	(WB (/ (- (* x yC) (* y xC)) d))
	(WC (/ (- (* y xB) (* x yB)) d)))
  ;;point is in triangle if WA, WB, WC all 0 <= W <= 1
  (if (and
       (and (>= WA 0)
	    (>= WB 0)
	    (>= WC 0))
       (and (<= WA 1)
	    (<= WB 1)
	    (<= WC 1)))
      1
      0)))

(define (detect-sort-label-objects-single-floorplan floorplan-dir
						    results-filename
						    frame-data-filename
						    data-output-dir)
 ;;this is the wrapper function that calls get-detection-data-for-floorplan
 ;;and matlab functions find_objects, cluster_detections_by_object,
 ;;sort_by_cluster, and sort_clusters_single_floorplan
 (let* ((output-dirname (format #f "detections-~a" data-output-dir)) ;;under floorplan-dir
	(matlab-output-filename "detection_data.mat")
	(img-dir (format #f "~a/~a/" floorplan-dir output-dirname)))
  (start-matlab!)
  (get-detection-data-for-floorplan floorplan-dir
				    results-filename
				    frame-data-filename
				    output-dirname 
				    matlab-output-filename)
  ;;don't think I need to load detection_data.mat here b/c matlab already has detection_data
  (matlab (format #f
		  "[numobj, objxys,~] = find_objects(detection_data,~a,~a,~a,~a,~a,~a);"
		  *xmin* *xmax* *ymin* *ymax*
		  5 ;; cm_between HARDCODED
		  0.25));; gaussian_variance HARDCODED
  (matlab (format #f
		  "cluster_data = cluster_detections_by_object(detection_data,objxys,~a);"
		  0.5)) ;; threshold in m HARDCODED
  (matlab (format #f
		  "sort_by_cluster(cluster_data,'~a');"
		  img-dir))
  (matlab (format #f
		  "xy_with_label = sort_clusters_single_floorplan(objxys,'~a');"
		  img-dir ))
  ;;write xy_with_label to scheme-style file
  (write-object-to-file (matlab-get-variable "xy_with_label")
			(format #f "~axy_with_label.sc" img-dir))
  ))

;;modified version of results-end-to-end --> gets codetection results for every run in a dataset
(define (get-codetection-results-training-or-generation
	 data-directory ;; NEED slash on data-dir
	 top-k
	 ssize
	 alpha
	 beta
	 gamma
	 delta
	 dummy-f
	 dummy-g
	 output-directory ;;NO slash on output-dir--this is a full path
	 data-output-dir ;;this is just a DIR NAME that will be under each run dir
	 server-list
	 source-machine ;;just a string, i.e., "seykhl"
	 )
 (let* ((servers server-list)
	(source source-machine)
	(matlab-cpus-per-job 8);;4);; for under-the-hood matlab parallelism
	(c-cpus-per-job 1)
	(output-matlab (format #f "~a-matlab/" output-directory))
	(output-c (format #f "~a-c/" output-directory))
	(plandirs (system-output (format #f "ls ~a | grep plan" data-directory)))
	(dir-list (join
		   (map
		    (lambda (p)
		     (map (lambda (d) (format #f "~a/~a/~a" data-directory p d))
			  (system-output
			   (format #f "ls ~a/~a | grep 201" data-directory p))))
		    plandirs)))
	(commands-matlab
	 (map
	  (lambda (dir) ;;change get-matlab... command if using auto-drive
	   (format #f "(load \"/home/sbroniko/codetection/source/sentence-codetection/codetection-test.sc\") (get-matlab-data-training-or-generation-improved \"~a\" ~a ~a ~a ~a ~a ~a ~a ~a \"~a\") :n :n :n :n :b" dir top-k ssize alpha beta gamma delta dummy-f dummy-g data-output-dir)) dir-list))
	(commands-c ;;if something breaks this might be it--not sure I have path changes right
	 (map
	  (lambda (dir)
	   (format #f "(load \"/home/sbroniko/codetection/source/sentence-codetection/codetection-test.sc\") (visualize-results-improved \"~a\" ~a ~a \"~a\") :n :n :n :n :b"
		   dir
		   dummy-f
		   dummy-g
		   data-output-dir)) dir-list))
	)
  (dtrace "starting get-codetection-results-training-or-generation" #f)
  (system "date")
  ;; (for-each (lambda (server dir) (mkdir-p (format #f "/net/~a~a" server dir)))
  ;; 	    servers (list output-matlab output-c)) ;;this had problems using /net
  ;; (for-each (lambda (dir)
  ;; 	     (for-each (lambda (server) (rsync-directory-to-server source dir server))
  ;; 		       servers))
  ;; 	    (list output-matlab output-c))  ;;NOT NECESSARY
  (for-each (lambda (dir) (mkdir-p dir)) (list output-matlab output-c))
  (for-each (lambda (dir)
	     (for-each (lambda (server) (run-unix-command-on-server
					 (format #f "mkdir -p ~a" dir) server))
		       servers))
	    (list output-matlab output-c))
  (dtrace "starting matlab processing" #f)
  (system "date")
  (synchronous-run-commands-in-parallel-with-queueing commands-matlab
  						      servers
  						      matlab-cpus-per-job
  						      output-matlab
  						      source
  						      data-directory)
  (dtrace "matlab processing complete" #f)
  (system "date")
  (for-each (lambda (server)
	     (rsync-directory-to-server server data-directory source))
	    servers) ;;copy results back to source
  (dtrace "matlab results rsync'd, starting c processing" #f)
  (system "date")
  (synchronous-run-commands-in-parallel-with-queueing commands-c
  						      servers
  						      c-cpus-per-job
  						      output-c
  						      source
  						      data-directory)
  (for-each (lambda (server)
	     (rsync-directory-to-server server data-directory source))
	    servers) ;;copy results back to source
  (dtrace "processing complete for get-codetection-results-training-or-generation" #f)
  (system "date")))

(define (get-codetection-results-auto-drive
	 data-directory ;; NEED slash on data-dir
	 top-k
	 ssize
	 alpha
	 beta
	 gamma
	 delta
	 dummy-f
	 dummy-g
	 output-directory ;;NO slash on output-dir--this is a full path
	 data-output-dir ;;this is just a DIR NAME that will be under each run dir
	 server-list
	 source-machine ;;just a string, i.e., "seykhl"
	 )
 (let* ((servers server-list)
	(source source-machine)
	(matlab-cpus-per-job 8);;4);; for under-the-hood matlab parallelism
	(c-cpus-per-job 1)
	(output-matlab (format #f "~a-matlab/" output-directory))
	(output-c (format #f "~a-c/" output-directory))
	(plandirs (system-output (format #f "ls ~a | grep plan" data-directory)))
	;; (dir-list (list
	;; 	   "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/auto-drive/plan8/2014-11-21-03:03:46"
	;; 	   "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/auto-drive/plan5/2014-11-21-02:27:38"))
	;;TEMPORARY for re-run of plan5,plan8
	
	(dir-list (join
		   (map
		    (lambda (p)
		     (map (lambda (d) (format #f "~a/~a/~a" data-directory p d))
			  (system-output
			   (format #f "ls ~a/~a | grep 201" data-directory p))))
		    plandirs)))
	(commands-matlab
	 (map
	  (lambda (dir) ;;change get-matlab... command if using auto-drive
	   (format #f "(load \"/home/sbroniko/codetection/source/sentence-codetection/codetection-test.sc\") (get-matlab-data-auto-drive-improved \"~a\" ~a ~a ~a ~a ~a ~a ~a ~a \"~a\") :n :n :n :n :b" dir top-k ssize alpha beta gamma delta dummy-f dummy-g data-output-dir)) dir-list))
	(commands-c ;;if something breaks this might be it--not sure I have path changes right
	 (map
	  (lambda (dir)
	   (format #f "(load \"/home/sbroniko/codetection/source/sentence-codetection/codetection-test.sc\") (visualize-results-improved \"~a\" ~a ~a \"~a\") :n :n :n :n :b"
		   dir
		   dummy-f
		   dummy-g
		   data-output-dir)) dir-list))
	)
  (dtrace "starting get-codetection-results-auto-drive" #f)
  (system "date")
  ;; (for-each (lambda (server dir) (mkdir-p (format #f "/net/~a~a" server dir)))
  ;; 	    servers (list output-matlab output-c)) ;;this had problems using /net
  ;; (for-each (lambda (dir)
  ;; 	     (for-each (lambda (server) (rsync-directory-to-server source dir server))
  ;; 		       servers))
  ;; 	    (list output-matlab output-c))  ;;NOT NECESSARY
  (for-each (lambda (dir) (mkdir-p dir)) (list output-matlab output-c))
  (for-each (lambda (dir)
	     (for-each (lambda (server) (run-unix-command-on-server
					 (format #f "mkdir -p ~a" dir) server))
		       servers))
	    (list output-matlab output-c))
  (dtrace "starting matlab processing" #f)
  (system "date")
  (synchronous-run-commands-in-parallel-with-queueing commands-matlab
  						      servers
  						      matlab-cpus-per-job
  						      output-matlab
  						      source
  						      data-directory)
  (dtrace "matlab processing complete" #f)
  (system "date")
  (for-each (lambda (server)
	     (rsync-directory-to-server server data-directory source))
	    servers) ;;copy results back to source
  (dtrace "matlab results rsync'd, starting c processing" #f)
  (system "date")
  (synchronous-run-commands-in-parallel-with-queueing commands-c
  						      servers
  						      c-cpus-per-job
  						      output-c
  						      source
  						      data-directory)
  (for-each (lambda (server)
	     (rsync-directory-to-server server data-directory source))
	    servers) ;;copy results back to source
  (dtrace "processing complete for get-codetection-results-auto-drive" #f)
  (system "date")))

;;this runs object detection on all floorplans
(define (get-object-detections-all-floorplans
	 data-directory ;; NEED slash on data-dir
	 output-directory ;;NO slash on output-dir--this is a full path
	 results-filename ;;remember to add data-output-dir to this and frame-data...
	 frame-data-filename
	 data-output-dir
	 server-list
	 source-machine ;;just a string, i.e., "seykhl"
	 )
 (let* ((servers server-list)
	(source source-machine)
	(matlab-cpus-per-job 20);;12);;4) ;;for under-the-hood matlab parallelism and to spread out jobs among servers
	(output-matlab (format #f "~a-detection/" output-directory))
	(plandirs (system-output (format #f "ls ~a | grep plan" data-directory)))
	;;TEMPORARY for re-run of auto-drive
	;;(plandirs (list "plan0" "plan1"))
	;;(plandirs (list "plan5" "plan8"))

	;; (dir-list (join
	;; 	   (map
	;; 	    (lambda (p)
	;; 	     (map (lambda (d) (format #f "~a/~a/~a" data-directory p d))
	;; 		  (system-output
	;; 		   (format #f "ls ~a/~a | grep 201" data-directory p))))
	;; 	    plandirs)))
	(commands-matlab
	 (map
	  (lambda (dir) 
	   (format #f
		   "(load \"/home/sbroniko/codetection/source/sentence-codetection/codetection-test.sc\") (detect-sort-label-objects-single-floorplan \"~a\" \"~a\" \"~a\" \"~a\") :n :n :n :n :b"
		   (format #f "~a/~a" data-directory dir)
		   results-filename
		   frame-data-filename
		   data-output-dir))
	  plandirs));;dir-list))

	)
  (dtrace "starting get-object-detections-all-floorplans" #f)
  (system "date")
  ;; (for-each (lambda (server dir) (mkdir-p (format #f "/net/~a~a" server dir)))
  ;; 	    servers (list output-matlab output-c)) ;;this had problems using /net
  (for-each (lambda (dir)
  	     (for-each (lambda (server) (rsync-directory-to-server source dir server))
  		       servers))
  	    (list output-matlab));; output-c))
  (for-each (lambda (dir) (mkdir-p dir)) (list output-matlab));; output-c))
  (for-each (lambda (dir)
	     (for-each (lambda (server) (run-unix-command-on-server
					 (format #f "mkdir -p ~a" dir) server))
		       servers))
	    (list output-matlab));; output-c))
  (dtrace "starting matlab processing" #f)
  (system "date")
  (synchronous-run-commands-in-parallel-with-queueing commands-matlab
  						      servers
  						      matlab-cpus-per-job
  						      output-matlab
  						      source
  						      data-directory)
  (dtrace "matlab processing complete" #f)
  (system "date")
  (for-each (lambda (server)
	     (rsync-directory-to-server server data-directory source))
	    servers) ;;copy results back to source

  (dtrace "processing complete for get-object-detections-all-floorplans" #f)
  (system "date")))


;;this is the wrapper function that calls codetection, sorts/labels objects in a single floorplan, and then ???
(define (codetect-sort-templabel-training-or-generation data-output-dirname)
 (let* ((data-directory
	 "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation/")
	(top-k 10)
	(ssize 64)
	(alpha 1)
	(beta 1)
	(gamma 1)
	(delta 0)
	(dummy-f 0.6)
	(dummy-g 0.6)
	(output-directory
	 (format #f  "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/results-~a"
		 data-output-dirname))
	(data-output-dir data-output-dirname)
	(results-filename (format #f
				  "~a/results-~a-~a.sc"
				  data-output-dir
				  dummy-f
				  dummy-g))
	(frame-data-filename (format #f
				     "~a/frame-data-~a-~a.sc"
				     data-output-dir
				     dummy-f
				     dummy-g))
	(server-list
	 (list "aruco" "save" "akili" "aql" "verstand" "arivu")) ;; "perisikan" acting weird, jobs dying without finishing
	(source-machine "seykhl"))
  (get-codetection-results-training-or-generation data-directory 
						  top-k
						  ssize
						  alpha
						  beta
						  gamma
						  delta
						  dummy-f
						  dummy-g
						  output-directory 
						  data-output-dir 
						  server-list
						  source-machine) 


;;when calling detect-sort-label..., need to remember to add data-output-dir to results-filename and frame-data-filename
  (get-object-detections-all-floorplans data-directory 
					output-directory 
					results-filename ;;remember to add data-output-dir to this and frame-data...
					frame-data-filename
					data-output-dir
					server-list
					source-machine)
  ))

(define (codetect-sort-templabel-auto-drive data-output-dirname)
 (let* ((data-directory
	 "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/auto-drive/")
	(top-k 10)
	(ssize 64)
	(alpha 1)
	(beta 1)
	(gamma 1)
	(delta 0)
	(dummy-f 0.6)
	(dummy-g 0.6)
	(output-directory
	 (format #f  "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/results-~a"
		 data-output-dirname))
	(data-output-dir data-output-dirname)
	(results-filename (format #f
				  "~a/results-~a-~a.sc"
				  data-output-dir
				  dummy-f
				  dummy-g))
	(frame-data-filename (format #f
				     "~a/frame-data-~a-~a.sc"
				     data-output-dir
				     dummy-f
				     dummy-g))
	(server-list
	 (list "aruco" "save" "akili" "aql" "verstand" "arivu")) ;; "perisikan" acting weird, jobs dying without finishing
	(source-machine "seykhl"))
  ;;TEMPORARY for re-run of auto-drive
  (get-codetection-results-auto-drive data-directory 
  						  top-k
  						  ssize
  						  alpha
  						  beta
  						  gamma
  						  delta
  						  dummy-f
  						  dummy-g
  						  output-directory 
  						  data-output-dir 
  						  server-list
  						  source-machine)
  


;;when calling detect-sort-label..., need to remember to add data-output-dir to results-filename and frame-data-filename
  (get-object-detections-all-floorplans data-directory 
					output-directory 
					results-filename ;;remember to add data-output-dir to this and frame-data...
					frame-data-filename
					data-output-dir
					server-list
					source-machine)
  ))

(define (get-ground-truth-from-dataset-file dataset-file)
 ;;should return list of lists of vectors of ground-truth object locations
 ;;for entire dataset
 (let* ((raw-data (read-object-from-file dataset-file))
	(labeled-floorplans (map (lambda (f) (first (first f))) raw-data))
	(ground-truth-lists (map (lambda (f) (map second f)) labeled-floorplans)))
  ground-truth-lists))

(define (get-labeled-ground-truth-from-dataset-file dataset-file)
 ;;should return list of lists of vectors of ground-truth object locations
 ;;for entire dataset
 (let* ((raw-data (read-object-from-file dataset-file))
	(labeled-floorplans (map (lambda (f) (first (first f))) raw-data)))
  labeled-floorplans))
	
(define (make-scheme-file-of-xys floorplan-dir results-file output-file)
 (let* ((rundirs (system-output (format #f "ls -d ~a/*/" floorplan-dir)))
	(xys (join
	      (map
	       (lambda (f)
		(get-xy-from-results-file
		 (format #f "~a~a" f results-file)))
	       rundirs))))
  (write-object-to-file xys output-file)))
	     
(define (make-scheme-file-of-xys-separated floorplan-dir results-file output-file)
 (let* ((rundirs (system-output (format #f "ls -d ~a/*/" floorplan-dir)))
	(xys (map
	      (lambda (f)
	       (get-xy-from-results-file
		(format #f "~a~a" f results-file)))
	      rundirs)))
  (write-object-to-file xys output-file)))

(define (scott-proposals-only top-k data-path)
 (let* ((video-path (format #f "~a/video_front.avi" data-path))
	(frames (video->frames 1 video-path))
	(tt (length frames))
	(poses (align-frames-with-poses data-path tt))
	(one-frame (first frames))
	(height (imlib:height one-frame))
	(width (imlib:width one-frame)))
  (start-matlab!)
  (scheme->matlab! "poses" poses)
  (matlab (format #f "frames=zeros(~a,~a,~a,~a,'uint8');" height width 3 tt))
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
  (matlab (format #f "bboxes=scott_proposals_only(~a,frames,poses);" top-k))
  (map-n (lambda (t)
	  (matlab (format #f "tmp=bboxes(:,:,~a);" (+ t 1)))
	  (matlab-get-variable "tmp"))
	 tt)))
	
;;;----NEW STUFF 17NOV15----
(define (run-codetection-only-house-test data-output-dirname)
 (let* ((data-directory
	 "/aux/sbroniko/vader-rover/logs/house-test-12nov15/")
	(top-k 10)
	(ssize 64)
	(alpha 1)
	(beta 1)
	(gamma 1)
	(delta 0)
	(dummy-f 0.6)
	(dummy-g 0.6)
	(output-directory
	 (format #f  "/aux/sbroniko/vader-rover/logs/results-house-test-~a"
		 data-output-dirname))
	(data-output-dir data-output-dirname)
	(results-filename (format #f
				  "~a/results-~a-~a.sc"
				  data-output-dir
				  dummy-f
				  dummy-g))
	(frame-data-filename (format #f
				     "~a/frame-data-~a-~a.sc"
				     data-output-dir
				     dummy-f
				     dummy-g))
	(server-list
	 (list "aruco" "save" "akili" "verstand" "arivu" "perisikan" "cuddwybodaeth" "istihbarat" "wywiad" "jalitusteabe"))
	  ;;all servers except upplysingaoflun, aql
	(source-machine "seykhl"))
  (get-codetection-results-house-test data-directory 
						  top-k
						  ssize
						  alpha
						  beta
						  gamma
						  delta
						  dummy-f
						  dummy-g
						  output-directory 
						  data-output-dir 
						  server-list
						  source-machine)   
  ))
(define (run-codetection-only-house-test-2 data-output-dirname)
 (let* ((data-directory
	 "/aux/sbroniko/vader-rover/logs/house-test-12nov15/")
	(top-k 10)
	(ssize 64)
	(alpha 1)
	(beta 1)
	(gamma 1)
	(delta 0)
	(dummy-f 0.6)
	(dummy-g 0.6)
	(output-directory
	 (format #f  "/aux/sbroniko/vader-rover/logs/results-house-test-~a"
		 data-output-dirname))
	(data-output-dir data-output-dirname)
	(results-filename (format #f
				  "~a/results-~a-~a.sc"
				  data-output-dir
				  dummy-f
				  dummy-g))
	(frame-data-filename (format #f
				     "~a/frame-data-~a-~a.sc"
				     data-output-dir
				     dummy-f
				     dummy-g))
	(server-list
	 (list "aruco" "save" "akili" "verstand" "arivu" "perisikan" "cuddwybodaeth" "istihbarat" "wywiad" "jalitusteabe"))
	  ;;all servers except upplysingaoflun, aql
	(source-machine "seykhl"))
  (get-codetection-results-house-test-2 data-directory 
					top-k
					ssize
					alpha
					beta
					gamma
					delta
					dummy-f
					dummy-g
					output-directory 
					data-output-dir 
					server-list
					source-machine)   
  ))

;; gets codetection results for every run in a dataset
(define (get-codetection-results-house-test
	 data-directory ;; NEED slash on data-dir
	 top-k
	 ssize
	 alpha
	 beta
	 gamma
	 delta
	 dummy-f
	 dummy-g
	 output-directory ;;NO slash on output-dir--this is a full path
	 data-output-dir ;;this is just a DIR NAME that will be under each run dir
	 server-list
	 source-machine ;;just a string, i.e., "seykhl"
	 )
 (let* ((servers server-list)
	(source source-machine)
	(matlab-cpus-per-job 8);;4);; for under-the-hood matlab parallelism
	(c-cpus-per-job 1)
	(output-matlab (format #f "~a-matlab/" output-directory))
	(output-c (format #f "~a-c/" output-directory))
	;;(plandirs (system-output (format #f "ls ~a | grep plan" data-directory)))
	;; (dir-list (join
	;; 	   (map
	;; 	    (lambda (p)
	;; 	     (map (lambda (d) (format #f "~a/~a/~a" data-directory p d))
	;; 		  (system-output
	;; 		   (format #f "ls ~a/~a | grep 201" data-directory p))))
	;; 	    plandirs)))
	(dir-list (map
		   (lambda (d) (format #f "~a/~a" data-directory d))
		   (system-output (format #f "ls ~a | grep floor" data-directory))))
	(commands-matlab
	 (map
	  (lambda (dir) 
	   (format #f "(load \"/home/sbroniko/codetection/source/new-sentence-codetection/codetection-test.sc\") (get-matlab-data-house-test \"~a\" ~a ~a ~a ~a ~a ~a ~a ~a \"~a\") :n :n :n :n :b" dir top-k ssize alpha beta gamma delta dummy-f dummy-g data-output-dir)) dir-list))
	(commands-c ;;if something breaks this might be it--not sure I have path changes right
	 (map
	  (lambda (dir)
	   (format #f "(load \"/home/sbroniko/codetection/source/new-sentence-codetection/codetection-test.sc\") (visualize-results-improved \"~a\" ~a ~a \"~a\") :n :n :n :n :b"
		   dir
		   dummy-f
		   dummy-g
		   data-output-dir)) dir-list))
	)
  (dtrace "starting get-codetection-results-house-test" #f)
  (system "date")
  ;; (for-each (lambda (server dir) (mkdir-p (format #f "/net/~a~a" server dir)))
  ;; 	    servers (list output-matlab output-c)) ;;this had problems using /net
  ;; (for-each (lambda (dir)
  ;; 	     (for-each (lambda (server) (rsync-directory-to-server source dir server))
  ;; 		       servers))
  ;; 	    (list output-matlab output-c))  ;;NOT NECESSARY
  (for-each (lambda (dir) (mkdir-p dir)) (list output-matlab output-c))
  (for-each (lambda (dir)
	     (for-each (lambda (server) (run-unix-command-on-server
					 (format #f "mkdir -p ~a" dir) server))
		       servers))
	    (list output-matlab output-c))
  (dtrace "starting matlab processing" #f)
  (system "date")
  (synchronous-run-commands-in-parallel-with-queueing commands-matlab
  						      servers
  						      matlab-cpus-per-job
  						      output-matlab
  						      source
  						      data-directory)
  (dtrace "matlab processing complete" #f)
  (system "date")
  (for-each (lambda (server)
	     (rsync-directory-to-server server data-directory source))
	    servers) ;;copy results back to source
  (dtrace "matlab results rsync'd, starting c processing" #f)
  (system "date")
  (synchronous-run-commands-in-parallel-with-queueing commands-c
  						      servers
  						      c-cpus-per-job
  						      output-c
  						      source
  						      data-directory)
  (for-each (lambda (server)
	     (rsync-directory-to-server server data-directory source))
	    servers) ;;copy results back to source
  (dtrace "processing complete for get-codetection-results-house-test" #f)
  (system "date")))

(define (get-codetection-results-house-test-2 ;;new version that only runs c stuff, and spreads the load out more
	 data-directory ;; NEED slash on data-dir
	 top-k
	 ssize
	 alpha
	 beta
	 gamma
	 delta
	 dummy-f
	 dummy-g
	 output-directory ;;NO slash on output-dir--this is a full path
	 data-output-dir ;;this is just a DIR NAME that will be under each run dir
	 server-list
	 source-machine ;;just a string, i.e., "seykhl"
	 )
 (let* ((servers server-list)
	(source source-machine)
	(matlab-cpus-per-job 8);;4);; for under-the-hood matlab parallelism
	(c-cpus-per-job 40) ;;1)
	(output-matlab (format #f "~a-matlab/" output-directory))
	(output-c (format #f "~a-c/" output-directory))
	;;(plandirs (system-output (format #f "ls ~a | grep plan" data-directory)))
	;; (dir-list (join
	;; 	   (map
	;; 	    (lambda (p)
	;; 	     (map (lambda (d) (format #f "~a/~a/~a" data-directory p d))
	;; 		  (system-output
	;; 		   (format #f "ls ~a/~a | grep 201" data-directory p))))
	;; 	    plandirs)))
	(dir-list (map
		   (lambda (d) (format #f "~a/~a" data-directory d))
		   (system-output (format #f "ls ~a | grep floor" data-directory))))
	(commands-matlab
	 (map
	  (lambda (dir) 
	   (format #f "(load \"/home/sbroniko/codetection/source/new-sentence-codetection/codetection-test.sc\") (get-matlab-data-house-test \"~a\" ~a ~a ~a ~a ~a ~a ~a ~a \"~a\") :n :n :n :n :b" dir top-k ssize alpha beta gamma delta dummy-f dummy-g data-output-dir)) dir-list))
	(commands-c ;;if something breaks this might be it--not sure I have path changes right
	 (map
	  (lambda (dir)
	   (format #f "(load \"/home/sbroniko/codetection/source/new-sentence-codetection/codetection-test.sc\") (visualize-results-improved \"~a\" ~a ~a \"~a\") :n :n :n :n :b"
		   dir
		   dummy-f
		   dummy-g
		   data-output-dir)) dir-list))
	)
  (dtrace "starting get-codetection-results-house-test-2" #f)
  (system "date")
  ;; (for-each (lambda (server dir) (mkdir-p (format #f "/net/~a~a" server dir)))
  ;; 	    servers (list output-matlab output-c)) ;;this had problems using /net
  ;; (for-each (lambda (dir)
  ;; 	     (for-each (lambda (server) (rsync-directory-to-server source dir server))
  ;; 		       servers))
  ;; 	    (list output-matlab output-c))  ;;NOT NECESSARY
  (for-each (lambda (dir) (mkdir-p dir)) (list output-matlab output-c))
  (for-each (lambda (dir)
	     (for-each (lambda (server) (run-unix-command-on-server
					 (format #f "mkdir -p ~a" dir) server))
		       servers))
	    (list output-matlab output-c))
  ;; (dtrace "starting matlab processing" #f)
  ;; (system "date")
  ;; (synchronous-run-commands-in-parallel-with-queueing commands-matlab
  ;; 						      servers
  ;; 						      matlab-cpus-per-job
  ;; 						      output-matlab
  ;; 						      source
  ;; 						      data-directory)
  ;; (dtrace "matlab processing complete" #f)
  (system "date")
  (for-each (lambda (server)
	     (rsync-directory-to-server server data-directory source))
	    servers) ;;copy results back to source
  (dtrace "matlab results rsync'd, starting c processing" #f)
  (system "date")
  (synchronous-run-commands-in-parallel-with-queueing commands-c
  						      servers
  						      c-cpus-per-job
  						      output-c
  						      source
  						      data-directory)
  (for-each (lambda (server)
	     (rsync-directory-to-server server data-directory source))
	    servers) ;;copy results back to source
  (dtrace "processing complete for get-codetection-results-house-test" #f)
  (system "date")))

(define (get-matlab-data-house-test
	 path top-k ssize alpha beta gamma delta dummy-f dummy-g data-output-dir)
 (mkdir-p (format #f "~a/~a" path data-output-dir))
 (write-object-to-file
  (get-matlab-proposals-similarity-full-video
   top-k ssize (format #f "~a" path) alpha beta gamma delta)
  (format #f "~a/~a/frame-data-~a-~a.sc" path data-output-dir
	  (number->padded-string-of-length dummy-f 3)
	  (number->padded-string-of-length dummy-g 3)))
 (dtrace (format #f "wrote ~a/~a/frame-data-~a-~a.sc" path data-output-dir
		 (number->padded-string-of-length dummy-f 3)
		 (number->padded-string-of-length dummy-g 3)) #f))


(define (quick-and-dirty-test)
 (let* ((data-directory
	 "/aux/sbroniko/vader-rover/logs/house-test-12nov15/")
	(top-k 10)
	(ssize 64)
	(alpha 1)
	(beta 1)
	(gamma 1)
	(delta 0)
	(dummy-f 0.6)
	(dummy-g 0.6)
	(data-output-dirname "quick-test")
	(output-directory
	 (format #f  "/aux/sbroniko/vader-rover/logs/results-house-test-~a"
		 data-output-dirname))
	(data-output-dir data-output-dirname)
	(results-filename (format #f
				  "~a/results-~a-~a.sc"
				  data-output-dir
				  dummy-f
				  dummy-g))
	(frame-data-filename (format #f
				     "~a/frame-data-~a-~a.sc"
				     data-output-dir
				     dummy-f
				     dummy-g))
	(run-dir "floorplan-1-sentence-5")
	(dir (format #f "~a~a" data-directory run-dir)))

  (get-matlab-data-house-test dir
			      top-k
			      ssize
			      alpha
			      beta
			      gamma
			      delta
			      dummy-f
			      dummy-g
			      data-output-dir)
  (visualize-results-improved dir dummy-f dummy-g data-output-dir)))

(define (single-run-test data-output-dirname top-k)
 (let* ((data-directory
	 "/aux/sbroniko/vader-rover/logs/house-test-12nov15/")
	(*house-x-y* (read-object-from-file "/aux/sbroniko/vader-rover/logs/house-test-12nov15/house-x-y.sc"))
	(*the-max* (* 1.1 (max (first (first *house-x-y*))
			       (first (second *house-x-y*)))))
	(*the-min* (* 1.1 (min (second (first *house-x-y*))
			       (second (second *house-x-y*)))))
	(max-x *the-max*)
	(max-y *the-max*)
	(min-x *the-min*)
	(min-y *the-min*)
	;;(top-k 10)
	(ssize 64)
	(alpha 1)
	(beta 1)
	(gamma 1)
	(delta 0)
	(dummy-f 0.6)
	(dummy-g 0.6)
;;	(data-output-dirname "quick-test")
	(output-directory
	 (format #f  "/aux/sbroniko/vader-rover/logs/results-house-test-~a"
		 data-output-dirname))
	(data-output-dir data-output-dirname)
	(results-filename (format #f
				  "~a/results-~a-~a.sc"
				  data-output-dir
				  dummy-f
				  dummy-g))
	(frame-data-filename (format #f
				     "~a/frame-data-~a-~a.sc"
				     data-output-dir
				     dummy-f
				     dummy-g))
	(run-dir "floorplan-0-sentence-1")
	(dir (format #f "~a~a" data-directory run-dir)))

  (dtrace (format #f "starting single-run-test in ~a" data-output-dirname) #f)
  (system "date")
  (get-matlab-data-house-test-new dir
				  top-k
				  ssize
				  alpha
				  beta
				  gamma
				  delta
				  dummy-f
				  dummy-g
				  data-output-dir
				  min-x
				  max-x
				  min-y
				  max-y)
  (visualize-results-improved dir dummy-f dummy-g data-output-dir)
  (system (format #f "rsync -avrz ~a/~a/~a/ seykhl:~a/~a/~a/"
		  data-directory
		  run-dir
		  data-output-dirname
		  data-directory
		  run-dir
		  data-output-dirname))
  (dtrace (format #f "finished single-run-test in ~a" data-output-dirname) #f)
  (system "date")
  ))

(define (single-run-test-new data-output-dirname top-k)
 (let* ((data-directory
	 "/aux/sbroniko/vader-rover/logs/house-test-12nov15/")
	(*house-x-y* (read-object-from-file "/aux/sbroniko/vader-rover/logs/house-test-12nov15/house-x-y.sc"))
	(*the-max* (* 1.1 (max (first (first *house-x-y*))
			       (first (second *house-x-y*)))))
	(*the-min* (* 1.1 (min (second (first *house-x-y*))
			       (second (second *house-x-y*)))))
	(max-x *the-max*)
	(max-y *the-max*)
	(min-x *the-min*)
	(min-y *the-min*)
	(ssize 64)
	(dummy-f 0.6)
	(dummy-g 0.6)
	(output-directory
	 (format #f  "/aux/sbroniko/vader-rover/logs/results-house-test-~a"
		 data-output-dirname))
	(data-output-dir data-output-dirname)
	(results-filename (format #f
				  "~a/results-~a-~a.sc"
				  data-output-dir
				  dummy-f
				  dummy-g))
	(frame-data-filename (format #f
				     "~a/frame-data-~a-~a.sc"
				     data-output-dir
				     dummy-f
				     dummy-g))
	(run-dir "test-segment")
	(dir (format #f "~a~a" data-directory run-dir))
	(proposal-file (format #f "~a/proposal_boxes_1000.mat" dir))
	(discount-factor 0.1))

  (dtrace (format #f "starting single-run-test-new in ~a" data-output-dirname) #f)
  (system "date")
  (get-matlab-data-house-test-new2 dir
				   top-k
				   ssize
				   dummy-f
				   dummy-g
				   data-output-dir
				   min-x
				   max-x
				   min-y
				   max-y
				   proposal-file
				   discount-factor)
  (visualize-results-improved-new dir
				  dummy-f
				  dummy-g
				  data-output-dir
				  discount-factor)
  (system (format #f "rsync -arz ~a/~a/~a/ seykhl:~a/~a/~a/"
		  data-directory
		  run-dir
		  data-output-dirname
		  data-directory
		  run-dir
		  data-output-dirname))
  (dtrace (format #f "finished single-run-test-new in ~a" data-output-dirname) #f)
  (system "date")
  ))

(define (single-run-test-new2 data-output-dirname top-k dummy-f dummy-g)
 (let* ((data-directory
	 "/aux/sbroniko/vader-rover/logs/house-test-12nov15/")
	(*house-x-y* (read-object-from-file "/aux/sbroniko/vader-rover/logs/house-test-12nov15/house-x-y.sc"))
	(*the-max* (* 1.1 (max (first (first *house-x-y*))
			       (first (second *house-x-y*)))))
	(*the-min* (* 1.1 (min (second (first *house-x-y*))
			       (second (second *house-x-y*)))))
	(max-x *the-max*)
	(max-y *the-max*)
	(min-x *the-min*)
	(min-y *the-min*)
	(ssize 64)
;;	(dummy-f 0.6)
;;	(dummy-g 0.6)
	(output-directory
	 (format #f  "/aux/sbroniko/vader-rover/logs/results-house-test-~a"
		 data-output-dirname))
	(data-output-dir data-output-dirname)
	;; (results-filename (format #f
	;; 			  "~a/results-~a-~a.sc"
	;; 			  data-output-dir
	;; 			  dummy-f
	;; 			  dummy-g))
	;; (frame-data-filename (format #f
	;; 			     "~a/frame-data-~a-~a.sc"
	;; 			     data-output-dir
	;; 			     dummy-f
	;; 			     dummy-g))
	(run-dir "test-segment")
	(dir (format #f "~a~a" data-directory run-dir))
	(proposal-file (format #f "~a/proposal_boxes_1000.mat" dir))
	(discount-factor 0.1))

  (dtrace (format #f "starting single-run-test-new in ~a" data-output-dirname) #f)
  (system "date")
  (get-matlab-data-house-test-new2 dir
				   top-k
				   ssize
				   dummy-f
				   dummy-g
				   data-output-dir
				   min-x
				   max-x
				   min-y
				   max-y
				   proposal-file
				   discount-factor)
  (visualize-results-improved-new dir
				  dummy-f
				  dummy-g
				  data-output-dir
				  discount-factor)
  (system (format #f "rsync -arz ~a/~a/~a/ seykhl:~a/~a/~a/"
		  data-directory
		  run-dir
		  data-output-dirname
		  data-directory
		  run-dir
		  data-output-dirname))
  (dtrace (format #f "finished single-run-test-new in ~a" data-output-dirname) #f)
  (system "date")
  ))

(define (single-run-test-viterbi data-output-dir top-k world-weight discount-factor)
 (let* ((data-directory
	 "/aux/sbroniko/vader-rover/logs/house-test-12nov15/")
	(*house-x-y*
	 (read-object-from-file
	  "/aux/sbroniko/vader-rover/logs/house-test-12nov15/house-x-y.sc"))
	(*the-max* (* 1.1 (max (first (first *house-x-y*))
			       (first (second *house-x-y*)))))
	(*the-min* (* 1.1 (min (second (first *house-x-y*))
			       (second (second *house-x-y*)))))
	(max-x *the-max*)
	(max-y *the-max*)
	(min-x *the-min*)
	(min-y *the-min*)
	(ssize 64)
	(run-dir "test-segment")
	(dir (format #f "~a~a" data-directory run-dir))
	(proposal-file (format #f "~a/proposal_boxes_edgeboxes_2500.mat" dir))

	 ;;(format #f "~a/proposal_boxes_1000.mat" dir))
	;; (discount-factor 0.1)
	)
  (dtrace (format #f "starting single-run-test-viterbi in ~a" data-output-dir) #f)
  (system "date")
  (visualize-results-viterbi dir
			     top-k
			     ssize
			     data-output-dir
			     min-x
			     max-x
			     min-y
			     max-y
			     proposal-file
			     discount-factor
			     world-weight)
  (system (format #f "rsync -arz ~a/~a/~a/ seykhl:~a/~a/~a/"
		  data-directory
		  run-dir
		  data-output-dir
		  data-directory
		  run-dir
		  data-output-dir))
  (dtrace (format #f "finished single-run-test-viterbi in ~a" data-output-dir) #f)
  (system "date")))

(define (single-run-test-viterbi-multiple
	 data-output-dir top-k world-weight discount-factor num-tubes reduce-factor)
 (let* ((data-directory
	 "/aux/sbroniko/vader-rover/logs/house-test-12nov15/")
	(*house-x-y*
	 (read-object-from-file
	  "/aux/sbroniko/vader-rover/logs/house-test-12nov15/house-x-y.sc"))
	(*the-max* (* 1.1 (max (first (first *house-x-y*))
			       (first (second *house-x-y*)))))
	(*the-min* (* 1.1 (min (second (first *house-x-y*))
			       (second (second *house-x-y*)))))
	(max-x *the-max*)
	(max-y *the-max*)
	(min-x *the-min*)
	(min-y *the-min*)
	(ssize 64)
	(run-dir "test-segment")
	(dir (format #f "~a~a" data-directory run-dir))
	(proposal-file (format #f "~a/proposal_boxes_edgeboxes_2500.mat" dir))

	 ;;(format #f "~a/proposal_boxes_1000.mat" dir))
	;; (discount-factor 0.1)
	)
  (dtrace (format #f "starting single-run-test-viterbi-multiple in ~a"
		  data-output-dir) #f)
  (system "date")
  (visualize-results-viterbi-multiple dir
				      top-k
				      ssize
				      data-output-dir
				      min-x
				      max-x
				      min-y
				      max-y
				      proposal-file
				      discount-factor
				      world-weight
				      num-tubes
				      reduce-factor)
  (system (format #f "rsync -arz ~a/~a/~a/ seykhl:~a/~a/~a/"
		  data-directory
		  run-dir
		  data-output-dir
		  data-directory
		  run-dir
		  data-output-dir))
  (dtrace (format #f "finished single-run-test-viterbi-multiple in ~a"
		  data-output-dir) #f)
  (system "date")))
  

(define (read-camera-timing-new path)
 (let* ((lines (read-file path))
       (data-lines (sublist lines 2 (- (length lines) 2))))
  (map (lambda (l) (string->number (first (pregexp-split ":" l)))) data-lines)))


;;;;----temporary testing-data stuff-------
;;;COMMENT OUT THE FOUR LINES BELOW UNLESS TRYING TO RE-ADD THE DATA
;; (define test-data-small #f) (define test-data-medium #f) (define test-data-large #f) (define test-data-full #f)

;; (define (load-data)
;;  (dtrace "starting load-data" #f)
;;  (system "date")
;;  (set! test-data-small (get-matlab-proposals-similarity-by-frame 10 64 "/home/sbroniko/codetection/testing-data" 17 20 1 1 1 0))
;;  (dtrace "loaded test-data-small" #f)
;;  (system "date")
;;  (set! test-data-medium (get-matlab-proposals-similarity-by-frame 10 64 "/home/sbroniko/codetection/testing-data" 17 46 1 1 1 0))
;;  (dtrace "loaded test-data-medium" #f)
;;  (system "date")
;;  (set! test-data-large (get-matlab-proposals-similarity-by-frame 10 64 "/home/sbroniko/codetection/testing-data" 17 116 1 1 1 0))
;;  (dtrace "loaded test-data-large" #f)
;;  (system "date")
;;  (set! test-data-full (get-matlab-proposals-similarity-full-video 10 64 "/home/sbroniko/codetection/testing-data" 1 1 1 0))
;;  (dtrace "loaded test-data-full, load complete" #f)
;;  (system "date"))


;;  (define test-data-small (read-object-from-file "/home/sbroniko/codetection/testing-data/test-data-small.sc"))
;;  (define test-data-medium (read-object-from-file "/home/sbroniko/codetection/testing-data/test-data-medium.sc"))
;;  (define test-data-large (read-object-from-file "/home/sbroniko/codetection/testing-data/test-data-large.sc"))
;;  (define test-data-full (read-object-from-file "/home/sbroniko/codetection/testing-data/test-data-full.sc"))

;; (define test-frames-full
;;  (let* ((data-path "/home/sbroniko/codetection/testing-data")
;; 	(video-path (format #f "~a/video_front.avi" data-path)))
;;   (video->frames 1 video-path)))

;; (define test-frames-small (sublist test-frames-full 16 20))

;; (define test-frames-medium (sublist test-frames-full 16 46))

;; (define test-frames-large (sublist test-frames-full 16 116))

;;to plot object detections from all floorplans
;;(map (lambda (num) (matlab "figure") (plot-objects-from-floorplan (format #f "/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation/plan~a" num) "test20150617/results-0.6-0.6.sc")) (list 0 1 2 3 4 5 6 7 8 9))

(define (get-matlab-data-house-test-new
	 path top-k ssize alpha beta gamma delta dummy-f dummy-g data-output-dir min-x max-x min-y max-y)
 (mkdir-p (format #f "~a/~a" path data-output-dir))
 (write-object-to-file
  (get-matlab-proposals-similarity-full-video-new
   top-k ssize path alpha beta gamma delta data-output-dir min-x max-x min-y max-y)
  (format #f "~a/~a/frame-data-~a-~a.sc" path data-output-dir
	  (number->padded-string-of-length dummy-f 3)
	  (number->padded-string-of-length dummy-g 3)))
 (dtrace (format #f "wrote ~a/~a/frame-data-~a-~a.sc" path data-output-dir
		 (number->padded-string-of-length dummy-f 3)
		 (number->padded-string-of-length dummy-g 3)) #f))

(define (get-matlab-data-house-test-new2
	 path top-k ssize dummy-f dummy-g
	 data-output-dir min-x max-x min-y max-y proposal-file discount-factor)
 (mkdir-p (format #f "~a/~a" path data-output-dir))
 (write-object-to-file
  (get-matlab-proposals-similarity-full-video-new2
   top-k ssize path data-output-dir min-x max-x min-y max-y
   proposal-file discount-factor)
  (format #f "~a/~a/frame-data-~a-~a.sc" path data-output-dir ;;dummy-f dummy-g))
	  (number->padded-string-of-length dummy-f 3)
	  (number->padded-string-of-length dummy-g 3)))
 (dtrace (format #f "wrote ~a/~a/frame-data-~a-~a.sc" path data-output-dir
;;		 dummy-f dummy-g
		 (number->padded-string-of-length dummy-f 3)
		 (number->padded-string-of-length dummy-g 3)
		 ) #f))


(define (get-matlab-proposals-similarity-full-video-new top-k
							box-size
							data-path
							alpha
							beta
							gamma
							delta
							data-output-dir
							min-x max-x min-y max-y)
 (let* ((video-path (format #f "~a/video_front.avi" data-path))
	(frames (video->frames 1 video-path))
	(poses (align-frames-with-poses data-path (length frames)))
	(coeff-sum (+ alpha beta gamma delta))
	(alpha-norm (/ alpha coeff-sum))
	(beta-norm (/ beta coeff-sum))
	(gamma-norm (/ gamma coeff-sum))
	(delta-norm (/ delta coeff-sum)))
  (dtrace
   "in new-sentence-codetection/get-matlab-proposals-similarity-full-video-new" #f)
  (get-matlab-proposals-similarity-new top-k
				       box-size
				       frames
				       poses
				       alpha-norm
				       beta-norm
				       gamma-norm
				       delta-norm
				       data-path
				       data-output-dir
				       min-x max-x min-y max-y)))

(define (get-matlab-proposals-similarity-full-video-new2 top-k
							 box-size
							 data-path
							 data-output-dir
							 min-x max-x min-y max-y
							 proposal-file
							 discount-factor)
 (let* ((video-path (format #f "~a/video_front.avi" data-path))
	(frames (video->frames 1 video-path))
	(poses (align-frames-with-poses data-path (length frames))))
  (dtrace
   "in new-sentence-codetection/get-matlab-proposals-similarity-full-video-new2" #f)
  (get-matlab-proposals-similarity-new2 top-k
					box-size
					frames
					poses
					data-path
					data-output-dir
					min-x max-x min-y max-y
					proposal-file
					discount-factor)))

(define (get-matlab-proposals-similarity-new top-k
					     box-size
					     frames
					     poses
					     alpha-norm
					     beta-norm
					     gamma-norm
					     delta-norm
					     data-path
					     data-output-dir
					     min-x max-x min-y max-y)
 (let* ((num-frames (length frames))
	(one-frame (first frames))
	(height (imlib:height one-frame))
	(width (imlib:width one-frame)))
  ;;(list frames poses)
  (start-matlab!)
  (matlab "addpath(genpath('/home/sbroniko/codetection/source/new-sentence-codetection/'))")
  (if (not
       (file-exists? (format #f "~a/~a/proposal_data.mat" data-path data-output-dir)))
      (begin
       (scheme->matlab! "poses" poses)
       (matlab (format #f "frames = zeros(~a,~a,~a,~a,'uint8');" height width 3 num-frames))
       ;; convert frames to matlab matrix
       (for-each-indexed
	(lambda (frame i)
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
       ;; call matlab function
       ;; (matlab
       ;;  (format
       ;;   #f
       ;;   "[boxes_w_fscore,gscore,num_gscore] = scott_proposals_similarity2(~a,~a,frames,poses,~a,~a,~a);"
       ;;   top-k box-size alpha-norm beta-norm gamma-norm))
       
       (dtrace "calling new_proposals_and_dsift" #f)
       (matlab
	(format
	 #f
	 "[bboxes,valid_loc,phists] = new_proposals_and_dsift(~a,~a,frames,poses,~a,~a,~a,~a);"
	 top-k box-size min-x max-x min-y max-y))
       (matlab (format #f
		       "save('~a/~a/proposal_data.mat','bboxes','valid_loc','phists');"
		       data-path data-output-dir))))
  (matlab (format #f "load('~a/~a/proposal_data.mat');" data-path data-output-dir))
  (dtrace (format #f "loaded ~a/~a/proposal_data.mat" data-path data-output-dir) #f)
  (matlab
   (format
    #f
    "[boxes_w_fscore,gscore,num_gscore] = new_binary_scores(bboxes,valid_loc,phists,~a,~a,~a,~a,~a);"
    num-frames top-k alpha-norm beta-norm gamma-norm))

  ;; convert matlab variables to scheme
  (list (map-n (lambda (t)
		(matlab (format #f "tmp=boxes_w_fscore(:,:,~a);" (+ t 1)))
		(matlab-get-variable "tmp"))
	       num-frames)
	  (matlab-get-variable "gscore")
	  (matlab-get-variable "num_gscore"))

  ))

(define (get-matlab-proposals-similarity-new2 top-k
					      box-size
					      frames
					      poses
					      data-path
					      data-output-dir
					      min-x max-x min-y max-y
					      proposal-file
					      discount-factor)
 (let* ((num-frames (length frames))
	(one-frame (first frames))
	(height (imlib:height one-frame))
	(width (imlib:width one-frame)))
  ;;(list frames poses)
  (start-matlab!)
  (matlab "addpath(genpath('/home/sbroniko/codetection/source/new-sentence-codetection/'))")
  (if (not
       (file-exists? (format #f "~a/~a/proposal_data.mat" data-path data-output-dir)))
      (begin
       (scheme->matlab! "poses" poses)
       (matlab (format #f "frames = zeros(~a,~a,~a,~a,'uint8');" height width 3 num-frames))
       ;; convert frames to matlab matrix
       (for-each-indexed
	(lambda (frame i)
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
       ;; call matlab function
       ;; (matlab
       ;;  (format
       ;;   #f
       ;;   "[boxes_w_fscore,gscore,num_gscore] = scott_proposals_similarity2(~a,~a,frames,poses,~a,~a,~a);"
       ;;   top-k box-size alpha-norm beta-norm gamma-norm))
       (matlab (format #f "load('~a')" proposal-file))
       (dtrace "calling new_score_saved_proposals_with_dsift" #f)
       (matlab
	(format
	 #f
	 "[bboxes,phists] = new_score_saved_proposals_with_dsift(proposal_boxes,~a,~a,frames,poses,~a,~a,~a,~a,~a);"
	 top-k box-size min-x max-x min-y max-y discount-factor))
       (matlab (format #f
		       "save('~a/~a/proposal_data.mat','bboxes','phists');"
		       data-path data-output-dir))))
  (matlab (format #f "load('~a/~a/proposal_data.mat');" data-path data-output-dir))
  (dtrace (format #f "loaded ~a/~a/proposal_data.mat" data-path data-output-dir) #f)
  (matlab
    "[boxes_w_fscore,gscore,num_gscore] = new_binary_scores_world_and_pixel(bboxes);")

  ;; convert matlab variables to scheme
  (list (map-n (lambda (t)
		(matlab (format #f "tmp=boxes_w_fscore(:,:,~a);" (+ t 1)))
		(matlab-get-variable "tmp"))
	       num-frames)
	  (matlab-get-variable "gscore")
	  (matlab-get-variable "num_gscore"))))

(define (get-matlab-proposals-similarity-viterbi top-k
						 box-size
						 data-path
						 data-output-dir
						 min-x max-x min-y max-y
						 proposal-file
						 discount-factor
						 world-weight)
 (let* ((video-path (format #f "~a/video_front.avi" data-path))
	(frames (video->frames 1 video-path))
	(num-frames (length frames))
	(poses (align-frames-with-poses data-path num-frames))
	(one-frame (first frames))
	(height (imlib:height one-frame))
	(width (imlib:width one-frame)))
  (dtrace
   "in new-sentence-codetection/get-matlab-proposals-similarity-viterbi" #f)
  (start-matlab!)
  (matlab "addpath(genpath('/home/sbroniko/codetection/source/new-sentence-codetection/'))")
  (if (not
       (file-exists? (format #f "~a/~a/proposal_data.mat" data-path data-output-dir)))
      (begin
       (scheme->matlab! "poses" poses)
       (matlab (format #f "frames = zeros(~a,~a,~a,~a,'uint8');" height width 3 num-frames))
       ;; convert frames to matlab matrix
       (for-each-indexed
	(lambda (frame i)
	 (with-temporary-file
	  "/tmp/imlib-frame.ppm"
	  (lambda (tmp-frame)
	   ;; write scheme frame to file
	   (imlib:save-image frame tmp-frame)
	   ;; read file as matlab frame
	   (matlab (format #f "frame=imread('~a');" tmp-frame))
	   (matlab (format #f "frames(:,:,:,~a)=uint8(frame);" (+ i 1)))))
	 (imlib:free-image-and-decache frame))    
	frames)
       ;; call matlab function
       (matlab (format #f "load('~a')" proposal-file))
       (dtrace "calling new_score_saved_proposals_with_dsift" #f)
       (matlab
	(format
	 #f
	 "[bboxes] = new_score_saved_proposals_with_dsift2(proposal_boxes,~a,~a,frames,poses,~a,~a,~a,~a,~a);"
	 top-k box-size min-x max-x min-y max-y discount-factor)
	;; (format ;;OLD way with phists in output
	;;  #f
	;;  "[bboxes,phists] = new_score_saved_proposals_with_dsift2(proposal_boxes,~a,~a,frames,poses,~a,~a,~a,~a,~a);"
	;;  top-k box-size min-x max-x min-y max-y discount-factor)
	)
       (matlab (format #f"save('~a/~a/proposal_data.mat','bboxes')" ;;,'phists');" NOT USING PHISTS NOW
		       data-path data-output-dir))))
  (matlab (format #f "load('~a/~a/proposal_data.mat');" data-path data-output-dir))
  (dtrace (format #f "loaded ~a/~a/proposal_data.mat" data-path data-output-dir) #f)
  (matlab (format #f "a = ~a;" world-weight))
  (matlab
    "[boxes_w_fscore,gscore,num_gscore,G,binary_scores] = new_binary_scores_world_and_pixel2(bboxes,a);")
  (matlab (format #f "save('~a/~a/binary_score_data.mat','binary_scores');"
		  data-path data-output-dir))
  ;; convert matlab variables to scheme for output
  (list (map-n (lambda (t)
		(matlab (format #f "tmp=boxes_w_fscore(:,:,~a);" (+ t 1)))
		(matlab-get-variable "tmp"))
	       num-frames)
	  (matlab-get-variable "gscore")
	  (matlab-get-variable "num_gscore"))))


(define (get-and-save-proposal-boxes dir num-proposals)
 (let* ((video-path (format #f "~a/video_front.avi" dir))
	(frames (video->frames 1 video-path))
	(num-frames (length frames))
	(one-frame (first frames))
	(height (imlib:height one-frame))
	(width (imlib:width one-frame)))
  (dtrace (format #f "starting get-and-save-proposal-boxes in ~a" dir) #f)
  (start-matlab!)
  (matlab (format #f "num_proposals = ~a;" num-proposals))
  (matlab "addpath(genpath('/home/sbroniko/codetection/source/new-sentence-codetection/'))")
  (matlab (format #f "frames = zeros(~a,~a,~a,~a,'uint8');"
		  height width 3 num-frames))
  ;; convert frames to matlab matrix
  (for-each-indexed
   (lambda (frame i)
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
  (matlab "proposal_boxes = get_proposals(frames,num_proposals)")
  (matlab (format #f "filename = '~a/proposal_boxes_~a.mat';"
		  dir num-proposals))
  (matlab "save(filename,'proposal_boxes')")
  (matlab "clear proposal_boxes;")
  (if (file-exists? (format #f "~a/proposal_boxes_~a.mat" dir num-proposals))
      (dtrace (format #f "saved ~a/proposal_boxes_~a.mat" dir num-proposals) #f)
      (dtrace (format #f "**ERROR** saving ~a/proposal_boxes_~a.mat"
		      dir num-proposals) #f))
  ))

(define (get-and-save-proposal-boxes-all-videos num-proposals)
 (let* ((rundirs
	 (system-output
	  "ls -d /aux/sbroniko/vader-rover/logs/house-test-12nov15/*/")))
  (for-each
   (lambda (dir)
    (get-and-save-proposal-boxes dir num-proposals)) rundirs)))

(define (frames-and-poses->matlab dir)
 (let* ((video-path (format #f "~a/video_front.avi" dir))
	(frames (video->frames 1 video-path))
	(num-frames (length frames))
	(one-frame (first frames))
	(height (imlib:height one-frame))
	(width (imlib:width one-frame))
	(poses (align-frames-with-poses dir (length frames))))
  (start-matlab!)
  (matlab "addpath(genpath('/home/sbroniko/codetection/source/new-sentence-codetection/'))")
  (matlab (format #f "frames = zeros(~a,~a,~a,~a,'uint8');"
		  height width 3 num-frames))
  (scheme->matlab! "poses" poses)
  ;; convert frames to matlab matrix
  (for-each-indexed
   (lambda (frame i)
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
  ))


(define (simple-run-and-plot)
 (dtrace "starting simple-run-and-plot" #f)
 (system "date")
 (let* ((path "/aux/sbroniko/vader-rover/logs/house-test-12nov15/test-segment/")
	(testdirs ;; (list "20151130_top_k_10"
		  ;; 	"20151130_top_k_50"
		  ;; 	"20151130_top_k_100")
	 ;; (list "20151201_top_k_10"
	 ;;       "20151201_top_k_50"
	 ;;       "20151201_top_k_100")
	 ;; (list "20151201a_top_k_10"
	 ;;       "20151201a_top_k_50"
	 ;;       "20151201a_top_k_100")
	 ;; (list "20151201b_top_k_10"
	 ;;       "20151201b_top_k_50"
	 ;;       "20151201b_top_k_100")
	 (list "20151201c_top_k_10"
	       "20151201c_top_k_50"
	       "20151201c_top_k_100")
		  )
	(top-ks (list 10 50 100))
	(matlab-filename "detection_data.mat"))
  (single-run-test-new (first testdirs) (first top-ks))
  (single-run-test-new (second testdirs) (second top-ks))
  (single-run-test-new (third testdirs) (third top-ks))
  (for-each
   (lambda (testdir)
    (make-quad-video-and-plots-one-run path testdir matlab-filename)
    (system (format #f "rsync -arz ~a/~a/ seykhl:~a/~a/"
		  path testdir path testdir))
    )
   testdirs)
  (dtrace "simple-run-and-plot complete" #f)
  (system "date")
  ))

(define (simple-test testdir top-k dummy-f dummy-g)
 (dtrace "starting simple-test" #f)
 (system "date")
 (let* ((path "/aux/sbroniko/vader-rover/logs/house-test-12nov15/test-segment/")
	(matlab-filename "detection_data.mat"))
  (single-run-test-new2 testdir top-k dummy-f dummy-g)
  (make-quad-video-and-plots-one-run-new path
					 testdir
					 matlab-filename
					 dummy-f
					 dummy-g)
  (system (format #f "rsync -arz ~a/~a/ seykhl:~a/~a/"
		  path testdir path testdir)))
 (dtrace "simple-test complete" #f)
 (system "date"))

(define (simple-run-and-plot-new)
 (dtrace "starting simple-run-and-plot-new" #f)
 (system "date")
 (let* ((path "/aux/sbroniko/vader-rover/logs/house-test-12nov15/test-segment/")
	(testdirs
	 (list "20151203b_top_k_10"
	       "20151203b_top_k_50"
	       "20151203b_top_k_100"
	       "20151203b_top_k_200")
		  )
	(top-ks (list 10 50 100 200))
	(matlab-filename "detection_data.mat")
	(dummy-f 0.6)
	(dummy-g 0.6))
  (single-run-test-new2 (first testdirs) (first top-ks) dummy-f dummy-g)
  (single-run-test-new2 (second testdirs) (second top-ks) dummy-f dummy-g)
  (single-run-test-new2 (third testdirs) (third top-ks) dummy-f dummy-g)
  (single-run-test-new2 (fourth testdirs) (fourth top-ks) dummy-f dummy-g)
  (for-each
   (lambda (testdir)
    (make-quad-video-and-plots-one-run-new path
					   testdir
					   matlab-filename
					   dummy-f
					   dummy-g)
    (system (format #f "rsync -arz ~a/~a/ seykhl:~a/~a/"
		  path testdir path testdir))
    )
   testdirs)
  (dtrace "simple-run-and-plot complete-new" #f)
  (system "date")))


(define (simple-run-and-plot-viterbi)
 (dtrace "starting simple-run-and-plot-viterbi" #f)
 (system "date")
 (let* ((path "/aux/sbroniko/vader-rover/logs/house-test-12nov15/test-segment/")
	(world-weight 0.5);;1)
	;;(discount-factor 0.01);;0.1)
	(discount-factors (list 0.1 ));;0.3 0.5 0.7 0.9 1.1));;0.01);;0.1)
	(top-k 200)
	;;(top-ks (list 10 50 100 200 500 1000))
	(testdirs
	 (map (lambda (d)
	       (format #f "20151211_TESTING_ww_~a_df_~a_top_k_~a"
		       world-weight d top-k))
	      discount-factors))
	;; (testdirs
	;;  (map (lambda (k)
	;;        (format #f "20151211b_ww_~a_df_~a_top_k_~a"
	;; 	       world-weight discount-factor k))
	;;       top-ks))
	(matlab-filename "detection_data.mat"))
  ;; (single-run-test-viterbi (first testdirs)
  ;; 			   (first top-ks) world-weight discount-factor)
  ;; (single-run-test-viterbi (second testdirs)
  ;; 			   (second top-ks) world-weight discount-factor)
  ;; (single-run-test-viterbi (third testdirs)
  ;; 			   (third top-ks) world-weight discount-factor)
  ;; (single-run-test-viterbi (fourth testdirs)
  ;; 			   (fourth top-ks) world-weight discount-factor)
  ;; (single-run-test-viterbi (fifth testdirs)
  ;; 			   (fifth top-ks) world-weight discount-factor)
  ;; (single-run-test-viterbi (sixth testdirs)
  ;; 			   (sixth top-ks) world-weight discount-factor)
  (single-run-test-viterbi (first testdirs)
  			   top-k world-weight (first discount-factors))
  ;; (single-run-test-viterbi (second testdirs)
  ;; 			   top-k world-weight (second discount-factors))
  ;; (single-run-test-viterbi (third testdirs)
  ;; 			   top-k world-weight (third discount-factors))
  ;; (single-run-test-viterbi (fourth testdirs)
  ;; 			   top-k world-weight (fourth discount-factors))
  ;; (single-run-test-viterbi (fifth testdirs)
  ;; 			   top-k world-weight (fifth discount-factors))
  ;; (single-run-test-viterbi (sixth testdirs)
  ;; 			   top-k world-weight (sixth discount-factors))
  
  ;;PLOTTING--disable to save time
  ;; (for-each
  ;;  (lambda (testdir)
  ;;   (make-quad-video-and-plots-one-run-viterbi path
  ;; 					       testdir
  ;; 					       matlab-filename)
  ;;   (system (format #f "rsync -arz ~a/~a/ seykhl:~a/~a/"
  ;; 		    path testdir path testdir)))
  ;;  testdirs)
  (dtrace "simple-run-and-plot-viterbi complete" #f)
  (system "date")))

;;;;;;------NEW STUFF for TLD tubes------

(define (read-and-sort-matlab-proposals filename)
 (start-matlab!)
 (matlab (format #f "load ~a" filename))
 (let* ((proposals (transpose (matlab-get-variable "proposal_boxes")))
	(sorted-proposals (map (lambda (frame-boxes)
				(sort (vector->list frame-boxes)
				>
				(lambda (b) (vector-ref b 4))))
			       (vector->list proposals))))
  sorted-proposals))

;; (define *boxes* (read-and-sort-matlab-proposals "/net/seykhl/aux/sbroniko/vader-rover/logs/house-test-12nov15/test-segment/proposal_boxes_edgeboxes_2500.mat"))

(define (get-tld-tube-from-box video-pathname box)
 (let* ((video (ffmpeg-open-video video-pathname))
	(video-width (ffmpeg-video-width video))
	(video-height (ffmpeg-video-height video))
	(boxes (read-from-string
		(system-output
		 (format #f
			 "LD_LIBRARY_PATH=/home/dpbarret/opencv3/lib /home/sbroniko/codetection/source/new-sentence-codetection/run-TLD.out MEDIANFLOW ~a ~a ~a ~a ~a"
			 video-pathname
			 (min (max 1 (x box)) (- video-width 1))
			 (min (max 1 (y box)) (- video-height 1))
			 (min (max 1 (z box)) (- video-width 1))
			 (min (max 1 (vector-ref box 3)) (- video-height 1))
			 )))))
  boxes))

(define (scott-box->voc4 box)
 (let* ((x1 (x box))
       (y1 (y box))
       (x2 (+ x1 (z box)))
       (y2 (+ y1 (vector-ref box 3))))	   
 (make-voc4-detection x1 y1 x2 y2 #f #f #f #f #f #f)))

(define *video-path* "/net/seykhl/aux/sbroniko/vader-rover/logs/house-test-12nov15/test-segment/video_front.avi")


(define (get-frame-numbers num-frames downsample)
 (let loop ((frame-numbers '())
	    (start #t)
	    (i 0))
  (if (or start (< i num-frames))
      (if (zero? (modulo i downsample))
	  (loop (cons i frame-numbers) #f (+ i 1))
	  (loop frame-numbers #f (+ i 1)))
      (reverse frame-numbers))))

(define (generate-proposals video-pathname
			    K  ;;top-k
			    L) ;;interval between frames (every Lth frame)
 (start-matlab!)
 (if (not (integer? L))
     (dtrace "ERROR: L must be an integer" #f)
     (let* ((num-frames (video-length (load-darpa-video video-pathname)))
	    (frames (video->frames L video-pathname))
	    (factor 10) ;;multiplier for proposals so that K will be left after NMS
	    (iou 0.5) ;;HARDCODED intersection-over-union ratio
	    (frame-numbers (get-frame-numbers num-frames L)))
      ;;(dtrace "before frames->matlab!" #f)
      (frames->matlab! frames "frames")
      ;;(dtrace "after frames->matlab!" #f)
      (matlab (format #f "K=~a;" K ))
      (matlab (format #f "factor=~a;" factor))
      ;;(dtrace "after K=" #f)
      (matlab "bbs = get_proposals_edgeboxes(frames,(K*factor));")
      ;;run nms on generated proposals
      (matlab (format #f "iou=~a;" iou))
      (matlab "nmsbbs = nms_iou(bbs,iou,K);")
      (list (length frame-numbers)
	    K
	    frame-numbers
	    (transpose (matlab-get-variable "nmsbbs")))
      )))

(define (frames->matlab! frames matlab-name)
 (let* ((num-frames (length frames))
	(one-frame (first frames))
	(height (imlib:height one-frame))
	(width (imlib:width one-frame)))
  (start-matlab!)
  (matlab (format #f "clear ~a" matlab-name))
  (matlab (format #f "~a = zeros(~a,~a,~a,~a,'uint8');"
		  matlab-name height width 3 num-frames))
  (for-each-indexed
   (lambda (frame i)
    (with-temporary-file
     "/tmp/imlib-frame.ppm"
     (lambda (tmp-frame)
      ;; write scheme frame to file
      (imlib:save-image frame tmp-frame)
      ;; read file as matlab frame
      (matlab (format #f "frame=imread('~a');" tmp-frame))
      (matlab (format #f "~a(:,:,:,~a)=uint8(frame);" matlab-name (+ i 1)))))
    (imlib:free-image-and-decache frame))    
   frames)))

(define (get-medianflow-tube-from-starting-frame-and-proposal-box video-pathname
								  starting-frame
								  box) ;;box is in format #(x,y,w,h)
 (let* ((video (ffmpeg-open-video video-pathname))
	(video-width (ffmpeg-video-width video))
	(video-height (ffmpeg-video-height video))
	;;(foo (dtrace "box" box))
	;;error-checking input here to make sure box stays inside frame
	(x-val (min (max 1 (x box)) (- video-width 1)))
	(y-val (min (max 1 (y box)) (- video-height 1)))
	(w-val (min (z box) (- (- video-width 1) (x box))))
	(h-val (min (vector-ref box 3) (- (- video-height 1) (y box))))
	(boxes (join (read-from-string
		      (system-output
		       (format #f
			 "LD_LIBRARY_PATH=/home/dpbarret/opencv3/lib /home/sbroniko/codetection/source/new-sentence-codetection/run-MF.out ~a ~a ~a ~a ~a ~a"
			 video-pathname
			 starting-frame
			 x-val y-val w-val h-val))))))

  boxes))

;;start-up initialization stuff
(start-matlab!)
;;moved the below calls into ~/Documents/MATLAB/startup.m
;; (matlab "addpath(genpath('/home/sbroniko/codetection/source/new-sentence-codetection/'))")
;; (matlab "InstallEdgeBoxes")

