;;definitions of word types
(define subjects '(the-robot))
(define verbs '(went))
(define one-object-prepositions '(left-of right-of behind in-front-of around towards away-from past))
(define two-object-prepositions '(between))
(define objects '(the-table the-chair the-box the-ball the-bucket the-cone))
(define conjunctions '(and))
(define word-lexicon (cons subjects
			   (cons verbs
				 (cons one-object-prepositions
				       (cons two-object-prepositions
					     (cons objects
						   (cons conjunctions '())))))))

;;hardcoding these variables for testing
(define datapath "./data/test-2014-07-31/")
(define numtraces 10)

;; Generator for robot speech control grammar (adapted from EE570 mad-libs.sc)
;; Author: Scott Bronikowski
;; Date: 20 August 2014


(define (a-subject) (cons (a-member-of subjects) '()))
;;(list (a-member-of subjects)))
;;(either '(the-robot)))

(define (a-verb) (cons (a-member-of verbs) '()))
;;(list (a-member-of verbs)))
 ;;(either '(went)))

(define (a-one-object-preposition) (cons (a-member-of one-object-prepositions) '()))
;; (list (a-member-of one-object-prepositions)))
;; (either '(left-of) '(right-of) '(behind) '(in-front-of)))

(define (a-two-object-preposition) (cons (a-member-of two-object-prepositions) '()))
;; (list (a-member-of two-object-prepositions)))
;; (either '(between)))

;;(define (an-article) (either '(the)))

(define (an-object) (cons (a-member-of objects) '()))
;;(list (a-member-of objects)))
;;(either '(the-table) '(the-chair)))

(define (a-conjunction) (cons (a-member-of conjunctions) '()))
;;(list (a-member-of conjunctions)))
;;(either '(and)))

(define (a-predicate)
 (either (append (a-verb) (a-one-object-preposition) (an-object))
	 (append (a-verb) (a-two-object-preposition) (an-object) (a-conjunction) (an-object))))
;;;**FIXME** need to change this to separate the prepositional phrase from the verb, and then link multiple prepositional phrases

 (define (a-sentence) (append (a-subject) (a-predicate)))

 (define (print-sentences)
  (for-effects
   (write (a-sentence))
   (newline)))

;; end generator

;; Recognizer for robot speech control grammar (adapted from EE570 recognizer.sc)
;; Author: Scott Bronikowski
;; Date: 20 August 2014

(define (strip-a-word words lexicon)
 (when (null? words) (fail))
 (unless (memq (first words) lexicon) (fail))
 (rest words))

(define (strip-a-subject words)
 (strip-a-word words subjects));;'(the-robot)))

(define (strip-a-verb words)
 (strip-a-word words verbs));;'(went)))

(define (strip-a-one-object-preposition words)
 (strip-a-word words one-object-prepositions));;'(left-of right-of behind in-front-of)))

(define (strip-a-two-object-preposition words)
 (strip-a-word words two-object-prepositions));;'(between)))

(define (strip-an-object words)
 (strip-a-word words objects));;'(the-table the-chair)))

(define (strip-a-conjunction words)
 (strip-a-word words conjunctions));;'(and)))

(define (strip-a-predicate words)
 (either (strip-an-object (strip-a-one-object-preposition (strip-a-verb words)))
	 (strip-an-object
	  (strip-a-conjunction
	   (strip-an-object (strip-a-two-object-preposition (strip-a-verb words)))))))

(define (strip-a-sentence words)
 (strip-a-predicate (strip-a-subject words)))

(define (sentence? words)
 (possibly? (null? (strip-a-sentence words))))

;;end recognizer

;; Parser for robot speech control grammar (adapted from EE570 parser.sc)
;; Author: Scott Bronikowski
;; Date: 20 August 2014

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
  (make-state (cons (list category (first stack))
		    (rest stack))
	      (state-words state))))

(define (pop-two category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category (second stack) (first stack))
		    (rest (rest stack)))
	      (state-words state))))

(define (pop-three category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category (third stack) (second stack) (first stack))
		    (rest (rest (rest stack))))
	      (state-words state))))

(define (pop-four category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category (fourth stack) (third stack) (second stack) (first stack))
		    (rest (rest (rest (rest stack)))))
	      (state-words state))))

(define (pop-five category state)
 (let ((stack (state-stack state)))
  (make-state (cons (list category
			  (fifth stack)
			  (fourth stack)
			  (third stack)
			  (second stack)
			  (first stack))
		    (rest (rest (rest (rest (rest stack))))))
	      (state-words state))))

(define (parse-a-subject state)
 (parse-a-word state 'subj subjects))
                           ;;'(the-robot)))

(define (parse-a-verb state)
 (parse-a-word state 'v verbs))
                        ;;'(went)))

(define (parse-a-one-object-preposition state)
 (parse-a-word state 'prep-1 one-object-prepositions))
                             ;;'(left-of right-of behind in-front-of)))

(define (parse-a-two-object-preposition state)
 (parse-a-word state 'prep-2 two-object-prepositions))
	                     ;;'(between)))

(define (parse-an-object state)
 (parse-a-word state 'obj objects))
                          ;;'(the-table the-chair)))

(define (parse-a-conjunction state)
 (parse-a-word state 'conj conjunctions))
                           ;;'(and)))

(define (parse-a-predicate state)
 (either (pop-three 'pred (parse-an-object (parse-a-one-object-preposition (parse-a-verb state))))
	 (pop-five 'pred (parse-an-object (parse-a-conjunction (parse-an-object (parse-a-two-object-preposition (parse-a-verb state))))))))

(define (parse-a-sentence state)
 (pop-two 's (parse-a-predicate (parse-a-subject state))))

(define (a-parse words)
 (let ((state (parse-a-sentence (make-state '() words))))
  (unless (null? (state-words state)) (fail))
  (first (state-stack state))))

;; end parser

;; new stuff

;;need to read in (x1 y1) pairs into a list from file
(define (read-trace filename)  ;;reads trace.txt produced by log-to-track.out
 (read-object-from-file filename))
(define (get-endpoint trace)
 (but-last (last trace)))
(define (get-traces datapath numtraces)
 (let ((filelist
	(map-n (lambda (i) (format #f "~atrial~a/trace.txt" datapath (number->padded-string-of-length (+ i 1) 3))) numtraces)))
  (map read-trace filelist)))


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
(define obstacle-lexicon (map (lambda (x) (eval x)) objects))
 ;;(cons the-table (cons the-chair '())))

;;distance stuff
(define (distance-between p1 p2)
 (sqrt (+ (expt (- (first p1) (first p2)) 2) (expt (- (second p1) (second p2)) 2))))

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
      1 ;;return 1 if obstacle is closest, else 0.5 (may need tweaking)
      0.5)))

;;angle and preposition stuff converted from C++
(define (normalize-angle angle)
 (cond
  ((> angle pi) (normalize-angle (- angle two-pi)))
  ((<= angle (- pi)) (normalize-angle (+ angle two-pi)))
  (else angle)))

(define (angle-between p1 p2)
 (atan (- (second p1) (second p2))
       (- (first p1) (first p2))))

(define (left-of robot obstacle lexicon)
 (let ((distance-multiplier (distance-factor robot obstacle lexicon))
       ;;(distance (distance-between robot (location-of obstacle)))
       (angle (angle-between robot (location-of obstacle))))
  (* (- 1 (/ (abs (- (abs angle) PI)) PI)) distance-multiplier)))

(define (right-of robot obstacle lexicon)
 (let ((distance-multiplier (distance-factor robot obstacle lexicon))
       ;;(distance (distance-between robot (location-of obstacle)))
       (angle (angle-between robot (location-of obstacle))))
  (* (- 1 (/ (abs angle) PI)) distance-multiplier)))

(define (in-front-of robot obstacle lexicon)
 (let ((distance-multiplier (distance-factor robot obstacle lexicon))
       ;;(distance (distance-between robot (location-of obstacle)))
       (angle (angle-between robot (location-of obstacle))))
  (* (- 1 (/ (abs (normalize-angle (- angle (- half-pi)))) pi))
     distance-multiplier)))

(define (behind robot obstacle lexicon)
 (let ((distance-multiplier (distance-factor robot obstacle lexicon))
       ;;(distance (distance-between robot (location-of obstacle)))
       (angle (angle-between robot (location-of obstacle))))
  (* (- 1 (/ (abs (normalize-angle (- angle half-pi))) pi)) distance-multiplier)))

(define (between robot obstacle1 obstacle2)
 (let* ((angle1 (angle-between robot (location-of obstacle1)))
	(angle2 (angle-between robot (location-of obstacle2)))
	;; (distance1 (distance-between robot (location-of obstacle1)))
	;;(distance2 (distance-between robot (location-of obstacle2)))
	;;(average-distance (/ (+ distance1 distance2) 2))
	)
  ;; (/ (- 1 (/ (abs (- pi (abs (- angle1 angle2)))) pi)) average-distance)
  ;;using average distance didn't seem to work well
  (- 1 (/ (abs (- pi (abs (- angle1 angle2)))) pi))))

;;dummy functions for around towards away-from past
(define (around robot obstacle lexicon) 0)
(define (towards robot obstacle lexicon) 0)
(define (away-from robot obstacle lexicon) 0)
(define (past robot obstacle lexicon) 0)

(define all-sentences (all-values (a-sentence)))

(define (parse-sentence sentence) (a-parse sentence))

(define (sentence-from-string string)
 (map string->symbol (fields (string-upcase string))))

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

(define all-traces (get-traces datapath numtraces))

(define (produce-score-matrix lexicon traces)
 (map (lambda (sentence)
       (list sentence (map (lambda (trace)
			    (score-sentence sentence lexicon trace))
			   traces)))
      all-sentences))

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

