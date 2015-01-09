(MODULE TOOLLIB-PERSPECTIVE-PROJECTION)
(include "QobiScheme-AD.sch")
(include "toollib-c-macros.sch")
(include "toollib-c-externals.sch")
(include "toollib-perspective-projection.sch")

(define (transform-world-point-to-pixel robot point)
 (let* ((world->camera-txf (get-robot-world->camera-txf robot))
	(intrinsics (camera-info-intrinsic-parameters
		     (robot-camera-info robot)))
	(camera-point (transform-point-3d world->camera-txf point))
	(homo-point (m*v intrinsics camera-point)))
  (subvector (v/s homo-point (z homo-point)) 0 2)))

(define (transform-world-point-to-pixel-with-transformation
	 robot world->camera-txf point)
 (let* ((intrinsics (camera-info-intrinsic-parameters
		     (robot-camera-info robot)))
	(camera-point (transform-point-3d world->camera-txf point))
	(homo-point (m*v intrinsics camera-point)))
  (subvector (v/s homo-point (z homo-point)) 0 2)))

(define (transform-world-point->pixel-generic
	 world->camera-txf intrinsics point)
 (let* ((camera-point (transform-point-3d world->camera-txf point))
	(homo-point (m*v intrinsics camera-point)))
  (subvector (v/s homo-point (z homo-point)) 0 2)))

