(define (viterbi initial-state-distribution
                 frames-states-output-log-distributions
                 transition-matrix)
 (let loop ((frames-states-scores
             (list (map (lambda (initial-state-probability state-output-probability)
                         (+ initial-state-probability state-output-probability))
                        initial-state-distribution
                        (first frames-states-output-log-distributions))))
            (frames-states-output-log-distributions (rest frames-states-output-log-distributions))
            (frames-states-sequences (list (map-indexed (lambda (x i) (list i)) transition-matrix)) ))
  (dtrace "frames-states-sequences:" frames-states-sequences)
  (if (null? frames-states-output-log-distributions)
      (list (reverse frames-states-scores) (reverse (map (lambda (x) (map reverse x)) frames-states-sequences)))
      (loop
       (cons (map (lambda (state-output-probability transition-column)
                   (let* ((possible-scores
			   (map (lambda (prev-state-score transition-probability)
				 (+ prev-state-score transition-probability state-output-probability))
				(first frames-states-scores)
				transition-column))
			  (score (maximum possible-scores))
			  (prev-state (position score possible-scores)))
                    score))
                  (first frames-states-output-log-distributions)
                  (transpose-list-of-lists transition-matrix))
             frames-states-scores)
       (rest frames-states-output-log-distributions)
       (cons
        (map (lambda (state-output-probability transition-column state)
	      (let* ((possible-scores
		      (map (lambda (prev-state-score transition-probability)
			    (+ prev-state-score transition-probability state-output-probability))
			   (first frames-states-scores)
			   transition-column))
		     (score (maximum possible-scores))
		     (prev-state (position score possible-scores)))
	       (cons state (list-ref (first frames-states-sequences) prev-state))))
	     (first frames-states-output-log-distributions)
	     (transpose-list-of-lists transition-matrix)
	     (enumerate (length transition-matrix)))
        frames-states-sequences)))))