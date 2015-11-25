(load "/home/dpbarret/darpa-collaboration/rover/toollib-feature-based-trace-generator.sc")
;;(load "/home/dpbarret/darpa-collaboration/rover/new-parser.sc")


;;; (DATASET-MANUAL-LOGS->TRACKS (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-dataset.sc") "/aux/dpbarret/rover-logs/MSEE1-dataset")

;;; (define downsampled-dataset (join (downsample-dataset-tracks (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-dataset.sc") "/net/mohio/aux/dpbarret/rover-logs/MSEE1-dataset/training-runs")))

;;(learn-from-dataset downsampled-dataset 'r)


(define *objects* (list 'the-box 'the-chair 'the-stool 'the-bag 'the-cone 'the-table))

(define *duplicable-objects* (list 'the-box 'the-chair 'the-bag 'the-table))

(define *minimum-distance-between-objects* 1.6)

(define (random-element l)
 (list-ref l (random-integer (length l))))

(define *all-grid-positions*
 (list
  (vector -1 0) (vector 1 0)
  (vector -2 1) (vector -1 1) (vector 0 1) (vector 1 1) (vector 2 1)
  (vector -2 2) (vector -1 2) (vector 0 2) (vector 1 2) (vector 2 2)
  (vector -2 3) (vector -1 3) (vector 0 3) (vector 1 3) (vector 2 3)
  (vector -2 4) (vector -1 4) (vector 0 4) (vector 1 4) (vector 2 4)
  (vector -1 5) (vector 0 5) (vector 1 5)))

(define *grid-positions*
 (list
  (vector -1 1) (vector 0 1) (vector 1 1) 
  (vector -1 2)  (vector 1 2) 
  (vector -1 3) (vector 0 3) (vector 1 3) 
  (vector -1 4) (vector 0 4) (vector 1 4)))

(define *grid-positions*
 (list
  (vector -1 1) (vector 0 1) (vector 1 1) 
  (vector -1 2)  (vector 1 2) 
  (vector -1 3) (vector 0 3) (vector 1 3) 
  (vector -1 4) (vector 0 4) (vector 1 4)))

(define *grid-positions*
 (join (map
	(lambda (x)
	 (map
	  (lambda (y)
	   (vector x y))
	  (list .5 1 1.5 2 2.5 3 3.5 4)))
	(list -1.5 -1 -.5 0 .5 1.5))))

(define (grid-position->world-position g)
 (vector ;; (case (x g)
	 ;;  ((-2)
	 ;;   -3)
	 ;;  ((-1)
	 ;;   -1.37)
	 ;;  ((-0)
	 ;;   0)
	 ;;  ((1)
	 ;;   1.37)
	 ;;  ((2)
	 ;;   3.05))
	 (if (<= (abs (x g)) 1)
	     (* (x g) 1.37)
	     (* (if (< (x g) 0) -1 1)
		(+ (* (- (abs (x g)) 1) 1.68) 1.37)))
	 (* (- (y g) 2) 1.304)))

(define (random-quantized-object-instantiation object-types grid-positions)
 (let loop ((object-types object-types)
	    (grid-positions grid-positions)
	    (objects '()))
  (if (null? object-types)
      objects
      (let* ((grid-index (random-integer (length grid-positions)))
	     (position (dtrace "random position:"(grid-position->world-position
			(list-ref grid-positions grid-index)))))
       (if (> (dtrace "min distance:"
		      (minimum (map (lambda (obj)
				     (distance (second obj) position))
				    (cons (list 'the-origin (vector 0 0)) objects))))
	      *minimum-distance-between-objects*)
	   (loop (rest object-types)
		 (list-remove grid-positions grid-index)
		 (cons (list (first object-types) position) objects))
	   (loop object-types
		 (list-remove grid-positions grid-index)
		 objects))))))

;;(define floorplans (map-n (lambda (i) (random-quantized-object-instantiation (cons (random-element *duplicable-objects*) *objects*) *grid-positions*)) 10))


(define (generate-random-track-sentence-triple-from-floorplan
	 object-instantiations
	 number-of-predicates
	 one-object-prepositions
	 plot?)
 (let* ((object-strings
	 (map string-downcase
	      (map symbol->string
		   (map remove-the (map first object-instantiations)))))
	(object-structs (object-instantiations->object-structs object-instantiations))
	(resolved-objects (dtrace "resolved:" (map render-object (resolve-ambiguity object-structs))))
	(sentence
	 (dtrace "sentence:" (generate-random-simple-sentence resolved-objects number-of-predicates one-object-prepositions)))
	(raw-trace-and-score (trace-from-parse-functions-step-by-step
			      (parse-tree->parse-functions
			       (parse-sentence sentence) object-instantiations)
			      (if plot? (objects->plot-function object-instantiations) #f)))
	(raw-trace (first raw-trace-and-score))
	(score (second raw-trace-and-score))
	(trace (smooth-trace
		(interpolate-trace
		 raw-trace
		 32)
		(list .15 .7 .15))))
  (when plot? (plot-trace trace object-instantiations))
(if (< score (expt .98 number-of-predicates))
    #f
    (list object-instantiations
	  sentence
	  trace))))

(define (n-indexed-weighted-random-elements-without-replacement n weighted-list)
 (if (< (length weighted-list) n)
     (panic "not enough elements")
     (let loop ((weighted-list weighted-list)
		(result '()))
      (if (= (length result) n)
	  result
	  (let* ((total-weight (reduce + (map second weighted-list) 0))
		 (lottery-number (random-in-range 0 total-weight))
		 (indexed-winner (let loop2 ((i 0)
					     (weighted-list weighted-list)
					     (lottery-number lottery-number))
				  (if (< lottery-number (second (first weighted-list)))
				      (list (first weighted-list) i)
				      (loop2 (+ i 1)
					     (rest weighted-list)
					     (- lottery-number (second (first weighted-list))))))))
	   (loop (list-remove weighted-list (second indexed-winner))
		 (cons indexed-winner result)))))))

(define (generate-random-dataset-from-floorplan
	 floorplan
	 number-of-datapoints
	 weighted-numbers-of-predicates
	 one-object-prepositions
	 plot?)
 (map-n
  (lambda (d)
   (let (
	 (number-of-predicates (first (first (first (n-indexed-weighted-random-elements-without-replacement 1 weighted-numbers-of-predicates))))))
    (generate-random-track-sentence-triple-from-floorplan
     floorplan
     number-of-predicates
     one-object-prepositions
     plot?)))
  number-of-datapoints))


(define (generate-random-dataset-from-floorplans floorplans
						 number-of-datapoints-per-floorplan
						 weighted-numbers-of-predicates
						 one-object-prepositions
						 plot?)
  (map
   (lambda (floorplan)
    
     (filter-out-complicated-triples
     (removeq #f
      (generate-random-dataset-from-floorplan
       floorplan
       (* number-of-datapoints-per-floorplan 3)
       weighted-numbers-of-predicates
       one-object-prepositions
       plot?))     
     7))
     
   floorplans))


(define (run-manual-log->track directory)
 (system (dtrace ""
	  (format #f "/home/sbroniko/vader-rover/position/log-to-track.out /home/sbroniko/vader-rover/position/config.txt ~a/imu-log.txt ~a/track.txt ~a/track.sc"
		      directory
		      directory
		      directory
		      ))))

(define (runs-in-directory-manual-log->track directory)
 (let ((sub-directories (system-output (format #f "ls ~a" directory))))
  (for-each (lambda (dir)
	     (run-manual-log->track (format #f "~a/~a/" directory dir))
	     )
	    sub-directories)))
 
(define (dataset-manual-logs->tracks dataset directory)
 (for-each-indexed
  (lambda (plan-data p)
   (let* ((run-dirs (system-output (format #f "ls ~a/plan~a" directory p))))
    (for-each
     (lambda (run-dir)
      (dtrace "run-dir:" run-dir)
      (system (format #f "/home/sbroniko/vader-rover/position/log-to-track.out /home/sbroniko/vader-rover/position/config.txt ~a/plan~a/~a/imu-log.txt ~a/plan~a/~a/track.txt ~a/plan~a/~a/track.sc"
		      directory
		      p
		      run-dir
		      directory
		      p
		      run-dir
		      directory
		      p
		      run-dir)))
     run-dirs)))
  dataset))

(define (dataset-visualize-tracks p plan-data directory)
 ;;(for-each-indexed
  ;;(lambda (plan-data p)
   (let* ((run-dirs (system-output (format #f "ls ~a/plan~a/ | grep 20" directory p))))
    (for-each
     (lambda (run-dir run-data)
      (dtrace "run-dir:" run-dir)
      (when (file-exists? (dtrace ""(format #f "~a/plan~a/~a/track.sc" directory p run-dir)))
       (let* ((track (list->vector (map list->vector (read-object-from-file (format #f "~a/plan~a/~a/track.sc" directory p run-dir))))))
	(plot-trace track (first run-data))
	(matlab (format #f "title('~a')" (second run-data)))
	(matlab "figure"))))
     run-dirs plan-data))
   ;)
  ;dataset))

   )

(define (dataset-read-manual-tracks p plan-data directory)
 ;;(for-each-indexed
  ;;(lambda (plan-data p)
   (let* ((run-dirs (system-output (format #f "ls ~a/plan~a/ | grep 20" directory p))))
    (map
     (lambda (run-dir run-data)
      (dtrace "run-dir:" run-dir)
      (when (file-exists? (dtrace ""(format #f "~a/plan~a/~a/track.sc" directory p run-dir)))
       (let* ((track (list->vector (map list->vector (read-object-from-file (format #f "~a/plan~a/~a/track.sc" directory p run-dir))))))
	track)))
     run-dirs plan-data))
   ;)
  ;dataset))

   )

(define (dataset-read-house-tracks)
 (let* ((directory"/aux/sbroniko/vader-rover/logs/house-test-12nov15")
	 ;;"/home/sbroniko/vader-rover/logs/house-test-12nov15")
	(run-dirs (system-output (format #f "ls -d ~a/*/" directory ))))
  (map
   (lambda (run-dir)
    (dtrace "run-dir:" run-dir)
      (when (file-exists? (dtrace ""(format #f "~a/track.sc" run-dir)))
       (let* ((track (list->vector (map list->vector (read-object-from-file (format #f "~a/track.sc" run-dir))))))
	track)))
     run-dirs)))




(define (visualize-floorplan-dataset-with-sentences floorplan-data floorplan-sentences)
 (for-each
  (lambda (run-data run-sentences)
   (plot-trace (third run-data) (first run-data))
   (matlab (format #f "title('~a')" (first run-sentences)))
   (matlab "figure"))
floorplan-data floorplan-sentences))

(define (downsample-list-by-factor l f)
 (removeq #f
	  (map-indexed
	   (lambda (e i)
	    (if (= (modulo i f) 0)
		e
		#f))
	   l)))


(define (downsample-dataset-tracks dataset directory)
 (map-indexed
  (lambda (plan-data p)
   (let* ((run-dirs (system-output (format #f "ls ~a/plan~a/ | grep 20" directory p))))
    (map
     (lambda (run-dir run-data)
      (dtrace "run-dir:" run-dir)
      (let* ((track (map list->vector (read-object-from-file (format #f "~a/plan~a/~a/track.sc" directory p run-dir)))))
       (list (first run-data)
	     (second run-data)
	     (list->vector (downsample-list-by-factor (map (lambda (p) (v+ (k*v .0001 (vector (random-real) (random-real)))(subvector p 0 2))) track) 10)))))
     run-dirs plan-data))
  )
  dataset))

(define (downsample-dataset-tracks2 dataset directory)
 (map-indexed
  (lambda (plan-data p)
   (let* ((run-dirs (system-output (format #f "ls ~a/plan~a/ | grep 20" directory p))))
    (map
     (lambda (run-dir run-data)
      (dtrace "run-dir:" run-dir)
      (let* ((track (map list->vector (read-object-from-file (format #f "~a/plan~a/~a/track.sc" directory p run-dir)))))
       (list (first run-data)
	     (second run-data)
	     (list->vector (downsample-track-with-fixed-spacing (map (lambda (p) (subvector p 0 2)) track) 0.10)))))
     run-dirs plan-data))
  )
  dataset))

(define (downsample-dataset-tracks3 dataset)
 (map (lambda (plan-data)
       (list (first plan-data)
	     (second plan-data)
	     (list->vector
	      (downsample-track-with-fixed-spacing
	       (vector->list (third plan-data))
	       0.10))))
      dataset))


(define (downsample-dataset-tracks4 dataset directory)
 (map-indexed
  (lambda (plan-data p)
   (let* ((run-dirs (system-output (format #f "ls ~a/plan~a/ | grep floorplan" directory p))))
    (map
     (lambda (run-dir run-data)
      (dtrace "run-dir:" run-dir)
      (let* ((track (map list->vector (read-object-from-file (format #f "~a/plan~a/~a/track.sc" directory p run-dir)))))
       (list (first run-data)
	     (second run-data)
	     (list->vector (downsample-track-with-fixed-spacing (map (lambda (p) (subvector p 0 2)) track) 0.10)))))
     run-dirs plan-data))
  )
  dataset))

(define (downsample-track-with-fixed-spacing track spacing)
 (let loop ((track track)
	    (current-point #f))
  (if (null? track)
      '()
      (if current-point
	  (let ((new-track (let subloop ((track track))
			    (if (or (null? track) (>= (distance current-point (first track))
						      spacing))
				track
				(subloop (rest track))))))
	   (cons current-point
		 (if (null? new-track)
		     '()
		     (loop
		      new-track
		      (first new-track)))))
	  (loop track (first track))))))
	  


(define (matrix-append a b) (map-vector vector-append a b))

(define (ppm-append a b)
 (make-ppm
  (ppm-raw? a)
  (ppm-maxval a)
  (matrix-append (ppm-red a) (ppm-red b))
  (matrix-append (ppm-green a) (ppm-green b))
  (matrix-append (ppm-blue a) (ppm-blue b))))

(define (do-it3 a b c d)
 (write-pnm (ppm-append (ppm-append (read-pnm a) (read-pnm b)) (read-pnm c)) d))

(define (do-it a b d)
 (write-pnm (ppm-append (read-pnm a) (read-pnm b)) d))

(define (concatenate-2-videos v1 v2 outdir)
 (system (format #f "ffmpeg -i ~a ~a/v1-%04d.ppm" v1 outdir))
 (system (format #f "ffmpeg -i ~a ~a/v2-%04d.ppm" v2 outdir))
 (for-each
  (lambda (im1 im2 i)
   (do-it im1 im2 (format #f "~a/merged-~a.ppm" outdir (number->padded-string-of-length i 4))))
  (system-output (format #f "ls ~a/v1-*.ppm" outdir))
  (system-output (format #f "ls ~a/v2-*.ppm" outdir))
  (enumerate (length (system-output (format #f "ls ~a/v2-*.ppm" outdir)))))
 (system (format #f "ffmpeg -i ~a/merged-%04d.ppm -b 300000 ~a/merged.avi" outdir outdir)))

(define (concatenate-3-videos v1 v2 v3 outdir)
 (system (format #f "ffmpeg -i ~a ~a/v1-%04d.ppm" v1 outdir))
 (system (format #f "ffmpeg -i ~a ~a/v2-%04d.ppm" v2 outdir))
 (system (format #f "ffmpeg -i ~a ~a/v3-%04d.ppm" v3 outdir))
 (for-each
  (lambda (im1 im2 im3 i)
   (do-it3 im1 im2 im3 (format #f "~a/merged-~a.ppm" outdir (number->padded-string-of-length i 4))))
  (system-output (format #f "ls ~a/v1-*.ppm" outdir))
  (system-output (format #f "ls ~a/v2-*.ppm" outdir))
  (system-output (format #f "ls ~a/v3-*.ppm" outdir))
  (enumerate (length (system-output (format #f "ls ~a/v2-*.ppm" outdir)))))
 (system (format #f "ffmpeg -i ~a/merged-%04d.ppm -b 30000000 ~a/merged.avi" outdir outdir)))

;;

(define (concatenate-videos-in-runs dir)
 (for-each
  (lambda (d)
   (dtrace "dir:" d)
   (mkdir-p (format #f "~a/~a/concat" dir d))
   (concatenate-2-videos (format #f "~a/~a/video_front.avi" dir d)
			 (format #f "~a/~a/video_pano.avi" dir d)
			 (format #f "~a/~a/concat" dir d)))
  (system-output (format #f "ls ~a" dir))))

(define (concatenate-minimal-pairs)
 (concatenate-videos-in-runs "/aux/dpbarret/rover-logs/MSEE1-dataset/minimal-pairs"))

(define (concatenate-auto-drive)
 (for-each-n
  (lambda (i)
   (concatenate-videos-in-runs (format #f "/aux/dpbarret/rover-logs/MSEE1-dataset/auto-drive/plan~a/" i)))
  10))

(define (concatenate-generation)
 (for-each-n
  (lambda (i)
   (concatenate-videos-in-runs (format #f "/aux/dpbarret/rover-logs/MSEE1-dataset/generation/plan~a/" i)))
  10))

(define (read-robot-estimated-track-from-log-file filename)
 (let* ((lines (read-file filename))
	(valid (remove-if-not (lambda (line)
				      (let*
					((split-line (pregexp-split ":" line)))
				       (and (> (length split-line) 6)
					    (equal? (first split-line) "ESTIMATE"))))
				     lines))
	(pose (map (lambda (line)
		    (let*
		      ((split-line (pregexp-split ":" line)))
		     (vector (string->number (third split-line))
			     (string->number (fifth split-line)))))
		   valid)))
pose))

(define (read-auto-tracks)
 (map-n
  (lambda (p)
   (map-indexed
    (lambda (run-dir i)
     (dtrace "floorplan i run j:" (list p i))
     (list->vector (read-robot-estimated-track-from-log-file
      (format #f "/aux/dpbarret/rover-logs/MSEE1-dataset/auto-drive/plan~a/~a/imu-log.txt"
	      p run-dir))))
    (system-output
     (format #f "ls /aux/dpbarret/rover-logs/MSEE1-dataset/auto-drive/plan~a" p))))
  10))

(define (read-robot-estimated-track-from-log-file-lists filename)
 (let* ((lines (read-file filename))
	(valid (remove-if-not (lambda (line)
				      (let*
					((split-line (pregexp-split ":" line)))
				       (and (> (length split-line) 6)
					    (equal? (first split-line) "ESTIMATE"))))
				     lines))
	(pose (map (lambda (line)
		    (let*
		      ((split-line (pregexp-split ":" line)))
		     (list (string->number (third split-line))
			   (string->number (fifth split-line))
			   (string->number (seventh split-line)))))
		   valid)))
pose))


(define (read-auto-tracks2)
 (map-n
  (lambda (p)
   (map-indexed
    (lambda (run-dir i)
     (let* ((logfile
	     (format #f
		     "/aux/sbroniko/vader-rover/logs/MSEE2-dataset/plan~a/~a/imu-log.txt"
		     p run-dir))
	    (trackfile
	     ;;(dtrace "trackfile"
		     (format #f
			     "/aux/sbroniko/vader-rover/logs/MSEE2-dataset/plan~a/~a/track.sc"
			     p run-dir)));;)
      (dtrace "floorplan i run j:" (list p i))
      (if (file-exists? logfile)
	  (write-object-to-file
	   (read-robot-estimated-track-from-log-file-lists logfile)
	   trackfile)
	  (dtrace "no valid trace found"
		  (write-object-to-file
		   (map-n (lambda (i) (list 0.000000 0.000000 1.570796)) 100)
		   trackfile))
	  )
	  ))
    (system-output
     (format #f "ls /aux/sbroniko/vader-rover/logs/MSEE2-dataset/plan~a" p))))
  10))

(define (read-house-tracks)
 (map
  (lambda (run-dir)
   (let* ((logfile
	   (format #f
		   "/aux/sbroniko/vader-rover/logs/house-test-12nov15/~a/imu-log.txt"
		     run-dir))
	    (trackfile
	     ;;(dtrace "trackfile"
		     (format #f
			     "/aux/sbroniko/vader-rover/logs/house-test-12nov15/~a/track.sc"
			     run-dir)))
      (dtrace "floorplan:" (list run-dir))
      (if (file-exists? logfile)
	  (write-object-to-file
	   (read-robot-estimated-track-from-log-file-lists logfile)
	   trackfile)
	  (dtrace "no valid trace found"
		  (write-object-to-file
		   (map-n (lambda (i) (list 0.000000 0.000000 1.570796)) 100)
		   trackfile))
	  )
	  ))
    (system-output
     (format #f "ls /aux/sbroniko/vader-rover/logs/house-test-12nov15"))))


(define (read-planned-tracks)
 (map-n
  (lambda (p)
   (map-indexed
    (lambda (run-dir i)
     (dtrace "floorplan i run j:" (list p i))
     (list->vector (read-object-from-file
      (format #f "/aux/dpbarret/rover-logs/MSEE1-dataset/auto-drive/planned-traces/plan~a/~a"
	      p run-dir))))
    (system-output
     (format #f "ls /aux/dpbarret/rover-logs/MSEE1-dataset/auto-drive/planned-traces/plan~a" p))))
  10))

(define (read-minimal-pairs-tracks)
 (map-indexed
  (lambda (run-dir i)
   (dtrace "floorplan i run j:" (list p i))
   (list->vector (read-robot-estimated-track-from-log-file
		  (format #f "/aux/dpbarret/rover-logs/MSEE1-dataset/minimal-pairs/~a/imu-log.txt"
			  run-dir))))
  (system-output
   (format #f "ls /aux/dpbarret/rover-logs/MSEE1-dataset/minimal-pairs/"))))

(define (create-sentence->trace-localized-worksheets outpath)
 (let* ((dataset-tracks (read-auto-tracks))
	(dataset (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-auto-drive-datasetb.sc"))
	(images (join (map
		 (lambda (ft fd)
		 (map
		  (lambda (d t)
		   (CREATE-SENTENCE->TRACE-WORKSHEET (second d) t (first d) "slt"))
		  fd ft))
		 dataset-tracks dataset )))
	(images (append images (map-n (lambda (i) (let ((image (imlib:create 1236 800)))
						     (imlib:fill-rectangle image 0 0 1236 800 `#(255 255 255))))
				      (- 3 (modulo (length images) 3)))))
	(image-pairs
	 (shape-matrix (list->vector  images) 3))
	(pages (map-indexed-vector
		(lambda (pair i)
		 (let ((image (imlib:create 1236 1600)))
		  (imlib:blend image (x pair) #f 0 0 1236 800 0 0 1236 800)
		  (imlib:blend image (y pair) #f 0 0 1236 800 0 540 1236 800)
		  (imlib:blend image (z pair) #f 0 0 1236 800 0 1080 1236 800)
		  (imlib:save image (format #f "~a/page-~a.png" outpath
					    (number->padded-string-of-length i 4)))
		  (imlib:free (x pair))
		  (imlib:free (y pair))
		  (imlib:free image)))
		image-pairs)))
	#t))

(define (create-sentence->trace-planned-worksheets outpath)
 (let* ((dataset-tracks (read-planned-tracks))
	(dataset (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-auto-drive-datasetb.sc"))
	(images (join (map
		 (lambda (ft fd)
		 (map
		  (lambda (d t)
		   (CREATE-SENTENCE->TRACE-WORKSHEET (second d) t (first d) "spt"))
		  fd ft))
		 dataset-tracks dataset )))
	(images (append images (map-n (lambda (i) (let ((image (imlib:create 1236 800)))
						     (imlib:fill-rectangle image 0 0 1236 800 `#(255 255 255))))
				      (- 3 (modulo (length images) 3)))))
	(image-pairs
	 (shape-matrix (list->vector  images) 3))
	(pages (map-indexed-vector
		(lambda (pair i)
		 (let ((image (imlib:create 1236 1600)))
		  (imlib:blend image (x pair) #f 0 0 1236 800 0 0 1236 800)
		  (imlib:blend image (y pair) #f 0 0 1236 800 0 540 1236 800)
		  (imlib:blend image (z pair) #f 0 0 1236 800 0 1080 1236 800)
		  (imlib:save image (format #f "~a/page-~a.png" outpath
					    (number->padded-string-of-length i 4)))
		  (imlib:free (x pair))
		  (imlib:free (y pair))
		  (imlib:free image)))
		image-pairs)))
	#t))
  

(define (world->pixel world-xy width height minx maxx miny maxy)
  (vector (+ (* width (/ (x world-xy) (- maxx minx)))
			    (/ width 2))
			 (+ (- (* height (/ (y world-xy) (- maxy miny))))
			    (/ height 2))))
(define (draw-world-line line image width height minx maxx miny maxy color)
(imlib:draw-line image color 
		 (x (world->pixel (first line) 600 600 minx maxx miny maxy))
		 (y (world->pixel (first line)  600 600 minx maxx miny maxy))
		 (x (world->pixel (second line) 600 600 minx maxx miny maxy))
		 (y (world->pixel (second line)  600 600 minx maxx miny maxy)))
(imlib:draw-line image color 
		 (+ 1 (x (world->pixel (first line) 600 600 minx maxx miny maxy)))
		 (y (world->pixel (first line)  600 600 minx maxx miny maxy))
		 (+ 1 (x (world->pixel (second line) 600 600 minx maxx miny maxy)))
		 (y (world->pixel (second line)  600 600 minx maxx miny maxy)))
(imlib:draw-line image color 
		 (x (world->pixel (first line) 600 600 minx maxx miny maxy))
		 (+ 1 (y (world->pixel (first line)  600 600 minx maxx miny maxy)))
		 (x (world->pixel (second line) 600 600 minx maxx miny maxy))
		 (+ 1 (y (world->pixel (second line)  600 600 minx maxx miny maxy))))
(imlib:draw-line image color 
		 (- (x (world->pixel (first line) 600 600 minx maxx miny maxy)) 1)
		 (y (world->pixel (first line)  600 600 minx maxx miny maxy))
		 (- (x (world->pixel (second line) 600 600 minx maxx miny maxy)) 1)
		 (y (world->pixel (second line)  600 600 minx maxx miny maxy)))
(imlib:draw-line image color 
		 (- (x (world->pixel (first line) 600 600 minx maxx miny maxy)) 0)
		 (- (y (world->pixel (first line)  600 600 minx maxx miny maxy)) 1)
		 (- (x (world->pixel (second line) 600 600 minx maxx miny maxy)) 0)
		 (- (y (world->pixel (second line)  600 600 minx maxx miny maxy)) 1)))

(define (draw-trace points image width height minx maxx miny maxy)
  (let loop ((points points))
    (if (< (length points) 2)
	(imlib:draw-ellipse image 
			    (x (world->pixel (first points) width height minx maxx miny maxy))
			    (y (world->pixel (first points) width height minx maxx miny maxy))
			    2 2 `#(0 0 255))
	(begin (draw-world-line (sublist points 0 2) image width height minx maxx miny maxy `#(0 0 255))
	       
	       (loop (rest points))))))

(define (draw-object-on-floorplan obj image color width height minx maxx miny maxy)
  (let* ((world-xy (second obj))
	 (pix-xy (vector (+ (* width (/ (x world-xy) (- maxx minx)))
			    (/ width 2))
			 (+ (- (* height (/ (y world-xy) (- maxy miny))))
			    (/ height 2)))))
    (imlib-draw-text-on-image image 
			      (symbol->string (first obj))
			      `#(0 0 0) 8 (x pix-xy) (y pix-xy) `#(255 255 255))
    (imlib:draw-ellipse image (x pix-xy) (y pix-xy) 2 2 color)))

(define (draw-floorplan-for-worksheet image trace floorplan)
 
(for-each
 (lambda (obj)
  (dtrace "drawing object:" obj)
   (draw-object-on-floorplan obj image `#(0 0 0) 600 600 -4 4 -4 4))
 floorplan)

(draw-object-on-floorplan (list 'start (vector 0 0)) image `#(0 0 0) 600 600 -4 4 -4 4)


(draw-trace trace image 600 600 -4 4 -4 4)
		 
)

(define (create-turk-sentences-image sentence-list
				     trace-image-file
				     output-filename)
 (let* ((image (imlib:create 2000 640))
	(trace-image (imlib:load! trace-image-file)) 
	;; (sub-clauses (map-indexed (lambda (c i)
	;; 			   (if (= i 0)
	;; 			       c
	;; 			       (string-append "then" c)))
	;; 			  (pregexp-split "then" sentence)))
	)
  (imlib:fill-rectangle image 0 0 2000 640 `#(255 255 255))
  (imlib:blend image trace-image #f 0 0 640 480 0 0 640 480)
  ;; (imlib-draw-text-on-image
  ;;    image 
  ;;    "Hello world!"
  ;;    `#(0 0 0) 12 10 480 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     (first sentence-list)
     `#(0 0 0) 8 10 480 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     (second sentence-list)
     `#(0 0 0) 8 10 520 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     (third sentence-list)
     `#(0 0 0) 8 10 560 `#(255 255 255))
  (imlib:save image output-filename)))

(define (make-acq-sentence-images)
 (let* ((image-file-prefix
	 "/net/seykhl/aux/sbroniko/vader-rover/plots/acquisition")
	(output-file-prefix
	 "/net/seykhl/aux/sbroniko/vader-rover/plots/turked/acquisition")
	(sentences
	 (read-object-from-file
	  "/home/dpbarret/aws-mturk-clt-1.3.1/hits/rover-sentences/parsed-acquisition-sentences.sc")))
  (for-each-indexed
   (lambda (sen i)
    (create-turk-sentences-image
     sen
     (format #f "~a~a.png"
	     image-file-prefix
	     (number->padded-string-of-length i 4))
     (format #f "~a~a.png"
	     output-file-prefix
	     (number->padded-string-of-length i 4))))
   sentences)))
	
(define (make-comp-sentence-images)
 (let* ((image-file-prefix
	 "/net/seykhl/aux/sbroniko/vader-rover/plots/comprehension")
	(output-file-prefix
	 "/net/seykhl/aux/sbroniko/vader-rover/plots/turked/comprehension")
	(sentences
	 (read-object-from-file
	  "/home/dpbarret/aws-mturk-clt-1.3.1/hits/rover-sentences/parsed-comprehension-sentences.sc")))
  (for-each-indexed
   (lambda (sen i)
    (create-turk-sentences-image
     sen
     (format #f "~a~a.png"
	     image-file-prefix
	     (number->padded-string-of-length i 4))
     (format #f "~a~a.png"
	     output-file-prefix
	     (number->padded-string-of-length i 4))))
   sentences)))


(define (create-sentence->trace-worksheet sentence trace floorplan tag)
 (let* ((image (imlib:create 1236 800))
	(sub-clauses (map-indexed (lambda (c i)
				   (if (= i 0)
				       c
				       (string-append "then" c)))
				  (pregexp-split "then" sentence))))
  (imlib:fill-rectangle image 0 0 1236 800 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     tag
     `#(0 0 0) 6 10 10 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     "Phrase covered by path? (Y/N)"
     `#(0 0 0) 14 600 25 `#(255 255 255))
  (for-each-indexed
   (lambda (c i)
    (imlib-draw-text-on-image
     image 
     c
     `#(0 0 0) 14 640 (+ 60 (* i 34)) `#(255 255 255))
    (imlib:draw-line image `#(0 0 0)
		   600 (+ 60 (* i 34)) 630 (+ 60 (* i 34)))
    (imlib:draw-line image `#(0 0 0)
		   600 (+ 60 (* (+ i 1) 34)) 630 (+ 60 (* (+ i 1) 34))))
   sub-clauses)
  (draw-floorplan-for-worksheet image (vector->list trace) floorplan)
  (imlib:draw-line image `#(0 0 0)
		   600 60 600 280)
  (imlib:draw-line image `#(0 0 0)
		   630 60 630 280)
  (imlib-draw-text-on-image
     image 
     "How much of the path depicts motion"
     `#(0 0 0) 14 600 300 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     "not described in the sentence?"
     `#(0 0 0) 14 600 328 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     "(0 means nothing extra. 5 is completely wrong)"
     `#(0 0 0) 14 600 365 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     "0  1  2  3  4  5"
     `#(0 0 0) 14 600 405 `#(255 255 255))
  image))




(define (create-trace->sentence-worksheet sentence trace floorplan tag)
 (let* ((image (imlib:create 1236 800))
	(sub-clauses (map-indexed (lambda (c i)
				   (if (= i 0)
				       c
				       (string-append "then" c)))
				  (pregexp-split "then" (pregexp-replace* "-" sentence " ")))))
  (imlib:fill-rectangle image 0 0 1236 800 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     tag
     `#(0 0 0) 6 10 10 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     "Phrase correct? (Y/N)"
     `#(0 0 0) 14 600 25 `#(255 255 255))
  (for-each-indexed
   (lambda (c i)
    (imlib-draw-text-on-image
     image 
     c
     `#(0 0 0) 14 640 (+ 60 (* i 34)) `#(255 255 255))
    (imlib:draw-line image `#(0 0 0)
		   600 (+ 60 (* i 34)) 630 (+ 60 (* i 34)))
    (imlib:draw-line image `#(0 0 0)
		   600 (+ 60 (* (+ i 1) 34)) 630 (+ 60 (* (+ i 1) 34))))
   sub-clauses)

  
  (imlib-draw-text-on-image
     image 
     "Rate the length of the sentence: "
     `#(0 0 0) 14 50 450 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     "(much too short) -2 -1 0 1 2 (much too long)"
     `#(0 0 0) 14 50 478 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     "How much of the path is "
     `#(0 0 0) 14 50 10 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     "covered by the sentence?"
     `#(0 0 0) 14 50 38 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     "(0 is completely wrong. 5 is complete coverage)"
     `#(0 0 0) 14 50 75 `#(255 255 255))
  (imlib-draw-text-on-image
     image 
     "0  1  2  3  4  5"
     `#(0 0 0) 14 50 115 `#(255 255 255))
  (draw-floorplan-for-worksheet image (vector->list trace) floorplan)
  (imlib:draw-line image `#(0 0 0)
		   600 60 600 280)
  (imlib:draw-line image `#(0 0 0)
		   630 60 630 280)
  
  image))


(define (create-trace->sentence-worksheets outpath)
 (let* ((dataset (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-generation-dataset.sc"))
	(dataset-tracks (map-n (lambda (p) (dataset-read-manual-tracks p dataset "/aux/dpbarret/rover-logs/MSEE1-dataset/generation")) 10))
	(sentences (read-object-from-file "/aux/dpbarret/rover-logs/MSEE1-dataset/generation/sentences.sc"))
	(images (join (map
		 (lambda (ft fd fs)
		 (map
		  (lambda (d t s)
		   (CREATE-TRACE->sentence-WORKSHEET (first s) t (first d) "tslm"))
		  fd ft fs))
		 dataset-tracks dataset sentences)))
	(images (append images (map-n (lambda (i) (let ((image (imlib:create 1236 800)))
						     (imlib:fill-rectangle image 0 0 1236 800 `#(255 255 255))))
				      (- 3 (modulo (length images) 3)))))
	(image-pairs
	 (shape-matrix (list->vector  images) 3))
	(pages (map-indexed-vector
		(lambda (pair i)
		 (let ((image (imlib:create 1236 1600)))
		  (imlib:blend image (x pair) #f 0 0 1236 800 0 0 1236 800)
		  (imlib:blend image (y pair) #f 0 0 1236 800 0 540 1236 800)
		  (imlib:blend image (z pair) #f 0 0 1236 800 0 1080 1236 800)
		  (imlib:save image (format #f "~a/page-~a.png" outpath
					    (number->padded-string-of-length i 4)))
		  (imlib:free (x pair))
		  (imlib:free (y pair))
		  (imlib:free image)))
		image-pairs)))
	#t))

(define (create-trace->sentence-hand-worksheets outpath)
 (let* ((dataset (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-generation-dataset.sc"))
	(dataset-tracks (map-n (lambda (p) (dataset-read-manual-tracks p dataset "/aux/dpbarret/rover-logs/MSEE1-dataset/generation")) 10))
	(sentences (read-object-from-file "/aux/dpbarret/rover-logs/MSEE1-dataset/generation/sentences-hand.sc"))
	(images (join (map
		 (lambda (ft fd fs)
		 (map
		  (lambda (d t s)
		   (CREATE-TRACE->sentence-WORKSHEET (first s) t (first d) "tshm"))
		  fd ft fs))
		 dataset-tracks dataset sentences)))
	(images (append images (map-n (lambda (i) (let ((image (imlib:create 1236 800)))
						     (imlib:fill-rectangle image 0 0 1236 800 `#(255 255 255))))
				      (- 3 (modulo (length images) 3)))))
	(image-pairs
	 (shape-matrix (list->vector  images) 3))
	(pages (map-indexed-vector
		(lambda (pair i)
		 (let ((image (imlib:create 1236 1600)))
		  (imlib:blend image (x pair) #f 0 0 1236 800 0 0 1236 800)
		  (imlib:blend image (y pair) #f 0 0 1236 800 0 540 1236 800)
		  (imlib:blend image (z pair) #f 0 0 1236 800 0 1080 1236 800)
		  (imlib:save image (format #f "~a/page-~a.png" outpath
					    (number->padded-string-of-length i 4)))
		  (imlib:free (x pair))
		  (imlib:free (y pair))
		  (imlib:free image)))
		image-pairs)))
	#t))

(define (create-trace->sentence-no-merge-worksheets outpath)
 (let* ((dataset (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-generation-dataset.sc"))
	(dataset-tracks (map-n (lambda (p) (dataset-read-manual-tracks p dataset "/aux/dpbarret/rover-logs/MSEE1-dataset/generation")) 10))
	(sentences (read-object-from-file "/aux/dpbarret/rover-logs/MSEE1-dataset/generation/sentences-no-merge.sc"))
	(images (join (map
		 (lambda (ft fd fs)
		 (map
		  (lambda (d t s)
		   (CREATE-TRACE->sentence-WORKSHEET (first s) t (first d) "tsl"))
		  fd ft fs))
		 dataset-tracks dataset sentences)))
	(images (append images (map-n (lambda (i) (let ((image (imlib:create 1236 800)))
						     (imlib:fill-rectangle image 0 0 1236 800 `#(255 255 255))))
				      (- 3 (modulo (length images) 3)))))
	(image-pairs
	 (shape-matrix (list->vector  images) 3))
	(pages (map-indexed-vector
		(lambda (pair i)
		 (let ((image (imlib:create 1236 1600)))
		  (imlib:blend image (x pair) #f 0 0 1236 800 0 0 1236 800)
		  (imlib:blend image (y pair) #f 0 0 1236 800 0 540 1236 800)
		  (imlib:blend image (z pair) #f 0 0 1236 800 0 1080 1236 800)
		  (imlib:save image (format #f "~a/page-~a.png" outpath
					    (number->padded-string-of-length i 4)))
		  (imlib:free (x pair))
		  (imlib:free (y pair))
		  (imlib:free image)))
		image-pairs)))
	#t))



(define (create-trace->sentence-hand-no-merge-worksheets outpath)
 (let* ((dataset (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-generation-dataset.sc"))
	(dataset-tracks (map-n (lambda (p) (dataset-read-manual-tracks p dataset "/aux/dpbarret/rover-logs/MSEE1-dataset/generation")) 10))
	(sentences (read-object-from-file "/aux/dpbarret/rover-logs/MSEE1-dataset/generation/sentences-hand-no-merge.sc"))
	(images (join (map
		 (lambda (ft fd fs)
		 (map
		  (lambda (d t s)
		   (CREATE-TRACE->sentence-WORKSHEET (first s) t (first d) "tsh"))
		  fd ft fs))
		 dataset-tracks dataset sentences)))
	(images (append images (map-n (lambda (i) (let ((image (imlib:create 1236 800)))
						     (imlib:fill-rectangle image 0 0 1236 800 `#(255 255 255))))
				      (- 3 (modulo (length images) 3)))))
	(image-pairs
	 (shape-matrix (list->vector  images) 3))
	(pages (map-indexed-vector
		(lambda (pair i)
		 (let ((image (imlib:create 1236 1600)))
		  (imlib:blend image (x pair) #f 0 0 1236 800 0 0 1236 800)
		  (imlib:blend image (y pair) #f 0 0 1236 800 0 540 1236 800)
		  (imlib:blend image (z pair) #f 0 0 1236 800 0 1080 1236 800)
		  (imlib:save image (format #f "~a/page-~a.png" outpath
					    (number->padded-string-of-length i 4)))
		  (imlib:free (x pair))
		  (imlib:free (y pair))
		  (imlib:free image)))
		image-pairs)))
	#t))


(define (compute-trace-trace-distance trace1 trace2)
 (let ((distance1
	(list-mean
	 (map (lambda (p1)
	       (minimum (map (lambda (p2)
			      (distance p1 p2))
			     trace2)))
	      trace1)))
	(distance2
	 (list-mean
	  (map (lambda (p1)
		(minimum (map (lambda (p2)
			       (distance p1 p2))
			      trace1)))
	       trace2))))
  (list (list-mean (list distance1 distance2)) distance1 distance2)))

(define (point-avg p1 p2)
 (vector (* .5 (+ (x p1) (x p2)))
	 (* .5 (+ (y p1) (y p2)))))

(define (interpolate-trace trace factor)
 (if (<= factor 1)
     trace
     (interpolate-trace
      (map-n-vector
       (lambda (i)
	(if (>= (+ (exact-floor (/ i 2)) 1) (vector-length trace))
	    (vector-ref trace (exact-floor (/ i 2)))
	    (let* ((point1 (vector-ref trace (exact-floor (/ i 2))))
		   (point2 (vector-ref trace (+ (exact-floor (/ i 2)) 1))))
	     (if (= (/ i 2) (exact-round (/ i 2)))
		 point1
		 (point-avg point1 point2)))))
       (- (* (vector-length trace) 2) 1))
      (/ factor 2))))

(define (compute-distances-between-planned-and-auto-tracks)
 (let* ((planned-tracks (map (lambda (fp) (map (lambda (p) (interpolate-trace
							    p
							    16))
					       fp))
			     (read-planned-tracks)))
	(auto-tracks (read-auto-tracks))
	(distances
	 (join
	  (map (lambda (fp fa)
		(map (lambda (p a)
		      (dtrace "" (first (compute-trace-trace-distance (vector->list p) (vector->list a)))))
		     fp fa))
	       planned-tracks
	       auto-tracks))))
  (list (list-mean distances) distances)))

(define (place-in-bin x bins min max)
 (let* ((bin-width  (/ (- max min) (vector-length bins)))
	(i (exact-floor (/ (- x min) bin-width))))
  (vector-set! bins i (+ (vector-ref bins i) 1))))

(define (plot-histogram data min max number-of-bins)
 (let* ((bins (make-vector number-of-bins 0)))
  (for-each
   (lambda (d)
    (place-in-bin d bins min max))
   data)
  (plot-lines-in-matlab
   (list (map (lambda (i) (+ (* (/ i number-of-bins) (- max min)) min))
	      (enumerate number-of-bins)))
   (list (vector->list bins)) (list "'foo'") "-o")))


(define (read-st-worksheet filename)
 (if (file-exists? filename)
 (let* ((lines (read-file filename))
	(completeness (map string->number (map first (remove-if (lambda (line) (equal? (first line) ";;")) (removeq '() (map fields lines))))))
	(correct (map string->number (map second (remove-if (lambda (line) (equal? (first line) ";;")) (removeq '() (map fields lines))))))
	(total (map string->number (map third (remove-if (lambda (line) (equal? (first line) ";;")) (removeq '() (map fields lines)))))))
  (list filename
	(list "completeness mean and std"
	      (list-mean completeness) (sqrt (list-variance completeness)))
	(list "correctness mean and std"
	      (list-mean (map (lambda (c t)
			       (/ c t))
			      correct total))
	      (sqrt (list-variance (map (lambda (c t)
			       (/ c t))
			      correct total))))
	(list "total correct and total"
	      (reduce + correct 0) (reduce + total 0))))
 #f))

(define (read-ts-worksheet filename)
 (if (file-exists? filename)
 (let* ((lines (read-file filename))
	(completeness (map string->number (map first (remove-if (lambda (line) (equal? (first line) ";;")) (removeq '() (map fields lines))))))
	(correct (map string->number (map second (remove-if (lambda (line) (equal? (first line) ";;")) (removeq '() (map fields lines))))))
	(total (map string->number (map third (remove-if (lambda (line) (equal? (first line) ";;")) (removeq '() (map fields lines))))))
	(redundancy (map string->number (map fourth (remove-if (lambda (line) (equal? (first line) ";;")) (removeq '() (map fields lines)))))))
  (scheme->matlab! "foo" redundancy)
  (matlab "baz = hist(foo,[-2 -1 0 1 2])")
  (matlab "figure")
  (matlab "bar([-2 -1 0 1 2],baz)")
  (matlab (format #f "title('length rating for ~a')" filename)) 
  (list filename
	(list "completeness mean and std"
	      (list-mean completeness) (sqrt (list-variance completeness)))
	(list "correctness mean and std"
	      (list-mean (map (lambda (c t)
			       (/ c t))
			      correct total))
	      (sqrt (list-variance (map (lambda (c t)
			       (/ c t))
			      correct total))))
	(list "total correct and total"
	      (reduce + correct 0) (reduce + total 0))
	(list "redundacy mean and std"
	      (list-mean redundancy) (sqrt (list-variance redundancy)))
	(list "absolute length-error mean and std"
	      (list-mean (map abs redundancy)) (sqrt (list-variance (map abs redundancy))))
	redundancy
	
	))
 #f))

(define (read-all-st-worksheets)
(let* ((spt1 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/spt1.txt"))
       (spt2 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/spt2.txt"))
       (spt3 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/spt3.txt"))
       (slt1 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/slt1.txt"))
       (slt2 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/slt2.txt"))
       (slt3 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/slt3.txt")))
 (list
  (list "aggregate"
	(list "spt"
	      (list "completeness"
		    (list-mean (map second (map second (list spt1 spt2 spt3))))
		    (sqrt (list-variance (map second (map second (list spt1 spt2 spt3))))))
	      (list "correctness"
		    (list-mean (map second (map third (list spt1 spt2 spt3))))
		    (sqrt (list-variance (map second (map third (list spt1 spt2 spt3)))))))
	(list "slt"
	      (list "completeness"
		    (list-mean (map second (map second (list slt1 slt2 slt3))))
		    (sqrt (list-variance (map second (map second (list slt1 slt2 slt3))))))
	      (list "correctness"
		    (list-mean (map second (map third (list slt1 slt2 slt3))))
		    (sqrt (list-variance (map second (map third (list slt1 slt2 slt3))))))))
  (list "individual"
	(list
	 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/spt1.txt")
	 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/spt2.txt")
	 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/spt3.txt")
	 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/slt1.txt")
	 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/slt2.txt")
	 (read-st-worksheet "/home/dpbarret/darpa-collaboration/rover/slt3.txt"))))))

(define (read-all-ts-worksheets) ;;non-merged
 (let* ((tsl1 (read-ts-worksheet "/home/dpbarret/darpa-collaboration/rover/tsl1.txt"))
	(tsl2 (read-ts-worksheet "/home/dpbarret/darpa-collaboration/rover/tsl2.txt"))
	(tsl3 (read-ts-worksheet "/home/dpbarret/darpa-collaboration/rover/tsl3.txt"))
	(tsh1 (read-ts-worksheet "/home/dpbarret/darpa-collaboration/rover/tsh1.txt"))
	(tsh2 (read-ts-worksheet "/home/dpbarret/darpa-collaboration/rover/tsh2.txt"))
	(tsh3 (read-ts-worksheet "/home/dpbarret/darpa-collaboration/rover/tsh3.txt"))
	(tsl-redundancy (join (map (lambda (tsl) (seventh tsl)) (list tsl1 tsl2 tsl3))))
	(tsh-redundancy (join (map (lambda (tsh) (seventh tsh)) (list tsh1 tsh2 tsh3)))))
	
 (scheme->matlab! "foo" tsh-redundancy)
  (matlab "baz = hist(foo,[-2 -1 0 1 2])")
  (matlab "figure")
  (matlab "bar([-2 -1 0 1 2],baz)")
  (matlab (format #f "title('Conciseness for sentences generated by hand-constructed models')")) 

 (scheme->matlab! "foo" tsl-redundancy)
  (matlab "baz = hist(foo,[-2 -1 0 1 2])")
  (matlab "figure")
  (matlab "bar([-2 -1 0 1 2],baz)")
  (matlab (format #f "title('Conciseness for sentences generated by learned models')")) 
  
  
  (list "aggregate"
	(list "tsl"
	      (list "completeness"
		    (list-mean (map second (map second (list tsl1 tsl2 tsl3))))
		    (sqrt (list-variance (map second (map second (list tsl1 tsl2 tsl3))))))
	      (list "correctness"
		    (list-mean (map second (map third (list tsl1 tsl2 tsl3))))
		    (sqrt (list-variance (map second (map third (list tsl1 tsl2 tsl3)))))))
	(list "tsh"
	      (list "completeness"
		    (list-mean (map second (map second (list tsh1 tsh2 tsh3))))
		    (sqrt (list-variance (map second (map second (list tsh1 tsh2 tsh3))))))
	      (list "correctness"
		    (list-mean (map second (map third (list tsh1 tsh2 tsh3))))
		    (sqrt (list-variance (map second (map third (list tsh1 tsh2 tsh3)))))))
       
  (list "individual"
   (list "tsl"
	 tsl1 tsl2 tsl3
   (list "tsh"
	 tsh1 tsh2 tsh3))))))


(define (plot-lines-in-matlab x-lists y-lists labels symbol)
 (matlab "X=[];")
 (matlab "Y=[];")
  (matlab (string-append
   "h=plot("
   (reduce (lambda (s1 s2)
	    (string-append s1 "," s2))
	   (map (lambda (x-values y-values i)
		     (scheme->matlab! "tempx" x-values)
		     (scheme->matlab! "tempy" y-values)
		     (matlab (format #f
				     "X{~a}=tempx;"
				     (+ i 1)))
		     (matlab (format #f
				     "Y{~a}=tempy;"
				     (+ i 1)))
		     (format #f
			     (string-append "X{~a},Y{~a},"
					    ""symbol"")
			     (+ i 1)
			     (+ i 1)))
		    x-lists y-lists (enumerate (length x-lists)))
   	   "")
   ")"))
  (matlab (string-append
	   "legend(h,"
	   (reduce (lambda (s1 s2)
		    (string-append s1 "," s2))
		   labels
		   "")
	   ",'Location','NorthWest')")))


(define (plot-lines-in-matlab-with-symbols x-lists y-lists labels symbols)
 (matlab "X=[];")
 (matlab "Y=[];")
  (matlab (string-append
   "h=plot("
   (reduce (lambda (s1 s2)
	    (string-append s1 "," s2))
	   (map (lambda (x-values y-values symbol i)
		     (scheme->matlab! "tempx" x-values)
		     (scheme->matlab! "tempy" y-values)
		     (matlab (format #f
				     "X{~a}=tempx;"
				     (+ i 1)))
		     (matlab (format #f
				     "Y{~a}=tempy;"
				     (+ i 1)))
		     (format #f
			     (string-append "X{~a},Y{~a},"
					    ""symbol"")
			     (+ i 1)
			     (+ i 1)))
		    x-lists y-lists symbols (enumerate (length x-lists)))
   	   "")
   ")"))
  (matlab (string-append
	   "legend(h,"
	   (reduce (lambda (s1 s2)
		    (string-append s1 "," s2))
		   labels
		   "")
	   ",'Location','NorthWest')")))

(define (plot-lines-in-matlab-with-symbols-no-legend x-lists
						     y-lists
						     labels
						     symbols)
 (matlab "X=[];")
 (matlab "Y=[];")
  (matlab
   (string-append
    "h=plot("
    (reduce (lambda (s1 s2)
	     (string-append s1 "," s2))
	    (map (lambda (x-values y-values symbol i)
		  (scheme->matlab! "tempx" x-values)
		  (scheme->matlab! "tempy" y-values)
		  (matlab (format #f
				  "X{~a}=tempx;"
				  (+ i 1)))
		  (matlab (format #f
				     "Y{~a}=tempy;"
				     (+ i 1)))
		  (format #f
			  (string-append "X{~a},Y{~a},"
					 ""symbol"")
			  (+ i 1)
			  (+ i 1)))
		 x-lists y-lists symbols (enumerate (length x-lists)))
   	   "")
    ")")
   )
  )

(define (matlab-quiver-with-linespec list-of-xyuv-vectors
				     linespec)
 (scheme->matlab! "XYUV" list-of-xyuv-vectors)
 (matlab (format #f
		 "hq=quiver(XYUV(:,1),XYUV(:,2),XYUV(:,3),XYUV(:,4),~a);"
		 linespec))
 )

(define (matlab-plot-arrowheads-on-trace-OLD list-of-xyuv-vectors)
 (let* ((quiver-linespec "'LineStyle','-'") ;;prints quiver invisibly
	(arrow-linespec "'k','HeadStyle','vback3','HeadLength',100,'HeadWidth',100"))
  (scheme->matlab! "XYUV" list-of-xyuv-vectors)
  (matlab (format #f
		  "hq=quiver(XYUV(:,1),XYUV(:,2),XYUV(:,3),XYUV(:,4),~a);"
		  quiver-linespec))
  (matlab "hkid = get(hq,'children');")
  (matlab "X = get(hkid(1),'XData');")
  (matlab "Y = get(hkid(1),'YData');")
  (matlab "for i = 1:3:length(X)-1;
                       xa = [X(i),X(i+1)]; ya = [Y(i),Y(i+1)];
                       [xaf,yaf] = ds2nfu(xa,ya);
                       ah = annotation('arrow',xaf,yaf);
                  end;")))


(define (matlab-plot-arrowheads-on-trace list-of-xy-vectors)
 (let* ((arrow-linespec
	 "'Color','cyan','HeadStyle','vback3','HeadLength',10,'HeadWidth',10"))
  (scheme->matlab! "D" list-of-xy-vectors)
  (matlab "axis([-4 4 -4 4])")
  (matlab "[r,c] = size(D)")
  (matlab (format #f
		  "for i = 1:r;
                       xa = [D(i,1),D(i,3)]; ya = [D(i,2),D(i,4)];
                       [xaf,yaf] = ds2nfu(xa,ya);
                       ah = annotation('arrow',xaf,yaf,~a);
                   end;" arrow-linespec))
  (matlab "set(gcf,'WindowStyle','normal'); set(gcf, 'Position', [0 0 900 800])")))
		  

(define (plot-trace trace objects)
 (plot-lines-in-matlab-with-symbols
  (list (map x
	     (map second objects))
	(map x (vector->list trace)))
  (list (map y (map second objects))
	(map y (vector->list trace)))
  (list "'objects'" "'trace'") (list "'b.'" "'g-','LineWidth',2"))
 (map (lambda (object)
       (matlab (format #f "text(~a,~a,'~a')" (x (second object)) (y (second object))
		       (symbol->string (remove-the (first object))))))
      objects)
 (matlab "hold off")
 (matlab "axis equal"))

(define (plot-trace-no-legend trace objects)
 (let* ((start (vector-ref trace 0))
	(end (vector-ref trace (- (vector-length trace) 1)))
	(interval 3) ;;interval between points for arrow heads
	(smooth 1);;(exact-round (/ interval 2)))
	(reduced-trace-initial
	 (removeq #f (map-indexed
		      (lambda (x i)
		       (if (= 0 (modulo i interval)) x #f))
		      (vector->list trace))))
	(reduced-trace-next
	 (removeq #f (map-indexed
		      (lambda (x i)
		       (if (= smooth (modulo i interval)) x #f)) ;smoothing factor
		      (vector->list trace))))
	;; (xys (if (= (length reduced-trace-initial)
	;; 	    (length reduced-trace-next))
	;; 	 reduced-trace-initial
	;; 	 (sublist reduced-trace-initial 0
	;; 		  (length reduced-trace-next))))
	;; (uvs (map v- reduced-trace-next xys))
	;; (xyuvs (map vector-append xys uvs))
	(x1y1 (if (= (length reduced-trace-initial)
		     (length reduced-trace-next))
		  reduced-trace-initial
		  (sublist reduced-trace-initial 0
			   (length reduced-trace-next))))
	(xy-data (if (or (null? x1y1)
			 (null? reduced-trace-next))
		     '()
		     (sublist
		      (map vector-append x1y1 reduced-trace-next)
		      0 (- (length reduced-trace-next) 1))))
	)
  (matlab "hold on")
;;  (dtrace "reduced-trace-initial" reduced-trace-initial)
;;  (dtrace "reduced-trace-next" reduced-trace-next)
  (plot-lines-in-matlab-with-symbols-no-legend
   (list (map x (map second objects)))
   (list (map y (map second objects)))
   (list "'objects'")
   (list "'md','MarkerFaceColor','m'"))
  (plot-lines-in-matlab-with-symbols-no-legend
   (list (map x (vector->list trace)))
   (list (map y (vector->list trace)))
   (list "'trace'")
   (list "'c-','LineWidth',2"))
  ;; (plot-lines-in-matlab-with-symbols-no-legend
  ;;  (list (map x
  ;; 	      (map second objects))
  ;; 	 (map x (vector->list trace)))
  ;;  (list (map y (map second objects))
  ;; 	 (map y (vector->list trace)))
  ;;  (list "'objects'" "'trace'")
  ;;  (list "'md'" "'c-','LineWidth',2"))
  (plot-lines-in-matlab-with-symbols-no-legend
   (list (list (first (vector->list start))))
   (list (list (second (vector->list start))))
   (list "'start'" )
   (list "'go','MarkerFaceColor','g'"))
  (plot-lines-in-matlab-with-symbols-no-legend
   (list (list (first (vector->list end))))
   (list (list (second (vector->list end))))
   (list "'end'" )
   (list "'ro','MarkerFaceColor','r'"))
  (map (lambda (object)
	(matlab (format #f "text(~a,~a,'~a')" (x (second object)) (y (second object))
			(symbol->string (remove-the (first object))))))
       objects)
  
  (matlab (format #f "text(~a,~a,'~a')" (x start) (y start) "start"))
  (matlab (format #f "text(~a,~a,'~a')" (x end) (y end) "end"))
  ;;(matlab "axis([-4 4 -4 4])")
  ;; (matlab-quiver-with-linespec xyuvs
  ;; 			       "'k','AutoScale','on','LineWidth',3,'MaxHeadSize',500000,'LineStyle','none'")
  (if (null? reduced-trace-next)
      (dtrace "nothing to plot" #f)
      (matlab-plot-arrowheads-on-trace xy-data)
      )
  (matlab "hold off")
  ;; (matlab "axis equal")
  ))


(define (plot-trace-for-paper floorplan-sentence-trace)
 (plot-trace (third floorplan-sentence-trace)
	     (first floorplan-sentence-trace))
 (matlab "axis([-4 4 -4 4])")
 (matlab "set(gcf,'WindowStyle','normal'); set(gcf, 'Position', [0 0 400 400])"))

(define (plot-trace-for-turk floorplan-sentence-trace)
 (matlab "clear all; close all;") ;;get rid of old figures/data
 (plot-trace-no-legend (third floorplan-sentence-trace)
		       (first floorplan-sentence-trace))
 (matlab "box on"))

(define (plot-trace-for-turk-and-save floorplan-sentence-trace
				      outdir filename n)
 (matlab "clear all; close all;") ;;get rid of old figures/data
 (plot-trace-no-legend (third floorplan-sentence-trace)
		       (first floorplan-sentence-trace))
 (matlab "box on")
 (matlab (format #f
		 "saveas(gcf,'~a/~a~a.png');"
		 outdir
		 filename
		 (number->padded-string-of-length n 4))))

(define (run-acquisition-plots)
 (let* ((outdir "/aux/sbroniko/vader-rover/plots")
	(filename "acquisition"))
  (for-each-indexed
   (lambda (run n)
    (plot-trace-for-turk-and-save run outdir filename n))
   acquisition-dataset)))

(define (run-comprehension-plots)
 (let* ((outdir "/aux/sbroniko/vader-rover/plots")
	(filename "comprehension"))
  (for-each-indexed
   (lambda (run n)
    (plot-trace-for-turk-and-save run outdir filename n))
   comprehension-dataset)))

(define (run-acquisition-plots-new)
 (let* ((outdir "/aux/sbroniko/vader-rover/plots/second-amt-run")
	(filename "acquisition"))
  (for-each-indexed
   (lambda (run n)
    (plot-trace-for-turk-and-save run outdir filename n))
   acquisition-dataset)))

(define (run-comprehension-plots-new)
 (let* ((outdir "/aux/sbroniko/vader-rover/plots/second-amt-run")
	(filename "comprehension"))
  (for-each-indexed
   (lambda (run n)
    (plot-trace-for-turk-and-save run outdir filename n))
   comprehension-dataset)))

(define (run-generation-plots-new)
 (let* ((outdir "/aux/sbroniko/vader-rover/plots/second-amt-run")
	(filename "generation"))
  (for-each-indexed
   (lambda (run n)
    (plot-trace-for-turk-and-save run outdir filename n))
   generation-dataset)))

(define (run-auto-drive-plots-new)
 (let* ((outdir "/aux/sbroniko/vader-rover/plots/second-amt-run")
	(filename "auto-drive"))
  (for-each-indexed
   (lambda (run n)
    (plot-trace-for-turk-and-save run outdir filename n))
   auto-drive-dataset)))

(define (run-auto-drive-plots-new-from-number number)
 (let* ((outdir "/aux/sbroniko/vader-rover/plots/second-amt-run")
	(filename "auto-drive"))
  (for-each-indexed
   (lambda (run n)
    (plot-trace-for-turk-and-save run outdir filename (+ n number)))
   (sublist auto-drive-dataset number (length auto-drive-dataset)))))


(define (visualize-noun-model d)
 (scheme->matlab! "foo" d)
;; (matlab "figure")
 (matlab "bar(foo)")
(matlab "set(gca,'XTickLabel',{'bag','box','chair','cone','stool','table'})")
 )

(define foo (list "bag" "box" "chair" "cone" "stool" "table"))

;;dataset stuff
;; (define downsampled-dataset (join (downsample-dataset-tracks2 (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-dataset.sc") "/net/mohio/aux/dpbarret/rover-logs/MSEE1-dataset/training-runs")))

;; (define *test-data* (first downsampled-dataset))

;; (define acquisition-dataset (join (downsample-dataset-tracks2 (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-dataset.sc") "/net/mohio/aux/dpbarret/rover-logs/MSEE1-dataset/training-runs")))

;; (define auto-drive-dataset (join (downsample-dataset-tracks4 (read-object-from-file "/home/sbroniko/vader-rover/dsci-on-latop/turk-comprehension-dataset.sc") "/net/seykhl/aux/sbroniko/vader-rover/logs/MSEE2-dataset")))

;; (define comprehension-dataset (downsample-dataset-tracks3 (join (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-auto-drive-datasetb.sc"))))

;; BAD (define generation-dataset (downsample-dataset-tracks3 (join (read-object-from-file "/home/dpbarret/darpa-collaboration/rover/msee1-generation-dataset.sc"))))

;; (define generation-dataset (join (downsample-dataset-tracks2 (read-object-from-file "/net/seykhl/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation/msee1-generation-dataset.sc") "/net/seykhl/aux/sbroniko/vader-rover/logs/MSEE1-dataset/generation")))


(define comp-sentences (read-object-from-file "/home/dpbarret/aws-mturk-clt-1.3.1/hits/rover-sentences/parsed-comprehension-sentences.sc"))
(define acq-sentences (read-object-from-file "/home/dpbarret/aws-mturk-clt-1.3.1/hits/rover-sentences/parsed-acquisition-sentences.sc"))