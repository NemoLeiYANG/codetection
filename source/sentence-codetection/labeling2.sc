;;test data setup for multiple seeded runs with wraparound overlap
(define *asm-full* (read-object-from-file "asm_20150702.sc")) ;;base data
(define *total-peaks* (vector-length *asm-full))
(define *num-runs* 5) ;;must be odd

;;abandoning this idea, see notes 24Jul15