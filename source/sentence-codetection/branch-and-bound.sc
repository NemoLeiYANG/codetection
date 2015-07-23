;;functions for branch and bound

(define (build-table sim num-labels)
 (map-n-vector
  (lambda (i)
   (map-n-vector
    (lambda (j)
     (if (= i j)
	 (* -1 (log sim))
	 (* -1 (log (- 1 sim)))))
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
       (list (min (-(log sim-value)) (-(log (- 1 sim-value))))
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
				       ;; (let* ((fooA (new-best-possible
				       ;; 		     (new-score subscore
				       ;; 				(append labels
				       ;; 					(list i))
				       ;; 				table-matrix)
				       ;; 		     (append labels (list i))
				       ;; 		     max-score-vec))
				       ;; 	      (fooB (best-possible
				       ;; 		     (append labels (list i))
				       ;; 		     table-matrix
				       ;; 		     num-peaks)))
				       ;; 	(if (> (dtrace "abs" (abs (- fooA fooB))) 0.001)
				       ;; 	    (begin
				       ;; 	     (dtrace "fooA" fooA)
				       ;; 	     (dtrace "fooB" fooB)
				       ;; 	     (dtrace "subscore" subscore)
				       ;; 	     (dtrace "labels" labels)
				       ;; 	     (dtrace "i" i)
				       ;; 	     (fuck-up))
				       ;; 	    fooA))
				       )))
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

