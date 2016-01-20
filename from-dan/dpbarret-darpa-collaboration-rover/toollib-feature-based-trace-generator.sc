;;(load (format #f "/home/~a/darpa-collaboration/rover/toollib-analysis.sc" (getenv "USER")))

(load (format #f "/home/~a/imitate/tool/toollib-ad.sc" (getenv "USER")))
(load "/home/dpbarret/darpa-collaboration/rover/haonan-generator.sc")
(load (format #f "/home/~a/darpa-collaboration/pose-retraining/felz-baum-welch-plotting.sc" (getenv "USER")))

(define *directions* '("left of" "in front of" "right of" "behind"))

(define *loud-trace-generator?* #f)

(define (trace-dtrace s x)
 (if *loud-trace-generator?*
     (dtrace s x)
     x))


(define *vonmises-kappa* 3)
(define *distance-sigma* 0.1)
(define *velocity-sigma* 0.03)
(define *vonmises-eps* 1e-20)

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

(define (log-von-mises v mean kappa)
 (unless (and (> kappa 0.0)
 	      (and (>= mean (- pi)) (<= mean pi))
 	      (and (>= v (- pi)) (<= v pi)))
  (format #t "~a ~a ~a~%" v mean kappa)
  (panic "log-radial") (abort))
 (let ((x (- v mean)))
  (- (* kappa (cos x)) (log-bessel0 kappa))))

(define (parse-tree-steps parse-tree)
 1)

(define (center-angle-at angle center)
 (cond ((< angle (- center pi)) (center-angle-at (+ angle two-pi) center))
       ((> angle (+ center pi)) (center-angle-at (- angle two-pi) center))
       (else (- angle center))))

(define (angle-between p1 p2)
 (if (equal? p1 p2)
     0
     (atan (- (y p1) (y p2))
	   (- (x p1) (x p2)))))

(define (left-of p1 p2)
 (- 1 (/ (sqr (center-angle-at (angle-between p1 p2) pi))
	 (* (sqr pi) 2))))

(define (right-of p1 p2)
 (- 1 (/ (sqr (center-angle-at (angle-between p1 p2) 0))
	 (* (sqr pi) 2))))

(define (in-front-of p1 p2)
 (- 1 (/ (sqr (center-angle-at (angle-between p1 p2) (- (/ pi 2))))
	 (* (sqr pi) 2))))

(define (behind p1 p2)
 (- 1 (/ (sqr (center-angle-at (angle-between p1 p2) (/ pi 2)))
	 (* (sqr pi) 2))))

(define (between p1 p2 p3)
 (- 1 (/ (sqr (center-angle-at (- (angle-between p1 p2) (angle-between p1 p3)) pi))
	 (* (sqr pi) 2))))

(define (towards angle p1 p2)
 ;;(trace-dtrace "v-angle" (primal* (y fv)))
 ;;(trace-dtrace "v-angle target" (primal* (angle-between p2 (x fv))))
 (- 1  (/ (sqr (center-angle-at angle (angle-between p2 p1)))
	  (sqr two-pi))))


(define (parallel-to angle p1 p2)
 ;;(trace-dtrace "v-angle" (primal* (y fv)))
 ;;(trace-dtrace "v-angle target" (primal* (angle-between p2 (x fv))))
 (let ((c1 (- 1  (/ (sqr (center-angle-at angle (+ (angle-between p2 p1) (/ pi 2))))
	       (sqr two-pi))))
      (c2 (- 1  (/ (sqr (center-angle-at angle (- (angle-between p2 p1) (/ pi 2))))
	       (sqr two-pi)))))
  (if (< c1 c2)
      c2
      c1)))

(define (away-from angle p1 p2)
(- 1 (/ (sqr (center-angle-at angle (+ (angle-between  p2 p1) pi)))
   (sqr two-pi))))

(define (angles-opposite-each-other angle1 angle2)
 (- 1 (/ (sqr (center-angle-at (center-angle-at angle1 angle2) pi))
	 (sqr (* 2 pi)))))

(define (distances-equal p1 p2 p3)
 (* (- 1 (/ (sqrt (sqr (- (distance p1 p2) (distance p2 p3)))) (* 100 (distance p2 p3)))) 
    (- 1 (/  (sqrt (sqr (- (distance p1 p2) (distance p1 p3)))) (* 100 (distance p1 p3))))))

(define (near p1 p2)
 (exp (/ (- (distance p1 p2)) 100)))

(define (trace-left-of fvs i p2)
 (* (left-of (x (vector-ref fvs i)) p2)
    (near (x (vector-ref fvs i)) p2)))

(define (trace-right-of fvs i p2)
 (* (right-of (x (vector-ref fvs i)) p2)
    (near (x (vector-ref fvs i)) p2)))

(define (trace-in-front-of fvs i p2)
 (* (in-front-of (x (vector-ref fvs i)) p2)
    (near (x (vector-ref fvs i)) p2)))

(define (trace-behind fvs i p2)
 (* (behind (x (vector-ref fvs i)) p2)
    (near (x (vector-ref fvs i)) p2)))

(define (trace-between fvs i p2 p3)
(between (x (vector-ref fvs i)) p2 p3))

(define (trace-towards fvs i p2)
 (* (towards (y (vector-ref fvs i)) (x (vector-ref fvs (if (= i 0)
							0
							(- i 1)))) p2)
    (towards (y (vector-ref fvs i)) (x (vector-ref fvs (if (= i 0)
							0
							(- i 0)))) p2)))

(define (trace-away-from fvs i p2)
 (* (away-from (y (vector-ref fvs i)) (x (vector-ref fvs (if (= i 0)
							0
							(- i 1)))) p2)
    (away-from (y (vector-ref fvs i)) (x (vector-ref fvs (if (= i 0)
							0
							(- i 0)))) p2)))

(define (trace-keep-straight fvs i)
 (let* ((direction-energy (+ (sqr (center-angle-at
				   (y (vector-ref fvs (+ i 0)))
				   (y (vector-ref fvs (- i 1)))))
			     )))
  (- 1 (/ direction-energy (* 2 (sqr pi))))
     ))

(define (trace-keep-turning fvs i)
 (let* ((direction-energy (sqr (center-angle-at
				   (y (vector-ref fvs (+ i 0)))
				   (y (vector-ref fvs (- i 1)))))))
  ;;(trace-dtrace "turning:" (primal* (sigmoid (/ direction-energy (* 2 (sqr pi))) .02 .1)))
  ;; (/ direction-energy (* 2 (sqr pi))) 
  (sigmoid (/ direction-energy (* 2 (sqr pi))) .002 .1)))

(define (trace-parallel-to fvs i p2)
 (parallel-to (y (vector-ref fvs i)) (x (vector-ref fvs i)) p2))

(define (point-avg p1 p2)
 (vector (* .5 (+ (x p1) (x p2)))
	 (* .5 (+ (y p1) (y p2)))))

(define (trace-parallel-to2 fvs i p2)
 (parallel-to (y (vector-ref fvs i)) (point-avg
				      (x (vector-ref fvs i))
				      (x (vector-ref fvs (- i 1)))) p2))

(define (trace-past fvs i p2)
 ;; need to create two points for this, one with no funcitons, and then one with this function
 (* (trace-keep-straight fvs (- i 1))
    (trace-parallel-to fvs (- i 1) p2)
    (trace-keep-straight fvs i)))

(define (trace-around fvs i p2)
 (* ;(trace-keep-straight fvs (- i 2))
    (trace-parallel-to2 fvs (- i 2) p2)
   ;; (trace-keep-turning fvs (- i 1))
    (trace-parallel-to2 fvs (- i 1) p2)
    ;;(trace-keep-turning fvs (- i 0))
    (trace-parallel-to2 fvs (- i 0) p2)
    (between p2 (x (vector-ref fvs i)) (x (vector-ref fvs (- i 3))))
    ;; (angles-opposite-each-other (y (vector-ref fvs i)) (y (vector-ref fvs (- i 3))))
    (distances-equal (x (vector-ref fvs i)) (x (vector-ref fvs (- i 1))) p2)
    (distances-equal (x (vector-ref fvs (- i 1))) (x (vector-ref fvs (- i 2))) p2)
    (distances-equal (x (vector-ref fvs (- i 2))) (x (vector-ref fvs (- i 3))) p2)
    ))


(define (trace-around2 fvs i p2)
 (* ;(trace-keep-straight fvs (- i 2))
    (trace-parallel-to2 fvs (- i 2) p2)
   ;; (trace-keep-turning fvs (- i 1))
    (trace-parallel-to2 fvs (- i 1) p2)
    ;;(trace-keep-turning fvs (- i 0))
    (trace-parallel-to2 fvs (- i 0) p2)
    (between p2 (x (vector-ref fvs i)) (x (vector-ref fvs (- i 3))))
    (angles-opposite-each-other (y (vector-ref fvs i)) (y (vector-ref fvs (- i 3))))
    (near (x (vector-ref fvs i)) p2)
    (near (x (vector-ref fvs (- i 1))) p2)
    (near (x (vector-ref fvs (- i 2))) p2)
    ;;(distances-equal (x (vector-ref fvs i)) (x (vector-ref fvs (- i 1))) p2)
    ;;(distances-equal (x (vector-ref fvs (- i 1))) (x (vector-ref fvs (- i 2))) p2)
    ;;(distances-equal (x (vector-ref fvs (- i 2))) (x (vector-ref fvs (- i 3))) p2)
    ))

(define (not-too-close point1 point2 radius1 radius2)
 (let* ((r (distance point1 point2))
       (rmax (+ radius1 radius2 (min radius1 radius2)))
       (rmin (+ radius2 radius2))
       (ravg (/ (+ rmin rmax) 2))
       (v (* (+ rmin rmax) .15)))
 (cond
  ((> r rmax) 1)
  (else
   (+ (sigmoid r ravg v) (- 1 (sigmoid rmax ravg v)))))))

(define (trace-adjacent-points-not-too-close trace radius)
 (reduce-vector * (map-vector (lambda (i) (not-too-close (vector-ref trace i)
					   (vector-ref trace (+ i 1))
					   radius
					   radius))
			      (enumerate-vector (- (vector-length trace) 1)))
		1))

(define (trace-not-too-close-to-obstacles trace obstacles robot-radius obstacle-radii)
 (reduce-vector * (map-vector
		   (lambda (i)
		    (reduce-vector
		     *
		    (map-vector
		     (lambda (j)
		      (not-too-close (vector-ref trace i)
				     (vector-ref obstacles j)
				     robot-radius
				     (vector-ref obstacle-radii j)))
		     (enumerate-vector (vector-length obstacles)))
		    1))
		   (enumerate-vector (vector-length trace)))
		1))		


(define (compute-trace-features points)
 (map-n-vector
  (lambda (j)
   (let* ((i (- j 1)))
   (vector (if (= i -1) (vector 0 0) (vector-ref points i))
	   (angle-between ;;(if (= i (- (vector-length points) 1))
	    (if (< i 0)
		(vector 0 0)
		(vector-ref points i))
			     ;; (vector-ref points (+ i 1)))
	    (if (< i 1)
		(vector 0 0);; the -1th point is (0 0);;(vector-ref points i)
		(vector-ref points (- i 1)))))))			      
  (+ (vector-length points) 1)))

(define (compute-generic-trace-features points)
 (map-n-vector
  (lambda (j)
   (let* ((i (- j 1)))
   (vector (if (= i -1) (vector 0 0) (vector-ref points i))
	   (angle-between ;;(if (= i (- (vector-length points) 1))
	    (if (< i 0)
		(vector 0 0)
		(vector-ref points i))
			     ;; (vector-ref points (+ i 1)))
	    (if (< i 1)
		(vector 0 0);; the -1th point is (0 0);;(vector-ref points i)
		(vector-ref points (- i 1)))))))			      
  (+ (vector-length points) 1)))

(define (location-orientation-wrt-object point object)
 (angle-between point object))

(define (object-orientation-wrt-direction point direction object)
 (center-angle-at direction (angle-between object point)))

(define (object-orientation-difference-wrt-objects point object1 object2)
 (center-angle-at (angle-between point object1) (angle-between point object2)))

(define (compute-one-object-features generic-trace-features objects)
 (map-vector
  (lambda (fv)
   (map-vector
    (lambda (object)
     (vector (location-orientation-wrt-object (x fv) object)
	     (object-orientation-wrt-direction  (x fv) (y fv) object)))
    objects))
  generic-trace-features))

(define (compute-two-object-features generic-trace-features objects)
 (map-vector
  (lambda (fv)
   (map-n-vector
    (lambda (i)
     (map-n-vector
      (lambda (j)
       (vector (object-orientation-difference-wrt-objects  (x fv)
							   (vector-ref objects i)
							   (vector-ref objects (+ i j)))))
      (- (vector-length objects) i)))
    (vector-length objects)))
  generic-trace-features))

(define (score-parse-functions parse-functions trace)
 ;;(trace-dtrace "score-parse-functions:" (map-vector primal* trace))
 (let* ((trace-features (compute-trace-features (shape-matrix trace 2))))
;;(trace-dtrace "fvs:" (map-vector (lambda (v) (map-vector primal* v)) trace-features))
 (*
  (reduce-vector *
  (map-vector
   (lambda (v)
    (reduce-vector * v 1))
   (map-vector
    (lambda (feature-functions i)
     (map-vector (lambda (f)
	   (f trace-features i))
	  feature-functions))
   parse-functions
   (enumerate-vector (vector-length parse-functions))))
  1))))

;;(+ (left-of (list (vector-ref trace 0) (y trace 1)) (list 1 1))
;;   (in-front-of (list (vector-ref trace 0) (vector-ref trace 1)) (list -2 2))));; *obstacle-lexicon*)))

(define (minimize f x tol1 tol2)
 (let ((g (gradient-R f)))
  (let loop ((x x)
	     (gx (magnitude (g x)))
	     (c (f x))
	     (step .1))
   (trace-dtrace "x c" (list (primal* x) c))
   (if (or (< c tol1)
	   (< gx tol2))
       x
       (let* ((gx (g x))
	      (x-prime (v- x (k*v step gx)))
	      (c-prime (f x-prime)))
	;;(trace-dtrace "mgx" (magnitude gx))
	;;(trace-dtrace "step:" step)
	(if (< c-prime c)
	    (loop x-prime (magnitude gx) c-prime (* step 1.1))
	    (loop x (magnitude gx) c (* step .5))))))))

(define (maximize f x tol1 tol2 drawing-function)
 (let ((g (gradient-R f)))
  (let loop ((x x)
	     (gx (magnitude (g x)))
	     (c (f x))
	     (step .1)
	     (prev-dx (map-n-vector (lambda (i) 0) (vector-length x))))
   (when (= (modulo *iteration-count* 100) 0) (trace-dtrace "x c gx step" (list (primal* x) c gx step))
	 (when drawing-function (drawing-function x))
	 ;; (plot-lines-in-matlab (list (cons 0 (vector->list (map-vector (lambda (v) (vector-ref v 0))
	 ;; 								       (shape-matrix x 2)))))
	 ;; 		       (list (cons 0 (vector->list (map-vector (lambda (v) (vector-ref v 1))
	 ;; 								       (shape-matrix x 2)))))
	 ;; 			     (list "'trace'") ".-")
	 )
   (set! *iteration-count* (+ *iteration-count* 1))
   (if (or (> c tol1)
	   (< gx tol2)
	   (< step 1e-12)
	   (< (* step gx) 1e-5))
       x
       (let* ((gx (g x))
	      (dx (k*v step (v+ gx (k*v 0.00 prev-dx))))
	      (x-prime (v+ x dx))
	      (c-prime (f x-prime)))
	;;(trace-dtrace "mgx" (magnitude gx))
	;;(trace-dtrace "step:" step)
	(if (> c-prime c)
	    (loop x-prime (magnitude gx) c-prime (* step 1.5) dx)
	    (loop x (magnitude gx) c (* step .5) (k*v .5 prev-dx))))))))

(define (nice-subvector v i j)
(if (>= i (vector-length v))
    `#()
    (subvector v i j)))

(define (maximize-with-respect-to-ith-point i f x tol1 tol2 drawing-function)
 (let* ((new-f (lambda (v)
		(let* ((newx (vector-append (nice-subvector x 0 (* i 2)) v (nice-subvector x (* (+ i 1) 2) (vector-length x)))))
		 ;;(trace-dtrace "newx" (map-vector primal* newx))
		 (f newx)))))
  (vector-append (nice-subvector x 0 (* i 2))
		 (maximize new-f (trace-dtrace "current point:" (nice-subvector (trace-dtrace "whole vector:" x) (* i 2) (+ (* i 2) 2))) tol1 tol2 drawing-function)
		 (nice-subvector x (* (+ i 1) 2) (vector-length x)))))

(define (trace-from-parse-functions parse-functions drawing-function)
 (set! *iteration-count* 0)
 (let* ((number-of-points (- (vector-length parse-functions) 1))
	(initial-trace (trace-dtrace "initial trace:"(map-n-vector (lambda (i)
				      (if (= (modulo i 2) 0) 0 (/ i 10)))
				     (* 2 number-of-points))))
	(score-function (lambda (trace) (score-parse-functions parse-functions trace))))
  (trace-dtrace "initial trace features: " (compute-trace-features (shape-matrix initial-trace 2)))
  (start-matlab!)
  (let ((result (maximize score-function initial-trace (- 1 1e-4) 1e-5 drawing-function)))
   (when drawing-function (drawing-function result))
   (vector-append (vector `#(0 0)) (shape-matrix result 2)))))

(define (trace-from-parse-functions-with-initial parse-functions initial-trace drawing-function)
 (set! *iteration-count* 0)
 (let* ((number-of-points (- (vector-length parse-functions) 1))
	;; (initial-trace (trace-dtrace "initial trace:"(map-n-vector (lambda (i)
	;; 			      (if (= (modulo i 2) 0) 0 (/ i 10)))
	;; 			     (* 2 number-of-points))))
	(score-function (lambda (trace) (score-parse-functions parse-functions trace))))
  (trace-dtrace "initial trace features: " (compute-trace-features (shape-matrix initial-trace 2)))
  (start-matlab!)
  (let ((result (maximize score-function initial-trace (- 1 1e-7) 1e-7 drawing-function)))
   (when drawing-function (drawing-function result))
    (vector-append  `#(0 0) result))))


(define (trace-from-parse-functions-step-by-step parse-functions drawing-function)
 (let* ((result1
	(let loop ((parse-functions parse-functions)
		   (used-parse-functions (list (first (vector->list parse-functions))))
		   (unused-parse-functions (rest (vector->list parse-functions)))
		   (initial-trace `#(0 0)))
	 (if (null? unused-parse-functions)
	     (shape-matrix initial-trace 2)
	     (loop
	      parse-functions
	      (cons (first unused-parse-functions) used-parse-functions)
	      (rest unused-parse-functions)
	      (trace-from-parse-functions-with-initial
	       (list->vector (reverse (cons (first unused-parse-functions) used-parse-functions)))
	       (vector-append (subvector initial-trace 2 (vector-length initial-trace))
			      (v+ (subvector initial-trace
					     (- (vector-length initial-trace) 2)
					     (- (vector-length initial-trace) 0))
				  (k*v .1 (if (>= (vector-length initial-trace) 4)
					      (v- (subvector initial-trace
							     (- (vector-length initial-trace) 2)
							     (- (vector-length initial-trace) 0))
						  (subvector initial-trace
							     (- (vector-length initial-trace) 4)
							     (- (vector-length initial-trace) 2)))
					      (vector 0 .1)))))
	       drawing-function)))))
	(result2
	 (let outer-loop
	   ((j 0)
	    (x (reduce-vector vector-append (subvector result1 1 (vector-length result1)) `#()))
	    (score 0))
	  (if (> j 5)
	      (list (shape-matrix x 2) score)
	      (let ((x-and-score
		     (let loop ((i 0)
				(x x))
		      
		      (if (>= i (vector-length parse-functions))
			  (list x (score-parse-functions parse-functions x)) 
			  (loop (+ i 1)
				(trace-dtrace "output from first ith optimization"
					      (maximize-with-respect-to-ith-point
					       i
					       (lambda (trace)
						(score-parse-functions parse-functions trace))
					       x
					       1
					       1e-7
					       drawing-function)))))))
	       (outer-loop (+ j 1)
			   (first x-and-score)
			   (second x-and-score)))))))
  (when drawing-function (drawing-function (reduce-vector vector-append (first result2) `#())))
 (list (vector-append (vector (vector 0 0)) (first result2)) (second result2))))

(define (trace->splines trace number-of-points)
(scheme->matlab! "points" trace)
 (scheme->matlab! "t" (enumerate-vector (vector-length trace)))
(matlab (format #f "pp=spline(t,points'); yy=ppval(linspace(0,max(t),~a),pp);" number-of-points))
(let* ((xs-and-ys (matlab-get-variable "yy")))
 (map-vector (lambda (x y)
	      (vector x y))
	     (x xs-and-ys)
	     (y xs-and-ys))))

(define (interpolate-trace trace factor)
 (if (<= factor 1)
     trace
     (interpolate-trace
      (map-n-vector
       (lambda (i)
	(if (>= (+ (exact-floor (/ i 2)) 1) (vector-length trace))
	    (vector-ref trace (trace-dtrace "point1" (exact-floor (/ i 2))))
	    (let* ((point1 (vector-ref trace (trace-dtrace "point1" (exact-floor (/ i 2)))))
		   (point2 (vector-ref trace (+ (exact-floor (/ i 2)) 1))))
	     (if (= (/ i 2) (exact-round (/ i 2)))
		 point1
		 (point-avg point1 point2)))))
       (- (* (vector-length trace) 2) 1))
      (/ factor 2))))
 

(define (plot-trace-splines trace)
 (scheme->matlab! "points" trace)
 (scheme->matlab! "t" (enumerate-vector (vector-length trace)))
 (matlab "points")
 (matlab "t")
 (matlab "hold on")
 (matlab (format #f "pp=spline(t,points'); yy=ppval(linspace(0,max(t),200),pp); plot(yy(1,:),yy(2,:),'b-',points(:,1),points(:,2),'ro');")))

(define (remove-the symbol) (string->symbol (second (pregexp-split "-" (symbol->string symbol)))))

(define (objects->plot-function objects)
 (lambda (ps)
  (plot-lines-in-matlab-with-symbols
   (list (map x
	      (map second objects))
	 (cons 0 (vector->list
		  (map-vector
		   (lambda (v) (vector-ref v 0))
		   (shape-matrix ps 2)))))
   (list (map y (map second objects))
	 (cons 0 (vector->list
		  (map-vector
		   (lambda (v) (vector-ref v 1))
		   (shape-matrix ps 2)))))
   (list "'objects'" "'trace'") (list "b." "g.-"))
  (map (lambda (object)
	(matlab (format #f "text(~a,~a,'~a')" (x (second object)) (y (second object))
			(symbol->string (remove-the (first object))))))
       objects)
  (matlab "hold off")
  (matlab "axis equal")))


(define (plot-trace trace objects)
 (plot-lines-in-matlab-with-symbols
  (list (map x
	     (map second objects))
	(map x (vector->list trace)))
  (list (map y (map second objects))
	(map y (vector->list trace)))
  (list "'objects'" "'trace'") (list "b." "g-"))
 (map (lambda (object)
       (matlab (format #f "text(~a,~a,'~a')" (x (second object)) (y (second object))
		       (symbol->string (remove-the (first object))))))
      objects)
 (matlab "hold off")
 (matlab "axis equal"))

(define (vector-ref-bounded v i)
 (cond ((< i 0)
	(vector-ref v 0))
       ((>= i (vector-length v))
	(vector-ref v (- (vector-length v) 1)))
       (else
	(vector-ref v i))))
	

(define (smooth-trace trace weights)
 (map-n-vector
  (lambda (i)
   (reduce
    v+
    (map k*v weights (map (lambda (j) (vector-ref-bounded trace (+ i j)))
			(map (lambda (j) (- j (exact-floor (/ (length weights) 2))))
			     (enumerate (length weights)))))
    `#(0 0)))
   (vector-length trace)))


(define (random-object-instantiation object-types number minimum-distance field-size)
 (let loop ((objects '()))
  (if (>= (length objects) number)
      objects
      (let* ((type (list-ref object-types (random-integer (length object-types))))
	     (x (random-in-range (- (/ field-size 2)) (/ field-size 2)))
	     (y (random-in-range (- (/ field-size 2)) (/ field-size 2))))
   (if (some (lambda (o) (< (distance (second o) (vector x y)) minimum-distance)) objects)
       (loop objects)
       (loop (cons (list type (vector x y)) objects)))))))

(define (object-instantiations->object-structs objects)
 (map-indexed
  (lambda (o i)
   (make-object i
		(string-downcase (symbol->string (remove-the (first o))))
		(vector->list (second o))
		#f))
  objects))


(define (generate-random-field-track-sentence-triple object-types
						     number
						     minimum-distance
						     field-size
						     number-of-predicates
						     one-object-prepositions
						     plot?)
 (let* ((object-instantiations
	 (random-object-instantiation object-types number minimum-distance field-size))
	(object-strings
	 (map string-downcase
	      (map symbol->string
		   (map remove-the (map first object-instantiations)))))
	(object-structs (object-instantiations->object-structs object-instantiations))
	(resolved-objects (dtrace "resolved:" (map render-object (resolve-ambiguity object-structs))))
	(sentence
	 (dtrace "sentence:" (generate-random-simple-sentence resolved-objects number-of-predicates one-object-prepositions)))
	(raw-trace-and-score (trace-from-parse-functions-step-by-step
			      (parse-tree->parse-functions
			       (parse-sentence sentence) object-instantiations)
			      (if plot? (objects->plot-function object-instantiations) #f)))
	(raw-trace (first raw-trace-and-score))
	(score (second raw-trace-and-score))
	(trace (smooth-trace
		(interpolate-trace
		 raw-trace
		 32)
		(list .15 .7 .15))))
  (when plot? (plot-trace trace object-instantiations))
(if (< score (expt .98 number-of-predicates))
    #f
    (list object-instantiations
	  sentence
	  trace))))

(define (n-indexed-weighted-random-elements-without-replacement n weighted-list)
 (if (< (length weighted-list) n)
     (panic "not enough elements")
     (let loop ((weighted-list weighted-list)
		(result '()))
      (if (= (length result) n)
	  result
	  (let* ((total-weight (reduce + (map second weighted-list) 0))
		 (lottery-number (random-in-range 0 total-weight))
		 (indexed-winner (let loop2 ((i 0)
					     (weighted-list weighted-list)
					     (lottery-number lottery-number))
				  (if (< lottery-number (second (first weighted-list)))
				      (list (first weighted-list) i)
				      (loop2 (+ i 1)
					     (rest weighted-list)
					     (- lottery-number (second (first weighted-list))))))))
	   (loop (list-remove weighted-list (second indexed-winner))
		 (cons indexed-winner result)))))))

(define (generate-random-dataset number-of-datapoints
				 weighted-numbers-of-objects
				 weighted-numbers-of-predicates
				 object-types
				 minimum-distance
				 field-size
				 one-object-prepositions
				 plot?)
 (map-n
  (lambda (d)
   (let ((number-of-objects (first (first (first (n-indexed-weighted-random-elements-without-replacement 1 weighted-numbers-of-objects)))))
	 (number-of-predicates (first (first (first (n-indexed-weighted-random-elements-without-replacement 1 weighted-numbers-of-predicates))))))
    (generate-random-field-track-sentence-triple object-types
						 number-of-objects
						 minimum-distance
						 field-size
						 number-of-predicates
						 one-object-prepositions
						 plot?)))
  number-of-datapoints))

(define (filter-out-complicated-triples dataset max-references)
 (remove-if (lambda (triple)
	     (> (length (remove-if (lambda (r) (equal? (first r) 'robot))
				   (first (parsed-sentence->linked-references
				(parse-sentence (second triple))))))
		max-references))
	    dataset))
  

;; (load "/home/dpbarret/darpa-collaboration/rover/toollib-trace-generator.sc") (plot-trace-splines (trace-from-parse-functions (vector (vector (lambda (fvs i) (trace-adjacent-points-not-too-close (map-vector x fvs) .15))) (vector  (lambda (fvs i) (trace-left-of fvs i (vector 1 1))) (lambda (fvs i) (trace-in-front-of fvs i (vector 0 2)))) (vector (lambda (fvs i) (trace-left-of fvs i (vector 2 2))) (lambda (fvs i) (trace-in-front-of fvs i (vector 1 3)))) (vector  (lambda (fvs i) (trace-in-front-of fvs i (vector 0.5 2.5))) (lambda (fvs i)(trace-away-from fvs i (vector 2 2)))) (vector  (lambda (fvs i) (trace-towards fvs i (vector 6.5 -3)))) (vector  (lambda (fvs i) (trace-towards fvs i (vector 0 0))))) (lambda (x) (plot-lines-in-matlab-with-symbols (list (list 1 0 2 1 0 .5 0 5 2) (cons 0 (vector->list (map-vector (lambda (v) (vector-ref v 0)) (shape-matrix x 2))))) (list (list 1 2 2 3 2 2 3 .5 0) (cons 0 (vector->list (map-vector (lambda (v) (vector-ref v 1)) (shape-matrix x 2))))) (list "'obstacles'" "'trace'") (list "." ".-")))))



;; more up to date:

;; (load "/home/dpbarret/darpa-collaboration/rover/new-parser.sc")
;;(trace->splines (trace-from-parse-functions-step-by-step (parse-tree->parse-functions (parse-sentence "the robot went between the table which is between the chair and the box which is right of the table and the chair then went right of the stool then went in front of the cone and behind the table then went between the ball and the bucket then went left of the ball then went between the ball and the table which is in front of the box which is left of the cone") *object-instantiations*) (objects->plot-function *object-instantiations*)) 100)

;; list of trace sentences:

;; (this one is with the old object locations)
;; (trace-from-parse-functions-step-by-step (parse-tree->parse-functions (parse-sentence "the robot went between the bucket and the cone which is left of the ball then went behind the ball then went around the ball") *objects1*) (objects->plot-function *objects1*))

;;(trace-from-parse-functions-step-by-step (parse-tree->parse-functions (parse-sentence "the robot went towards the box then went past the table which is left of the chair then went behind the chair then went in front of the table which is right of the chair") *objects1*) (objects->plot-function *objects1*))

;;(trace-from-parse-functions-step-by-step (parse-tree->parse-functions (parse-sentence "the robot went in front of the ball then went around the ball then went behind the chair which is behind the box then went left of the box") *objects2*) (objects->plot-function *objects2*))

;;(trace-from-parse-functions-step-by-step (parse-tree->parse-functions (parse-sentence "the robot went between the bucket and the box which is left of the ball then went around the bucket then went behind the box which is right of the ball") *objects3*) (objects->plot-function *objects3*))

;;(trace-from-parse-functions-step-by-step (parse-tree->parse-functions (parse-sentence "the robot went between the bucket and the box which is left of the ball then went around the bucket then went left of the ball then went away from the ball") *objects3*) (objects->plot-function *objects3*))

;; (trace-from-parse-functions-step-by-step (parse-tree->parse-functions (parse-sentence "the robot went towards the stool then went between the cone and the ball which is right of the stool then went past the cone then went between the bucket and the ball which is left of the cone then went around the bucket") *objects4*) (objects->plot-function *objects4*))

;; (trace-from-parse-functions-step-by-step (parse-tree->parse-functions (parse-sentence "the robot went right of the stool then went in front of the bucket which is left of the table then went towards the table then went right of the bucket") *objects5*) (objects->plot-function *objects5*))


(define foo #f)