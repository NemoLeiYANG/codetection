;;(load "/home/dpbarret/darpa-collaboration/rover/generate-msee1-dataset.sc")
(load "/home/dpbarret/imitate/tool/toollib-perspective-projection.sc")

;;; some basic vector and transformation stuff from imitate/tool/toollib-misc.sc


(define (linspace min max n)
 (let ((numbers (enumerate n))
       (range (- max min)))
  (map (lambda (number)
	(+ (* (/ number (- n 1))
	      range)
	   min))
       numbers)))

(define (v/s v s)
 (map-vector
  (lambda (e)
    (/ e s))
  v))

(define (vectors->angle v1 v2)
 (acos (/ (dot v1 v2) (magnitude v1) (magnitude v2))))


(define (my-rotation-3d-x a)    ;; roll
 `#(#(1 0            0            0)
    #(0 ,(cos a)     ,(- (sin a))     0)
    #(0 ,(sin a)     ,(cos a)     0)
    #(0 0            0            1)))

(define (my-rotation-3d-y a)    ;; pitch
 `#(#(,(cos a)       0 ,(sin a) 0)
    #(0              1 0        0)
    #(,(- 0 (sin a)) 0 ,(cos a) 0)
    #(0              0 0        1)))

(define (my-rotation-3d-z a)    ;; yaw
 `#(#(,(cos a) ,(- (sin a)) 0 0)
    #(,(sin a) ,(cos a)     0 0)
    #(0            0        1 0)
    #(0            0        0 1)))

(define (my-make-transform-3d theta phi psi x y z)
(m* (translation-3d x y z)
     (m* (m* (my-rotation-3d-z theta)
	     (my-rotation-3d-y phi))
	 (my-rotation-3d-x psi))))

;;copied from ~/imitate/tool/toollib-misc.sc
(define (my-transform->parameters txf)
 (if (not (or (equal? (matrix-ref txf 2 0) 1)
	      (equal? (matrix-ref txf 2 0) -1)))
     (let* ((theta1 (- (asin (matrix-ref txf 2 0))))
	    (theta2 (- pi theta1))
	    (psi1 (atan (/ (matrix-ref txf 2 1)
			   (cos theta1))
			(/ (matrix-ref txf 2 2)
			   (cos theta1))))
	    (psi2 (atan (/ (matrix-ref txf 2 1)
			   (cos theta2))
			(/ (matrix-ref txf 2 2)
			   (cos theta2))))
	    (phi1 (atan (/ (matrix-ref txf 1 0)
			   (cos theta1))
			(/ (matrix-ref txf 0 0)
			   (cos theta1))))
	    (phi2 (atan (/ (matrix-ref txf 1 0)
			   (cos theta2))
			(/ (matrix-ref txf 0 0)
			   (cos theta2)))))
      (vector  phi1
	       theta1
	       psi1
	       (matrix-ref txf 0 3)
	       (matrix-ref txf 1 3)
	       (matrix-ref txf 2 3)))
     ;;(list  phi2
     ;;	   theta2
     ;;   psi2
     ;; (matrix-ref txf 0 3)
     ;; (matrix-ref txf 1 3)
     ;; (matrix-ref txf 2 3))))
     (let* ((phi 0)
	    (theta (if (equal? (matrix-ref txf 2 0) -1)
		       (- (/ pi 2))
		       (/ pi 2)))
	    (psi (if (equal? (matrix-ref txf 2 0) -1)
		     (+ phi (atan (matrix-ref txf 0 1)
				  (matrix-ref txf 0 2)))
		     (+ (- phi) (atan (- (matrix-ref txf 0 1))
				      (- (matrix-ref txf 0 2)))))))
      (vector phi
	      theta
	      psi
	      (matrix-ref txf 0 3)
	      (matrix-ref txf 1 3)
	      (matrix-ref txf 2 3)))))

(define (invert-tx-matrix txf)
 (let* ((transposed-r (transpose (submatrix txf 0 0 3 3)))
	(t (map-vector (lambda (r) (vector-ref r 3)) (subvector txf 0 3)))
	(new-t (k*v -1 (m*v transposed-r t))))
  (vector-append
   (map-vector
    (lambda (r t) (vector-append r (vector t)))
    transposed-r new-t)
   '#(#(0 0 0 1)))))

(define (point->homogenous p) (list->vector (append (vector->list p) `(,1))))
(define (homogenous->point p) (subvector p 0 3))

(define (transform-point-3d m p)
 (homogenous->point (m*v m (point->homogenous p))))



;;; this is probably the thing you want to use
(define (pixel-and-height->world p camera->world intrinsics height)
 (let* ((camera-world (transform-point-3d camera->world (vector 0 0 0)))
	(fx  (matrix-ref intrinsics 0 0))
	(fy  (matrix-ref intrinsics 1 1))
	(px  (/ (- (x p) (matrix-ref intrinsics 0 2)) fx))
	(py  (/ (- (y p) (matrix-ref intrinsics 1 2)) fy))
	(pixel-world  (transform-point-3d camera->world (vector px py 1)))
	(dxyz (v- pixel-world camera-world))
	(l (/ (- height (z camera-world)) (z dxyz))))
  (v+ camera-world (k*v l dxyz))));;(v*s dxyz l))))

