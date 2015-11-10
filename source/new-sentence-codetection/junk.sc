(define (count-breaks vec)
 (let loop ((data (vector->list vec))
	    (prevf1 0)
	    (prevf2 0)
	    (counter 0))
  (if (null? data)
      counter ;;done
      (if (and (= (x (first data)) prevf1)
	       (= (z (first data)) prevf2))
	  (loop (rest data) prevf1 prevf2 counter)
	  (loop (rest data) (x (first data)) (z (first data)) (+ counter 1))))))
 