
;;This is the test data
(define asm-full (read-object-from-file "asm_20150702.sc"))
(define asm-tiny (submatrix asm-full 0 0 4 4))
(define asm-small (submatrix asm-full 0 0 8 8))
(define asm-half (submatrix asm-full 0 0 21 21))
(define asm-12 (submatrix asm-full 0 0 12 12))
(define asm-16 (submatrix asm-full 0 0 16 16))

(define tables-tiny (build-table-matrix asm-tiny 4))
(define tables-small (build-table-matrix asm-small 6))
(define tables-full (build-table-matrix asm-full 8))
(define tables-half (build-table-matrix asm-half 8))
(define tables-12 (build-table-matrix asm-12 7))
(define tables-16 (build-table-matrix asm-16 8))

(define (run-4)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-tiny 4))))
(define (run-8)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-small 8))))
(define (run-12)
 (time-thunk "~as " (lambda ()
;;		     (find-labels infinity '(0 ) tables-12 12)
		     (find-labels (score '(0 1 2 3 4 5 6 0 1 2 3 4) tables-12)
					 '(0 ) tables-12 12))))
(define (run-16)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-16 16))))
(define (run-21)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-half 21))))
(define (run-43)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-full 43))))


;; ;;functions for branch and bound

;; (define (build-table sim num-labels)
;;  (map-n-vector
;;   (lambda (i)
;;    (map-n-vector
;;     (lambda (j)
;;      (if (= i j)
;; 	 (* -1 (log sim))
;; 	 (* -1 (log (- 1 sim)))))
;;     num-labels))
;;    num-labels))

;; (define (build-table-matrix sim-matrix num-labels)
;;  (let ((r (matrix-rows sim-matrix))
;;        (c (matrix-columns sim-matrix)))
;;   (map-n-vector
;;    (lambda (i)
;;     (map-n-vector
;;      (lambda (j)
;;       (let* ((sim1 (matrix-ref sim-matrix i j))
;; 	     (sim2 (matrix-ref sim-matrix j i))
;; 	     (sim-value (/ (+ sim1 sim2) 2.0)))
;;        (list i j (build-table sim-value num-labels))))
;;      c))
;;    r)))


;; (define (minimum-vector v)
;;  (let ((m infinity)
;;        (len (vector-length v)))
;;   (let loop
;;     ((i 0)
;;      (m m))
;;    (if (>= i len)
;;        m
;;        (loop (+ i 1)
;; 	     (min m (vector-ref v i)))))))

;; (define (maximum-vector v)
;;  (let ((m minus-infinity)
;;        (len (vector-length v)))
;;   (let loop
;;     ((i 0)
;;      (m m))
;;    (if (>= i len)
;;        m
;;        (loop (+ i 1)
;; 	     (max m (vector-ref v i)))))))


;; (define (best-possible labels table-matrix num-peaks)
;;  (let ((labels (append labels
;; 		       (map-n (lambda (i) #f) (- num-peaks (length labels))))))
;;   (reduce +
;; 	 (join 
;; 	  (map-indexed
;; 	   (lambda (label1 i)
;; 	    (map-indexed
;; 	     (lambda (label2 j)
;; 		    (if (< i j) ;;so we're not adding everything twice
;; 			(cond ((and label1 label2)
;; 			       (matrix-ref 
;; 				(third (matrix-ref table-matrix i j))
;; 				label1 label2))
;; 			      ((and (not label1) (not label2))
;; 			       (minimum-vector
;; 				(map-vector
;; 				 (lambda (x)
;; 				  (minimum-vector x))
;; 				 (third (matrix-ref table-matrix i j)))))
;; 			      (else
;; 			       (minimum-vector
;; 				(vector-ref
;; 				 (third (matrix-ref table-matrix i j))
;; 				 label1))
;; 			       ))
;; 			      0)) labels)) labels))
;; 	 0)))

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

;; (define (find-labels best labels table-matrix num-peaks)
;;  (let* ((v (length labels))
;; 	(num-labels (vector-length (third (matrix-ref table-matrix 0 0)))))
;;   (if (= v num-peaks)
;;       (list (score labels table-matrix) labels) ;;done
;;       (let ((bars
;;       	     (removeq
;;       	      #f
;; 	      (let loop ((i 0)
;; 			 (best best))
;; 	       (if (< i num-labels)
;; 		   (let* ((new-labels (append labels (list i)))
;; 			  (new-best
;; 			   (best-possible new-labels table-matrix num-peaks)))
;; 		    (if (< new-best best)
;; 			(let* ((answer
;; 				(find-labels best
;; 					     new-labels
;; 					     table-matrix
;; 					     num-peaks))
;; 			       (new-best
;; 				(if (< (first answer) best)
;; 				    (first answer)
;; 				    best)))
;; 			 (cons answer
;; 			       (loop (+ i 1) new-best)))
;; 			(begin
;; 			 ;;(dtrace "path abandoned" #f)
;; 			 (loop (+ i 1) best))))
;; 		   '()
;; 		   )))))
;;        (if (null? bars)
;; 	   (list infinity '())
;; 	   (first (sort bars < first)))))))
	

