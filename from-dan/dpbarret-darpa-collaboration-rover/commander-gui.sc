(define *cdr-viewer-active* #f)

(define (my-quit-command)
 ;;update variable first
 (let ((tempvar (read-cdr-viewer-active)))
 (if (= tempvar 1)
     (set! *cdr-viewer-active* #t)
     (set! *cdr-viewer-active* #f))
 (if (not (dtrace "viewer active?" *cdr-viewer-active*))
     (quit))))

(define (define-buttons)
 ;;(standard-buttons 2 (lambda () #f))
 (define-button 0 0 "Quit" #f
  (lambda () (my-quit-command)))
 ;; (define-button 5 7 "Start Cameras" #f
 ;;  (lambda () (gamepad-start-cameras)))
 ;; (define-button 5 8 "Stop Cameras" #f
 ;;  (lambda () (gamepad-stop-cameras)))
 ;; (define-button 6 0 "Start Emperor" #f
 ;;  (lambda ()
 ;;   (system "ssh -p 22222 root@localhost \"/root/bin/emperor &\" &")))
 ;; (define-button 6 1 "Stop Emperor" #f
 ;;  (lambda ()
 ;;   (system "ssh -p 22222 root@localhost \"pkill emperor\" &")))
 (define-button 4 0 "Test Image Get" #f
  (lambda () (cdr-get-next-image-command)))
 )

(define (define-keys)
 ;; misc settings:
 (define-key escape "Get Images" cdr-get-next-image-command) ;;defined in toollib-rover.sc
 (define-key (control #\m) "Enter command"
  (lambda () (dtrace "the string you typed:" *input*))))

(set! *program* "commander-viewer")

(define-application viewer
 ;; Example:
 ;;   (viewer '())
 1600 800  ; Dimension of the window
 1        ; TRANSCRIPT-LINES
 2        ; BUTTON-ROWS
 5        ; BUTTON-COLUMNS
 ;;; Pre-initialize procedure:
 (lambda ()
  ;;(set! *clear-display-pane?* #f)
  ;;(setup-extra-x-gcs)
  (format #t "Calling Pre-init~%")
  (define-buttons)
  (define-keys)
  (cdr-viewer-setup)
  (cdr-viewer-start)
  (dtrace "Finished calling the god-damned pre-initialize function" "")
  )
 ;;; Post-initialize procedure:
 (lambda () ;(wait-for-next-frame 0)
  (dtrace ""  "Calling Post-init")
  )
 ;;; Finalize procedure:
 (lambda ()
  (dtrace ""  "Calling Finalize")
  (cdr-viewer-cleanup)
  (imlib-context-disconnect-display))
 ;;; Redraw procedure:
 (lambda ()
  (display "redraw")
  ;; (let loop ()
  ;; (let* ((image (imlib:load! "/home/sbroniko/vader-rover/GR-final.ppm")))
  ;; ;; (let* ((image (imlib:load! "/net/rongovosai/tmp/frames/00001.ppm")))
  ;;  (draw-imlib-pixmap image 0 0)
  ;;  (imlib:free image))
  ;; (display "hello") (newline)
  ;; (loop))
	 
  )
 ;;; Listener procedure:
 (lambda ()
  (dtrace ""  "Calling Listener")
  ))