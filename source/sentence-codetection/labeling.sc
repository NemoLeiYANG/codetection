
;;This is the test data
;;(define asm-full (read-object-from-file "asm_20150702.sc"))
(define asm-full (read-object-from-file "asm_20150727a.sc"))
(define asm-tiny (submatrix asm-full 0 0 4 4))
(define asm-small (submatrix asm-full 0 0 8 8))
(define asm-half (submatrix asm-full 0 0 21 21))
(define asm-12 (submatrix asm-full 0 0 12 12))
(define asm-16 (submatrix asm-full 0 0 16 16))
(define asm-25 (submatrix asm-full 0 0 25 25))
(define asm-30 (submatrix asm-full 0 0 30 30))
(define asm-30-1 (submatrix asm-full 1 1 30 30))
(define asm-30-2 (submatrix asm-full 2 2 30 30))
(define asm-30-3 (submatrix asm-full 3 3 30 30))
(define asm-30-4 (submatrix asm-full 4 4 30 30))
(define asm-30-5 (submatrix asm-full 5 5 30 30))
(define asm-30-6 (submatrix asm-full 6 6 30 30))
(define asm-30-7 (submatrix asm-full 7 7 30 30))
(define asm-30-8 (submatrix asm-full 8 8 30 30))
(define asm-30-9 (submatrix asm-full 9 9 30 30))
(define asm-30-10 (submatrix asm-full 10 10 30 30))
(define asm-30-11 (submatrix asm-full 11 11 30 30))
(define asm-30-12 (submatrix asm-full 12 12 30 30))
(define asm-30b (submatrix asm-full 13 13 30 30))
(define asm-35 (submatrix asm-full 0 0 35 35))
(define asm-35b (submatrix asm-full 8 8 35 35))

(define tables-tiny (build-table-matrix asm-tiny 4))
(define tables-small (build-table-matrix asm-small 6))
(define tables-full (build-table-matrix asm-full 8))
(define tables-half (build-table-matrix asm-half 8))
(define tables-12 (build-table-matrix asm-12 7))
(define tables-16 (build-table-matrix asm-16 8))
(define tables-25 (build-table-matrix asm-25 8))
(define tables-30 (build-table-matrix asm-30 8))
(define tables-35 (build-table-matrix asm-35 8))

(define tables-tiny-a (build-table-matrix asm-tiny 8))
(define tables-small-a (build-table-matrix asm-small 12))
(define tables-full-a (build-table-matrix asm-full 16))
(define tables-half-a (build-table-matrix asm-half 16))
(define tables-12-a (build-table-matrix asm-12 14))
(define tables-16-a (build-table-matrix asm-16 16))
(define tables-25-a (build-table-matrix asm-25 16))
(define tables-30-a (build-table-matrix asm-30 16))
(define tables-30-a-1 (build-table-matrix asm-30-1 16))
(define tables-30-a-2 (build-table-matrix asm-30-2 16))
(define tables-30-a-3 (build-table-matrix asm-30-3 16))
(define tables-30-a-4 (build-table-matrix asm-30-4 16))
(define tables-30-a-5 (build-table-matrix asm-30-5 16))
(define tables-30-a-6 (build-table-matrix asm-30-6 16))
(define tables-30-a-7 (build-table-matrix asm-30-7 16))
(define tables-30-a-8 (build-table-matrix asm-30-8 16))
(define tables-30-a-9 (build-table-matrix asm-30-9 16))
(define tables-30-a-10 (build-table-matrix asm-30-10 16))
(define tables-30-a-11 (build-table-matrix asm-30-11 16))
(define tables-30-a-12 (build-table-matrix asm-30-12 16))
(define tables-30-b (build-table-matrix asm-30b 16))
(define tables-35-a (build-table-matrix asm-35 16))
(define tables-35-b (build-table-matrix asm-35b 16))

