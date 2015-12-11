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

;;; this is probably the thing you want to use
(define (box-at-height->world-corners x1 y1 x2 y2 camera->world intrinsics height)
 (let* ((camera-world (transform-point-3d camera->world (vector 0 0 0)))
	(fx  (matrix-ref intrinsics 0 0))
	(fy  (matrix-ref intrinsics 1 1))
	(pblx (/ (- x1 (matrix-ref intrinsics 0 2)) fx))
	(pbly  (/ (- y2 (matrix-ref intrinsics 1 2)) fy))
	(pbrx (/ (- x2 (matrix-ref intrinsics 0 2)) fx))
	(pbry  (/ (- y2 (matrix-ref intrinsics 1 2)) fy))
	(ptly  (/ (- y1 (matrix-ref intrinsics 1 2)) fy))
	;;(px  (/ (- (x p) (matrix-ref intrinsics 0 2)) fx))
	;;(py  (/ (- (y p) (matrix-ref intrinsics 1 2)) fy))
	;(pixel-world  (transform-point-3d camera->world (vector px py 1)))
	(bottom-left-pixel-world (transform-point-3d camera->world (vector pblx pbly 1)))
	(bottom-right-pixel-world (transform-point-3d camera->world (vector pbrx pbry 1)))
	(top-left-pixel-world (transform-point-3d camera->world (vector pblx ptly 1)))
	;(dxyz (v- pixel-world camera-world))
	(dxyzbl (v- bottom-left-pixel-world camera-world))
	(dxyzbr (v- bottom-right-pixel-world camera-world))
	(dxyztl (v- top-left-pixel-world camera-world))
	;(l (/ (- height (z camera-world)) (z dxyz)))
	(lbl (/ (- height (z camera-world)) (z dxyzbl)))
	(lbr (/ (- height (z camera-world)) (z dxyzbr)))
	(world-bottom-left (v+ camera-world (k*v lbl dxyzbl)))
	(world-bottom-right (v+ camera-world (k*v lbr dxyzbr)))
	(ltl (/ (- (x world-bottom-left) (x camera-world))
		 (- (x top-left-pixel-world) (x camera-world))))
	(world-top-left (v+ camera-world (k*v ltl dxyztl))))
(dtrace "bottom-left bottom-tight top-left"
	(list world-bottom-left world-bottom-right world-top-left))))

(define (discount-boxes frames-boxes-scores track discount)
 (map (lambda (boxes-scores box)
       (map-indexed
	(lambda (s i)
	 (if (= i box)
	     (- s discount)
	     s))
	boxes-scores))
      frames-boxes-scores
      track))

(define (viterbi-multiple frames-boxes-scores
			  frames-boxes-boxes-coherence
			  num-tracks
			  discount) ;;a SUBTRACTIVE discount 
 (let loop
   ((frames-boxes-scores frames-boxes-scores)
    (i 0)
    (scored-tracks '()))
  (if (= i num-tracks)
      scored-tracks
      (let ((scored-track (viterbi-boxes frames-boxes-scores frames-boxes-boxes-coherence)))
       (loop (discount-boxes frames-boxes-scores (second scored-track) discount)
	     (+ i 1)
	     (cons scored-track scored-tracks))))))
