(define (generate-video-pairs videos-and-sentences)
 (let* ((videos-and-objects
	 (map
	  (lambda (video-and-sentence)
	   (list (first video-and-sentence)
		 (remove-duplicates
		  (removeq 'person
			   (join 
			    (map (lambda (predicate)
				  (map (lambda (a) (x a)) (rest (rest predicate))))
				 (second video-and-sentence)))))))
	  videos-and-sentences))
	(all-video-pairs
	 (remove-if
	  (lambda (pair)	   
	   (null? (intersection (second (first pair))
				(second (second pair)))))
	  (all-pairs videos-and-objects))))
  (map (lambda (pair) (map first pair))
       all-video-pairs)))