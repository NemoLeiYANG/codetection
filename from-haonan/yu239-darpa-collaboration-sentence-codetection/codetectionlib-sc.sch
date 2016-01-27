(DEFINE-EXTERNAL (STRING-JOIN DELIM L) PARSER)
(DEFINE-EXTERNAL (PREGEXP-SPLIT PAT STR) PREGEXP)
(DEFINE-EXTERNAL (O A B . C) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (ZIP A B . CS) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (ALL-POSITIONS X LST) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (ALL-PAIRS L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (MEDIAN LST) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (CURRENT-TIME) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (HOSTNAME) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (CURRENT-DATE-AND-TIME) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (LIST-MEAN P) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (RANDOMIZE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (NONDETERMINISTIC-MAP F L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (INITIAL-SUBLIST? REF L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (MAXIMUMP L P) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (FLATTEN* L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (MATRIX->LIST-OF-LISTS M) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (LIST-OF-LISTS->MATRIX LOL) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (SPLIT-INTO N L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (TAKE N L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (DROP N L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (SPLIT-N N L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (JOIN L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (UNZIP L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (PAD-IF-NECESSARY LST LEN ELEMENT) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (TAKE-IF-POSSIBLE N L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (RAND-PICK-M LST M) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (TAKE-EVERY-N LST N) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (MIDDLE LST) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (TRANSPOSE-LIST-OF-LISTS LOL) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (EVENLY-PICK-M LST M) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (GROUP-BY F L) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (UPPER-TRUNCATE T X) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (SIGMOID T A B) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (TRACE->SPLINES TRACE NUMBER-OF-POINTS) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL FFMPEG-OPEN-VIDEO CODETECTIONLIB-SC)
(DEFINE-EXTERNAL FFMPEG-VIDEO-FRAME-DATA-AS-IMLIB CODETECTIONLIB-SC)
(DEFINE-EXTERNAL FFMPEG-CLOSE-VIDEO CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (FFMPEG-NEXT-FRAME! VIDEO) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL IMLIB:CONTEXT-SET-IMAGE! CODETECTIONLIB-SC)
(DEFINE-EXTERNAL IMLIB:CONTEXT-SET-COLOR! CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:CONTEXT-SET-COLOR-RGB/A! COLOR) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:DRAW-RECTANGLE IMAGE X1 Y1 W H COLOR THICKNESS) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (*DEFAULT-FONT-PATH*) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL IMLIB:CONTEXT-SET-FONT! CODETECTIONLIB-SC)
(DEFINE-EXTERNAL IMLIB:LOAD-IMAGE CODETECTIONLIB-SC)
(DEFINE-EXTERNAL IMLIB:LOAD-FONT! CODETECTIONLIB-SC)
(DEFINE-EXTERNAL IMLIB:FREE-FONT CODETECTIONLIB-SC)
(DEFINE-EXTERNAL IMLIB:ADD-PATH-TO-FONT-PATH CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:TEXT-DRAW IMAGE X Y TEXT COLOR FONT-SIZE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:FREE-IMAGE-AND-DECACHE IMAGE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:SAVE-IMAGE IMAGE FILE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:HEIGHT IMAGE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:WIDTH IMAGE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:CLONE IMAGE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (IMLIB:DATA-PTR-READ-ONLY IMAGE) CODETECTIONLIB-SC)
(DEFINE-EXTERNAL (MATLAB . STRINGS) TOOLLIB-MATLAB)
(DEFINE-EXTERNAL (FOLDL F L I) TOOLLIB-MATLAB)
(DEFINE-EXTERNAL (SCHEME->MATLAB! VARIABLE S) TOOLLIB-MATLAB)
(DEFINE-EXTERNAL (MATLAB-GET-VARIABLE NAME) TOOLLIB-MATLAB)