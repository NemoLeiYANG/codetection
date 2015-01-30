(MODULE
  CODETECTION
  (WITH QOBISCHEME XLIB PREGEXP TOOLLIB-MATLAB TOOLLIB-C-BINDINGS)
  (MAIN MAIN))

(include "QobiScheme.sch")
(include "toollib-c-macros.sch")
(include "codetection.sch")
(c-include "codetectionlib-c.h")

(set! *program* "codetection")
(set! *panic?* #f)

;;;; ffmpeg, imlib, and pnm scheme->c bindings

(define-structure imlib-image handle)
(c-ffi:add-custom-type imlib-image pointer make-imlib-image imlib-image-handle)

(define ffmpeg-open-video
 (c-function pointer ("ffmpeg_open_video" string)))

(define ffmpeg-video-frame-data-as-imlib
 (c-function imlib-image ("ffmpeg_get_frame_as_imlib" pointer)))

(define ffmpeg-close-video
 (c-function void ("ffmpeg_close_and_free_video" pointer)))

(define (ffmpeg-next-frame! video)
 (not (= ((c-function int ("ffmpeg_next_frame" pointer)) video) 0)))

(define imlib-context-set-image!
 (c-function void ("imlib_context_set_image" imlib-image)))

(define (imlib:free-image-and-decache image)
 (imlib-context-set-image! image)
 ((c-function void ("imlib_free_image_and_decache"))))

(define (imlib:height image)
 (imlib-context-set-image! image)
 ((c-function int ("imlib_image_get_height"))))

(define (imlib:width image)
 (imlib-context-set-image! image)
 ((c-function int ("imlib_image_get_width"))))

(define (imlib:clone image)
 (imlib-context-set-image! image)
 ((c-function imlib-image ("imlib_clone_image"))))

(define (imlib:data-ptr-read-only image)
 (imlib-context-set-image! image)
 ((c-function pointer ("imlib_image_get_data_for_reading_only"))))

(define-structure pnm-buffer buffer width height pixfmt storage type)

(define (pixfmt->red pixfmt)
 (cond ((equal? pixfmt "RGB") 0)
       ((equal? pixfmt "BGR0") 2)
       (else (fuck-up))))

(define (pixfmt->stride pixfmt)
 (cond ((equal? pixfmt "I") 1)
       ((equal? pixfmt "RGB") 3)
       ((equal? pixfmt "BGR0") 4)
       (else (fuck-up))))

(define (pixfmt->green pixfmt)
 (cond ((equal? pixfmt "RGB") 1)
       ((equal? pixfmt "BGR0") 1)
       (else (fuck-up))))

(define (pixfmt->blue pixfmt)
 (cond ((equal? pixfmt "RGB") 2)
       ((equal? pixfmt "BGR0") 0)
       (else (fuck-up))))

(define (imlib-image->ppm image)
 (let* ((pnm-buf (imlib-image->pnm-buffer! image))
	(ppm (pnm-buffer->ppm pnm-buf)))
  (free-pnm-buffer! pnm-buf)
  ppm))

(define (imlib-image->pnm-buffer! image)
 (make-pnm-buffer (imlib:data-ptr-read-only (imlib:clone image))
                  (imlib:width image)
                  (imlib:height image)
                  "BGR0"
                  8
                  'color))

(define (pnm-buffer->ppm p)
 ;; TODO check maxval
 (let ((ppm (make-ppm
	     #f
	     255
	     (make-matrix (pnm-buffer-height p) (pnm-buffer-width p) 0)
	     (make-matrix (pnm-buffer-height p) (pnm-buffer-width p) 0)
	     (make-matrix (pnm-buffer-height p) (pnm-buffer-width p) 0)))
       (stride (pixfmt->stride (pnm-buffer-pixfmt p)))
       (red-index (pixfmt->red (pnm-buffer-pixfmt p)))
       (green-index (pixfmt->green (pnm-buffer-pixfmt p)))
       (blue-index (pixfmt->blue (pnm-buffer-pixfmt p))))
  (for-each-n
    (lambda (r)
     (for-each-n
       (lambda (c)
        (matrix-set! (ppm-red ppm)
                     r c
                     (c-byte-ref (pnm-buffer-buffer p) (+ (* stride (+ (* r (pnm-buffer-width p)) c)) red-index)))
        (matrix-set! (ppm-green ppm)
                     r c
                     (c-byte-ref (pnm-buffer-buffer p) (+ (* stride (+ (* r (pnm-buffer-width p)) c)) green-index)))
        (matrix-set! (ppm-blue ppm)
                     r c
                     (c-byte-ref (pnm-buffer-buffer p) (+ (* stride (+ (* r (pnm-buffer-width p)) c)) blue-index))))
      (pnm-buffer-width p)))
   (pnm-buffer-height p))
  ppm))

(define (free-pnm-buffer! p) (free (pnm-buffer-buffer p)) #f)

;;;;;;;;

(define (video->frames video-path)
 (let ((ffmpeg-video (ffmpeg-open-video video-path)))
  (let loop ((frames '())
	     (start #t))
   (if (or start (ffmpeg-next-frame! ffmpeg-video))
       (let* ((image (ffmpeg-video-frame-data-as-imlib ffmpeg-video))
	      (ppm (imlib-image->ppm image)))
	(imlib:free-image-and-decache image)	
	(loop (cons ppm frames) #f))
       (begin
	(ffmpeg-close-video ffmpeg-video)
	(reverse frames))))))

(define (proposals&similarity-with-frames top-k frames)
 (let* ((tt (length frames))
	(one-frame (vector-ref (first frames) 3))
	(height (vector-length one-frame))
	(width (vector-length (vector-ref one-frame 0))))
  (start-matlab!)
  (matlab (format #f "frames=zeros(~a,~a,~a,~a,'uint8');" height width 3 tt))
  ;; convert frames to matlab matrix
  (for-each-indexed
   (lambda (frame i)
    (scheme->matlab! "frame" frame)
    (matlab (format #f "frames(:,:,:,~a)=uint8(frame);" (+ i 1))))
   frames)
  ;; call proposals_and_similarity
  (matlab (format #f "[bboxes,simi]=proposals_and_similarity(~a,frames);" top-k))
  ;; convert matlab variables to scheme
  ;; each time can only convert a 2D matrix
  (list (map-n (lambda (t)
		(matlab (format #f "tmp=bboxes(:,:,~a);" (+ t 1)))
		(matlab-get-variable "tmp"))
	       tt)
	(map-n (lambda (t)
		(matlab (format #f "tmp=simi(:,:,~a);" (+ t 1)))
		(matlab-get-variable "tmp"))
	       (- tt 1)))))

(define (proposals&similarity top-k video-path)
 (proposals&similarity-with-frames top-k (video->frames video-path)))

(define-command
 (main (at-most-one
	("video" video? (video-path "video-path" string-argument ""))))
 (pp (proposals&similarity 1 video-path))
 (newline))
