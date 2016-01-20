(MODULE EASY-FFI)
;;; LaHaShem HaAretz U'Mloah
;;; Copyright 2013 Purdue University. All rights reserved.

(include "QobiScheme.sch")
(include "toollib-c-macros.sch")
(include "easy-ffi.sch")

(define (easy-ffi:to-c c-set! c-size)
 (lambda (n x)
  (let loop ((n n) (x x))
   (if (= n 1)
       (cond
	((list? x)
	 (let ((v ((c-function pointer ("malloc" unsigned))
		   (* (length x) c-size))))
	  (for-each-indexed (lambda (x i) (c-set! v (* i c-size) x)) x)
	  v))
	((vector? x)
	 (let ((v ((c-function pointer ("malloc" unsigned))
		   (* (vector-length x) c-size))))
	  (for-each-n (lambda (i) (c-set! v (* i c-size) (vector-ref x i)))
		      (vector-length x))
	  v))
	(else (panic "Not a list or vector")))
       (cond
	((list? x)
	 (let ((v ((c-function pointer ("malloc" unsigned))
		   (* (length x) c-sizeof-s2cuint))))
	  (for-each-indexed
	   (lambda (x i)
	    (c-s2cuint-set! v (* i c-sizeof-s2cuint) (loop (- n 1) x)))
	   x)
	  v))
	((vector? x)
	 (let ((v ((c-function pointer ("malloc" unsigned))
		   (* (vector-length x) c-sizeof-s2cuint))))
	  (for-each-n
	   (lambda (i)
	    (c-s2cuint-set!
	     v (* i c-sizeof-s2cuint) (loop (- n 1) (vector-ref x i))))
	   (vector-length x))
	  v))
	(else (panic "Not a list or vector")))))))

(define (easy-ffi:from-c c-ref c-size)
 (lambda (ns ts v)
  (let loop ((ns ns) (ts ts) (v v))
   (if (= (length ns) 1)
       (case (first ts)
	((list) (map-n (lambda (i) (c-ref v (* i c-size))) (first ns)))
	((vector) (map-n-vector (lambda (i) (c-ref v (* i c-size))) (first ns)))
	(else (panic "Not a list or vector")))
       (case (first ts)
	((list)
	 (map-n
	  (lambda (i)
	   (loop (rest ns) (rest ts) (c-s2cuint-ref v (* i c-sizeof-s2cuint))))
	  (first ns)))
	((vector)
	 (map-n-vector
	  (lambda (i)
	   (loop (rest ns) (rest ts) (c-s2cuint-ref v (* i c-sizeof-s2cuint))))
	  (first ns)))
	(else (panic "Not a list or vector")))))))

(define (easy-ffi:free n x v)
 (let loop ((n n) (x x) (v v))
  (if (= n 1)
      ((c-function void ("free" pointer)) v)
      (cond
       ((list? x)
	(for-each-indexed
	 (lambda (x i)
	  (loop (- n 1) x (c-s2cuint-ref v (* i c-sizeof-s2cuint))))
	 x)
	((c-function void ("free" pointer)) v))
       ((vector? x)
	(for-each-n
	 (lambda (i)
	  (loop
	   (- n 1) (vector-ref x i) (c-s2cuint-ref v (* i c-sizeof-s2cuint))))
	 (vector-length x))
	((c-function void ("free" pointer)) v))
       (else (panic "Not a list or vector"))))))

(define easy-ffi:byte-to-c (easy-ffi:to-c c-byte-set! 1))

(define easy-ffi:double-to-c (easy-ffi:to-c c-double-set! c-sizeof-double))

(define easy-ffi:float-to-c (easy-ffi:to-c c-float-set! c-sizeof-float))

(define easy-ffi:int-to-c (easy-ffi:to-c c-int-set! c-sizeof-int))

(define easy-ffi:longint-to-c (easy-ffi:to-c c-longint-set! c-sizeof-long))

(define easy-ffi:longunsigned-to-c
 (easy-ffi:to-c c-longunsigned-set! c-sizeof-long))

(define easy-ffi:shortint-to-c (easy-ffi:to-c c-shortint-set! c-sizeof-short))

(define easy-ffi:shortunsigned-to-c
 (easy-ffi:to-c c-shortunsigned-set! c-sizeof-short))

(define easy-ffi:unsigned-to-c (easy-ffi:to-c c-unsigned-set! c-sizeof-int))

(define easy-ffi:byte-from-c (easy-ffi:from-c c-byte-ref 1))

(define easy-ffi:double-from-c (easy-ffi:from-c c-double-ref c-sizeof-double))

(define easy-ffi:float-from-c (easy-ffi:from-c c-float-ref c-sizeof-float))

(define easy-ffi:int-from-c (easy-ffi:from-c c-int-ref c-sizeof-int))

(define easy-ffi:longint-from-c (easy-ffi:from-c c-longint-ref c-sizeof-long))

(define easy-ffi:longunsigned-from-c
 (easy-ffi:from-c c-longunsigned-ref c-sizeof-long))

(define easy-ffi:shortint-from-c
 (easy-ffi:from-c c-shortint-ref c-sizeof-short))

(define easy-ffi:shortunsigned-from-c
 (easy-ffi:from-c c-shortunsigned-ref c-sizeof-short))

(define easy-ffi:unsigned-from-c (easy-ffi:from-c c-unsigned-ref c-sizeof-int))

(define (easy-ffi:remove-leading-stars type)
 (string->symbol
  (list->string
   (let loop ((chars (string->list (symbol->string type))))
    (if (char=? (first chars) #\*)
	(loop (rest chars))
	chars)))))

(define (easy-ffi:count-leading-stars type)
 (let loop ((chars (string->list (symbol->string type))))
  (if (char=? (first chars) #\*) (+ (loop (rest chars)) 1) 0)))

(define (easy-ffi:remove-trailing-stars type)
 (string->symbol
  (list->string
   (reverse
    (let loop ((chars (reverse (string->list (symbol->string type)))))
     (if (char=? (first chars) #\*)
	 (loop (rest chars))
	 chars))))))

(define (easy-ffi:count-trailing-stars type)
 (let loop ((chars (reverse (string->list (symbol->string type)))))
  (if (char=? (first chars) #\*) (+ (loop (rest chars)) 1) 0)))

;;; byte
;;; pointer array char tscp void

;;; Tam V'Nishlam Shevah L'El Borei Olam
