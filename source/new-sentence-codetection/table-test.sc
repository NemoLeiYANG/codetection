(define (build-table sim num-labels)
 (dtrace "sim" sim)
 (map-n-vector
  (lambda (i)
   (map-n-vector
    (lambda (j)
     (dtrace "if output"
     (if (= i j)
	 (- (sigmoid sim 0.8 10))
	 (- (sigmoid (- 1 sim) 0.8 10))
	 ;;old way
	 ;; (* -1 (log sim))
	 ;; (* -1 (log (- 1 sim)))
	 ))
     )
    num-labels))
   num-labels))

(define (build-table-matrix sim-matrix num-labels)
 (dtrace "sim-matrix" sim-matrix)
 (let ((r (matrix-rows sim-matrix))
       (c (matrix-columns sim-matrix)))
  (map-n-vector
   (lambda (i)
    (map-n-vector
     (lambda (j)
      (let* ((sim1 (matrix-ref sim-matrix i j))
	     (sim2 (matrix-ref sim-matrix j i))
	     (sim-value (/ (+ sim1 sim2) 2.0)))
       (list (min (- (sigmoid sim-value 0.8 10))
		  (- (sigmoid (- 1 sim-value) 0.8 10)))
;; (min (-(log sim-value)) (-(log (- 1 sim-value))))
	     0
	     (build-table sim-value num-labels))))
     c))
   r)))