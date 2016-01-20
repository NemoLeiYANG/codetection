;;(load (format #f "/home/~a/darpa-collaboration/rover/toollib-analysis.sc" (getenv "USER")))

(load (format #f "/home/~a/imitate/tool/toollib-ad.sc" (getenv "USER")))
(load "/home/dpbarret/darpa-collaboration/rover/haonan-generator.sc")
(load (format #f "/home/dpbarret/darpa-collaboration/pose-retraining/felz-baum-welch-plotting.sc"));; (getenv "USER")))

(define *learned-one-object-prepositions*
 '(left-of right-of in-front-of behind towards away-from))

(define (params->lexicon params)
 (let* ((obj-params (subvector params 0 (* 7 7)))
	(noun-distributions (shape-matrix obj-params 7))
	(prep-params (subvector params (+ (* 7 7) 1) (vector-length params)))
	(prep-feats-distributions (map-vector (lambda (p)
					       (shape-matrix p 16))
					      (shape-matrix prep-params 32)))
	(prep-feats-von-mises (map-vector
			       (lambda (p)
				(map-indexed-vector
				 (lambda (d i)
				  (if (= i 0)
				      (list->vector (fit-model-to-angular-histogram d))
				      (list->vector (fit-model-to-angular-histogram
				       (duplicate-bins d)))))
				 p))
			       prep-feats-distributions)))
  (vector noun-distributions
	  prep-feats-von-mises)))

(define (adverb-preposition->function preposition lexicon)
 (lambda (fv object-position)
  (parser-dtrace "fv objpos" (list fv object-position))
  (score-adverb fv (vector-ref (y lexicon) (position preposition *learned-one-object-prepositions*)) object-position)))

;;  (case preposition
;;   ((left-of)
;;    trace-left-of)
;;   ((right-of)
;;    trace-right-of)
;;   ((in-front-of)
;;    trace-in-front-of)
;;   ((behind)
;;    trace-behind)
;; ;;  ((between)
;; ;;   trace-between)
;;   ((towards)
;;    trace-towards)
;;   ((away-from)
;;    trace-away-from)
;;  ;; ((past)
;;  ;;  trace-past)
;;  ;; ((around)
;;  ;;  trace-around)
;;   (else
;;    (parser-dtrace "unknown adverb preposition:" preposition)
;;    (fuck-up))))

(define (adjective-preposition->function preposition lexicon)
 (lambda (p1 p2)
  (score-adjective p1 p2 (vector-ref (y lexicon) (position preposition *learned-one-object-prepositions*)))))


(define *objects*
 (list 'the-table 'the-chair 'the-box 'the-bucket 'the-cone 'the-stool 'the-bag))

(define *object-code-names*
 (list 'the-table 'the-chair 'the-box 'the-bucket 'the-cone 'the-bag 'the-stool))

(define (object-phrase->scored-points object-phrase objects lexicon)
 (parser-dtrace "input to object-phrase->scored-points:" object-phrase)
 (parser-dtrace
  "object-phrase->point returned:"
  (if (equal? (dtrace "what is this?" (first (second object-phrase))) 'noun)
      ;; (list (a-member-of
      ;; 	     (parser-dtrace "objects to choose from:"(remove-if-not
      ;; 	      (lambda (o)
      ;; 	       (equal? (first o)
      ;; 		       (second (second object-phrase))))
      ;; 	      objects)))
      ;; 	    1)
     (let* ((object-class (second (second object-phrase)))
	    (object (a-member-of objects))
	    (object-type-score (parser-dtrace "object-type-score"
					(vector-ref
				 (vector-ref (x lexicon)
					     (position object-class *objects*))

				 (position (first object) *object-code-names*)))))
      (list object (log object-type-score)))
      
      (let* ((object-class (second (first (second object-phrase))))
	     (object (a-member-of
		      objects
		      ;; (remove-if-not
		      ;;  (lambda (o)
		      ;; 	(equal? (first o)
		      ;; 		object-class))
		      ;;  objects)
		      ))
	     (object-type-score (parser-dtrace "object-type-score"
					(vector-ref
				 (vector-ref (x lexicon)
					     (position object-class *objects*))

				 (position (first object) *object-code-names*))))
	     (score
	      (+ (log object-type-score)
	      (reduce
	       +
	       (map
		(lambda (e)
		 (parser-dtrace "element of adjective phrase" e)
		 (if (equal? (first (first e)) 'ONE-OBJECT-ADJECTIVE-PREPOSITION)
		     (let ((other-scored-object (object-phrase->scored-points
						 (second e)
						 objects
						 lexicon)))
		      (when (equal? (parser-dtrace "other object:"(first other-scored-object)) (parser-dtrace "object:" object))
		       (parser-dtrace "objects equal, failing" (list object other-scored-object))
		       (fail))
		      (+ ((adjective-preposition->function (second (first e)) lexicon)
			  (second object)
			  (second (first other-scored-object)))
			 (second other-scored-object)))
		     (let ((other-scored-object1 (object-phrase->scored-points
						  (second e)
						  objects
						  lexicon))
			   (other-scored-object2 (object-phrase->scored-points
						  (third e)
						  objects
						  lexicon)))
		      (when (or (equal? (first other-scored-object1) object)
				(equal? (first other-scored-object2) object)
				(equal? (first other-scored-object1) (first other-scored-object2)))
		       (fail))
		      (+ ((adjective-preposition->function (second (first e)) lexicon)
			  (second object)
			  (second (first other-scored-object1))
			  (second (first other-scored-object2)))))))
		     
		(second (second (second object-phrase))))
	       0))))
       (list object score)))))

(define (object-phrase->point object-phrase objects lexicon)
 (parser-dtrace "object-phrase:" object-phrase)
 (let* ((scored-objects
	 (parser-dtrace "scored-objects:"
			(all-values (object-phrase->scored-points
				     object-phrase objects lexicon))))
	(sorted-objects (sort scored-objects > second)))
  (dtrace "point" (second (first (first sorted-objects))))))


(define (parse-tree->parse-functions parse-tree objects lexicon)
 (let* ((simplified-parse-tree (simplify-parse-tree parse-tree)))
  (list->vector
   (cons
    ;;(vector )
    (vector
    	  (lambda (fvs i)
    	   (trace-adjacent-points-not-too-close (map-vector x fvs) .15))
    	  (lambda (fvs i)
    	   (trace-not-too-close-to-obstacles
    	    (map-vector x fvs)
    	    (list->vector (map second objects))
    	    .1
    	    (list->vector (map (lambda (o) .3) objects)))))
    (let* ((time-function-sets 
	    (map
	     (lambda (predicate)
	      (map
	       (lambda (adverbial-phrase)
		(parser-dtrace "adverbial-phrase" adverbial-phrase)
		(if (equal? (first (first (second adverbial-phrase)))
			    'ONE-OBJECT-ADVERB-PREPOSITION)
		    (let* ((object (object-phrase->point (second (second adverbial-phrase))
							 objects
							 lexicon))
			   (adverb (second (first (second adverbial-phrase))))
			   (function (parser-dtrace "prep->function output:"
					     (adverb-preposition->function adverb lexicon))))
		     (list
		      (cond
		       ((equal? adverb 'past) 1)
		       ((equal? adverb 'around) 2)
		       (else 0))
		      (lambda (fvs i)
		       (parser-dtrace "this function is asociated with:" (list fvs i object adverb))
		       (parser-dtrace "function output:"(function
			(vector-ref fvs i) object)))))
		    (begin
		     (panic "we don't yet have any multi-object prepositions")
		     (let* ((object1 (object-phrase->point (second (second adverbial-phrase))
							  objects))
			   (object2 (object-phrase->point (fourth (second adverbial-phrase))
							  objects))
			   (adverb (second (first (second adverbial-phrase))))
			   (function (parser-dtrace "2prep->function output:"
					     (adverb-preposition->function adverb))))
		     (list
		      (cond
		       ((equal? adverb 'past) 1)
		       ((equal? adverb 'around) 2)
		       (else 0))
		      (lambda (fvs i)
		       (function
			fvs i
			object1 object2)))))))
	       
	       predicate))
	     simplified-parse-tree)))
      (let loop ((time-function-sets time-function-sets))
       (if (null? time-function-sets)
	   '()
	   (append
	    (append
	     (map-n (lambda (i) (vector )) (maximum (map first (first time-function-sets))))
	     (list (list->vector (map second (first time-function-sets)))))
	    (loop (rest time-function-sets))))))))))

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

(define (renormalized-von-mises v mean kappa)
;; (let ((x (- v mean)))
;; (/ (exp (* kappa (cos x)))))
(- (log-von-mises v mean kappa)
   (log-von-mises 0 0 kappa)))

(define (score-adverb features models object-position)
 ;; features is the position and velocity of the robot
 (let* ((position-angle (parser-dtrace "position angle"
				(angle-between (x features) object-position)))
	(velocity-angle (parser-dtrace "velocity angle:"(center-angle-at (y features)
					 (angle-between object-position
							(x features)))))
	(score (+ (parser-dtrace "position score:" (renormalized-von-mises position-angle (x (x models)) (y (x models))))
     (parser-dtrace "velocity score:" (renormalized-von-mises velocity-angle (x (y models)) (y (y models))))
     (- (distance (x features) object-position)))))
  ;;(dtrace "avb score:" (primal* score))
  score))

 ;; (reduce * (map-vector (lambda (f m) (renormalized-von-mises f (x m) (y m)))
 ;; 		features models)
 ;; 	 1))

(define (score-adjective p1 p2 models)
 (renormalized-von-mises (angle-between p1 p2) (x (x models)) (y (x models))))

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
   ;;(dtrace "not too close:" (primal* (/ (- r rmax) r)))
   (+ 1 (/ (- rmax r) r))))))
;;   (+ (sigmoid r ravg v) (- 1 (sigmoid rmax ravg v)))))))

(define (trace-adjacent-points-not-too-close trace radius)
 (- (log (reduce-vector * (map-vector (lambda (i) (not-too-close (vector-ref trace i)
					   (vector-ref trace (+ i 1))
					   radius
					   radius))
			      (enumerate-vector (- (vector-length trace) 1)))
		1))))

(define (trace-not-too-close-to-obstacles trace obstacles robot-radius obstacle-radii)
 (- (log (reduce-vector * (map-vector
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
		1))))		


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
     (vector (location-orientation-wrt-object (x fv) (y object))
	     (object-orientation-wrt-direction  (x fv) (y fv) (y object))))
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
 (let* ((trace-features (compute-one-object-features
			 (compute-generic-trace-features (shape-matrix trace 2)))))
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

(define (trace->features trace objects)
 (compute-one-object-features
  (compute-generic-trace-features (shape-matrix trace 2))
  objects))

(define (score-parse-functions parse-functions trace)
 ;;(trace-dtrace "score-parse-functions:" (map-vector primal* trace))
  (let* ((trace-features (compute-generic-trace-features (shape-matrix trace 2))))
;;(trace-dtrace "fvs:" (map-vector (lambda (v) (map-vector primal* v)) trace-features))
 (+
  (reduce-vector +
  (map-vector
   (lambda (v)
    (reduce-vector + v 0))
   (map-vector
    (lambda (feature-functions i)
     (map-vector (lambda (f)
	   (f trace-features i))
	  feature-functions))
   parse-functions
   (enumerate-vector (vector-length parse-functions))))
  0))))

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
   (when (= (modulo *iteration-count* 1000) 0) (trace-dtrace "x c gx step" (list (primal* x) c gx step))
	 (when drawing-function (drawing-function x))
	 ;; (plot-lines-in-matlab (list (cons 0 (vector->list (map-vector (lambda (v) (vector-ref v 0))
	 ;; 								       (shape-matrix x 2)))))
	 ;; 		       (list (cons 0 (vector->list (map-vector (lambda (v) (vector-ref v 1))
	 ;; 								       (shape-matrix x 2)))))
	 ;; 			     (list "'trace'") ".-")
	 )
   (set! *iteration-count* (+ *iteration-count* 1))
   (if (or (> c tol1)
	   ;(< gx tol2)
	   (< step 1e-12)
	   ;(< (* step gx) 1e-5)
	   )
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
  

(define (trace-from-sentence-floorplan-and-lexicon sentence floorplan lexicon)
 (trace-from-parse-functions-step-by-step
  (parse-tree->parse-functions
   (parse-sentence sentence)
   floorplan lexicon)
  (objects->plot-function floorplan)))

(define (trace-from-sentence sentence)
(trace-from-sentence-floorplan-and-lexicon sentence (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/saved-floorplan.sc") (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/learned-lexicon.sc")))


(define (line-intersects-circle? line-p1 line-p2 circle-center circle-radius)
 (let* ((dx (- (x line-p2) (x line-p1)))
	(dy (- (y line-p2) (y line-p1)))
	(dr (sqrt (+ (* dx dx) (* dy dy))))
	(D (- (* (- (x line-p1) (x circle-center)) (- (y line-p2) (y circle-center)))
	      (* (- (x line-p2) (x circle-center)) (- (y line-p1) (y circle-center))))))
  (>= (- (* (sqr circle-radius) (sqr dr)) (sqr D))
      0)))

(define (sign x)
 (if (>= x 0)
     1
     -1)) 

(define (line-circle-intersection
	 line-p1 line-p2 circle-center circle-radius)
 (let* ((dx (- (x line-p2) (x line-p1)))
	(dy (- (y line-p2) (y line-p1)))
	(dr (sqrt (+ (* dx dx) (* dy dy))))
	(D (- (* (- (x line-p1) (x circle-center)) (- (y line-p2) (y circle-center)))
	      (* (- (x line-p2) (x circle-center)) (- (y line-p1) (y circle-center))))))
  (if (>= (- (* (sqr circle-radius) (sqr dr)) (sqr D))
	  0)
      (vector (- (/ (+ (* D dy)
		    (* (sign dy)
		       dx
		       (sqrt (- (* (sqr circle-radius)
				   (sqr dr))
				(sqr D)))))
		 (sqr dr)) (x circle-center))
	      (- (/ (+ (* -1 D dx)
		    (* (abs dy)
		       (sqrt (- (* (sqr circle-radius)
				   (sqr dr))
				(sqr D)))))
		 (sqr dr)) (y circle-center)))
      #f)))



(define (line-pair->lambda line1 line2)
 ;;; lambda from (x,y)=(x1,y1)+lambda(x1-x2,y1-y2)
 ;;; where this is the particular lambda corresponding
 ;;; to the intersection
 (let* ((x1 (x (first line1)))
	(y1 (y (first line1)))
	(x2 (x (second line1)))
	(y2 (y (second line1)))
	(x1p (x (first line2)))
	(y1p (y (first line2)))
	(x2p (x (second line2)))
	(y2p (y (second line2)))
	(numerator (+ (* x1 y1p)
		      (- (* x1p y1))
		      (- (* x1 y2p))
		      (* x2p y1)
		      (* x1p y2p)
		      (- (* x2p y1p))))
	(denominator (+ (* x1 y1p)
			(- (* x1p y1))
			(- (* x1 y2p))
			(* x1p y2)
			(- (* x2 y1p))
			(* x2p y1)
			(* x2 y2p)
			(- (* x2p y2)))))
  (if (equal? denominator 0)
      infinity
  (-
   (/
    numerator
    denominator)))))

(define (line-pair->intersection line1 line2)
 (let* ((l (line-pair->lambda line1 line2))
	;;(d (distance (list->vector line1) (list->vector line2)))
	(x1 (x (first line1)))
	(y1 (y (first line1)))
	(x2 (x (second line1)))
	(y2 (y (second line1))))
  (if (equal? l infinity)
      (vector infinity infinity)
      (vector (+ x1 (* l (- x1 x2)))
	    (+ y1 (* l (- y1 y2)))))))

(define (point-on-line-nearest-point line-point1 line-point2 point)
 (let* ((dx (- (x line-point2) (x line-point1)))
	(dy (- (y line-point2) (y line-point1)))
	(v (vector dx dy))
	(perp-v (vector dy (- dx))))
  (line-pair->intersection (list line-point1 line-point2)
			   (list point (v+ point perp-v)))))

(define (point-on-line-segment? point line-point1 line-point2)
 (let* ((p-p1 (v- point line-point1))
	(p-p2 (v- point line-point2)))
  (< (magnitude (v- (k*v -1 (unit p-p1)) 
			 (unit p-p2)))
     0.0000001)))

(define (line-segment-intersects-circle? line-point1 line-point2 circle-center radius)
 (let ((nearest-point (point-on-line-nearest-point line-point1 line-point2 circle-center)))
  (and (<= (distance nearest-point circle-center)
	   radius)
       (point-on-line-segment? nearest-point line-point1 line-point2))))
       

(define (avoid-obstacle point1 point2 obstacle radius)
 (if (line-segment-intersects-circle? point1 point2 obstacle radius)
     (let* ((reference-point (dtrace (format #f "point on line [~a ~a]near point:~a" point1 point2 obstacle)
				     (point-on-line-nearest-point  point1 point2 obstacle)))
	     (mid-point (v+ obstacle
			    (k*v (* 1.1 radius)
				 (unit (v- reference-point
						obstacle))))))
      (dtrace "" (list point1 mid-point point2)))
     (list point1 point2)))

(define (segment->segments-avoiding-objects point1 point2 obstacle-points radius)
 ;;(plot-trace (vector point1 point2) (list (list 'the-dummy (vector 0 0))))
 (matlab "drawnow")
 (dtrace "point1 point2 objstacles" (list point1 point2 obstacle-points))
 (let* ((new-points
	 (let loop ((points (list point1 point2))
		    (obstacle-points obstacle-points))
	  (if (null? obstacle-points)
	      points
	      (loop (let subloop
		      ((points points)
		       (obstacle-points obstacle-points))
		     ;;(dtrace "points, obstacles:" (list points obstacle-points))
		     (if (< (length points) 2)
			 points
			 (append (subloop (but-last (avoid-obstacle (first points) (second points) (first obstacle-points) radius)) obstacle-points)
				 (subloop (rest points) obstacle-points))))
		    (rest obstacle-points))))))
;;  new-points))

  (if (> (length new-points) 2)
      (let loop ((points new-points))
       (if (< (length points) 2)
  	   points
  	   (append (but-last (segment->segments-avoiding-objects (first points) (second points) obstacle-points radius))
  		   (loop (rest points)))))
      new-points)))


  ;; 	(if (line-intersects-circle? point1 point2 (first obstacle-points) radius)
  ;;     (let* ((reference-point (point-on-line-nearest-point  point1 point2 (first obstacle-points)))
  ;; 	     (mid-point (v+ (first obstacle-points) (k*v (* 1.1 radius) (normalize (v- reference-point
  ;; 										       (first obstacle-points))))))
  ;;     (loop point1 point2 (rest obstacle-points))
  ;; ))

(define (avoid-objects trace floorplan radius)
 (let loop ((points trace))
       (if (< (length points) 2)
  	   points
  	   (append (but-last (dtrace "foo" (segment->segments-avoiding-objects (first points) (second points) (map second floorplan) radius)))
  		   (loop (rest points))))))

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