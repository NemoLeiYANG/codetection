;;toollib-analysis.sc
;;tools for putting sentential meanings to/from traces of rover path
;;Scott Bronikowski
;;20 August 2014

;;Revised generator-recognizer-parser 19 September 2014
;;definitions of word types
(define *subjects* '(the-robot))
(define *verbs* '(went))
(define *one-object-prepositions* '(left-of right-of behind in-front-of around towards away-from past))
(define *two-object-prepositions* '(between))
(define *objects* '(the-table the-chair the-box the-ball the-bucket the-cone))
(define *conjunctions* '(and))
(define *temporal-prepositions* '(then))
(define *word-lexicon* (cons *subjects*
			   (cons *verbs*
				 (cons *one-object-prepositions*
				       (cons *two-object-prepositions*
					     (cons *objects*
						   (cons *conjunctions*
							 (cons *temporal-prepositions* '()))))))))

;;generator section
(define (a-subject) (cons (a-member-of *subjects*) '()))
(define (a-verb) (cons (a-member-of *verbs*) '()))
(define (a-one-object-preposition) (cons (a-member-of *one-object-prepositions*) '()))
(define (a-two-object-preposition) (cons (a-member-of *two-object-prepositions*) '()))
(define (an-object) (cons (a-member-of *objects*) '()))
(define (a-conjunction) (cons (a-member-of *conjunctions*) '()))
(define (a-temporal-preposition) (cons (a-member-of *temporal-prepositions*) '()))
(define (a-prepositional-phrase)
 (either (append (a-one-object-preposition) (an-object))
	 (append (a-two-object-preposition) (an-object) (a-conjunction) (an-object))))
(define (a-predicate)
 (either (append (a-verb) (a-prepositional-phrase))
	 (append (a-verb) (a-prepositional-phrase)
		 (a-temporal-preposition) (a-prepositional-phrase))
	 (append (a-verb) (a-prepositional-phrase)
		 (a-temporal-preposition) (a-prepositional-phrase)
		 (a-temporal-preposition) (a-prepositional-phrase))
	 (append (a-verb) (a-prepositional-phrase)
		 (a-temporal-preposition) (a-prepositional-phrase)
		 (a-temporal-preposition) (a-prepositional-phrase)
		 (a-temporal-preposition) (a-prepositional-phrase))
	))
;;could define a-predicate recursively, but then how would I put a bound on how many prepositional phrases to use when building all-sentences?
(define (a-sentence) (append (a-subject) (a-predicate)))

(define (print-sentences)
 (for-effects
  (write (a-sentence))
  (newline)))
;; end generator

;; recognizer section
(define (strip-a-word words lexicon)
 (when (null? words) (fail))
 (unless (memq (first words) lexicon) (fail))
 (rest words))

(define (strip-a-subject words) (strip-a-word words *subjects*))

(define (strip-a-verb words) (strip-a-word words *verbs*))

(define (strip-a-one-object-preposition words)
 (strip-a-word words *one-object-prepositions*))

(define (strip-a-two-object-preposition words)
 (strip-a-word words *two-object-prepositions*))

(define (strip-an-object words) (strip-a-word words *objects*))

(define (strip-a-conjunction words) (strip-a-word words *conjunctions*))

(define (strip-a-temporal-preposition words)
 (strip-a-word words *temporal-prepositions*))

(define (strip-a-prepositional-phrase words)
 (either (strip-an-object (strip-a-one-object-preposition words))
	 (strip-an-object
	  (strip-a-conjunction
	   (strip-an-object (strip-a-two-object-preposition words))))))

(define (strip-a-predicate words)
 (either (strip-a-prepositional-phrase (strip-a-verb words)) ;;1-prep-phrase
	 (strip-a-prepositional-phrase ;;2-prep-phrases
	  (strip-a-temporal-preposition
	   (strip-a-prepositional-phrase
	    (strip-a-verb words))))
	 (strip-a-prepositional-phrase ;;3-prep-phrases
	  (strip-a-temporal-preposition
	   (strip-a-prepositional-phrase
	    (strip-a-temporal-preposition
	     (strip-a-prepositional-phrase
	      (strip-a-verb words))))))
	 (strip-a-prepositional-phrase ;;4-prep-phrases
	  (strip-a-temporal-preposition
	   (strip-a-prepositional-phrase
	    (strip-a-temporal-preposition
	     (strip-a-prepositional-phrase
	      (strip-a-temporal-preposition
	       (strip-a-prepositional-phrase
		(strip-a-verb words))))))))))

(define (strip-a-sentence words)
 (strip-a-predicate (strip-a-subject words)))

(define (sentence? words)
 (possibly? (null? (strip-a-sentence words))))
;;end recognizer

;;parser section
(define-structure state stack words)

(define (parse-a-word state category lexicon)
 (let ((words (state-words state)))
  (when (null? words) (fail))
  (unless (memq (first words) lexicon) (fail))
  (make-state (cons (list category (first words))
		    (state-stack state))
	      (rest words))))

(define (pop-one category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category
			  (first stack))
		    (rest stack))
	      (state-words state))))

(define (pop-two category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category
			  (second stack)
			  (first stack))
		    (rest
		     (rest stack)))
	      (state-words state))))

(define (pop-three category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category
			  (third stack)
			  (second stack)
			  (first stack))
		    (rest
		     (rest
		      (rest stack))))
	      (state-words state))))

(define (pop-four category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category
			  (fourth stack)
			  (third stack)
			  (second stack)
			  (first stack))
		    (rest
		     (rest
		      (rest
		       (rest stack)))))
	      (state-words state))))

(define (pop-five category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category
			  (fifth stack)
			  (fourth stack)
			  (third stack)
			  (second stack)
			  (first stack))
		    (rest
		     (rest
		      (rest
		       (rest
			(rest stack))))))
	      (state-words state))))

(define (pop-six category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category
			  (sixth stack)
			  (fifth stack)
			  (fourth stack)
			  (third stack)
			  (second stack)
			  (first stack))
		    (rest
		     (rest
		      (rest
		       (rest
			(rest
			 (rest stack)))))))
	      (state-words state))))

(define (pop-seven category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category
			  (seventh stack)
			  (sixth stack)
			  (fifth stack)
			  (fourth stack)
			  (third stack)
			  (second stack)
			  (first stack))
		    
		    (rest
		     (rest
		      (rest
		       (rest
			(rest
			 (rest
			  (rest stack))))))))
	      (state-words state))))

(define (pop-eight category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category
			  (eighth stack)
			  (seventh stack)
			  (sixth stack)
			  (fifth stack)
			  (fourth stack)
			  (third stack)
			  (second stack)
			  (first stack))
		    
		    (rest
		     (rest
		      (rest
		       (rest
			(rest
			 (rest
			  (rest
			   (rest stack)))))))))
	      (state-words state))))

(define (parse-a-subject state) (parse-a-word state 'subj *subjects*))

(define (parse-a-verb state) (parse-a-word state 'v *verbs*))

(define (parse-a-one-object-preposition state)
 (parse-a-word state 'prep-1 *one-object-prepositions*))

(define (parse-a-two-object-preposition state)
 (parse-a-word state 'prep-2 *two-object-prepositions*))

(define (parse-an-object state) (parse-a-word state 'obj *objects*))

(define (parse-a-conjunction state) (parse-a-word state 'conj *conjunctions*))

(define (parse-a-temporal-preposition state)
 (parse-a-word state 'prep-t *temporal-prepositions*))

(define (parse-a-prepositional-phrase state)
 (either (pop-two 'prep-ph (parse-an-object
			    (parse-a-one-object-preposition state)))
	 (pop-four 'prep-ph (parse-an-object
			     (parse-a-conjunction
			      (parse-an-object
			       (parse-a-two-object-preposition state)))))))

(define (parse-a-predicate state)
 (either (pop-two 'pred (parse-a-prepositional-phrase (parse-a-verb state)))
	 (pop-four 'pred (parse-a-prepositional-phrase
			  (parse-a-temporal-preposition
			   (parse-a-prepositional-phrase
			    (parse-a-verb state)))))
	 (pop-six 'pred (parse-a-prepositional-phrase
			  (parse-a-temporal-preposition
			   (parse-a-prepositional-phrase
			    (parse-a-temporal-preposition
			     (parse-a-prepositional-phrase
			      (parse-a-verb state)))))))
	 (pop-eight 'pred (parse-a-prepositional-phrase
			  (parse-a-temporal-preposition
			   (parse-a-prepositional-phrase
			    (parse-a-temporal-preposition
			     (parse-a-prepositional-phrase
			      (parse-a-temporal-preposition
			       (parse-a-prepositional-phrase
				(parse-a-verb state)))))))))))

(define (parse-a-sentence state)
 (pop-two 's (parse-a-predicate (parse-a-subject state))))

(define (a-parse words)
 (let ((state (parse-a-sentence (make-state '() words))))
  (unless (null? (state-words state)) (fail))
  (first (state-stack state))))
;; end parser
;;End revised generator-recognizer-parser

;;Analysis tools

;;hardcoding these variables for testing
(define *datapath* "./data/test-2014-07-31/")
(define *numtraces* 10)

;;need to read in (x1 y1) pairs into a list from file
(define (read-trace filename)  ;;reads trace.txt produced by log-to-track.out
 (read-object-from-file filename))
(define (get-endpoint trace)
 (but-last (last trace)))
(define (get-traces *datapath* *numtraces*)
 (let ((filelist
	(map-n (lambda (i) (format #f "~atrial~a/trace.txt" *datapath* (number->padded-string-of-length (+ i 1) 3))) *numtraces*)))
  (map read-trace filelist)))

;;made this a thunk so it isn't computed every time I load the file (takes a while when sentence space is big)
(define (all-sentences) (all-values (a-sentence)))
;;might need to redefine this as a thunk if numtraces gets very big
(define all-traces (get-traces *datapath* *numtraces*))

;;need to have lexicon for objects and prepositions
(define the-table '(the-table (-1.26 2.55))) ;;hardcoded for now
(define the-chair '(the-chair (1.26 2.54)))
;;need dummy obstacle locations for the-box the-ball the-bucket the-cone
(define the-box '(the-box (99 99)))
(define the-ball '(the-ball (99 99)))
(define the-bucket '(the-bucket (99 99)))
(define the-cone '(the-cone (99 99)))

(define (location-of obstacle)
 (last obstacle))
(define *obstacle-lexicon* (map (lambda (x) (eval x)) objects))

;;distance stuff

(define (fold-polynomial x coeffs)
 (let loop ((s 0) (c (reverse coeffs)))
  (if (null? c)
      s
      (loop (* x (+ s (first c))) (rest c)))))

(define (log-bessel0 kappa)
 (let ((ax (abs kappa)))
  (if (< ax 3.75)
      (log
       (+ 1.0
	  (fold-polynomial (sqr (/ kappa 3.75))
			   '(3.5156229
			     3.0899424
			     1.2067492
			     0.2659732
			     0.360768e-1
			     0.45813e-2))))
      (+ (- ax (* 0.5 (log ax)))
	 (log
	  (+ 0.39894228
	     (fold-polynomial (/ 3.75 ax)
			      '(0.39894228
				0.1328592e-1
				0.225319e-2
				-0.157565e-2
				0.916281e-2
				-0.2057706e-1
				0.2635537e-1
				-0.1647633e-1
				0.392377e-2))))))))

(define (log-von-mises v mean kappa)
 (unless (and (> kappa 0.0)
 	      (and (>= mean (- pi)) (<= mean pi))
 	      (and (>= v (- pi)) (<= v pi)))
  (format #t "~a ~a ~a~%" v mean kappa)
  (panic "log-radial") (abort))
 (let ((x (- v mean)) (log_2pi 1.837877))
  (- (* kappa (cos x)) log_2pi (log-bessel0 kappa))))

(define (log-inverse-sigmoid t a b)
 (log (- 1 (/ (+ 1 (exp (- (* b (- t a)))))))))

(define (distance-between p1 p2)
 (+ (sqr (- (first p1) (first p2)))
    (sqr (- (second p1) (second p2)))))

(define (nearest-obstacle point lexicon)
 (let ((distances
	(map (lambda (x) (distance-between point x))
	     (map location-of lexicon))))
  (first (list-ref lexicon
		   (position (minimum distances)
			     distances)))))

(define (distance-factor point obstacle lexicon)
 (let ((nearest (nearest-obstacle point lexicon)))
  (if (equal? nearest (first obstacle))
      0         ;; return 1 if obstacle is closest, else 0.5 (may need tweaking)
      -0.69315  ;; (log 0.5)
      )))

;;angle and preposition stuff converted from C++
(define (normalize-angle angle)
 (cond
  ((> angle pi) (normalize-angle (- angle two-pi)))
  ((<= angle (- pi)) (normalize-angle (+ angle two-pi)))
  (else angle)))

;; [-pi, pi]
(define (angle-between p1 p2)
 (atan (- (second p1) (second p2))
       (- (first p1) (first p2))))

(define (spatial-preposition-condition robot obstacle lexicon dist-f)
 (let ((distance-multiplier (distance-factor robot obstacle lexicon))
       (angle (angle-between robot (location-of obstacle))))
  (+ (dist-f angle) distance-multiplier)))

(define (left-of robot obstacle lexicon)
 (spatial-preposition-condition
  robot obstacle lexicon
  (lambda (x) (log-von-mises x PI 3))))

(define (right-of robot obstacle lexicon)
 (spatial-preposition-condition
  robot obstacle lexicon
  (lambda (x) (log-von-mises x 0 3))))

(define (in-front-of robot obstacle lexicon)
 (spatial-preposition-condition
  robot obstacle lexicon
  (lambda (x) (log-von-mises x (- (/ PI 2)) 3))))

(define (behind robot obstacle lexicon)
 (spatial-preposition-condition
  robot obstacle lexicon
  (lambda (x) (log-von-mises x (/ PI 2) 3))))

(define (between robot obstacle1 obstacle2)
 (let* ((angle1 (angle-between robot (location-of obstacle1)))
	(angle2 (angle-between robot (location-of obstacle2)))
	(delta-angle (abs (- angle1 angle2)))
	(delta-dist (sqrt (distance-between (location-of obstacle1)
					    (location-of obstacle2)))))
  (+ (log-von-mises delta-angle PI 3)
     (log-inverse-sigmoid delta-dist 50 0.05))))  ;; needs tweaking

;;dummy functions for around towards away-from past
(define (around robot obstacle lexicon) 0)
(define (towards robot obstacle lexicon) 0)
(define (away-from robot obstacle lexicon) 0)
(define (past robot obstacle lexicon) 0)

(define (parse-sentence sentence) (a-parse sentence))

(define (sentence-from-string string)
 (map string->symbol (fields (string-upcase string))))

;;FIXME--this won't work with new sentence structure
(define (score-parse parse-tree lexicon trace)
 (let* ((preposition (last (third (last parse-tree))))
	(endpoint (get-endpoint trace)) ;;using just endpoints for now
	(obj1 (last (fourth (last parse-tree)))) ;;always at least one object
	(obstacle1
	 (list-ref lexicon (position obj1 (map first lexicon))))) 
  (if (some (lambda (x) (equal? x preposition)) two-object-prepositions)
      (let* ;;two-object preposition, need to get second object
	((obj2 (last (sixth (last parse-tree))))
	 (obstacle2
	  (list-ref lexicon (position obj2 (map first lexicon))))) 
       ((eval preposition) endpoint obstacle1 obstacle2))
      ((eval preposition) endpoint obstacle1 lexicon) ;;one-object preposition
      )
  )
 )

(define (score-sentence sentence lexicon trace)
 (score-parse (parse-sentence sentence) lexicon trace))

;;FIXME--this won't work when all-sentences gets very big
(define (produce-score-matrix lexicon traces)
 (map (lambda (sentence)
       (list sentence (map (lambda (trace)
			    (score-sentence sentence lexicon trace))
			   traces)))
      all-sentences))

;;FIXME
(define (highest-scoring-trace-for-sentence lexicon sentence traces)
 (let*
   ((scores
     (map (lambda (trace)
	   (score-sentence sentence lexicon trace))
	  traces))
    (max (maximum scores)))
  (+ (position max scores) 1)))

(define (pretty-hstfs lexicon sentence traces)
 (let
   ((num (highest-scoring-trace-for-sentence lexicon sentence traces)))
  (format #t "The highest scoring trace for ~a is trace ~a~%" sentence num)))

;;FIXME
(define (highest-scoring-sentence-for-trace lexicon trace)
 (let*
   ((scores
     (map (lambda (sentence)
	   (score-sentence sentence lexicon trace))
	  all-sentences))
    (max (maximum scores)))
  (list-ref all-sentences (position max scores))))

(define (pretty-hssft lexicon trace)
 (let
   ((sentence (highest-scoring-sentence-for-trace lexicon trace))
    (num (+ 1 (position trace all-traces))))
  (format #t "The highest scoring sentence for trace ~a is ~a~%" num sentence)))

;;email1 from Jeff 22Aug14
;; A reasonable next step would be to figure out how you can take the parse tree
;; produced by your parser, along with a lexicon and a trace, and produce a score.

;; You would like to produce a function

;;   (score-parse parse-tree lexicon trace) ==> score

;;   lexicon would be a list of pairs ((word1 meaning1) (word2 meaning2) ...)
;;   trace would be a list of x-y coordinates ((x1 y1) (x2 y2) ...)

;; With this you could easily produce a function

;;   (score-sentence sentence lexicon trace)
;;   = (score-parse (parse-sentence sentence) lexicon trace)

;; And with this you can easily write

;;   (produce-score-matrix lexicon traces)

;; that takes a list of traces, and calls your generator to generate all possible
;; sentences, and produces the score matrix.

;; And with this you can easily write

;;   (highest-scoring-sentence-for-trace lexicon trace)

;; that takes a trace and produces the highest scoring sentence (among all of
;; those produced by your generator).

;; And you can also easily write

;;   (highest-scoring-trace-for-sentence lexicon sentence traces)
;;-----------------------------

;;email2 from Jeff 22Aug14
;;    lexicon would be a list of pairs ((word1 meaning1) (word2 meaning2) ...)

;;    I'm envisioning that the (word meaning) pairs would only apply to my
;;    prepositions and objects, since my subject and verb are fixed values.  For
;;    an object, the meaning would simply be the x-y location of the
;;    object--i.e., (the-table (2.5 1.25)).  For a preposition, the meaning would
;;    be a function, similar to the ones I wrote in C last week, that take an
;;    object x-y position and a robot x-y position and return a score that
;;    reflects how well or poorly that preposition describes the robot's
;;    relationship to the object.  Am I on the right track with this?

;; Yes.

;; The only nontrivial part of this exercise is to figure out how to combine the
;; meaning of a preposition and a noun to yield a meaning of a prepositional
;; phrase. Everything else literally would take someone with Dan or Haonan's
;; level of familiarity with Scheme (which is not much) a few minutes. That is
;; why it is important to learn Scheme.

;; Here is the nontrival part. Suppose a trace is a list of x-y-theta triples.
;; And suppose I have coded a Scheme function (in-front-of coordinate1 coordinate2)
;; which takes two x-y coordinates and returns a score for the first being in
;; front of the second. You take the meaning of the word "in front of" to be

;; (lambda (object)
;;  (lambda (trace)
;;   (in-front-of (but-last (last trace)) object)))

;; and you take the meaning of "the table" to be something like

;; '(42 915)

;; and then you call the meaning of "in front of" on the meaning of "the table"
;; and get

;; (lambda (trace)
;;  (in-front-of (but-last (last trace)) '(42 915)))

;; Then (score-parse parse-tree lexicon trace) works by looking up "in front of"
;; and "the table" in the lexicon, computing the above, and then calling
;; (lambda (trace) ...) on trace to get the score.

;; This all can be done in less than a page of Scheme code.
;;----------------------