(define (read-robot-estimated-pose-from-log-file filename)
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
			     (string->number (fifth split-line))
			     (string->number (seventh split-line)))))
		   valid)))
  (reverse
   (let loop ((lines lines)
	      (timed-poses '())
	      (last-time1 #f)
	      (last-time2 #f)
	      (last-time3 #f))
    (if (null? lines)
	timed-poses
	(if (equal? (first lines) "")
	    (loop (rest lines)
		  timed-poses
		  last-time1
		  last-time2
		  last-time3)
	    (let* ((begining (first (pregexp-split ":" (first lines))))
		   (time (string->number begining))
		   (estimate? (equal? begining "ESTIMATE")))
	     (if time
		 (loop (rest lines)
		       timed-poses
		       time
		       last-time1
		       last-time2)
		 (if estimate?
		     (let* ((split-line (pregexp-split ":" (first lines))))
		      (loop (rest lines)
			    (cons (list last-time1 (vector (string->number (third split-line))
							   (string->number (fifth split-line))
							   (string->number (seventh split-line))))
				  timed-poses)
			    last-time1
			    last-time2
			    last-time3))
		     (loop (rest lines)
			   timed-poses
			   last-time1
			   last-time2
			   last-time3))))))))))

(define (interpolate-line p1 p2 number)
 (let* ((xs (linspace (x p1) (x p2) number))
	(ys (linspace (y p1) (y p2) number))
	(zs (linspace (z p1) (z p2) number)))
  (map (lambda (x y z) (vector x y z)) xs ys zs)))

(define (draw-3d-lines-projection-nice image
				       points
				       world->camera-txf
				       intrinsics
				       color)
 (let loop ((points points))
  (if (< (length points) 2)
      '()
      (begin
       (let subloop ((subpoints (interpolate-line (first points) (second points) 100)))
	(if (< (length subpoints) 2)
	    '()
	    (begin
	     
	     (when (and (> (z (transform-point-3d world->camera-txf (first subpoints)))
			   0)
			(> (z (transform-point-3d world->camera-txf (second subpoints)))
			   0))
	      (draw-point-projection image
				     world->camera-txf
				     intrinsics
				     (first subpoints)
				     'circle
				     10
				     (vector 0  0 255))
	      (draw-line-projection
	       image (first subpoints) (second subpoints)
	       world->camera-txf intrinsics color))
	     (subloop (rest subpoints)))))
       (when (> (z (transform-point-3d world->camera-txf (first points)))
		0)
	(draw-text-projection image
			      world->camera-txf
			      intrinsics
			      (first points)
			      12
			      (vector 255 255 255)
			      (format #f "(~a, ~a, ~a)"
				      (x (first points))
				      (y (first points))
				      (z (first points)))))
       (loop (rest points))))))


;; (define (robot-pose-to-world->camera-txf robot-pose camera-offset)
;;  (m*
;;   (translation-3d-30 160 -200)
;;   (invert-tx-matrix
;; 		(my-make-transform-3d (- (z robot-pose) half-pi)
;; 				      0
;; 				      (- half-pi)
;; 				      (* (x robot-pose) 1000)
;; 				      (* (y robot-pose) 1000)
;; 				      0
;; 				      ))))

(define (robot-pose-to-camera->world-txf robot-pose camera-offset-matrix)
 (invert-tx-matrix
  (m*
   camera-offset-matrix
   (invert-tx-matrix
    (my-make-transform-3d (- (z robot-pose) half-pi)
			  0
			  (- half-pi)
			  (x robot-pose);;(* (x robot-pose) 1000)
			  (y robot-pose);;(* (y robot-pose) 1000)
			  0
			  )))))

(define (x-y-theta->6dof pose)
 (vector (x pose) (y pose) 0. (z pose) 0. 0.))

(define (six-dof->x-y-theta pose)
 (vector (x pose) (y pose) (vector-ref pose 3)))

;; (define (world-6dof->robot-6dof pose)
;;  (let* ((old-pose (subvector pose 0 3))
;; 	(theta (vector-ref pose 3)))
;;   (vector-append (transform-point-3d
;; 		  (my-make-transform-3d (- half-pi) 0 0 0 0 0)
;; 		  old-pose)
;; 		 (vector (- theta half-pi) 0. 0.))))

;; (define (robot-6dof->world-6dof pose)
;;  (let* ((old-pose (subvector pose 0 3))
;; 	(theta (vector-ref pose 3)))
;;   (vector-append (transform-point-3d
;; 		  (my-make-transform-3d (+ half-pi) 0 0 0 0 0)
;; 		  old-pose)
;; 		 (vector (+ theta half-pi) 0. 0.))))
;;the above could be wrong

(define (robot-6dof->world-6dof pose)
 #f)

(define (world-6dof->robot-6dof pose)
 #f)


;;FIXME
;; (define (world-delta->robot-delta world-delta world-pose)
;;  (let* ((theta (vector-ref world-pose 3))
;; 	(delta-xyz (subvector world-delta 0 3))
;; 	(delta-angles (subvector world-delta 3 6)))
;;   (vector-append

(define (robot-pose-6dof-to-camera->world-txf robot-pose-6dof camera-offset-matrix)
 ;;robot-pose-6dof is (x,y,z,theta,phi,psi) -- my-make-transform-3d puts angles first
 (let* ((xval (x robot-pose-6dof))
	(yval (y robot-pose-6dof))
	(zval (z robot-pose-6dof))
	(theta (vector-ref robot-pose-6dof 3))
	(phi (vector-ref robot-pose-6dof 4))
	(psi (vector-ref robot-pose-6dof 5)))
 (invert-tx-matrix
  (m*
   camera-offset-matrix
   (invert-tx-matrix
    (my-make-transform-3d (- theta half-pi)
			  phi
			  (- psi half-pi)
			  xval yval zval))))))


(define (read-camera-timing path)
 (let* ((lines (read-file path))
       (data-lines (sublist lines 2 (- (length lines) 3))))
  (map (lambda (l) (string->number (first (pregexp-split ":" l)))) data-lines)))

(define (test)
 (let* ((run-path "/net/mohio/aux/dpbarret/rover-logs/MSEE1-dataset/auto-drive/plan0/2014-11-21-00:38:47")
	(video-path (format #f "~a/video_front.avi" run-path))
	(video (ffmpeg-open-video video-path))
	(video-timing-path (format #f "~a/camera_front.txt" run-path))
	(video-times (read-camera-timing video-timing-path))
	(timed-estimated-poses (read-robot-estimated-pose-from-log-file
			  (format #f "~a/imu-log.txt" run-path)))
	(camera-offset (vector 30 160 200))
	(intrinsics (vector
		     (vector 715.6 0. 311.4)
		     (vector 0. 715.6 187.3)
		     (vector 0. 0. 1.)))
	(floor-points (list 
			    (vector -3000 3930 0)
			    (vector 3050 3930 0)
			    (vector 3050 -2620 0)
			    (vector -3000 -2620 0)
			    (vector -3000 3930 0)
			    (vector -3000 -2620 0)
			    (vector 0 -2620 0)
			    (vector 0 3930 0)
			    (vector 0 0 0)
			    (vector -3000 0 0)
			    (vector 3050 0 0))))

  (ffmpeg-next-frame! video)
  (let loop ((image (ffmpeg-video-frame-data-as-imlib video))
	     (timed-poses timed-estimated-poses)
	     (video-times video-times)
	     (previous-timed-pose #f)
	     (frame-number 0)
	     (initial? #t))
   (if (or (dtrace "poses null" (null? timed-poses))
	   (dtrace "video-times-null" (null? video-times)))
	   
       (dtrace "done" #f)
       (if (dtrace "less" (and initial?
			       (< (first video-times)
			     (first (first timed-poses)))))
	   (begin
	    (ffmpeg-next-frame! video)
	    (loop (ffmpeg-video-frame-data-as-imlib video)
		  timed-poses
		  (rest video-times)
		  #f
		  (+ frame-number 1)
		  #t))
	   (if previous-timed-pose
	       (if (< (abs (- (first previous-timed-pose)
			      (first video-times)))
		      (abs (- (first (first timed-poses))
			      (first video-times))))
		   (begin
		    (dtrace "camera and pose times"
			    (list (first video-times)
				  (first previous-timed-pose)))
		   (let* ((pose (second previous-timed-pose)))
		    (dtrace "pose:" pose)
		    (let ((txf (robot-pose-to-world->camera-txf pose camera-offset)))
		     (dtrace "0 0 0 -> camera"
			     (transform-point-3d txf (vector 0 0 0)))
		     (for-each
		      (lambda (p)
		       (when (< 100 (z (transform-point-3d txf p)))
			(draw-cylinder-projection image
						  100
						  100
						  p
						  0
						  0
						  0
						  txf
						  intrinsics
						  (vector 0 255 0)
						  100)))
		      floor-points)
		     (draw-3d-lines-projection-nice image
						    floor-points
						    (dtrace "txf:" txf)
						    intrinsics
						    (vector 255 0 0))
		     (dtrace "????" #f)
		     (imlib:save image (format #f "/tmp/rover-images-~a.png"
					   (number->padded-string-of-length frame-number 5)))    
		     (ffmpeg-next-frame! video)
		     (loop (ffmpeg-video-frame-data-as-imlib video)
			   (rest timed-poses)
			   (rest video-times)
			   (first timed-poses)
			   (+ frame-number 1)
			   #f))))
		   (loop image 
			 (rest timed-poses)
			 video-times
			 (first timed-poses)
			 (+ frame-number 0)
			 #f))
	       (loop image 
		     (rest timed-poses)
		     video-times
		     (first timed-poses)
		     (+ frame-number 0)
		     #f)))))))

       