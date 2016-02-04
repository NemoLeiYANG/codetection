(MODULE TOOLLIB-CODETECTION)

(include "QobiScheme.sch")
(include "toollib-c-macros.sch")
(include "toollib-codetection.sch")
(c-include "codetectionlib-c.h")
(c-include "idealib-c.h")
(c-include "inference.h")

;;(set! *program* "codetection")
;;(set! *panic?* #f)


;;;;UNCOMMENT IF NOT USING IN DSCI
;; ;;;; ffmpeg, imlib, and pnm scheme->c bindings

;; (define-structure imlib-image handle)
;; (c-ffi:add-custom-type imlib-image pointer make-imlib-image imlib-image-handle)

;; (define ffmpeg-open-video
;;  (c-function pointer ("ffmpeg_open_video" string)))

;; (define ffmpeg-video-frame-data-as-imlib
;;  (c-function imlib-image ("ffmpeg_get_frame_as_imlib" pointer)))

;; (define ffmpeg-close-video
;;  (c-function void ("ffmpeg_close_and_free_video" pointer)))

;; (define (ffmpeg-next-frame! video)
;;  (not (= ((c-function int ("ffmpeg_next_frame" pointer)) video) 0)))

;; (define imlib-context-set-image!
;;  (c-function void ("imlib_context_set_image" imlib-image)))

(define (imlib:free-image-and-decache image)
 (imlib-context-set-image! image)
 ((c-function void ("imlib_free_image_and_decache"))))

(define (imlib:save-image image file)
 (imlib-context-set-image! image)
 ((c-function void ("imlib_save_image" pointer)) file))

;; (define (imlib:height image)
;;  (imlib-context-set-image! image)
;;  ((c-function int ("imlib_image_get_height"))))

;; (define (imlib:width image)
;;  (imlib-context-set-image! image)
;;  ((c-function int ("imlib_image_get_width"))))

;; (define (imlib:clone image)
;;  (imlib-context-set-image! image)
;;  ((c-function imlib-image ("imlib_clone_image"))))

;; (define (imlib:data-ptr-read-only image)
;;  (imlib-context-set-image! image)
;;  ((c-function pointer ("imlib_image_get_data_for_reading_only"))))

;; ;;;;;;;;; auxiliary 

;; (define (matrix->list-of-lists m)
;;  (vector->list (map-vector vector->list m)))

;; ;;;;;;;;; timing

;; (define (time-thunk format-string thunk)
;;  (let* ((start (current-time)
;; 	(result (thunk))
;; 	(end (current-time))
;; 	(precision 2)
;; 	(length
;; 	 (if (< (- end start) 1) ;; 0.xx
;; 	     (+ 2 precision)
;; 	     (inexact->exact
;; 	      (floor (+ (+ (/ (log (- end start))
;; 			      (log 10)) 1) 1 precision))))))
;;   (format #t format-string
;; 	  (number->string-of-length-and-precision (- end start) length precision))
;;   result))

;; (define *time-depth* 0)

;; (define (current-time)
;;  (let ((time-file (string-append "/tmp/time-" (number->string (getpid)))))
;;   (system (format #f "date +'%s %N' > ~a" time-file))
;;   (let ((t (first (map fields (read-file time-file)))))
;;    (rm time-file)
;;    (string->number (string-append (first t) "." (second t))))))

;; (define-macro time
;;  (lambda (form expander)
;;   (expander `(time-thunk ,(second form) (lambda () ,(third form))) expander)))

;; (define-macro time-code
;;  (lambda (form expander)
;;   (expander `(time-thunk (format #f "~a~~a : ~a~%"
;; 				 (make-string *time-depth* #\+)
;; 				 ,(format #f "~a" (second form)))
;; 			 (lambda ()
;; 			  (set! *time-depth* (+ *time-depth* 1))
;; 			  (let ((ret ,(second form)))
;; 			   (set! *time-depth* (- *time-depth* 1))
;; 			   ret)))
;; 	    expander)))

;;;;;;;;; compute proposals from matlab functions ;;;;;;;;;;;;

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

(define (proposals&similarity-with-frames top-k box-size frames)
 (let* ((tt (length frames))
	(one-frame (first frames))
	(height (imlib:height one-frame))
	(width (imlib:width one-frame))
	;; (prop-sim-path "/home/sbroniko/codetection/source/sentence-codetection/proposals_and_similarity")
	)
  (start-matlab!)
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
    (imlib:free-image-and-decache frame))    
   frames)
  ;;(matlab (format #f "imshow(frames(:,:,:,20));"))
  ;; call proposals_and_similarity
  (matlab (format #f "[bboxes,simi]=proposals_and_similarity(~a,frames,~a);"
		  top-k box-size))
  ;; convert matlab variables to scheme
  (list (map-n (lambda (t)
		(matlab (format #f "tmp=bboxes(:,:,~a);" (+ t 1)))
		(matlab-get-variable "tmp"))
	       tt)
	(map-n (lambda (t)
		(matlab (format #f "tmp=simi(:,:,~a);" (+ t 1)))
		(matlab-get-variable "tmp"))
	       (- tt 1)))))

(define (proposals&similarity top-k box-size downsample video-path)
 (proposals&similarity-with-frames top-k box-size
				   (video->frames downsample video-path)))

;;;;;;;;;; codetection inference with BP ;;;;;;;;;;

;; (define bp-object-inference
;;  (c-function double ("bp_object_inference" pointer pointer int int pointer)))


(define bp-object-inference ;;DON'T FUCK THIS ONE UP
 (c-function double ("bp_object_inference" pointer pointer int int
		     double double int pointer)))

(define bp-object-inference-new
 (c-function double ("bp_object_inference_new" pointer pointer int int
		     double double int pointer)))

;;--new function for graphical model 29Jan16
(define bp-sentence-codetection-inference
 (c-function double ("bp_sentence_codetection_inference" int int pointer
		     int pointer pointer int pointer pointer pointer)))

;;--new function for simple graphical model 4Feb16
(define bp-sentence-codetection-inference-simple
 (c-function double ("bp_sentence_codetection_inference_simple" int int pointer
		     int pointer pointer pointer)))


;;------these don't work
(define bp-label-inference
 (c-function double ("bp_label_inference" int int
		     double pointer pointer)))

(define bruteforce-label-inference
 (c-function double ("bruteforce_label_inference" int int
		     double pointer pointer)))


(define bp-label-inference-original
 (c-function double ("bp_label_inference_original" int int
		     double double pointer double pointer)))


(define label-inference-test-with-noise
 (c-function double ("label_inference_test_with_noise" int int
		     double pointer pointer int float)))


(define label-inference-with-noise
 (c-function double ("label_inference_with_noise" int int
		     double pointer pointer int double double)))
;;-----------



;;--------------compiling stuff from codetection-test.sc into dsci
;;----Dan's string-rounding function from driver-gui
(define (number->string-with-n-decimal-places f n)
  (let* ((non-decimal-length (string-length (number->string (exact-round f))))
	 (s (number->string
	      (/ (exact-round (* f (expt 10 n)))
		 (expt 10 n))))
	 (s (if (= f 0)
		"0."
		s))
	 (len (string-length s))
	 (s (string-append s (string-join ""
					  (map-n (lambda (i)
						   "0")
						 (- (+ non-decimal-length
						       1
						       n)
						    len))))))
	 (substring
	  s
	  0 
	  (+ non-decimal-length
	     1
	     n))))

;;---Preposition functions from sentence-to-trace-from-learned-models.sc----
(define (fold-polynomial x coeffs)
 (let loop ((s 0) (c (reverse coeffs)))
  (if (null? c)
      s
      (loop (* x (+ s (first c))) (rest c)))))

(define (log-bessel0 kappa)
 (let ((ax (abs kappa)))
  (if (< ax 3.75)
      (log
       (+ 1.0
	  (fold-polynomial (sqr (/ kappa 3.75))
			   '(3.5156229
			     3.0899424
			     1.2067492
			     0.2659732
			     0.360768e-1
			     0.45813e-2))))
      (+ (- ax (* 0.5 (log ax)))
	 (log
	  (+ 0.39894228
	     (fold-polynomial (/ 3.75 ax)
			      '(0.39894228
				0.1328592e-1
				0.225319e-2
				-0.157565e-2
				0.916281e-2
				-0.2057706e-1
				0.2635537e-1
				-0.1647633e-1
				0.392377e-2))))))))

;; (define (log-von-mises v mean kappa)
;;  (unless (and (> kappa 0.0)
;;  	      (and (>= mean (- pi)) (<= mean pi))
;;  	      (and (>= v (- pi)) (<= v pi)))
;;   (format #t "~a ~a ~a~%" v mean kappa)
;;   (panic "log-radial") (abort))
;;  (let ((x (- v mean)))
;;   (- (* kappa (cos x)) (log-bessel0 kappa))))
;;causes conflict with functions in hmm-train-classify.sc


(define (renormalized-von-mises v mean kappa)
;; (let ((x (- v mean)))
;; (/ (exp (* kappa (cos x)))))
(- (log-von-mises v mean kappa)
   (log-von-mises 0 0 kappa)))

(define (center-angle-at angle center)
 (cond ((< angle (- center pi)) (center-angle-at (+ angle two-pi) center))
       ((> angle (+ center pi)) (center-angle-at (- angle two-pi) center))
       (else (- angle center))))

(define (angle-between p1 p2)
 (if (equal? p1 p2)
     0
     (atan (- (y p1) (y p2))
	   (- (x p1) (x p2)))))

(define *von-mises-kappa* 2.5) ;;might need to change this

(define (left-of robot-or-tube tube)
 (let* ((p1 (subvector robot-or-tube 0 2))
	(p2 tube))
  (exp (renormalized-von-mises
	(center-angle-at (angle-between p1 p2) 0)
	pi
	*von-mises-kappa*))))

(define (right-of robot-or-tube tube)
 (let* ((p1 (subvector robot-or-tube 0 2))
	(p2 tube))
  (exp (renormalized-von-mises
	(center-angle-at (angle-between p1 p2) 0)
	0
	*von-mises-kappa*))))

(define (in-front-of robot-or-tube tube)
 (let* ((p1 (subvector robot-or-tube 0 2))
	(p2 tube))
  (exp (renormalized-von-mises
	(center-angle-at (angle-between p1 p2) 0)
	(- half-pi)
	*von-mises-kappa*))))

(define (behind robot-or-tube tube)
 (let* ((p1 (subvector robot-or-tube 0 2))
	(p2 tube))
  (exp (renormalized-von-mises
	(center-angle-at (angle-between p1 p2) 0)
	half-pi
	*von-mises-kappa*))))

(define (between robot-or-tube tube2 tube3)
 (let* ((p1 (subvector robot-or-tube 0 2))
	(p2 tube2)
	(p3 tube3))
  (exp (renormalized-von-mises
	(center-angle-at (- (angle-between p1 p2) (angle-between p1 p3)) 0)
	pi
	*von-mises-kappa*))))

(define (towards robot tube)
 (let* ((p1 (subvector robot 0 2))
	(angle (z robot))
	(p2 tube))
  (exp (renormalized-von-mises (center-angle-at angle 0)
			       (center-angle-at (angle-between p2 p1) 0)
			       *von-mises-kappa*))))

;; this tells if a robot's heading is tangent to the line between
;; the point and the robot
(define (tangent-to robot point)
 ;;(trace-dtrace "v-angle" (primal* (y fv)))
 ;;(trace-dtrace "v-angle target" (primal* (angle-between p2 (x fv))))
 (let* ((p1 (subvector robot 0 2))
	(angle (z robot))
	(p2 point)
	(c1 (exp (renormalized-von-mises (center-angle-at angle 0)
					 (center-angle-at (+ (angle-between p2 p1)
							     half-pi)
							   0)
					 *von-mises-kappa*)))
	(c2 (exp (renormalized-von-mises (center-angle-at angle 0)
					 (center-angle-at (- (angle-between p2 p1)
							     half-pi)
							  0)
					 *von-mises-kappa*))))
  (if (< c1 c2)
      c2
      c1)))

(define (away-from robot tube)
 (let* ((p1 (subvector robot 0 2))
	(angle (z robot))
	(p2 tube))
  (exp (renormalized-von-mises (center-angle-at angle 0)
			       (center-angle-at (+ (angle-between  p2 p1) pi)  0)
			       *von-mises-kappa*))))

;; ?? what is this supposed to do??
(define (angles-opposite-each-other angle1 angle2)
 (- 1 (/ (sqr (center-angle-at (center-angle-at angle1 angle2) pi))
	 ;; (sqr (* 2 pi))
	 (sqr pi))))

(define (distances-equal p1 p2 p3)
 (* (- 1 (/ (sqrt (sqr (- (distance p1 p2) (distance p2 p3)))) (* 100 (distance p2 p3)))) 
    (- 1 (/  (sqrt (sqr (- (distance p1 p2) (distance p1 p3)))) (* 100 (distance p1 p3))))))

(define (near p1 p2)
 (exp (/ (- (distance p1 p2)) 100)))
;;--------------------------End preposition functions


;;--------functions from Haonan's codetectionlib-sc.sc
(define (middle lst)
 (if (null? lst)
     '()
     (list-ref lst (quotient (length lst) 2))))

;; (define (transpose-list-of-lists lol)
;;  (matrix->list-of-lists (transpose (list-of-lists->matrix lol))))
;;already defined in toollib-misc.sc

(define (evenly-pick-m lst m)
 (if (= m 1)
     (list-ref lst (quotient (length lst) 2))
     (map middle (split-into m lst))))
;;--------End Haonan functions

;;----End compiled stuff from codetection-test.sc


;;Compiling labeling.sc stuff into dsci

;;functions for branch and bound

(define (build-table sim num-labels)
 (map-n-vector
  (lambda (i)
   (map-n-vector
    (lambda (j)
     (if (= i j)
	 ;;sigmoid experimenting
	 ;; (- (sigmoid sim 0.8 10))
	 ;; (+ -1 (sigmoid sim 0.8 10))
	 ;;old way
	 (* -1 (log sim))
	 (* -1 (log (- 1 sim)))
	 ))
    num-labels))
   num-labels))

(define (build-table-matrix sim-matrix num-labels)
 (let ((r (matrix-rows sim-matrix))
       (c (matrix-columns sim-matrix)))
  (map-n-vector
   (lambda (i)
    (map-n-vector
     (lambda (j)
      (let* ((sim1 (matrix-ref sim-matrix i j))
	     (sim2 (matrix-ref sim-matrix j i))
	     (sim-value (/ (+ sim1 sim2) 2.0)))
       (list
	;; (min (- (sigmoid sim-value 0.8 10))
	;; 	  (+ -1 (sigmoid sim-value 0.8 10)))
	(min (-(log sim-value))
	     (-(log (- 1 sim-value))))
	     0
	     (build-table sim-value num-labels))))
     c))
   r)))


(define (minimum-vector v)
 (let ((m infinity)
       (len (vector-length v)))
  (let loop
    ((i 0)
     (m m))
   (if (>= i len)
       m
       (loop (+ i 1)
	     (min m (vector-ref v i)))))))

(define (maximum-vector v)
 (let ((m minus-infinity)
       (len (vector-length v)))
  (let loop
    ((i 0)
     (m m))
   (if (>= i len)
       m
       (loop (+ i 1)
	     (max m (vector-ref v i)))))))


(define (best-possible labels table-matrix num-peaks)
 (let ((labels (append labels
		       (map-n (lambda (i) #f) (- num-peaks (length labels))))))
  (reduce +
	 (join 
	  (map-indexed
	   (lambda (label1 i)
	    (map-indexed
	     (lambda (label2 j)
		    (if (< i j) ;;so we're not adding everything twice
			(cond ((and label1 label2)
			       ;;both labels set, so score it
			       (matrix-ref 
				(third (matrix-ref table-matrix i j))
				label1 label2))
			      ((and (not label1) (not label2))
			       ;;neither label set, so get best possible for that pair
			       (first (matrix-ref table-matrix i j))
			       ;; (minimum-vector
			       ;; 	(map-vector
			       ;; 	 (lambda (x)
			       ;; 	  (minimum-vector x))
			       ;; 	 (third (matrix-ref table-matrix i j))))
			       )
			      (else
			       ;;label1 set but label2 not, so get best possible
			       (first (matrix-ref table-matrix i j))
			       ;; (minimum-vector
			       ;; 	(vector-ref
			       ;; 	 (third (matrix-ref table-matrix i j))
			       ;; 	 label1))
			       ))
			      0)) labels)) labels))
	 0)))


(define (best-possible-i labels table-matrix num-peaks)
 (let ((labels (append labels
		       (map-n (lambda (i) #f) (- num-peaks (length labels))))))
  (reduce +
	 (join 
	  (map-indexed
	   (lambda (label1 i)
	    (map-indexed
	     (lambda (label2 j)
		    (if (< i j) ;;so we're not adding everything twice
			(cond ((and label1 label2)
			       0)
			      (else
			       (first (matrix-ref table-matrix i j))
			       ))
			      0)) labels)) labels))
	 0)))

(define (compute-max-score-vec table-matrix num-peaks)
 (map-n-vector (lambda (i)
		(best-possible-i (map-n (lambda (j) 0) i) table-matrix num-peaks))
	       num-peaks))

;; (define (best-possible2 set-labels set-labels-score next-label table-matrix num-peaks)
;;  (let* ((num-set (length set-labels))
;; 	(num-unset (- num-peaks num-set 1))
;; 	(last-label (list-ref set-labels (- num-set 1)))
;; 	)
;;   (+ set-labels-score next-label-score unset-labels-score)))


(define (new-best-possible score labels max-score-vec)
 (+ score (vector-ref max-score-vec (length labels) )))


;; (define (score labels table-matrix)
;;  (reduce +
;; 	 (join 
;; 	  (map-indexed
;; 	   (lambda (label1 i)
;; 	    (map-indexed
;; 	     (lambda (label2 j)
;; 		    (if (< i j) ;;so we're not adding everything twice
;; 			(matrix-ref 
;; 			 (third (matrix-ref table-matrix i j))
;; 			 label1 label2)
;; 			0)) labels)) labels))
;; 	 0))

(define (new-score prev-score labels table-matrix)
 (let* ((new-element-index (- (length labels) 1))
	(new-element (last labels)))
  (let loop ((i 0)
	     (score prev-score)
	     (labels labels)
	     )
   (if (= i new-element-index)
       score
       (loop (+ i 1)
	     (+ score
		(matrix-ref (third (matrix-ref table-matrix i new-element-index))
			    (first labels)
			    new-element))
	     (rest labels))))))
	

(define (score labels table-matrix)
 (let outer-loop ((label1s labels)
		  (i 0)
		  (score 0))
  (if (null? label1s)
      score
      (outer-loop
       (rest label1s)
       (+ i 1)
       (+ score
	  (let inner-loop ((label2s (rest label1s))
			   (j (+ i 1))
			   (inner-score 0))
	   (if (null? label2s)
	       inner-score
	       (inner-loop (rest label2s) (+ j 1) (+ inner-score
						     (matrix-ref 
						      (third (matrix-ref table-matrix i j))
						      (first label1s) (first label2s)))))))))))

 
(define (find-labels best labels table-matrix num-peaks prev-score max-score-vec)
 (let* ((v (length labels))
	(num-labels (vector-length (third (matrix-ref table-matrix 0 0))))
	(max-label-to-consider
	 (if (null? labels)
	     0
	     (min (+ 1 (maximum labels)) (- num-labels 1))))
	(subscore (new-score prev-score labels table-matrix))
	)
  (if (= v num-peaks)
      (list subscore labels) ;;done
      (let* ((scores (map-n (lambda (i)
			     (list i
				   (if (= v (- num-peaks 1))
				       (new-score subscore
						  (append labels (list i))
						  table-matrix)
				       (new-best-possible
					(new-score subscore
						   (append labels
							   (list i))
						   table-matrix)
					(append labels (list i))
					max-score-vec)
				       )
				   )
			     )
			    (+ max-label-to-consider 1)))
	     (sorted-scores (sort scores < second))
	     (bars
	      (let loop ((scored-labels sorted-scores)
			 (best best))
	       (if (null? scored-labels)
		   '()
		   (if (< (second (first scored-labels)) best)
		       (let* ((answer
			       (find-labels best
					    (append labels
						    (list
						     (first (first scored-labels))))
					    table-matrix
					    num-peaks
					    subscore
					    max-score-vec))
			      (new-best
			       (if (< (first answer) best)
	       			   (first answer)
	       			   best)))
			(cons answer
			      (loop (rest scored-labels) new-best)))
		       (begin
			;; (dtrace "PRUNED"
			;; 	(format #f "score ~a best ~a num-labels ~a"
			;; 		(second (first scored-labels))
			;; 		best v))
			;; (dtrace "labels" (append labels (list (first (first scored-labels)))))
			(loop (rest scored-labels) best))))
	       )))
       (if (null? bars)
	   (list infinity '())
	   (first (sort bars < first)))))))



;;This change actually slowed things down, no clue why--should have sped things up 23Jul15.

;; (define (find-labels best labels table-matrix num-peaks prev-score max-score-vec)
;;  (let* ((v (length labels))
;; 	(num-labels (vector-length (third (matrix-ref table-matrix 0 0))))
;; 	(max-label-to-consider
;; 	 (if (null? labels)
;; 	     0
;; 	     (min (+ 1 (maximum labels)) (- num-labels 1))))
;; 	(subscore prev-score);;(new-score prev-score labels table-matrix))
;; 	)
;;   (if (= v num-peaks)
;;       (list subscore labels) ;;done
;;       (let* ((scores (map-n (lambda (i)
;; 			     ;;(list i
;; 			     (let* ((new-score-val
;; 				     (new-score subscore
;; 						(append labels (list i))
;; 						table-matrix)))
;; 			      (vector i
;; 				      (if (= v (- num-peaks 1))
;; 					  new-score-val
;; 					  ;; (new-score subscore
;; 					  ;; 	   (append labels (list i))
;; 					  ;; 	   table-matrix)
;; 					  (new-best-possible
;; 					   new-score-val
;; 					   ;; (new-score subscore
;; 					   ;; 	    (append labels
;; 					   ;; 		    (list i))
;; 					   ;; 	    table-matrix)
;; 					   (append labels (list i))
;; 					 max-score-vec)
;; 					  ;; (let* ((fooA (new-best-possible
;; 					  ;; 		     (new-score subscore
;; 				       ;; 				(append labels
;; 					  ;; 					(list i))
;; 					  ;; 				table-matrix)
;; 					  ;; 		     (append labels (list i))
;; 					  ;; 		     max-score-vec))
;; 					  ;; 	      (fooB (best-possible
;; 					  ;; 		     (append labels (list i))
;; 					  ;; 		     table-matrix
;; 					  ;; 		     num-peaks)))
;; 					  ;; 	(if (> (dtrace "abs" (abs (- fooA fooB))) 0.001)
;; 					  ;; 	    (begin
;; 					  ;; 	     (dtrace "fooA" fooA)
;; 					  ;; 	     (dtrace "fooB" fooB)
;; 					  ;; 	     (dtrace "subscore" subscore)
;; 					  ;; 	     (dtrace "labels" labels)
;; 					  ;; 	     (dtrace "i" i)
;; 					  ;; 	     (fuck-up))
;; 					  ;; 	    fooA))
;; 					  )
;; 				      new-score-val)
;; 			      ))
;; 			    (+ max-label-to-consider 1)))
;; 	     (sorted-scores (sort scores < y));;second))
;; 	     (bars
;; 	      (let loop ((scored-labels sorted-scores)
;; 			 (best best))
;; 	       (if (null? scored-labels)
;; 		   '()
;; 		   (if (< (y (first scored-labels)) best)
;; 		       (let* ((answer
;; 			       (find-labels best
;; 					    (append labels
;; 						    (list
;; 						     (x (first scored-labels))))
;; 					    table-matrix
;; 					    num-peaks
;; 					    (z (first scored-labels));;subscore
;; 					    max-score-vec))
;; 			      (new-best
;; 			       (if (< (first answer) best)
;; 	       			   (first answer)
;; 	       			   best)))
;; 			(cons answer
;; 			      (loop (rest scored-labels) new-best)))
;; 		       (begin
;; 			;; (dtrace "PRUNED"
;; 			;; 	(format #f "score ~a best ~a num-labels ~a"
;; 			;; 		(second (first scored-labels))
;; 			;; 		best v))
;; 			;; (dtrace "labels" (append labels (list (first (first scored-labels)))))
;; 			(loop (rest scored-labels) best))))
;; 	       )))
;;        (if (null? bars)
;; 	   (list infinity '())
;; 	   (first (sort bars < first)))))))



;; (define (find-labels best labels table-matrix num-peaks)
;;  (let* ((v (length labels))
;; 	(num-labels (vector-length (third (matrix-ref table-matrix 0 0))))
;; 	(max-label-to-consider
;; 	 (if (null? labels)
;; 	     0
;; 	     (min (+ 1 (maximum labels)) (- num-labels 1))))
;; 	)
;;   (if (= v num-peaks)
;;       (list (score labels table-matrix) labels) ;;done
;;       (let* ((scores (map-n (lambda (i)
;; 			     (list i (best-possible
;; 				      (append labels (list i))
;; 				      table-matrix
;; 				      num-peaks)))
;; 			    (+ max-label-to-consider 1)))
;; 	     (sorted-scores (sort scores < second))
;; 	     (bars
;; 	      (let loop ((scored-labels sorted-scores)
;; 			 (best best))
;; 	       (if (null? scored-labels)
;; 		   '()
;; 		   (if (< (second (first scored-labels)) best)
;; 		       (let* ((answer
;; 			       (find-labels best
;; 					    (append labels
;; 						    (list
;; 						     (first (first scored-labels))))
;; 					    table-matrix
;; 					    num-peaks))
;; 			      (new-best
;; 			       (if (< (first answer) best)
;; 	       			   (first answer)
;; 	       			   best)))
;; 			(cons answer
;; 			      (loop (rest scored-labels) new-best)))
;; 		       (begin
;; 			;; (dtrace "PRUNED"
;; 			;; 	(format #f "score ~a best ~a num-labels ~a"
;; 			;; 		(second (first scored-labels))
;; 			;; 		best v))
;; 			;; (dtrace "labels" (append labels (list (first (first scored-labels)))))
;; 			(loop (rest scored-labels) best))))
;; 	       )))
;;        (if (null? bars)
;; 	   (list infinity '())
;; 	   (first (sort bars < first)))))))






;;;;;NEED TO REBUILD THIS AS A STAND-ALONE PROCEDURE
;; (define-command
;;  (main (at-most-one
;; 	("video" video? (video-path "video-path" string-argument "")))
;;        (at-most-one
;; 	("top-k" top-k? (top-k "top-k" integer-argument 100)))
;;        (at-most-one
;; 	("downsample" downsample? (downsample "rate" integer-argument 1)))
;;        (at-most-one
;; 	("box-size" box-size? (box-size "size" integer-argument 64))))
;;  (let* ((proposals-similarity (proposals&similarity top-k box-size downsample video-path))
;; 	(proposals (map (lambda (boxes) (map (lambda (x) (but-last x))
;; 					     (matrix->list-of-lists boxes)))
;; 			(first proposals-similarity)))
;; 	(f (map (lambda (boxes) (map fifth (matrix->list-of-lists boxes)))
;; 		(first proposals-similarity)))
;; 	(g (map (lambda (sim) (matrix->list-of-lists sim))
;; 		(second proposals-similarity)))
;; 	(f-c (easy-ffi:double-to-c 2 f))
;; 	(g-c (easy-ffi:double-to-c 3 g))
;; 	(boxes-c (list->c-exact-array (malloc (* c-sizeof-int (length f)))
;; 				      (map-n (lambda _ 0) (length f))
;; 				      c-sizeof-int #t))	
;; 	(score (bp-object-inference f-c g-c (length f) top-k boxes-c))
;; 	(boxes (c-exact-array->list boxes-c c-sizeof-int (length f) #t)))
;;   (free boxes-c)
;;   (easy-ffi:free 2 f f-c)
;;   (easy-ffi:free 3 g g-c)
;;   (pp (map (lambda (b pool) (list b (list-ref pool b)))
;; 	   boxes proposals))))
       
