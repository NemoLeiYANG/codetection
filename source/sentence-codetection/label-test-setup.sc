
(start-matlab!)
(matlab "load('~/codetection/source/sentence-codetection/asm_20150702.mat')")
(define asm (matlab-get-variable "avg_similarity_matrix"))
(define asm-g (matrix->list-of-lists asm))
(define g-c (easy-ffi:double-to-c 2 asm-g))
(matlab "asm_small = avg_similarity_matrix(1:8,1:8);")
(define asm-small (matlab-get-variable "asm_small"))
(define asm-g-small (matrix->list-of-lists asm-small))
(define g-c-small (easy-ffi:double-to-c 2 asm-g-small))
(matlab "asm_tiny = avg_similarity_matrix(1:4,1:4);")
(define asm-tiny (matlab-get-variable "asm_tiny"))
(define asm-g-tiny (matrix->list-of-lists asm-tiny))
(define g-c-tiny (easy-ffi:double-to-c 2 asm-g-tiny))



(matlab "load('~/codetection/source/sentence-codetection/asm_20150709.mat')")
(define asm2 (matlab-get-variable "avg_similarity_matrix"))
(define asm-g2 (matrix->list-of-lists asm2))
(define g-c2 (easy-ffi:double-to-c 2 asm-g2))
(matlab "asm_small = avg_similarity_matrix(1:8,1:8);")
(define asm2-small (matlab-get-variable "asm_small"))
(define asm-g2-small (matrix->list-of-lists asm2-small))
(define g-c2-small (easy-ffi:double-to-c 2 asm-g2-small))
(matlab "asm_tiny = avg_similarity_matrix(1:4,1:4);")
(define asm2-tiny (matlab-get-variable "asm_tiny"))
(define asm-g2-tiny (matrix->list-of-lists asm2-tiny))
(define g-c2-tiny (easy-ffi:double-to-c 2 asm-g2-tiny))



(define (test-labeling num-labels f-value)
 (let* ((labels-c
	 (list->c-exact-array (malloc (* c-sizeof-int (length asm-g)))
			      (map-n (lambda _ 0) (length asm-g)) c-sizeof-int #t))
	(test-score (bp-label-inference (length asm-g)
					num-labels
					f-value
					g-c
					labels-c))
	(labels (c-exact-array->list labels-c c-sizeof-int (length asm-g) #t)))
  (free labels-c)
  labels))

(define (test-labeling-small num-labels f-value)
 (let* ((labels-c
	 (list->c-exact-array (malloc (* c-sizeof-int (length asm-g-small)))
			      (map-n (lambda _ 0) (length asm-g-small)) c-sizeof-int #t))
	(test-score (bp-label-inference (length asm-g-small)
					num-labels
					f-value
					g-c-small
					labels-c))
	(labels (c-exact-array->list labels-c c-sizeof-int (length asm-g-small) #t)))
  (free labels-c)
  labels))

(define (test-labeling-tiny num-labels f-value)
 (let* ((labels-c
	 (list->c-exact-array (malloc (* c-sizeof-int (length asm-g-tiny)))
			      (map-n (lambda _ 0) (length asm-g-tiny)) c-sizeof-int #t))
	(test-score (bp-label-inference (length asm-g-tiny)
					num-labels
					f-value
					g-c-tiny
					labels-c))
	(labels (c-exact-array->list labels-c c-sizeof-int (length asm-g-tiny) #t)))
  (free labels-c)
  labels))



(define (test-labeling2 num-labels f-value)
 (let* ((labels-c
	 (list->c-exact-array (malloc (* c-sizeof-int (length asm-g2)))
			      (map-n (lambda _ 0) (length asm-g2)) c-sizeof-int #t))
	(test-score (bp-label-inference (length asm-g2)
					num-labels
					f-value
					g-c2
					labels-c))
	(labels (c-exact-array->list labels-c c-sizeof-int (length asm-g) #t)))
  (free labels-c)
  labels))


(define (test-labeling2-small num-labels f-value)
 (let* ((labels-c
	 (list->c-exact-array (malloc (* c-sizeof-int (length asm-g2-small)))
			      (map-n (lambda _ 0) (length asm-g2-small)) c-sizeof-int #t))
	(test-score (bp-label-inference (length asm-g2-small)
					num-labels
					f-value
					g-c2-small
					labels-c))
	(labels (c-exact-array->list labels-c c-sizeof-int (length asm-g2-small) #t)))
  (free labels-c)
  labels))

(define (test-labeling2-tiny num-labels f-value)
 (let* ((labels-c
	 (list->c-exact-array (malloc (* c-sizeof-int (length asm-g2-tiny)))
			      (map-n (lambda _ 0) (length asm-g2-tiny)) c-sizeof-int #t))
	(test-score (bp-label-inference (length asm-g2-tiny)
					num-labels
					f-value
					g-c2-tiny
					labels-c))
	(labels (c-exact-array->list labels-c c-sizeof-int (length asm-g2-tiny) #t)))
  (free labels-c)
  labels))


(define (positions v l)
 (let loop ((l l) (i 0))
  (let ((p (position v l)))
   (if p
       (cons (+ p i) (loop (list-remove l p) (+ i 1)))
       '()))))

(define (test-labeling-original num-labels f-value default-g-value dummy-g-value)
 (let* ((labels-c
	 (list->c-exact-array (malloc (* c-sizeof-int (length asm-g)))
			      (map-n (lambda _ 0) (length asm-g)) c-sizeof-int #t))
	(test-score (bp-label-inference-original (length asm-g)
						 num-labels
						 f-value
						 default-g-value
						 g-c
						 dummy-g-value
						 labels-c))
	(labels (c-exact-array->list labels-c c-sizeof-int (length asm-g) #t)))
  (free labels-c)
  labels))

(define (test-labeling2-original num-labels f-value default-g-value dummy-g-value)
 (let* ((labels-c
	 (list->c-exact-array (malloc (* c-sizeof-int (length asm-g2)))
			      (map-n (lambda _ 0) (length asm-g2)) c-sizeof-int #t))
	(test-score (bp-label-inference-original (length asm-g2)
						 num-labels
						 f-value
						 default-g-value
						 g-c2
						 dummy-g-value
						 labels-c))
	(labels (c-exact-array->list labels-c c-sizeof-int (length asm-g) #t)))
  (free labels-c)
  labels))

