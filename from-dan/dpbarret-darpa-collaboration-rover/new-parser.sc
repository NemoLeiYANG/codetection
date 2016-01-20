(load (format #f "/home/~a/darpa-collaboration/rover/toollib-feature-based-trace-generator.sc" (getenv "USER")))
(define *loud-parser?* #f)
(define (parser-dtrace s x)
 (if *loud-parser?*
     (dtrace s x)
     x))

(define *subjects* '(the-robot))
(define *verbs* '(went))
(define *one-object-adverb-prepositions*
 '(left-of right-of behind in-front-of around towards away-from past))
(define *one-object-adjective-prepositions*
 '(left-of right-of behind in-front-of))
(define *learned-one-object-prepositions*
 '(left-of right-of in-front-of behind towards away-from))

(define *two-object-adverb-prepositions* '(between))
(define *two-object-adjective-prepositions* '(between))
(define *objects* '(the-table the-chair the-box the-ball the-bucket the-cone the-stool the-bag))
(define *conjunctions* '(and))
(define *temporal-conjunctions* '(then))

(define *connectors* (list 'which-is))

(define *all-words* (append *subjects* *verbs* *one-object-adverb-prepositions* *one-object-adjective-prepositions* *two-object-adverb-prepositions* *two-object-adjective-prepositions* *objects* *conjunctions* *temporal-conjunctions* *connectors*))

(define (parse-sentence sentence)
 (parser-dtrace "parse-sentence returned:"
 (parse-words (string->words sentence *all-words*))))
  

(define (parse-words words)
 (parser-dtrace "parse-sentence" words)
 (all-values
  (list
   'sentence
   (let* ((subject-and-leftovers (parse-subject words))
	  (predicate-and-leftovers (parse-predicate (second subject-and-leftovers))))
    (when (not (null? (second predicate-and-leftovers))) (fail))
    (list (first subject-and-leftovers)
	  (first predicate-and-leftovers))))))

(define (parse-subject words)
 (parser-dtrace "parse-subject" words)
 (let ((subject (first words)))
 (if (member subject *subjects*)
     (list (list 'subject subject) (rest words))
     (fail))))

(define (parse-verb words)
 (parser-dtrace "parse-verb" words)
 (let ((verb (first words)))
  (if (member verb *verbs*)
     (list (list 'verb verb) (rest words))
     (fail))))

(define (parse-temporal-conjunction words)
 (parser-dtrace "parse-temp-conj" words)
 (let ((temporal-conjunction (first words)))
  (if (member temporal-conjunction *temporal-conjunctions*)
     (list (list 'temporal-conjunction temporal-conjunction) (rest words))
     (fail))))

(define (parse-a-word words category lexicon)
 (parser-dtrace "parse word" (list category words lexicon))
 (parser-dtrace "word-parse returned:"
	 (let ((parsed-word (first words)))
  (if (member parsed-word lexicon)
     (list (list category parsed-word) (rest words))
     (fail)))))

(define (parse-subject words)
 (parse-a-word words 'subject *subjects*))

(define (parse-verb words)
 (parse-a-word words 'verb *verbs*))

(define (parse-noun words)
 (parse-a-word words 'noun *objects*))

(define (parse-temporal-conjunction words)
 (parse-a-word words 'temporal-conjunction *temporal-conjunctions*))

(define (parse-one-object-adverb-preposition words)
 (parse-a-word words 'one-object-adverb-preposition *one-object-adverb-prepositions*))

(define (parse-two-object-adverb-preposition words)
 (parse-a-word words 'two-object-adverb-preposition *two-object-adverb-prepositions*))

(define (parse-one-object-adjective-preposition words)
 (parse-a-word words 'one-object-adjective-preposition *one-object-adjective-prepositions*))

(define (parse-two-object-adjective-preposition words)
 (parse-a-word words 'two-object-adjective-preposition *two-object-adjective-prepositions*))

(define (another-prepositional-phrase? words)
 (and (>= (length words) 2) (member (first words) *conjunctions*)
      (or (member (second words) *one-object-adverb-prepositions*)
	  (member (second words) *two-object-adverb-prepositions*))))

(define (parse-conjunction words)
 (parse-a-word words 'conjunction *conjunctions*))

(define (parse-adjective-phrase words)
 (parser-dtrace "parse-adjective-phrase" words)
 (either
  (let* ((connector-and-words (if (equal? (first words) 'which-is)
				  (list 'which-is (rest words))
				  (fail)))
	 (words (second connector-and-words))
	 (single-object-preposition-and-words
	  (parse-one-object-adjective-preposition words))
	 (preposition (first single-object-preposition-and-words))
	 (words (second single-object-preposition-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase (first object-phrase-and-words))
	 (words (second object-phrase-and-words)))
   (if (and (>= (length words) 2)
	    (equal? (first words) 'and) (equal? (second words) 'which-is))
       (let* ((more-adjective-phrases-and-words (parse-adjective-phrase (rest words)))
	      (more-phrases (first more-adjective-phrases-and-words))
	      (words (second more-adjective-phrases-and-words)))
	(list (list 'adjective-phrase (cons (list preposition object-phrase)
					   (second more-phrases)))
	      words))
       (list (list 'adjective-phrase (list (list preposition object-phrase))) words)))
  (let* ((connector-and-words (if (equal? (first words) 'which-is)
				  (list 'which-is (rest words))
				  (fail)))
	 (words (second connector-and-words))
	 (two-object-preposition-and-words
	  (parse-two-object-adjective-preposition words))
	 (preposition (first two-object-preposition-and-words))
	 (words (second two-object-preposition-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase (first object-phrase-and-words))
	 (words (second object-phrase-and-words))
	 (conjunction-and-words (parse-conjunction words))
	 (conjunction (first conjunction-and-words))
	 (words (second conjunction-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase2 (first object-phrase-and-words))
	 (words (second object-phrase-and-words)))
	 
   (if (and (>= (length words) 2)
	    (equal? (first words) 'and) (equal? (second words) 'which-is))
       (let* ((more-adjective-phrases-and-words (parse-adjective-phrase (rest words)))
	      (more-phrases (first more-adjective-phrases-and-words))
	      (words (second more-adjective-phrases-and-words)))
	(list (list 'adjective-phrase (cons (list preposition object-phrase object-phrase2)
					   (second more-phrases)))
	      words))
       (list (list 'adjective-phrase (list (list preposition object-phrase object-phrase2))) words)))))
	 	 

(define (parse-object-phrase words)
 (parser-dtrace "parse-object-phrase" words)
 ;; no either because we always use the 'which-is if its available
 ;; this is to prevent ambiguity with preposition attachment
(parser-dtrace "parse-object-phrase-returned:"
	(let* ((noun-and-words (parse-noun words))
	 (noun (first noun-and-words))
	 (words (second noun-and-words)))
   (cond
    ((and (>= (length words) 1) (equal? (first words) 'which-is))
     (let* ((adjective-phrase-and-words (parse-adjective-phrase words))
	    (adjective-phrase (first adjective-phrase-and-words))
	    (words (second adjective-phrase-and-words)))
      (list (list 'object-phrase (list noun adjective-phrase)) words)))
    (else
     (list (list 'object-phrase noun) words))))))
	      

(define (parse-prepositional-phrase words)
 (parser-dtrace "parse-prepositional-phrase" words)
 (parser-dtrace "prepositional-phrase-parse returned:"
	 (either
  (let* ((preposition-and-words (parse-one-object-adverb-preposition words))
	 (preposition (first preposition-and-words))
	 (words (second preposition-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase (first object-phrase-and-words))
	 (words (second object-phrase-and-words)))
   (parser-dtrace "in the midst of parsing single-object prepositional phrase" #t)
   (if (parser-dtrace "another prep phrase?" (another-prepositional-phrase? words))
       (let* ((more-prepositional-phrases-and-words (parse-prepositional-phrase (rest words)))
	     (more-prepositional-phrases (parser-dtrace "more-prepositional-phrases:"(first more-prepositional-phrases-and-words)))
	     (words (second more-prepositional-phrases-and-words)))
	(list (cons (list 'prepositional-phrase (list preposition object-phrase))
		    more-prepositional-phrases)
	      words))
       (list (list (list 'prepositional-phrase (list preposition object-phrase))) words)))
  (let* ((preposition-and-words (parse-two-object-adverb-preposition words))
	 (preposition (first preposition-and-words))
	 (words (second preposition-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase1 (first object-phrase-and-words))
	 (words (second object-phrase-and-words))
	 (conjunction-and-words (parse-conjunction words))
	 (conjunction (first conjunction-and-words))
	 (words (second conjunction-and-words))
	 (object-phrase-and-words (parse-object-phrase words))
	 (object-phrase2 (first object-phrase-and-words))
	 (words (second object-phrase-and-words)))
   (if (another-prepositional-phrase? words)
       (let* ((more-prepositional-phrases-and-words (parse-prepositional-phrase (rest words)))
	     (more-prepositional-phrases (first more-prepositional-phrases-and-words))
	     (words (second more-prepositional-phrases-and-words)))
	(list (cons (list 'prepositional-phrase (list preposition object-phrase1 conjunction object-phrase2))
		    more-prepositional-phrases)
	      words))
       
       (list (list (list 'prepositional-phrase (list preposition object-phrase1 conjunction object-phrase2)))
		     words))))))
  

(define (parse-predicate words)
 (parser-dtrace "parse-predicate" words)
 (parser-dtrace "parse-predicate-returned:"
  (either
   (let* ((verb-and-words (parse-verb words))
	  (verb (first verb-and-words))
	  (words (second verb-and-words))
	  (prepositional-phrase-and-words (parse-prepositional-phrase words))
	  (prepositional-phrase (first prepositional-phrase-and-words))
	  (words (second prepositional-phrase-and-words)))
    (parser-dtrace "in the midst of parsing predicate" words)
    (if (null? words)
	(list (list 'predicate (list (list verb prepositional-phrase))) words)
	(let* ((conjunction-and-words (parse-temporal-conjunction words))
	       (conjunction (first conjunction-and-words))
	       (words (second conjunction-and-words))
	       (predicate-and-words (parse-predicate words))
	       (predicate (first predicate-and-words))
	       (words (second predicate-and-words)))
	 (list (list 'predicate (cons (list verb prepositional-phrase)
				      (second predicate)))
	       words)))))))


(define (string->words string symbols)
;;(parser-dtrace "string->words returned:"
	(let* ((strings (fields string)))
  (let loop ((strings strings))
;;   (parser-dtrace "loop:" strings)
   (if (null? strings)
       '()
       (let ((symbol-and-strings
	      (let loop2 ((word-strings '())
			  (strings strings))
	       ;;(parser-dtrace "loop2:" (list word-strings strings))
	       (if (member (string->symbol (string-upcase (string-join "-" (reverse word-strings)))) symbols)
		   (list (string->symbol (string-upcase (string-join "-" (reverse word-strings)))) strings)
		   (if (null? strings)
		       (list 'bad '())
		       (loop2 (cons (first strings) word-strings) (rest strings)))))))
	(if (null? (second symbol-and-strings))
	    (list (first symbol-and-strings))
	    (cons (first symbol-and-strings) (loop (second symbol-and-strings)))))))))

(define (simplify-parse-tree parse-tree)
 ;;(pp parse-tree)
(map (lambda (predicate)
      (map (lambda (adverbial-phrase)
	    adverbial-phrase)
	    (second predicate)))
      (second (second(second (first parse-tree))))))

(define (adverb-preposition->function preposition)
 (case preposition
  ((left-of)
   trace-left-of)
  ((right-of)
   trace-right-of)
  ((in-front-of)
   trace-in-front-of)
  ((behind)
   trace-behind)
  ((between)
   trace-between)
  ((towards)
   trace-towards)
  ((away-from)
   trace-away-from)
  ((past)
   trace-past)
  ((around)
   trace-around)
  (else
   (parser-dtrace "unknown adverb preposition:" preposition)
   (fuck-up))))

(define (adjective-preposition->function preposition)
 (case preposition
  ((left-of)
   left-of)
  ((right-of)
   right-of)
  ((in-front-of)
   in-front-of)
  ((behind)
   behind)
  ((between)
   between)
  (else
   (parser-dtrace "unknown adjective preposition:" preposition)
   (fuck-up))))

(define *object-instantiations*
 (list
  (list 'the-table (vector 5 2))
  (list 'the-table (vector 0 2))
  (list 'the-table (vector -3 1))
  (list 'the-chair (vector 3 2))
  (list 'the-box (vector -2 2))
  (list 'the-box (vector 8 4))
  (list 'the-ball (vector -5 2))
  (list 'the-bucket (vector -3 4))
  (list 'the-cone (vector 0 4))
  (list 'the-stool (vector 3 4))))


(define *objects1*
(list
 (list 'the-table (vector 5 2.5))
 (list 'the-table (vector 0 1.5))
 (list 'the-chair (vector 3 2))
 (list 'the-box (vector 2 3))))

(define *objects2*
 (list
  (list 'the-chair (vector 0 1))
  (list 'the-chair (vector 1 3))
  (list 'the-box (vector 0 2))
  (list 'the-ball (vector 5 2))))

(define *objects3*
 (list
  (list 'the-box (vector -2 2))
  (list 'the-box (vector 8 4))
  (list 'the-ball (vector 5 2))
  (list 'the-bucket (vector -3 4))))

(define *objects4*
 (list (list 'the-ball (vector -2 2))
       (list 'the-ball (vector 2 2))
       (list 'the-bucket (vector -3 4))
       (list 'the-cone (vector 0 2.5))
       (list 'the-stool (vector 1 1))))

(define *objects5*
 (list (list 'the-bucket (vector 3 1))
       (list 'the-bucket (vector 3.2 4))
       (list 'the-cone (vector 0 4))
       (list 'the-stool (vector .5 .5))
       (list 'the-table (vector 5 2))))


(define *objects6*
 (list
  (list 'the-cone (vector 0 4))
  (list 'the-cone (vector 0 4))
  (list 'the-stool (vector 3 4))
  (list 'the-chair (vector 3 2))
  (list 'the-box (vector -2 2))))
  
(define (object-phrase->scored-points object-phrase objects)
 (parser-dtrace "input to object-phrase->scored-points:" object-phrase)
 (parser-dtrace
  "object-phrase->point returned:"
  (if (equal? (first (second object-phrase)) 'noun)
      (list (a-member-of
	     (parser-dtrace "objects to choose from:"(remove-if-not
	      (lambda (o)
	       (equal? (first o)
		       (second (second object-phrase))))
	      objects)))
	    1)
      (let* ((object-class (second (first (second object-phrase))))
	     (object (a-member-of
		      (remove-if-not
		       (lambda (o)
			(equal? (first o)
				object-class))
		       objects)))
	     (score
	      (reduce
	       *
	       (map
		(lambda (e)
		 (parser-dtrace "element of adjective phrase" e)
		 (if (equal? (first (first e)) 'ONE-OBJECT-ADJECTIVE-PREPOSITION)
		     (let ((other-scored-object (object-phrase->scored-points
						 (second e)
						 objects)))
		      (when (equal? (parser-dtrace "other object:"(first other-scored-object)) (parser-dtrace "object:" object))
		       (parser-dtrace "objects equal, failing" (list object other-scored-object))
		       (fail))
		      (* ((adjective-preposition->function (second (first e)))
			  (second object)
			  (second (first other-scored-object)))
			 (second other-scored-object)))
		     (let ((other-scored-object1 (object-phrase->scored-points
						  (second e)
						  objects))
			   (other-scored-object2 (object-phrase->scored-points
						  (third e)
						  objects)))
		      (when (or (equal? (first other-scored-object1) object)
				(equal? (first other-scored-object2) object)
				(equal? (first other-scored-object1) (first other-scored-object2)))
		       (fail))
		      (* ((adjective-preposition->function (second (first e)))
			  (second object)
			  (second (first other-scored-object1))
			  (second (first other-scored-object2)))))))
		     
		(second (second (second object-phrase))))
	       1)))
       (list object score)))))

(define (object-phrase->point object-phrase objects)
 (parser-dtrace "object-phrase:" object-phrase)
 (let* ((scored-objects (parser-dtrace "scored-objects:"
				(all-values (object-phrase->scored-points object-phrase objects))))
	(sorted-objects (sort scored-objects > second)))
  (second (first (first sorted-objects)))))

(define (parse-tree->parse-functions parse-tree objects)
 (let* ((simplified-parse-tree (simplify-parse-tree parse-tree)))
  (list->vector
   (cons
    (vector
	  (lambda (fvs i)
	   (trace-adjacent-points-not-too-close (map-vector x fvs) .15))
	  (lambda (fvs i)
	   (trace-not-too-close-to-obstacles
	    (map-vector x fvs)
	    (list->vector (map second objects))
	    .1
	    (list->vector (map (lambda (o) .3) objects)))))
    (let* ((time-function-sets 
	    (map
	     (lambda (predicate)
	      (map
	       (lambda (adverbial-phrase)
		(parser-dtrace "adverbial-phrase" adverbial-phrase)
		(if (equal? (first (first (second adverbial-phrase)))
			    'ONE-OBJECT-ADVERB-PREPOSITION)
		    (let* ((object (object-phrase->point (second (second adverbial-phrase))
							 objects))
			   (adverb (second (first (second adverbial-phrase))))
			   (function (parser-dtrace "prep->function output:"
					     (adverb-preposition->function adverb))))
		     (list
		      (cond
		       ((equal? adverb 'past) 1)
		       ((equal? adverb 'around) 2)
		       (else 0))
		      (lambda (fvs i)
		       (function
			fvs i
			object))))
		    (let* ((object1 (object-phrase->point (second (second adverbial-phrase))
							  objects))
			   (object2 (object-phrase->point (fourth (second adverbial-phrase))
							  objects))
			   (adverb (second (first (second adverbial-phrase))))
			   (function (parser-dtrace "2prep->function output:"
					     (adverb-preposition->function adverb))))
		     (list
		      (cond
		       ((equal? adverb 'past) 1)
		       ((equal? adverb 'around) 2)
		       (else 0))
		      (lambda (fvs i)
		       (function
			fvs i
			object1 object2))))))
	       
	       predicate))
	     simplified-parse-tree)))
      (let loop ((time-function-sets time-function-sets))
       (if (null? time-function-sets)
	   '()
	   (append
	    (append
	     (map-n (lambda (i) (vector )) (maximum (map first (first time-function-sets))))
	     (list (list->vector (map second (first time-function-sets)))))
	    (loop (rest time-function-sets))))))))))

(define (generate-random-simple-sentence objects number-of-predicates one-object-prepositions)
 (string-append "the robot "
		(reduce string-append
			(map-n
			 (lambda (i)
			  (string-append (if (> i 0) "then " "")
					 "went "
					 (random-member one-object-prepositions)
					 " " ;;the "
					 (random-member objects)
					 " "))
			 number-of-predicates)
			"")))

(define (parsed-object-phrase->linked-references tree modified-object-reference)
 (parser-dtrace "object-phrase function:" (list tree modified-object-reference))
 (parser-dtrace "object-phrase function returned:"
	 (let adjective-loop ((tree tree)
		      (references '())
		      (current-reference modified-object-reference)
		      (links '()))
  (if (null? tree)
      (list references links current-reference)
      (if (equal? (first (second (second (first tree)))) 'noun)
      (let* ((adjective (second (first (first tree))))
	     (noun (second (second (second (first tree))))))
       (parser-dtrace "we have a unmodified object:" (first tree))
       (parser-dtrace "adj noun" (list adjective noun))
       (adjective-loop (rest tree)
		       (cons (list noun (+ current-reference 1)) references)
		       (+ current-reference 1)
		       (cons (list adjective
				   modified-object-reference
				   (+ current-reference 1))
			     links)))
      (let* ((adjective (second (first (first tree))))
	     (noun (second (first (second (second (first tree))))))
	     (references (cons (list noun (+ current-reference 1)) references))
	     (links (cons (list adjective
				modified-object-reference
				(+ current-reference 1))
			  links))
	     (current-reference (+ current-reference 1))
	     (new-references-and-links
		  (parsed-object-phrase->linked-references
		   (second (second (second (second (first tree)))))
		   current-reference)))
       (parser-dtrace "object branch 2" (list adjective noun))
       (adjective-loop (rest tree)
		       (append references (first new-references-and-links))
		       (+ (third new-references-and-links) 1)
		       (append links (second new-references-and-links)))))))))
      
	     

(define (parsed-prepositional-phrase->linked-references tree robot-reference)
 (parser-dtrace "prep-phrase function:" (list tree robot-reference))
 (let adverb-loop ((tree tree)
		   (references '())
		   (current-reference robot-reference)
		   (links '()))
  (if (null? tree)
      (list references links current-reference)
      (if (equal? (first (second (second (second (first tree))))) 'noun)
	  (let* ((preposition (second (first (second (first tree)))))
		 (noun (second (second(second (second (first tree))))))
		 (current-reference (+ current-reference 1))
		 (references (cons (list noun
					 current-reference)
				   references))
		 (links (cons (list preposition
				    robot-reference
				    current-reference)
			      links)))
	   (adverb-loop (rest tree)
			references
			current-reference
			links))
	  (let* ((preposition (second (first (second (first tree)))))
		 (noun (second (first (second(second (second (first tree)))))))
		 (current-reference (+ current-reference 1))
		 (references (cons (list noun
					 current-reference)
				   references))
		 (links (cons (list preposition
				    robot-reference
				    current-reference)
			      links))
		 (new-references-and-links
		  (parsed-object-phrase->linked-references
		   (second (second (second(second (second
						   (first tree))))))
		   current-reference)))
	   (adverb-loop (rest tree)
			(append references (first new-references-and-links))
			(third new-references-and-links)
			(append links (second new-references-and-links))))))))
      
	     

(define (parsed-sentence->linked-references parse)
 (let* ((tree (simplify-parse-tree parse)))
  (let time-loop ((tree tree)
		  (references (list ))
		  (current-reference 0)
		  (links (list ))
		  (phase 0))

   (if (null? tree)
       (list references links)
       (let* ((references (cons (list 'robot current-reference phase) references))
	      (new-references-and-links
	       (parsed-prepositional-phrase->linked-references
		(first tree) current-reference)))    
	(time-loop (rest tree)
		   (append references (first new-references-and-links))
		   (+ (third new-references-and-links) 1)
		   (append links (second new-references-and-links))
		   (+ phase 1)))))))

(define foo #f)