(define msv-tiny (compute-max-score-vec tables-tiny 4))
(define msv-tiny-a (compute-max-score-vec tables-tiny-a 4))
(define msv-small (compute-max-score-vec tables-small 8))
(define msv-small-a (compute-max-score-vec tables-small-a 8))
(define msv-full (compute-max-score-vec tables-full 43))
(define msv-full-a (compute-max-score-vec tables-full-a 43))
(define msv-half (compute-max-score-vec tables-half 21))
(define msv-half-a (compute-max-score-vec tables-half-a 21))
(define msv-12 (compute-max-score-vec tables-12 12))
(define msv-12-a (compute-max-score-vec tables-12-a 12))
(define msv-16 (compute-max-score-vec tables-16 16))
(define msv-16-a (compute-max-score-vec tables-16-a 16))
(define msv-25 (compute-max-score-vec tables-25 25))
(define msv-25-a (compute-max-score-vec tables-25-a 25))
(define msv-30 (compute-max-score-vec tables-30 30))
(define msv-30-a (compute-max-score-vec tables-30-a 30))
(define msv-30-a-1 (compute-max-score-vec tables-30-a-1 30))
(define msv-30-a-2 (compute-max-score-vec tables-30-a-2 30))
(define msv-30-a-3 (compute-max-score-vec tables-30-a-3 30))
(define msv-30-a-4 (compute-max-score-vec tables-30-a-4 30))
(define msv-30-a-5 (compute-max-score-vec tables-30-a-5 30))
(define msv-30-a-6 (compute-max-score-vec tables-30-a-6 30))
(define msv-30-a-7 (compute-max-score-vec tables-30-a-7 30))
(define msv-30-a-8 (compute-max-score-vec tables-30-a-8 30))
(define msv-30-a-9 (compute-max-score-vec tables-30-a-9 30))
(define msv-30-a-10 (compute-max-score-vec tables-30-a-10 30))
(define msv-30-a-11 (compute-max-score-vec tables-30-a-11 30))
(define msv-30-a-12 (compute-max-score-vec tables-30-a-12 30))
(define msv-30-b (compute-max-score-vec tables-30-b 30))
(define msv-35 (compute-max-score-vec tables-35 35))
(define msv-35-a (compute-max-score-vec tables-35-a 35))
(define msv-35-b (compute-max-score-vec tables-35-b 35))

(define (run-4)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-tiny 4 0 msv-tiny))))
(define (run-8)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-small 8 0 msv-small))))
(define (run-12)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-12 12 0 msv-12)
		     ;; (find-labels (score '(0 1 2 3 4 5 6 0 1 2 3 4) tables-12)
		     ;; 			 '(0 ) tables-12 12)
		     )))
(define (run-16)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-16 16 0 msv-16))))
(define (run-21)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-half 21 0 msv-half))))
(define (run-25)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-25 25 0 msv-25))))
(define (run-30)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-30 30 0 msv-30))))

(define (run-35)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-35 35 0 msv-35))))

(define (run-43)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-full 43 0 msv-full))))

(define (run-4a)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-tiny-a 4 0 msv-tiny-a))))
(define (run-8a)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-small-a 8 0 msv-small-a))))
(define (run-12a)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-12-a 12 0 msv-12-a)
		     ;; (find-labels (score '(0 1 2 3 4 5 6 0 1 2 3 4) tables-12)
		     ;; 			 '(0 ) tables-12 12)
		     )))
(define (run-16a)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-16-a 16 0 msv-16-a))))
(define (run-21a)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-half-a 21 0 msv-half-a))))
(define (run-25a)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-25-a 25 0 msv-25-a))))
(define (run-30a)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-30-a 30 0 msv-30-a))))

(define (run-30a-1)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-1
				  30
				  0
				  msv-30-a-1))))
(define (run-30a-2)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-2
				  30
				  0
				  msv-30-a-2))))

(define (run-30a-3)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-3
				  30
				  0
				  msv-30-a-3))))

(define (run-30a-4)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-4
				  30
				  0
				  msv-30-a-4))))

(define (run-30a-5)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-5
				  30
				  0
				  msv-30-a-5))))

(define (run-30a-6)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-6
				  30
				  0
				  msv-30-a-6))))

(define (run-30a-7)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-7
				  30
				  0
				  msv-30-a-7))))

(define (run-30a-8)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-8
				  30
				  0
				  msv-30-a-8))))

(define (run-30a-9)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-9
				  30
				  0
				  msv-30-a-9))))

(define (run-30a-10)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-10
				  30
				  0
				  msv-30-a-10))))

(define (run-30a-11)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-11
				  30
				  0
				  msv-30-a-11))))

(define (run-30a-12)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity
				  '(0 )
				  tables-30-a-12
				  30
				  0
				  msv-30-a-12))))

(define (run-30b)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-30-b 30 0 msv-30-b))))

(define (run-35a)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-35-a 35 0 msv-35-a))))

(define (run-35b)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-35-b 35 0 msv-35-b))))


(define (run-43a)
 (time-thunk "~as " (lambda ()
		     (find-labels infinity '(0 ) tables-full-a 43 0 msv-full-a))))


(define (rolling-overlap-30)
 (time-thunk "entire run: ~as "
	     (lambda ()
	      (list
	       (dtrace "run-30a" (run-30a))
	       (dtrace "run-30a-1" (run-30a-1))
	       (dtrace "run-30a-2" (run-30a-2))
	       (dtrace "run-30a-3" (run-30a-3))
	       (dtrace "run-30a-4" (run-30a-4))
	       (dtrace "run-30a-5" (run-30a-5))
	       (dtrace "run-30a-6" (run-30a-6))
	       (dtrace "run-30a-7" (run-30a-7))
	       (dtrace "run-30a-8" (run-30a-8))
	       (dtrace "run-30a-9" (run-30a-9))
	       (dtrace "run-30a-10" (run-30a-10))
	       (dtrace "run-30a-11" (run-30a-11))
	       (dtrace "run-30a-12" (run-30a-12))
	       (dtrace "run-30b" (run-30b))
	       ))))
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
	

