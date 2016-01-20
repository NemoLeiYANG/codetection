(MODULE PARSER)

(include "QobiScheme.sch")
(include "parser.sch")
(include "toollib-c-macros.sch")

(define *predicate-names* '(to-the-left-of          ;; 0 l
			    to-the-right-of         ;; 1 r
			    picked-up               ;; 2 pk
			    put-down                ;; 3 pd
			    carried                 ;; 4 c
			    approached              ;; 5 ap
			    towards                 ;; 6 tw
			    away-from               ;; 7 aw			    
			    ;; new added            
			    to-the-left-of-start    ;; 8 l1
			    to-the-left-of-end      ;; 9 l2
			    to-the-right-of-start   ;; 10 r1
			    to-the-right-of-end     ;; 11 r2
			    on-top-of-start         ;; 12 t1
			    on-top-of-end           ;; 13 t2
			    near-start              ;; 14 n1
			    near-end                ;; 15 n2
			    in-start                ;; 16 i1
			    in-end                  ;; 17 i2
			    below-start             ;; 18 b1
			    below-end               ;; 19 b2
			    above-start             ;; 20 a1
			    above-end               ;; 21 a2			    
			    moved                   ;; 22 mv
			    rotated                 ;; 23 rt
			    above-any               ;; 24 aa
			    carried-leftwards       ;; 25 cl
			    carried-rightwards      ;; 26 cr
			    vertical                ;; 27 vr
			    ))

(define *predicate-full-names*
 (map (lambda (x y)
       (list x y))
      '(l r pk pd c ap tw aw l1 l2 r1 r2 t1 t2 n1 n2 i1 i2
	  b1 b2 a1 a2 mv rt aa cl cr vr)
      *predicate-names*))

(define *objects-house*
 '(bowl
   cabbage
   squash
   pineapple
   cleaner
   coffee
   ketchup
   milk
   juice
   cup
   cooler
   box
   watering-pot
   gas-can
   bucket))

(define *objects-cad*
 '(bowl
   cup
   microwave
   jar
   cereal))

(define-structure production-rule lhs rhs)

(define-structure cfg rules)

(define p-lhs production-rule-lhs)

(define p-rhs production-rule-rhs)

(define (p-leaf? l) (every symbol? l))

(define (ip-leaf? l)
 (let ((pre (take-until vector? l)) (post (drop-until vector? l)))
  (and (every symbol? pre) (every vector? post))))

(define (index-leaves tree leaf? prefix)
 (if (leaf? tree)
     (append tree (list (list->vector prefix)))
     (cons (car tree)
	   (all-values
	    (let ((i (an-integer-between 1 (length (cdr tree)))))
	     (index-leaves (list-ref tree i) leaf? (cons i prefix)))))))

