(load "/home/sbroniko/darpa-collaboration/ideas/toollib-multi-process.sc")
;; made edits to this file in rsync-directory-to-server in order to NOT exclude image files
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
 (let* (;;(frames (video->frames 1 (format #f "~a/video_front.avi" datapath)))
	(cam-timing (read-camera-timing
		     (format #f "~a/camera_front.txt" datapath)))
	(timing-file (if (file-exists? (format #f "~a/imu-log-with-estimates.txt"
					       datapath))
			 (format #f "~a/imu-log-with-estimates.txt" datapath)
			 (format #f "~a/imu-log.txt" datapath)))
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
  (matlab "addpath(genpath('/home/sbroniko/codetection/source/sentence-codetection/'))")
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
	(score (bp-object-inference f-c g-c (length f)
				    top-k dummy-f dummy-g num-g boxes-c))
	(boxes (c-exact-array->list boxes-c c-sizeof-int (length f) #t)))
  ;;  (dtrace "before (free boxes-c)" #f)
  (free boxes-c)
  ;;  (dtrace "before (easy-ffi:free 2 f f-c)" #f)
  (easy-ffi:free 2 f f-c)
  ;;  (dtrace "before (easy-ffi:free 2 g g-c)" #f)
  (easy-ffi:free 2 g g-c);;

  ;;output
  (list boxes
	(map (lambda
	       (b prop-xy) (list-ref prop-xy b))
	     boxes
	     (map (lambda (prop-xy) (append prop-xy '(())))
		  proposals-xy))
	(map (lambda
	       (b prop-boxes) (list-ref prop-boxes b))
	     boxes
	     (map (lambda (prop-boxes) (append prop-boxes '(())))
		  proposals-boxes))
	     )

  ;;(list boxes) ;;just box indices
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
 (let* ((data (read-object-from-file (format #f "~a/frame-data-new2.sc" path)))
	(img-path (format #f "~a/images-~a-~a-new2" path
			  (number->padded-string-of-length dummy-f 3)
			  (number->padded-string-of-length dummy-g 3)))
	(results (run-codetection-with-proposals-similarity data
							    dummy-f
							    dummy-g))
	(boxes (third results))
	(video-path (format #f "~a/video_front.avi" path))
	(frames (video->frames 1 video-path))
	)
  (write-object-to-file results (format #f "~a/results-~a-~a-new2.sc" path
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

(define (get-matlab-data-training-or-generation
	 path top-k ssize alpha beta gamma delta)
 (let* ((log-to-track "/home/sbroniko/vader-rover/position/log-to-track.out"))
  (unless ;;comment out this unless if doing autodrive
    (file-exists? (format #f "~a/imu-log-with-estimates.txt" path))
   (system (format #f "~a none ~a/imu-log.txt ~a/imu-log-with-estimates.txt ~a/imu-log-with-estimates.sc" log-to-track path path path)))
  (write-object-to-file
   (get-matlab-proposals-similarity-full-video
    top-k ssize (format #f "~a" path) alpha beta gamma delta)
   (format #f "~a/frame-data-new2.sc" path)) ;;NEW HERE TO PREVENT OVERWRITE
  (dtrace (format #f "wrote ~a/frame-data-new2.sc" path) #f)))

(define (get-matlab-data-auto-drive path top-k ssize alpha beta gamma delta)
 (begin
  (write-object-to-file
   (get-matlab-proposals-similarity-full-video
    top-k ssize (format #f "~a" path) alpha beta gamma delta)
   (format #f "~a/frame-data-new.sc" path)) ;;NEW HERE TO PREVENT OVERWRITE
  (dtrace (format #f "wrote ~a/frame-data-new.sc" path) #f)))

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
 (let* ((servers (list "chino" "maniishaa" "alykkyys" "seulki" "faisneis" "buddhi" "rongovosai" "cuddwybodaeth" "istihbarat"));;)) ;;*2g-servers*)  "zhineng" "wywiad" "jalitusteabe"
	(source "seykhl");;"jalitusteabe")
	(matlab-cpus-per-job 1);; 7) ;;if using parfor
	(c-cpus-per-job 1)
	(output-matlab (format #f "~a-matlab/" output-directory))
	(output-c (format #f "~a-c/" output-directory))
	(plandirs (system-output (format #f "ls ~a | grep plan" data-directory)))
	(dir-list (join
		   (map
		    (lambda (p)
		     (map (lambda (d) (format #f "~a/~a/~a" data-directory p d))
			  (system-output (format #f "ls ~a/~a" data-directory p))))
		    plandirs)))
	(commands-matlab (map
			  (lambda (dir) ;;change get-matlab... command if using auto-drive
			   (format #f "(load \"/home/sbroniko/codetection/source/sentence-codetection/codetection-test.sc\") (get-matlab-data-training-or-generation \"~a\" ~a ~a ~a ~a ~a ~a) :n :n :n :n :b" dir top-k ssize alpha beta gamma delta)) dir-list))
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
  (dtrace "processing complete" #f)
  (system "date")))


(define (join-images basedir subdir1 subdir2)
 (let* ((images (system-output (format #f "ls ~a/~a" basedir subdir1)))
	(joindir (format #f "~a/joined2" basedir)))
  (mkdir-p joindir)
  (for-each (lambda (img)
	     (system (format #f "montage -tile 2x1 -geometry +0+0 \"~a\"/\"~a\"/\"~a\" \"~a\"/\"~a\"/\"~a\" \"~a\"/\"~a\""
			     basedir subdir1 img basedir subdir2 img joindir img)))
	    images)
  (dtrace (format #f "wrote images in ~a" joindir) #f)))

(define (join-all-images datasetdir subdir1 subdir2)
 (let* ((plandirs (system-output (format #f "ls ~a | grep plan" datasetdir)))
	(dir-list (join
		   (map
		    (lambda (p)
		     (map (lambda (d) (format #f "~a/~a/~a" datasetdir p d))
			  (system-output (format #f "ls ~a/~a" datasetdir p))))
		    plandirs))))
  (for-each (lambda (dir) (join-images dir subdir1 subdir2)) dir-list)
  (dtrace "join-all-images complete" #f)))
;;;;----temporary testing-data stuff-------
;;;COMMENT OUT THE FOUR LINES BELOW UNLESS TRYING TO RE-ADD THE DATA
;; (define test-data-small #f) (define test-data-medium #f) (define test-data-large #f) (define test-data-full #f)

(define (load-data)
 (dtrace "starting load-data" #f)
 (system "date")
 (set! test-data-small (get-matlab-proposals-similarity-by-frame 10 64 "/home/sbroniko/codetection/testing-data" 17 20 1 1 1 0))
 (dtrace "loaded test-data-small" #f)
 (system "date")
 (set! test-data-medium (get-matlab-proposals-similarity-by-frame 10 64 "/home/sbroniko/codetection/testing-data" 17 46 1 1 1 0))
 (dtrace "loaded test-data-medium" #f)
 (system "date")
 (set! test-data-large (get-matlab-proposals-similarity-by-frame 10 64 "/home/sbroniko/codetection/testing-data" 17 116 1 1 1 0))
 (dtrace "loaded test-data-large" #f)
 (system "date")
 (set! test-data-full (get-matlab-proposals-similarity-full-video 10 64 "/home/sbroniko/codetection/testing-data" 1 1 1 0))
 (dtrace "loaded test-data-full, load complete" #f)
 (system "date"))


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

