;; **working stuff in scheme to manually compute GM output value**
;; (define frame-data (read-object-from-file "/aux/sbroniko/vader-rover/logs/house-test-12nov15/test-segment/20151202a_top_k_1/frame-data-00.-00..sc"))
;; (define results (read-object-from-file "/aux/sbroniko/vader-rover/logs/house-test-12nov15/test-segment/20151202a_top_k_1/results-00.-00..sc"))
;; (define binary-scores (vector->list (second frame-data)))
;; (define binary-scores-list (map (lambda (b) (vector-ref b 4)) binary-scores))
;; (define unary-scores-list (fourth results))
;; (define log-unary-scores (map (lambda (u) (* -1 (log u))) unary-scores-list))
;; (define log-binary-scores (map (lambda (u) (* -1 (log u))) binary-scores-list))
;; (+ (reduce + log-binary-scores 0) (reduce + log-unary-scores 0))

;; **working stuff in scheme-->need to add to codetection-test.sc run-codetection-with-proposals-similarity**
;; > (load "rendering-code.sc")
;; "rendering-code.sc"
;; > (load "source/new-sentence-codetection/codetection-test.sc")
;; "source/new-sentence-codetection/codetection-test.sc"
;; > (define frame-data (read-object-from-file "/aux/sbroniko/vader-rover/logs/house-test-12nov15/test-segment/20151201b_foo_top_k_10/frame-data-0.6-0.6.sc"))
;; FRAME-DATA
;; > (vector-length (second frame-data))
;; 7900
;; > (define binary-scores (vector->list (second frame-data)))
;; BINARY-SCORES
;; > (length binary-scores)
;; 7900
;; > (define indices (map (lambda (f) (subvector f 0 4)) binary-scores))
;; INDICES
;; > (first indices)
;; #(1. 1. 2. 1.)
;; > (position (vector 1. 1. 2. 9.) indices)
;; 8
;; > (define exact-indices (map (lambda (v) (map-vector exact-round v)) indices))
;; EXACT-INDICES
;; > (first exact-indices)
;; #(1 1 2 1)
;; > (position (vector 1 1 2 9) exact-indices)
;; 8
;; > (define g-list (matrix->list-of-lists (second frame-data)))
;; > (first g-list)
;; (1. 1. 2. 1. 0.9505696892738342)
;; > 



;; (define box-list (first results))
;; (define score-vals (map (lambda 
;; 			    (b scores) (list-ref scores b))
;; 			  box-list 
;; 			  (map (lambda (scores) (append scores (list 0)))
;; 			       f)))


(define (find-binary-scores box-list binary-scores) ;;binary-scores is list of vectors
 (let* ((binary-score-vals (map (lambda (b) (vector-ref b 4)) binary-scores))
	(binary-score-indices
	 (map (lambda (g) (vector->list (map-vector exact-round g)))
	      (map (lambda (f) (subvector f 0 4)) binary-scores)))
	(positions-list  (find-positions-list box-list binary-score-indices)))
  (map (lambda (p) (list-ref binary-score-vals p)) positions-list)
  ))

(define (find-positions-list box-list binary-score-indices)
 (let loop ((box-list box-list)
	    (i 1)
	    (positions '()))
  (if (= 1 (length box-list))
      (reverse positions) ;;done
      (loop (rest box-list)
	    (+ i 1)
	    (cons
	     (position
;;	      (dtrace "index: "
	      (list i (+ 1 (first box-list)) (+ i 1) (+ 1 (second box-list)))
;;		      )
	      binary-score-indices)
	     positions)))))

		     