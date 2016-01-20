(define (split l n)
 (let loop ((l l) (r '()))
  (if (< (length l) n) (cons l r) (loop (drop n l) (cons (take n l) r)))))

(define (generate)
 (let* ((raw (system-output "ls /net/upplysingaoflun/aux/dpbarret/westerns-AMT-clips/*.swf"))
	(number-extra (modulo (length raw) 10))
	(number-to-duplicate (- 10 number-extra))
	(number-to-duplicate (if (= number-to-duplicate 10) 0 number-to-duplicate))
	(ordered (append (map-n (lambda (i) (first raw)) number-to-duplicate)
			 raw))
	(foo (dtrace "length before appending:" (length raw)))
	(foo (dtrace "length after appending:" (length ordered)))
	(unordered (deal ordered))
	(files (map strip-directory unordered))
	(first-line-elements
	 (map-n (lambda (i) (format "video~a" (+ i 1))) 10))
	(lines-elements (remove-if null? (cons first-line-elements (split files 10))))
	(lines (map (lambda (es) (string-join (list->string (list #\tab)) es)) lines-elements)))
  (write-file lines "/home/dpbarret/aws-mturk-clt-1.3.1/hits/firstattempt/firstattempt.autoinput")))
	
	
	
	