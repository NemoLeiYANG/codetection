(define *object-names* '("table" "chair" "box" ;;"ball"
			 "bucket" "cone" "stool" "bag"))
(define *directions* '("left-of" "in-front-of" "right-of" "behind"))
(define-structure object id name xy solution)

(define (trace->splines trace number-of-points)
 (let ((trace (list->vector (map list->vector trace))))
  (scheme->matlab! "points" trace)
  (scheme->matlab! "t" (enumerate-vector (vector-length trace)))
  (matlab (format #f "pp=spline(t,points'); yy=ppval(linspace(0,max(t),~a),pp);" number-of-points))
  (let* ((xs-and-ys (matlab-get-variable "yy")))
   (vector->list
    (map-vector (lambda (x y)
		 (list x y)) 
		(x xs-and-ys)
		(y xs-and-ys))))))

;;;;;;;;;;;;;;;;;;;;;;;;; 6 examples ;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;  (generate-sentence *trace1* *hand-models* *objects1* 5)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; (define *trace1* (trace->splines '((0 -2) (2 -2) (3 0) (2 2) (0 2) (-2 5) (1 7)) 100))
;; (define *objects1* (list (make-object 0 "bucket" '(1 5) #f)
;; 			(make-object 1 "table" '(2 0) #f)
;; 			(make-object 2 "chair" '(-2 2) #f)))

;; (define *trace2* (trace->splines '((0 -1) (2 -1) (3 0) (2 1) (0 1) (-4 1)) 100))
;; (define *objects2* (list (make-object 0 "table" '(-3 0) #f)
;; 			 (make-object 1 "chair" '(-1 0) #f)
;; 			 (make-object 2 "bucket" '(1 0) #f)))

;; (define *trace3* (trace->splines '((2 0) (1.5 -1.5) (0 -2) (-0.5 -0.5) (-1 0) (-1 4)) 100))
;; (define *objects3* (list (make-object 0 "table" '(0 0) #f)
;; 			 (make-object 1 "bucket" '(1 0) #f)
;; 			 (make-object 2 "chair" '(0 2) #f)
;; 			 (make-object 3 "stool" '(-2 0) #f)))

;; (define *trace4* (trace->splines '((1 -5) (1.2 -2.5) (1 0) (0.8 2.5) (1 5)) 30))
;; (define *objects4* (list (make-object 0 "table" '(0 -2) #f)
;; 			 (make-object 1 "chair" '(0 2) #f)
;; 			 (make-object 2 "bucket" '(2 4) #f)))

;; (define *trace5* (trace->splines '((-4 -4) (-3 -3.5) (-2 -2.5) (0 -1) (1 -2) (0 -3)
;; 				   (-1 -2) (1 4) (-2 5) (-4 2) (-5 -0.5)) 150)) 
;; (define *objects5* (list (make-object 0 "table" '(0 -2) #f)
;; 			 (make-object 1 "chair" '(1 5.5) #f)
;; 			 (make-object 2 "bucket" '(-3 3) #f)))

;; (define *trace6* (trace->splines '((-3 -2) (-3 0) (-2 4) (0 8) (2 4) (3 0)) 120))
;; (define *objects6* (list (make-object 0 "table" '(-2 0) #f)
;; 			 (make-object 1 "table" '(2 0) #f)
;; 			 (make-object 2 "chair" '(0 7) #f)))

;; (load (format #f "/home/~a/darpa-collaboration/pose-retraining/felz-baum-welch-plotting.sc" (getenv "USER")))

(define (plot-lines-in-matlab x-lists y-lists labels symbol)
 (matlab "X=[];")
 (matlab "Y=[];")
  (matlab (string-append
   "h=plot("
   (reduce (lambda (s1 s2)
	    (string-append s1 "," s2))
	   (map (lambda (x-values y-values i)
		     (scheme->matlab! "tempx" x-values)
		     (scheme->matlab! "tempy" y-values)
		     (matlab (format #f
				     "X{~a}=tempx;"
				     (+ i 1)))
		     (matlab (format #f
				     "Y{~a}=tempy;"
				     (+ i 1)))
		     (format #f
			     (string-append "X{~a},Y{~a},"
					    "'"symbol"'")
			     (+ i 1)
			     (+ i 1)))
		    x-lists y-lists (enumerate (length x-lists)))
   	   "")
   ")"))
  (matlab (string-append
	   "legend(h,"
	   (reduce (lambda (s1 s2)
		    (string-append s1 "," s2))
		   labels
		   "")
	   ",'Location','NorthWest')")))

(define (plot-lines-in-matlab-with-symbols x-lists y-lists labels symbols)
 (matlab "X=[];")
 (matlab "Y=[];")
  (matlab (string-append
   "h=plot("
   (reduce (lambda (s1 s2)
	    (string-append s1 "," s2))
	   (map (lambda (x-values y-values symbol i)
		     (scheme->matlab! "tempx" x-values)
		     (scheme->matlab! "tempy" y-values)
		     (matlab (format #f
				     "X{~a}=tempx;"
				     (+ i 1)))
		     (matlab (format #f
				     "Y{~a}=tempy;"
				     (+ i 1)))
		     (format #f
			     (string-append "X{~a},Y{~a}," symbol)
			     (+ i 1)
			     (+ i 1)))
		    x-lists y-lists symbols (enumerate (length x-lists)))
   	   "")
   ")"))
  (matlab (string-append
	   "legend(h,"
	   (reduce (lambda (s1 s2)
		    (string-append s1 "," s2))
		   labels
		   "")
	   ",'Location','NorthWest')")))
(define (objects->plot-function objects)
 (lambda (ps)
  (plot-lines-in-matlab-with-symbols
   (list (map x
	      (map second objects))
	 (vector->list
	  (map-vector
	   (lambda (v) (vector-ref v 0))
	   (shape-matrix ps 2))))
   (list (map y (map second objects))
	 (vector->list
	  (map-vector
	   (lambda (v) (vector-ref v 1))
	   (shape-matrix ps 2))))
   (list "'objects'" "'trace'") (list "'b.'" "'g-','LineWidth',2"))
  (map (lambda (object)
	(matlab (format #f "text(~a,~a,'~a')" (x (second object)) (y (second object))
			(symbol->string (first object)))))
       objects)
  (matlab "hold off")
  (matlab "axis equal")
  (matlab "axis equal; axis square; set(gcf,'WindowStyle','normal'); set(gcf, 'Position', [0 0 400 400])")))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;
;;;      4      ;;;
;;;   1  o  3   ;;;
;;;      2      ;;;
;;;;;;;;;;;;;;;;;;;
;; xy1 should be the anchor; xy2 should be the object
(define (spatial-location xy1 xy2)
 (if (equal? xy1 xy2)
     0
     (let* ((theta (angle-between xy1 xy2))
	    (theta (if (< theta (- (/ PI 4)))
		       (+ (* 2.25 PI) theta)
		       (+ (* 0.25 PI) theta))))
      (+ (quotient theta (/ PI 2)) 1))))

(define (compute-relation-matrix g object-groups)
 (map
  (lambda (o)
   (map
    (lambda (anchor-g)
     (remove-duplicates
      (remove-if zero?
		 (map
		  (lambda (anchor-o)
		   (spatial-location (object-xy anchor-o)
				     (object-xy o)))
		  anchor-g))))
    object-groups))
  g))

(define (compute-discrimination-matrices rm)
 (map
  (lambda (relation-i)
   (map
    (lambda (relation-j)
     (map
      (lambda (ri rj)
       (set-difference ri rj))
      relation-i relation-j))
    rm))
  rm))

(define (min-cover-column dm)
 (let* ((columns (transpose-list-of-lists dm))
	(order (sort (map-n identity (length columns)) >
		     (lambda (c)
		      (length (remove-if null? (list-ref columns c)))))))
  (let loop ((cover (map-n (const '()) (length dm)))
	     (remaining order)
	     (used '()))
   (if (not (some null? cover))        ;; the ambiguity can be resolved
       used
       (if (null? remaining)
	   #f
	   (let* ((current-trial (list-ref columns (first remaining)))
		  (trial-result (map fast-join (zip cover current-trial))))
	    (if (> (length (remove-if null? trial-result))
		   (length (remove-if null? cover)))
		(let ((rs (map-n
			   (lambda (r)
			    (if (and (null? (list-ref cover r))
				     (not (null? (list-ref trial-result r))))
				r
				-1))
			   (length trial-result))))
		 (loop trial-result (rest remaining)
		       (cons (list (first remaining) (removeq -1 rs)) used)))
		(loop cover (rest remaining) used))))))))

(define (generate-solution columns rm i object-groups)
 (define (power-set set)
  (if (null? set) '(())
      (let ((remainder-set (power-set (cdr set))))
       (append remainder-set
	       (map (lambda (subset) (cons (car set) subset))
		    remainder-set)))))
 (let* ((relation (list-ref rm i))
	(rmt (transpose-list-of-lists (list-remove rm i))))
  (map
   (lambda (crs)
    (let* ((c (first crs))
	   (rs (second crs))
	   (subsets (sort (power-set (list-ref relation c)) < length))
	   (column (list-ref rmt c))
	   (contains (map (lambda (p)
			   (list p
				 (every (lambda (r)
					 (not (null? (set-difference p (list-ref column r))))) rs)))
			  subsets))
	   (min-discrimination (first (find-if second contains))))
     (list (first (list-ref object-groups c))
	   min-discrimination)))
   columns)))

(define (render-object o)
 (define (modified? o)
  (and (not (null? (object-solution o)))
       (object-solution o)))
 (let ((subject (string-append "the " (object-name o))))
  (if (null? (object-solution o))
      subject
      (if (not (object-solution o))
	  subject
	  (let* ((anchors (sort (object-solution o)
				   (lambda (r1 r2)
				    (if (and (modified? r1)
					     (not (modified? r2))) #f #t)) first))
		 (modifiers
		  (fast-join (map (lambda (r)
			      (map (lambda (d)
				    (string-append " which is "
						   (list-ref *directions* (- d 1))
						   " "
						   (render-object (first r))))
				   (second r)))
			     anchors))))
	   (string-append subject (string-join " and" modifiers)))))))

(define (update-object-solution o solution)
 (make-object (object-id o)
	      (object-name o)
	      (object-xy o)
	      solution))

;; each object is a structure (id name xy solution)
(define (resolve-ambiguity objects)
 (define (pick-solution g)
  (first (sort g (lambda (r1 r2)
		  (if (or (not r1)
			  (and r2 (> (length r1) (length r2)))) #f #t))
	       object-solution)))
 (let* ((object-groups
	 (let ((groups (group-by object-name objects)))
	  (for-each (lambda (aa)
		     (when (= (length aa) 1)
		      (for-each (lambda (a)
				 (set-object-solution! a '())) aa)))
		    groups)
	  groups))
	(solved (map object-id (fast-join (remove-if (lambda (g) (> (length g) 1)) object-groups)))))
  ;; resolve multiple objects of the same class/word
 (let loop ((object-groups object-groups))
;;  (display solved) (newline)
  (let* ((new-object-groups
	  (map
	   (lambda (g)
	    (let* ((rm (compute-relation-matrix g object-groups))
		   (dms (compute-discrimination-matrices rm)))
	     (map
	      (lambda (dm o i)
	       (if (member (object-id o) solved)   ;; already solved
		   o
		   (let* ((dm (list-remove dm i))
			  (columns (min-cover-column dm)))
		    (when (object-solution o)
		     (panic "resolving a unique object~"))
		    (if columns
			(begin
			 (set! solved (cons (object-id o) solved))
			 (update-object-solution o (generate-solution columns rm i object-groups)))
			o))))  ;; cannot be solved
	      dms g (map-n identity (length g)))))
	   object-groups))
	 (new-solved-objects (set-difference (fast-join new-object-groups)
					     (fast-join object-groups)))
	 (new-object-groups
	  (remove-duplicates
	   (append (map list new-solved-objects) object-groups))))
   (if (equal? new-object-groups object-groups)
       (map pick-solution (group-by object-id (fast-join new-object-groups)))
       (loop new-object-groups))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; robot movement ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define *vonmises-kappa* 3)
(define *distance-sigma* 2)
(define *score-threshold* -2)
(define *vonmises-eps* 1e-20)
(define *1d-smooth-kernel* '(0.15 0.7 0.15))
(define *1d-difference-kernel* '(-1 0 1))


(define (fold-polynomial x coeffs)
 (let loop ((s 0) (c (reverse coeffs)))
  (if (null? c)
      s
      (loop (* x (+ s (first c))) (rest c)))))

(define (log-bessel0 kappa)
 (let ((ax (sqrt (sqr kappa))))
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

(define (haonan-log-von-mises v mean kappa)
 (unless (and (> kappa 0.0))
 	      ;; (and (>= mean (- pi)) (<= mean pi))
 	      ;; (and (>= v (- pi)) (<= v pi)))
  (format #t "~a ~a ~a~%" v mean kappa)
  (panic "log-radial") (abort))
 (let ((x (- v mean)))
  (- (* kappa (cos x)) log-two-pi (log-bessel0 kappa))))

(define (log-gaussian x sigma)
 (- (+ (/ (sqr x) (* 2 (sqr sigma))) (* 0.5 log-two-pi) (log sigma))))

;;;;;;;;
;;  p1 <--- p2
;;;;;;;;
(define (angle-between p1 p2)
 (atan (- (second p1) (second p2))
       (- (first p1) (first p2))))

(define-structure word name part-of-speech arguments-n arguments feature-distributions)

(define (object-class-f distribution)
 (lambda (k)
  (unless (and (>= k 0) (< k (length distribution)))
   (panic "object-class-f error"))
  (log (list-ref distribution k))))

(define (orientation-f miu kappa)
 (lambda (theta) (haonan-log-von-mises theta miu kappa)))

(define (distance-f sigma)
 (lambda (x) (log-gaussian x sigma)))

(define (add x y)
 (if (number? x) (+ x y) (map + x y)))

(define (minus x y)
 (if (number? x) (- x y) (map - x y)))

(define (times x k)
 (if (number? x)
     (* x k)
     (vector->list (k*v k (list->vector x)))))

(define (haonan-truncate x a b)
 (if (< x a) a (if (> x b) b x)))

(define (symmetric-point xy xy0)
 (minus (times xy0 2) xy))

(define (norm v)
  (distance (list->vector v) (make-vector (length v) 0)))

(define (angle-between-vectors v1 v2)
 (acos (haonan-truncate (/ (reduce + (map * v1 v2) 0) (norm v1) (norm v2)) -1 1)))

(define (convolve-trace trace kernel)
 (when (zero? (modulo (length kernel) 2))
  (panic "kernel size must be odd"))
 (if (>= (quotient (length kernel) 2) (length trace))
     trace  ;; do nothing
     (let* ((kernel-size (quotient (length kernel) 2))
	    ;; symmetric padding the trace
	    (padded-trace (append (reverse (map-n (lambda (j)
						   (symmetric-point (list-ref trace (+ j 1))
								    (first trace))) kernel-size))
				  trace
				  (map-n (lambda (j)
					  (symmetric-point (list-ref (reverse trace) (+ j 1))
							   (last trace))) kernel-size))))
      (map-n
       (lambda (i)
	(reduce add (map times (sublist padded-trace i (+ i (length kernel))) kernel) #f))
       (length trace)))))

(define (point->line-distance p a b c)
 (/ (abs (+ (* a (first p)) (* b (second p)) c))
    (sqrt (+ (* a a) (* b b)))))

(define (compute-features strace predicate objs)
 (case (word-part-of-speech predicate)
  ((p) (if (= (word-arguments-n predicate) 2)
	   (compute-two-argument-features strace (first objs))
	   (compute-three-argument-features
	    strace (first objs) (second objs))))
  ((n) (compute-one-argument-features (first objs)))
  (else (fuck-up))))

;; strace is smoothed trace
(define (compute-two-argument-features strace obj)
 (let* ((robot-obj-orientation
	 (map (lambda (robot)
	       (quantize-angle
		(angle-between robot (object-xy obj)))) strace))
	(robot-obj-distance
	 (map (lambda (robot) (distance (list->vector robot)
					(list->vector (object-xy obj)))) strace))
	(robot-direction (convolve-trace strace *1d-difference-kernel*)))
  (transpose-list-of-lists
   (if (equal? (length strace) 1) ;; changed by dan
       (list robot-obj-orientation
	     robot-obj-distance)
       (list robot-obj-orientation
	     robot-obj-distance
	     (map quantize-angle
		  (map angle-between-vectors
		       robot-direction
		       (map (lambda (robot) (minus (object-xy obj) robot)) strace))))))))

(define (compute-three-argument-features strace obj1 obj2)
 (let ((robot-obj-orientation-diff
	(map (lambda (robot)
	      (quantize-angle
	       (angle-between-vectors (minus (object-xy obj1) robot)
				      (minus robot (object-xy obj2))))) strace))
       (obj-obj-distance
	(map-n (const (distance (list->vector (object-xy obj1))
				(list->vector (object-xy obj2)))) (length strace))))
  (transpose-list-of-lists
   (list robot-obj-orientation-diff
	 obj-obj-distance))))

(define (compute-one-argument-features obj)
 (list (list (position (object-name obj) *object-names*))))

(define (group-intervals predicated-trace)
 (let loop ((current-predicate '())
	    (remaining predicated-trace)
	    (intervals '())
	    (start -1)
	    (cnt -1)
	    (accumulated-score 0))
  (if (null? remaining)
      (reverse (cons (list current-predicate
			   (/ accumulated-score (+ (- cnt start) 1))
			   (list start cnt))
		     intervals))
      (if (equal? current-predicate (second (first remaining)))
	  (loop current-predicate (rest remaining) intervals start
		(+ cnt 1) (+ accumulated-score (first (first remaining))))
	  (loop (second (first remaining)) (rest remaining)
		(if (>= start 0)
		    (cons (list current-predicate
				(/ accumulated-score (+ (- cnt start) 1))
				(list start cnt))
			  intervals)
		    intervals)
		(+ cnt 1) (+ cnt 1) (first (first remaining)))))))

(define (compute-intervals-multiple strace predicates objects)
 (let* ((objects (sort (resolve-ambiguity objects) < object-id))
	(predicate-object-pairs
	 (map (lambda (o)
	       (let* ((o-pairs (remove-if-not (lambda (pair) (member o pair))
					      (all-pairs objects)))
		      (two-argument-predicates
		       (remove-if-not (lambda (p) (= (word-arguments-n p) 2))
				      predicates))
		      (three-argument-predicates
		       (set-difference predicates two-argument-predicates)))
		(append (map (lambda (p) (list (list o) p)) two-argument-predicates)
			(fast-join (map (lambda (os)
				    (map (lambda (p) (list os p)) three-argument-predicates))
				   o-pairs))))) objects))
	(score-matrices
	 (map (lambda (g)
	       (map (lambda (pair)
		     (let ((features (compute-features strace (second pair) (first pair))))
		      ;(convolve-trace
		      (map (lambda (f)
			     (score-per-frame (second pair) f)) features)
		     ;;  *1d-smooth-kernel*)
		     ))
		    g))
	      predicate-object-pairs)))
  (map
   (lambda (gs gp)
    (let* ((score-matrix-t (transpose-list-of-lists gs))
	   (max-scores (map maximum score-matrix-t))
	   (max-predicates (map (lambda (s row) (list-ref gp (position s row)))
				max-scores score-matrix-t)))
     (group-intervals (zip max-scores max-predicates))))
   score-matrices predicate-object-pairs)))

(define (merge-intervals intervals)
 (let loop ((merged '())
	    (current-interval '(()))
	    (remaining intervals))
  (if (null? remaining)
      (reverse (if (null? (first current-interval))
		   merged
		   (cons current-interval merged)))
      (if (equal? (first current-interval)
		  (first (first remaining)))
	  (loop merged (list (first current-interval)
			     ;; (let ((len1 (+ (- (second (third current-interval))
			     ;; 		       (first (third current-interval))) 1))
			     ;; 	   (len2 (+ (- (second (third (first remaining)))
			     ;; 		       (first (third (first remaining)))) 1)))
			     ;;   (/ (+ (* len1 (second current-interval))
			     ;; 	     (* len2 (second (first remaining))))
			     ;; 	  (+ len1 len2)))
			     (average-cost (list current-interval (first remaining)))
			     (list (first (third current-interval))
				   (second (third (first remaining)))))
		(rest remaining))
	  (loop (if (null? (first current-interval))
		    merged
		    (cons current-interval merged))
		(first remaining) (rest remaining))))))

(define (average-cost intervals)
 (/ (map-reduce + 0 (lambda (i)
		     (* (second i) (+ 1 (- (second (third i))
					   (first (third i)))))) intervals)
    (+ 1 (- (second (third (last intervals)))
	    (first (third (first intervals)))))))

(define (spatial-adjacent? ws w)
 (define (spatial-index w)
  (position (string-downcase (symbol->string (word-name w)))
	    *directions*))
 (let ((ps (map spatial-index ws))
       (p (spatial-index w))
       (len (length *directions*)))
  (and (every identity ps) p
       (or (and (= (length ps) 1) (or (= 1 (modulo (- p (first ps)) len))
			              (= 3 (modulo (- p (first ps)) len))))
	   (and (> (length ps) 1) (= (modulo (- (second ps) (first ps)) len)
				     (modulo (- p (last ps)) len)))))))

(define (merge-spatial-relations intervals k)
 (let loop ((merged '())
	    (waiting-list '())
	    (remaining
	     (append intervals
		     (list (list (list '()
				       (make-word 'dummy #f #f #f #f))
				 #f #f)))))
  (if (null? remaining)
      (reverse merged)
      (if (or (null? waiting-list)
	      (not (spatial-adjacent? (map (o second first) (reverse waiting-list))
				      (second (first (first remaining))))))
	  (if (>= (length waiting-list) k)
	      (loop (cons ;; we decide whether 'aroud or 'past according to the
		          ;; length of waiting-list and the scores
		          (let ((name (if (or (> (length waiting-list) 3)
					      (and (= (length waiting-list) 3)
						   (< (list-variance (map second waiting-list))
						      (* 0.04 (sqr *distance-sigma*)))))
					  'around
					  'past)))
			   (list (list (first (first (first waiting-list)))
				       (make-word name 'p 2 '() #f))
				 (average-cost (reverse waiting-list))
				 (list (first (third (last waiting-list)))
				       (second (third (first waiting-list)))
				       )))
			  merged)
		    (list (first remaining))
		    (rest remaining))
	      (loop (append waiting-list merged) (list (first remaining))
		    (rest remaining)))
	  (loop merged (cons (first remaining) waiting-list) (rest remaining))))))
		    
(define (haonan-generate-sentence trace predicates objects delta)
 (generate-sentence-from-intervals (compute-intervals-multiple trace predicates objects)
				   delta))

(define (generate-sentence-from-intervals intervals-multiple delta)
;; (pp intervals-multiple) (newline)
 (let loop ((intervals-multiple
	     (map (lambda (ints)
		   ;; remove small (possibly noisy intervals) and merge
		   (remove-if
		    (lambda (i) (< (second i) *score-threshold*))
		    (merge-spatial-relations
		      (merge-intervals
		       (remove-if (lambda (i)
				  (< (+ 1 (- (second (third i))
					     (first (third i)))) delta))
				  ints))
		      3)))
		  intervals-multiple))
	    (sentence "the robot")
	    (idle? #t))
  ;;(when idle? (pp intervals-multiple) (newline))
  (if (every null? intervals-multiple)
      ;; remove the first "then" and the last comma
      (if idle?
	  (string-append sentence " does nothing.")
	  (let* ((words-set (pregexp-split " " sentence))
		 (first-then (position "then" words-set)))
	   (pregexp-replace*
	    "," 
	    (string-join " " (append (but-last (list-remove words-set first-then))
				     (list (pregexp-replace "," (last words-set) ""))))
	    "")))
      (let* ((intervals-multiple (remove-if null? intervals-multiple))
	     (candidate-intervals (map first intervals-multiple))
	     (minimum-end (minimum (map (o second third) candidate-intervals)))
	     (candidate-intervals
	      (map (lambda (i)
		    (list i (<= (first (third i)) minimum-end)))
		   candidate-intervals))
	     (intersected-intervals
	      (map first (remove-if-not second candidate-intervals)))
	     ;; here we should merge some events
	     ;; if the predicate is the same word (e.g., to-the-left-of)
	     ;; we pick the highest score one
	     (intersected-intervals
	      (sort
	       (let ((sorted (sort intersected-intervals > second)))
		(if (and (>= (length sorted) 2)
			 (> (second (second sorted))
			    (- (second (first sorted)) (* 0.4 (sqr *distance-sigma*)))))
		    (take 2 sorted)
		    (take-if-possible 1 sorted)))	       
	       < (o first third)))     ;; begins earlier, generated earlier
	     (phrases
	      (map (lambda (i)
		    (let ((p (second (first i)))
			  (objects (map render-object (first (first i)))))
		     (if (= (word-arguments-n p) 3)
			 (string-append (string-downcase (symbol->string (word-name p))) " "
					(first objects) " and " (second objects))
			 (string-append (string-downcase (symbol->string (word-name p))) " "
					(first objects)))))
		   intersected-intervals)))
       (when (null? intersected-intervals) (fuck-up))
       (loop (map (lambda (i ci)
		   (if (second ci) (remove (first ci) i) i))
		  intervals-multiple candidate-intervals)
	     (string-append sentence " then went " (string-join " and " phrases) ",")
	     #f)))))
   
(define *hand-models*
 ;;; features
 ;; two arguments
 ;; 1. object-anchor orientation
 ;; 2. object-anchor distance
 ;; 3. angle between robot direction and robot-anchor orientation
 ;; three arguments
 ;; 1. difference of object-anchor orientations
 ;; 2. object-object distance
 (let ((dummy-orientation (orientation-f 0 *vonmises-eps*)))
  (list (make-word 'left-of 'p 2 '()
		   (list (orientation-f PI *vonmises-kappa*)
			 (distance-f *distance-sigma*)
			 dummy-orientation))
	(make-word 'right-of 'p 2 '()
		   (list (orientation-f 0 *vonmises-kappa*)
			 (distance-f *distance-sigma*)
			 dummy-orientation))
	(make-word 'in-front-of 'p 2 '()
		   (list (orientation-f (- (/ PI 2)) *vonmises-kappa*)
			 (distance-f *distance-sigma*)
			 dummy-orientation))
	(make-word 'behind 'p 2 '()
		   (list (orientation-f (/ PI 2) *vonmises-kappa*)
			 (distance-f *distance-sigma*)
			 dummy-orientation))
	(make-word 'towards 'p 2 '()
		   (list dummy-orientation
			 (distance-f *distance-sigma*)
			 (orientation-f 0 *vonmises-kappa*)))
	(make-word 'away-from 'p 2 '()
		   (list dummy-orientation
			 (distance-f *distance-sigma*)
			 (orientation-f PI *vonmises-kappa*)))	
	(make-word 'between 'p 3 '()
		   (list (orientation-f 0 *vonmises-kappa*)
			 (distance-f *distance-sigma*)))
	)))

(define (score-per-frame model features)
 (reduce + (map (lambda (feat dist-f) (dist-f feat))
		features
		(word-feature-distributions model)) #f))

;;; begin learning.sc
(define *mappings* (read-object-from-file (format #f "/home/~a/darpa-collaboration/robot-nsf-proposal/mappings.sc"  (getenv "USER"))));;"mappings.sc"))

(define *dummy-output-p* (log .1))
(define soft-minus-infinity -500)
(define *eps* 1e-30)
(define *angle-bins-n* 16)
(define *angle-bin-width* (/ two-pi *angle-bins-n*))

(define (sparse-array key-values n)
 (let ((array (map-n (const 0) n)))
  (for-each (lambda (key-value)
	     (set! array (list-replace array (first key-value) (second key-value))))
	    key-values)
  array))

(define *models-to-learn*
 ;;; features
 ;; two arguments
 ;; 1. object-anchor orientation
 ;; 2. object-anchor distance
 ;; 3. angle between robot direction and robot-anchor orientation
 ;; one argument
 ;; object class index
 (let ((dummy-orientation (map-n (const (/ 1 *angle-bins-n*)) *angle-bins-n*)))
  (list (make-word 'left-of 'p 2 '()
		   (list (object-class-f (sparse-array '((6 0.1) (7 0.4) (8 0.4) (9 0.1)) *angle-bins-n*))
			 (distance-f *distance-sigma*)
			 (object-class-f dummy-orientation)))
	(make-word 'right-of 'p 2 '()
		   (list (object-class-f (sparse-array '((0 0.4) (1 0.1) (14 0.1) (15 0.4)) *angle-bins-n*))
			 (distance-f *distance-sigma*)
			 (object-class-f dummy-orientation)))
	(make-word 'in-front-of 'p 2 '()
		   (list (object-class-f (sparse-array '((11 0.4) (12 0.4) (10 0.1) (13 0.1)) *angle-bins-n*))
			 (distance-f *distance-sigma*)
			 (object-class-f dummy-orientation)))
	(make-word 'behind 'p 2 '()
		   (list (object-class-f (sparse-array '((3 0.4) (4 0.4) (2 0.1) (5 0.1)) *angle-bins-n*))
			 (distance-f *distance-sigma*)
			 (object-class-f dummy-orientation)))
	(make-word 'towards 'p 2 '()
		   (list (object-class-f dummy-orientation)
			 (distance-f *distance-sigma*)
			 (object-class-f (sparse-array '((0 0.4) (1 0.1) (14 0.1) (15 0.4)) *angle-bins-n*))))
	(make-word 'away-from 'p 2 '()
		   (list (object-class-f dummy-orientation)
			 (distance-f *distance-sigma*)
			 (object-class-f (sparse-array '((6 0.1) (7 0.4) (8 0.4) (9 0.1)) *angle-bins-n*))))
	(make-word 'table 'n 1 '()
		   (list (object-class-f (sparse-array `((,(position "table" *object-names*) 1))
						       (length *object-names*)))))
	(make-word 'chair 'n 1 '()
		   (list (object-class-f (sparse-array `((,(position "chair" *object-names*) 1))
						       (length *object-names*)))))
	(make-word 'box 'n 1 '()
		   (list (object-class-f (sparse-array `((,(position "box" *object-names*) 1))
						       (length *object-names*)))))		   
	;; (make-word 'ball 'n 1 '()
	;; 	   (list (object-class-f (sparse-array `((,(position "ball" *object-names*) 1))
	;; 					       (length *object-names*)))))
	
	(make-word 'bucket 'n 1 '()
		   (list (object-class-f (sparse-array `((,(position "bucket" *object-names*) 1))
						       (length *object-names*)))))
	(make-word 'cone 'n 1 '()
		   (list (object-class-f (sparse-array `((,(position "cone" *object-names*) 1))
						       (length *object-names*)))))
	(make-word 'bag 'n 1 '()
		   (list (object-class-f (sparse-array `((,(position "bag" *object-names*) 1))
						       (length *object-names*)))))
	(make-word 'stool 'n 1 '()
		   (list (object-class-f (sparse-array `((,(position "stool" *object-names*) 1))
						       (length *object-names*))))))))
(define (quantize-angle theta)
 (define (make-right-range alpha)
  (cond
   ((> alpha two-pi) (make-right-range (- alpha two-pi)))
   ((< alpha 0) (make-right-range (+ alpha two-pi)))
   (else alpha)))
 (quotient (make-right-range theta) *angle-bin-width*))
	
(define (object-instantiations->object-structs objects)
 (map-indexed
  (lambda (o i)
   (make-object i
		(pregexp-replace* "the-" (string-downcase (symbol->string (first o))) "")
		(vector->list (second o))
		#f))
  objects))

(define (haonan-smooth-max-chks-2 a b t)
 (/ (+ (sqrt (+ (sqr (- a b)) (sqr t))) a b) 2))

(define (haonan-smooth-min-chks-2 a b t)
 (- (haonan-smooth-max-chks-2 (- a) (- b) t)))

(define (smooth-add-exp e1 e2)
 (let* ((t 1e-5)
	(e-max (haonan-smooth-max-chks-2 e1 e2 t))
	(e-min (haonan-smooth-min-chks-2 e1 e2 t)))
  (cond ((nan? e-max) (fuck-up))   ;; assume that no -inf
	((> (- e-max e-min) 30) e-max)
	(else (+ (log (+ 1.0 (exp (- e-min e-max)))) e-max)))))

;; a trace-predicate is in the following format:
;; ((left-of) (behind right-of) (away-from))
;; each group happens simutanuously: left-of, then behind and right-of, then away-from
;; each predicate should have been already instantiated with argument-to-reference mapping
(define-structure trace-predicate predicates-groups)

(define (find-model-with-name name models)
 (let ((model (find-if (lambda (m)
			(equal? (pregexp-replace* "the-" (string-downcase (symbol->string name)) "")
				(string-downcase (symbol->string (word-name m)))))
		       models)))
  (unless model
   (display name) (newline)
   (fuck-up))
  model))

;; structure is SHALLOW copied; we have to make a new one
(define (update-model-arguments model arguments)
 (make-word (word-name model)
	    (word-part-of-speech model)
	    (word-arguments-n model)
	    arguments
	    (word-feature-distributions model)))

(define (update-model-distributions model distributions)
 (make-word (word-name model)
	    (word-part-of-speech model)
	    (word-arguments-n model)
	    (word-arguments model)
	    distributions))

(define (my-linked-references linked-references)
 (let* ((robot-references (remove-if-not
			   (lambda (r) (equal? (first r) 'robot))
			   (first linked-references)))
	(other-references (set-difference (first linked-references) robot-references))
	(robot-numbers (map second robot-references))
	(compute-phase (lambda (m) (- (length (remove-if (lambda (n) (> n m)) robot-numbers)) 1)))
	(predicate-names (append other-references (second linked-references)))
	(phases (map (lambda (p) (map compute-phase (rest p))) predicate-names)))
  (map (lambda (p phrs)
	`(,(first p) ,(maximum phrs) ,@(map (lambda (m phr)
					     (if (member m robot-numbers) 0 (- m phr))) (rest p) phrs)))
       predicate-names phases)))

(define (memorize-all-mappings n m)
 (let ((mapping (find-if (lambda (e) (equal? (first e) (list n m))) *mappings*)))
  (if (not mapping)
      (let* ((nm (all-values (map-n (lambda _ (an-integer-between 0 (- m 1))) n)))
	     (new-mappings (cons (list (list n m) nm) *mappings*)))
       (write-object-to-file new-mappings "mappings.sc")
       (set! *mappings* new-mappings)
       nm)
      (second mapping))))
    
;;;;
;; sentence-trace-score: evaluate the score of a trace-sentence pair
;; INPUT:
;;     trace            - robot's trace, a list of xy coordinates
;;     sentence         - a plain sentence that describes the trace
;;     objects          - object instances in the floor plan
;;     models           - whole set of words to be learned, with parameters initialized
;; OUTPUT:
;;     a single log-space score
;;;;
(define (sentence-trace-score trace sentence objects models)
 (let* ((predicate-names
	 (my-linked-references
	  (parsed-sentence->linked-references (parse-sentence sentence))))
	(sequence-info (map second predicate-names))
	(predicates
	 (map (lambda (p)
	       (let ((references (rest (rest p)))
		     (model (find-model-with-name (first p) models)))
		(unless (= (length references) (word-arguments-n model)) (fuck-up))
		(update-model-arguments model references)))
	      predicate-names)))
  (parsed-sentence-trace-score
   trace
   (maximum (remove-if symbol? (fast-join predicate-names)))
   predicates
   sequence-info
   objects)))

;; TODO: deal with noncontinuous function when using AD
(define (parsed-sentence-trace-score trace references-n predicates sequence-info objects)
 (map-reduce
  smooth-add-exp
  soft-minus-infinity
  (lambda (mapping)
   ;; the overall hmm score for a single possible reference-to-object mapping
   (let* ((oreferences (map (lambda (i) (list-ref objects i)) mapping))
	  (robot-spatials-grouped
	   (map (lambda (g) (map first g))
		(group-by second
			  (sort 
			   (remove-if-not
			    (lambda (ps)
			     (and (equal? 'p (word-part-of-speech (first ps)))
				  (some zero? (word-arguments (first ps)))))
			    (zip predicates sequence-info))
			   < second))))
	  (stationary-predicates
	   (set-difference predicates (fast-join robot-spatials-grouped))))
    (if (some
	 (lambda (sp)
	  (let ((objs (map (lambda (i)
			    (list-ref oreferences (- i 1)))
			   (word-arguments sp))))
	   (not (= (length (remove-duplicates objs))
		   (length objs)))))
	 stationary-predicates)
	soft-minus-infinity
	(+ (/
	    (map-reduce
	    +
	    0
	    (lambda (sp)
	     (let ((objs (map (lambda (i)
			       (list-ref oreferences (- i 1)))
			      (word-arguments sp))))
	      (score-per-frame
	       sp
	       (first
		(if (= (length objs) 1)
		    (compute-features '() sp objs)
		    (compute-features (map object-xy (take 1 objs)) sp (rest objs)))))))
	    stationary-predicates)
	    1);; single-frame score for stationary predicates
	   (/ (trace-spatial-score trace
				   oreferences
				   robot-spatials-grouped)
	      (length trace))))))
  (memorize-all-mappings references-n (length objects))))

(define (trace-spatial-score trace oreferences robot-spatials-grouped)
 (let* ((dummy-states-n (+ (length robot-spatials-grouped) 1))
	(states-n (- (* 2 dummy-states-n) 1))
	(two-argument-features-multiple
	 (map (lambda (o)
	       (list (list o) (list->vector (compute-two-argument-features trace o))))
	      oreferences))
	(three-argument-features-multiple
	 (map (lambda (os)
	       (list os (list->vector (compute-three-argument-features
				       trace (first os) (second os)))))
	      (all-pairs oreferences))))
  (if (null? trace)
      minus-infinity
      (let loop ((alphas (map-n (lambda (q)
				 (if (zero? q)
				     *dummy-output-p*
				     soft-minus-infinity)) states-n))
		 (remaining-trace (rest trace))
		 (t 1))
       (if (null? remaining-trace)
	   ;; the state can only end up with (states-n - 1)
	   (smooth-add-exp (last alphas) (last (but-last alphas)))
	   (loop (map-n
		  (lambda (q)
		   (let ((output-p
			  (if (even? q)
			      *dummy-output-p*
			      (map-reduce
			       + 0 (lambda (p)
				    (score-per-frame
				     p
				     (vector-ref 
				      (second
				       (find-if (lambda (f)
						 (set-equal?
						  (first f)
						  (map (lambda (i) (list-ref oreferences (- i 1)))
						       ;; assume that arguments start with 0 (robot)
						       (rest (word-arguments p)))))
						(if (= (word-arguments-n p) 2)
						    two-argument-features-multiple
						    three-argument-features-multiple)))
				      t)))
			       (list-ref robot-spatials-grouped (quotient q 2))))))
		    (+ output-p
		       (if (positive? q)
			   (smooth-add-exp (list-ref alphas q)
					   (list-ref alphas (- q 1)))
			   (list-ref alphas q)))))
		  states-n)
		 (rest remaining-trace)
		 (+ t 1)))))))

;;;;;
;; sentence-trace-score-with-parameters
;; take the current parameters and a training set of triples and compute
;; the overall score on the whole set
;; INPUTS:
;;     parameters        - a flat list of all the parameters, consisting of:
;;                         object-parameters (#objects*#objects)
;;                         distance-sigma (1)
;;                         preposition-parameters (#preps*4)
;;                         all those that must be positive are in log space; others are in linear space
;;                         the order of the parameters should be the same as in *models-to-learn*
;;     triples           - a list of triples, each one has (objects-in-plane, sentence, trace)
;; OUTPUT:
;; a single score in log space
(define (sentence-trace-score-with-parameters parameters triples)
 (let* ((objects-n (length *object-names*))
	(prep-n (- (length *models-to-learn*) objects-n))
	(_ (unless (= (length parameters)
		      (+ (* objects-n objects-n) 1 (* prep-n 2 *angle-bins-n*)))
	    (panic "length of parameters wrong")))
	(object-distributions-multiple
	 (split-n objects-n (take (* objects-n objects-n) parameters)))
	(sigma (list-ref parameters (* objects-n objects-n)))
	(prep-distributions-multiple
	 (split-n (* 2 *angle-bins-n*) (drop (+ (* objects-n objects-n) 1) parameters))))
  (map-reduce
   +
   0
   (lambda (triple)
    (let ((objects-in-plane (object-instantiations->object-structs (first triple)))
	  (sentence (second triple))
	  (trace (map vector->list (vector->list (third triple))))
	  (models (map (lambda (m ps)
			(if (equal? (word-part-of-speech m) 'p)
			    (update-model-distributions
			     m (list (object-class-f (take *angle-bins-n* ps))
				     (distance-f sigma)
				     (object-class-f (drop *angle-bins-n* ps))))
			    (update-model-distributions
			     m (list (object-class-f ps)))))
		       *models-to-learn*
		       (append prep-distributions-multiple
			       object-distributions-multiple))))
     (sentence-trace-score trace sentence objects-in-plane models)))
   triples)))

(define (randomise-parameters)
 (let ((object-distributions-multiple
	(map-n (lambda _ (map-n (lambda _ (random-real))
				(length *object-names*)))
	       (length *object-names*)))
       (sigma (* (random-real) 4))
       (prep-distributions-multiple
	(map-n (lambda _
		(map-n (lambda _ (random-real)) (* 2 *angle-bins-n*)))
	       (- (length *models-to-learn*)
		  (length *object-names*)))))
  (renormalize-and-soften
   (append (fast-join object-distributions-multiple)
	   (list sigma)
	   (fast-join prep-distributions-multiple)))))

(define (optimal-parameters)
 (let ((dummy-orientation (map-n (const (/ 1 *angle-bins-n*)) *angle-bins-n*)))
  (append
   (list 1 0 0 0 0 0 0
	 0 1 0 0 0 0 0
	 0 0 1 0 0 0 0
	 0 0 0 1 0 0 0
	 0 0 0 0 1 0 0
	 0 0 0 0 0 1 0
	 0 0 0 0 0 0 1)
   (list *distance-sigma*)
   `(0 0 0 0 0 0 0.1 0.4 0.4 0.1 0 0 0 0 0 0
     ,@dummy-orientation
     0.4 0.1 0 0 0 0 0 0 0 0 0 0 0 0 0.1 0.4
     ,@dummy-orientation
     0 0 0 0 0 0 0 0 0 0 0.1 0.4 0.4 0.1 0 0
     ,@dummy-orientation
     0 0 0.1 0.4 0.4 0.1 0 0 0 0 0 0 0 0 0 0
     ,@dummy-orientation
     ,@dummy-orientation
     0.4 0.1 0 0 0 0 0 0 0 0 0 0 0 0 0.1 0.4
     ,@dummy-orientation
     0 0 0 0 0 0 0.1 0.4 0.4 0.1 0 0 0 0 0 0))))
       
(define (renormalize-and-soften parameters)
 (let ((objects-n (length *object-names*)))
  (append (fast-join (map
		 (lambda (dist)
		  (map (lambda (x) (/ (+ x *eps*) (reduce + dist 0))) dist))
		 (split-n objects-n (take (* objects-n objects-n) parameters))))
	  (list (list-ref parameters (* objects-n objects-n)))
	  (fast-join (map
		 (lambda (dist)
		  (map (lambda (x) (/ (+ x *eps*) (reduce + dist 0))) dist))
		 (split-n *angle-bins-n* (drop (+ 1 (* objects-n objects-n)) parameters)))))))	 

(define *loud-parser?* #f)
(define (parser-dtrace s x)
 (if *loud-parser?*
     (dtrace s x)
     x))

(define *subjects* '(the-robot))
(define *dan-verbs* '(went))
(define *one-object-adverb-prepositions*
 '(left-of right-of behind in-front-of around towards away-from past))
(define *one-object-adjective-prepositions*
 '(left-of right-of behind in-front-of))
(define *two-object-adverb-prepositions* '(between))
(define *two-object-adjective-prepositions* '(between))
(define *object-phrases* '(the-table the-chair the-box ;;the-ball
				     the-bucket the-cone the-stool the-bag))
(define *conjunctions* '(and))
(define *temporal-conjunctions* '(then))

(define *connectors* (list 'which-is))

(define *all-words* (append *subjects* *dan-verbs* *one-object-adverb-prepositions* *one-object-adjective-prepositions* *two-object-adverb-prepositions* *two-object-adjective-prepositions* *object-phrases* *conjunctions* *temporal-conjunctions* *connectors*))

(define (parse-sentence sentence)
 (parser-dtrace "parse-sentence returned:"
 (parse-words (string->words sentence *all-words*))))

(define (parse-words words)
 (parser-dtrace "parse-sentence" words)
 (all-values
  (list
   'sentence
   (let* ((subject-and-leftovers (dan-parse-subject words))
	  (predicate-and-leftovers (parse-predicate (second subject-and-leftovers))))
    (when (not (null? (second predicate-and-leftovers))) (fail))
    (list (first subject-and-leftovers)
	  (first predicate-and-leftovers))))))

;; (define (dan-parse-subject words)
;;  (parser-dtrace "dan-parse-subject" words)
;;  (let ((subject (first words)))
;;  (if (member subject *subjects*)
;;      (list (list 'subject subject) (rest words))
;;      (fail))))

;; (define (dan-parse-verb words)
;;  (parser-dtrace "dan-parse-verb" words)
;;  (let ((verb (first words)))
;;   (if (member verb *dan-verbs*)
;;      (list (list 'verb verb) (rest words))
;;      (fail))))

;; (define (dan-parse-temporal-conjunction words)
;;  (parser-dtrace "parse-temp-conj" words)
;;  (let ((temporal-conjunction (first words)))
;;   (if (member temporal-conjunction *temporal-conjunctions*)
;;      (list (list 'temporal-conjunction temporal-conjunction) (rest words))
;;      (fail))))

(define (parse-a-word words category lexicon)
 (parser-dtrace "parse word" (list category words lexicon))
 (parser-dtrace "word-parse returned:"
	 (let ((parsed-word (first words)))
  (if (member parsed-word lexicon)
     (list (list category parsed-word) (rest words))
     (fail)))))

(define (dan-parse-subject words)
 (parse-a-word words 'subject *subjects*))

(define (dan-parse-verb words)
 (parse-a-word words 'verb *dan-verbs*))

(define (parse-noun words)
 (parse-a-word words 'noun *object-phrases*))

(define (dan-parse-temporal-conjunction words)
 (parse-a-word words 'temporal-conjunction *temporal-conjunctions*))

(define (parse-one-object-adverb-preposition words)
 (parse-a-word words 'one-object-adverb-preposition *one-object-adverb-prepositions*))

(define (parse-two-object-adverb-preposition words)
 (parse-a-word words 'two-object-adverb-preposition *two-object-adverb-prepositions*))

(define (parse-one-object-adjective-preposition words)
 (parse-a-word words 'one-object-adjective-preposition *one-object-adjective-prepositions*))

(define (parse-two-object-adjective-preposition words)
 (parse-a-word words 'two-object-adjective-preposition *two-object-adjective-prepositions*))

(define (another-prepositional-phrase? words)
 (and (>= (length words) 2) (member (first words) *conjunctions*)
      (or (member (second words) *one-object-adverb-prepositions*)
	  (member (second words) *two-object-adverb-prepositions*))))

(define (parse-conjunction words)
 (parse-a-word words 'conjunction *conjunctions*))

(define (parse-adjective-phrase words)
 (parser-dtrace "parse-adjective-phrase" words)
 (either
  (let* ((connector-and-words (if (equal? (first words) 'which-is)
				  (list 'which-is (rest words))
				  (fail)))
	 (words (second connector-and-words))
	 (single-object-preposition-and-words
	  (parse-one-object-adjective-preposition words))
	 (preposition (first single-object-preposition-and-words))
	 (words (second single-object-preposition-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase (first object-phrase-and-words))
	 (words (second object-phrase-and-words)))
   (if (and (>= (length words) 2)
	    (equal? (first words) 'and) (equal? (second words) 'which-is))
       (let* ((more-adjective-phrases-and-words (parse-adjective-phrase (rest words)))
	      (more-phrases (first more-adjective-phrases-and-words))
	      (words (second more-adjective-phrases-and-words)))
	(list (list 'adjective-phrase (cons (list preposition object-phrase)
					   (second more-phrases)))
	      words))
       (list (list 'adjective-phrase (list (list preposition object-phrase))) words)))
  (let* ((connector-and-words (if (equal? (first words) 'which-is)
				  (list 'which-is (rest words))
				  (fail)))
	 (words (second connector-and-words))
	 (two-object-preposition-and-words
	  (parse-two-object-adjective-preposition words))
	 (preposition (first two-object-preposition-and-words))
	 (words (second two-object-preposition-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase (first object-phrase-and-words))
	 (words (second object-phrase-and-words))
	 (conjunction-and-words (parse-conjunction words))
	 (conjunction (first conjunction-and-words))
	 (words (second conjunction-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase2 (first object-phrase-and-words))
	 (words (second object-phrase-and-words)))
	 
   (if (and (>= (length words) 2)
	    (equal? (first words) 'and) (equal? (second words) 'which-is))
       (let* ((more-adjective-phrases-and-words (parse-adjective-phrase (rest words)))
	      (more-phrases (first more-adjective-phrases-and-words))
	      (words (second more-adjective-phrases-and-words)))
	(list (list 'adjective-phrase (cons (list preposition object-phrase object-phrase2)
					   (second more-phrases)))
	      words))
       (list (list 'adjective-phrase (list (list preposition object-phrase object-phrase2))) words)))))
	 	 
(define (parse-object-phrase words)
 (parser-dtrace "parse-object-phrase" words)
 ;; no either because we always use the 'which-is if its available
 ;; this is to prevent ambiguity with preposition attachment
(parser-dtrace "parse-object-phrase-returned:"
	(let* ((noun-and-words (parse-noun words))
	 (noun (first noun-and-words))
	 (words (second noun-and-words)))
   (cond
    ((and (>= (length words) 1) (equal? (first words) 'which-is))
     (let* ((adjective-phrase-and-words (parse-adjective-phrase words))
	    (adjective-phrase (first adjective-phrase-and-words))
	    (words (second adjective-phrase-and-words)))
      (list (list 'object-phrase (list noun adjective-phrase)) words)))
    (else
     (list (list 'object-phrase noun) words))))))
	      
(define (parse-prepositional-phrase words)
 (parser-dtrace "parse-prepositional-phrase" words)
 (parser-dtrace "prepositional-phrase-parse returned:"
	 (either
  (let* ((preposition-and-words (parse-one-object-adverb-preposition words))
	 (preposition (first preposition-and-words))
	 (words (second preposition-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase (first object-phrase-and-words))
	 (words (second object-phrase-and-words)))
   (parser-dtrace "in the midst of parsing single-object prepositional phrase" #t)
   (if (parser-dtrace "another prep phrase?" (another-prepositional-phrase? words))
       (let* ((more-prepositional-phrases-and-words (parse-prepositional-phrase (rest words)))
	     (more-prepositional-phrases (parser-dtrace "more-prepositional-phrases:"(first more-prepositional-phrases-and-words)))
	     (words (second more-prepositional-phrases-and-words)))
	(list (cons (list 'prepositional-phrase (list preposition object-phrase))
		    more-prepositional-phrases)
	      words))
       (list (list (list 'prepositional-phrase (list preposition object-phrase))) words)))
  (let* ((preposition-and-words (parse-two-object-adverb-preposition words))
	 (preposition (first preposition-and-words))
	 (words (second preposition-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase1 (first object-phrase-and-words))
	 (words (second object-phrase-and-words))
	 (conjunction-and-words (parse-conjunction words))
	 (conjunction (first conjunction-and-words))
	 (words (second conjunction-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase2 (first object-phrase-and-words))
	 (words (second object-phrase-and-words)))
   (if (another-prepositional-phrase? words)
       (let* ((more-prepositional-phrases-and-words (parse-prepositional-phrase (rest words)))
	     (more-prepositional-phrases (first more-prepositional-phrases-and-words))
	     (words (second more-prepositional-phrases-and-words)))
	(list (cons (list 'prepositional-phrase (list preposition object-phrase1 conjunction object-phrase2))
		    more-prepositional-phrases)
	      words))
       
       (list (list (list 'prepositional-phrase (list preposition object-phrase1 conjunction object-phrase2)))
		     words))))))
  
(define (parse-predicate words)
 (parser-dtrace "parse-predicate" words)
 (parser-dtrace "parse-predicate-returned:"
  (either
   (let* ((verb-and-words (dan-parse-verb words))
	  (verb (first verb-and-words))
	  (words (second verb-and-words))
	  (prepositional-phrase-and-words (parse-prepositional-phrase words))
	  (prepositional-phrase (first prepositional-phrase-and-words))
	  (words (second prepositional-phrase-and-words)))
    (parser-dtrace "in the midst of parsing predicate" words)
    (if (null? words)
	(list (list 'predicate (list (list verb prepositional-phrase))) words)
	(let* ((conjunction-and-words (dan-parse-temporal-conjunction words))
	       (conjunction (first conjunction-and-words))
	       (words (second conjunction-and-words))
	       (predicate-and-words (parse-predicate words))
	       (predicate (first predicate-and-words))
	       (words (second predicate-and-words)))
	 (list (list 'predicate (cons (list verb prepositional-phrase)
				      (second predicate)))
	       words)))))))

(define (string->words string symbols)
;;(parser-dtrace "string->words returned:"
	(let* ((strings (fields string)))
  (let loop ((strings strings))
;;   (parser-dtrace "loop:" strings)
   (if (null? strings)
       '()
       (let ((symbol-and-strings
	      (let loop2 ((word-strings '())
			  (strings strings))
	       ;;(parser-dtrace "loop2:" (list word-strings strings))
	       (if (member (string->symbol (string-upcase (string-join "-" (reverse word-strings)))) symbols)
		   (list (string->symbol (string-upcase (string-join "-" (reverse word-strings)))) strings)
		   (if (null? strings)
		       (list 'bad '())
		       (loop2 (cons (first strings) word-strings) (rest strings)))))))
	(if (null? (second symbol-and-strings))
	    (list (first symbol-and-strings))
	    (cons (first symbol-and-strings) (loop (second symbol-and-strings)))))))))

(define (parsed-object-phrase->linked-references tree modified-object-reference)
 (parser-dtrace "object-phrase function:" (list tree modified-object-reference))
 (parser-dtrace "object-phrase function returned:"
	 (let adjective-loop ((tree tree)
		      (references '())
		      (current-reference modified-object-reference)
		      (links '()))
  (if (null? tree)
      (list references links current-reference)
      (if (equal? (first (second (second (first tree)))) 'noun)
      (let* ((adjective (second (first (first tree))))
	     (noun (second (second (second (first tree))))))
       (parser-dtrace "we have a unmodified object:" (first tree))
       (parser-dtrace "adj noun" (list adjective noun))
       (adjective-loop (rest tree)
		       (cons (list noun (+ current-reference 1)) references)
		       (+ current-reference 1)
		       (cons (list adjective
				   modified-object-reference
				   (+ current-reference 1))
			     links)))
      (let* ((adjective (second (first (first tree))))
	     (noun (second (first (second (second (first tree))))))
	     (references (cons (list noun (+ current-reference 1)) references))
	     (links (cons (list adjective
				modified-object-reference
				(+ current-reference 1))
			  links))
	     (current-reference (+ current-reference 1))
	     (new-references-and-links
		  (parsed-object-phrase->linked-references
		   (second (second (second (second (first tree)))))
		   current-reference)))
       (parser-dtrace "object branch 2" (list adjective noun))
       (adjective-loop (rest tree)
		       (append references (first new-references-and-links))
		       (+ (third new-references-and-links) 1)
		       (append links (second new-references-and-links)))))))))
      	    
(define (parsed-prepositional-phrase->linked-references tree robot-reference)
 (parser-dtrace "prep-phrase function:" (list tree robot-reference))
 (let adverb-loop ((tree tree)
		   (references '())
		   (current-reference robot-reference)
		   (links '()))
  (if (null? tree)
      (list references links current-reference)
      (if (equal? (first (second (second (second (first tree))))) 'noun)
	  (let* ((preposition (second (first (second (first tree)))))
		 (noun (second (second(second (second (first tree))))))
		 (current-reference (+ current-reference 1))
		 (references (cons (list noun
					 current-reference)
				   references))
		 (links (cons (list preposition
				    robot-reference
				    current-reference)
			      links)))
	   (adverb-loop (rest tree)
			references
			current-reference
			links))
	  (let* ((preposition (second (first (second (first tree)))))
		 (noun (second (first (second(second (second (first tree)))))))
		 (current-reference (+ current-reference 1))
		 (references (cons (list noun
					 current-reference)
				   references))
		 (links (cons (list preposition
				    robot-reference
				    current-reference)
			      links))
		 (new-references-and-links
		  (parsed-object-phrase->linked-references
		   (second (second (second(second (second
						   (first tree))))))
		   current-reference)))
	   (adverb-loop (rest tree)
			(append references (first new-references-and-links))
			(third new-references-and-links)
			(append links (second new-references-and-links))))))))

(define (simplify-parse-tree parse-tree)
 ;;(pp parse-tree)
 (map (lambda (predicate)
       (map (lambda (adverbial-phrase)
	     adverbial-phrase)
	    (second predicate)))
      (second (second(second (first parse-tree))))))

(define (parsed-sentence->linked-references parse)
 (let* ((tree (simplify-parse-tree parse)))
  (let time-loop ((tree tree)
		  (references (list ))
		  (current-reference 0)
		  (links (list ))
		  (phase 0))
   (if (null? tree)
       (list references links)
       (let* ((references (cons (list 'robot current-reference phase) references))
	      (new-references-and-links
	       (parsed-prepositional-phrase->linked-references
		(first tree) current-reference)))    
	(time-loop (rest tree)
		   (append references (first new-references-and-links))
		   (+ (third new-references-and-links) 1)
		   (append links (second new-references-and-links))
		   (+ phase 1)))))))

;;; begin learning optimization


(define *iteration-count* 0)
(define (optimize-word-parameters f x tol1 tol2)
 (let ((g (gradient-R f)))
  (let loop ((x x)
	     (gx (magnitude (g x)))
	     (c (f x))
	     (step .1)
	     (prev-dx (map-n-vector (lambda (i) 0) (vector-length x))))
   (when (= (modulo *iteration-count* 1) 0) (dtrace "x c gx step" (list (primal* x) c gx step))
	 (dtrace ""(plot-parameters x))
	 )
   (set! *iteration-count* (+ *iteration-count* 1))
   (if (or (> c tol1)
	   (< gx tol2)
	   (< step 1e-12)
	   (< (* step gx) 1e-5))
       x
       (let* ((gx (g x))
	      (dx (k*v step (v+ gx (k*v 0.00 prev-dx))))
	      (x-prime (list->vector (renormalize-and-soften (vector->list (v+ x dx)))))
	      (c-prime (f x-prime)))
	;;(trace-dtrace "mgx" (magnitude gx))
	;;(trace-dtrace "step:" step)
	(if (> c-prime c)
	    (loop x-prime (magnitude gx) c-prime (* step 1.5) dx)
	    (loop x (magnitude gx) c (* step .5) (k*v .5 prev-dx))))))))

(define (plot-parameters params)
 (let* ((position-means (map-vector (lambda (v) (x v))
				    (shape-matrix (subvector params (+ (* 7 7) 1)
							     (vector-length params))
						  4)))
	(position-kappas (map-vector (lambda (v) (y v))
				    (shape-matrix (subvector params (+ (* 7 7) 1)
							     (vector-length params))
						  4)))
	(direction-means (map-vector (lambda (v) (vector-ref v 2))
				    (shape-matrix (subvector params (+ (* 7 7) 1)
							     (vector-length params))
						  4)))
	(direction-kappas (map-vector (lambda (v) (vector-ref v 3))
				     (shape-matrix (subvector params (+ (* 7 7) 1)
							      (vector-length params))
						   4))))
	
 
(list position-means
      direction-means
      position-kappas
      direction-kappas)))

(define (optimize-word-parameters-nnstyle f x tol1 tol2)
 (let ((g (gradient-R f)))
  (let loop ((x x)
	     (gx (magnitude (g x)))
	     (c (f x))
	     (phase 'noun)
	     (noun-step .1)
	     (prep-step .1)
	     (prev-dx (map-n-vector (lambda (i) 0) (vector-length x))))
   (dtrace "phase:" phase)
   (when (= (modulo *iteration-count* 5) 0) (dtrace "x c gx noun-step prep-step" (list (primal* x) c gx noun-step prep-step))
	 )
   (set! *iteration-count* (+ *iteration-count* 1))
   (dtrace ""(plot-parameters x))
   (if (or (> c tol1)
	   (< gx tol2)
	   ;;(< step 1e-12)
	   (and (< (* noun-step gx) 1e-5) (< (* prep-step gx) 1e-5)))
       x
       (let* ((gx (g x))
	      (dx (v+ gx (k*v 0.00 prev-dx)))
	      (deltax
	       (if (equal? phase 'noun)
		   (k*v noun-step (vector-append
				   (subvector dx 0 (* 7 7))
				   (make-vector (+ (* 6 4) 1) 0)))
		   (k*v prep-step (vector-append
				   (make-vector (* 7 7) 0)
				   (subvector dx (* 7 7)
					      (vector-length dx))))))
	      
	      (x-prime (list->vector (renormalize-and-soften
				      (vector->list (v+ x deltax)))))
	      (c-prime (f x-prime)))
;;	(dtrace "lengths:" (list (vector-length dx) (vector-length deltax)))
;;	(dtrace "dx" dx)
;;	(dtrace "deltax" deltax)
	;;(trace-dtrace "mgx" (magnitude gx))
	;;(trace-dtrace "step:" step)
	(if (> c-prime c)
	    (loop x-prime
		  (magnitude gx)
		  c-prime
		  (if (equal? phase 'noun)
		      'prep
		      'noun)
		  (if (equal? phase 'noun)
		      (* noun-step 1.5)
		      noun-step)
		  (if (equal? phase 'prep)
		      (* prep-step 1.5)
		      prep-step)
		  dx)
	    (loop x
		  (magnitude gx)
		  c
		  (if (equal? phase 'noun)
		      'prep
		      'noun)
		  (if (equal? phase 'noun)
		      (* noun-step .5)
		      noun-step)
		  (if (equal? phase 'prep)
		      (* prep-step .5)
		      prep-step)
		  (k*v .5 prev-dx)
		  )))))))

(define (dan-gt-discrete-distribution-update distribution gradient d)
 (dtrace "normalized:"
	 ;;(normalize
	  (map-vector
	   (lambda (x g) (* x (+ g d)))
	   distribution
	   gradient)));)

(define (update-parameters g x)
 (let* ((nouns (subvector x 0 (* 7 7)))
	(sigma (vector-ref x (* 7 7)))
	(preps (subvector x (+ (* 7 7) 1) (vector-length x)))
	(noun-ds (shape-matrix nouns 7))
	(prep-ds (shape-matrix preps 32))
	(noun-gs (shape-matrix (subvector g 0 (* 7 7)) 7))
	(prep-gs (shape-matrix (subvector g (+ (* 7 7) 1) (vector-length x)) 32))
	(updated-noun-ds
	 (map-vector
	  (lambda (d g)
	   (dan-gt-discrete-distribution-update d g .1))
	  noun-ds
	  noun-gs))
	(updated-prep-ds
	 (map-vector
	  (lambda (d g)
	   (dan-gt-discrete-distribution-update d g .1))
	  prep-ds
	  prep-gs)))
  (vector-append (reduce-vector vector-append updated-noun-ds `#())
		 (vector sigma)
		 (reduce-vector vector-append updated-prep-ds `#()))))
	

(define (optimize-word-parameters-fletcher-reeves f x tol1 tol2 mode)
 (let ((g (if (equal? mode 'r)
	      (gradient-R f)
	      (gradient-F f))))
  (let loop ((x x)
	     (gx (magnitude (g x)))
	     (c (f x))
	     (step .1)
	     (prev-gx #f));;(map-n-vector (lambda (i) 0) (vector-length x))))
   (when (= (modulo *iteration-count* 1) 0)
    (dtrace "x c gx step" (list (primal* x) c gx step))
    (dtrace "score:" c)
	;; (dtrace ""(plot-parameters x))
	 )
   (set! *iteration-count* (+ *iteration-count* 1))
   (if (or (> c tol1)
	   (< gx tol2)
	   (< step 1e-12)
	   (< (* step gx) 1e-15))
       x
       (let* ((gx (g x))
	      (beta (if prev-gx
			(/ (magnitude-squared gx) (magnitude-squared prev-gx))
			0))
	      (dx (if #f;;prev-gx
		      (k*v step (v+ gx (k*v beta prev-gx)))
		      (k*v step gx)))
	      ;(x-prime (list->vector (renormalize-and-soften (vector->list (v+ x dx)))))
	      (x-prime (list->vector
			(renormalize-and-soften
			 (vector->list (update-parameters dx x)))))
	      (c-prime (f x-prime)))
	;;(trace-dtrace "mgx" (magnitude gx))
	;;(trace-dtrace "step:" step)
	(if (> c-prime c)
	    (loop x-prime (magnitude gx) c-prime (* step 1.3) gx)
	    (loop x (magnitude gx) c (* step .5) #f;; (if prev-gx (k*v .5 prev-gx)
						   ;;   prev-gx)
		  )))))))


(define (linspace min max n)
 (let ((numbers (enumerate n))
       (range (- max min)))
  (map (lambda (number)
	(+ (* (/ number (- n 1))
	      range)
	   min))
       numbers)))

(define (plot-score-vs-ith-param i params triples min max N)
 (let* ((ps (linspace min max N))
	(params-list (map-n
		      (lambda (j)
		       (vector-append (subvector params 0 i)
				      (vector (list-ref ps j))
				      (subvector params (+ i 1) (vector-length params))))
		      N))
	(scores (map (lambda (params)
		      (sentence-trace-score-with-parameters (vector->list params) triples))
		     params-list)))
  (matlab "figure")
  (plot-lines-in-matlab (list ps) (list scores) (list "'foo'") "-")))
		     
 (define (visualize-angle-distribution d)
  (let* ((angles (reduce append (map-n (lambda (i) (list (* i (/ pi (* 8)))
							 (* (+ i .5) (/ pi (* 8)))
							 (* (+ i 1) (/ pi (* 8)))))
				       (vector-length d)) '()))
	 (distances (reduce append (map (lambda (b) (list b b b)) (vector->list d)) '()))
	 (xs (map (lambda (a p) (* p (cos a))) angles distances))
	 (ys (map (lambda (a p) (* p (sin a))) angles distances)))
   (matlab "figure")
   (plot-lines-in-matlab (list (cons (last xs) xs)) (list (cons (last ys) ys)) (list "'foo'") ".-")
   (matlab "axis([-1 1 -1 1])")))

(define (visualize-word-params p)
 (for-each-indexed
  (lambda (w i)
   (visualize-angle-distribution
    (subvector p (+ 49 1 (* 32 i)) (+ 49 1 16 (* 32 i))))

   (matlab (format #f "title('~a')" w))
   (matlab (format #f "saveas(gcf,'~a','png')"w)))
  (list "left-p" "right-p" "front-p" "behind-p" "towards-p" "away-p"))
 (for-each-indexed
  (lambda (w i)
   (visualize-angle-distribution
    (subvector p (+ 49 1 16 (* 32 i)) (+ 49 1 16 16 (* 32 i))))
   (matlab (format #f "title('~a')" w))
   (matlab (format #f "saveas(gcf,'~a','png')"w)))
  (list "left-v" "right-v" "front-v" "behind-v" "towards-v" "away-v")))


(define (fit-model-to-angular-histogram h)
 (scheme->matlab! "a" (map-n (lambda (i) (* (+ i .5) (/ pi 8))) (vector-length h)))
 (scheme->matlab! "w" h)
 (matlab (format #f"addpath /home/~a/darpa-collaboration/robot-nsf-proposal/" (getenv "USER")))
 (dtrace "" (matlab "a"))
 (dtrace "" (matlab "w"))
 (dtrace "" (matlab "mu=circmean(a,w,2)"))
 (dtrace "" (matlab "kappa=circ_kappa(a,w)"))
 (list (matrix-ref  (matlab-get-variable "mu") 0 0) (matrix-ref (matlab-get-variable "kappa") 0 0)))


(define (duplicate-bins d)
 (let* ((p1 (subvector d 0 (exact-round (/ (vector-length d) 2)))))
  (vector-append p1 (list->vector (reverse (vector->list p1))))))

(define (visualize-word-params-as-von-mises p)
 (for-each-indexed
  (lambda (w i)
   (visualize-angle-distribution-as-von-mises
    (subvector p (+ 49 1 (* 32 i)) (+ 49 1 16 (* 32 i))))
   (matlab (format #f "title('~a')" w))
   (matlab (format #f "saveas(gcf,'~a','png')"w)))
  (list "left-p" "right-p" "front-p" "behind-p" "towards-p" "away-p"))
 (for-each-indexed
  (lambda (w i)
   (visualize-angle-distribution-as-von-mises
    (duplicate-bins (subvector p (+ 49 1 16 (* 32 i)) (+ 49 1 16 16 (* 32 i)))))
   (matlab (format #f "title('~a')" w))
   (matlab (format #f "saveas(gcf,'~a','png')"w)))
  (list "left-v" "right-v" "front-v" "behind-v" "towards-v" "away-v")))

(define (visualize-angle-distribution-as-von-mises d)
  (let* ((mu-kappa (fit-model-to-angular-histogram d))
	 (angles (linspace minus-pi pi 75))
	 (xs (map (lambda (a)  (* (exp (log-von-mises a (first mu-kappa) (second mu-kappa)))
				   (cos a))) angles))
	 (ys (map (lambda (a) (* (exp (log-von-mises a (first mu-kappa) (second mu-kappa)))
				   (sin a))) angles))
	 (xs2 (reduce append (map (lambda (x) (list x 0)) xs) '()))
	 (ys2 (reduce append (map (lambda (y) (list y 0)) ys) '())))
   (matlab "figure")
   (plot-lines-in-matlab (list (cons (last xs2) xs2)) (list (cons (last ys2) ys2)) (list "'foo'") "-")
   (matlab "axis([-1.5 1.5 -1.5 1.5])")
   ;; (matlab "axis equal")
   ))

(define (visualize-angle-distribution-as-von-mises-with-raster d size rotation)
 (let* ((mu-kappa (fit-model-to-angular-histogram d))
	(image (imlib-create-image size size))
	(max (exp (log-von-mises 0 0 (second mu-kappa)))))
  (for-each-n
   (lambda (x)
    (for-each-n
     (lambda (y)
      (let* ((angle (- (atan (- (- y (/ size 2)))  (- x (/ size 2))) rotation))
	     (g (/ (* 255 (exp (log-von-mises angle (first mu-kappa) (second mu-kappa))))
		   max)))
      (imlib:draw-pixel image x y (vector g g g))))
     size))
    size)
 image))

(define (visualize-word-params-as-von-mises-with-raster p size)
(list (map-indexed
  (lambda (w i)
   (imlib:save
    (visualize-angle-distribution-as-von-mises-with-raster
     (subvector p (+ 49 1 (* 32 i)) (+ 49 1 16 (* 32 i)))
     size
     0)
    (format #f "~a.png" w)))
  (list "left-p" "right-p" "front-p" "behind-p" "towards-p" "away-p"))
 (map-indexed
  (lambda (w i)
   (imlib:save
    (visualize-angle-distribution-as-von-mises-with-raster
     (duplicate-bins (subvector p (+ 49 1 16 (* 32 i)) (+ 49 1 16 16 (* 32 i))))
     size
     half-pi)
    (format #f "~a.png" w)))
  (list "left-v" "right-v" "front-v" "behind-v" "towards-v" "away-v"))))

(define (learn-from-dataset dataset mode)
 (let* ((f (lambda (params) (sentence-trace-score-with-parameters (vector->list params) dataset)))
	(params (list->vector (randomise-parameters)))
	(newparams (optimize-word-parameters-fletcher-reeves f params 1000 1e-15 mode)))
  (visualize-word-params newparams)
  newparams))