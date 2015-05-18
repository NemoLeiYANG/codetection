(define *ellipses* '())

(define *points* '())

(define (mean x) (k*v (/ (vector-length x)) (reduce-vector v+ x #f)))

(define (covariance x)
 (let ((mu (mean x)))
  (k*m (/ (vector-length x))
       (self-outer-product
	dot (transpose (map-vector (lambda (x) (v- x mu)) x))))))

(define (point->ellipse point)
 (let ((k 50))
  (make-ellipse (+ (* k (x point)) 320) (+ (* k (y point)) 240) 0 2 2)))

(define (fit-ellipse points)
 (let* ((k 50)
	(points (list->vector points))
	(mu (mean points))
	(sigma (covariance points))
	(e (eigenvalues sigma)))
  (make-ellipse (+ (* k (x mu)) 320)
		(+ (* k (y mu)) 240)
		(eigenvector-angle1 sigma)
		(* k (sqrt (* 2.0 (vector-ref e 0))))
		(* k (sqrt (* 2.0 (vector-ref e 1)))))))

(define-application viewer 640 480 #f 1 6
 (lambda ()
  (define-button 0 0 "Help" #f help-command)
  (define-button 1 0 "EM" #f
   (lambda ()
    (set! *points*
	  (map (lambda (line)
		(let ((point (list->vector (map string->number (fields line)))))
		 (vector (x point) (- (y point)))))
	       (read-file "/tmp/data.text")))
    (set! *ellipses*
	  (map fit-ellipse
	       (em-jj-clusterer (list->vector *points*)
				5
				'#(0.75 0.75)
				0.00001
				0.00001)))
    (redraw-display-pane)))
  (define-button 2 0 "K Means" #f
   (lambda ()
    (set! *points*
	  (map (lambda (line)
		(let ((point (list->vector (map string->number (fields line)))))
		 (vector (x point) (- (y point)))))
	       (read-file "/tmp/data.text")))
    (set! *ellipses*
	  (map fit-ellipse
	       (k-medoids
		(lambda (ps) (mean (list->vector ps))) distance *points* 10)))
    (redraw-display-pane)))
  (define-button 5 0 "Quit" #f quit))
 (lambda () #f)
 (lambda () #f)
 (lambda ()
  (for-each (lambda (point)
	     (draw-ellipse *display*
			   *display-pane*
			   *thin-gc*
			   (point->ellipse point)))
	    *points*)
  (for-each (lambda (ellipse)
	     (draw-ellipse *display* *display-pane* *thin-gc* ellipse))
	    *ellipses*)))

(define (floorplan) (viewer '()))
