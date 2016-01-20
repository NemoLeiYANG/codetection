(define (normalize-matrix m)
 (let ((maxval 255)
       (minimum
	(map-reduce-vector
	 min
	 infinity
	 (lambda (row) (reduce-vector min row infinity))
	 m))
       (maximum
	(map-reduce-vector
	 max
	 minus-infinity
	 (lambda (row) (reduce-vector max row minus-infinity))
	 m)))
  (map-vector
   (lambda (row)
    (map-vector
     (lambda (element)
      (inexact->exact
       (floor (* maxval (/ (- element minimum) (- maximum minimum))))))
     row))
   m)))

(define (field pathname f)
 (let ((height 1024)
       (width 1024))
  (write-pnm
   (make-pgm
    #t
    255
    (normalize-matrix
     (map-n-vector
      (lambda (y) (map-n-vector (lambda (x) (f (vector x y))) width))
      height)))
   (default-extension pathname "pgm"))))

(define (near)
 (field "images/near.pgm" (lambda (p) (- (distance p (vector 512 512))))))

(define (far)
 (field "images/far.pgm" (lambda (p) (distance p (vector 512 512)))))

(define (orientation v) (atan (y v) (x v)))

(define (front)
 (field "images/front.pgm"
	(lambda (p)
	 (abs (rotation- (orientation (v- p (vector 512 512))) half-pi)))))

(define (between)
 (field "images/between.pgm"
	(lambda (p)
	 (- (+ (distance p (vector 0 512)) (distance p (vector 1024 512)))))))

(define (generate)
 (near)
 (far)
 (front)
 (between))
