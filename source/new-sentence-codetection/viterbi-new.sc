(define (viterbi frames-boxes-scores frames-boxes-boxes-coherence)
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



(define (read-and-sort-matlab-proposals filename)
 (start-matlab!)
 (matlab (format #f "load ~a" filename))
 (let* ((proposals (transpose (matlab-get-variable "proposal_boxes")))
	(sorted-proposals (map (lambda (frame-boxes)
				(sort (vector->list frame-boxes)
				>
				(lambda (b) (vector-ref b 4))))
			       (vector->list proposals))))
  sorted-proposals))


(define (read-annotated-boxes filename)
 (read-object-from-file filename))
	
(define (scott-box->voc4 box)
 (let* ((x1 (x box))
       (y1 (y box))
       (x2 (+ x1 (z box)))
       (y2 (+ y1 (vector-ref box 3))))	   
 (make-voc4-detection x1 y1 x2 y2 #f #f #f #f #f #f)))

(define (gui-box->voc4 box)
 (let* ((tl (y box))
	(br (z box))
	(x1 (x tl))
	(y1 (y tl))
	(x2 (x br))
	(y2 (y br)))
   (make-voc4-detection x1 y1 x2 y2 #f #f #f #f #f #f)))


(define (compute-rank-of-overlapping-proposals proposals-file gui-file threshold)
 (let* ((proposals (read-and-sort-matlab-proposals proposals-file))
	(gui-boxes (read-annotated-boxes gui-file))
	(frames-proposal-voc4s (rest (map (lambda (boxes)
				     (map scott-box->voc4 boxes))
				    proposals)))
	(gui-voc4s (map gui-box->voc4 (vector->list gui-boxes))))
  (map (lambda (proposals box)
	(let* ((overlaps
		(map (lambda (p)
		      (voc4-detection-intersection-divided-by-union
		       p box))
		     proposals))
	       (best (maximum overlaps))
	       (p (position best overlaps)))
	 (let loop
	   ((overlaps overlaps)
	    (i 0))
	  (if (null? overlaps)
	      #f
	      (if (> (first overlaps) threshold)
		  i
		  (loop (rest overlaps) (+ i 1)))))))	       
       frames-proposal-voc4s
       gui-voc4s)))



;;; this is probably the thing you want to use
(define (pixel-and-height->world p camera->world intrinsics height)
 (let* ((camera-world (transform-point-3d camera->world (vector 0 0 0)))
	(foo (dtrace "camera-world" camera-world))
	(fx  (matrix-ref intrinsics 0 0))
	(fy  (matrix-ref intrinsics 1 1))
	(px  (/ (- (x p) (matrix-ref intrinsics 0 2)) fx))
	(py  (/ (- (y p) (matrix-ref intrinsics 1 2)) fy))
	(pixel-world  (transform-point-3d camera->world (vector px py 1)))
	(bar (dtrace "pixel-world" pixel-world))
	(dxyz (v- pixel-world camera-world))
	(baz (dtrace "dxyz" dxyz))
	(l (/ (- height (z camera-world)) (z dxyz))))
  (v+ camera-world (k*v l dxyz))));;(v*s dxyz l))))



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
(dtrace "bottom-left bottom-right top-left"
	(list world-bottom-left world-bottom-right world-top-left))))



