(define (hausdorf-distance d)
 (lambda (p q)
  (map-reduce
   max
   minus-infinity
   (lambda (p) (map-reduce min infinity (lambda (q) (d p q)) q)) p)))

(define (chamfer-distance d)
 (lambda (p q)
  (map-reduce
   + 0 (lambda (p) (map-reduce min infinity (lambda (q) (d p q)) q)) p)))

(define (complete-linkage-distance d)
 (lambda (p q)
  (map-reduce
   max
   minus-infinity
   (lambda (p) (map-reduce max minus-infinity (lambda (q) (d p q)) q)) p)))

(define (single-linkage-distance d)
 (lambda (p q)
  (map-reduce
   min
   infinity
   (lambda (p) (map-reduce min infinity (lambda (q) (d p q)) q)) p)))

(define (average-linkage-distance d)
 (lambda (p q)
  (/ (map-reduce + 0 (lambda (p) (map-reduce + 0 (lambda (q) (d p q)) q)) p)
     (* (length p) (length q)))))

(define (minimum-average-distance d)
 (lambda (p q)
  (map-reduce
   min infinity (lambda (p) (map-reduce + 0 (lambda (q) (d p q)) q)) p)))

(define (point-with-minimum-average-distance d)
 (lambda (p q)
  (let loop ((p (rest p))
	     (b (first p))
	     (c (map-reduce + 0 (lambda (q) (d (first p) q)) q)))
   (if (null? p)
       b
       (let ((c1 (map-reduce + 0 (lambda (q) (d (first p) q)) q)))
	(if (< c1 c)
	    (loop (rest p) (first p) c1)
	    (loop (rest p) b c)))))))

(define (invert-distance d) (lambda (p q) (d q p)))

(define (bidirectional d s)
 (lambda (p q) (s (d p q) ((invert-distance d) p q))))

(define (medoid d)
 (lambda (ps) ((point-with-minimum-average-distance d) ps ps)))

(define (k-medoids medoid d p n)
 (let* ((ps (random-partition-of-size n p)) (medoids (map medoid ps)))
  (let loop ((ps ps)
	     (medoids medoids)
	     (cost
	      (map-reduce
	       +
	       0
	       (lambda (p medoid) (map-reduce + 0 (lambda (p) (d p medoid)) p))
	       ps
	       medoids)))
   (let* ((pis (map (lambda (p)
		     (let ((ds (map (lambda (medoid) (d p medoid)) medoids)))
		      (list p (positionv (reduce min ds infinity) ds))))
		    p))
	  (ps1 (removeq
		'()
		(map-n
		 (lambda (i)
		  (map first
		       (remove-if-not (lambda (pi) (= (second pi) i)) pis)))
		 (length medoids))))
	  (medoids1 (map medoid ps1))
	  (cost1
	   (map-reduce
	    +
	    0
	    (lambda (p medoid) (map-reduce + 0 (lambda (p) (d p medoid)) p))
	    ps1
	    medoids1)))
    (if (< cost1 cost) (loop ps1 medoids1 cost1) ps)))))
