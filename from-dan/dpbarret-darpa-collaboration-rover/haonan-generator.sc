;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; object layout ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define *directions* '("left-of" "front-of" "right-of" "behind"))
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
;;;;  (generate-sentence *trace1* *robot:models* *objects1* 5)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define *trace1* (trace->splines '((0 -2) (2 -2) (3 0) (2 2) (0 2) (-2 5) (1 7)) 100))
(define *objects1* (list (make-object 0 "trash-can" '(1 5) #f)
			(make-object 1 "table" '(2 0) #f)
			(make-object 2 "chair" '(-2 2) #f)))

(define *trace2* (trace->splines '((0 -1) (2 -1) (3 0) (2 1) (0 1) (-4 1)) 100))
(define *objects2* (list (make-object 0 "table" '(-3 0) #f)
			 (make-object 1 "chair" '(-1 0) #f)
			 (make-object 2 "bucket" '(1 0) #f)))

(define *trace3* (trace->splines '((2 0) (1.5 -1.5) (0 -2) (-0.5 -0.5) (-1 0) (-1 4)) 100))
(define *objects3* (list (make-object 0 "table" '(0 0) #f)
			 (make-object 1 "bucket" '(1 0) #f)
			 (make-object 2 "chair" '(0 2) #f)
			 (make-object 3 "stool" '(-2 0) #f)))

(define *trace4* (trace->splines '((1 -5) (1.2 -2.5) (1 0) (0.8 2.5) (1 5)) 30))
(define *objects4* (list (make-object 0 "table" '(0 -2) #f)
			 (make-object 1 "chair" '(0 2) #f)
			 (make-object 2 "trash-can" '(2 4) #f)))

(define *trace5* (trace->splines '((-4 -4) (-3 -3.5) (-2 -2.5) (0 -1) (1 -2) (0 -3)
				   (-1 -2) (1 4) (-2 5) (-4 2) (-5 -0.5)) 150)) 
(define *objects5* (list (make-object 0 "table" '(0 -2) #f)
			 (make-object 1 "chair" '(1 5.5) #f)
			 (make-object 2 "bucket" '(-3 3) #f)))

(define *trace6* (trace->splines '((-3 -2) (-3 0) (-2 4) (0 8) (2 4) (3 0)) 120))
(define *objects6* (list (make-object 0 "table" '(-2 0) #f)
			 (make-object 1 "table" '(2 0) #f)
			 (make-object 2 "chair" '(0 7) #f)))

(load (format #f "/home/~a/darpa-collaboration/pose-retraining/felz-baum-welch-plotting.sc" (getenv "USER")))
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
;; xy1 should be the reference; xy2 should be the object
(define (spatial-location xy1 xy2)
 (if (equal? xy1 xy2)
     0
     (let* ((theta (haonan-angle-between xy1 xy2))
	    (theta (if (< theta (- (/ PI 4)))
		       (+ (* 2.25 PI) theta)
		       (+ (* 0.25 PI) theta))))
      (+ (quotient theta (/ PI 2)) 1))))

(define (compute-relation-matrix g object-groups)
 (map
  (lambda (o)
   (map
    (lambda (reference-g)
     (remove-duplicates
      (remove-if zero?
		 (map
		  (lambda (reference-o)
		   (spatial-location (object-xy reference-o)
				     (object-xy o)))
		  reference-g))))
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
		  (trial-result (map join (zip cover current-trial))))
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
  (and (not (null? (object-sultion o)))
       (object-solution o)))
 (let ((subject (string-append "the " (object-name o))))
  (if (null? (object-solution o))
      subject
      (if (not (object-solution o))
	  subject
	  (let* ((references (sort (object-solution o)
				   (lambda (r1 r2)
				    (if (and (modified? r1)
					     (not modified? r2)) #f #t)) first))
		 (modifiers
		  (join (map (lambda (r)
			      (map (lambda (d)
				    (string-append " which is "
						   (list-ref *directions* (- d 1))
						   " "
						   (render-object (first r))))
				   (second r)))
			     references))))
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
	(solved (map object-id (join (remove-if (lambda (g) (> (length g) 1)) object-groups)))))
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
	 (new-solved-objects (set-difference (join new-object-groups)
					     (join object-groups)))
	 (new-object-groups
	  (remove-duplicates
	   (append (map list new-solved-objects) object-groups))))
   (if (equal? new-object-groups object-groups)
       (map pick-solution (group-by object-id (join new-object-groups)))
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

(define (log-gaussian x sigma)
 (- (+ (/ (sqr x) (* 2 (sqr sigma))) (log sigma))))

;;;;;;;;
;;  p1 <--- p2
;;;;;;;;
(define (haonan-angle-between p1 p2)
 (atan (- (second p1) (second p2))
       (- (first p1) (first p2))))

(define-structure words name part-of-speech arguments feature-distributions)

(define (orientation-f miu kappa)
 (lambda (theta) (log-von-mises theta miu kappa)))

(define (distance-f)
 (lambda (x) (log-gaussian x *distance-sigma*)))

(define (add x y)
 (if (number? x) (+ x y) (map + x y)))

(define (minus x y)
 (if (number? x) (- x y) (map - x y)))

(define (times x k)
 (if (number? x)
     (* x k)
     (vector->list (k*v k (list->vector x)))))

(define (truncate x a b)
 (if (< x a) a (if (> x b) b x)))

(define (symmetric-point xy xy0)
 (minus (times xy0 2) xy))

(define (norm v)
  (distance (list->vector v) (make-vector (length v) 0)))

(define (angle-between-vectors v1 v2)
 (acos (truncate (/ (reduce + (map * v1 v2) 0) (norm v1) (norm v2)) -1 1)))

(define (convolve-trace trace kernel)
 (when (zero? (modulo (length kernel) 2))
  (panic "kernel size must be odd"))
 (when (>= (quotient (length kernel) 2) (length trace))
  (panic "trace is too short"))
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
   (length trace))))

(define (point->line-distance p a b c)
 (/ (abs (+ (* a (first p)) (* b (second p)) c))
    (sqrt (+ (* a a) (* b b)))))

;; strace is smoothed trace
(define (compute-two-point-features strace reference)
 (let* ((robot-reference-orientation
	 (map (lambda (robot) (haonan-angle-between robot reference)) strace))
	(robot-reference-distance
	 (map (lambda (robot) (distance (list->vector robot)
					(list->vector reference))) strace))
	(robot-direction (convolve-trace strace *1d-difference-kernel*))
	(robot-direction-change
	 (cons 0
	       (map (lambda (v1 v2)
		     (angle-between-vectors v1 v2))
		    (rest robot-direction)
		    (but-last robot-direction)))))
  (transpose-list-of-lists
   (list robot-reference-orientation
	 robot-reference-distance
	 (map angle-between-vectors
	      robot-direction
	      (map (lambda (robot) (minus reference robot)) strace))
	 robot-direction-change
	 ))))

(define (compute-three-point-features strace reference1 reference2)
 (let ((robot-reference-orientation-diff
	(map (lambda (robot)
	      (angle-between-vectors (minus reference1 robot)
				     (minus robot reference2))) strace))
       (reference-reference-distance
	(map-n (const (distance (list->vector reference1)
				(list->vector reference2))) (length strace))))
  (transpose-list-of-lists
   (list robot-reference-orientation-diff
	 reference-reference-distance))))

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
 (let* (;;(strace (convolve-trace trace *1d-smooth-kernel*))
	(objects (sort (resolve-ambiguity objects) < object-id))
	(predicate-object-pairs
	 (map (lambda (o)
	       (let* ((o-pairs (remove-if-not (lambda (pair) (member o pair))
					      (all-pairs objects)))
		      (two-argument-predicates
		       (remove-if-not (lambda (p) (= (words-arguments p) 2))
				      predicates))
		      (three-argument-predicates
		       (set-difference predicates two-argument-predicates)))
		(append (map (lambda (p) (list (list o) p)) two-argument-predicates)
			(join (map (lambda (os)
				    (map (lambda (p) (list os p)) three-argument-predicates))
				   o-pairs))))) objects))
	(score-matrices
	 (map (lambda (g)
	       (map (lambda (pair)
		     (let ((features
			    (if (= (words-arguments (second pair)) 2)
				(compute-two-point-features
				 strace (object-xy (first (first pair))))
				(compute-three-point-features
				 strace (object-xy (first (first pair)))
				 (object-xy (second (first pair)))))))
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
  (position (string-downcase (symbol->string (words-name w)))
	    *directions*))
 (let ((ps (map spatial-index ws))
       (p (spatial-index w))
       (len (length *directions*)))
  (and (every identity ps) p
       (or (and (= (length ps) 1) (or (= 1 (modulo (- p (first ps)) len))
			              (= 3 (modulo (- p (first ps)) len))))
	   (and (> (length ps) 1) (= (modulo (- (second ps) (first ps)) len)
				     (modulo (- p (last ps)) len)))))))

;; (merge-spatial-relations (list (list (list '() (make-words 'behind #f #f #f)) 1 '(0 2)) (list (list '() (make-words 'to-the-right-of #f #f #f)) 2 '(3 4)) (list (list '() (make-words 'in-front-of #f #f #f)) 3 '(5 6)) (list (list '() (make-words 'behind #f #f #f)) 1 '(7 10))) 3 'around)
(define (merge-spatial-relations intervals k)
 (let loop ((merged '())
	    (waiting-list '())
	    (remaining
	     (append intervals
		     (list (list (list '()
				       (make-words 'dummy #f #f #f))
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
				       (make-words name 'sp 2 #f))
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
		    
(define (generate-sentence trace predicates objects delta)
 (generate-sentence-from-intervals (compute-intervals-multiple trace predicates objects)
				   delta))

(define (generate-sentence-from-intervals intervals-multiple delta)
 (pp intervals-multiple) (newline)
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
  (when idle? (pp intervals-multiple) (newline))
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
		     (if (= (words-arguments p) 3)
			 (string-append (string-downcase (symbol->string (words-name p))) " "
					(first objects) " and " (second objects))
			 (string-append (string-downcase (symbol->string (words-name p))) " "
					(first objects)))))
		   intersected-intervals)))
       (when (null? intersected-intervals) (fuck-up))
       (loop (map (lambda (i ci)
		   (if (second ci) (remove (first ci) i) i))
		  intervals-multiple candidate-intervals)
	     (string-append sentence " then went " (string-join " and " phrases) ",")
	     #f)))))
   
(define *robot:models*
 ;;; features
 ;; two arguments
 ;; 1. object-reference orientation
 ;; 2. object-reference distance
 ;; 3. angle between robot direction and robot-reference orientation
 ;; 4. robot direction change
 ;; three arguments
 ;; 1. difference of object-reference orientations
 ;; 2. reference-reference distance
 (let ((dummy-distribution (orientation-f 0 *vonmises-eps*)))
  (list (make-words 'left-of 'sp 2
		    (list (orientation-f PI *vonmises-kappa*)
			  (distance-f)
			  dummy-distribution
			  dummy-distribution))
	(make-words 'right-of 'sp 2
		    (list (orientation-f 0 *vonmises-kappa*)
			  (distance-f)
			  dummy-distribution
			  dummy-distribution))
	(make-words 'front-of 'sp 2
		    (list (orientation-f (- (/ PI 2)) *vonmises-kappa*)
			  (distance-f)
			  dummy-distribution
			  dummy-distribution))
	(make-words 'behind 'sp 2
		    (list (orientation-f (/ PI 2) *vonmises-kappa*)
			  (distance-f)
			  dummy-distribution
			  dummy-distribution))
	(make-words 'towards 'ap 2
		    (list dummy-distribution
			  (distance-f)
			  (orientation-f 0 *vonmises-kappa*)
			  dummy-distribution))
	(make-words 'away-from 'ap 2
		    (list dummy-distribution
			  (distance-f)
			  (orientation-f PI *vonmises-kappa*)
			  dummy-distribution))
	;; (make-words 'around 'ap 2
	;; 	    (list dummy-distribution
	;; 		  (distance-f)
	;; 		  (orientation-f (/ PI 2) *vonmises-kappa*)
	;; 		  dummy-distribution))
	;; (make-words 'past 'ap 2
	;; 	    (list dummy-distribution
	;; 		  (distance-f)
	;; 		  dummy-distribution
	;; 		  (orientation-f 0 (* 10 *vonmises-kappa*))))
	(make-words 'between 'sp 3
		    (list (orientation-f 0 *vonmises-kappa*)
			  (distance-f))))))

(define (score-per-frame model features)
 (reduce + (map (lambda (dist-f feat) (dist-f feat))
		(words-feature-distributions model)
		features) #f))
 