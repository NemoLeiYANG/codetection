(define (viterbi-boxes frames-boxes-scores frames-boxes-boxes-coherence)
 ;;; the first element in  frames-boxes-boxes-coherence is coherence between
 ;;; the boxes in the second and first frame
 ;;; these are organized as lists of the coherence for all boxes in the previous frame against the current frame
 ;;; i.e (x (second (first frames-boxes-boxes-coherence)))
;;;          is the coherence betweem the second box in the second frame and the first box in the first frame
 (let loop ((frames-boxes-scores (rest frames-boxes-scores))
	    (frames-boxes-boxes-coherence frames-boxes-boxes-coherence)
	    (optimal-paths (map-indexed (lambda (s i) (list i)) (first frames-boxes-scores)))
	    (optimal-path-scores (map (lambda (s) s) (first frames-boxes-scores))))
  (if (null? frames-boxes-scores)
      (let* ((optimal-path-index (position (maximum optimal-path-scores) optimal-path-scores)))
       (list (list-ref optimal-path-scores optimal-path-index)
	     (reverse (list-ref optimal-paths optimal-path-index))))
      (let* ((boxes-scores (first frames-boxes-scores))
	     (coherence (first frames-boxes-boxes-coherence))
	     (optimal-scores-and-paths
	      (map (lambda (box-score box-coherence i)
		    (let* ((scores-ending-here
			    (map (lambda (path-score path)
				  (+ path-score box-score (vector-ref box-coherence (first path))))
				 optimal-path-scores
				 optimal-paths))
			   (best-score (maximum scores-ending-here))
			   (best-index (position  best-score scores-ending-here))			   
			   (new-best-path (cons i (list-ref optimal-paths best-index))))
		     (list new-best-path best-score)))
		   boxes-scores
		   coherence
		   (enumerate (length boxes-scores))))
	     (optimal-path-scores (map second optimal-scores-and-paths))
	     (optimal-paths (map first optimal-scores-and-paths)))
       (loop (rest frames-boxes-scores)
	     (rest frames-boxes-boxes-coherence)
	     optimal-paths
	     optimal-path-scores)))))
	     