(MODULE CODETECTIONLIB-SC)

(include "QobiScheme.sch")
(include "codetectionlib-sc.sch")
(include "toollib-c-macros.sch")
(c-include "codetectionlib-c.h")

;;;;;;;;; auxiliary
(define (o a b . c)
 (let ((fs (cons a (cons b c))))
  (lambda d (foldl (lambda (x f) (f x)) (rest (reverse fs)) (apply (last fs) d)))))

(define (zip a b . cs)
 (map reverse (foldl (lambda (a b) (map cons b a)) (cons b cs) (map list a))))

(define (all-positions x lst)
 (removeq #f
	  (map-indexed (lambda (e i)
			(if (equal? e x)
			    i
			    #f))
		       lst)))

(define (all-pairs l)
 (if (null? l)
     '()
     (append
      (all-pairs (cdr l))
      (map (lambda (r) (list (car l) r)) (cdr l)))))

(define (median lst)
 (list-ref (sort lst < identity) (/ (length lst) 2)))

(define (current-time)
 (let ((time-file (string-append "/tmp/time-" (number->string (getpid)))))
  (system (format #f "date +'%s %N' > ~a" time-file))
  (let ((t (first (map fields (read-file time-file)))))
   (rm time-file)
   (string->number (string-append (first t) "." (second t))))))

(define (hostname)
 (let ((host-file (string-append "/tmp/host-" (number->string (getpid)))))
  (system (format #f "hostname > ~a" host-file))
  (let ((name (read-file host-file)))
   (rm host-file)
   (first name))))

(define (current-date-and-time)
 (let ((time-file (string-append "/tmp/time-" (number->string (getpid)))))
  (system (format #f "date > ~a" time-file))
  (let ((date (string-join "-" (take 4 (remove "" (pregexp-split " " (first (read-file time-file))))))))
   (rm time-file)
   date)))

(define (list-mean p)
 (if (vector? (car p))
     (k*v  (/ 1 (length p)) (reduce v+ p 0))
     (/ (reduce + p 0) (length p))))

(define (randomize)
 (for-each-n (lambda (i) (random-real))
	     (+ (getpid) (map-reduce + 0 char->integer (string->list (hostname))))))

(define (nondeterministic-map f l)
 ;; workaround for map breaking in non-deterministic code
 (let loop ((c '()) (l l))
  (if (null? l) (reverse c) (loop (cons (f (first l)) c) (rest l)))))

(define (initial-sublist? ref l)
 (and (> (length ref) (length l))
    (let loop ((l1 l) (l2 ref))
     (if (null? l1) #t (and (equal? (car l1) (car l2)) (loop (cdr l1) (cdr l2)))))))

(define (maximump l p)
 (define (m p l x)
  (if (null? l) x
      (if (> (p (car l)) (p x)) (m p (cdr l) (car l)) (m p (cdr l) x))))
 (when (not (null? l)) (m p (cdr l) (car l))))

(define (flatten* l)
 (if (null? l)
     '()
     (if (list? (car l))
	 (flatten* (append (car l) (cdr l)))
	 (cons (car l) (flatten* (cdr l))))))

(define (matrix->list-of-lists m)
 (vector->list (map-vector vector->list m)))

(define (list-of-lists->matrix lol)
 (list->vector (map list->vector lol)))

(define (split-into n l)
 (let ((len (inexact->exact (floor (/ (length l) n)))))
  (let loop ((l l) (mod (modulo (length l) n)))
   (cond ((null? l) '())
	 ((> mod 0) (cons (take (+ len 1) l)
			  (loop (drop (+ len 1) l) (- mod 1))))
	 ((= mod 0) (cons (take len l) (loop (drop len l) mod)))
	 (else (fuck-up))))))

(define (take n l) (sublist l 0 n))

(define (drop n l) (sublist l n (length l)))

(define (split-n n l)
 (if (null? l) l (cons (take n l) (split-n n (drop n l)))))

(define (join l) (reduce append l '()))

(define (unzip l)
 (if (null? l) '()
     (map-n (lambda (i) (map (lambda (e) (list-ref e i)) l)) (length (first l)))))

(define (pad-if-necessary lst len element)
 (if (>= (length lst) len)
     lst
     (append lst (map-n (lambda _ element) (- len (length lst))))))

(define (take-if-possible n l) (if (> (length l) n) (take n l) l))

(define (rand-pick-m lst m)
 (sort 
  (take-if-possible
   m (map second (sort (map (lambda (x) (list (random-real) x)) lst) < first)))
  <
  identity))

(define (take-every-n lst n)
 (removeq
  #f
  (map-indexed
   (lambda (x i)
    (if (zero? (modulo (+ i 1) n))
	x
	#f))
   lst)))

(define (middle lst)
 (if (null? lst)
     '()
     (list-ref lst (quotient (length lst) 2))))

(define (transpose-list-of-lists lol)
 (matrix->list-of-lists (transpose (list-of-lists->matrix lol))))

(define (evenly-pick-m lst m)
 (if (= m 1)
     (list-ref lst (quotient (length lst) 2))
     (map middle (split-into m lst))))

(define (group-by f l)
 (transitive-equivalence-classesp (lambda (a b) (equal? (f a) (f b))) l))

;;;;;;;;; math

(define (upper-truncate t x) (if (> x t) t x))

(define (sigmoid t a b) (/ (+ 1 (exp (- (* b (- t a)))))))

;;;; ffmpeg, imlib, and pnm scheme->c bindings

(define (trace->splines trace number-of-points)
 (let ((trace (list->vector (map list->vector trace))))
  (scheme->matlab! "points" trace)
  (scheme->matlab! "t" (enumerate-vector (vector-length trace)))
  (matlab (format #f "pp=spline(t,points'); yy=ppval(linspace(0,max(t),~a),pp);" number-of-points))
  (let* ((xs-and-ys (matlab-get-variable "yy")))
   (vector->list
    (map-vector (lambda (x y)
		 (list x y)) 
		(x xs-and-ys)
		(y xs-and-ys))))))

(define ffmpeg-open-video
 (c-function pointer ("ffmpeg_open_video" string)))

(define ffmpeg-video-frame-data-as-imlib
 (c-function pointer ("ffmpeg_get_frame_as_imlib" pointer)))

(define ffmpeg-close-video
 (c-function void ("ffmpeg_close_and_free_video" pointer)))

(define (ffmpeg-next-frame! video)
 (not (= ((c-function int ("ffmpeg_next_frame" pointer)) video) 0)))

(define imlib:context-set-image!
 (c-function void ("imlib_context_set_image" pointer)))

(define imlib:context-set-color!
 (c-function void ("imlib_context_set_color" int int int int)))

(define (imlib:context-set-color-rgb/a! color)
 (define (a v) (vector-ref v 3))
 (define (b v) (vector-ref v 2))
 (define (g v) (vector-ref v 1))
 (define (r v) (vector-ref v 0))
 (imlib:context-set-color! (r color) (g color) (b color)
                           (if (= (vector-length color) 3) 255 (a color))))

(define (imlib:draw-rectangle image x1 y1 w h color thickness)
 (let ((width (imlib:width image))
       (height (imlib:height image)))
  (imlib:context-set-color-rgb/a! color)
  (imlib:context-set-image! image)
  ;; a hack to draw with thick lines
  (let* ((x2 (+ x1 w -1))
	 (y2 (+ y1 h -1))
	 (min_x (max 0 (- x1 thickness -1)))
	 (max_x (min (- width 1) (+ x2 thickness -1)))
	 (min_y (max 0 (- y1 thickness -1)))
	 (max_y (min (- height 1) (+ y2 thickness -1))))
  (for-each-n
   (lambda (i)
    ((c-function void ("imlib_image_draw_rectangle" int int int int))
     (+ min_x i) (+ min_y i)
     (- (- max_x i) (+ min_x i) -1) (- (- max_y i) (+ min_y i) -1)))
   thickness)
  image)))

(define (*default-font-path*)
 (cond ((file-exists? "/usr/share/fonts/truetype/ttf-dejavu")
	"/usr/share/fonts/truetype/ttf-dejavu")
       ((file-exists? "/usr/share/fonts/dejavu")
	"/usr/share/fonts/dejavu")
       ((file-exists? "/usr/share/fonts/TTF")
	"/usr/share/fonts/TTF")
       (else (panic "Can't find a font directory"))))

(define imlib:context-set-font!
 (c-function void ("imlib_context_set_font" pointer)))

(define imlib:load-image
 (c-function pointer ("imlib_load_image" string)))

(define imlib:load-font!
 (c-function pointer ("imlib_load_font" string)))

(define imlib:free-font
 (c-function void ("imlib_free_font")))

(define imlib:add-path-to-font-path
 (c-function void ("imlib_add_path_to_font_path" string)))

(define (imlib:text-draw image x y text color font-size)
 (imlib:add-path-to-font-path (*default-font-path*))
 (imlib:context-set-font! (imlib:load-font! (format #f "DejaVuSans/~a" font-size)))
 (imlib:context-set-color-rgb/a! color)
 (imlib:context-set-image! image)
 ((c-function void ("imlib_text_draw" int int pointer))
  x y text)
 (imlib:free-font))

(define (imlib:free-image-and-decache image)
 (imlib:context-set-image! image)
 ((c-function void ("imlib_free_image_and_decache"))))

(define (imlib:save-image image file)
 (imlib:context-set-image! image)
 ((c-function void ("imlib_save_image" pointer)) file))

(define (imlib:height image)
 (imlib:context-set-image! image)
 ((c-function int ("imlib_image_get_height"))))

(define (imlib:width image)
 (imlib:context-set-image! image)
 ((c-function int ("imlib_image_get_width"))))

(define (imlib:clone image)
 (imlib:context-set-image! image)
 ((c-function pointer ("imlib_clone_image"))))

(define (imlib:data-ptr-read-only image)
 (imlib:context-set-image! image)
 ((c-function pointer ("imlib_image_get_data_for_reading_only"))))