(define (tree->leaves tree leaf?)
 (let ((leaves '()))
  (if (leaf? tree)
      (set! leaves (cons tree leaves))
      (let loop ((tree tree))
       (all-values
	(let ((t (a-member-of tree)))
	 (cond ((not (list? t)) (fail))
	       ((leaf? t) (set! leaves (cons t leaves)))
	       (else (loop t)))))))
  (reverse leaves)))

;;; Zippers

(define-structure zipper tree thread)

(define (zipper:initialize tree) (make-zipper tree '()))

(define (zipper:descend zipper i)
 (unless (<= 0 i (- (length (zipper-tree zipper)) 1))
  (panic "zipper: cannot descend to out-of-bounds index"))
 (let ((elem (list-ref (zipper-tree zipper) i)))
  (make-zipper
   elem
   (cons (map-indexed (lambda (e j) (if (= i j) #f e)) (zipper-tree zipper)) (zipper-thread zipper)))))

(define (zipper:ascend zipper)
 (when (null? (zipper-thread zipper)) (panic "zipper: cannot ascend any further"))
 (make-zipper
  (map (lambda (e) (if e e (zipper-tree zipper))) (car (zipper-thread zipper)))
  (cdr (zipper-thread zipper))))

(define (zipper:descend-seq zipper seq)
 (let loop ((z zipper) (s seq))
  (if (null? s) z (loop (zipper:descend zipper (car s)) (cdr s)))))

(define (zipper:ascend-n zipper n)
 (unless (<= 0 n) (panic "zipper: cannot ascend negative levels"))
 (case n
  ((0) zipper)
  ((1) (zipper:ascend zipper))
  (else (zipper:ascend-n zipper (- n 1)))))

(define (zipper:can-ascend? zipper) (not (null? (zipper-thread zipper))))
(define (zipper:can-descend? zipper) (some list? (zipper-tree zipper)))

(define (zipper:ascend-until zipper predicate)
 (let loop ((z zipper))
  (if (predicate z) z (loop (zipper:ascend zipper)))))

(define (zipper:ascend-height zipper) (length (zipper-thread zipper)))

(define (create-cfg rules)
 (unless (and (not (some list? (map production-rule-lhs rules)))
	      (not (every list? (map production-rule-lhs rules))))
  (panic "Production rule: NT (terminals* U NT*)"))
 (make-cfg rules))

(define (unwords l) (string-join " " l))

(define (string-join delim l)
 (if (null? l) "" (foldl (lambda (a b) (string-append a delim b)) (cdr l) (car l))))

(define (lexicalize es cfg . symbol)
 (map (lambda (t) (string->symbol
		   (string-join (if (null? symbol) "-" (symbol->string (car symbol)))
				(map symbol->string (rest t)))))
      (tree->leaves (sentence:parse-sentence-any (unwords (map symbol->string es)) cfg) p-leaf?)))

(define (cfg:a-valid-rhs rhs)
 (remove #f (nondeterministic-map (lambda (r) (if (list? r) (either #f (car r)) r)) rhs)))

(define (cfg:possible-rules lhs rules)
 (remove-if-not (lambda (r) (equal? (p-lhs r) lhs)) rules))

(define (cfg:terminals cfg)
 (set-difference (flatten* (map p-rhs (cfg-rules cfg))) (map p-lhs (cfg-rules cfg))))

(define (cfg:non-terminals cfg)
 (remove-duplicates (map p-lhs (cfg-rules cfg))))

(define (cfg:non-terminal? symbol cfg)
 (member symbol (map p-lhs (cfg-rules cfg))))

(define (cfg:terminal-categories cfg)
 (remove-duplicates
  (removeq
   #f
   (map (lambda (r) (and (not (some (lambda (t) (cfg:non-terminal? t cfg)) (p-rhs r))) (p-lhs r)))
	(cfg-rules cfg)))))

(define (sentence:parse-sentence-any sentence cfg)
 (call-with-current-continuation
  (lambda (return)
   (for-each
    (lambda (nt) (let ((parse (sentence:parse-sentence sentence cfg nt))) (when parse (return parse))))
    (cfg:non-terminals cfg)))))

(define (sentence:parse-sentence sentence cfg . start)
 (define rules (cfg-rules cfg))
 (define terminals (cfg:terminals cfg))
 (define tokens (map string->symbol (fields (string-upcase sentence))))
 (define (num-terminals p) (length (intersection (flatten* p) terminals)))
 (define (longest-parse parses) (if (null? parses) '() (maximump parses num-terminals)))
 (find-if
  (lambda (p) (equal? (intersection (flatten* p) terminals) tokens))
  (map
   (lambda (start-rule)
    (let loop ((rule start-rule) (stack (take 1 tokens)) (tokens (cdr tokens)))
     (cond
      ((equal? (p-rhs rule) stack) (cons (p-lhs rule) stack))
      ((initial-sublist? (p-rhs rule) stack)
       (if (null? tokens)
	   '()
	   (loop rule (append stack (take 1 tokens)) (cdr tokens))))
      (else (longest-parse
	     (all-values
	      (cons (p-lhs rule)
		    (nondeterministic-map
		     (lambda (r)
		      (let* ((poss (cfg:possible-rules r rules))
			     (parse (if (null? poss) (fail) (loop (a-member-of poss) stack tokens))))
		       (if (null? parse)
			   (fail)
			   (begin
			    (local-set! tokens (drop (- (num-terminals parse) (length stack)) tokens))
			    (unless (null? tokens)
			     (local-set! stack (take 1 tokens))
			     (local-set! tokens (cdr tokens)))
			    parse))))
		     (cfg:a-valid-rhs (p-rhs rule))))))))))
   (remove-if-not (lambda (r) (eq? (p-lhs r) (if (null? start) 'S (car start)))) rules))))

(define (drop-until p ls)
 (let loop ((ls ls)) (if (or (null? ls) (p (car ls))) ls (loop (cdr ls)))))

(define (take-until p l)
 (let loop ((l l) (a '())) (if (or (null? l) (p (car l))) (reverse a) (loop (cdr l) (cons (car l) a)))))

(define (theta-role-assignments sentence cfg semantics)
 (define parse (sentence:parse-sentence-any sentence cfg))
 (define terminal-categories (cfg:terminal-categories cfg))
 (define (head-noun tree)
  (let ((n (find-if (lambda (e) (eq? (car e) 'N)) (tree->leaves tree ip-leaf?))))
   (unless n (panic "head-noun: noun not pund in parse:~%~a~%" tree))
   `#(,(car (lexicalize (take-until vector? (rest n)) cfg)) ,(vector->list (last n)))))
 (define (get-noun-terms ztree category)
  (map head-noun (remove-if-not (lambda (t) (eq? (car t) category)) (rest (zipper-tree ztree)))))
 (define (assign-roles ztree)
  (if (member (car (zipper-tree ztree)) terminal-categories)
      (let ((terminal (car (lexicalize (take-until vector? (cdr (zipper-tree ztree))) cfg))))
       (append
	(list (car (zipper-tree ztree)) terminal)
	(let loop ((ztree ztree) (terms '()) (l (length (semantics terminal))))
	 (if (<= l 0)
	     (take (length (semantics terminal)) terms)
	     (if (zipper:can-ascend? ztree)
		 (let* ((new-ztree (zipper:ascend ztree))
			(current-ns (get-noun-terms new-ztree 'N))
			(current-nps (get-noun-terms new-ztree 'NP)))
		  (loop new-ztree
			(append current-ns current-nps terms)
			(- l (length current-ns) (length current-nps))))
		 (loop ztree (cons `#(thing (,l)) terms) (- l 1)))))))
      (cons (car (zipper-tree ztree))
	    (all-values
	     (assign-roles
	      (zipper:descend ztree (an-integer-between 1 (- (length (zipper-tree ztree)) 1))))))))
 (unless parse (panic "Failed parse~%  sentence: ~a~%" sentence))
 (tree->leaves (assign-roles (zipper:initialize (index-leaves parse p-leaf? '()))) ip-leaf?))

(define (my-topological-sort nodes edges)
 (let* ((degrees (map (lambda (v) (length (remove-if-not
					   (lambda (e) (equal? v (second e)))
					   edges)))
		      nodes)))
  (let loop ((degrees degrees)
	     (nodes nodes)
	     (sorted-nodes '()))
   (if (null? nodes)
       (reverse sorted-nodes)
       (let* ((i (position 0 degrees))
	      (zero-node (list-ref nodes i)))
	(loop (list-remove
	       (map (lambda (d v)
		     ;; (if (member (list zero-node v) edges)
		     ;; 	 (- d 1)
		     ;; 	 d)
		     (- d (count (list zero-node v) edges))
		     )
		    degrees nodes)	       
	       i)
	      (remove zero-node nodes)
	      (cons zero-node sorted-nodes)))))))

(define (sentence->predicates sentence cfg semantics)
 (let* ((theta-roles (theta-role-assignments sentence cfg semantics))
	(objects (map third (remove-if-not
			     (lambda (role)
			      (and (equal? 'n (first role)) ;; noun
				   (not (equal? 'person (second role))))) ;; but not 'person'
			     theta-roles)))
	(predicates (map rest (remove-if
			       (lambda (role)
				(member (first role) '(n d adv a)))
			       theta-roles))))
  (map (lambda (p)
	(cons (first p)
	      (map (lambda (obj)
		    (if (position obj objects)
			(list (x obj) (position obj objects))
			#f))
		   (rest p))))
       predicates)))

;; predicates:
;;    (predicate_id object1_id object2_id ...)
;; objects:
;;    (object_id object_name video_id)
(define (sentences->universal-predicates-and-objects sentences)
 (let* ((predicates-menu
	 (map (lambda (s)
	       (sentence->predicates s *new4-corpus:cfg* *new4-corpus:semantics*))
	      sentences))
	(all-objects (join (map-indexed
			    (lambda (predicates n)
			     (remove-if-not
			      second
			      (remove-duplicates			      
			       (map (lambda (obj)
				     (list n obj))
				    (join (map rest predicates))))))
			    predicates-menu))))
  (list (join
	 (map-indexed
	  (lambda (predicates n)
	   (map (lambda (p) (append
			     (cons (position (first p) *predicate-names*)
				   (map (lambda (arg)
					 (if (position (list n arg) all-objects)
					     (position (list n arg) all-objects)
					     -1))
					(rest p)))))
		predicates))
	  predicates-menu))
	(map-indexed
	 (lambda (obj i)
	  (list i (first (second obj)) (first obj)))
	 all-objects))))

;;;;;; just for fast testing ;;;;;;
(define (theta-roles->predicates theta-roles)
 (let* (;; (objects (map third (remove-if-not
	;; 		     (lambda (role)
	;; 		      (and (equal? 'n (first role)) ;; noun
	;; 			   (not (equal? 'person (second role))))) ;; but not 'person'
	;; 		     theta-roles)))
	(objects
	 (remove-if
	  (lambda (o)
	   (equal? 'person (x o))) ;; not 'person
	  (remove-duplicates
	   (join
	    (map (lambda (p) (drop 2 p))			 
		 (remove-if
		  (lambda (role)
		   (member (first role) '(n d adv a)))
		  theta-roles))))))
	(predicates (map rest (remove-if
			       (lambda (role)
				(member (first role) '(n d adv a)))
			       theta-roles))))
  (map (lambda (p)
	(cons (first p)
	      (map (lambda (obj)
		    (if (position obj objects)
			(list (x obj) (position obj objects))
			#f))
		   (rest p))))
       predicates)))

(define (theta-roles->universal-predicates-and-objects theta-roles-menu objects)
 (let* ((predicates-menu
	 (map (lambda (theta-roles)
	       (theta-roles->predicates theta-roles))
	      theta-roles-menu))
	;; predicates-menu:
	;; (((PUT-DOWN #F (TISSUE-BOX 0)) (NEAR-END (TISSUE-BOX 0) (CUP 1))))
	;; needs a topological sort so that the id of the first argument
	;; is always smaller than that of the second argument
	(edges (join (map-indexed
		      (lambda (predicates n)
		       (map (lambda (p)
			     (list (list n (second p))
				   (list n (third p))))
			    (remove-if (lambda (p) (member #f p)) predicates)))
		      predicates-menu)))	
	(all-objects (join (map-indexed
			    (lambda (predicates n)
			     (remove-if-not
			      second
			      (remove-duplicates			      
			       (map (lambda (obj)
				     (list n obj))
				    (join (map rest predicates))))))
			    predicates-menu)))       
	(all-objects (my-topological-sort all-objects edges))
	(_ (for-each (lambda (obj)
		      (unless (member (first (second obj)) objects)
		       (format #t "~a~%" (first (second obj)))
		       (panic "wrong object")))
		     all-objects)))
  (list (join
	 (map-indexed
	  (lambda (predicates n)
	   (map (lambda (p) (append
			     (cons (let ((p-id (position (first p) *predicate-names*)))
				    (if (not p-id)
					(begin
					 (format #t "~a~%" (first p))
					 (panic "wrong predicate"))
					p-id))
				   (map (lambda (arg)
					 (if (position (list n arg) all-objects)
					     (position (list n arg) all-objects)
					     -1))
					(rest p)))))
		predicates))
	  predicates-menu))
	(map-indexed
	 (lambda (obj i)
	  (list i (first (second obj)) (first obj)))
	 all-objects))))

(define *new4-corpus:cfg*
 (create-cfg
  (list (make-production-rule 'S '(NP VP))
	(make-production-rule 'NP '(D (A) N (PP)))
	(make-production-rule 'D '(the))
	(make-production-rule 'A '(blue))
	(make-production-rule 'A '(red))
	(make-production-rule 'N '(person))
	(make-production-rule 'N '(backpack))
	(make-production-rule 'N '(trash-can))
	(make-production-rule 'N '(chair))
	(make-production-rule 'N '(traffic-cone))
	(make-production-rule 'N '(stool))
	(make-production-rule 'N '(object))
	(make-production-rule 'PP '(PL NP))
	(make-production-rule 'PL '(to the left of))
	(make-production-rule 'PL '(to the right of))
	(make-production-rule 'P '(with))
	(make-production-rule 'P '(to))
	(make-production-rule 'VP '(TV NP (ADV) (PPM)))
	(make-production-rule 'VP '((ADV) DTV NP P NP))
	(make-production-rule 'TV '(picked up))
	(make-production-rule 'TV '(put down))
	(make-production-rule 'TV '(carried))
	(make-production-rule 'TV '(approached))
	;; (make-production-rule 'TV '(collided with))
	;; (make-production-rule 'TV '(left))
	;; (make-production-rule 'DTV '(gave))
	;; (make-production-rule 'DTV '(replaced))
	(make-production-rule 'ADV '(quickly))
	(make-production-rule 'ADV '(slowly))
	(make-production-rule 'PPM '(PM NP))
	(make-production-rule 'PM '(towards))
	(make-production-rule 'PM '(away from)))))

(define (*new4-corpus:semantics* lexical-entry)
 (let ((all-roles '(agent patient referent goal source)))
  (case lexical-entry
   ((to-the-left-of) `((agent patient goal) (referent)))
   ((to-the-right-of) `((agent patient goal) (referent)))
   ((picked-up) `((agent) (patient)))
   ((put-down) `((agent) (patient)))
   ((carried) `((agent) (patient)))
   ((approached) `((agent) (goal)))
   ((towards) `((agent patient) (goal)))
   ((away-from) `((agent patient) (source)))
   ;; ((gave) `((agent) (patient) (goal)))
   ;; ((replaced) `((agent) (patient) (goal)))
   ;;   ((followed) `((agent) (patient)))
   ;; ((left) `((agent) (goal)))
   ;; ((collided-with) `((agent) (patient)))
   ;; ((with) `((patient) (goal)))
   (else `(,all-roles)))))


;;;;;;;;;;;;;;; from sentence to predicates automatically ;;;;;;;;;;;;;;;;;;

(define *dataset-id* "")
(define *files-dir* "/home/yu239/darpa-collaboration/sentence-codetection/videos-files")

(define (sentence->participants sentence objs)
 (define objects (cons 'person objs))
 (define counts (make-vector (length objects) 0))
 (define total 0)
 (define bindings '())
 (let ((ret
	(map (lambda (x)
	      (let ((sx (c-string->symbol x)))
	       (if (member sx objects)
		   (let* ((pos (position sx objects))
			  (p (vector sx (vector-ref counts pos)))
			  (np (c-string->symbol (format #f "x~a" total))))
		    (set! bindings (cons (list p np) bindings))
		    (set! total (+ total 1))
		    (vector-set! counts pos (+ (y p) 1))
		    np)
		   sx)))
	     (pregexp-split " " sentence))))
  (list ret bindings)))

(define (apply-bindings bindings predicates)
 (map (lambda (sp)
       (map (lambda (p) (if (assoc p bindings)
			    (second (assoc p bindings))
			    p)) sp))
      predicates))

(define (get-amt-corpus k)
 (let ((dry-sentences (read-file "sentences.txt.dry"))
       (videos (read-file "amt-videos.txt"))
       (ispelled-sentences (read-file "sentences-ispelled.txt")))
  (map (lambda (g)
	(take-if-possible k g))
       (group-by (lambda (vs) (first vs))
		 (transpose-list-of-lists
		  (list videos dry-sentences ispelled-sentences))))))

;; to be filled with conversion rules by hand
(define (amt-sentence-templates k objects)
 (let* ((video-sentences (join (get-amt-corpus k)))	
	(video-sentence-templates
	 (map (lambda (pair)
	       (append (but-last pair)
		       (list (first (sentence->participants (second pair) objects)))))
	      video-sentences))
	(grouped-templates
	 (map (lambda (g)
	       (list (map but-last g)
		     (last (first g))
		     '-~->
		     '()))
	      (group-by (lambda (e) (third e)) video-sentence-templates))))
  grouped-templates))

;;;; only for the house dataset
(define (get-old-rules)
 (let* ((annotation
	 (map
	  rest
	  (read-object-from-file (format #f "~a/house/videos-house.sc" *files-dir*))))
	(templates	 
	 (map (lambda (a)
	       (let* ((res (sentence->participants (second a) *objects-house*))
		      (s (first res))
		      (bindings (second res)))
		(list s
		      '-~->
		      (apply-bindings bindings (first a)))))
	      annotation))
	(grouped-templates
	 (group-by first templates)))
  (map first grouped-templates)))

(define (get-amt-rules abbr-table-file)
 (let* ((abbr-table (map rest (read-object-from-file
			       abbr-table-file))))
  (map
   (lambda (rule)
    (let ((rhs (third rule)))
     `(,@(but-last rule)       
       ,(map (lambda (p)
	      `(p
		,(second (assoc (first p) *predicate-full-names*))
		,(second p)
		,(third p)))
	     (split-n 3 rhs)))))
   abbr-table)))

(define (apply-rules-to-sentence sentence rules objects)
 (let* ((res (sentence->participants sentence objects))
	(s (first res))
	(bindings (map reverse (second res)))
	(predicates (third (assoc s rules))))
  (apply-bindings bindings predicates)))

(define (generate-amt-corpus k objects)
 (let ((rules (get-amt-rules "predicate-table-k3-abbr.sc"))
       (corpus (unzip (get-amt-corpus k))))
  (for-each-indexed
   (lambda (c i)
    (write-object-to-file
     (map (lambda (vs)
	   (list (format #f "/net/zhineng/aux/yu239/~a/~a.avi" *dataset-id* (first vs))
		 (apply-rules-to-sentence (second vs) rules objects)
		 (third vs)))
	  c)
     (format #f "videos-~a-amt-~a.sc" *dataset-id* (+ i 1))))
   corpus)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;; only for the house dataset ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (find-missing-objects k)
 (let* ((old-objects (map (lambda (v) (remove-duplicates (remove-if-not vector? (join (second v)))))
			  (read-object-from-file "videos-house.sc")))
	(new-objects-multiple
	 (map-n
	  (lambda (i)
	   (map
	    (lambda (v)
	     (list (remove-duplicates (remove-if-not vector? (join (second v))))
		   (third v)))
	    (read-object-from-file (format #f "videos-house-amt-~a.sc" (+ i 1)))))
	  k))
	(new-objects
	 (map (o remove-duplicates join (lambda (l) (map first l)))
	      (transpose-list-of-lists new-objects-multiple)))
	(missing-objects
	 (map (lambda (a b) (remove '#(person 0) (set-difference a b))) new-objects old-objects))
	(missing-objects-with-sentences
	 (map-indexed
	  (lambda (lst n)
	   (if (null? lst)
	       '()
	       (let ((set-i (find-if
			     (lambda (x)
			      (null? (set-difference lst (first (list-ref x n)))))
			     new-objects-multiple)))
		(list lst (second (list-ref set-i n))))))
	  missing-objects)))
  (write-object-to-file
   (remove-if
    (o null? second)
    (zip (read-file "videos.txt")
	 missing-objects-with-sentences))
   "missing-objects.sc")))

(define (generate-anno-gui-sentences)
 (write-file
  (join
   (join
    (map
     (lambda (v)
      (let ((video-name (strip-directory (first v)))
	    (instances (first (second v)))
	    (words (pregexp-split " " (second (second v)))))
       (map
	(lambda (instance)
	 (let* ((name (string-downcase (symbol->string (x instance))))
		(mark (format #f "~a~a" name (y instance)))
		(idx
		 (second
		  (list-ref 
		   (remove-if-not
		    (lambda (w) (string=? (first w) name))
		    (zip words (map-n identity (length words))))
		   (y instance))))
		(marked-sentence
		 (string-join " " (list-replace words
						idx
						(format #f "<mark><strong>~a</strong></mark>" name)))))
	  (list (format #f "~a ~a" video-name mark)
		marked-sentence)))
	instances)))
     (read-object-from-file "missing-objects.sc"))))
  "/tmp/videos-sentences.txt"))
       

 