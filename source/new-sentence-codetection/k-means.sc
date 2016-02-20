(define (k-means vs k)
 (let* ((starting-means (n-random-elements-without-replacement k vs)))
  (let loop ((means starting-means)
	     (assignments
	      (map (lambda (mean)
		    (remove-if-not (lambda (v)
				    (< (distance v mean)
				       (minimum (map (lambda (other-mean)
						      (distance v other-mean))
						     (remove mean starting-means)))))
				   vs))
		   starting-means)))
   (let* ((new-means (map mean-point assignments))
	  (new-assignments
	   (map (lambda (mean)
		 (remove-if-not (lambda (v)
				 (< (distance v mean)
				    (minimum (map (lambda (other-mean)
						   (distance v other-mean))
						  (remove mean new-means)))))
				vs))
		new-means)))
    (if (basically-equal? new-means means)
	new-means
	(loop (dtrace "looping with:" new-means) new-assignments))))))

(define (basically-equal? a b)
 (if (and (list? a) (list? b) (= (length a) (length b)))
     (reduce (lambda (x y) (and x y)) (map basically-equal? a b) #t)
     (if (and (vector? a) (vector? b) (= (vector-length a) (vector-length b)))
	 (reduce-vector (lambda (x y) (and x y)) (map-vector basically-equal? a b) #t)
	 (if (and (number? a) (number? b))
	     (begin
	      ;;(dtrace-if (not (< (abs (- a b)) 1e-10)) "not equal:" (list a b))
	      ;;(dtrace-if (< (abs (- a b)) 1e-10) "equal:" (list a b))
	      (< (abs (- a b)) 1e-10))
	     (equal? a b)))))

(define (average-distance-from-means means vs)
 (map (lambda (mean)
       (list-mean
	(map (lambda (v)
	      (distance v mean))
	     (remove-if-not (lambda (v)
			     (< (distance v mean)
				(minimum (map (lambda (other-mean)
					       (distance v other-mean))
					      (remove mean means)))))
			    vs))))
      means))

(define (assign-point-to-cluster p means)
 (position
  (first
   (remove-if-not (lambda (mean)
		   (< (distance p mean)
		      (minimum (map (lambda (other-mean)
				     (distance p other-mean))
				    (remove mean means)))))
		  means))
  means))

(define (mean-point points)
 (vector (list-mean (map x points))
	 (list-mean (map y points))
	 ;; (list-mean (map z points))
	 ))
;;-------------------Dan's k-means code above-----------------------------------
;;-------------------my code for manipulating ralicra2016 data below------------

(define *plandirs* (system-output "ls -d /net/seykhl/aux/sbroniko/vader-rover/logs/MSEE1-dataset/ralicra2016/plan*"))

(define *rundirs*
 (join (map (lambda (d) (system-output (format #f "ls -d ~a/2014-*" d))) *plandirs*)))

(define *testdir* "test20150618")

(define *frame-file* "frame-data-0.6-0.6.sc")

(define *outfile-name* "proposal-xy.sc")

(define (get-and-save-raw-xy-locations-from-frame-file
	 rundir testdir frame-file outfile-name)
 (let* ((filedata
	 (read-object-from-file (format #f "~a/~a/~a" rundir testdir frame-file)))
	(framedata (first filedata))
	(xy-list
	 (join
	  (map (lambda (l)
		(map (lambda (ll) (subvector ll 5 7)) (vector->list l))) framedata))))
  (write-object-to-file xy-list (format #f "~a/~a/~a" rundir testdir outfile-name))
  (display (format #f "wrote ~a/~a/~a" rundir testdir outfile-name))
  (newline)))

(define (find-and-save-k-means-for-floorplan
	 plandir testdir proposal-file output-file)
 (let* ((rundirs (system-output (format #f "ls -d ~a/2014-*" plandir)))
	(K 5) ;;number of objects
	(all-proposals
	 (join
	  (map (lambda (d)
		(read-object-from-file
		 (format #f "~a/~a/~a" d testdir proposal-file)))
	       rundirs)))
	(peaks (k-means all-proposals K)))
  peaks))
  
  
	