(define (draw-point-projection image
			       world->camera-txf
			       intrinsics
			       point
			       shape
			       size
			       color)
 (let* ((pix-point (transform-world-point->pixel-generic
		    world->camera-txf
		    intrinsics
		    point)))
  (cond ((equal? shape 'pixel)
	 (imlib:draw-pixel image
			   (x pix-point)
			   (y pix-point)
			   color))
	((equal? shape 'square)
	 (imlib:draw-rectangle image
			       (x pix-point)
			       (y pix-point)
			       size
			       size
			       color))
	((equal? shape 'circle)
	 (imlib:draw-ellipse image
			     (x pix-point)
			     (y pix-point)
			     size
			     size
			     color)))))

(define (draw-text-projection image
			      world->camera-txf
			      intrinsics
			      point
			      size
			      color
			      text)
 (let* ((pix-point (transform-world-point->pixel-generic
		    world->camera-txf
		    intrinsics
		    point)))
  (imlib-draw-text-on-image image
			    text
			    color
			    size
			    (x pix-point)
			    (y pix-point)
			    #f)))

(define (draw-line-projection image
			      point1
			      point2
			      world->camera-txf
			      intrinsics
			      color)
 (let* ((pix-point1 (transform-world-point->pixel-generic
		     world->camera-txf
		     intrinsics
		     point1))
	(pix-point2 (transform-world-point->pixel-generic
		     world->camera-txf
		     intrinsics
		     point2)))
  (imlib:draw-line image
		   color
		   (x pix-point1)
		   (y pix-point1)
		   (x pix-point2)
		   (y pix-point2))))

(define (draw-arrow-projection image
			       point1
			       point2
			       world->camera-txf
			       intrinsics
			       size
			       color)
 (let* ((pix-point1 (transform-world-point->pixel-generic
		     world->camera-txf
		     intrinsics
		     point1))
	(pix-point2 (transform-world-point->pixel-generic
		     world->camera-txf
		     intrinsics
		     point2))
	(vp1p2 (v- pix-point2 pix-point1))
	(normal (vector (- (y vp1p2)) (x vp1p2)))
	(unit-normal (v/s normal (magnitude normal)))
	(unit-p2p1 (v/s vp1p2 (- (magnitude vp1p2))))
	(arrow-point1 (v+ pix-point2
			  (v*s (v+ unit-p2p1 unit-normal) size)))
	(arrow-point2 (v+ pix-point2
			  (v*s (v- unit-p2p1 unit-normal) size))))
  (imlib:draw-line image
		   color
		   (x pix-point1)
		   (y pix-point1)
		   (x pix-point2)
		   (y pix-point2))
  (imlib:draw-line image
		   color
		   (x pix-point2)
		   (y pix-point2)
		   (x arrow-point1)
		   (y arrow-point1))
  (imlib:draw-line image
		   color
		   (x pix-point2)
		   (y pix-point2)
		   (x arrow-point2)
		   (y arrow-point2))
  (imlib:draw-line image
		   color
		   (x arrow-point1)
		   (y arrow-point1)
		   (x arrow-point2)
		   (y arrow-point2))))

(define (draw-axis-projection image
			      axis-txf
			      world->camera-txf
			      intrinsics
			      length
			      brightness)
 (let* ((origin (transform-point-3d axis-txf (vector 0 0 0)))
	(x-point (transform-point-3d axis-txf (vector length 0 0)))
	(y-point (transform-point-3d axis-txf (vector 0 length 0)))
	(z-point (transform-point-3d axis-txf (vector 0 0 length))))
  (draw-arrow-projection image origin x-point world->camera-txf
			 intrinsics 5 (vector (* brightness 255) 0 0))
  (draw-arrow-projection image origin y-point world->camera-txf
			 intrinsics 5 (vector 0 (* brightness 255) 0))
  (draw-arrow-projection
   image origin z-point world->camera-txf
   intrinsics 5 (vector 0 0 (* brightness 255)))))

(define (world-forward-project image
			       robot
			       world->camera-txf
			       intrinsics
			       color)
 (topological-traverse
  (lambda (joint name point tx)
   (let* ((joint-txf (joint->transformation joint))
          (tx (m* tx joint-txf))
	  (new-point (transform-point-3d tx '#(0 0 0))))
    (when (and new-point point)
     (draw-line-projection
      image point new-point world->camera-txf intrinsics color))
    (list (joint-name joint) new-point tx)))
  (lambda (joint)
   (intersectionp (lambda (e1 e2) (equal? e2 (joint-name e1)))
		  (robot-joints robot)
		  (joint-connects-to joint)))
  (first (robot-joints robot))
  #f
  #f
  (robot-base-to-world-txf robot)))

(define (draw-3d-lines-projection image
				  points
				  world->camera-txf
				  intrinsics
				  color)
 (let loop ((points points))
  (if (< (length points) 2)
      '()
      (begin
       (draw-line-projection
	image (first points) (second points)
	world->camera-txf intrinsics color)
       (loop (rest points))))))

(define (draw-circle-projection image
				radius
				circle->world-txf
				world->camera-txf
				intrinsics
				color)
 (let* ((circle-points (map (lambda (theta) (vector (* radius (cos theta))
						    (* radius (sin theta))
						    0))
			    (linspace 0 (* 2 pi) 100)))
	(world-points (map (lambda (point)
			    (transform-point-3d circle->world-txf point))
			   circle-points)))
  (draw-3d-lines-projection image world-points world->camera-txf
			    intrinsics color)
  (draw-line-projection image (last circle-points) (first circle-points)
			world->camera-txf intrinsics color)))

(define (facing-camera? p v camera)
 (let* ((v2 (v- camera p))
	(angle (vectors->angle v v2)))
  (<= angle half-pi)))

(define (find-cylinder-lines upper-circle-world-points
			     upper-circle-world-points-visible
			     lower-circle-world-points
			     lower-circle-world-points-visible)
 (let* ((upper-visibility
	 (reduce + (map (lambda (b) (if b 1 0))
			upper-circle-world-points-visible)
		 0))
	(lower-visibility
	 (reduce + (map (lambda (b) (if b 1 0))
			lower-circle-world-points-visible)
		 0))
	(visibles (if (< lower-visibility upper-visibility)
		      (list->vector upper-circle-world-points)
		      (list->vector lower-circle-world-points)))
	(occludeds (if (< lower-visibility upper-visibility)
		       (list->vector lower-circle-world-points)
		       (list->vector upper-circle-world-points)))
	(occluded-visible
	 (if (< lower-visibility upper-visibility)
	     (list->vector lower-circle-world-points-visible)
	     (list->vector upper-circle-world-points-visible)))
	(is-endpoint?
	 (map-n
	  (lambda (i)
	   (if
	    (and (vector-ref occluded-visible i)
		 (if (not (or (= i 0)
			      (= i (- (vector-length occluded-visible)
				      1))))
		     (or (and (vector-ref occluded-visible (+ i 1))
			      (not (vector-ref occluded-visible (- i 1))))
			 (and (not (vector-ref occluded-visible (+ i 1)))
			      (vector-ref occluded-visible (- i 1))))
		     (if (= i 0)	   
			 (or
			  (and (vector-ref occluded-visible (+ i 1))
			       (not (vector-ref
				     occluded-visible
				     (- (vector-length occluded-visible)
					1))))
			  (and (not (vector-ref occluded-visible (+ i 1)))
			       (vector-ref
				occluded-visible
				(- (vector-length occluded-visible)
				   1))))
			 (or (and (vector-ref occluded-visible (- i 1))
				  (not (vector-ref occluded-visible
						   0)))
			     (and (not (vector-ref occluded-visible
						   (- i 1)))
				  (vector-ref occluded-visible
					      0))))))
	    (list (vector-ref visibles i)
		  (vector-ref occludeds i)
		  i)
	    #f))			   
	  (vector-length occludeds)))
	(lines (removeq #f is-endpoint?)))
  lines))

(define (points->sets-of-visible-points points
					visibility
					loop?)
 (let ((sets (let loop ((points points)
			(visibility visibility)
			(sets '())
			(last? #f)
			(first? (first visibility)))
	      (if (null? points)
		  sets
		  (loop (rest points)
			(rest visibility)
			(if (first visibility)
			    (if last?
				(cons (cons (first points)
					    (first sets))
				      (rest sets))
				(cons (list (first points))
				      sets))
			    sets)
			(first visibility)
			first?)))))
  (if loop?
      (if (and (first visibility) (last visibility) (>= (length sets) 2))
	  (cons (append  (last sets) (first sets))
		(rest sets))
	  sets)
      sets)))

(define (draw-cylinder-projection image
				  radius
				  height
				  world-center
				  theta
				  phi
				  psi
				  world->camera-txf
				  intrinsics
				  color
				  samples)
 (let* ((camera-world-position
	 (transform-point-3d (invert-matrix world->camera-txf) `#(0 0 0)))
	(cylinder->world-txf
	 (make-transform-3d
	  theta phi psi
	  (x world-center) (y world-center) (z world-center)))
       	(lower-circle-points
	 (map (lambda (theta) (vector (* radius (cos theta))
				      (* radius (sin theta))
				      0))
	      (linspace 0 (* 2 pi) (+ samples 1))))
	(upper-circle-points
	 (map (lambda (theta) (vector (* radius (cos theta))
				      (* radius (sin theta))
				      height))
	      (linspace 0 (* 2 pi) (+ samples 1))))
	(lower-circle-world-points
	 (map (lambda (point)
	       (transform-point-3d cylinder->world-txf point))
	      lower-circle-points))
	(upper-circle-world-points
	 (map (lambda (point)
	       (transform-point-3d cylinder->world-txf point))
	      upper-circle-points))
	(lower-circle-center
	 (transform-point-3d cylinder->world-txf `#(,0 ,0 ,0)))
	(upper-circle-center
	 (transform-point-3d cylinder->world-txf `#(,0 ,0 ,height)))
	(lower-point-visible?
	 (map
	  (lambda (point upper-point i)
	   (or (facing-camera? point
			       (v- point lower-circle-center)
			       camera-world-position)
	       (and (not (= i 0))
		    (facing-camera? point
				    (v- (v/s (v+ point (list-ref lower-circle-world-points (- i 1))) 2) lower-circle-center)
				    camera-world-position))
	       (and (not (= i (- (length lower-circle-world-points) 1)))
		    (facing-camera? point
				    (v- (v/s (v+ point (list-ref lower-circle-world-points (+ i 1))) 2) lower-circle-center)
				    camera-world-position))
	       (facing-camera? point
			       (v- point upper-point)
			       camera-world-position)))
	  lower-circle-world-points
	  upper-circle-world-points
	  (enumerate (length lower-circle-world-points))))
	(upper-point-visible?
	 (map
	  (lambda (lower-point point i)
	   (or (facing-camera? point
			       (v- point upper-circle-center)
			       camera-world-position)
	       (and (not (= i 0))
		    (facing-camera? point
				    (v- (v/s (v+ point (list-ref upper-circle-world-points (- i 1))) 2) upper-circle-center)
				    camera-world-position))
	       (and (not (= i (- (length upper-circle-world-points) 1)))
		    (facing-camera? point
				    (v- (v/s (v+ point (list-ref upper-circle-world-points (+ i 1))) 2) upper-circle-center)
				    camera-world-position))
	       (facing-camera? point
			       (v- point lower-point)
			       camera-world-position)))
	  lower-circle-world-points
	  upper-circle-world-points
	  (enumerate (length lower-circle-world-points))))
	(lines (find-cylinder-lines
		upper-circle-world-points upper-point-visible?
		lower-circle-world-points lower-point-visible?))
	(visible-lower-circle-world-points-sets
	 (points->sets-of-visible-points lower-circle-world-points
					 lower-point-visible?
					 #t))
	(visible-upper-circle-world-points-sets
	 (points->sets-of-visible-points upper-circle-world-points
					 upper-point-visible?
					 #t)))
  (map (lambda (set)
	(draw-3d-lines-projection
	 image set world->camera-txf intrinsics color))
       visible-lower-circle-world-points-sets)
  (map (lambda (set)
	(draw-3d-lines-projection
	 image set world->camera-txf intrinsics color))
       visible-upper-circle-world-points-sets)
  (map (lambda (line)
	(draw-line-projection image (first line) (second line) world->camera-txf intrinsics color))
       lines)))

(define (draw-king-bottom-projection image
				     radius
				     height
				     world-center
				     theta
				     phi
				     psi
				     world->camera-txf
				     intrinsics
				     color
				     samples)
;; cant see much of the top because there is another piece sitting on it.
 (let* ((camera-world-position
	 (transform-point-3d (invert-matrix world->camera-txf) `#(0 0 0)))
	(cylinder->world-txf
	 (make-transform-3d
	  theta phi psi
	  (x world-center) (y world-center) (z world-center)))
       	(lower-circle-points
	 (map (lambda (theta) (vector (* radius (cos theta))
				      (* radius (sin theta))
				      0))
	      (linspace 0 (* 2 pi) (+ samples 1))))
	(upper-circle-points
	 (map (lambda (theta) (vector (* radius (cos theta))
				      (* radius (sin theta))
				      height))
	      (linspace 0 (* 2 pi) (+ samples 1))))
	(lower-circle-world-points
	 (map (lambda (point)
	       (transform-point-3d cylinder->world-txf point))
	      lower-circle-points))
	(upper-circle-world-points
	 (map (lambda (point)
	       (transform-point-3d cylinder->world-txf point))
	      upper-circle-points))
	(lower-circle-center
	 (transform-point-3d cylinder->world-txf `#(,0 ,0 ,0)))
	(upper-circle-center
	 (transform-point-3d cylinder->world-txf `#(,0 ,0 ,height)))
	(lower-point-visible?
	 (map
	  (lambda (point upper-point i)
	   (or (facing-camera? point
			       (v- point lower-circle-center)
			       camera-world-position)
	       (and (not (= i 0))
		    (facing-camera? point
				    (v- (v/s (v+ point (list-ref lower-circle-world-points (- i 1))) 2) lower-circle-center)
				    camera-world-position))
	       (and (not (= i (- (length lower-circle-world-points) 1)))
		    (facing-camera? point
				    (v- (v/s (v+ point (list-ref lower-circle-world-points (+ i 1))) 2) lower-circle-center)
				    camera-world-position))
	       (facing-camera? point
			       (v- point upper-point)
			       camera-world-position)))
	  lower-circle-world-points
	  upper-circle-world-points
	  (enumerate (length lower-circle-world-points))))
	(upper-point-visible?
	 (map
	  (lambda (lower-point point i)
	   (or (facing-camera? point
			       (v- point upper-circle-center)
			       camera-world-position)
	       (and (not (= i 0))
		    (facing-camera? point
				    (v- (v/s (v+ point (list-ref upper-circle-world-points (- i 1))) 2) upper-circle-center)
				    camera-world-position))
	       (and (not (= i (- (length upper-circle-world-points) 1)))
		    (facing-camera? point
				    (v- (v/s (v+ point (list-ref upper-circle-world-points (+ i 1))) 2) upper-circle-center)
				    camera-world-position))
	       ;; (facing-camera? point
	       ;; 		       (v- point lower-point)
	       ;; 		       camera-world-position)
	       
	       ))
	  lower-circle-world-points
	  upper-circle-world-points
	  (enumerate (length lower-circle-world-points))))
	(lines (find-cylinder-lines
		upper-circle-world-points upper-point-visible?
		lower-circle-world-points lower-point-visible?))
	(visible-lower-circle-world-points-sets
	 (points->sets-of-visible-points lower-circle-world-points
					 lower-point-visible?
					 #t))
	(visible-upper-circle-world-points-sets
	 (points->sets-of-visible-points upper-circle-world-points
					 upper-point-visible?
					 #t)))
  (map (lambda (set)
	(draw-3d-lines-projection
	 image set world->camera-txf intrinsics color))
       visible-lower-circle-world-points-sets)
  (map (lambda (set)
	(draw-3d-lines-projection
	 image set world->camera-txf intrinsics color))
       visible-upper-circle-world-points-sets)
  (map (lambda (line)
	(draw-line-projection image (first line) (second line) world->camera-txf intrinsics color))
       lines)))

(define (make-cylinder-image image-width
			     image-height
			     world->camera-txf
			     intrinsics
			     piece-radius
			     piece-height
			     x
			     y
			     z
			     theta
			     phi
			     psi
			     color
			     samples)
 (let ((image (imlib:create image-width image-height)))
  (imlib:fill-rectangle image 0 0 image-width image-height `#(0 0 0))
  (draw-cylinder-projection image
			    piece-radius
			    piece-height
			    (vector x y z)
			    theta
			    phi
			    psi
			    world->camera-txf
			    intrinsics
			    color
			    samples)
  image))

(define (make-king-bottom-image image-width
				image-height
				world->camera-txf
				intrinsics
				piece-radius
				piece-height
				x
				y
				z
				theta
				phi
				psi
				color
				samples)
 (let ((image (imlib:create image-width image-height)))
  (imlib:fill-rectangle image 0 0 image-width image-height `#(0 0 0))
  (draw-king-bottom-projection image
			    piece-radius
			    piece-height
			    (vector x y z)
			    theta
			    phi
			    psi
			    world->camera-txf
			    intrinsics
			    color
			    samples)
  image))

(define (test-make-cylinder-image samples)
 (let* ((image-width 800)
	(image-height 600)
	(world->camera-txf (vector
			    `#(1 0 0 0)
			    `#(0 1 0 0)
			    `#(0 0 1 0)
			    `#(0 0 0 1)))
	(intrinsics (vector `#(1000 0. 400)
			    `#(0. 1000 300)
			    `#(0. 0. 1.)))
	(piece-radius 200)
	(piece-height 80)
	(x 0)
	(y 0)
	(z 1000)
	(theta (+ (/ pi 4)))
	(phi 0)
	(psi 0)
	(color `#(255 255 255))
	(image (make-cylinder-image image-width
				    image-height
				    world->camera-txf
				    intrinsics
				    piece-radius
				    piece-height
				    x
				    y
				    z
				    theta
				    phi
				    psi
				    color
				    samples)))
  (imlib:save image
	      "/tmp/cylinder-image.png")
  (imlib:free image)))
 
(define (test-make-king-bottom-image samples)
 (let* ((image-width 800)
	(image-height 600)
	(world->camera-txf (vector
			    `#(1 0 0 0)
			    `#(0 1 0 0)
			    `#(0 0 1 0)
			    `#(0 0 0 1)))
	(intrinsics (vector `#(1000 0. 400)
			    `#(0. 1000 300)
			    `#(0. 0. 1.)))
	(piece-radius 200)
	(piece-height 80)
	(x 0)
	(y 0)
	(z 1000)
	(theta (random-in-range (- pi) pi)) ;;-(- (/ pi 4)))
	(phi (random-in-range (- pi) pi))
	(psi (random-in-range (- pi) pi))
	(color `#(255 255 255))
	(image (make-king-bottom-image image-width
				    image-height
				    world->camera-txf
				    intrinsics
				    piece-radius
				    piece-height
				    x
				    y
				    z
				    theta
				    phi
				    psi
				    color
				    samples)))
  (imlib:save image
	      "/tmp/cylinder-image.png")
  (show-image image)
  (imlib:free image)))