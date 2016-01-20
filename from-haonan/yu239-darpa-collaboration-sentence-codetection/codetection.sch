(DEFINE-EXTERNAL *OBJECTS-HOUSE* PARSER)
(DEFINE-EXTERNAL *OBJECTS-CAD* PARSER)
(DEFINE-EXTERNAL (THETA-ROLES->UNIVERSAL-PREDICATES-AND-OBJECTS THETA-ROLES-MENU OBJECTS) PARSER)
(DEFINE-EXTERNAL (PREGEXP S) PREGEXP)
(DEFINE-EXTERNAL (PREGEXP-SPLIT PAT STR) PREGEXP)
(DEFINE-EXTERNAL (O A B . C) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (ALL-PAIRS L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (MEDIAN LST) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (CURRENT-TIME) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (HOSTNAME) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (MATRIX->LIST-OF-LISTS M) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (LIST-OF-LISTS->MATRIX LOL) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (TAKE N L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (DROP N L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (JOIN L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (EVENLY-PICK-M LST M) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (GROUP-BY F L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL FFMPEG-OPEN-VIDEO CODETECTIONLIB-SC)
(DEFINE-EXTERNAL FFMPEG-VIDEO-FRAME-DATA-AS-IMLIB CODETECTIONLIB-SC)
(DEFINE-EXTERNAL FFMPEG-CLOSE-VIDEO CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (FFMPEG-NEXT-FRAME! VIDEO) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:DRAW-RECTANGLE IMAGE X1 Y1 W H COLOR THICKNESS) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:TEXT-DRAW IMAGE X Y TEXT COLOR FONT-SIZE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:FREE-IMAGE-AND-DECACHE IMAGE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:SAVE-IMAGE IMAGE FILE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:HEIGHT IMAGE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:WIDTH IMAGE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (MATLAB . STRINGS) TOOLLIB-MATLAB)
(DEFINE-EXTERNAL (START-MATLAB!) TOOLLIB-MATLAB)
(DEFINE-EXTERNAL (SCHEME->MATLAB! VARIABLE S) TOOLLIB-MATLAB)
(DEFINE-EXTERNAL (MATLAB-GET-VARIABLE NAME) TOOLLIB-MATLAB)
(DEFINE-EXTERNAL (SYMBOL->C-STRING S) TOOLLIB-C-BINDINGS)
(DEFINE-EXTERNAL (ELEMENTWISE-MATRIX-MAX M1 M2) TOOLLIB-C-BINDINGS)
(DEFINE-EXTERNAL (EASY-FFI:FREE N X V) EASY-FFI)
(DEFINE-EXTERNAL EASY-FFI:DOUBLE-TO-C EASY-FFI)
(DEFINE-EXTERNAL EASY-FFI:INT-TO-C EASY-FFI)
(DEFINE-EXTERNAL EASY-FFI:LONGUNSIGNED-TO-C EASY-FFI)
(DEFINE-EXTERNAL EASY-FFI:DOUBLE-FROM-C EASY-FFI)
(DEFINE-EXTERNAL EASY-FFI:INT-FROM-C EASY-FFI)
