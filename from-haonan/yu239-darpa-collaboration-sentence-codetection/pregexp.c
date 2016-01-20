
/* SCHEME->C */

#include <objects.h>

void pregexp__init();
DEFSTATICTSCP( c16100 );
DEFSTATICTSCP( c15766 );
DEFSTATICTSCP( c15765 );
DEFSTATICTSCP( c15246 );
DEFSTATICTSCP( c15156 );
DEFSTATICTSCP( t16796 );
DEFSTATICTSCP( t16797 );
DEFSTATICTSCP( c15053 );
DEFSTATICTSCP( c14976 );
DEFSTATICTSCP( t16798 );
DEFSTATICTSCP( t16799 );
DEFSTATICTSCP( c14975 );
DEFSTATICTSCP( c14971 );
DEFSTATICTSCP( c14967 );
DEFSTATICTSCP( c14963 );
DEFSTATICTSCP( c14959 );
DEFSTATICTSCP( c14932 );
DEFSTATICTSCP( c14829 );
DEFSTATICTSCP( c14537 );
DEFSTATICTSCP( c14536 );
DEFSTATICTSCP( c14529 );
DEFSTATICTSCP( c14522 );
DEFSTATICTSCP( c14518 );
DEFSTATICTSCP( c14514 );
DEFSTATICTSCP( c14510 );
DEFSTATICTSCP( c14503 );
DEFSTATICTSCP( c14499 );
DEFSTATICTSCP( c14495 );
DEFSTATICTSCP( c14491 );
DEFSTATICTSCP( c14487 );
DEFSTATICTSCP( c14350 );
DEFSTATICTSCP( c14312 );
DEFSTATICTSCP( c14290 );
DEFSTATICTSCP( c14236 );
DEFSTATICTSCP( c14059 );
DEFSTATICTSCP( c13925 );
DEFSTATICTSCP( c13857 );
DEFSTATICTSCP( c13856 );
DEFSTATICTSCP( c13855 );
DEFSTATICTSCP( c13854 );
DEFSTATICTSCP( c13851 );
DEFSTATICTSCP( c13626 );
DEFSTATICTSCP( c13620 );
DEFSTATICTSCP( c13619 );
DEFSTATICTSCP( c13595 );
DEFSTATICTSCP( c13507 );
DEFSTATICTSCP( c13378 );
DEFSTATICTSCP( c13369 );
DEFSTATICTSCP( c13360 );
DEFSTATICTSCP( c13320 );
DEFSTATICTSCP( c13319 );
DEFSTATICTSCP( c13277 );
DEFSTATICTSCP( c13276 );
DEFSTATICTSCP( c13254 );
DEFSTATICTSCP( c13201 );
DEFSTATICTSCP( c13076 );
DEFSTATICTSCP( c13003 );
DEFSTATICTSCP( c12994 );
DEFSTATICTSCP( c12985 );
DEFSTATICTSCP( c12976 );
DEFSTATICTSCP( t16800 );
DEFSTATICTSCP( c12951 );
DEFSTATICTSCP( c12942 );
DEFSTATICTSCP( c12925 );
DEFSTATICTSCP( c12916 );
DEFSTATICTSCP( c12689 );
DEFSTATICTSCP( c12680 );
DEFSTATICTSCP( c12671 );
DEFSTATICTSCP( c12606 );
DEFSTATICTSCP( c12572 );
DEFSTATICTSCP( c12547 );
DEFSTATICTSCP( c12546 );
DEFSTATICTSCP( c12481 );
DEFSTATICTSCP( c12327 );
DEFSTATICTSCP( c12320 );
DEFCSTRING( t16801, "Argument is out of range: ~s" );
DEFSTATICTSCP( c12261 );
DEFCSTRING( t16802, "Argument is not a STRING: ~s" );
DEFSTATICTSCP( c12260 );
DEFSTATICTSCP( c12259 );
DEFCSTRING( t16803, "Argument is not an INTEGER: ~s" );
DEFSTATICTSCP( c12238 );
DEFSTATICTSCP( c12237 );
DEFCSTRING( t16804, "Argument(s) not CHAR: ~s ~s" );
DEFSTATICTSCP( c12231 );
DEFSTATICTSCP( c12230 );
DEFCSTRING( t16805, "pregexp-error" );
DEFSTATICTSCP( c12195 );
DEFCSTRING( t16806, "Error:" );
DEFSTATICTSCP( c12170 );
DEFCSTRING( t16807, "Argument not a PAIR: ~s" );
DEFSTATICTSCP( c12163 );
DEFSTATICTSCP( c12162 );
DEFCSTRING( t16808, "Argument not an unsigned 8-bit INTEGER: ~s" );
DEFSTATICTSCP( c12101 );
DEFSTATICTSCP( c12100 );
DEFCSTRING( t16809, "Argument not a CHAR: ~s" );
DEFSTATICTSCP( c12071 );
DEFSTATICTSCP( c12070 );

static void  init_constants()
{
        c16100 = EMPTYLIST;
        c16100 = CONS( _TSCP( 10514 ), c16100 );
        c16100 = CONS( _TSCP( 10258 ), c16100 );
        c16100 = CONS( _TSCP( 32018 ), c16100 );
        c16100 = CONS( _TSCP( 31506 ), c16100 );
        c16100 = CONS( _TSCP( 23826 ), c16100 );
        c16100 = CONS( _TSCP( 23314 ), c16100 );
        c16100 = CONS( _TSCP( 9234 ), c16100 );
        c16100 = CONS( _TSCP( 24082 ), c16100 );
        c16100 = CONS( _TSCP( 31762 ), c16100 );
        c16100 = CONS( _TSCP( 11026 ), c16100 );
        c16100 = CONS( _TSCP( 10770 ), c16100 );
        c16100 = CONS( _TSCP( 16146 ), c16100 );
        c16100 = CONS( _TSCP( 11794 ), c16100 );
        c16100 = CONS( _TSCP( 23570 ), c16100 );
        CONSTANTEXP( ADR( c16100 ) );
        c15766 = STRINGTOSYMBOL( CSTRING_TSCP( "PATTERN-MUST-BE-COMPILED-OR-\
STRING-REGEXP" ) );
        CONSTANTEXP( ADR( c15766 ) );
        c15765 = STRINGTOSYMBOL( CSTRING_TSCP( "PREGEXP-MATCH-POSITIONS" ) );
        CONSTANTEXP( ADR( c15765 ) );
        c15246 = STRINGTOSYMBOL( CSTRING_TSCP( "NON-EXISTENT-BACKREF" ) );
        CONSTANTEXP( ADR( c15246 ) );
        c15156 = EMPTYLIST;
        t16796 = STRINGTOSYMBOL( CSTRING_TSCP( ":ANY" ) );
        c15156 = CONS( t16796, c15156 );
        c15156 = CONS( FALSEVALUE, c15156 );
        c15156 = CONS( _TSCP( 0 ), c15156 );
        c15156 = CONS( FALSEVALUE, c15156 );
        t16797 = STRINGTOSYMBOL( CSTRING_TSCP( ":BETWEEN" ) );
        c15156 = CONS( t16797, c15156 );
        CONSTANTEXP( ADR( c15156 ) );
        c15053 = STRINGTOSYMBOL( CSTRING_TSCP( "GREEDY-QUANTIFIER-OPERAND-CO\
ULD-BE-EMPTY" ) );
        CONSTANTEXP( ADR( c15053 ) );
        c14976 = EMPTYLIST;
        t16798 = STRINGTOSYMBOL( CSTRING_TSCP( ":CASE-INSENSITIVE" ) );
        c14976 = CONS( t16798, c14976 );
        t16799 = STRINGTOSYMBOL( CSTRING_TSCP( ":CASE-SENSITIVE" ) );
        c14976 = CONS( t16799, c14976 );
        CONSTANTEXP( ADR( c14976 ) );
        c14975 = STRINGTOSYMBOL( CSTRING_TSCP( ":NO-BACKTRACK" ) );
        CONSTANTEXP( ADR( c14975 ) );
        c14971 = STRINGTOSYMBOL( CSTRING_TSCP( ":NEG-LOOKBEHIND" ) );
        CONSTANTEXP( ADR( c14971 ) );
        c14967 = STRINGTOSYMBOL( CSTRING_TSCP( ":LOOKBEHIND" ) );
        CONSTANTEXP( ADR( c14967 ) );
        c14963 = STRINGTOSYMBOL( CSTRING_TSCP( ":NEG-LOOKAHEAD" ) );
        CONSTANTEXP( ADR( c14963 ) );
        c14959 = STRINGTOSYMBOL( CSTRING_TSCP( ":LOOKAHEAD" ) );
        CONSTANTEXP( ADR( c14959 ) );
        c14932 = STRINGTOSYMBOL( CSTRING_TSCP( "PREGEXP-MATCH-POSITIONS-AUX" ) );
        CONSTANTEXP( ADR( c14932 ) );
        c14829 = STRINGTOSYMBOL( CSTRING_TSCP( ":SUB" ) );
        CONSTANTEXP( ADR( c14829 ) );
        c14537 = STRINGTOSYMBOL( CSTRING_TSCP( "PREGEXP-CHECK-IF-IN-CHAR-CLA\
SS?" ) );
        CONSTANTEXP( ADR( c14537 ) );
        c14536 = STRINGTOSYMBOL( CSTRING_TSCP( ":XDIGIT" ) );
        CONSTANTEXP( ADR( c14536 ) );
        c14529 = STRINGTOSYMBOL( CSTRING_TSCP( ":UPPER" ) );
        CONSTANTEXP( ADR( c14529 ) );
        c14522 = STRINGTOSYMBOL( CSTRING_TSCP( ":PUNCT" ) );
        CONSTANTEXP( ADR( c14522 ) );
        c14518 = STRINGTOSYMBOL( CSTRING_TSCP( ":PRINT" ) );
        CONSTANTEXP( ADR( c14518 ) );
        c14514 = STRINGTOSYMBOL( CSTRING_TSCP( ":LOWER" ) );
        CONSTANTEXP( ADR( c14514 ) );
        c14510 = STRINGTOSYMBOL( CSTRING_TSCP( ":GRAPH" ) );
        CONSTANTEXP( ADR( c14510 ) );
        c14503 = STRINGTOSYMBOL( CSTRING_TSCP( ":CNTRL" ) );
        CONSTANTEXP( ADR( c14503 ) );
        c14499 = STRINGTOSYMBOL( CSTRING_TSCP( ":BLANK" ) );
        CONSTANTEXP( ADR( c14499 ) );
        c14495 = STRINGTOSYMBOL( CSTRING_TSCP( ":ASCII" ) );
        CONSTANTEXP( ADR( c14495 ) );
        c14491 = STRINGTOSYMBOL( CSTRING_TSCP( ":ALPHA" ) );
        CONSTANTEXP( ADR( c14491 ) );
        c14487 = STRINGTOSYMBOL( CSTRING_TSCP( ":ALNUM" ) );
        CONSTANTEXP( ADR( c14487 ) );
        c14350 = STRINGTOSYMBOL( CSTRING_TSCP( "CHARACTER-CLASS-ENDED-TOO-SO\
ON" ) );
        CONSTANTEXP( ADR( c14350 ) );
        c14312 = STRINGTOSYMBOL( CSTRING_TSCP( ":ONE-OF-CHARS" ) );
        CONSTANTEXP( ADR( c14312 ) );
        c14290 = STRINGTOSYMBOL( CSTRING_TSCP( "PREGEXP-READ-CHAR-LIST" ) );
        CONSTANTEXP( ADR( c14290 ) );
        c14236 = STRINGTOSYMBOL( CSTRING_TSCP( ":CHAR-RANGE" ) );
        CONSTANTEXP( ADR( c14236 ) );
        c14059 = STRINGTOSYMBOL( CSTRING_TSCP( ":NONE-OF-CHARS" ) );
        CONSTANTEXP( ADR( c14059 ) );
        c13925 = STRINGTOSYMBOL( CSTRING_TSCP( "PREGEXP-READ-NUMS" ) );
        CONSTANTEXP( ADR( c13925 ) );
        c13857 = STRINGTOSYMBOL( CSTRING_TSCP( "AT-MOST" ) );
        CONSTANTEXP( ADR( c13857 ) );
        c13856 = STRINGTOSYMBOL( CSTRING_TSCP( "AT-LEAST" ) );
        CONSTANTEXP( ADR( c13856 ) );
        c13855 = STRINGTOSYMBOL( CSTRING_TSCP( "MINIMAL?" ) );
        CONSTANTEXP( ADR( c13855 ) );
        c13854 = STRINGTOSYMBOL( CSTRING_TSCP( ":BETWEEN" ) );
        CONSTANTEXP( ADR( c13854 ) );
        c13851 = STRINGTOSYMBOL( CSTRING_TSCP( "NEXT-I" ) );
        CONSTANTEXP( ADR( c13851 ) );
        c13626 = STRINGTOSYMBOL( CSTRING_TSCP( "SET-CAR!" ) );
        CONSTANTEXP( ADR( c13626 ) );
        c13620 = STRINGTOSYMBOL( CSTRING_TSCP( "LEFT-BRACE-MUST-BE-FOLLOWED-\
BY-NUMBER" ) );
        CONSTANTEXP( ADR( c13620 ) );
        c13619 = STRINGTOSYMBOL( CSTRING_TSCP( "PREGEXP-WRAP-QUANTIFIER-IF-A\
NY" ) );
        CONSTANTEXP( ADR( c13619 ) );
        c13595 = EMPTYLIST;
        c13595 = CONS( _TSCP( 31506 ), c13595 );
        c13595 = CONS( _TSCP( 16146 ), c13595 );
        c13595 = CONS( _TSCP( 11026 ), c13595 );
        c13595 = CONS( _TSCP( 10770 ), c13595 );
        CONSTANTEXP( ADR( c13595 ) );
        c13507 = STRINGTOSYMBOL( CSTRING_TSCP( "PREGEXP-READ-SUBPATTERN" ) );
        CONSTANTEXP( ADR( c13507 ) );
        c13378 = EMPTYLIST;
        c13378 = CONS( c14959, c13378 );
        CONSTANTEXP( ADR( c13378 ) );
        c13369 = EMPTYLIST;
        c13369 = CONS( c14963, c13369 );
        CONSTANTEXP( ADR( c13369 ) );
        c13360 = EMPTYLIST;
        c13360 = CONS( c14975, c13360 );
        CONSTANTEXP( ADR( c13360 ) );
        c13320 = EMPTYLIST;
        c13320 = CONS( c14967, c13320 );
        CONSTANTEXP( ADR( c13320 ) );
        c13319 = EMPTYLIST;
        c13319 = CONS( c14971, c13319 );
        CONSTANTEXP( ADR( c13319 ) );
        c13277 = STRINGTOSYMBOL( CSTRING_TSCP( ":CASE-SENSITIVE" ) );
        CONSTANTEXP( ADR( c13277 ) );
        c13276 = STRINGTOSYMBOL( CSTRING_TSCP( ":CASE-INSENSITIVE" ) );
        CONSTANTEXP( ADR( c13276 ) );
        c13254 = STRINGTOSYMBOL( CSTRING_TSCP( "PREGEXP-READ-CLUSTER-TYPE" ) );
        CONSTANTEXP( ADR( c13254 ) );
        c13201 = EMPTYLIST;
        c13201 = CONS( c14829, c13201 );
        CONSTANTEXP( ADR( c13201 ) );
        c13076 = STRINGTOSYMBOL( CSTRING_TSCP( "PREGEXP-READ-POSIX-CHAR-CLAS\
S" ) );
        CONSTANTEXP( ADR( c13076 ) );
        c13003 = STRINGTOSYMBOL( CSTRING_TSCP( ":WBDRY" ) );
        CONSTANTEXP( ADR( c13003 ) );
        c12994 = STRINGTOSYMBOL( CSTRING_TSCP( ":NOT-WBDRY" ) );
        CONSTANTEXP( ADR( c12994 ) );
        c12985 = STRINGTOSYMBOL( CSTRING_TSCP( ":DIGIT" ) );
        CONSTANTEXP( ADR( c12985 ) );
        c12976 = EMPTYLIST;
        c12976 = CONS( c12985, c12976 );
        t16800 = STRINGTOSYMBOL( CSTRING_TSCP( ":NEG-CHAR" ) );
        c12976 = CONS( t16800, c12976 );
        CONSTANTEXP( ADR( c12976 ) );
        c12951 = STRINGTOSYMBOL( CSTRING_TSCP( ":SPACE" ) );
        CONSTANTEXP( ADR( c12951 ) );
        c12942 = EMPTYLIST;
        c12942 = CONS( c12951, c12942 );
        c12942 = CONS( t16800, c12942 );
        CONSTANTEXP( ADR( c12942 ) );
        c12925 = STRINGTOSYMBOL( CSTRING_TSCP( ":WORD" ) );
        CONSTANTEXP( ADR( c12925 ) );
        c12916 = EMPTYLIST;
        c12916 = CONS( c12925, c12916 );
        c12916 = CONS( t16800, c12916 );
        CONSTANTEXP( ADR( c12916 ) );
        c12689 = STRINGTOSYMBOL( CSTRING_TSCP( ":BOS" ) );
        CONSTANTEXP( ADR( c12689 ) );
        c12680 = STRINGTOSYMBOL( CSTRING_TSCP( ":EOS" ) );
        CONSTANTEXP( ADR( c12680 ) );
        c12671 = STRINGTOSYMBOL( CSTRING_TSCP( ":ANY" ) );
        CONSTANTEXP( ADR( c12671 ) );
        c12606 = STRINGTOSYMBOL( CSTRING_TSCP( ":NEG-CHAR" ) );
        CONSTANTEXP( ADR( c12606 ) );
        c12572 = STRINGTOSYMBOL( CSTRING_TSCP( ":BACKREF" ) );
        CONSTANTEXP( ADR( c12572 ) );
        c12547 = STRINGTOSYMBOL( CSTRING_TSCP( "BACKSLASH" ) );
        CONSTANTEXP( ADR( c12547 ) );
        c12546 = STRINGTOSYMBOL( CSTRING_TSCP( "PREGEXP-READ-PIECE" ) );
        CONSTANTEXP( ADR( c12546 ) );
        c12481 = STRINGTOSYMBOL( CSTRING_TSCP( ":EMPTY" ) );
        CONSTANTEXP( ADR( c12481 ) );
        c12327 = STRINGTOSYMBOL( CSTRING_TSCP( ":SEQ" ) );
        CONSTANTEXP( ADR( c12327 ) );
        c12320 = STRINGTOSYMBOL( CSTRING_TSCP( ":OR" ) );
        CONSTANTEXP( ADR( c12320 ) );
        c12261 = CSTRING_TSCP( t16801 );
        CONSTANTEXP( ADR( c12261 ) );
        c12260 = CSTRING_TSCP( t16802 );
        CONSTANTEXP( ADR( c12260 ) );
        c12259 = STRINGTOSYMBOL( CSTRING_TSCP( "STRING-LENGTH" ) );
        CONSTANTEXP( ADR( c12259 ) );
        c12238 = CSTRING_TSCP( t16803 );
        CONSTANTEXP( ADR( c12238 ) );
        c12237 = STRINGTOSYMBOL( CSTRING_TSCP( "STRING-REF" ) );
        CONSTANTEXP( ADR( c12237 ) );
        c12231 = CSTRING_TSCP( t16804 );
        CONSTANTEXP( ADR( c12231 ) );
        c12230 = STRINGTOSYMBOL( CSTRING_TSCP( "CHAR=?" ) );
        CONSTANTEXP( ADR( c12230 ) );
        c12195 = CSTRING_TSCP( t16805 );
        CONSTANTEXP( ADR( c12195 ) );
        c12170 = CSTRING_TSCP( t16806 );
        CONSTANTEXP( ADR( c12170 ) );
        c12163 = CSTRING_TSCP( t16807 );
        CONSTANTEXP( ADR( c12163 ) );
        c12162 = STRINGTOSYMBOL( CSTRING_TSCP( "SET-CDR!" ) );
        CONSTANTEXP( ADR( c12162 ) );
        c12101 = CSTRING_TSCP( t16808 );
        CONSTANTEXP( ADR( c12101 ) );
        c12100 = STRINGTOSYMBOL( CSTRING_TSCP( "INTEGER->CHAR" ) );
        CONSTANTEXP( ADR( c12100 ) );
        c12071 = CSTRING_TSCP( t16809 );
        CONSTANTEXP( ADR( c12071 ) );
        c12070 = STRINGTOSYMBOL( CSTRING_TSCP( "CHAR->INTEGER" ) );
        CONSTANTEXP( ADR( c12070 ) );
}

DEFTSCP( pregexp_xp_2d1_2d0_d5be5fd9_v );
DEFCSTRING( t16810, "gensym-pregexp-1-0" );

TSCP  pregexp_xp_2d1_2d0_d5be5fd9(  )
{
        PUSHSTACKTRACE( t16810 );
        POPSTACKTRACE( 0 );}
  #include<stddef.h>
int gensym_pregexp_2_0(){ return 1;gensym_pregexp_2_0( );
}

DEFTSCP( pregexp_xp_2d3_2d0_af7e0cb9_v );
DEFCSTRING( t16812, "gensym-pregexp-3-0" );

TSCP  pregexp_xp_2d3_2d0_af7e0cb9(  )
{
        PUSHSTACKTRACE( t16812 );
        POPSTACKTRACE( 0 );}
  #include<stdlib.h>
int gensym_pregexp_4_0(){ return 1;gensym_pregexp_4_0( );
}

DEFTSCP( pregexp_xp_2d5_2d0_203ef919_v );
DEFCSTRING( t16814, "gensym-pregexp-5-0" );

TSCP  pregexp_xp_2d5_2d0_203ef919(  )
{
        PUSHSTACKTRACE( t16814 );
        POPSTACKTRACE( 0 );}
  #include<string.h>
int gensym_pregexp_6_0(){ return 1;gensym_pregexp_6_0( );
}

DEFTSCP( pregexp_version_2a_627fa14e_v );
DEFCSTRING( t16816, "*PREGEXP-VERSION*" );
DEFTSCP( pregexp__2dchar_2a_8489832_v );
DEFCSTRING( t16817, "*PREGEXP-COMMENT-CHAR*" );
DEFTSCP( pregexp_r_2dint_2a_a0f5bbd1_v );
DEFCSTRING( t16818, "*PREGEXP-NUL-CHAR-INT*" );
EXTERNTSCPP( scdebug_error, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scdebug_error_v );
EXTERNTSCPP( scrt2__2d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2d_2dtwo_v );
DEFTSCP( pregexp__2dchar_2a_2f258f12_v );
DEFCSTRING( t16825, "*PREGEXP-RETURN-CHAR*" );
EXTERNTSCPP( scrt2__2b_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2b_2dtwo_v );
EXTERNTSCPP( scrt2__3c_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3c_2dtwo_v );
EXTERNTSCPP( scrt2__3e_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3e_2dtwo_v );
DEFTSCP( pregexp__2dchar_2a_cd905c7c_v );
DEFCSTRING( t16851, "*PREGEXP-TAB-CHAR*" );
DEFTSCP( pregexp_tive_3f_2a_bd6b8339_v );
DEFCSTRING( t16877, "*PREGEXP-SPACE-SENSITIVE?*" );
DEFTSCP( pregexp_pregexp_2dreverse_21_v );
DEFCSTRING( t16878, "PREGEXP-REVERSE!" );
EXTERNTSCPP( scrt1__24__cdr_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__cdr_2derror_v );

TSCP  pregexp_pregexp_2dreverse_21( s12141 )
        TSCP  s12141;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t16878 );
        X1 = s12141;
        X2 = EMPTYLIST;
L16881:
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( EMPTYLIST ) ) )  goto L16882;
        if  ( EQ( TSCPTAG( X1 ), PAIRTAG ) )  goto L16885;
        scrt1__24__cdr_2derror( X1 );
L16885:
        X3 = PAIR_CDR( X1 );
        SETGEN( PAIR_CDR( X1 ), X2 );
        X2 = X1;
        X1 = X3;
        GOBACK( L16881 );
L16882:
        POPSTACKTRACE( X2 );
}

DEFTSCP( pregexp_pregexp_2derror_v );
DEFCSTRING( t16889, "PREGEXP-ERROR" );
EXTERNTSCPP( scrt6_display, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt6_display_v );
EXTERNTSCPP( scrt1__24__car_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__car_2derror_v );
EXTERNTSCPP( scrt6_write, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt6_write_v );
EXTERNTSCPP( scrt6_newline, XAL1( TSCP ) );
EXTERNTSCP( scrt6_newline_v );
EXTERNTSCPP( qobischeme_panic, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_panic_v );

TSCP  pregexp_pregexp_2derror( w12169 )
        TSCP  w12169;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t16889 );
        scrt6_display( c12170, EMPTYLIST );
        X1 = w12169;
L16892:
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( EMPTYLIST ) ) )  goto L16893;
        if  ( EQ( TSCPTAG( X1 ), PAIRTAG ) )  goto L16897;
        scrt1__24__car_2derror( X1 );
L16897:
        X2 = PAIR_CAR( X1 );
        scrt6_display( _TSCP( 8210 ), EMPTYLIST );
        scrt6_write( X2, EMPTYLIST );
        X1 = PAIR_CDR( X1 );
        GOBACK( L16892 );
L16893:
        scrt6_newline( EMPTYLIST );
        POPSTACKTRACE( qobischeme_panic( c12195, EMPTYLIST ) );
}

DEFTSCP( pregexp__2dpattern_829cfa27_v );
DEFCSTRING( t16901, "PREGEXP-READ-PATTERN" );
EXTERNTSCPP( scrt2__3e_3d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3e_3d_2dtwo_v );
EXTERNTSCPP( sc_cons, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_cons_v );
EXTERNTSCPP( pregexp_d_2dbranch_201e770d, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( pregexp_d_2dbranch_201e770d_v );

TSCP  pregexp__2dpattern_829cfa27( s12197, i12198, n12199 )
        TSCP  s12197, i12198, n12199;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t16901 );
        if  ( BITAND( BITOR( _S2CINT( i12198 ), 
                             _S2CINT( n12199 ) ), 
                      3 ) )  goto L16904;
        if  ( GTE( _S2CINT( i12198 ), _S2CINT( n12199 ) ) )  goto L16908;
        goto L16909;
L16904:
        if  ( FALSE( scrt2__3e_3d_2dtwo( i12198, n12199 ) ) )  goto L16909;
L16908:
        X8 = sc_cons( c12327, EMPTYLIST );
        X7 = X8;
        X6 = sc_cons( X7, EMPTYLIST );
        X5 = sc_cons( c12320, X6 );
        X4 = X5;
        X5 = sc_cons( i12198, EMPTYLIST );
        X3 = sc_cons( X4, X5 );
        POPSTACKTRACE( X3 );
L16909:
        X2 = EMPTYLIST;
        X1 = i12198;
L16916:
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( n12199 ) ), 
                      3 ) )  goto L16917;
        X3 = BOOLEAN( GTE( _S2CINT( X1 ), 
                           _S2CINT( n12199 ) ) );
        goto L16918;
L16917:
        X3 = scrt2__3e_3d_2dtwo( X1, n12199 );
L16918:
        if  ( TRUE( X3 ) )  goto L16923;
        if  ( EQ( TSCPTAG( X1 ), FIXNUMTAG ) )  goto L16925;
        scdebug_error( c12237, 
                       c12238, CONS( X1, EMPTYLIST ) );
L16925:
        X5 = BOOLEAN( LT( _S2CINT( X1 ), 0 ) );
        if  ( TRUE( X5 ) )  goto L16931;
        if  ( AND( EQ( TSCPTAG( s12197 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12197 ), STRINGTAG ) )
            )  goto L16933;
        scdebug_error( c12259, 
                       c12260, CONS( s12197, EMPTYLIST ) );
L16933:
        X6 = C_FIXED( STRING_LENGTH( s12197 ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L16937;
        if  ( GTE( _S2CINT( X1 ), _S2CINT( X6 ) ) )  goto L16931;
        goto L16944;
L16937:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X1, X6 ) ) )  goto L16944;
L16931:
        scdebug_error( c12237, 
                       c12261, CONS( X1, EMPTYLIST ) );
L16944:
        X4 = C_CHAR( STRING_CHAR( s12197, X1 ) );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X4 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 10514 ) ), 
                       CHARACTERTAG ) ) )  goto L16946;
        X5 = CONS( _TSCP( 10514 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X4, X5 ) );
L16946:
        if  ( EQ( _S2CINT( X4 ), _S2CINT( _TSCP( 10514 ) ) ) )  goto L16923;
        X8 = BOOLEAN( LT( _S2CINT( X1 ), 0 ) );
        if  ( TRUE( X8 ) )  goto L16955;
        if  ( AND( EQ( TSCPTAG( s12197 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12197 ), STRINGTAG ) )
            )  goto L16957;
        scdebug_error( c12259, 
                       c12260, CONS( s12197, EMPTYLIST ) );
L16957:
        X9 = C_FIXED( STRING_LENGTH( s12197 ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X9 ) ), 
                      3 ) )  goto L16961;
        if  ( GTE( _S2CINT( X1 ), _S2CINT( X9 ) ) )  goto L16955;
        goto L16968;
L16961:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X1, X9 ) ) )  goto L16968;
L16955:
        scdebug_error( c12237, 
                       c12261, CONS( X1, EMPTYLIST ) );
L16968:
        X7 = C_CHAR( STRING_CHAR( s12197, X1 ) );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X7 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 31762 ) ), 
                       CHARACTERTAG ) ) )  goto L16970;
        X8 = CONS( _TSCP( 31762 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X7, X8 ) );
L16970:
        if  ( NEQ( _S2CINT( X7 ), 
                   _S2CINT( _TSCP( 31762 ) ) ) )  goto L16972;
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16974;
        X6 = _TSCP( IPLUS( _S2CINT( X1 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L16973;
L16974:
        X6 = scrt2__2b_2dtwo( X1, _TSCP( 4 ) );
        goto L16973;
L16972:
        X6 = X1;
L16973:
        X5 = pregexp_d_2dbranch_201e770d( s12197, X6, n12199 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L16978;
        scrt1__24__car_2derror( X5 );
L16978:
        X7 = PAIR_CAR( X5 );
        X6 = sc_cons( X7, X2 );
        X7 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L16982;
        scrt1__24__car_2derror( X7 );
L16982:
        X1 = PAIR_CAR( X7 );
        X2 = X6;
        GOBACK( L16916 );
L16923:
        X5 = pregexp_pregexp_2dreverse_21( X2 );
        X4 = sc_cons( c12320, X5 );
        X5 = sc_cons( X1, EMPTYLIST );
        X3 = sc_cons( X4, X5 );
        POPSTACKTRACE( X3 );
}

DEFTSCP( pregexp_d_2dbranch_201e770d_v );
DEFCSTRING( t16985, "PREGEXP-READ-BRANCH" );
EXTERNTSCPP( pregexp_ad_2dpiece_b70ed9c5, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( pregexp_ad_2dpiece_b70ed9c5_v );

TSCP  pregexp_d_2dbranch_201e770d( s12329, i12330, n12331 )
        TSCP  s12329, i12330, n12331;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t16985 );
        X1 = EMPTYLIST;
        X2 = i12330;
L16988:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( n12331 ) ), 
                      3 ) )  goto L16990;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( n12331 ) ) )  goto L16994;
        goto L16995;
L16990:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X2, n12331 ) ) )  goto L16994;
L16995:
        if  ( EQ( TSCPTAG( X2 ), FIXNUMTAG ) )  goto L16999;
        scdebug_error( c12237, 
                       c12238, CONS( X2, EMPTYLIST ) );
L16999:
        X4 = BOOLEAN( LT( _S2CINT( X2 ), 0 ) );
        if  ( TRUE( X4 ) )  goto L17005;
        if  ( AND( EQ( TSCPTAG( s12329 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12329 ), STRINGTAG ) )
            )  goto L17007;
        scdebug_error( c12259, 
                       c12260, CONS( s12329, EMPTYLIST ) );
L17007:
        X5 = C_FIXED( STRING_LENGTH( s12329 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X5 ) ), 
                      3 ) )  goto L17011;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X5 ) ) )  goto L17005;
        goto L17018;
L17011:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X2, X5 ) ) )  goto L17018;
L17005:
        scdebug_error( c12237, 
                       c12261, CONS( X2, EMPTYLIST ) );
L17018:
        X3 = C_CHAR( STRING_CHAR( s12329, X2 ) );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X3 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 31762 ) ), 
                       CHARACTERTAG ) ) )  goto L17021;
        X5 = CONS( _TSCP( 31762 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X3, X5 ) );
L17021:
        X4 = BOOLEAN( EQ( _S2CINT( X3 ), 
                          _S2CINT( _TSCP( 31762 ) ) ) );
        if  ( TRUE( X4 ) )  goto L17027;
        if  ( AND( EQ( TSCPIMMEDIATETAG( X3 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 10514 ) ), 
                       CHARACTERTAG ) ) )  goto L17029;
        X5 = CONS( _TSCP( 10514 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X3, X5 ) );
L17029:
        if  ( EQ( _S2CINT( X3 ), _S2CINT( _TSCP( 10514 ) ) ) )  goto L17027;
        X5 = pregexp_ad_2dpiece_b70ed9c5( s12329, X2, n12331 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L17035;
        scrt1__24__car_2derror( X5 );
L17035:
        X7 = PAIR_CAR( X5 );
        X6 = sc_cons( X7, X1 );
        X7 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L17039;
        scrt1__24__car_2derror( X7 );
L17039:
        X2 = PAIR_CAR( X7 );
        X1 = X6;
        GOBACK( L16988 );
L17027:
        X5 = pregexp_pregexp_2dreverse_21( X1 );
        X4 = sc_cons( c12327, X5 );
        X5 = sc_cons( X2, EMPTYLIST );
        X3 = sc_cons( X4, X5 );
        POPSTACKTRACE( X3 );
L16994:
        X5 = pregexp_pregexp_2dreverse_21( X1 );
        X4 = sc_cons( c12327, X5 );
        X5 = sc_cons( X2, EMPTYLIST );
        X3 = sc_cons( X4, X5 );
        POPSTACKTRACE( X3 );
}

DEFTSCP( pregexp_ad_2dpiece_b70ed9c5_v );
DEFCSTRING( t17043, "PREGEXP-READ-PIECE" );
EXTERNTSCPP( pregexp_2dif_2dany_74203067, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( pregexp_2dif_2dany_74203067_v );
EXTERNTSCPP( pregexp_har_2dlist_9cba0ef7, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( pregexp_har_2dlist_9cba0ef7_v );
EXTERNTSCPP( pregexp_subpattern_ac026cd3, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( pregexp_subpattern_ac026cd3_v );
EXTERNTSCPP( pregexp_d_2dnumber_1f1ad78b, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( pregexp_d_2dnumber_1f1ad78b_v );
EXTERNTSCPP( pregexp_ped_2dchar_b91fbb8c, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( pregexp_ped_2dchar_b91fbb8c_v );
EXTERNTSCPP( scrt3_char_2dwhitespace_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt3_char_2dwhitespace_3f_v );

TSCP  pregexp_ad_2dpiece_b70ed9c5( s12412, i12413, n12414 )
        TSCP  s12412, i12413, n12414;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t17043 );
        if  ( EQ( TSCPTAG( i12413 ), FIXNUMTAG ) )  goto L17046;
        scdebug_error( c12237, 
                       c12238, CONS( i12413, EMPTYLIST ) );
L17046:
        X2 = BOOLEAN( LT( _S2CINT( i12413 ), 0 ) );
        if  ( TRUE( X2 ) )  goto L17052;
        if  ( AND( EQ( TSCPTAG( s12412 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12412 ), STRINGTAG ) )
            )  goto L17054;
        scdebug_error( c12259, 
                       c12260, CONS( s12412, EMPTYLIST ) );
L17054:
        X3 = C_FIXED( STRING_LENGTH( s12412 ) );
        if  ( BITAND( BITOR( _S2CINT( i12413 ), 
                             _S2CINT( X3 ) ), 
                      3 ) )  goto L17058;
        if  ( GTE( _S2CINT( i12413 ), _S2CINT( X3 ) ) )  goto L17052;
        goto L17065;
L17058:
        if  ( FALSE( scrt2__3e_3d_2dtwo( i12413, X3 ) ) )  goto L17065;
L17052:
        scdebug_error( c12237, 
                       c12261, CONS( i12413, EMPTYLIST ) );
L17065:
        X1 = C_CHAR( STRING_CHAR( s12412, i12413 ) );
        if  ( NEQ( _S2CUINT( X1 ), 
                   _S2CUINT( _TSCP( 24082 ) ) ) )  goto L17067;
        if  ( BITAND( BITOR( _S2CINT( i12413 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17069;
        X4 = _TSCP( IPLUS( _S2CINT( i12413 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17070;
L17069:
        X4 = scrt2__2b_2dtwo( i12413, _TSCP( 4 ) );
L17070:
        X3 = sc_cons( X4, EMPTYLIST );
        X2 = sc_cons( c12689, X3 );
        POPSTACKTRACE( X2 );
L17067:
        if  ( NEQ( _S2CUINT( X1 ), 
                   _S2CUINT( _TSCP( 9234 ) ) ) )  goto L17072;
        if  ( BITAND( BITOR( _S2CINT( i12413 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17074;
        X4 = _TSCP( IPLUS( _S2CINT( i12413 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17075;
L17074:
        X4 = scrt2__2b_2dtwo( i12413, _TSCP( 4 ) );
L17075:
        X3 = sc_cons( X4, EMPTYLIST );
        X2 = sc_cons( c12680, X3 );
        POPSTACKTRACE( X2 );
L17072:
        if  ( NEQ( _S2CUINT( X1 ), 
                   _S2CUINT( _TSCP( 11794 ) ) ) )  goto L17077;
        if  ( BITAND( BITOR( _S2CINT( i12413 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17079;
        X5 = _TSCP( IPLUS( _S2CINT( i12413 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17080;
L17079:
        X5 = scrt2__2b_2dtwo( i12413, _TSCP( 4 ) );
L17080:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c12671, X4 );
        X2 = X3;
        POPSTACKTRACE( pregexp_2dif_2dany_74203067( X2, 
                                                    s12412, n12414 ) );
L17077:
        if  ( NEQ( _S2CUINT( X1 ), 
                   _S2CUINT( _TSCP( 23314 ) ) ) )  goto L17082;
        if  ( BITAND( BITOR( _S2CINT( i12413 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17084;
        X2 = _TSCP( IPLUS( _S2CINT( i12413 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17085;
L17084:
        X2 = scrt2__2b_2dtwo( i12413, _TSCP( 4 ) );
L17085:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( n12414 ) ), 
                      3 ) )  goto L17089;
        X5 = BOOLEAN( LT( _S2CINT( X2 ), _S2CINT( n12414 ) ) );
        goto L17090;
L17089:
        X5 = scrt2__3c_2dtwo( X2, n12414 );
L17090:
        if  ( FALSE( X5 ) )  goto L17092;
        if  ( EQ( TSCPTAG( X2 ), FIXNUMTAG ) )  goto L17095;
        scdebug_error( c12237, 
                       c12238, CONS( X2, EMPTYLIST ) );
L17095:
        X6 = BOOLEAN( LT( _S2CINT( X2 ), 0 ) );
        if  ( TRUE( X6 ) )  goto L17101;
        if  ( AND( EQ( TSCPTAG( s12412 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12412 ), STRINGTAG ) )
            )  goto L17103;
        scdebug_error( c12259, 
                       c12260, CONS( s12412, EMPTYLIST ) );
L17103:
        X7 = C_FIXED( STRING_LENGTH( s12412 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X7 ) ), 
                      3 ) )  goto L17107;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X7 ) ) )  goto L17101;
        goto L17114;
L17107:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X2, X7 ) ) )  goto L17114;
L17101:
        scdebug_error( c12237, 
                       c12261, CONS( X2, EMPTYLIST ) );
L17114:
        X4 = C_CHAR( STRING_CHAR( s12412, X2 ) );
        goto L17093;
L17092:
        X4 = X5;
L17093:
        if  ( NEQ( _S2CUINT( X4 ), 
                   _S2CUINT( _TSCP( 24082 ) ) ) )  goto L17087;
        if  ( BITAND( BITOR( _S2CINT( i12413 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17115;
        X5 = _TSCP( IPLUS( _S2CINT( i12413 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17116;
L17115:
        X5 = scrt2__2b_2dtwo( i12413, _TSCP( 8 ) );
L17116:
        X4 = pregexp_har_2dlist_9cba0ef7( s12412, X5, n12414 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L17119;
        scrt1__24__car_2derror( X4 );
L17119:
        X9 = PAIR_CAR( X4 );
        X8 = sc_cons( X9, EMPTYLIST );
        X7 = sc_cons( c12606, X8 );
        X6 = X7;
        X9 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X9 ), PAIRTAG ) )  goto L17124;
        scrt1__24__car_2derror( X9 );
L17124:
        X8 = PAIR_CAR( X9 );
        X7 = sc_cons( X8, EMPTYLIST );
        X5 = sc_cons( X6, X7 );
        X3 = X5;
        goto L17088;
L17087:
        X3 = pregexp_har_2dlist_9cba0ef7( s12412, X2, n12414 );
L17088:
        POPSTACKTRACE( pregexp_2dif_2dany_74203067( X3, 
                                                    s12412, n12414 ) );
L17082:
        if  ( NEQ( _S2CUINT( X1 ), 
                   _S2CUINT( _TSCP( 10258 ) ) ) )  goto L17127;
        if  ( BITAND( BITOR( _S2CINT( i12413 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17129;
        X3 = _TSCP( IPLUS( _S2CINT( i12413 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17130;
L17129:
        X3 = scrt2__2b_2dtwo( i12413, _TSCP( 4 ) );
L17130:
        X2 = pregexp_subpattern_ac026cd3( s12412, X3, n12414 );
        POPSTACKTRACE( pregexp_2dif_2dany_74203067( X2, 
                                                    s12412, n12414 ) );
L17127:
        if  ( NEQ( _S2CUINT( X1 ), 
                   _S2CUINT( _TSCP( 23570 ) ) ) )  goto L17131;
        X3 = pregexp_d_2dnumber_1f1ad78b( s12412, i12413, n12414 );
        if  ( FALSE( X3 ) )  goto L17134;
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L17137;
        scrt1__24__car_2derror( X3 );
L17137:
        X8 = PAIR_CAR( X3 );
        X7 = sc_cons( X8, EMPTYLIST );
        X6 = sc_cons( c12572, X7 );
        X5 = X6;
        X8 = PAIR_CDR( X3 );
        if  ( EQ( TSCPTAG( X8 ), PAIRTAG ) )  goto L17142;
        scrt1__24__car_2derror( X8 );
L17142:
        X7 = PAIR_CAR( X8 );
        X6 = sc_cons( X7, EMPTYLIST );
        X4 = sc_cons( X5, X6 );
        X2 = X4;
        goto L17147;
L17134:
        X4 = pregexp_ped_2dchar_b91fbb8c( s12412, i12413, n12414 );
        if  ( FALSE( X4 ) )  goto L17146;
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L17149;
        scrt1__24__car_2derror( X4 );
L17149:
        X6 = PAIR_CAR( X4 );
        X9 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X9 ), PAIRTAG ) )  goto L17153;
        scrt1__24__car_2derror( X9 );
L17153:
        X8 = PAIR_CAR( X9 );
        X7 = sc_cons( X8, EMPTYLIST );
        X5 = sc_cons( X6, X7 );
        X2 = X5;
        goto L17147;
L17146:
        X5 = CONS( c12547, EMPTYLIST );
        X2 = pregexp_pregexp_2derror( CONS( c12546, X5 ) );
L17147:
        POPSTACKTRACE( pregexp_2dif_2dany_74203067( X2, 
                                                    s12412, n12414 ) );
L17131:
        X2 = pregexp_tive_3f_2a_bd6b8339_v;
        if  ( TRUE( X2 ) )  goto L17160;
        if  ( FALSE( scrt3_char_2dwhitespace_3f( X1 ) ) )  goto L17161;
        X3 = FALSEVALUE;
        goto L17162;
L17161:
        X3 = TRUEVALUE;
L17162:
        if  ( FALSE( X3 ) )  goto L17172;
        X4 = pregexp__2dchar_2a_8489832_v;
        if  ( AND( EQ( TSCPIMMEDIATETAG( X1 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( X4 ), CHARACTERTAG ) )
            )  goto L17168;
        X5 = CONS( X4, EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X1, X5 ) );
L17168:
        if  ( EQ( _S2CINT( X1 ), _S2CINT( X4 ) ) )  goto L17172;
L17160:
        if  ( BITAND( BITOR( _S2CINT( i12413 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17173;
        X5 = _TSCP( IPLUS( _S2CINT( i12413 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17174;
L17173:
        X5 = scrt2__2b_2dtwo( i12413, _TSCP( 4 ) );
L17174:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( X1, X4 );
        X2 = X3;
        POPSTACKTRACE( pregexp_2dif_2dany_74203067( X2, 
                                                    s12412, n12414 ) );
L17172:
        X2 = i12413;
        X3 = FALSEVALUE;
L17177:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( n12414 ) ), 
                      3 ) )  goto L17179;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( n12414 ) ) )  goto L17183;
        goto L17184;
L17179:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X2, n12414 ) ) )  goto L17183;
L17184:
        if  ( EQ( TSCPTAG( X2 ), FIXNUMTAG ) )  goto L17188;
        scdebug_error( c12237, 
                       c12238, CONS( X2, EMPTYLIST ) );
L17188:
        X5 = BOOLEAN( LT( _S2CINT( X2 ), 0 ) );
        if  ( TRUE( X5 ) )  goto L17194;
        if  ( AND( EQ( TSCPTAG( s12412 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12412 ), STRINGTAG ) )
            )  goto L17196;
        scdebug_error( c12259, 
                       c12260, CONS( s12412, EMPTYLIST ) );
L17196:
        X6 = C_FIXED( STRING_LENGTH( s12412 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L17200;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X6 ) ) )  goto L17194;
        goto L17207;
L17200:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X2, X6 ) ) )  goto L17207;
L17194:
        scdebug_error( c12237, 
                       c12261, CONS( X2, EMPTYLIST ) );
L17207:
        X4 = C_CHAR( STRING_CHAR( s12412, X2 ) );
        if  ( FALSE( X3 ) )  goto L17209;
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17211;
        X5 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17212;
L17211:
        X5 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L17212:
        if  ( AND( EQ( TSCPIMMEDIATETAG( X4 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 2578 ) ), 
                       CHARACTERTAG ) ) )  goto L17214;
        X6 = CONS( _TSCP( 2578 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X4, X6 ) );
L17214:
        X3 = BOOLEAN( NEQ( _S2CINT( X4 ), 
                           _S2CINT( _TSCP( 2578 ) ) ) );
        X2 = X5;
        GOBACK( L17177 );
L17209:
        if  ( FALSE( scrt3_char_2dwhitespace_3f( X4 ) ) )  goto L17216;
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17218;
        X5 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17219;
L17218:
        X5 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L17219:
        X3 = FALSEVALUE;
        X2 = X5;
        GOBACK( L17177 );
L17216:
        X5 = pregexp__2dchar_2a_8489832_v;
        if  ( AND( EQ( TSCPIMMEDIATETAG( X4 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( X5 ), CHARACTERTAG ) )
            )  goto L17221;
        X6 = CONS( X5, EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X4, X6 ) );
L17221:
        if  ( NEQ( _S2CINT( X4 ), _S2CINT( X5 ) ) )  goto L17223;
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17225;
        X6 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17226;
L17225:
        X6 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L17226:
        X3 = TRUEVALUE;
        X2 = X6;
        GOBACK( L17177 );
L17223:
        X7 = sc_cons( X2, EMPTYLIST );
        X6 = sc_cons( c12481, X7 );
        POPSTACKTRACE( X6 );
L17183:
        X5 = sc_cons( X2, EMPTYLIST );
        X4 = sc_cons( c12481, X5 );
        POPSTACKTRACE( X4 );
}

DEFTSCP( pregexp_d_2dnumber_1f1ad78b_v );
DEFCSTRING( t17229, "PREGEXP-READ-ESCAPED-NUMBER" );
EXTERNTSCPP( scrt3_char_2dnumeric_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt3_char_2dnumeric_3f_v );
EXTERNTSCPP( scrt2_string_2d_3enumber, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_string_2d_3enumber_v );
EXTERNTSCPP( scrt3_list_2d_3estring, XAL1( TSCP ) );
EXTERNTSCP( scrt3_list_2d_3estring_v );

TSCP  pregexp_d_2dnumber_1f1ad78b( s12722, i12723, n12724 )
        TSCP  s12722, i12723, n12724;
{
        TSCP  X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t17229 );
        if  ( BITAND( BITOR( _S2CINT( i12723 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17231;
        X2 = _TSCP( IPLUS( _S2CINT( i12723 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17232;
L17231:
        X2 = scrt2__2b_2dtwo( i12723, _TSCP( 4 ) );
L17232:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( n12724 ) ), 
                      3 ) )  goto L17234;
        X1 = BOOLEAN( LT( _S2CINT( X2 ), _S2CINT( n12724 ) ) );
        goto L17235;
L17234:
        X1 = scrt2__3c_2dtwo( X2, n12724 );
L17235:
        if  ( FALSE( X1 ) )  goto L17237;
        if  ( BITAND( BITOR( _S2CINT( i12723 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17239;
        X3 = _TSCP( IPLUS( _S2CINT( i12723 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17240;
L17239:
        X3 = scrt2__2b_2dtwo( i12723, _TSCP( 4 ) );
L17240:
        if  ( EQ( TSCPTAG( X3 ), FIXNUMTAG ) )  goto L17242;
        scdebug_error( c12237, 
                       c12238, CONS( X3, EMPTYLIST ) );
L17242:
        X4 = BOOLEAN( LT( _S2CINT( X3 ), 0 ) );
        if  ( TRUE( X4 ) )  goto L17248;
        if  ( AND( EQ( TSCPTAG( s12722 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12722 ), STRINGTAG ) )
            )  goto L17250;
        scdebug_error( c12259, 
                       c12260, CONS( s12722, EMPTYLIST ) );
L17250:
        X5 = C_FIXED( STRING_LENGTH( s12722 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X5 ) ), 
                      3 ) )  goto L17254;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( X5 ) ) )  goto L17248;
        goto L17261;
L17254:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X3, X5 ) ) )  goto L17261;
L17248:
        scdebug_error( c12237, 
                       c12261, CONS( X3, EMPTYLIST ) );
L17261:
        X2 = C_CHAR( STRING_CHAR( s12722, X3 ) );
        X3 = scrt3_char_2dnumeric_3f( X2 );
        if  ( FALSE( X3 ) )  goto L17264;
        X5 = sc_cons( X2, EMPTYLIST );
        X4 = X5;
        if  ( BITAND( BITOR( _S2CINT( i12723 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17267;
        X5 = _TSCP( IPLUS( _S2CINT( i12723 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17268;
L17267:
        X5 = scrt2__2b_2dtwo( i12723, _TSCP( 8 ) );
L17268:
        X6 = X5;
        X7 = X4;
L17271:
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( n12724 ) ), 
                      3 ) )  goto L17273;
        if  ( GTE( _S2CINT( X6 ), _S2CINT( n12724 ) ) )  goto L17277;
        goto L17278;
L17273:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X6, n12724 ) ) )  goto L17278;
L17277:
        X11 = pregexp_pregexp_2dreverse_21( X7 );
        X10 = scrt3_list_2d_3estring( X11 );
        X9 = scrt2_string_2d_3enumber( X10, EMPTYLIST );
        X10 = sc_cons( X6, EMPTYLIST );
        X8 = sc_cons( X9, X10 );
        POPSTACKTRACE( X8 );
L17278:
        if  ( EQ( TSCPTAG( X6 ), FIXNUMTAG ) )  goto L17283;
        scdebug_error( c12237, 
                       c12238, CONS( X6, EMPTYLIST ) );
L17283:
        X9 = BOOLEAN( LT( _S2CINT( X6 ), 0 ) );
        if  ( TRUE( X9 ) )  goto L17289;
        if  ( AND( EQ( TSCPTAG( s12722 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12722 ), STRINGTAG ) )
            )  goto L17291;
        scdebug_error( c12259, 
                       c12260, CONS( s12722, EMPTYLIST ) );
L17291:
        X10 = C_FIXED( STRING_LENGTH( s12722 ) );
        if  ( BITAND( BITOR( _S2CINT( X6 ), _S2CINT( X10 ) ), 
                      3 ) )  goto L17295;
        if  ( GTE( _S2CINT( X6 ), _S2CINT( X10 ) ) )  goto L17289;
        goto L17302;
L17295:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X6, X10 ) ) )  goto L17302;
L17289:
        scdebug_error( c12237, 
                       c12261, CONS( X6, EMPTYLIST ) );
L17302:
        X8 = C_CHAR( STRING_CHAR( s12722, X6 ) );
        if  ( FALSE( scrt3_char_2dnumeric_3f( X8 ) ) )  goto L17304;
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17306;
        X9 = _TSCP( IPLUS( _S2CINT( X6 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17307;
L17306:
        X9 = scrt2__2b_2dtwo( X6, _TSCP( 4 ) );
L17307:
        X7 = sc_cons( X8, X7 );
        X6 = X9;
        GOBACK( L17271 );
L17304:
        X12 = pregexp_pregexp_2dreverse_21( X7 );
        X11 = scrt3_list_2d_3estring( X12 );
        X10 = scrt2_string_2d_3enumber( X11, EMPTYLIST );
        X11 = sc_cons( X6, EMPTYLIST );
        X9 = sc_cons( X10, X11 );
        POPSTACKTRACE( X9 );
L17264:
        POPSTACKTRACE( X3 );
L17237:
        POPSTACKTRACE( X1 );
}

DEFTSCP( pregexp_ped_2dchar_b91fbb8c_v );
DEFCSTRING( t17309, "PREGEXP-READ-ESCAPED-CHAR" );

TSCP  pregexp_ped_2dchar_b91fbb8c( s12839, i12840, n12841 )
        TSCP  s12839, i12840, n12841;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t17309 );
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17311;
        X2 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17312;
L17311:
        X2 = scrt2__2b_2dtwo( i12840, _TSCP( 4 ) );
L17312:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( n12841 ) ), 
                      3 ) )  goto L17314;
        X1 = BOOLEAN( LT( _S2CINT( X2 ), _S2CINT( n12841 ) ) );
        goto L17315;
L17314:
        X1 = scrt2__3c_2dtwo( X2, n12841 );
L17315:
        if  ( FALSE( X1 ) )  goto L17317;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17319;
        X3 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17320;
L17319:
        X3 = scrt2__2b_2dtwo( i12840, _TSCP( 4 ) );
L17320:
        if  ( EQ( TSCPTAG( X3 ), FIXNUMTAG ) )  goto L17322;
        scdebug_error( c12237, 
                       c12238, CONS( X3, EMPTYLIST ) );
L17322:
        X4 = BOOLEAN( LT( _S2CINT( X3 ), 0 ) );
        if  ( TRUE( X4 ) )  goto L17328;
        if  ( AND( EQ( TSCPTAG( s12839 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12839 ), STRINGTAG ) )
            )  goto L17330;
        scdebug_error( c12259, 
                       c12260, CONS( s12839, EMPTYLIST ) );
L17330:
        X5 = C_FIXED( STRING_LENGTH( s12839 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X5 ) ), 
                      3 ) )  goto L17334;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( X5 ) ) )  goto L17328;
        goto L17341;
L17334:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X3, X5 ) ) )  goto L17341;
L17328:
        scdebug_error( c12237, 
                       c12261, CONS( X3, EMPTYLIST ) );
L17341:
        X2 = C_CHAR( STRING_CHAR( s12839, X3 ) );
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 25106 ) ) ) )  goto L17343;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17345;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17346;
L17345:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17346:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c13003, X4 );
        POPSTACKTRACE( X3 );
L17343:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 16914 ) ) ) )  goto L17348;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17350;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17351;
L17350:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17351:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c12994, X4 );
        POPSTACKTRACE( X3 );
L17348:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 25618 ) ) ) )  goto L17353;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17355;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17356;
L17355:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17356:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c12985, X4 );
        POPSTACKTRACE( X3 );
L17353:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 17426 ) ) ) )  goto L17358;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17360;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17361;
L17360:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17361:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c12976, X4 );
        POPSTACKTRACE( X3 );
L17358:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 28178 ) ) ) )  goto L17363;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17365;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17366;
L17365:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17366:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( _TSCP( 2578 ), X4 );
        POPSTACKTRACE( X3 );
L17363:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 29202 ) ) ) )  goto L17368;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17370;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17371;
L17370:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17371:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( pregexp__2dchar_2a_2f258f12_v, X4 );
        POPSTACKTRACE( X3 );
L17368:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 29458 ) ) ) )  goto L17373;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17375;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17376;
L17375:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17376:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c12951, X4 );
        POPSTACKTRACE( X3 );
L17373:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 21266 ) ) ) )  goto L17378;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17380;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17381;
L17380:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17381:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c12942, X4 );
        POPSTACKTRACE( X3 );
L17378:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 29714 ) ) ) )  goto L17383;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17385;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17386;
L17385:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17386:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( pregexp__2dchar_2a_cd905c7c_v, X4 );
        POPSTACKTRACE( X3 );
L17383:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 30482 ) ) ) )  goto L17388;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17390;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17391;
L17390:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17391:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c12925, X4 );
        POPSTACKTRACE( X3 );
L17388:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 22290 ) ) ) )  goto L17393;
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17395;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17396;
L17395:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17396:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c12916, X4 );
        POPSTACKTRACE( X3 );
L17393:
        if  ( BITAND( BITOR( _S2CINT( i12840 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17398;
        X5 = _TSCP( IPLUS( _S2CINT( i12840 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17399;
L17398:
        X5 = scrt2__2b_2dtwo( i12840, _TSCP( 8 ) );
L17399:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( X2, X4 );
        POPSTACKTRACE( X3 );
L17317:
        POPSTACKTRACE( X1 );
}

DEFTSCP( pregexp_ar_2dclass_27b9b680_v );
DEFCSTRING( t17401, "PREGEXP-READ-POSIX-CHAR-CLASS" );
EXTERNTSCPP( scrt3_char_2dalphabetic_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt3_char_2dalphabetic_3f_v );
EXTERNTSCPP( sc_string_2d_3esymbol, XAL1( TSCP ) );
EXTERNTSCP( sc_string_2d_3esymbol_v );
EXTERNTSCPP( qobischeme_string_2dupcase, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_string_2dupcase_v );

TSCP  pregexp_ar_2dclass_27b9b680( s13042, i13043, n13044 )
        TSCP  s13042, i13043, n13044;
{
        TSCP  X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t17401 );
        X1 = FALSEVALUE;
        X1 = CONS( X1, EMPTYLIST );
        X3 = sc_cons( _TSCP( 14866 ), EMPTYLIST );
        X2 = X3;
        X3 = i13043;
        X4 = X2;
L17407:
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( n13044 ) ), 
                      3 ) )  goto L17409;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( n13044 ) ) )  goto L17413;
        goto L17414;
L17409:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X3, n13044 ) ) )  goto L17413;
L17414:
        if  ( EQ( TSCPTAG( X3 ), FIXNUMTAG ) )  goto L17418;
        scdebug_error( c12237, 
                       c12238, CONS( X3, EMPTYLIST ) );
L17418:
        X6 = BOOLEAN( LT( _S2CINT( X3 ), 0 ) );
        if  ( TRUE( X6 ) )  goto L17424;
        if  ( AND( EQ( TSCPTAG( s13042 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s13042 ), STRINGTAG ) )
            )  goto L17426;
        scdebug_error( c12259, 
                       c12260, CONS( s13042, EMPTYLIST ) );
L17426:
        X7 = C_FIXED( STRING_LENGTH( s13042 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X7 ) ), 
                      3 ) )  goto L17430;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( X7 ) ) )  goto L17424;
        goto L17437;
L17430:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X3, X7 ) ) )  goto L17437;
L17424:
        scdebug_error( c12237, 
                       c12261, CONS( X3, EMPTYLIST ) );
L17437:
        X5 = C_CHAR( STRING_CHAR( s13042, X3 ) );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X5 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 24082 ) ), 
                       CHARACTERTAG ) ) )  goto L17440;
        X6 = CONS( _TSCP( 24082 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X5, X6 ) );
L17440:
        if  ( NEQ( _S2CINT( X5 ), 
                   _S2CINT( _TSCP( 24082 ) ) ) )  goto L17442;
        X6 = TRUEVALUE;
        SETGEN( PAIR_CAR( X1 ), X6 );
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17445;
        X6 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17446;
L17445:
        X6 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L17446:
        X3 = X6;
        GOBACK( L17407 );
L17442:
        if  ( FALSE( scrt3_char_2dalphabetic_3f( X5 ) ) )  goto L17447;
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17449;
        X6 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17450;
L17449:
        X6 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L17450:
        X4 = sc_cons( X5, X4 );
        X3 = X6;
        GOBACK( L17407 );
L17447:
        if  ( AND( EQ( TSCPIMMEDIATETAG( X5 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 14866 ) ), 
                       CHARACTERTAG ) ) )  goto L17452;
        X6 = CONS( _TSCP( 14866 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X5, X6 ) );
L17452:
        if  ( NEQ( _S2CINT( X5 ), 
                   _S2CINT( _TSCP( 14866 ) ) ) )  goto L17454;
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17456;
        X7 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17457;
L17456:
        X7 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L17457:
        if  ( BITAND( BITOR( _S2CINT( X7 ), 
                             _S2CINT( n13044 ) ), 
                      3 ) )  goto L17459;
        X6 = BOOLEAN( GTE( _S2CINT( X7 ), 
                           _S2CINT( n13044 ) ) );
        goto L17460;
L17459:
        X6 = scrt2__3e_3d_2dtwo( X7, n13044 );
L17460:
        if  ( TRUE( X6 ) )  goto L17465;
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17466;
        X8 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17467;
L17466:
        X8 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L17467:
        if  ( EQ( TSCPTAG( X8 ), FIXNUMTAG ) )  goto L17469;
        scdebug_error( c12237, 
                       c12238, CONS( X8, EMPTYLIST ) );
L17469:
        X9 = BOOLEAN( LT( _S2CINT( X8 ), 0 ) );
        if  ( TRUE( X9 ) )  goto L17475;
        if  ( AND( EQ( TSCPTAG( s13042 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s13042 ), STRINGTAG ) )
            )  goto L17477;
        scdebug_error( c12259, 
                       c12260, CONS( s13042, EMPTYLIST ) );
L17477:
        X10 = C_FIXED( STRING_LENGTH( s13042 ) );
        if  ( BITAND( BITOR( _S2CINT( X8 ), _S2CINT( X10 ) ), 
                      3 ) )  goto L17481;
        if  ( GTE( _S2CINT( X8 ), _S2CINT( X10 ) ) )  goto L17475;
        goto L17488;
L17481:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X8, X10 ) ) )  goto L17488;
L17475:
        scdebug_error( c12237, 
                       c12261, CONS( X8, EMPTYLIST ) );
L17488:
        X7 = C_CHAR( STRING_CHAR( s13042, X8 ) );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X7 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 23826 ) ), 
                       CHARACTERTAG ) ) )  goto L17490;
        X8 = CONS( _TSCP( 23826 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X7, X8 ) );
L17490:
        if  ( NEQ( _S2CINT( X7 ), 
                   _S2CINT( _TSCP( 23826 ) ) ) )  goto L17465;
        X11 = pregexp_pregexp_2dreverse_21( X4 );
        X10 = scrt3_list_2d_3estring( X11 );
        X9 = qobischeme_string_2dupcase( X10 );
        X8 = sc_string_2d_3esymbol( X9 );
        if  ( FALSE( PAIR_CAR( X1 ) ) )  goto L17495;
        X12 = sc_cons( X8, EMPTYLIST );
        X11 = sc_cons( c12606, X12 );
        X10 = X11;
        goto L17496;
L17495:
        X10 = X8;
L17496:
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17498;
        X12 = _TSCP( IPLUS( _S2CINT( X3 ), 
                            _S2CINT( _TSCP( 8 ) ) ) );
        goto L17499;
L17498:
        X12 = scrt2__2b_2dtwo( X3, _TSCP( 8 ) );
L17499:
        X11 = sc_cons( X12, EMPTYLIST );
        X9 = sc_cons( X10, X11 );
        POPSTACKTRACE( X9 );
L17454:
        POPSTACKTRACE( pregexp_pregexp_2derror( CONS( c13076, 
                                                      EMPTYLIST ) ) );
L17465:
        POPSTACKTRACE( pregexp_pregexp_2derror( CONS( c13076, 
                                                      EMPTYLIST ) ) );
L17413:
        POPSTACKTRACE( pregexp_pregexp_2derror( CONS( c13076, 
                                                      EMPTYLIST ) ) );
}

DEFTSCP( pregexp_ter_2dtype_740a2ea3_v );
DEFCSTRING( t17501, "PREGEXP-READ-CLUSTER-TYPE" );

TSCP  pregexp_ter_2dtype_740a2ea3( s13188, i13189, n13190 )
        TSCP  s13188, i13189, n13190;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t17501 );
        if  ( EQ( TSCPTAG( i13189 ), FIXNUMTAG ) )  goto L17506;
        scdebug_error( c12237, 
                       c12238, CONS( i13189, EMPTYLIST ) );
L17506:
        X2 = BOOLEAN( LT( _S2CINT( i13189 ), 0 ) );
        if  ( TRUE( X2 ) )  goto L17512;
        if  ( AND( EQ( TSCPTAG( s13188 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s13188 ), STRINGTAG ) )
            )  goto L17514;
        scdebug_error( c12259, 
                       c12260, CONS( s13188, EMPTYLIST ) );
L17514:
        X3 = C_FIXED( STRING_LENGTH( s13188 ) );
        if  ( BITAND( BITOR( _S2CINT( i13189 ), 
                             _S2CINT( X3 ) ), 
                      3 ) )  goto L17518;
        if  ( GTE( _S2CINT( i13189 ), _S2CINT( X3 ) ) )  goto L17512;
        goto L17525;
L17518:
        if  ( FALSE( scrt2__3e_3d_2dtwo( i13189, X3 ) ) )  goto L17525;
L17512:
        scdebug_error( c12237, 
                       c12261, CONS( i13189, EMPTYLIST ) );
L17525:
        X1 = C_CHAR( STRING_CHAR( s13188, i13189 ) );
        if  ( NEQ( _S2CUINT( X1 ), 
                   _S2CUINT( _TSCP( 16146 ) ) ) )  goto L17503;
        if  ( BITAND( BITOR( _S2CINT( i13189 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17526;
        X1 = _TSCP( IPLUS( _S2CINT( i13189 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17527;
L17526:
        X1 = scrt2__2b_2dtwo( i13189, _TSCP( 4 ) );
L17527:
        if  ( EQ( TSCPTAG( X1 ), FIXNUMTAG ) )  goto L17530;
        scdebug_error( c12237, 
                       c12238, CONS( X1, EMPTYLIST ) );
L17530:
        X3 = BOOLEAN( LT( _S2CINT( X1 ), 0 ) );
        if  ( TRUE( X3 ) )  goto L17536;
        if  ( AND( EQ( TSCPTAG( s13188 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s13188 ), STRINGTAG ) )
            )  goto L17538;
        scdebug_error( c12259, 
                       c12260, CONS( s13188, EMPTYLIST ) );
L17538:
        X4 = C_FIXED( STRING_LENGTH( s13188 ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X4 ) ), 
                      3 ) )  goto L17542;
        if  ( GTE( _S2CINT( X1 ), _S2CINT( X4 ) ) )  goto L17536;
        goto L17549;
L17542:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X1, X4 ) ) )  goto L17549;
L17536:
        scdebug_error( c12237, 
                       c12261, CONS( X1, EMPTYLIST ) );
L17549:
        X2 = C_CHAR( STRING_CHAR( s13188, X1 ) );
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 14866 ) ) ) )  goto L17551;
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17553;
        X5 = _TSCP( IPLUS( _S2CINT( X1 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17554;
L17553:
        X5 = scrt2__2b_2dtwo( X1, _TSCP( 4 ) );
L17554:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( EMPTYLIST, X4 );
        POPSTACKTRACE( X3 );
L17551:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 15634 ) ) ) )  goto L17556;
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17558;
        X5 = _TSCP( IPLUS( _S2CINT( X1 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17559;
L17558:
        X5 = scrt2__2b_2dtwo( X1, _TSCP( 4 ) );
L17559:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c13378, X4 );
        POPSTACKTRACE( X3 );
L17556:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 8466 ) ) ) )  goto L17561;
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17563;
        X5 = _TSCP( IPLUS( _S2CINT( X1 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17564;
L17563:
        X5 = scrt2__2b_2dtwo( X1, _TSCP( 4 ) );
L17564:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c13369, X4 );
        POPSTACKTRACE( X3 );
L17561:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 15890 ) ) ) )  goto L17566;
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17568;
        X5 = _TSCP( IPLUS( _S2CINT( X1 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17569;
L17568:
        X5 = scrt2__2b_2dtwo( X1, _TSCP( 4 ) );
L17569:
        X4 = sc_cons( X5, EMPTYLIST );
        X3 = sc_cons( c13360, X4 );
        POPSTACKTRACE( X3 );
L17566:
        if  ( NEQ( _S2CUINT( X2 ), 
                   _S2CUINT( _TSCP( 15378 ) ) ) )  goto L17571;
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17573;
        X6 = _TSCP( IPLUS( _S2CINT( X1 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17574;
L17573:
        X6 = scrt2__2b_2dtwo( X1, _TSCP( 4 ) );
L17574:
        if  ( EQ( TSCPTAG( X6 ), FIXNUMTAG ) )  goto L17576;
        scdebug_error( c12237, 
                       c12238, CONS( X6, EMPTYLIST ) );
L17576:
        X7 = BOOLEAN( LT( _S2CINT( X6 ), 0 ) );
        if  ( TRUE( X7 ) )  goto L17582;
        if  ( AND( EQ( TSCPTAG( s13188 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s13188 ), STRINGTAG ) )
            )  goto L17584;
        scdebug_error( c12259, 
                       c12260, CONS( s13188, EMPTYLIST ) );
L17584:
        X8 = C_FIXED( STRING_LENGTH( s13188 ) );
        if  ( BITAND( BITOR( _S2CINT( X6 ), _S2CINT( X8 ) ), 
                      3 ) )  goto L17588;
        if  ( GTE( _S2CINT( X6 ), _S2CINT( X8 ) ) )  goto L17582;
        goto L17595;
L17588:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X6, X8 ) ) )  goto L17595;
L17582:
        scdebug_error( c12237, 
                       c12261, CONS( X6, EMPTYLIST ) );
L17595:
        X5 = C_CHAR( STRING_CHAR( s13188, X6 ) );
        if  ( NEQ( _S2CUINT( X5 ), 
                   _S2CUINT( _TSCP( 15634 ) ) ) )  goto L17597;
        X4 = c13320;
        goto L17600;
L17597:
        if  ( NEQ( _S2CUINT( X5 ), 
                   _S2CUINT( _TSCP( 8466 ) ) ) )  goto L17599;
        X4 = c13319;
        goto L17600;
L17599:
        X4 = pregexp_pregexp_2derror( CONS( c13254, EMPTYLIST ) );
L17600:
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L17601;
        X6 = _TSCP( IPLUS( _S2CINT( X1 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L17602;
L17601:
        X6 = scrt2__2b_2dtwo( X1, _TSCP( 8 ) );
L17602:
        X5 = sc_cons( X6, EMPTYLIST );
        X3 = sc_cons( X4, X5 );
        POPSTACKTRACE( X3 );
L17571:
        X3 = X1;
        X4 = EMPTYLIST;
        X5 = FALSEVALUE;
L17605:
        if  ( EQ( TSCPTAG( X3 ), FIXNUMTAG ) )  goto L17607;
        scdebug_error( c12237, 
                       c12238, CONS( X3, EMPTYLIST ) );
L17607:
        X7 = BOOLEAN( LT( _S2CINT( X3 ), 0 ) );
        if  ( TRUE( X7 ) )  goto L17613;
        if  ( AND( EQ( TSCPTAG( s13188 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s13188 ), STRINGTAG ) )
            )  goto L17615;
        scdebug_error( c12259, 
                       c12260, CONS( s13188, EMPTYLIST ) );
L17615:
        X8 = C_FIXED( STRING_LENGTH( s13188 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X8 ) ), 
                      3 ) )  goto L17619;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( X8 ) ) )  goto L17613;
        goto L17626;
L17619:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X3, X8 ) ) )  goto L17626;
L17613:
        scdebug_error( c12237, 
                       c12261, CONS( X3, EMPTYLIST ) );
L17626:
        X6 = C_CHAR( STRING_CHAR( s13188, X3 ) );
        if  ( NEQ( _S2CUINT( X6 ), 
                   _S2CUINT( _TSCP( 11538 ) ) ) )  goto L17628;
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17630;
        X7 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17631;
L17630:
        X7 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L17631:
        X5 = TRUEVALUE;
        X3 = X7;
        GOBACK( L17605 );
L17628:
        if  ( NEQ( _S2CUINT( X6 ), 
                   _S2CUINT( _TSCP( 26898 ) ) ) )  goto L17632;
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17634;
        X7 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17635;
L17634:
        X7 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L17635:
        if  ( FALSE( X5 ) )  goto L17636;
        X9 = c13277;
        goto L17637;
L17636:
        X9 = c13276;
L17637:
        X8 = sc_cons( X9, X4 );
        X5 = FALSEVALUE;
        X4 = X8;
        X3 = X7;
        GOBACK( L17605 );
L17632:
        if  ( NEQ( _S2CUINT( X6 ), 
                   _S2CUINT( _TSCP( 30738 ) ) ) )  goto L17638;
        pregexp_tive_3f_2a_bd6b8339_v = X5;
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17641;
        X7 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17642;
L17641:
        X7 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L17642:
        X5 = FALSEVALUE;
        X3 = X7;
        GOBACK( L17605 );
L17638:
        if  ( NEQ( _S2CUINT( X6 ), 
                   _S2CUINT( _TSCP( 14866 ) ) ) )  goto L17643;
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17645;
        X9 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17646;
L17645:
        X9 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L17646:
        X8 = sc_cons( X9, EMPTYLIST );
        X7 = sc_cons( X4, X8 );
        POPSTACKTRACE( X7 );
L17643:
        POPSTACKTRACE( pregexp_pregexp_2derror( CONS( c13254, 
                                                      EMPTYLIST ) ) );
L17503:
        X2 = sc_cons( i13189, EMPTYLIST );
        X1 = sc_cons( c13201, X2 );
        POPSTACKTRACE( X1 );
}

DEFTSCP( pregexp_subpattern_ac026cd3_v );
DEFCSTRING( t17649, "PREGEXP-READ-SUBPATTERN" );

TSCP  pregexp_subpattern_ac026cd3( s13450, i13451, n13452 )
        TSCP  s13450, i13451, n13452;
{
        TSCP  X17, 
              X16, 
              X15, 
              X14, 
              X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t17649 );
        X1 = pregexp_tive_3f_2a_bd6b8339_v;
        X2 = pregexp_ter_2dtype_740a2ea3( s13450, i13451, n13452 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L17654;
        scrt1__24__car_2derror( X2 );
L17654:
        X3 = PAIR_CAR( X2 );
        X5 = PAIR_CDR( X2 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L17659;
        scrt1__24__car_2derror( X5 );
L17659:
        X4 = PAIR_CAR( X5 );
        X5 = pregexp__2dpattern_829cfa27( s13450, X4, n13452 );
        pregexp_tive_3f_2a_bd6b8339_v = X1;
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L17664;
        scrt1__24__cdr_2derror( X5 );
L17664:
        X7 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L17667;
        scrt1__24__car_2derror( X7 );
L17667:
        X6 = PAIR_CAR( X7 );
        X7 = PAIR_CAR( X5 );
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( n13452 ) ), 
                      3 ) )  goto L17671;
        X8 = BOOLEAN( LT( _S2CINT( X6 ), _S2CINT( n13452 ) ) );
        goto L17672;
L17671:
        X8 = scrt2__3c_2dtwo( X6, n13452 );
L17672:
        if  ( FALSE( X8 ) )  goto L17715;
        if  ( EQ( TSCPTAG( X6 ), FIXNUMTAG ) )  goto L17678;
        scdebug_error( c12237, 
                       c12238, CONS( X6, EMPTYLIST ) );
L17678:
        X10 = BOOLEAN( LT( _S2CINT( X6 ), 0 ) );
        if  ( TRUE( X10 ) )  goto L17684;
        if  ( AND( EQ( TSCPTAG( s13450 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s13450 ), STRINGTAG ) )
            )  goto L17686;
        scdebug_error( c12259, 
                       c12260, CONS( s13450, EMPTYLIST ) );
L17686:
        X11 = C_FIXED( STRING_LENGTH( s13450 ) );
        if  ( BITAND( BITOR( _S2CINT( X6 ), _S2CINT( X11 ) ), 
                      3 ) )  goto L17690;
        if  ( GTE( _S2CINT( X6 ), _S2CINT( X11 ) ) )  goto L17684;
        goto L17697;
L17690:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X6, X11 ) ) )  goto L17697;
L17684:
        scdebug_error( c12237, 
                       c12261, CONS( X6, EMPTYLIST ) );
L17697:
        X9 = C_CHAR( STRING_CHAR( s13450, X6 ) );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X9 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 10514 ) ), 
                       CHARACTERTAG ) ) )  goto L17699;
        X10 = CONS( _TSCP( 10514 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X9, X10 ) );
L17699:
        if  ( NEQ( _S2CINT( X9 ), 
                   _S2CINT( _TSCP( 10514 ) ) ) )  goto L17715;
        X12 = X3;
        X13 = X7;
L17704:
        if  ( NEQ( _S2CUINT( X12 ), _S2CUINT( EMPTYLIST ) ) )  goto L17705;
        X11 = X13;
        goto L17706;
L17705:
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L17708;
        scrt1__24__cdr_2derror( X12 );
L17708:
        X14 = PAIR_CDR( X12 );
        X16 = PAIR_CAR( X12 );
        X17 = sc_cons( X13, EMPTYLIST );
        X15 = sc_cons( X16, X17 );
        X13 = X15;
        X12 = X14;
        GOBACK( L17704 );
L17706:
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17712;
        X13 = _TSCP( IPLUS( _S2CINT( X6 ), 
                            _S2CINT( _TSCP( 4 ) ) ) );
        goto L17713;
L17712:
        X13 = scrt2__2b_2dtwo( X6, _TSCP( 4 ) );
L17713:
        X12 = sc_cons( X13, EMPTYLIST );
        X10 = sc_cons( X11, X12 );
        POPSTACKTRACE( X10 );
L17715:
        POPSTACKTRACE( pregexp_pregexp_2derror( CONS( c13507, 
                                                      EMPTYLIST ) ) );
}

DEFTSCP( pregexp_2dif_2dany_74203067_v );
DEFCSTRING( t17716, "PREGEXP-WRAP-QUANTIFIER-IF-ANY" );
EXTERNTSCPP( scrt1_memv, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_memv_v );
EXTERNTSCPP( scrt1_cdddr, XAL1( TSCP ) );
EXTERNTSCP( scrt1_cdddr_v );
EXTERNTSCPP( pregexp_pregexp_2dread_2dnums, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( pregexp_pregexp_2dread_2dnums_v );
EXTERNTSCPP( scrt1_caddr, XAL1( TSCP ) );
EXTERNTSCP( scrt1_caddr_v );

TSCP  pregexp_2dif_2dany_74203067( v13570, s13571, n13572 )
        TSCP  v13570, s13571, n13572;
{
        TSCP  X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t17716 );
        if  ( EQ( TSCPTAG( v13570 ), PAIRTAG ) )  goto L17719;
        scrt1__24__car_2derror( v13570 );
L17719:
        X1 = PAIR_CAR( v13570 );
        X3 = PAIR_CDR( v13570 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L17724;
        scrt1__24__car_2derror( X3 );
L17724:
        X2 = PAIR_CAR( X3 );
        X3 = X2;
L17728:
        X3 = CONS( X3, EMPTYLIST );
        X5 = PAIR_CAR( X3 );
        if  ( BITAND( BITOR( _S2CINT( X5 ), 
                             _S2CINT( n13572 ) ), 
                      3 ) )  goto L17731;
        if  ( LT( _S2CINT( X5 ), _S2CINT( n13572 ) ) )  goto L17735;
        POPSTACKTRACE( v13570 );
L17731:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X5, n13572 ) ) )  goto L17735;
        POPSTACKTRACE( v13570 );
L17735:
        X5 = PAIR_CAR( X3 );
        if  ( EQ( TSCPTAG( X5 ), FIXNUMTAG ) )  goto L17739;
        scdebug_error( c12237, 
                       c12238, CONS( X5, EMPTYLIST ) );
L17739:
        X6 = BOOLEAN( LT( _S2CINT( X5 ), 0 ) );
        if  ( TRUE( X6 ) )  goto L17745;
        if  ( AND( EQ( TSCPTAG( s13571 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s13571 ), STRINGTAG ) )
            )  goto L17747;
        scdebug_error( c12259, 
                       c12260, CONS( s13571, EMPTYLIST ) );
L17747:
        X7 = C_FIXED( STRING_LENGTH( s13571 ) );
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X7 ) ), 
                      3 ) )  goto L17751;
        if  ( GTE( _S2CINT( X5 ), _S2CINT( X7 ) ) )  goto L17745;
        goto L17758;
L17751:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X5, X7 ) ) )  goto L17758;
L17745:
        scdebug_error( c12237, 
                       c12261, CONS( X5, EMPTYLIST ) );
L17758:
        X4 = C_CHAR( STRING_CHAR( s13571, X5 ) );
        X5 = scrt3_char_2dwhitespace_3f( X4 );
        if  ( FALSE( X5 ) )  goto L17766;
        if  ( TRUE( pregexp_tive_3f_2a_bd6b8339_v ) )  goto L17766;
        X6 = PAIR_CAR( X3 );
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17768;
        X7 = _TSCP( IPLUS( _S2CINT( X6 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17769;
L17768:
        X7 = scrt2__2b_2dtwo( X6, _TSCP( 4 ) );
L17769:
        X3 = X7;
        GOBACK( L17728 );
L17766:
        if  ( FALSE( scrt1_memv( X4, c13595 ) ) )  goto L17770;
        X10 = sc_cons( X1, EMPTYLIST );
        X9 = sc_cons( c13857, X10 );
        X8 = sc_cons( c13856, X9 );
        X7 = sc_cons( c13855, X8 );
        X6 = sc_cons( c13854, X7 );
        X5 = X6;
        X8 = sc_cons( c13851, EMPTYLIST );
        X7 = sc_cons( X5, X8 );
        X6 = X7;
        if  ( NEQ( _S2CUINT( X4 ), 
                   _S2CUINT( _TSCP( 10770 ) ) ) )  goto L17776;
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L17780;
        scrt1__24__cdr_2derror( X5 );
L17780:
        X8 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X8 ), PAIRTAG ) )  goto L17783;
        scrt1__24__cdr_2derror( X8 );
L17783:
        X7 = PAIR_CDR( X8 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L17786;
        scdebug_error( c13626, 
                       c12163, CONS( X7, EMPTYLIST ) );
L17786:
        SETGEN( PAIR_CAR( X7 ), _TSCP( 0 ) );
        X7 = scrt1_cdddr( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L17789;
        scdebug_error( c13626, 
                       c12163, CONS( X7, EMPTYLIST ) );
L17789:
        SETGEN( PAIR_CAR( X7 ), FALSEVALUE );
        goto L17821;
L17776:
        if  ( NEQ( _S2CUINT( X4 ), 
                   _S2CUINT( _TSCP( 11026 ) ) ) )  goto L17791;
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L17795;
        scrt1__24__cdr_2derror( X5 );
L17795:
        X8 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X8 ), PAIRTAG ) )  goto L17798;
        scrt1__24__cdr_2derror( X8 );
L17798:
        X7 = PAIR_CDR( X8 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L17801;
        scdebug_error( c13626, 
                       c12163, CONS( X7, EMPTYLIST ) );
L17801:
        SETGEN( PAIR_CAR( X7 ), _TSCP( 4 ) );
        X7 = scrt1_cdddr( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L17804;
        scdebug_error( c13626, 
                       c12163, CONS( X7, EMPTYLIST ) );
L17804:
        SETGEN( PAIR_CAR( X7 ), FALSEVALUE );
        goto L17821;
L17791:
        if  ( NEQ( _S2CUINT( X4 ), 
                   _S2CUINT( _TSCP( 16146 ) ) ) )  goto L17806;
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L17810;
        scrt1__24__cdr_2derror( X5 );
L17810:
        X8 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X8 ), PAIRTAG ) )  goto L17813;
        scrt1__24__cdr_2derror( X8 );
L17813:
        X7 = PAIR_CDR( X8 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L17816;
        scdebug_error( c13626, 
                       c12163, CONS( X7, EMPTYLIST ) );
L17816:
        SETGEN( PAIR_CAR( X7 ), _TSCP( 0 ) );
        X7 = scrt1_cdddr( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L17819;
        scdebug_error( c13626, 
                       c12163, CONS( X7, EMPTYLIST ) );
L17819:
        SETGEN( PAIR_CAR( X7 ), _TSCP( 4 ) );
        goto L17821;
L17806:
        if  ( NEQ( _S2CUINT( X4 ), 
                   _S2CUINT( _TSCP( 31506 ) ) ) )  goto L17821;
        X9 = PAIR_CAR( X3 );
        if  ( BITAND( BITOR( _S2CINT( X9 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17824;
        X8 = _TSCP( IPLUS( _S2CINT( X9 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17825;
L17824:
        X8 = scrt2__2b_2dtwo( X9, _TSCP( 4 ) );
L17825:
        X7 = pregexp_pregexp_2dread_2dnums( s13571, X8, n13572 );
        if  ( TRUE( X7 ) )  goto L17827;
        X8 = CONS( c13620, EMPTYLIST );
        pregexp_pregexp_2derror( CONS( c13619, X8 ) );
L17827:
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L17830;
        scrt1__24__car_2derror( X7 );
L17830:
        X8 = PAIR_CAR( X7 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L17833;
        scrt1__24__cdr_2derror( X5 );
L17833:
        X10 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L17836;
        scrt1__24__cdr_2derror( X10 );
L17836:
        X9 = PAIR_CDR( X10 );
        if  ( EQ( TSCPTAG( X9 ), PAIRTAG ) )  goto L17839;
        scdebug_error( c13626, 
                       c12163, CONS( X9, EMPTYLIST ) );
L17839:
        SETGEN( PAIR_CAR( X9 ), X8 );
        X9 = PAIR_CDR( X7 );
        if  ( EQ( TSCPTAG( X9 ), PAIRTAG ) )  goto L17843;
        scrt1__24__car_2derror( X9 );
L17843:
        X8 = PAIR_CAR( X9 );
        X9 = scrt1_cdddr( X5 );
        if  ( EQ( TSCPTAG( X9 ), PAIRTAG ) )  goto L17846;
        scdebug_error( c13626, 
                       c12163, CONS( X9, EMPTYLIST ) );
L17846:
        SETGEN( PAIR_CAR( X9 ), X8 );
        X8 = scrt1_caddr( X7 );
        SETGEN( PAIR_CAR( X3 ), X8 );
L17821:
        X8 = PAIR_CAR( X3 );
        if  ( BITAND( BITOR( _S2CINT( X8 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17849;
        X7 = _TSCP( IPLUS( _S2CINT( X8 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17850;
L17849:
        X7 = scrt2__2b_2dtwo( X8, _TSCP( 4 ) );
L17850:
        X8 = X7;
L17853:
        if  ( BITAND( BITOR( _S2CINT( X8 ), 
                             _S2CINT( n13572 ) ), 
                      3 ) )  goto L17855;
        if  ( GTE( _S2CINT( X8 ), _S2CINT( n13572 ) ) )  goto L17859;
        goto L17860;
L17855:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X8, n13572 ) ) )  goto L17859;
L17860:
        if  ( EQ( TSCPTAG( X8 ), FIXNUMTAG ) )  goto L17865;
        scdebug_error( c12237, 
                       c12238, CONS( X8, EMPTYLIST ) );
L17865:
        X10 = BOOLEAN( LT( _S2CINT( X8 ), 0 ) );
        if  ( TRUE( X10 ) )  goto L17871;
        if  ( AND( EQ( TSCPTAG( s13571 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s13571 ), STRINGTAG ) )
            )  goto L17873;
        scdebug_error( c12259, 
                       c12260, CONS( s13571, EMPTYLIST ) );
L17873:
        X11 = C_FIXED( STRING_LENGTH( s13571 ) );
        if  ( BITAND( BITOR( _S2CINT( X8 ), _S2CINT( X11 ) ), 
                      3 ) )  goto L17877;
        if  ( GTE( _S2CINT( X8 ), _S2CINT( X11 ) ) )  goto L17871;
        goto L17884;
L17877:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X8, X11 ) ) )  goto L17884;
L17871:
        scdebug_error( c12237, 
                       c12261, CONS( X8, EMPTYLIST ) );
L17884:
        X9 = C_CHAR( STRING_CHAR( s13571, X8 ) );
        X10 = scrt3_char_2dwhitespace_3f( X9 );
        if  ( FALSE( X10 ) )  goto L17892;
        if  ( TRUE( pregexp_tive_3f_2a_bd6b8339_v ) )  goto L17892;
        if  ( BITAND( BITOR( _S2CINT( X8 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17893;
        X8 = _TSCP( IPLUS( _S2CINT( X8 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        GOBACK( L17853 );
L17893:
        X8 = scrt2__2b_2dtwo( X8, _TSCP( 4 ) );
        GOBACK( L17853 );
L17892:
        if  ( AND( EQ( TSCPIMMEDIATETAG( X9 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 16146 ) ), 
                       CHARACTERTAG ) ) )  goto L17896;
        X10 = CONS( _TSCP( 16146 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X9, X10 ) );
L17896:
        if  ( NEQ( _S2CINT( X9 ), 
                   _S2CINT( _TSCP( 16146 ) ) ) )  goto L17898;
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L17902;
        scrt1__24__cdr_2derror( X5 );
L17902:
        X10 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L17905;
        scdebug_error( c13626, 
                       c12163, CONS( X10, EMPTYLIST ) );
L17905:
        SETGEN( PAIR_CAR( X10 ), TRUEVALUE );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L17908;
        scrt1__24__cdr_2derror( X6 );
L17908:
        X10 = PAIR_CDR( X6 );
        if  ( BITAND( BITOR( _S2CINT( X8 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17910;
        X11 = _TSCP( IPLUS( _S2CINT( X8 ), 
                            _S2CINT( _TSCP( 4 ) ) ) );
        goto L17911;
L17910:
        X11 = scrt2__2b_2dtwo( X8, _TSCP( 4 ) );
L17911:
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L17913;
        scdebug_error( c13626, 
                       c12163, CONS( X10, EMPTYLIST ) );
L17913:
        SETGEN( PAIR_CAR( X10 ), X11 );
        goto L17863;
L17898:
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L17917;
        scrt1__24__cdr_2derror( X5 );
L17917:
        X10 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L17920;
        scdebug_error( c13626, 
                       c12163, CONS( X10, EMPTYLIST ) );
L17920:
        SETGEN( PAIR_CAR( X10 ), FALSEVALUE );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L17923;
        scrt1__24__cdr_2derror( X6 );
L17923:
        X10 = PAIR_CDR( X6 );
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L17926;
        scdebug_error( c13626, 
                       c12163, CONS( X10, EMPTYLIST ) );
L17926:
        SETGEN( PAIR_CAR( X10 ), X8 );
        goto L17863;
L17859:
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L17930;
        scrt1__24__cdr_2derror( X5 );
L17930:
        X10 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L17933;
        scdebug_error( c13626, 
                       c12163, CONS( X10, EMPTYLIST ) );
L17933:
        SETGEN( PAIR_CAR( X10 ), FALSEVALUE );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L17936;
        scrt1__24__cdr_2derror( X6 );
L17936:
        X10 = PAIR_CDR( X6 );
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L17939;
        scdebug_error( c13626, 
                       c12163, CONS( X10, EMPTYLIST ) );
L17939:
        SETGEN( PAIR_CAR( X10 ), X8 );
L17863:
        POPSTACKTRACE( X6 );
L17770:
        POPSTACKTRACE( v13570 );
}

DEFTSCP( pregexp_pregexp_2dread_2dnums_v );
DEFCSTRING( t17941, "PREGEXP-READ-NUMS" );
EXTERNTSCPP( scrt2__3d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3d_2dtwo_v );

TSCP  pregexp_pregexp_2dread_2dnums( s13904, i13905, n13906 )
        TSCP  s13904, i13905, n13906;
{
        TSCP  X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t17941 );
        X1 = EMPTYLIST;
        X2 = EMPTYLIST;
        X3 = i13905;
        X4 = _TSCP( 4 );
L17944:
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( n13906 ) ), 
                      3 ) )  goto L17946;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( n13906 ) ) )  goto L17950;
        goto L17953;
L17946:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X3, n13906 ) ) )  goto L17953;
L17950:
        pregexp_pregexp_2derror( CONS( c13925, EMPTYLIST ) );
L17953:
        if  ( EQ( TSCPTAG( X3 ), FIXNUMTAG ) )  goto L17955;
        scdebug_error( c12237, 
                       c12238, CONS( X3, EMPTYLIST ) );
L17955:
        X8 = BOOLEAN( LT( _S2CINT( X3 ), 0 ) );
        if  ( TRUE( X8 ) )  goto L17961;
        if  ( AND( EQ( TSCPTAG( s13904 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s13904 ), STRINGTAG ) )
            )  goto L17963;
        scdebug_error( c12259, 
                       c12260, CONS( s13904, EMPTYLIST ) );
L17963:
        X9 = C_FIXED( STRING_LENGTH( s13904 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X9 ) ), 
                      3 ) )  goto L17967;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( X9 ) ) )  goto L17961;
        goto L17974;
L17967:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X3, X9 ) ) )  goto L17974;
L17961:
        scdebug_error( c12237, 
                       c12261, CONS( X3, EMPTYLIST ) );
L17974:
        X5 = C_CHAR( STRING_CHAR( s13904, X3 ) );
        if  ( FALSE( scrt3_char_2dnumeric_3f( X5 ) ) )  goto L17976;
        if  ( BITAND( BITOR( _S2CINT( X4 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17979;
        if  ( EQ( _S2CUINT( X4 ), _S2CUINT( _TSCP( 4 ) ) ) )  goto L17983;
        goto L17984;
L17979:
        if  ( TRUE( scrt2__3d_2dtwo( X4, _TSCP( 4 ) ) ) )  goto L17983;
        goto L17984;
L17976:
        X8 = scrt3_char_2dwhitespace_3f( X5 );
        if  ( FALSE( X8 ) )  goto L17993;
        if  ( TRUE( pregexp_tive_3f_2a_bd6b8339_v ) )  goto L17993;
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17994;
        X9 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17995;
L17994:
        X9 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L17995:
        X3 = X9;
        GOBACK( L17944 );
L17984:
        X8 = sc_cons( X5, X2 );
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17996;
        X9 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17997;
L17996:
        X9 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L17997:
        X4 = _TSCP( 8 );
        X3 = X9;
        X2 = X8;
        GOBACK( L17944 );
L17983:
        X8 = sc_cons( X5, X1 );
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17998;
        X9 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17999;
L17998:
        X9 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L17999:
        X4 = _TSCP( 4 );
        X3 = X9;
        X1 = X8;
        GOBACK( L17944 );
L17993:
        if  ( AND( EQ( TSCPIMMEDIATETAG( X5 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 11282 ) ), 
                       CHARACTERTAG ) ) )  goto L18001;
        X9 = CONS( _TSCP( 11282 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X5, X9 ) );
L18001:
        X8 = BOOLEAN( EQ( _S2CINT( X5 ), 
                          _S2CINT( _TSCP( 11282 ) ) ) );
        if  ( FALSE( X8 ) )  goto L18016;
        if  ( BITAND( BITOR( _S2CINT( X4 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18008;
        if  ( EQ( _S2CUINT( X4 ), _S2CUINT( _TSCP( 4 ) ) ) )  goto L18012;
        goto L18016;
L18008:
        if  ( FALSE( scrt2__3d_2dtwo( X4, _TSCP( 4 ) ) ) )  goto L18016;
L18012:
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18017;
        X8 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18018;
L18017:
        X8 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L18018:
        X4 = _TSCP( 8 );
        X3 = X8;
        GOBACK( L17944 );
L18016:
        if  ( AND( EQ( TSCPIMMEDIATETAG( X5 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 32018 ) ), 
                       CHARACTERTAG ) ) )  goto L18020;
        X8 = CONS( _TSCP( 32018 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X5, X8 ) );
L18020:
        if  ( NEQ( _S2CINT( X5 ), 
                   _S2CINT( _TSCP( 32018 ) ) ) )  goto L18022;
        X9 = pregexp_pregexp_2dreverse_21( X2 );
        X8 = scrt3_list_2d_3estring( X9 );
        X6 = scrt2_string_2d_3enumber( X8, EMPTYLIST );
        X9 = pregexp_pregexp_2dreverse_21( X1 );
        X8 = scrt3_list_2d_3estring( X9 );
        X7 = scrt2_string_2d_3enumber( X8, EMPTYLIST );
        if  ( FALSE( X7 ) )  goto L18025;
        X8 = FALSEVALUE;
        goto L18026;
L18025:
        X8 = TRUEVALUE;
L18026:
        if  ( FALSE( X8 ) )  goto L18040;
        if  ( BITAND( BITOR( _S2CINT( X4 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18032;
        if  ( EQ( _S2CUINT( X4 ), _S2CUINT( _TSCP( 4 ) ) ) )  goto L18036;
        goto L18040;
L18032:
        if  ( TRUE( scrt2__3d_2dtwo( X4, _TSCP( 4 ) ) ) )  goto L18036;
        goto L18040;
L18022:
        POPSTACKTRACE( FALSEVALUE );
L18036:
        X10 = sc_cons( X3, EMPTYLIST );
        X9 = sc_cons( FALSEVALUE, X10 );
        X8 = sc_cons( _TSCP( 0 ), X9 );
        POPSTACKTRACE( X8 );
L18040:
        if  ( BITAND( BITOR( _S2CINT( X4 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18043;
        if  ( EQ( _S2CUINT( X4 ), _S2CUINT( _TSCP( 4 ) ) ) )  goto L18047;
        goto L18048;
L18043:
        if  ( FALSE( scrt2__3d_2dtwo( X4, _TSCP( 4 ) ) ) )  goto L18048;
L18047:
        X10 = sc_cons( X3, EMPTYLIST );
        X9 = sc_cons( X7, X10 );
        X8 = sc_cons( X7, X9 );
        POPSTACKTRACE( X8 );
L18048:
        X10 = sc_cons( X3, EMPTYLIST );
        X9 = sc_cons( X6, X10 );
        X8 = sc_cons( X7, X9 );
        POPSTACKTRACE( X8 );
}

DEFTSCP( pregexp_har_2dlist_c3a17f27_v );
DEFCSTRING( t18053, "PREGEXP-INVERT-CHAR-LIST" );

TSCP  pregexp_har_2dlist_c3a17f27( v14049 )
        TSCP  v14049;
{
        TSCP  X1;

        PUSHSTACKTRACE( t18053 );
        if  ( EQ( TSCPTAG( v14049 ), PAIRTAG ) )  goto L18056;
        scrt1__24__car_2derror( v14049 );
L18056:
        X1 = PAIR_CAR( v14049 );
        if  ( EQ( TSCPTAG( X1 ), PAIRTAG ) )  goto L18059;
        scdebug_error( c13626, 
                       c12163, CONS( X1, EMPTYLIST ) );
L18059:
        SETGEN( PAIR_CAR( X1 ), c14059 );
        POPSTACKTRACE( v14049 );
}

DEFTSCP( pregexp_har_2dlist_9cba0ef7_v );
DEFCSTRING( t18061, "PREGEXP-READ-CHAR-LIST" );

TSCP  pregexp_har_2dlist_9cba0ef7( s14062, i14063, n14064 )
        TSCP  s14062, i14063, n14064;
{
        TSCP  X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t18061 );
        X1 = EMPTYLIST;
        X2 = i14063;
L18064:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( n14064 ) ), 
                      3 ) )  goto L18066;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( n14064 ) ) )  goto L18070;
        goto L18071;
L18066:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X2, n14064 ) ) )  goto L18070;
L18071:
        if  ( EQ( TSCPTAG( X2 ), FIXNUMTAG ) )  goto L18075;
        scdebug_error( c12237, 
                       c12238, CONS( X2, EMPTYLIST ) );
L18075:
        X4 = BOOLEAN( LT( _S2CINT( X2 ), 0 ) );
        if  ( TRUE( X4 ) )  goto L18081;
        if  ( AND( EQ( TSCPTAG( s14062 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s14062 ), STRINGTAG ) )
            )  goto L18083;
        scdebug_error( c12259, 
                       c12260, CONS( s14062, EMPTYLIST ) );
L18083:
        X5 = C_FIXED( STRING_LENGTH( s14062 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X5 ) ), 
                      3 ) )  goto L18087;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X5 ) ) )  goto L18081;
        goto L18094;
L18087:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X2, X5 ) ) )  goto L18094;
L18081:
        scdebug_error( c12237, 
                       c12261, CONS( X2, EMPTYLIST ) );
L18094:
        X3 = C_CHAR( STRING_CHAR( s14062, X2 ) );
        if  ( NEQ( _S2CUINT( X3 ), 
                   _S2CUINT( _TSCP( 23826 ) ) ) )  goto L18096;
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( EMPTYLIST ) ) )  goto L18098;
        X4 = sc_cons( X3, X1 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18100;
        X2 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18101;
L18100:
        X2 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L18101:
        X1 = X4;
        GOBACK( L18064 );
L18098:
        X6 = pregexp_pregexp_2dreverse_21( X1 );
        X5 = sc_cons( c14312, X6 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18102;
        X7 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18103;
L18102:
        X7 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L18103:
        X6 = sc_cons( X7, EMPTYLIST );
        X4 = sc_cons( X5, X6 );
        POPSTACKTRACE( X4 );
L18096:
        if  ( NEQ( _S2CUINT( X3 ), 
                   _S2CUINT( _TSCP( 23570 ) ) ) )  goto L18105;
        X4 = pregexp_ped_2dchar_b91fbb8c( s14062, X2, n14064 );
        if  ( FALSE( X4 ) )  goto L18108;
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L18111;
        scrt1__24__car_2derror( X4 );
L18111:
        X6 = PAIR_CAR( X4 );
        X5 = sc_cons( X6, X1 );
        X6 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L18115;
        scrt1__24__car_2derror( X6 );
L18115:
        X2 = PAIR_CAR( X6 );
        X1 = X5;
        GOBACK( L18064 );
L18108:
        X5 = CONS( c12547, EMPTYLIST );
        POPSTACKTRACE( pregexp_pregexp_2derror( CONS( c14290, X5 ) ) );
L18105:
        if  ( NEQ( _S2CUINT( X3 ), 
                   _S2CUINT( _TSCP( 11538 ) ) ) )  goto L18117;
        X4 = BOOLEAN( EQ( _S2CUINT( X1 ), 
                          _S2CUINT( EMPTYLIST ) ) );
        if  ( TRUE( X4 ) )  goto L18123;
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18124;
        X5 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18125;
L18124:
        X5 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L18125:
        if  ( BITAND( BITOR( _S2CINT( X5 ), 
                             _S2CINT( n14064 ) ), 
                      3 ) )  goto L18127;
        X6 = BOOLEAN( LT( _S2CINT( X5 ), _S2CINT( n14064 ) ) );
        goto L18128;
L18127:
        X6 = scrt2__3c_2dtwo( X5, n14064 );
L18128:
        if  ( FALSE( X6 ) )  goto L18159;
        if  ( EQ( TSCPTAG( X5 ), FIXNUMTAG ) )  goto L18134;
        scdebug_error( c12237, 
                       c12238, CONS( X5, EMPTYLIST ) );
L18134:
        X8 = BOOLEAN( LT( _S2CINT( X5 ), 0 ) );
        if  ( TRUE( X8 ) )  goto L18140;
        if  ( AND( EQ( TSCPTAG( s14062 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s14062 ), STRINGTAG ) )
            )  goto L18142;
        scdebug_error( c12259, 
                       c12260, CONS( s14062, EMPTYLIST ) );
L18142:
        X9 = C_FIXED( STRING_LENGTH( s14062 ) );
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X9 ) ), 
                      3 ) )  goto L18146;
        if  ( GTE( _S2CINT( X5 ), _S2CINT( X9 ) ) )  goto L18140;
        goto L18153;
L18146:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X5, X9 ) ) )  goto L18153;
L18140:
        scdebug_error( c12237, 
                       c12261, CONS( X5, EMPTYLIST ) );
L18153:
        X7 = C_CHAR( STRING_CHAR( s14062, X5 ) );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X7 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 23826 ) ), 
                       CHARACTERTAG ) ) )  goto L18155;
        X8 = CONS( _TSCP( 23826 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X7, X8 ) );
L18155:
        if  ( EQ( _S2CINT( X7 ), _S2CINT( _TSCP( 23826 ) ) ) )  goto L18123;
        goto L18159;
L18117:
        if  ( NEQ( _S2CUINT( X3 ), 
                   _S2CUINT( _TSCP( 23314 ) ) ) )  goto L18160;
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18162;
        X5 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18163;
L18162:
        X5 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L18163:
        if  ( EQ( TSCPTAG( X5 ), FIXNUMTAG ) )  goto L18165;
        scdebug_error( c12237, 
                       c12238, CONS( X5, EMPTYLIST ) );
L18165:
        X6 = BOOLEAN( LT( _S2CINT( X5 ), 0 ) );
        if  ( TRUE( X6 ) )  goto L18171;
        if  ( AND( EQ( TSCPTAG( s14062 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s14062 ), STRINGTAG ) )
            )  goto L18173;
        scdebug_error( c12259, 
                       c12260, CONS( s14062, EMPTYLIST ) );
L18173:
        X7 = C_FIXED( STRING_LENGTH( s14062 ) );
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X7 ) ), 
                      3 ) )  goto L18177;
        if  ( GTE( _S2CINT( X5 ), _S2CINT( X7 ) ) )  goto L18171;
        goto L18184;
L18177:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X5, X7 ) ) )  goto L18184;
L18171:
        scdebug_error( c12237, 
                       c12261, CONS( X5, EMPTYLIST ) );
L18184:
        X4 = C_CHAR( STRING_CHAR( s14062, X5 ) );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X4 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 14866 ) ), 
                       CHARACTERTAG ) ) )  goto L18186;
        X5 = CONS( _TSCP( 14866 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X4, X5 ) );
L18186:
        if  ( NEQ( _S2CINT( X4 ), 
                   _S2CINT( _TSCP( 14866 ) ) ) )  goto L18188;
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L18190;
        X6 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L18191;
L18190:
        X6 = scrt2__2b_2dtwo( X2, _TSCP( 8 ) );
L18191:
        X5 = pregexp_ar_2dclass_27b9b680( s14062, X6, n14064 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L18194;
        scrt1__24__car_2derror( X5 );
L18194:
        X7 = PAIR_CAR( X5 );
        X6 = sc_cons( X7, X1 );
        X7 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L18198;
        scrt1__24__car_2derror( X7 );
L18198:
        X2 = PAIR_CAR( X7 );
        X1 = X6;
        GOBACK( L18064 );
L18188:
        X5 = sc_cons( X3, X1 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18200;
        X2 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18201;
L18200:
        X2 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L18201:
        X1 = X5;
        GOBACK( L18064 );
L18160:
        X4 = sc_cons( X3, X1 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18202;
        X2 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18203;
L18202:
        X2 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L18203:
        X1 = X4;
        GOBACK( L18064 );
L18123:
        X4 = sc_cons( X3, X1 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18204;
        X2 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18205;
L18204:
        X2 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L18205:
        X1 = X4;
        GOBACK( L18064 );
L18159:
        if  ( EQ( TSCPTAG( X1 ), PAIRTAG ) )  goto L18207;
        scrt1__24__car_2derror( X1 );
L18207:
        X4 = PAIR_CAR( X1 );
        if  ( NEQ( TSCPIMMEDIATETAG( X4 ), CHARACTERTAG ) )  goto L18210;
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18212;
        X11 = _TSCP( IPLUS( _S2CINT( X2 ), 
                            _S2CINT( _TSCP( 4 ) ) ) );
        goto L18213;
L18212:
        X11 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L18213:
        if  ( EQ( TSCPTAG( X11 ), FIXNUMTAG ) )  goto L18215;
        scdebug_error( c12237, 
                       c12238, CONS( X11, EMPTYLIST ) );
L18215:
        X12 = BOOLEAN( LT( _S2CINT( X11 ), 0 ) );
        if  ( TRUE( X12 ) )  goto L18221;
        if  ( AND( EQ( TSCPTAG( s14062 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s14062 ), STRINGTAG ) )
            )  goto L18223;
        scdebug_error( c12259, 
                       c12260, CONS( s14062, EMPTYLIST ) );
L18223:
        X13 = C_FIXED( STRING_LENGTH( s14062 ) );
        if  ( BITAND( BITOR( _S2CINT( X11 ), 
                             _S2CINT( X13 ) ), 
                      3 ) )  goto L18227;
        if  ( GTE( _S2CINT( X11 ), _S2CINT( X13 ) ) )  goto L18221;
        goto L18234;
L18227:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X11, X13 ) ) )  goto L18234;
L18221:
        scdebug_error( c12237, 
                       c12261, CONS( X11, EMPTYLIST ) );
L18234:
        X10 = C_CHAR( STRING_CHAR( s14062, X11 ) );
        X9 = sc_cons( X10, EMPTYLIST );
        X8 = sc_cons( X4, X9 );
        X7 = sc_cons( c14236, X8 );
        X6 = X7;
        X7 = PAIR_CDR( X1 );
        X5 = sc_cons( X6, X7 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L18237;
        X2 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L18238;
L18237:
        X2 = scrt2__2b_2dtwo( X2, _TSCP( 8 ) );
L18238:
        X1 = X5;
        GOBACK( L18064 );
L18210:
        X5 = sc_cons( X3, X1 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18239;
        X2 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18240;
L18239:
        X2 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L18240:
        X1 = X5;
        GOBACK( L18064 );
L18070:
        X4 = CONS( c14350, EMPTYLIST );
        POPSTACKTRACE( pregexp_pregexp_2derror( CONS( c14290, X4 ) ) );
}

DEFTSCP( pregexp_ng_2dmatch_8f735cce_v );
DEFCSTRING( t18241, "PREGEXP-STRING-MATCH" );

TSCP  pregexp_ng_2dmatch_8f735cce( s14352, 
                                   s14353, 
                                   i14354, 
                                   n14355, s14356, f14357 )
        TSCP  s14352, 
              s14353, i14354, n14355, s14356, f14357;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t18241 );
        if  ( AND( EQ( TSCPTAG( s14352 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s14352 ), STRINGTAG ) )
            )  goto L18244;
        scdebug_error( c12259, 
                       c12260, CONS( s14352, EMPTYLIST ) );
L18244:
        X1 = C_FIXED( STRING_LENGTH( s14352 ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( n14355 ) ), 
                      3 ) )  goto L18248;
        if  ( GT( _S2CINT( X1 ), _S2CINT( n14355 ) ) )  goto L18252;
        goto L18253;
L18248:
        if  ( FALSE( scrt2__3e_2dtwo( X1, n14355 ) ) )  goto L18253;
L18252:
        X2 = f14357;
        X2 = UNKNOWNCALL( X2, 0 );
        POPSTACKTRACE( VIA( PROCEDURE_CODE( X2 ) )( PROCEDURE_CLOSURE( X2 ) ) );
L18253:
        X2 = _TSCP( 0 );
        X3 = i14354;
L18257:
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L18259;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X1 ) ) )  goto L18263;
        goto L18264;
L18259:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X2, X1 ) ) )  goto L18264;
L18263:
        X4 = s14356;
        X4 = UNKNOWNCALL( X4, 1 );
        POPSTACKTRACE( VIA( PROCEDURE_CODE( X4 ) )( X3, 
                                                    PROCEDURE_CLOSURE( X4 ) ) );
L18264:
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( n14355 ) ), 
                      3 ) )  goto L18268;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( n14355 ) ) )  goto L18272;
        goto L18273;
L18268:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X3, n14355 ) ) )  goto L18272;
L18273:
        if  ( EQ( TSCPTAG( X3 ), FIXNUMTAG ) )  goto L18277;
        scdebug_error( c12237, 
                       c12238, CONS( X3, EMPTYLIST ) );
L18277:
        X5 = BOOLEAN( LT( _S2CINT( X3 ), 0 ) );
        if  ( TRUE( X5 ) )  goto L18283;
        if  ( AND( EQ( TSCPTAG( s14353 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s14353 ), STRINGTAG ) )
            )  goto L18285;
        scdebug_error( c12259, 
                       c12260, CONS( s14353, EMPTYLIST ) );
L18285:
        X6 = C_FIXED( STRING_LENGTH( s14353 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L18289;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( X6 ) ) )  goto L18283;
        goto L18296;
L18289:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X3, X6 ) ) )  goto L18296;
L18283:
        scdebug_error( c12237, 
                       c12261, CONS( X3, EMPTYLIST ) );
L18296:
        X4 = C_CHAR( STRING_CHAR( s14353, X3 ) );
        if  ( EQ( TSCPTAG( X2 ), FIXNUMTAG ) )  goto L18298;
        scdebug_error( c12237, 
                       c12238, CONS( X2, EMPTYLIST ) );
L18298:
        X6 = BOOLEAN( LT( _S2CINT( X2 ), 0 ) );
        if  ( TRUE( X6 ) )  goto L18304;
        X7 = C_FIXED( STRING_LENGTH( s14352 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X7 ) ), 
                      3 ) )  goto L18308;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X7 ) ) )  goto L18304;
        goto L18315;
L18308:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X2, X7 ) ) )  goto L18315;
L18304:
        scdebug_error( c12237, 
                       c12261, CONS( X2, EMPTYLIST ) );
L18315:
        X5 = C_CHAR( STRING_CHAR( s14352, X2 ) );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X5 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( X4 ), CHARACTERTAG ) )
            )  goto L18317;
        X6 = CONS( X4, EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X5, X6 ) );
L18317:
        if  ( NEQ( _S2CINT( X5 ), _S2CINT( X4 ) ) )  goto L18319;
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18321;
        X6 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18322;
L18321:
        X6 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L18322:
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18323;
        X3 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18324;
L18323:
        X3 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L18324:
        X2 = X6;
        GOBACK( L18257 );
L18319:
        X6 = f14357;
        X6 = UNKNOWNCALL( X6, 0 );
        POPSTACKTRACE( VIA( PROCEDURE_CODE( X6 ) )( PROCEDURE_CLOSURE( X6 ) ) );
L18272:
        X4 = f14357;
        X4 = UNKNOWNCALL( X4, 0 );
        POPSTACKTRACE( VIA( PROCEDURE_CODE( X4 ) )( PROCEDURE_CLOSURE( X4 ) ) );
}

DEFTSCP( pregexp__2dword_3f_96ff223a_v );
DEFCSTRING( t18325, "PREGEXP-CHAR-WORD?" );

TSCP  pregexp__2dword_3f_96ff223a( c14459 )
        TSCP  c14459;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t18325 );
        X1 = scrt3_char_2dalphabetic_3f( c14459 );
        if  ( TRUE( X1 ) )  goto L18328;
        X2 = scrt3_char_2dnumeric_3f( c14459 );
        if  ( TRUE( X2 ) )  goto L18331;
        if  ( AND( EQ( TSCPIMMEDIATETAG( c14459 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 24338 ) ), 
                       CHARACTERTAG ) ) )  goto L18334;
        X3 = CONS( _TSCP( 24338 ), EMPTYLIST );
        scdebug_error( c12230, 
                       c12231, CONS( c14459, X3 ) );
L18334:
        POPSTACKTRACE( BOOLEAN( EQ( _S2CINT( c14459 ), 
                                    _S2CINT( _TSCP( 24338 ) ) ) ) );
L18331:
        POPSTACKTRACE( X2 );
L18328:
        POPSTACKTRACE( X1 );
}

DEFTSCP( pregexp_2dclass_3f_7022b0e_v );
DEFCSTRING( t18336, "PREGEXP-CHECK-IF-IN-CHAR-CLASS?" );
EXTERNTSCPP( scrt3_char_2dlower_2dcase_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt3_char_2dlower_2dcase_3f_v );
EXTERNTSCPP( scrt3_char_2dupper_2dcase_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt3_char_2dupper_2dcase_3f_v );
EXTERNTSCPP( scrt3_char_2dci_3d_3f, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt3_char_2dci_3d_3f_v );

TSCP  pregexp_2dclass_3f_7022b0e( c14477, c14478 )
        TSCP  c14477, c14478;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t18336 );
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c12671 ) ) )  goto L18338;
        if  ( AND( EQ( TSCPIMMEDIATETAG( c14477 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 2578 ) ), 
                       CHARACTERTAG ) ) )  goto L18341;
        X1 = CONS( _TSCP( 2578 ), EMPTYLIST );
        scdebug_error( c12230, 
                       c12231, CONS( c14477, X1 ) );
L18341:
        POPSTACKTRACE( BOOLEAN( NEQ( _S2CINT( c14477 ), 
                                     _S2CINT( _TSCP( 2578 ) ) ) ) );
L18338:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c14487 ) ) )  goto L18343;
        X1 = scrt3_char_2dalphabetic_3f( c14477 );
        if  ( TRUE( X1 ) )  goto L18346;
        POPSTACKTRACE( scrt3_char_2dnumeric_3f( c14477 ) );
L18346:
        POPSTACKTRACE( X1 );
L18343:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c14491 ) ) )  goto L18348;
        POPSTACKTRACE( scrt3_char_2dalphabetic_3f( c14477 ) );
L18348:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c14495 ) ) )  goto L18350;
        if  ( EQ( TSCPIMMEDIATETAG( c14477 ), CHARACTERTAG ) )  goto L18353;
        scdebug_error( c12070, 
                       c12071, CONS( c14477, EMPTYLIST ) );
L18353:
        X1 = CHAR_FIX( c14477 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 512 ) ) ), 
                      3 ) )  goto L18356;
        POPSTACKTRACE( BOOLEAN( LT( _S2CINT( X1 ), 
                                    _S2CINT( _TSCP( 512 ) ) ) ) );
L18356:
        POPSTACKTRACE( scrt2__3c_2dtwo( X1, _TSCP( 512 ) ) );
L18350:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c14499 ) ) )  goto L18358;
        if  ( AND( EQ( TSCPIMMEDIATETAG( c14477 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 8210 ) ), 
                       CHARACTERTAG ) ) )  goto L18361;
        X2 = CONS( _TSCP( 8210 ), EMPTYLIST );
        scdebug_error( c12230, 
                       c12231, CONS( c14477, X2 ) );
L18361:
        X1 = BOOLEAN( EQ( _S2CINT( c14477 ), 
                          _S2CINT( _TSCP( 8210 ) ) ) );
        if  ( TRUE( X1 ) )  goto L18364;
        X2 = pregexp__2dchar_2a_cd905c7c_v;
        if  ( AND( EQ( TSCPIMMEDIATETAG( c14477 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( X2 ), CHARACTERTAG ) )
            )  goto L18367;
        X3 = CONS( X2, EMPTYLIST );
        scdebug_error( c12230, 
                       c12231, CONS( c14477, X3 ) );
L18367:
        POPSTACKTRACE( BOOLEAN( EQ( _S2CINT( c14477 ), 
                                    _S2CINT( X2 ) ) ) );
L18364:
        POPSTACKTRACE( X1 );
L18358:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c14503 ) ) )  goto L18369;
        if  ( EQ( TSCPIMMEDIATETAG( c14477 ), CHARACTERTAG ) )  goto L18372;
        scdebug_error( c12070, 
                       c12071, CONS( c14477, EMPTYLIST ) );
L18372:
        X1 = CHAR_FIX( c14477 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 128 ) ) ), 
                      3 ) )  goto L18375;
        POPSTACKTRACE( BOOLEAN( LT( _S2CINT( X1 ), 
                                    _S2CINT( _TSCP( 128 ) ) ) ) );
L18375:
        POPSTACKTRACE( scrt2__3c_2dtwo( X1, _TSCP( 128 ) ) );
L18369:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c12985 ) ) )  goto L18377;
        POPSTACKTRACE( scrt3_char_2dnumeric_3f( c14477 ) );
L18377:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c14510 ) ) )  goto L18379;
        if  ( EQ( TSCPIMMEDIATETAG( c14477 ), CHARACTERTAG ) )  goto L18382;
        scdebug_error( c12070, 
                       c12071, CONS( c14477, EMPTYLIST ) );
L18382:
        X2 = CHAR_FIX( c14477 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 128 ) ) ), 
                      3 ) )  goto L18385;
        X1 = BOOLEAN( GTE( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 128 ) ) ) );
        goto L18386;
L18385:
        X1 = scrt2__3e_3d_2dtwo( X2, _TSCP( 128 ) );
L18386:
        if  ( FALSE( X1 ) )  goto L18388;
        if  ( TRUE( scrt3_char_2dwhitespace_3f( c14477 ) ) )  goto L18390;
        POPSTACKTRACE( TRUEVALUE );
L18390:
        POPSTACKTRACE( FALSEVALUE );
L18388:
        POPSTACKTRACE( X1 );
L18379:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c14514 ) ) )  goto L18392;
        POPSTACKTRACE( scrt3_char_2dlower_2dcase_3f( c14477 ) );
L18392:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c14518 ) ) )  goto L18394;
        if  ( EQ( TSCPIMMEDIATETAG( c14477 ), CHARACTERTAG ) )  goto L18397;
        scdebug_error( c12070, 
                       c12071, CONS( c14477, EMPTYLIST ) );
L18397:
        X1 = CHAR_FIX( c14477 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 128 ) ) ), 
                      3 ) )  goto L18400;
        POPSTACKTRACE( BOOLEAN( GTE( _S2CINT( X1 ), 
                                     _S2CINT( _TSCP( 128 ) ) ) ) );
L18400:
        POPSTACKTRACE( scrt2__3e_3d_2dtwo( X1, _TSCP( 128 ) ) );
L18394:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c14522 ) ) )  goto L18402;
        if  ( EQ( TSCPIMMEDIATETAG( c14477 ), CHARACTERTAG ) )  goto L18405;
        scdebug_error( c12070, 
                       c12071, CONS( c14477, EMPTYLIST ) );
L18405:
        X2 = CHAR_FIX( c14477 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 128 ) ) ), 
                      3 ) )  goto L18408;
        X1 = BOOLEAN( GTE( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 128 ) ) ) );
        goto L18409;
L18408:
        X1 = scrt2__3e_3d_2dtwo( X2, _TSCP( 128 ) );
L18409:
        if  ( FALSE( X1 ) )  goto L18411;
        if  ( FALSE( scrt3_char_2dwhitespace_3f( c14477 ) ) )  goto L18413;
        X2 = FALSEVALUE;
        goto L18414;
L18413:
        X2 = TRUEVALUE;
L18414:
        if  ( FALSE( X2 ) )  goto L18416;
        if  ( FALSE( scrt3_char_2dalphabetic_3f( c14477 ) ) )  goto L18418;
        X3 = FALSEVALUE;
        goto L18419;
L18418:
        X3 = TRUEVALUE;
L18419:
        if  ( FALSE( X3 ) )  goto L18421;
        if  ( TRUE( scrt3_char_2dnumeric_3f( c14477 ) ) )  goto L18423;
        POPSTACKTRACE( TRUEVALUE );
L18423:
        POPSTACKTRACE( FALSEVALUE );
L18421:
        POPSTACKTRACE( X3 );
L18416:
        POPSTACKTRACE( X2 );
L18411:
        POPSTACKTRACE( X1 );
L18402:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c12951 ) ) )  goto L18425;
        POPSTACKTRACE( scrt3_char_2dwhitespace_3f( c14477 ) );
L18425:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c14529 ) ) )  goto L18427;
        POPSTACKTRACE( scrt3_char_2dupper_2dcase_3f( c14477 ) );
L18427:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c12925 ) ) )  goto L18429;
        X1 = scrt3_char_2dalphabetic_3f( c14477 );
        if  ( TRUE( X1 ) )  goto L18432;
        X2 = scrt3_char_2dnumeric_3f( c14477 );
        if  ( TRUE( X2 ) )  goto L18435;
        if  ( AND( EQ( TSCPIMMEDIATETAG( c14477 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 24338 ) ), 
                       CHARACTERTAG ) ) )  goto L18438;
        X3 = CONS( _TSCP( 24338 ), EMPTYLIST );
        scdebug_error( c12230, 
                       c12231, CONS( c14477, X3 ) );
L18438:
        POPSTACKTRACE( BOOLEAN( EQ( _S2CINT( c14477 ), 
                                    _S2CINT( _TSCP( 24338 ) ) ) ) );
L18435:
        POPSTACKTRACE( X2 );
L18432:
        POPSTACKTRACE( X1 );
L18429:
        if  ( NEQ( _S2CUINT( c14478 ), _S2CUINT( c14536 ) ) )  goto L18440;
        X1 = scrt3_char_2dnumeric_3f( c14477 );
        if  ( TRUE( X1 ) )  goto L18443;
        X2 = scrt3_char_2dci_3d_3f( c14477, _TSCP( 24850 ) );
        if  ( TRUE( X2 ) )  goto L18446;
        X3 = scrt3_char_2dci_3d_3f( c14477, _TSCP( 25106 ) );
        if  ( TRUE( X3 ) )  goto L18449;
        X4 = scrt3_char_2dci_3d_3f( c14477, _TSCP( 25362 ) );
        if  ( TRUE( X4 ) )  goto L18452;
        X5 = scrt3_char_2dci_3d_3f( c14477, _TSCP( 25618 ) );
        if  ( TRUE( X5 ) )  goto L18455;
        X6 = scrt3_char_2dci_3d_3f( c14477, _TSCP( 25874 ) );
        if  ( TRUE( X6 ) )  goto L18458;
        POPSTACKTRACE( scrt3_char_2dci_3d_3f( c14477, _TSCP( 26130 ) ) );
L18458:
        POPSTACKTRACE( X6 );
L18455:
        POPSTACKTRACE( X5 );
L18452:
        POPSTACKTRACE( X4 );
L18449:
        POPSTACKTRACE( X3 );
L18446:
        POPSTACKTRACE( X2 );
L18443:
        POPSTACKTRACE( X1 );
L18440:
        POPSTACKTRACE( pregexp_pregexp_2derror( CONS( c14537, 
                                                      EMPTYLIST ) ) );
}

DEFTSCP( pregexp_oundary_3f_80a8c00c_v );
DEFCSTRING( t18460, "PREGEXP-AT-WORD-BOUNDARY?" );

TSCP  pregexp_oundary_3f_80a8c00c( s14674, i14675, n14676 )
        TSCP  s14674, i14675, n14676;
{
        TSCP  X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t18460 );
        if  ( BITAND( BITOR( _S2CINT( i14675 ), 
                             _S2CINT( _TSCP( 0 ) ) ), 
                      3 ) )  goto L18462;
        X1 = BOOLEAN( EQ( _S2CUINT( i14675 ), 
                          _S2CUINT( _TSCP( 0 ) ) ) );
        goto L18463;
L18462:
        X1 = scrt2__3d_2dtwo( i14675, _TSCP( 0 ) );
L18463:
        if  ( TRUE( X1 ) )  goto L18465;
        if  ( BITAND( BITOR( _S2CINT( i14675 ), 
                             _S2CINT( n14676 ) ), 
                      3 ) )  goto L18467;
        X2 = BOOLEAN( GTE( _S2CINT( i14675 ), 
                           _S2CINT( n14676 ) ) );
        goto L18468;
L18467:
        X2 = scrt2__3e_3d_2dtwo( i14675, n14676 );
L18468:
        if  ( TRUE( X2 ) )  goto L18470;
        if  ( BITAND( BITOR( _S2CINT( i14675 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18472;
        X4 = _TSCP( IDIFFERENCE( _S2CINT( i14675 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L18473;
L18472:
        X4 = scrt2__2d_2dtwo( i14675, _TSCP( 4 ) );
L18473:
        if  ( EQ( TSCPTAG( X4 ), FIXNUMTAG ) )  goto L18475;
        scdebug_error( c12237, 
                       c12238, CONS( X4, EMPTYLIST ) );
L18475:
        X5 = BOOLEAN( LT( _S2CINT( X4 ), 0 ) );
        if  ( TRUE( X5 ) )  goto L18481;
        if  ( AND( EQ( TSCPTAG( s14674 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s14674 ), STRINGTAG ) )
            )  goto L18483;
        scdebug_error( c12259, 
                       c12260, CONS( s14674, EMPTYLIST ) );
L18483:
        X6 = C_FIXED( STRING_LENGTH( s14674 ) );
        if  ( BITAND( BITOR( _S2CINT( X4 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L18487;
        if  ( GTE( _S2CINT( X4 ), _S2CINT( X6 ) ) )  goto L18481;
        goto L18494;
L18487:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X4, X6 ) ) )  goto L18494;
L18481:
        scdebug_error( c12237, 
                       c12261, CONS( X4, EMPTYLIST ) );
L18494:
        X3 = C_CHAR( STRING_CHAR( s14674, X4 ) );
        if  ( EQ( TSCPTAG( i14675 ), FIXNUMTAG ) )  goto L18496;
        scdebug_error( c12237, 
                       c12238, CONS( i14675, EMPTYLIST ) );
L18496:
        X5 = BOOLEAN( LT( _S2CINT( i14675 ), 0 ) );
        if  ( TRUE( X5 ) )  goto L18502;
        if  ( AND( EQ( TSCPTAG( s14674 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s14674 ), STRINGTAG ) )
            )  goto L18504;
        scdebug_error( c12259, 
                       c12260, CONS( s14674, EMPTYLIST ) );
L18504:
        X6 = C_FIXED( STRING_LENGTH( s14674 ) );
        if  ( BITAND( BITOR( _S2CINT( i14675 ), 
                             _S2CINT( X6 ) ), 
                      3 ) )  goto L18508;
        if  ( GTE( _S2CINT( i14675 ), _S2CINT( X6 ) ) )  goto L18502;
        goto L18515;
L18508:
        if  ( FALSE( scrt2__3e_3d_2dtwo( i14675, X6 ) ) )  goto L18515;
L18502:
        scdebug_error( c12237, 
                       c12261, CONS( i14675, EMPTYLIST ) );
L18515:
        X4 = C_CHAR( STRING_CHAR( s14674, i14675 ) );
        X5 = pregexp_2dclass_3f_7022b0e( X3, c12925 );
        X6 = pregexp_2dclass_3f_7022b0e( X4, c12925 );
        if  ( FALSE( X6 ) )  goto L18518;
        if  ( FALSE( X5 ) )  goto L18520;
        X7 = FALSEVALUE;
        goto L18519;
L18520:
        X7 = TRUEVALUE;
        goto L18519;
L18518:
        X7 = X6;
L18519:
        if  ( TRUE( X7 ) )  goto L18523;
        if  ( FALSE( X6 ) )  goto L18525;
        X8 = FALSEVALUE;
        goto L18526;
L18525:
        X8 = TRUEVALUE;
L18526:
        if  ( TRUE( X8 ) )  goto L18528;
        POPSTACKTRACE( X8 );
L18528:
        POPSTACKTRACE( X5 );
L18523:
        POPSTACKTRACE( X7 );
L18470:
        POPSTACKTRACE( X2 );
L18465:
        POPSTACKTRACE( X1 );
}

DEFTSCP( pregexp_pregexp_2dlist_2dref_v );
DEFCSTRING( t18530, "PREGEXP-LIST-REF" );

TSCP  pregexp_pregexp_2dlist_2dref( s14775, i14776 )
        TSCP  s14775, i14776;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t18530 );
        X1 = s14775;
        X2 = _TSCP( 0 );
L18533:
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( EMPTYLIST ) ) )  goto L18534;
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( i14776 ) ), 
                      3 ) )  goto L18537;
        if  ( EQ( _S2CUINT( X2 ), _S2CUINT( i14776 ) ) )  goto L18541;
        goto L18542;
L18537:
        if  ( TRUE( scrt2__3d_2dtwo( X2, i14776 ) ) )  goto L18541;
        goto L18542;
L18534:
        POPSTACKTRACE( FALSEVALUE );
L18542:
        if  ( EQ( TSCPTAG( X1 ), PAIRTAG ) )  goto L18546;
        scrt1__24__cdr_2derror( X1 );
L18546:
        X3 = PAIR_CDR( X1 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18548;
        X2 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18549;
L18548:
        X2 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L18549:
        X1 = X3;
        GOBACK( L18533 );
L18541:
        if  ( EQ( TSCPTAG( X1 ), PAIRTAG ) )  goto L18551;
        scrt1__24__car_2derror( X1 );
L18551:
        POPSTACKTRACE( PAIR_CAR( X1 ) );
}

DEFTSCP( pregexp_ref_2dlist_bf9bf990_v );
DEFCSTRING( t18553, "PREGEXP-MAKE-BACKREF-LIST" );
EXTERNTSCPP( pregexp_s14818, XAL1( TSCP ) );
EXTERNTSCPP( scrt1_append_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_append_2dtwo_v );

TSCP  pregexp_s14818( r14820 )
        TSCP  r14820;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "SUB [inside PREGEXP-MAKE-BACKREF-LIST]" );
        if  ( NEQ( TSCPTAG( r14820 ), PAIRTAG ) )  goto L18557;
        X2 = PAIR_CDR( r14820 );
        X1 = pregexp_s14818( X2 );
        X2 = PAIR_CAR( r14820 );
        if  ( NOT( OR( EQ( _S2CUINT( X2 ), 
                           _S2CUINT( c14829 ) ), 
                       AND( EQ( TSCPTAG( X2 ), EXTENDEDTAG ), 
                            AND( EQ( TSCP_EXTENDEDTAG( X2 ), 
                                     DOUBLEFLOATTAG ), 
                                 AND( EQ( TSCPTAG( c14829 ), 
                                          EXTENDEDTAG ), 
                                      AND( EQ( TSCP_EXTENDEDTAG( c14829 ), 
                                               DOUBLEFLOATTAG ), 
                                           EQ( FLOAT_VALUE( X2 ), 
                                               FLOAT_VALUE( c14829 ) ) ) ) ) ) ) )
            )  goto L18562;
        X3 = sc_cons( r14820, FALSEVALUE );
        POPSTACKTRACE( sc_cons( X3, X1 ) );
L18562:
        X3 = pregexp_s14818( X2 );
        POPSTACKTRACE( scrt1_append_2dtwo( X3, X1 ) );
L18557:
        POPSTACKTRACE( EMPTYLIST );
}

TSCP  pregexp_ref_2dlist_bf9bf990( r14814 )
        TSCP  r14814;
{
        PUSHSTACKTRACE( t18553 );
        POPSTACKTRACE( pregexp_s14818( r14814 ) );
}

DEFTSCP( pregexp_ions_2daux_a110402e_v );
DEFCSTRING( t18564, "PREGEXP-MATCH-POSITIONS-AUX" );

TSCP  pregexp_i14847( x15567, c18566 )
        TSCP  x15567, c18566;
{
        PUSHSTACKTRACE( "IDENTITY [inside PREGEXP-MATCH-POSITIONS-AUX]" );
        POPSTACKTRACE( x15567 );
}

TSCP  pregexp__2414854( c18569 )
        TSCP  c18569;
{
        PUSHSTACKTRACE( "$_3 [inside PREGEXP-MATCH-POSITIONS-AUX]" );
        POPSTACKTRACE( FALSEVALUE );
}

EXTERNTSCPP( scrt3_char_3d_3f, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt3_char_3d_3f_v );
EXTERNTSCPP( scrt3_char_3c_3d_3f, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt3_char_3c_3d_3f_v );
EXTERNTSCPP( scrt3_char_2dci_3c_3d_3f, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt3_char_2dci_3c_3d_3f_v );
EXTERNTSCPP( pregexp_s14856, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCPP( pregexp_l15299, XAL2( TSCP, TSCP ) );

TSCP  pregexp_l15312( i15313, c18811 )
        TSCP  i15313, c18811;
{
        TSCP  X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15312 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c18811, 0 );
        X2 = DISPLAY( 6 );
        DISPLAY( 6 ) = CLOSURE_VAR( c18811, 1 );
        X3 = DISPLAY( 5 );
        DISPLAY( 5 ) = CLOSURE_VAR( c18811, 2 );
        X4 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c18811, 3 );
        X5 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c18811, 4 );
        X6 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c18811, 5 );
        X7 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c18811, 6 );
        X8 = DISPLAY( 10 );
        DISPLAY( 10 ) = CLOSURE_VAR( c18811, 7 );
        X9 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c18811, 8 );
        X10 = DISPLAY( 11 );
        DISPLAY( 11 ) = CLOSURE_VAR( c18811, 9 );
        X13 = DISPLAY( 11 );
        if  ( EQ( TSCPTAG( X13 ), PAIRTAG ) )  goto L18814;
        scrt1__24__cdr_2derror( X13 );
L18814:
        X12 = PAIR_CDR( X13 );
        X11 = pregexp_l15299( X12, i15313 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 6 ) = X2;
        DISPLAY( 5 ) = X3;
        DISPLAY( 4 ) = X4;
        DISPLAY( 0 ) = X5;
        DISPLAY( 3 ) = X6;
        DISPLAY( 2 ) = X7;
        DISPLAY( 10 ) = X8;
        DISPLAY( 9 ) = X9;
        DISPLAY( 11 ) = X10;
        POPSTACKTRACE( X11 );
}

TSCP  pregexp_l15299( r15301, i15302 )
        TSCP  r15301, i15302;
{
        TSCP  X2, X1;
        TSCP  SD11 = DISPLAY( 11 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "LOUP-SEQ [inside PREGEXP-MATCH-POSITIONS-AUX]" );
        DISPLAY( 11 ) = r15301;
        if  ( NEQ( _S2CUINT( DISPLAY( 11 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L18806;
        X1 = DISPLAY( 9 );
        X1 = UNKNOWNCALL( X1, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( i15302, 
                                             PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 11 ) = SD11;
        POPSTACKTRACE( SDVAL );
L18806:
        X2 = DISPLAY( 11 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L18809;
        scrt1__24__car_2derror( X2 );
L18809:
        X1 = PAIR_CAR( X2 );
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            pregexp_l15312, 
                            MAKECLOSURE( EMPTYLIST, 
                                         10, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 6 ), 
                                         DISPLAY( 5 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 10 ), 
                                         DISPLAY( 9 ), 
                                         DISPLAY( 11 ) ) );
        SDVAL = pregexp_s14856( X1, 
                                i15302, X2, DISPLAY( 10 ) );
        DISPLAY( 11 ) = SD11;
        POPSTACKTRACE( SDVAL );
}

EXTERNTSCPP( pregexp_l15264, XAL1( TSCP ) );

TSCP  pregexp_l15276( i15277, c18829 )
        TSCP  i15277, c18829;
{
        TSCP  X15, 
              X14, 
              X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15276 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c18829, 0 );
        X2 = DISPLAY( 6 );
        DISPLAY( 6 ) = CLOSURE_VAR( c18829, 1 );
        X3 = DISPLAY( 5 );
        DISPLAY( 5 ) = CLOSURE_VAR( c18829, 2 );
        X4 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c18829, 3 );
        X5 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c18829, 4 );
        X6 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c18829, 5 );
        X7 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c18829, 6 );
        X8 = DISPLAY( 8 );
        DISPLAY( 8 ) = CLOSURE_VAR( c18829, 7 );
        X9 = DISPLAY( 10 );
        DISPLAY( 10 ) = CLOSURE_VAR( c18829, 8 );
        X10 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c18829, 9 );
        X11 = DISPLAY( 11 );
        DISPLAY( 11 ) = CLOSURE_VAR( c18829, 10 );
        X14 = DISPLAY( 9 );
        X14 = UNKNOWNCALL( X14, 1 );
        X13 = VIA( PROCEDURE_CODE( X14 ) )( i15277, 
                                            PROCEDURE_CLOSURE( X14 ) );
        if  ( FALSE( X13 ) )  goto L18832;
        X12 = X13;
        goto L18833;
L18832:
        X15 = DISPLAY( 11 );
        if  ( EQ( TSCPTAG( X15 ), PAIRTAG ) )  goto L18835;
        scrt1__24__cdr_2derror( X15 );
L18835:
        X14 = PAIR_CDR( X15 );
        X12 = pregexp_l15264( X14 );
L18833:
        DISPLAY( 1 ) = X1;
        DISPLAY( 6 ) = X2;
        DISPLAY( 5 ) = X3;
        DISPLAY( 4 ) = X4;
        DISPLAY( 0 ) = X5;
        DISPLAY( 3 ) = X6;
        DISPLAY( 2 ) = X7;
        DISPLAY( 8 ) = X8;
        DISPLAY( 10 ) = X9;
        DISPLAY( 9 ) = X10;
        DISPLAY( 11 ) = X11;
        POPSTACKTRACE( X12 );
}

TSCP  pregexp_l15286( c18837 )
        TSCP  c18837;
{
        TSCP  X14, 
              X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15286 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c18837, 0 );
        X2 = DISPLAY( 6 );
        DISPLAY( 6 ) = CLOSURE_VAR( c18837, 1 );
        X3 = DISPLAY( 5 );
        DISPLAY( 5 ) = CLOSURE_VAR( c18837, 2 );
        X4 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c18837, 3 );
        X5 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c18837, 4 );
        X6 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c18837, 5 );
        X7 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c18837, 6 );
        X8 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c18837, 7 );
        X9 = DISPLAY( 8 );
        DISPLAY( 8 ) = CLOSURE_VAR( c18837, 8 );
        X10 = DISPLAY( 10 );
        DISPLAY( 10 ) = CLOSURE_VAR( c18837, 9 );
        X11 = DISPLAY( 11 );
        DISPLAY( 11 ) = CLOSURE_VAR( c18837, 10 );
        X14 = DISPLAY( 11 );
        if  ( EQ( TSCPTAG( X14 ), PAIRTAG ) )  goto L18840;
        scrt1__24__cdr_2derror( X14 );
L18840:
        X13 = PAIR_CDR( X14 );
        X12 = pregexp_l15264( X13 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 6 ) = X2;
        DISPLAY( 5 ) = X3;
        DISPLAY( 4 ) = X4;
        DISPLAY( 0 ) = X5;
        DISPLAY( 3 ) = X6;
        DISPLAY( 2 ) = X7;
        DISPLAY( 9 ) = X8;
        DISPLAY( 8 ) = X9;
        DISPLAY( 10 ) = X10;
        DISPLAY( 11 ) = X11;
        POPSTACKTRACE( X12 );
}

TSCP  pregexp_l15264( r15266 )
        TSCP  r15266;
{
        TSCP  X3, X2, X1;
        TSCP  SD11 = DISPLAY( 11 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "LOUP-OR [inside PREGEXP-MATCH-POSITIONS-AUX]" );
        DISPLAY( 11 ) = r15266;
        if  ( NEQ( _S2CUINT( DISPLAY( 11 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L18824;
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 11 ) = SD11;
        POPSTACKTRACE( SDVAL );
L18824:
        X2 = DISPLAY( 11 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L18827;
        scrt1__24__car_2derror( X2 );
L18827:
        X1 = PAIR_CAR( X2 );
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            pregexp_l15276, 
                            MAKECLOSURE( EMPTYLIST, 
                                         11, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 6 ), 
                                         DISPLAY( 5 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 8 ), 
                                         DISPLAY( 10 ), 
                                         DISPLAY( 9 ), 
                                         DISPLAY( 11 ) ) );
        X3 = MAKEPROCEDURE( 0, 
                            0, 
                            pregexp_l15286, 
                            MAKECLOSURE( EMPTYLIST, 
                                         11, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 6 ), 
                                         DISPLAY( 5 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 9 ), 
                                         DISPLAY( 8 ), 
                                         DISPLAY( 10 ), 
                                         DISPLAY( 11 ) ) );
        SDVAL = pregexp_s14856( X1, DISPLAY( 8 ), X2, X3 );
        DISPLAY( 11 ) = SD11;
        POPSTACKTRACE( SDVAL );
}

EXTERNTSCPP( scrt3_substring, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt3_substring_v );

TSCP  pregexp_l15241( i15242, c18865 )
        TSCP  i15242, c18865;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15241 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c18865, 0 );
        X3 = DISPLAY( 9 );
        X3 = UNKNOWNCALL( X3, 1 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( i15242, 
                                          PROCEDURE_CLOSURE( X3 ) );
        DISPLAY( 9 ) = X1;
        POPSTACKTRACE( X2 );
}

EXTERNTSCPP( scrt1_assv, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_assv_v );

TSCP  pregexp_l15222( i15223, c18876 )
        TSCP  i15223, c18876;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15222 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 5 );
        DISPLAY( 5 ) = CLOSURE_VAR( c18876, 0 );
        X2 = DISPLAY( 7 );
        DISPLAY( 7 ) = CLOSURE_VAR( c18876, 1 );
        X3 = DISPLAY( 8 );
        DISPLAY( 8 ) = CLOSURE_VAR( c18876, 2 );
        X4 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c18876, 3 );
        X6 = sc_cons( DISPLAY( 8 ), i15223 );
        X7 = scrt1_assv( DISPLAY( 7 ), DISPLAY( 5 ) );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L18879;
        scdebug_error( c12162, 
                       c12163, CONS( X7, EMPTYLIST ) );
L18879:
        SETGEN( PAIR_CDR( X7 ), X6 );
        X6 = DISPLAY( 9 );
        X6 = UNKNOWNCALL( X6, 1 );
        X5 = VIA( PROCEDURE_CODE( X6 ) )( i15223, 
                                          PROCEDURE_CLOSURE( X6 ) );
        DISPLAY( 5 ) = X1;
        DISPLAY( 7 ) = X2;
        DISPLAY( 8 ) = X3;
        DISPLAY( 9 ) = X4;
        POPSTACKTRACE( X5 );
}

TSCP  pregexp_l15211( c18892 )
        TSCP  c18892;
{
        PUSHSTACKTRACE( "pregexp_l15211 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        POPSTACKTRACE( FALSEVALUE );
}

TSCP  pregexp_l15198( c18905 )
        TSCP  c18905;
{
        PUSHSTACKTRACE( "pregexp_l15198 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        POPSTACKTRACE( FALSEVALUE );
}

TSCP  pregexp_l15185( c18918 )
        TSCP  c18918;
{
        PUSHSTACKTRACE( "pregexp_l15185 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        POPSTACKTRACE( FALSEVALUE );
}

TSCP  pregexp_l15167( c18934 )
        TSCP  c18934;
{
        PUSHSTACKTRACE( "pregexp_l15167 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        POPSTACKTRACE( FALSEVALUE );
}

TSCP  pregexp_l15148( c18948 )
        TSCP  c18948;
{
        PUSHSTACKTRACE( "pregexp_l15148 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        POPSTACKTRACE( FALSEVALUE );
}

TSCP  pregexp_l15133( i15134, c18966 )
        TSCP  i15134, c18966;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15133 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 11 );
        DISPLAY( 11 ) = CLOSURE_VAR( c18966, 0 );
        X2 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c18966, 1 );
        X3 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c18966, 2 );
        X5 = DISPLAY( 11 );
        SETGEN( PAIR_CAR( DISPLAY( 4 ) ), X5 );
        X5 = DISPLAY( 9 );
        X5 = UNKNOWNCALL( X5, 1 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( i15134, 
                                          PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 11 ) = X1;
        DISPLAY( 4 ) = X2;
        DISPLAY( 9 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  pregexp_l15135( c18968 )
        TSCP  c18968;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15135 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 11 );
        DISPLAY( 11 ) = CLOSURE_VAR( c18968, 0 );
        X2 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c18968, 1 );
        X3 = DISPLAY( 10 );
        DISPLAY( 10 ) = CLOSURE_VAR( c18968, 2 );
        X5 = DISPLAY( 11 );
        SETGEN( PAIR_CAR( DISPLAY( 4 ) ), X5 );
        X5 = DISPLAY( 10 );
        X5 = UNKNOWNCALL( X5, 0 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 11 ) = X1;
        DISPLAY( 4 ) = X2;
        DISPLAY( 10 ) = X3;
        POPSTACKTRACE( X4 );
}

EXTERNTSCPP( scrt1_cadddr, XAL1( TSCP ) );
EXTERNTSCP( scrt1_cadddr_v );
EXTERNTSCPP( scrt1_cddddr, XAL1( TSCP ) );
EXTERNTSCP( scrt1_cddddr_v );
EXTERNTSCPP( pregexp_l14994, XAL2( TSCP, TSCP ) );

TSCP  pregexp_l15075( i15076, c19007 )
        TSCP  i15076, c19007;
{
        TSCP  X19, 
              X18, 
              X17, 
              X16, 
              X15, 
              X14, 
              X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15075 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c19007, 0 );
        X2 = DISPLAY( 6 );
        DISPLAY( 6 ) = CLOSURE_VAR( c19007, 1 );
        X3 = DISPLAY( 5 );
        DISPLAY( 5 ) = CLOSURE_VAR( c19007, 2 );
        X4 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c19007, 3 );
        X5 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c19007, 4 );
        X6 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c19007, 5 );
        X7 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c19007, 6 );
        X8 = DISPLAY( 13 );
        DISPLAY( 13 ) = CLOSURE_VAR( c19007, 7 );
        X9 = DISPLAY( 12 );
        DISPLAY( 12 ) = CLOSURE_VAR( c19007, 8 );
        X10 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c19007, 9 );
        X11 = DISPLAY( 11 );
        DISPLAY( 11 ) = CLOSURE_VAR( c19007, 10 );
        X12 = DISPLAY( 10 );
        DISPLAY( 10 ) = CLOSURE_VAR( c19007, 11 );
        X13 = DISPLAY( 15 );
        DISPLAY( 15 ) = CLOSURE_VAR( c19007, 12 );
        X14 = DISPLAY( 17 );
        DISPLAY( 17 ) = CLOSURE_VAR( c19007, 13 );
        X15 = DISPLAY( 14 );
        DISPLAY( 14 ) = CLOSURE_VAR( c19007, 14 );
        X16 = DISPLAY( 16 );
        DISPLAY( 16 ) = CLOSURE_VAR( c19007, 15 );
        if  ( FALSE( DISPLAY( 14 ) ) )  goto L19020;
        X18 = DISPLAY( 17 );
        if  ( BITAND( BITOR( _S2CINT( i15076 ), 
                             _S2CINT( X18 ) ), 
                      3 ) )  goto L19013;
        if  ( EQ( _S2CUINT( i15076 ), _S2CUINT( X18 ) ) )  goto L19017;
        goto L19020;
L19013:
        if  ( FALSE( scrt2__3d_2dtwo( i15076, X18 ) ) )  goto L19020;
L19017:
        X19 = CONS( c15053, EMPTYLIST );
        pregexp_pregexp_2derror( CONS( c14932, X19 ) );
L19020:
        X19 = DISPLAY( 16 );
        if  ( BITAND( BITOR( _S2CINT( X19 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19022;
        X18 = _TSCP( IPLUS( _S2CINT( X19 ), 
                            _S2CINT( _TSCP( 4 ) ) ) );
        goto L19023;
L19022:
        X18 = scrt2__2b_2dtwo( X19, _TSCP( 4 ) );
L19023:
        X17 = pregexp_l14994( X18, i15076 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 6 ) = X2;
        DISPLAY( 5 ) = X3;
        DISPLAY( 4 ) = X4;
        DISPLAY( 0 ) = X5;
        DISPLAY( 3 ) = X6;
        DISPLAY( 2 ) = X7;
        DISPLAY( 13 ) = X8;
        DISPLAY( 12 ) = X9;
        DISPLAY( 9 ) = X10;
        DISPLAY( 11 ) = X11;
        DISPLAY( 10 ) = X12;
        DISPLAY( 15 ) = X13;
        DISPLAY( 17 ) = X14;
        DISPLAY( 14 ) = X15;
        DISPLAY( 16 ) = X16;
        POPSTACKTRACE( X17 );
}

TSCP  pregexp_f15015( c19034 )
        TSCP  c19034;
{
        TSCP  X4, X3, X2, X1;

        PUSHSTACKTRACE( "FK [inside PREGEXP-MATCH-POSITIONS-AUX]" );
        X1 = DISPLAY( 20 );
        DISPLAY( 20 ) = CLOSURE_VAR( c19034, 0 );
        X2 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c19034, 1 );
        X4 = DISPLAY( 9 );
        X4 = UNKNOWNCALL( X4, 1 );
        X3 = VIA( PROCEDURE_CODE( X4 ) )( DISPLAY( 20 ), 
                                          PROCEDURE_CLOSURE( X4 ) );
        DISPLAY( 20 ) = X1;
        DISPLAY( 9 ) = X2;
        POPSTACKTRACE( X3 );
}

EXTERNTSCPP( pregexp_l15010, XAL2( TSCP, TSCP ) );

TSCP  pregexp_l15038( i15039, c19054 )
        TSCP  i15039, c19054;
{
        TSCP  X19, 
              X18, 
              X17, 
              X16, 
              X15, 
              X14, 
              X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15038 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c19054, 0 );
        X2 = DISPLAY( 6 );
        DISPLAY( 6 ) = CLOSURE_VAR( c19054, 1 );
        X3 = DISPLAY( 5 );
        DISPLAY( 5 ) = CLOSURE_VAR( c19054, 2 );
        X4 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c19054, 3 );
        X5 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c19054, 4 );
        X6 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c19054, 5 );
        X7 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c19054, 6 );
        X8 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c19054, 7 );
        X9 = DISPLAY( 15 );
        DISPLAY( 15 ) = CLOSURE_VAR( c19054, 8 );
        X10 = DISPLAY( 11 );
        DISPLAY( 11 ) = CLOSURE_VAR( c19054, 9 );
        X11 = DISPLAY( 18 );
        DISPLAY( 18 ) = CLOSURE_VAR( c19054, 10 );
        X12 = DISPLAY( 20 );
        DISPLAY( 20 ) = CLOSURE_VAR( c19054, 11 );
        X13 = DISPLAY( 14 );
        DISPLAY( 14 ) = CLOSURE_VAR( c19054, 12 );
        X14 = DISPLAY( 19 );
        DISPLAY( 19 ) = CLOSURE_VAR( c19054, 13 );
        X15 = DISPLAY( 21 );
        DISPLAY( 21 ) = CLOSURE_VAR( c19054, 14 );
        if  ( FALSE( DISPLAY( 14 ) ) )  goto L19067;
        X17 = DISPLAY( 20 );
        if  ( BITAND( BITOR( _S2CINT( i15039 ), 
                             _S2CINT( X17 ) ), 
                      3 ) )  goto L19060;
        if  ( EQ( _S2CUINT( i15039 ), _S2CUINT( X17 ) ) )  goto L19064;
        goto L19067;
L19060:
        if  ( FALSE( scrt2__3d_2dtwo( i15039, X17 ) ) )  goto L19067;
L19064:
        X18 = CONS( c15053, EMPTYLIST );
        pregexp_pregexp_2derror( CONS( c14932, X18 ) );
L19067:
        X19 = DISPLAY( 19 );
        if  ( BITAND( BITOR( _S2CINT( X19 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19069;
        X18 = _TSCP( IPLUS( _S2CINT( X19 ), 
                            _S2CINT( _TSCP( 4 ) ) ) );
        goto L19070;
L19069:
        X18 = scrt2__2b_2dtwo( X19, _TSCP( 4 ) );
L19070:
        X17 = pregexp_l15010( X18, i15039 );
        if  ( FALSE( X17 ) )  goto L19072;
        X16 = X17;
        goto L19073;
L19072:
        X16 = pregexp_f15015( PROCEDURE_CLOSURE( DISPLAY( 21 ) ) );
L19073:
        DISPLAY( 1 ) = X1;
        DISPLAY( 6 ) = X2;
        DISPLAY( 5 ) = X3;
        DISPLAY( 4 ) = X4;
        DISPLAY( 0 ) = X5;
        DISPLAY( 3 ) = X6;
        DISPLAY( 2 ) = X7;
        DISPLAY( 9 ) = X8;
        DISPLAY( 15 ) = X9;
        DISPLAY( 11 ) = X10;
        DISPLAY( 18 ) = X11;
        DISPLAY( 20 ) = X12;
        DISPLAY( 14 ) = X13;
        DISPLAY( 19 ) = X14;
        DISPLAY( 21 ) = X15;
        POPSTACKTRACE( X16 );
}

TSCP  pregexp_l15030( i15031, c19077 )
        TSCP  i15031, c19077;
{
        TSCP  X16, 
              X15, 
              X14, 
              X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15030 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c19077, 0 );
        X2 = DISPLAY( 6 );
        DISPLAY( 6 ) = CLOSURE_VAR( c19077, 1 );
        X3 = DISPLAY( 5 );
        DISPLAY( 5 ) = CLOSURE_VAR( c19077, 2 );
        X4 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c19077, 3 );
        X5 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c19077, 4 );
        X6 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c19077, 5 );
        X7 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c19077, 6 );
        X8 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c19077, 7 );
        X9 = DISPLAY( 14 );
        DISPLAY( 14 ) = CLOSURE_VAR( c19077, 8 );
        X10 = DISPLAY( 15 );
        DISPLAY( 15 ) = CLOSURE_VAR( c19077, 9 );
        X11 = DISPLAY( 11 );
        DISPLAY( 11 ) = CLOSURE_VAR( c19077, 10 );
        X12 = DISPLAY( 18 );
        DISPLAY( 18 ) = CLOSURE_VAR( c19077, 11 );
        X13 = DISPLAY( 19 );
        DISPLAY( 19 ) = CLOSURE_VAR( c19077, 12 );
        X16 = DISPLAY( 19 );
        if  ( BITAND( BITOR( _S2CINT( X16 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19080;
        X15 = _TSCP( IPLUS( _S2CINT( X16 ), 
                            _S2CINT( _TSCP( 4 ) ) ) );
        goto L19081;
L19080:
        X15 = scrt2__2b_2dtwo( X16, _TSCP( 4 ) );
L19081:
        X14 = pregexp_l15010( X15, i15031 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 6 ) = X2;
        DISPLAY( 5 ) = X3;
        DISPLAY( 4 ) = X4;
        DISPLAY( 0 ) = X5;
        DISPLAY( 3 ) = X6;
        DISPLAY( 2 ) = X7;
        DISPLAY( 9 ) = X8;
        DISPLAY( 14 ) = X9;
        DISPLAY( 15 ) = X10;
        DISPLAY( 11 ) = X11;
        DISPLAY( 18 ) = X12;
        DISPLAY( 19 ) = X13;
        POPSTACKTRACE( X14 );
}

TSCP  pregexp_l15010( k15012, i15013 )
        TSCP  k15012, i15013;
{
        TSCP  X3, X2, X1;
        TSCP  SD19 = DISPLAY( 19 );
        TSCP  SD20 = DISPLAY( 20 );
        TSCP  SD21 = DISPLAY( 21 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "LOUP-Q [inside PREGEXP-MATCH-POSITIONS-AUX]" );
        DISPLAY( 19 ) = k15012;
        DISPLAY( 20 ) = i15013;
        DISPLAY( 21 ) = MAKEPROCEDURE( 0, 
                                       0, 
                                       pregexp_f15015, 
                                       MAKECLOSURE( EMPTYLIST, 
                                                    2, 
                                                    DISPLAY( 20 ), 
                                                    DISPLAY( 9 ) ) );
        X1 = DISPLAY( 18 );
        if  ( FALSE( X1 ) )  goto L19051;
        X2 = DISPLAY( 19 );
        X3 = DISPLAY( 18 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L19043;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X3 ) ) )  goto L19047;
        goto L19051;
L19043:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X2, X3 ) ) )  goto L19051;
L19047:
        SDVAL = pregexp_f15015( PROCEDURE_CLOSURE( DISPLAY( 21 ) ) );
        DISPLAY( 19 ) = SD19;
        DISPLAY( 20 ) = SD20;
        DISPLAY( 21 ) = SD21;
        POPSTACKTRACE( SDVAL );
L19051:
        if  ( FALSE( DISPLAY( 11 ) ) )  goto L19052;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            pregexp_l15038, 
                            MAKECLOSURE( EMPTYLIST, 
                                         15, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 6 ), 
                                         DISPLAY( 5 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 9 ), 
                                         DISPLAY( 15 ), 
                                         DISPLAY( 11 ), 
                                         DISPLAY( 18 ), 
                                         DISPLAY( 20 ), 
                                         DISPLAY( 14 ), 
                                         DISPLAY( 19 ), 
                                         DISPLAY( 21 ) ) );
        SDVAL = pregexp_s14856( DISPLAY( 15 ), 
                                DISPLAY( 20 ), 
                                X1, DISPLAY( 21 ) );
        DISPLAY( 19 ) = SD19;
        DISPLAY( 20 ) = SD20;
        DISPLAY( 21 ) = SD21;
        POPSTACKTRACE( SDVAL );
L19052:
        X1 = pregexp_f15015( PROCEDURE_CLOSURE( DISPLAY( 21 ) ) );
        if  ( TRUE( X1 ) )  goto L19075;
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            pregexp_l15030, 
                            MAKECLOSURE( EMPTYLIST, 
                                         13, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 6 ), 
                                         DISPLAY( 5 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 9 ), 
                                         DISPLAY( 14 ), 
                                         DISPLAY( 15 ), 
                                         DISPLAY( 11 ), 
                                         DISPLAY( 18 ), 
                                         DISPLAY( 19 ) ) );
        SDVAL = pregexp_s14856( DISPLAY( 15 ), 
                                DISPLAY( 20 ), 
                                X2, DISPLAY( 21 ) );
        DISPLAY( 19 ) = SD19;
        DISPLAY( 20 ) = SD20;
        DISPLAY( 21 ) = SD21;
        POPSTACKTRACE( SDVAL );
L19075:
        SDVAL = X1;
        DISPLAY( 19 ) = SD19;
        DISPLAY( 20 ) = SD20;
        DISPLAY( 21 ) = SD21;
        POPSTACKTRACE( SDVAL );
}

TSCP  pregexp_l14994( k14996, i14997 )
        TSCP  k14996, i14997;
{
        TSCP  X3, X2, X1;
        TSCP  SD16 = DISPLAY( 16 );
        TSCP  SD17 = DISPLAY( 17 );
        TSCP  SD18 = DISPLAY( 18 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "LOUP-P [inside PREGEXP-MATCH-POSITIONS-AUX]" );
        DISPLAY( 16 ) = k14996;
        DISPLAY( 17 ) = i14997;
        X1 = DISPLAY( 16 );
        X2 = DISPLAY( 12 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L18999;
        if  ( LT( _S2CINT( X1 ), _S2CINT( X2 ) ) )  goto L19003;
        goto L19004;
L18999:
        if  ( FALSE( scrt2__3c_2dtwo( X1, X2 ) ) )  goto L19004;
L19003:
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            pregexp_l15075, 
                            MAKECLOSURE( EMPTYLIST, 
                                         16, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 6 ), 
                                         DISPLAY( 5 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 13 ), 
                                         DISPLAY( 12 ), 
                                         DISPLAY( 9 ), 
                                         DISPLAY( 11 ), 
                                         DISPLAY( 10 ), 
                                         DISPLAY( 15 ), 
                                         DISPLAY( 17 ), 
                                         DISPLAY( 14 ), 
                                         DISPLAY( 16 ) ) );
        SDVAL = pregexp_s14856( DISPLAY( 15 ), 
                                DISPLAY( 17 ), 
                                X1, DISPLAY( 10 ) );
        DISPLAY( 16 ) = SD16;
        DISPLAY( 17 ) = SD17;
        DISPLAY( 18 ) = SD18;
        POPSTACKTRACE( SDVAL );
L19004:
        X1 = DISPLAY( 13 );
        if  ( FALSE( X1 ) )  goto L19025;
        X2 = DISPLAY( 12 );
        X3 = DISPLAY( 13 );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L19028;
        DISPLAY( 18 ) = _TSCP( IDIFFERENCE( _S2CINT( X3 ), 
                                            _S2CINT( X2 ) ) );
        goto L19026;
L19028:
        DISPLAY( 18 ) = scrt2__2d_2dtwo( X3, X2 );
        goto L19026;
L19025:
        DISPLAY( 18 ) = X1;
L19026:
        X1 = DISPLAY( 17 );
        SDVAL = pregexp_l15010( _TSCP( 0 ), X1 );
        DISPLAY( 16 ) = SD16;
        DISPLAY( 17 ) = SD17;
        DISPLAY( 18 ) = SD18;
        POPSTACKTRACE( SDVAL );
}

EXTERNTSCPP( pregexp_l15356, XAL1( TSCP ) );

TSCP  pregexp_l15368( c19103 )
        TSCP  c19103;
{
        TSCP  X14, 
              X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15368 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c19103, 0 );
        X2 = DISPLAY( 6 );
        DISPLAY( 6 ) = CLOSURE_VAR( c19103, 1 );
        X3 = DISPLAY( 5 );
        DISPLAY( 5 ) = CLOSURE_VAR( c19103, 2 );
        X4 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c19103, 3 );
        X5 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c19103, 4 );
        X6 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c19103, 5 );
        X7 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c19103, 6 );
        X8 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c19103, 7 );
        X9 = DISPLAY( 8 );
        DISPLAY( 8 ) = CLOSURE_VAR( c19103, 8 );
        X10 = DISPLAY( 10 );
        DISPLAY( 10 ) = CLOSURE_VAR( c19103, 9 );
        X11 = DISPLAY( 11 );
        DISPLAY( 11 ) = CLOSURE_VAR( c19103, 10 );
        X14 = DISPLAY( 11 );
        if  ( EQ( TSCPTAG( X14 ), PAIRTAG ) )  goto L19106;
        scrt1__24__cdr_2derror( X14 );
L19106:
        X13 = PAIR_CDR( X14 );
        X12 = pregexp_l15356( X13 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 6 ) = X2;
        DISPLAY( 5 ) = X3;
        DISPLAY( 4 ) = X4;
        DISPLAY( 0 ) = X5;
        DISPLAY( 3 ) = X6;
        DISPLAY( 2 ) = X7;
        DISPLAY( 9 ) = X8;
        DISPLAY( 8 ) = X9;
        DISPLAY( 10 ) = X10;
        DISPLAY( 11 ) = X11;
        POPSTACKTRACE( X12 );
}

TSCP  pregexp_l15356( c15358 )
        TSCP  c15358;
{
        TSCP  X2, X1;
        TSCP  SD11 = DISPLAY( 11 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "LOUP-ONE-OF-CHARS [inside PREGEXP-MATCH-POSITIONS-A\
UX]" );
        DISPLAY( 11 ) = c15358;
        if  ( NEQ( _S2CUINT( DISPLAY( 11 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L19098;
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 11 ) = SD11;
        POPSTACKTRACE( SDVAL );
L19098:
        X2 = DISPLAY( 11 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L19101;
        scrt1__24__car_2derror( X2 );
L19101:
        X1 = PAIR_CAR( X2 );
        X2 = MAKEPROCEDURE( 0, 
                            0, 
                            pregexp_l15368, 
                            MAKECLOSURE( EMPTYLIST, 
                                         11, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 6 ), 
                                         DISPLAY( 5 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 9 ), 
                                         DISPLAY( 8 ), 
                                         DISPLAY( 10 ), 
                                         DISPLAY( 11 ) ) );
        SDVAL = pregexp_s14856( X1, 
                                DISPLAY( 8 ), 
                                DISPLAY( 9 ), X2 );
        DISPLAY( 11 ) = SD11;
        POPSTACKTRACE( SDVAL );
}

TSCP  pregexp_l15338( i15339, c19115 )
        TSCP  i15339, c19115;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15338 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 10 );
        DISPLAY( 10 ) = CLOSURE_VAR( c19115, 0 );
        X3 = DISPLAY( 10 );
        X3 = UNKNOWNCALL( X3, 0 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( PROCEDURE_CLOSURE( X3 ) );
        DISPLAY( 10 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  pregexp_l15340( c19117 )
        TSCP  c19117;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "pregexp_l15340 [inside PREGEXP-MATCH-POSITIONS-AUX]\
" );
        X1 = DISPLAY( 8 );
        DISPLAY( 8 ) = CLOSURE_VAR( c19117, 0 );
        X2 = DISPLAY( 9 );
        DISPLAY( 9 ) = CLOSURE_VAR( c19117, 1 );
        X6 = DISPLAY( 8 );
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19120;
        X5 = _TSCP( IPLUS( _S2CINT( X6 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L19121;
L19120:
        X5 = scrt2__2b_2dtwo( X6, _TSCP( 4 ) );
L19121:
        X4 = DISPLAY( 9 );
        X4 = UNKNOWNCALL( X4, 1 );
        X3 = VIA( PROCEDURE_CODE( X4 ) )( X5, 
                                          PROCEDURE_CLOSURE( X4 ) );
        DISPLAY( 8 ) = X1;
        DISPLAY( 9 ) = X2;
        POPSTACKTRACE( X3 );
}

TSCP  pregexp_s14856( r14858, i14859, s14860, f14861 )
        TSCP  r14858, i14859, s14860, f14861;
{
        TSCP  X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;
        TSCP  SD7 = DISPLAY( 7 );
        TSCP  SD8 = DISPLAY( 8 );
        TSCP  SD9 = DISPLAY( 9 );
        TSCP  SD10 = DISPLAY( 10 );
        TSCP  SD11 = DISPLAY( 11 );
        TSCP  SD12 = DISPLAY( 12 );
        TSCP  SD13 = DISPLAY( 13 );
        TSCP  SD14 = DISPLAY( 14 );
        TSCP  SD15 = DISPLAY( 15 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "SUB [inside PREGEXP-MATCH-POSITIONS-AUX]" );
        DISPLAY( 7 ) = r14858;
        DISPLAY( 8 ) = i14859;
        DISPLAY( 9 ) = s14860;
        DISPLAY( 10 ) = f14861;
L18573:
        if  ( NOT( OR( EQ( _S2CUINT( DISPLAY( 7 ) ), 
                           _S2CUINT( c12689 ) ), 
                       AND( EQ( TSCPTAG( DISPLAY( 7 ) ), 
                                EXTENDEDTAG ), 
                            AND( EQ( TSCP_EXTENDEDTAG( DISPLAY( 7 ) ), 
                                     DOUBLEFLOATTAG ), 
                                 AND( EQ( TSCPTAG( c12689 ), 
                                          EXTENDEDTAG ), 
                                      AND( EQ( TSCP_EXTENDEDTAG( c12689 ), 
                                               DOUBLEFLOATTAG ), 
                                           EQ( FLOAT_VALUE( DISPLAY( 7 ) ), 
                                               FLOAT_VALUE( c12689 ) ) ) ) ) ) ) )
            )  goto L18574;
        X1 = DISPLAY( 2 );
        X2 = DISPLAY( 8 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L18578;
        if  ( EQ( _S2CUINT( X2 ), _S2CUINT( X1 ) ) )  goto L18582;
        goto L18583;
L18578:
        if  ( TRUE( scrt2__3d_2dtwo( X2, X1 ) ) )  goto L18582;
        goto L18583;
L18574:
        if  ( NOT( OR( EQ( _S2CUINT( DISPLAY( 7 ) ), 
                           _S2CUINT( c12680 ) ), 
                       AND( EQ( TSCPTAG( DISPLAY( 7 ) ), 
                                EXTENDEDTAG ), 
                            AND( EQ( TSCP_EXTENDEDTAG( DISPLAY( 7 ) ), 
                                     DOUBLEFLOATTAG ), 
                                 AND( EQ( TSCPTAG( c12680 ), 
                                          EXTENDEDTAG ), 
                                      AND( EQ( TSCP_EXTENDEDTAG( c12680 ), 
                                               DOUBLEFLOATTAG ), 
                                           EQ( FLOAT_VALUE( DISPLAY( 7 ) ), 
                                               FLOAT_VALUE( c12680 ) ) ) ) ) ) ) )
            )  goto L18586;
        X1 = DISPLAY( 8 );
        X2 = PAIR_CAR( DISPLAY( 3 ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L18590;
        if  ( GTE( _S2CINT( X1 ), _S2CINT( X2 ) ) )  goto L18594;
        goto L18595;
L18590:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X1, X2 ) ) )  goto L18594;
        goto L18595;
L18586:
        if  ( NOT( OR( EQ( _S2CUINT( DISPLAY( 7 ) ), 
                           _S2CUINT( c12481 ) ), 
                       AND( EQ( TSCPTAG( DISPLAY( 7 ) ), 
                                EXTENDEDTAG ), 
                            AND( EQ( TSCP_EXTENDEDTAG( DISPLAY( 7 ) ), 
                                     DOUBLEFLOATTAG ), 
                                 AND( EQ( TSCPTAG( c12481 ), 
                                          EXTENDEDTAG ), 
                                      AND( EQ( TSCP_EXTENDEDTAG( c12481 ), 
                                               DOUBLEFLOATTAG ), 
                                           EQ( FLOAT_VALUE( DISPLAY( 7 ) ), 
                                               FLOAT_VALUE( c12481 ) ) ) ) ) ) ) )
            )  goto L18598;
        X1 = DISPLAY( 9 );
        X1 = UNKNOWNCALL( X1, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( DISPLAY( 8 ), 
                                             PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18598:
        if  ( NOT( OR( EQ( _S2CUINT( DISPLAY( 7 ) ), 
                           _S2CUINT( c13003 ) ), 
                       AND( EQ( TSCPTAG( DISPLAY( 7 ) ), 
                                EXTENDEDTAG ), 
                            AND( EQ( TSCP_EXTENDEDTAG( DISPLAY( 7 ) ), 
                                     DOUBLEFLOATTAG ), 
                                 AND( EQ( TSCPTAG( c13003 ), 
                                          EXTENDEDTAG ), 
                                      AND( EQ( TSCP_EXTENDEDTAG( c13003 ), 
                                               DOUBLEFLOATTAG ), 
                                           EQ( FLOAT_VALUE( DISPLAY( 7 ) ), 
                                               FLOAT_VALUE( c13003 ) ) ) ) ) ) ) )
            )  goto L18600;
        if  ( FALSE( pregexp_oundary_3f_80a8c00c( DISPLAY( 0 ), 
                                                  DISPLAY( 8 ), 
                                                  PAIR_CAR( DISPLAY( 3 ) ) ) )
            )  goto L18602;
        X1 = DISPLAY( 9 );
        X1 = UNKNOWNCALL( X1, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( DISPLAY( 8 ), 
                                             PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18602:
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18600:
        if  ( NOT( OR( EQ( _S2CUINT( DISPLAY( 7 ) ), 
                           _S2CUINT( c12994 ) ), 
                       AND( EQ( TSCPTAG( DISPLAY( 7 ) ), 
                                EXTENDEDTAG ), 
                            AND( EQ( TSCP_EXTENDEDTAG( DISPLAY( 7 ) ), 
                                     DOUBLEFLOATTAG ), 
                                 AND( EQ( TSCPTAG( c12994 ), 
                                          EXTENDEDTAG ), 
                                      AND( EQ( TSCP_EXTENDEDTAG( c12994 ), 
                                               DOUBLEFLOATTAG ), 
                                           EQ( FLOAT_VALUE( DISPLAY( 7 ) ), 
                                               FLOAT_VALUE( c12994 ) ) ) ) ) ) ) )
            )  goto L18604;
        if  ( FALSE( pregexp_oundary_3f_80a8c00c( DISPLAY( 0 ), 
                                                  DISPLAY( 8 ), 
                                                  PAIR_CAR( DISPLAY( 3 ) ) ) )
            )  goto L18606;
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18606:
        X1 = DISPLAY( 9 );
        X1 = UNKNOWNCALL( X1, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( DISPLAY( 8 ), 
                                             PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18604:
        X1 = BOOLEAN( EQ( TSCPIMMEDIATETAG( DISPLAY( 7 ) ), 
                          CHARACTERTAG ) );
        if  ( FALSE( X1 ) )  goto L18622;
        X2 = DISPLAY( 8 );
        X3 = PAIR_CAR( DISPLAY( 3 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L18614;
        if  ( LT( _S2CINT( X2 ), _S2CINT( X3 ) ) )  goto L18618;
        goto L18622;
L18614:
        if  ( TRUE( scrt2__3c_2dtwo( X2, X3 ) ) )  goto L18618;
        goto L18622;
L18583:
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18582:
        X1 = DISPLAY( 9 );
        X1 = UNKNOWNCALL( X1, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( DISPLAY( 8 ), 
                                             PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18594:
        X1 = DISPLAY( 9 );
        X1 = UNKNOWNCALL( X1, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( DISPLAY( 8 ), 
                                             PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18595:
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18618:
        X3 = DISPLAY( 8 );
        X4 = DISPLAY( 0 );
        if  ( EQ( TSCPTAG( X3 ), FIXNUMTAG ) )  goto L18626;
        scdebug_error( c12237, 
                       c12238, CONS( X3, EMPTYLIST ) );
L18626:
        X5 = BOOLEAN( LT( _S2CINT( X3 ), 0 ) );
        if  ( TRUE( X5 ) )  goto L18632;
        if  ( AND( EQ( TSCPTAG( X4 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X4 ), STRINGTAG ) ) )  goto L18634;
        scdebug_error( c12259, 
                       c12260, CONS( X4, EMPTYLIST ) );
L18634:
        X6 = C_FIXED( STRING_LENGTH( X4 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L18638;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( X6 ) ) )  goto L18632;
        goto L18645;
L18638:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X3, X6 ) ) )  goto L18645;
L18632:
        scdebug_error( c12237, 
                       c12261, CONS( X3, EMPTYLIST ) );
L18645:
        X2 = C_CHAR( STRING_CHAR( X4, X3 ) );
        if  ( FALSE( PAIR_CAR( DISPLAY( 4 ) ) ) )  goto L18646;
        X1 = scrt3_char_3d_3f_v;
        goto L18647;
L18646:
        X1 = scrt3_char_2dci_3d_3f_v;
L18647:
        X1 = UNKNOWNCALL( X1, 2 );
        if  ( FALSE( VIA( PROCEDURE_CODE( X1 ) )( X2, 
                                                  DISPLAY( 7 ), 
                                                  PROCEDURE_CLOSURE( X1 ) ) )
            )  goto L18623;
        X3 = DISPLAY( 8 );
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18649;
        X2 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18650;
L18649:
        X2 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L18650:
        X1 = DISPLAY( 9 );
        X1 = UNKNOWNCALL( X1, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( X2, 
                                             PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18623:
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18622:
        X1 = BOOLEAN( NEQ( TSCPTAG( DISPLAY( 7 ) ), 
                           PAIRTAG ) );
        if  ( FALSE( X1 ) )  goto L18665;
        X2 = DISPLAY( 8 );
        X3 = PAIR_CAR( DISPLAY( 3 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L18657;
        if  ( LT( _S2CINT( X2 ), _S2CINT( X3 ) ) )  goto L18661;
        goto L18665;
L18657:
        if  ( FALSE( scrt2__3c_2dtwo( X2, X3 ) ) )  goto L18665;
L18661:
        X2 = DISPLAY( 8 );
        X3 = DISPLAY( 0 );
        if  ( EQ( TSCPTAG( X2 ), FIXNUMTAG ) )  goto L18669;
        scdebug_error( c12237, 
                       c12238, CONS( X2, EMPTYLIST ) );
L18669:
        X4 = BOOLEAN( LT( _S2CINT( X2 ), 0 ) );
        if  ( TRUE( X4 ) )  goto L18675;
        if  ( AND( EQ( TSCPTAG( X3 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X3 ), STRINGTAG ) ) )  goto L18677;
        scdebug_error( c12259, 
                       c12260, CONS( X3, EMPTYLIST ) );
L18677:
        X5 = C_FIXED( STRING_LENGTH( X3 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X5 ) ), 
                      3 ) )  goto L18681;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X5 ) ) )  goto L18675;
        goto L18688;
L18681:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X2, X5 ) ) )  goto L18688;
L18675:
        scdebug_error( c12237, 
                       c12261, CONS( X2, EMPTYLIST ) );
L18688:
        X1 = C_CHAR( STRING_CHAR( X3, X2 ) );
        if  ( FALSE( pregexp_2dclass_3f_7022b0e( X1, 
                                                 DISPLAY( 7 ) ) )
            )  goto L18666;
        X3 = DISPLAY( 8 );
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18690;
        X2 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18691;
L18690:
        X2 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L18691:
        X1 = DISPLAY( 9 );
        X1 = UNKNOWNCALL( X1, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( X2, 
                                             PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18666:
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18665:
        X1 = BOOLEAN( EQ( TSCPTAG( DISPLAY( 7 ) ), PAIRTAG ) );
        if  ( FALSE( X1 ) )  goto L18713;
        X3 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L18700;
        scrt1__24__car_2derror( X3 );
L18700:
        X2 = PAIR_CAR( X3 );
        if  ( NOT( OR( EQ( _S2CUINT( X2 ), 
                           _S2CUINT( c14236 ) ), 
                       AND( EQ( TSCPTAG( X2 ), EXTENDEDTAG ), 
                            AND( EQ( TSCP_EXTENDEDTAG( X2 ), 
                                     DOUBLEFLOATTAG ), 
                                 AND( EQ( TSCPTAG( c14236 ), 
                                          EXTENDEDTAG ), 
                                      AND( EQ( TSCP_EXTENDEDTAG( c14236 ), 
                                               DOUBLEFLOATTAG ), 
                                           EQ( FLOAT_VALUE( X2 ), 
                                               FLOAT_VALUE( c14236 ) ) ) ) ) ) ) )
            )  goto L18713;
        X2 = PAIR_CAR( DISPLAY( 3 ) );
        X3 = DISPLAY( 8 );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L18704;
        if  ( LT( _S2CINT( X3 ), _S2CINT( X2 ) ) )  goto L18708;
        goto L18713;
L18704:
        if  ( FALSE( scrt2__3c_2dtwo( X3, X2 ) ) )  goto L18713;
L18708:
        X2 = DISPLAY( 0 );
        X3 = DISPLAY( 8 );
        if  ( EQ( TSCPTAG( X3 ), FIXNUMTAG ) )  goto L18715;
        scdebug_error( c12237, 
                       c12238, CONS( X3, EMPTYLIST ) );
L18715:
        X4 = BOOLEAN( LT( _S2CINT( X3 ), 0 ) );
        if  ( TRUE( X4 ) )  goto L18721;
        if  ( AND( EQ( TSCPTAG( X2 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X2 ), STRINGTAG ) ) )  goto L18723;
        scdebug_error( c12259, 
                       c12260, CONS( X2, EMPTYLIST ) );
L18723:
        X5 = C_FIXED( STRING_LENGTH( X2 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X5 ) ), 
                      3 ) )  goto L18727;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( X5 ) ) )  goto L18721;
        goto L18734;
L18727:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X3, X5 ) ) )  goto L18734;
L18721:
        scdebug_error( c12237, 
                       c12261, CONS( X3, EMPTYLIST ) );
L18734:
        X1 = C_CHAR( STRING_CHAR( X2, X3 ) );
        if  ( FALSE( PAIR_CAR( DISPLAY( 4 ) ) ) )  goto L18736;
        X2 = scrt3_char_3c_3d_3f_v;
        goto L18737;
L18736:
        X2 = scrt3_char_2dci_3c_3d_3f_v;
L18737:
        X6 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L18741;
        scrt1__24__cdr_2derror( X6 );
L18741:
        X7 = PAIR_CDR( X6 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L18744;
        scrt1__24__car_2derror( X7 );
L18744:
        X5 = PAIR_CAR( X7 );
        X4 = X2;
        X4 = UNKNOWNCALL( X4, 2 );
        X3 = VIA( PROCEDURE_CODE( X4 ) )( X5, 
                                          X1, 
                                          PROCEDURE_CLOSURE( X4 ) );
        if  ( FALSE( X3 ) )  goto L18755;
        X5 = scrt1_caddr( DISPLAY( 7 ) );
        X4 = X2;
        X4 = UNKNOWNCALL( X4, 2 );
        if  ( FALSE( VIA( PROCEDURE_CODE( X4 ) )( X1, 
                                                  X5, 
                                                  PROCEDURE_CLOSURE( X4 ) ) )
            )  goto L18755;
        X6 = DISPLAY( 8 );
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L18753;
        X5 = _TSCP( IPLUS( _S2CINT( X6 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L18754;
L18753:
        X5 = scrt2__2b_2dtwo( X6, _TSCP( 4 ) );
L18754:
        X4 = DISPLAY( 9 );
        X4 = UNKNOWNCALL( X4, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X4 ) )( X5, 
                                             PROCEDURE_CLOSURE( X4 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18755:
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18713:
        if  ( NEQ( TSCPTAG( DISPLAY( 7 ) ), PAIRTAG ) )  goto L18756;
        X2 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L18759;
        scrt1__24__car_2derror( X2 );
L18759:
        X1 = PAIR_CAR( X2 );
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c14236 ) ) )  goto L18762;
        X2 = PAIR_CAR( DISPLAY( 3 ) );
        X3 = DISPLAY( 8 );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L18766;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( X2 ) ) )  goto L18770;
        goto L18771;
L18766:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X3, X2 ) ) )  goto L18770;
        goto L18771;
L18762:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c14312 ) ) )  goto L18774;
        X2 = DISPLAY( 8 );
        X3 = PAIR_CAR( DISPLAY( 3 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L18778;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X3 ) ) )  goto L18782;
        goto L18783;
L18778:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X2, X3 ) ) )  goto L18782;
        goto L18783;
L18774:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c12606 ) ) )  goto L18786;
        X2 = PAIR_CAR( DISPLAY( 3 ) );
        X3 = DISPLAY( 8 );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L18790;
        if  ( GTE( _S2CINT( X3 ), _S2CINT( X2 ) ) )  goto L18794;
        goto L18795;
L18790:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X3, X2 ) ) )  goto L18794;
        goto L18795;
L18786:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c12327 ) ) )  goto L18798;
        X3 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L18801;
        scrt1__24__cdr_2derror( X3 );
L18801:
        X2 = PAIR_CDR( X3 );
        X3 = DISPLAY( 8 );
        SDVAL = pregexp_l15299( X2, X3 );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18798:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c12320 ) ) )  goto L18816;
        X3 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L18819;
        scrt1__24__cdr_2derror( X3 );
L18819:
        X2 = PAIR_CDR( X3 );
        SDVAL = pregexp_l15264( X2 );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18816:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c12572 ) ) )  goto L18842;
        X4 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L18846;
        scrt1__24__cdr_2derror( X4 );
L18846:
        X5 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L18849;
        scrt1__24__car_2derror( X5 );
L18849:
        X3 = PAIR_CAR( X5 );
        X2 = pregexp_pregexp_2dlist_2dref( DISPLAY( 5 ), X3 );
        if  ( FALSE( X2 ) )  goto L18852;
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L18855;
        scrt1__24__cdr_2derror( X2 );
L18855:
        X3 = PAIR_CDR( X2 );
        goto L18853;
L18852:
        X4 = CONS( DISPLAY( 7 ), EMPTYLIST );
        X4 = CONS( c15246, X4 );
        pregexp_pregexp_2derror( CONS( c14932, X4 ) );
        X3 = FALSEVALUE;
L18853:
        if  ( FALSE( X3 ) )  goto L18859;
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L18862;
        scrt1__24__car_2derror( X3 );
L18862:
        X5 = PAIR_CAR( X3 );
        X6 = PAIR_CDR( X3 );
        X4 = scrt3_substring( DISPLAY( 0 ), X5, X6 );
        X5 = MAKEPROCEDURE( 1, 
                            0, 
                            pregexp_l15241, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 9 ) ) );
        SDVAL = pregexp_ng_2dmatch_8f735cce( X4, 
                                             DISPLAY( 0 ), 
                                             DISPLAY( 8 ), 
                                             PAIR_CAR( DISPLAY( 3 ) ), 
                                             X5, DISPLAY( 10 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18859:
        X4 = DISPLAY( 9 );
        X4 = UNKNOWNCALL( X4, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X4 ) )( DISPLAY( 8 ), 
                                             PROCEDURE_CLOSURE( X4 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18842:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c14829 ) ) )  goto L18867;
        X3 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L18871;
        scrt1__24__cdr_2derror( X3 );
L18871:
        X4 = PAIR_CDR( X3 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L18874;
        scrt1__24__car_2derror( X4 );
L18874:
        X2 = PAIR_CAR( X4 );
        X3 = MAKEPROCEDURE( 1, 
                            0, 
                            pregexp_l15222, 
                            MAKECLOSURE( EMPTYLIST, 
                                         4, 
                                         DISPLAY( 5 ), 
                                         DISPLAY( 7 ), 
                                         DISPLAY( 8 ), 
                                         DISPLAY( 9 ) ) );
        DISPLAY( 9 ) = X3;
        DISPLAY( 7 ) = X2;
        GOBACK( L18573 );
L18867:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c14959 ) ) )  goto L18881;
        X3 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L18887;
        scrt1__24__cdr_2derror( X3 );
L18887:
        X4 = PAIR_CDR( X3 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L18890;
        scrt1__24__car_2derror( X4 );
L18890:
        X2 = PAIR_CAR( X4 );
        X3 = MAKEPROCEDURE( 0, 0, pregexp_l15211, EMPTYLIST );
        if  ( FALSE( pregexp_s14856( X2, 
                                     DISPLAY( 8 ), 
                                     DISPLAY( 6 ), X3 ) ) )  goto L18883;
        X2 = DISPLAY( 9 );
        X2 = UNKNOWNCALL( X2, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X2 ) )( DISPLAY( 8 ), 
                                             PROCEDURE_CLOSURE( X2 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18883:
        X2 = DISPLAY( 10 );
        X2 = UNKNOWNCALL( X2, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X2 ) )( PROCEDURE_CLOSURE( X2 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18881:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c14963 ) ) )  goto L18894;
        X3 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L18900;
        scrt1__24__cdr_2derror( X3 );
L18900:
        X4 = PAIR_CDR( X3 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L18903;
        scrt1__24__car_2derror( X4 );
L18903:
        X2 = PAIR_CAR( X4 );
        X3 = MAKEPROCEDURE( 0, 0, pregexp_l15198, EMPTYLIST );
        if  ( FALSE( pregexp_s14856( X2, 
                                     DISPLAY( 8 ), 
                                     DISPLAY( 6 ), X3 ) ) )  goto L18896;
        X2 = DISPLAY( 10 );
        X2 = UNKNOWNCALL( X2, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X2 ) )( PROCEDURE_CLOSURE( X2 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18896:
        X2 = DISPLAY( 9 );
        X2 = UNKNOWNCALL( X2, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X2 ) )( DISPLAY( 8 ), 
                                             PROCEDURE_CLOSURE( X2 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18894:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c14967 ) ) )  goto L18907;
        X2 = PAIR_CAR( DISPLAY( 3 ) );
        X3 = PAIR_CAR( DISPLAY( 1 ) );
        X4 = DISPLAY( 8 );
        SETGEN( PAIR_CAR( DISPLAY( 3 ) ), X4 );
        X4 = DISPLAY( 8 );
        SETGEN( PAIR_CAR( DISPLAY( 1 ) ), X4 );
        X10 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L18912;
        scrt1__24__cdr_2derror( X10 );
L18912:
        X11 = PAIR_CDR( X10 );
        if  ( EQ( TSCPTAG( X11 ), PAIRTAG ) )  goto L18915;
        scrt1__24__car_2derror( X11 );
L18915:
        X9 = PAIR_CAR( X11 );
        X10 = sc_cons( c12680, EMPTYLIST );
        X8 = sc_cons( X9, X10 );
        X7 = sc_cons( c15156, X8 );
        X6 = sc_cons( c12327, X7 );
        X5 = X6;
        X6 = MAKEPROCEDURE( 0, 0, pregexp_l15185, EMPTYLIST );
        X4 = pregexp_s14856( X5, 
                             _TSCP( 0 ), DISPLAY( 6 ), X6 );
        X5 = X2;
        SETGEN( PAIR_CAR( DISPLAY( 3 ) ), X5 );
        X5 = X3;
        SETGEN( PAIR_CAR( DISPLAY( 1 ) ), X5 );
        if  ( FALSE( X4 ) )  goto L18921;
        X5 = DISPLAY( 9 );
        X5 = UNKNOWNCALL( X5, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X5 ) )( DISPLAY( 8 ), 
                                             PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18921:
        X5 = DISPLAY( 10 );
        X5 = UNKNOWNCALL( X5, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X5 ) )( PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18907:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c14971 ) ) )  goto L18923;
        X2 = PAIR_CAR( DISPLAY( 1 ) );
        X3 = PAIR_CAR( DISPLAY( 3 ) );
        X4 = DISPLAY( 8 );
        SETGEN( PAIR_CAR( DISPLAY( 3 ) ), X4 );
        X4 = DISPLAY( 8 );
        SETGEN( PAIR_CAR( DISPLAY( 1 ) ), X4 );
        X10 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L18928;
        scrt1__24__cdr_2derror( X10 );
L18928:
        X11 = PAIR_CDR( X10 );
        if  ( EQ( TSCPTAG( X11 ), PAIRTAG ) )  goto L18931;
        scrt1__24__car_2derror( X11 );
L18931:
        X9 = PAIR_CAR( X11 );
        X10 = sc_cons( c12680, EMPTYLIST );
        X8 = sc_cons( X9, X10 );
        X7 = sc_cons( c15156, X8 );
        X6 = sc_cons( c12327, X7 );
        X5 = X6;
        X6 = MAKEPROCEDURE( 0, 0, pregexp_l15167, EMPTYLIST );
        X4 = pregexp_s14856( X5, 
                             _TSCP( 0 ), DISPLAY( 6 ), X6 );
        X5 = X3;
        SETGEN( PAIR_CAR( DISPLAY( 3 ) ), X5 );
        X5 = X2;
        SETGEN( PAIR_CAR( DISPLAY( 1 ) ), X5 );
        if  ( FALSE( X4 ) )  goto L18937;
        X5 = DISPLAY( 10 );
        X5 = UNKNOWNCALL( X5, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X5 ) )( PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18937:
        X5 = DISPLAY( 9 );
        X5 = UNKNOWNCALL( X5, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X5 ) )( DISPLAY( 8 ), 
                                             PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18923:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c14975 ) ) )  goto L18939;
        X4 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L18943;
        scrt1__24__cdr_2derror( X4 );
L18943:
        X5 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L18946;
        scrt1__24__car_2derror( X5 );
L18946:
        X3 = PAIR_CAR( X5 );
        X4 = MAKEPROCEDURE( 0, 0, pregexp_l15148, EMPTYLIST );
        X2 = pregexp_s14856( X3, 
                             DISPLAY( 8 ), 
                             DISPLAY( 6 ), X4 );
        if  ( FALSE( X2 ) )  goto L18951;
        X3 = DISPLAY( 9 );
        X3 = UNKNOWNCALL( X3, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X3 ) )( X2, 
                                             PROCEDURE_CLOSURE( X3 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18951:
        X3 = DISPLAY( 10 );
        X3 = UNKNOWNCALL( X3, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X3 ) )( PROCEDURE_CLOSURE( X3 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18939:
        if  ( FALSE( scrt1_memv( X1, c14976 ) ) )  goto L18953;
        DISPLAY( 11 ) = PAIR_CAR( DISPLAY( 4 ) );
        X4 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L18957;
        scrt1__24__car_2derror( X4 );
L18957:
        X3 = PAIR_CAR( X4 );
        X2 = BOOLEAN( OR( EQ( _S2CUINT( X3 ), 
                              _S2CUINT( c13277 ) ), 
                          AND( EQ( TSCPTAG( X3 ), EXTENDEDTAG ), 
                               AND( EQ( TSCP_EXTENDEDTAG( X3 ), 
                                        DOUBLEFLOATTAG ), 
                                    AND( EQ( TSCPTAG( c13277 ), 
                                             EXTENDEDTAG ), 
                                         AND( EQ( TSCP_EXTENDEDTAG( c13277 ), 
                                                  DOUBLEFLOATTAG ), 
                                              EQ( FLOAT_VALUE( X3 ), 
                                                  FLOAT_VALUE( c13277 ) ) ) ) ) ) ) );
        SETGEN( PAIR_CAR( DISPLAY( 4 ) ), X2 );
        X3 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L18961;
        scrt1__24__cdr_2derror( X3 );
L18961:
        X4 = PAIR_CDR( X3 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L18964;
        scrt1__24__car_2derror( X4 );
L18964:
        X2 = PAIR_CAR( X4 );
        X3 = MAKEPROCEDURE( 1, 
                            0, 
                            pregexp_l15133, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 11 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 9 ) ) );
        DISPLAY( 10 ) = MAKEPROCEDURE( 0, 
                                       0, 
                                       pregexp_l15135, 
                                       MAKECLOSURE( EMPTYLIST, 
                                                    3, 
                                                    DISPLAY( 11 ), 
                                                    DISPLAY( 4 ), 
                                                    DISPLAY( 10 ) ) );
        DISPLAY( 9 ) = X3;
        DISPLAY( 7 ) = X2;
        GOBACK( L18573 );
L18953:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c13854 ) ) )  goto L18970;
        X2 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L18974;
        scrt1__24__cdr_2derror( X2 );
L18974:
        X3 = PAIR_CDR( X2 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L18977;
        scrt1__24__car_2derror( X3 );
L18977:
        if  ( FALSE( PAIR_CAR( X3 ) ) )  goto L18979;
        DISPLAY( 11 ) = FALSEVALUE;
        goto L18980;
L18979:
        DISPLAY( 11 ) = TRUEVALUE;
L18980:
        DISPLAY( 12 ) = scrt1_caddr( DISPLAY( 7 ) );
        DISPLAY( 13 ) = scrt1_cadddr( DISPLAY( 7 ) );
        X2 = DISPLAY( 11 );
        if  ( FALSE( X2 ) )  goto L18985;
        if  ( FALSE( DISPLAY( 13 ) ) )  goto L18987;
        DISPLAY( 14 ) = FALSEVALUE;
        goto L18986;
L18987:
        DISPLAY( 14 ) = TRUEVALUE;
        goto L18986;
L18985:
        DISPLAY( 14 ) = X2;
L18986:
        X2 = scrt1_cddddr( DISPLAY( 7 ) );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L18991;
        scrt1__24__car_2derror( X2 );
L18991:
        DISPLAY( 15 ) = PAIR_CAR( X2 );
        X2 = DISPLAY( 8 );
        SDVAL = pregexp_l14994( _TSCP( 0 ), X2 );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18970:
        SDVAL = pregexp_pregexp_2derror( CONS( c14932, EMPTYLIST ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18756:
        X1 = DISPLAY( 8 );
        X2 = PAIR_CAR( DISPLAY( 3 ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L19084;
        if  ( GTE( _S2CINT( X1 ), _S2CINT( X2 ) ) )  goto L19088;
        goto L19089;
L19084:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X1, X2 ) ) )  goto L19088;
        goto L19089;
L18771:
        SDVAL = pregexp_pregexp_2derror( CONS( c14932, EMPTYLIST ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18770:
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18782:
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18783:
        X2 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L19093;
        scrt1__24__cdr_2derror( X2 );
L19093:
        X1 = PAIR_CDR( X2 );
        SDVAL = pregexp_l15356( X1 );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L18795:
        X2 = DISPLAY( 7 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L19110;
        scrt1__24__cdr_2derror( X2 );
L19110:
        X3 = PAIR_CDR( X2 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L19113;
        scrt1__24__car_2derror( X3 );
L19113:
        X1 = PAIR_CAR( X3 );
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            pregexp_l15338, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 10 ) ) );
        DISPLAY( 10 ) = MAKEPROCEDURE( 0, 
                                       0, 
                                       pregexp_l15340, 
                                       MAKECLOSURE( EMPTYLIST, 
                                                    2, 
                                                    DISPLAY( 8 ), 
                                                    DISPLAY( 9 ) ) );
        DISPLAY( 9 ) = X2;
        DISPLAY( 7 ) = X1;
        GOBACK( L18573 );
L18794:
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L19088:
        X1 = DISPLAY( 10 );
        X1 = UNKNOWNCALL( X1, 0 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
L19089:
        SDVAL = pregexp_pregexp_2derror( CONS( c14932, EMPTYLIST ) );
        DISPLAY( 7 ) = SD7;
        DISPLAY( 8 ) = SD8;
        DISPLAY( 9 ) = SD9;
        DISPLAY( 10 ) = SD10;
        DISPLAY( 11 ) = SD11;
        DISPLAY( 12 ) = SD12;
        DISPLAY( 13 ) = SD13;
        DISPLAY( 14 ) = SD14;
        DISPLAY( 15 ) = SD15;
        POPSTACKTRACE( SDVAL );
}

EXTERNTSCPP( scrt1_cdr, XAL1( TSCP ) );
EXTERNTSCP( scrt1_cdr_v );

TSCP  pregexp_ions_2daux_a110402e( r14840, 
                                   s14841, 
                                   s14842, 
                                   s14843, n14844, i14845 )
        TSCP  r14840, 
              s14841, s14842, s14843, n14844, i14845;
{
        TSCP  X8, X7, X6, X5, X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SD3 = DISPLAY( 3 );
        TSCP  SD4 = DISPLAY( 4 );
        TSCP  SD5 = DISPLAY( 5 );
        TSCP  SD6 = DISPLAY( 6 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t18564 );
        DISPLAY( 0 ) = s14841;
        DISPLAY( 1 ) = s14842;
        DISPLAY( 2 ) = s14843;
        DISPLAY( 3 ) = n14844;
        DISPLAY( 1 ) = CONS( DISPLAY( 1 ), EMPTYLIST );
        DISPLAY( 3 ) = CONS( DISPLAY( 3 ), EMPTYLIST );
        DISPLAY( 4 ) = TRUEVALUE;
        DISPLAY( 5 ) = pregexp_ref_2dlist_bf9bf990( r14840 );
        DISPLAY( 6 ) = MAKEPROCEDURE( 1, 
                                      0, pregexp_i14847, EMPTYLIST );
        DISPLAY( 4 ) = CONS( DISPLAY( 4 ), EMPTYLIST );
        X1 = DISPLAY( 6 );
        X2 = MAKEPROCEDURE( 0, 0, pregexp__2414854, EMPTYLIST );
        pregexp_s14856( r14840, i14845, X1, X2 );
        X2 = DISPLAY( 5 );
        X3 = X2;
        X4 = EMPTYLIST;
        X5 = EMPTYLIST;
L19124:
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( EMPTYLIST ) ) )  goto L19125;
        X1 = X4;
        goto L19132;
L19125:
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L19128;
        scrt1__24__car_2derror( X3 );
L19128:
        X8 = PAIR_CAR( X3 );
        X7 = scrt1_cdr( X8 );
        X6 = sc_cons( X7, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L19131;
        X7 = PAIR_CDR( X3 );
        X5 = X6;
        X4 = X6;
        X3 = X7;
        GOBACK( L19124 );
L19131:
        X7 = PAIR_CDR( X3 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L19136;
        scdebug_error( c12162, 
                       c12163, CONS( X5, EMPTYLIST ) );
L19136:
        X5 = SETGEN( PAIR_CDR( X5 ), X6 );
        X3 = X7;
        GOBACK( L19124 );
L19132:
        if  ( EQ( TSCPTAG( X1 ), PAIRTAG ) )  goto L19140;
        scrt1__24__car_2derror( X1 );
L19140:
        X2 = PAIR_CAR( X1 );
        if  ( TRUE( X2 ) )  goto L19143;
        SDVAL = X2;
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        DISPLAY( 5 ) = SD5;
        DISPLAY( 6 ) = SD6;
        POPSTACKTRACE( SDVAL );
L19143:
        SDVAL = X1;
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        DISPLAY( 5 ) = SD5;
        DISPLAY( 6 ) = SD6;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( pregexp_lace_2daux_580391d8_v );
DEFCSTRING( t19145, "PREGEXP-REPLACE-AUX" );
EXTERNTSCP( sc_emptystring );
EXTERNTSCPP( scrt3_string_2dappend, XAL1( TSCP ) );
EXTERNTSCP( scrt3_string_2dappend_v );
EXTERNTSCPP( scrt3_string, XAL1( TSCP ) );
EXTERNTSCP( scrt3_string_v );

TSCP  pregexp_lace_2daux_580391d8( s15569, 
                                   i15570, n15571, b15572 )
        TSCP  s15569, i15570, n15571, b15572;
{
        TSCP  X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t19145 );
        X1 = sc_emptystring;
        X2 = _TSCP( 0 );
        X3 = X1;
L19149:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( n15571 ) ), 
                      3 ) )  goto L19151;
        if  ( LT( _S2CINT( X2 ), _S2CINT( n15571 ) ) )  goto L19155;
        POPSTACKTRACE( X3 );
L19151:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X2, n15571 ) ) )  goto L19155;
        POPSTACKTRACE( X3 );
L19155:
        if  ( EQ( TSCPTAG( X2 ), FIXNUMTAG ) )  goto L19159;
        scdebug_error( c12237, 
                       c12238, CONS( X2, EMPTYLIST ) );
L19159:
        X5 = BOOLEAN( LT( _S2CINT( X2 ), 0 ) );
        if  ( TRUE( X5 ) )  goto L19165;
        if  ( AND( EQ( TSCPTAG( i15570 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( i15570 ), STRINGTAG ) )
            )  goto L19167;
        scdebug_error( c12259, 
                       c12260, CONS( i15570, EMPTYLIST ) );
L19167:
        X6 = C_FIXED( STRING_LENGTH( i15570 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L19171;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X6 ) ) )  goto L19165;
        goto L19178;
L19171:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X2, X6 ) ) )  goto L19178;
L19165:
        scdebug_error( c12237, 
                       c12261, CONS( X2, EMPTYLIST ) );
L19178:
        X4 = C_CHAR( STRING_CHAR( i15570, X2 ) );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X4 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 23570 ) ), 
                       CHARACTERTAG ) ) )  goto L19181;
        X5 = CONS( _TSCP( 23570 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X4, X5 ) );
L19181:
        if  ( NEQ( _S2CINT( X4 ), 
                   _S2CINT( _TSCP( 23570 ) ) ) )  goto L19183;
        X5 = pregexp_d_2dnumber_1f1ad78b( i15570, X2, n15571 );
        if  ( FALSE( X5 ) )  goto L19186;
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L19189;
        scrt1__24__car_2derror( X5 );
L19189:
        X6 = PAIR_CAR( X5 );
        goto L19218;
L19186:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19191;
        X8 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L19192;
L19191:
        X8 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L19192:
        if  ( EQ( TSCPTAG( X8 ), FIXNUMTAG ) )  goto L19194;
        scdebug_error( c12237, 
                       c12238, CONS( X8, EMPTYLIST ) );
L19194:
        X9 = BOOLEAN( LT( _S2CINT( X8 ), 0 ) );
        if  ( TRUE( X9 ) )  goto L19200;
        if  ( AND( EQ( TSCPTAG( i15570 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( i15570 ), STRINGTAG ) )
            )  goto L19202;
        scdebug_error( c12259, 
                       c12260, CONS( i15570, EMPTYLIST ) );
L19202:
        X10 = C_FIXED( STRING_LENGTH( i15570 ) );
        if  ( BITAND( BITOR( _S2CINT( X8 ), _S2CINT( X10 ) ), 
                      3 ) )  goto L19206;
        if  ( GTE( _S2CINT( X8 ), _S2CINT( X10 ) ) )  goto L19200;
        goto L19213;
L19206:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X8, X10 ) ) )  goto L19213;
L19200:
        scdebug_error( c12237, 
                       c12261, CONS( X8, EMPTYLIST ) );
L19213:
        X7 = C_CHAR( STRING_CHAR( i15570, X8 ) );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X7 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 9746 ) ), 
                       CHARACTERTAG ) ) )  goto L19215;
        X8 = CONS( _TSCP( 9746 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X7, X8 ) );
L19215:
        if  ( NEQ( _S2CINT( X7 ), _S2CINT( _TSCP( 9746 ) ) ) )  goto L19217;
        X6 = _TSCP( 0 );
        goto L19218;
L19217:
        X6 = FALSEVALUE;
L19218:
        if  ( FALSE( X5 ) )  goto L19220;
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L19223;
        scrt1__24__cdr_2derror( X5 );
L19223:
        X8 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X8 ), PAIRTAG ) )  goto L19226;
        scrt1__24__car_2derror( X8 );
L19226:
        X7 = PAIR_CAR( X8 );
        goto L19233;
L19220:
        if  ( FALSE( X6 ) )  goto L19228;
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L19230;
        X7 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L19233;
L19230:
        X7 = scrt2__2b_2dtwo( X2, _TSCP( 8 ) );
        goto L19233;
L19228:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19232;
        X7 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L19233;
L19232:
        X7 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L19233:
        if  ( FALSE( X6 ) )  goto L19235;
        X8 = pregexp_pregexp_2dlist_2dref( b15572, X6 );
        if  ( FALSE( X8 ) )  goto L19238;
        if  ( EQ( TSCPTAG( X8 ), PAIRTAG ) )  goto L19241;
        scrt1__24__car_2derror( X8 );
L19241:
        X10 = PAIR_CAR( X8 );
        X11 = PAIR_CDR( X8 );
        X9 = CONS( scrt3_substring( s15569, X10, X11 ), 
                   EMPTYLIST );
        X3 = scrt3_string_2dappend( CONS( X3, X9 ) );
        goto L19238;
L19238:
        X2 = X7;
        GOBACK( L19149 );
L19235:
        if  ( EQ( TSCPTAG( X7 ), FIXNUMTAG ) )  goto L19245;
        scdebug_error( c12237, 
                       c12238, CONS( X7, EMPTYLIST ) );
L19245:
        X9 = BOOLEAN( LT( _S2CINT( X7 ), 0 ) );
        if  ( TRUE( X9 ) )  goto L19251;
        if  ( AND( EQ( TSCPTAG( i15570 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( i15570 ), STRINGTAG ) )
            )  goto L19253;
        scdebug_error( c12259, 
                       c12260, CONS( i15570, EMPTYLIST ) );
L19253:
        X10 = C_FIXED( STRING_LENGTH( i15570 ) );
        if  ( BITAND( BITOR( _S2CINT( X7 ), _S2CINT( X10 ) ), 
                      3 ) )  goto L19257;
        if  ( GTE( _S2CINT( X7 ), _S2CINT( X10 ) ) )  goto L19251;
        goto L19264;
L19257:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X7, X10 ) ) )  goto L19264;
L19251:
        scdebug_error( c12237, 
                       c12261, CONS( X7, EMPTYLIST ) );
L19264:
        X8 = C_CHAR( STRING_CHAR( i15570, X7 ) );
        if  ( BITAND( BITOR( _S2CINT( X7 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19266;
        X9 = _TSCP( IPLUS( _S2CINT( X7 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L19267;
L19266:
        X9 = scrt2__2b_2dtwo( X7, _TSCP( 4 ) );
L19267:
        if  ( AND( EQ( TSCPIMMEDIATETAG( X8 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 9234 ) ), 
                       CHARACTERTAG ) ) )  goto L19269;
        X10 = CONS( _TSCP( 9234 ), EMPTYLIST );
        scdebug_error( c12230, c12231, CONS( X8, X10 ) );
L19269:
        if  ( EQ( _S2CINT( X8 ), _S2CINT( _TSCP( 9234 ) ) ) )  goto L19272;
        X10 = CONS( scrt3_string( CONS( X8, EMPTYLIST ) ), 
                    EMPTYLIST );
        X3 = scrt3_string_2dappend( CONS( X3, X10 ) );
L19272:
        X2 = X9;
        GOBACK( L19149 );
L19183:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19273;
        X5 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L19274;
L19273:
        X5 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L19274:
        X6 = CONS( scrt3_string( CONS( X4, EMPTYLIST ) ), 
                   EMPTYLIST );
        X3 = scrt3_string_2dappend( CONS( X3, X6 ) );
        X2 = X5;
        GOBACK( L19149 );
}

DEFTSCP( pregexp_pregexp_v );
DEFCSTRING( t19275, "PREGEXP" );

TSCP  pregexp_pregexp( s15746 )
        TSCP  s15746;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t19275 );
        pregexp_tive_3f_2a_bd6b8339_v = TRUEVALUE;
        if  ( AND( EQ( TSCPTAG( s15746 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s15746 ), STRINGTAG ) )
            )  goto L19278;
        scdebug_error( c12259, 
                       c12260, CONS( s15746, EMPTYLIST ) );
L19278:
        X5 = C_FIXED( STRING_LENGTH( s15746 ) );
        X4 = pregexp__2dpattern_829cfa27( s15746, _TSCP( 0 ), X5 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L19281;
        scrt1__24__car_2derror( X4 );
L19281:
        X3 = PAIR_CAR( X4 );
        X2 = sc_cons( X3, EMPTYLIST );
        X1 = sc_cons( c14829, X2 );
        POPSTACKTRACE( X1 );
}

DEFTSCP( pregexp_dpositions_4faf9e1_v );
DEFCSTRING( t19284, "PREGEXP-MATCH-POSITIONS" );
EXTERNTSCPP( scrt2__3c_3d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3c_3d_2dtwo_v );

TSCP  pregexp_dpositions_4faf9e1( p15758, s15759, o15760 )
        TSCP  p15758, s15759, o15760;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t19284 );
        p15758 = CONS( p15758, EMPTYLIST );
        o15760 = CONS( o15760, EMPTYLIST );
        if  ( NOT( AND( EQ( TSCPTAG( PAIR_CAR( p15758 ) ), 
                            EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( PAIR_CAR( p15758 ) ), 
                            STRINGTAG ) ) ) )  goto L19286;
        X1 = pregexp_pregexp( PAIR_CAR( p15758 ) );
        SETGEN( PAIR_CAR( p15758 ), X1 );
        goto L19288;
L19286:
        if  ( EQ( TSCPTAG( PAIR_CAR( p15758 ) ), PAIRTAG ) )  goto L19288;
        X1 = CONS( PAIR_CAR( p15758 ), EMPTYLIST );
        X1 = CONS( c15766, X1 );
        pregexp_pregexp_2derror( CONS( c15765, X1 ) );
L19288:
        if  ( AND( EQ( TSCPTAG( s15759 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s15759 ), STRINGTAG ) )
            )  goto L19291;
        scdebug_error( c12259, 
                       c12260, CONS( s15759, EMPTYLIST ) );
L19291:
        X1 = C_FIXED( STRING_LENGTH( s15759 ) );
        if  ( NEQ( _S2CUINT( PAIR_CAR( o15760 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L19294;
        X2 = _TSCP( 0 );
        goto L19295;
L19294:
        X4 = PAIR_CAR( o15760 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L19297;
        scrt1__24__car_2derror( X4 );
L19297:
        X3 = PAIR_CAR( X4 );
        X5 = PAIR_CAR( o15760 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L19301;
        scrt1__24__cdr_2derror( X5 );
L19301:
        X4 = PAIR_CDR( X5 );
        SETGEN( PAIR_CAR( o15760 ), X4 );
        X2 = X3;
L19295:
        if  ( NEQ( _S2CUINT( PAIR_CAR( o15760 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L19304;
        X3 = X1;
        goto L19305;
L19304:
        X4 = PAIR_CAR( o15760 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L19307;
        scrt1__24__car_2derror( X4 );
L19307:
        X3 = PAIR_CAR( X4 );
L19305:
        X4 = X2;
L19311:
        if  ( BITAND( BITOR( _S2CINT( X4 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L19312;
        X5 = BOOLEAN( LTE( _S2CINT( X4 ), _S2CINT( X3 ) ) );
        goto L19313;
L19312:
        X5 = scrt2__3c_3d_2dtwo( X4, X3 );
L19313:
        if  ( FALSE( X5 ) )  goto L19315;
        X6 = pregexp_ions_2daux_a110402e( PAIR_CAR( p15758 ), 
                                          s15759, 
                                          X1, X2, X3, X4 );
        if  ( TRUE( X6 ) )  goto L19318;
        if  ( BITAND( BITOR( _S2CINT( X4 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19320;
        X4 = _TSCP( IPLUS( _S2CINT( X4 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        GOBACK( L19311 );
L19320:
        X4 = scrt2__2b_2dtwo( X4, _TSCP( 4 ) );
        GOBACK( L19311 );
L19318:
        POPSTACKTRACE( X6 );
L19315:
        POPSTACKTRACE( X5 );
}

DEFTSCP( pregexp_pregexp_2dmatch_v );
DEFCSTRING( t19322, "PREGEXP-MATCH" );
EXTERNTSCPP( sc_apply_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_apply_2dtwo_v );
EXTERNTSCPP( scrt1_cons_2a, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_cons_2a_v );

TSCP  pregexp_pregexp_2dmatch( p15828, s15829, o15830 )
        TSCP  p15828, s15829, o15830;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t19322 );
        X3 = CONS( o15830, EMPTYLIST );
        X2 = scrt1_cons_2a( p15828, CONS( s15829, X3 ) );
        X1 = sc_apply_2dtwo( pregexp_dpositions_4faf9e1_v, X2 );
        if  ( FALSE( X1 ) )  goto L19325;
        X2 = X1;
        X3 = EMPTYLIST;
        X4 = EMPTYLIST;
L19328:
        if  ( EQ( _S2CUINT( X2 ), _S2CUINT( EMPTYLIST ) ) )  goto L19329;
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L19332;
        scrt1__24__car_2derror( X2 );
L19332:
        X7 = PAIR_CAR( X2 );
        if  ( FALSE( X7 ) )  goto L19335;
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L19338;
        scrt1__24__car_2derror( X7 );
L19338:
        X8 = PAIR_CAR( X7 );
        X9 = PAIR_CDR( X7 );
        X6 = scrt3_substring( s15829, X8, X9 );
        goto L19336;
L19335:
        X6 = X7;
L19336:
        X5 = sc_cons( X6, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( EMPTYLIST ) ) )  goto L19342;
        X6 = PAIR_CDR( X2 );
        X4 = X5;
        X3 = X5;
        X2 = X6;
        GOBACK( L19328 );
L19342:
        X6 = PAIR_CDR( X2 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L19347;
        scdebug_error( c12162, 
                       c12163, CONS( X4, EMPTYLIST ) );
L19347:
        X4 = SETGEN( PAIR_CDR( X4 ), X5 );
        X2 = X6;
        GOBACK( L19328 );
L19329:
        POPSTACKTRACE( X3 );
L19325:
        POPSTACKTRACE( X1 );
}

DEFTSCP( pregexp_pregexp_2dsplit_v );
DEFCSTRING( t19349, "PREGEXP-SPLIT" );

TSCP  pregexp_pregexp_2dsplit( p15894, s15895 )
        TSCP  p15894, s15895;
{
        TSCP  X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t19349 );
        if  ( AND( EQ( TSCPTAG( s15895 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s15895 ), STRINGTAG ) )
            )  goto L19352;
        scdebug_error( c12259, 
                       c12260, CONS( s15895, EMPTYLIST ) );
L19352:
        X1 = C_FIXED( STRING_LENGTH( s15895 ) );
        X2 = _TSCP( 0 );
        X3 = EMPTYLIST;
        X4 = FALSEVALUE;
L19356:
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L19358;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X1 ) ) )  goto L19362;
        goto L19363;
L19358:
        if  ( TRUE( scrt2__3e_3d_2dtwo( X2, X1 ) ) )  goto L19362;
L19363:
        X8 = CONS( X1, EMPTYLIST );
        X7 = pregexp_dpositions_4faf9e1( p15894, 
                                         s15895, 
                                         CONS( X2, X8 ) );
        if  ( FALSE( X7 ) )  goto L19367;
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L19370;
        scrt1__24__car_2derror( X7 );
L19370:
        X8 = PAIR_CAR( X7 );
        if  ( EQ( TSCPTAG( X8 ), PAIRTAG ) )  goto L19374;
        scrt1__24__car_2derror( X8 );
L19374:
        X5 = PAIR_CAR( X8 );
        X6 = PAIR_CDR( X8 );
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L19379;
        if  ( EQ( _S2CUINT( X5 ), _S2CUINT( X6 ) ) )  goto L19383;
        goto L19384;
L19379:
        if  ( TRUE( scrt2__3d_2dtwo( X5, X6 ) ) )  goto L19383;
        goto L19384;
L19367:
        X9 = scrt3_substring( s15895, X2, X1 );
        X8 = sc_cons( X9, X3 );
        X4 = FALSEVALUE;
        X3 = X8;
        X2 = X1;
        GOBACK( L19356 );
L19384:
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L19387;
        X7 = BOOLEAN( EQ( _S2CUINT( X5 ), _S2CUINT( X2 ) ) );
        goto L19388;
L19387:
        X7 = scrt2__3d_2dtwo( X5, X2 );
L19388:
        if  ( FALSE( X7 ) )  goto L19395;
        if  ( FALSE( X4 ) )  goto L19395;
        X4 = FALSEVALUE;
        X2 = X6;
        GOBACK( L19356 );
L19395:
        X8 = scrt3_substring( s15895, X2, X5 );
        X7 = sc_cons( X8, X3 );
        X4 = FALSEVALUE;
        X3 = X7;
        X2 = X6;
        GOBACK( L19356 );
L19383:
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19396;
        X7 = _TSCP( IPLUS( _S2CINT( X6 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L19397;
L19396:
        X7 = scrt2__2b_2dtwo( X6, _TSCP( 4 ) );
L19397:
        if  ( BITAND( BITOR( _S2CINT( X5 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19398;
        X10 = _TSCP( IPLUS( _S2CINT( X5 ), 
                            _S2CINT( _TSCP( 4 ) ) ) );
        goto L19399;
L19398:
        X10 = scrt2__2b_2dtwo( X5, _TSCP( 4 ) );
L19399:
        X9 = scrt3_substring( s15895, X2, X10 );
        X8 = sc_cons( X9, X3 );
        X4 = TRUEVALUE;
        X3 = X8;
        X2 = X7;
        GOBACK( L19356 );
L19362:
        POPSTACKTRACE( pregexp_pregexp_2dreverse_21( X3 ) );
}

DEFTSCP( pregexp_pregexp_2dreplace_v );
DEFCSTRING( t19400, "PREGEXP-REPLACE" );

TSCP  pregexp_pregexp_2dreplace( p15974, s15975, i15976 )
        TSCP  p15974, s15975, i15976;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t19400 );
        if  ( AND( EQ( TSCPTAG( s15975 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s15975 ), STRINGTAG ) )
            )  goto L19403;
        scdebug_error( c12259, 
                       c12260, CONS( s15975, EMPTYLIST ) );
L19403:
        X1 = C_FIXED( STRING_LENGTH( s15975 ) );
        X3 = CONS( X1, EMPTYLIST );
        X2 = pregexp_dpositions_4faf9e1( p15974, 
                                         s15975, 
                                         CONS( _TSCP( 0 ), X3 ) );
        if  ( FALSE( X2 ) )  goto L19407;
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L19410;
        scrt1__24__car_2derror( X2 );
L19410:
        X4 = PAIR_CAR( X2 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L19413;
        scrt1__24__cdr_2derror( X4 );
L19413:
        X3 = PAIR_CDR( X4 );
        X5 = PAIR_CAR( X2 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L19417;
        scrt1__24__car_2derror( X5 );
L19417:
        X4 = PAIR_CAR( X5 );
        if  ( AND( EQ( TSCPTAG( i15976 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( i15976 ), STRINGTAG ) )
            )  goto L19420;
        scdebug_error( c12259, 
                       c12260, CONS( i15976, EMPTYLIST ) );
L19420:
        X5 = C_FIXED( STRING_LENGTH( i15976 ) );
        X6 = CONS( scrt3_substring( s15975, X3, X1 ), 
                   EMPTYLIST );
        X6 = CONS( pregexp_lace_2daux_580391d8( s15975, 
                                                i15976, X5, X2 ), 
                   X6 );
        POPSTACKTRACE( scrt3_string_2dappend( CONS( scrt3_substring( s15975, 
                                                                     _TSCP( 0 ), 
                                                                     X4 ), 
                                                    X6 ) ) );
L19407:
        POPSTACKTRACE( s15975 );
}

DEFTSCP( pregexp_pregexp_2dreplace_2a_v );
DEFCSTRING( t19423, "PREGEXP-REPLACE*" );

TSCP  pregexp_pregexp_2dreplace_2a( p16014, s16015, i16016 )
        TSCP  p16014, s16015, i16016;
{
        TSCP  X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t19423 );
        if  ( AND( EQ( TSCPTAG( i16016 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( i16016 ), STRINGTAG ) )
            )  goto L19426;
        scdebug_error( c12259, 
                       c12260, CONS( i16016, EMPTYLIST ) );
L19426:
        X1 = C_FIXED( STRING_LENGTH( i16016 ) );
        if  ( AND( EQ( TSCPTAG( s16015 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s16015 ), STRINGTAG ) )
            )  goto L19429;
        scdebug_error( c12259, 
                       c12260, CONS( s16015, EMPTYLIST ) );
L19429:
        X2 = C_FIXED( STRING_LENGTH( s16015 ) );
        if  ( NOT( AND( EQ( TSCPTAG( p16014 ), EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( p16014 ), 
                            STRINGTAG ) ) ) )  goto L19431;
        X3 = pregexp_pregexp( p16014 );
        goto L19432;
L19431:
        X3 = p16014;
L19432:
        X4 = sc_emptystring;
        X5 = _TSCP( 0 );
        X6 = X4;
L19436:
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L19438;
        if  ( LT( _S2CINT( X5 ), _S2CINT( X2 ) ) )  goto L19442;
        POPSTACKTRACE( X6 );
L19438:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X5, X2 ) ) )  goto L19442;
        POPSTACKTRACE( X6 );
L19442:
        X8 = CONS( X2, EMPTYLIST );
        X7 = pregexp_dpositions_4faf9e1( X3, 
                                         s16015, 
                                         CONS( X5, X8 ) );
        if  ( FALSE( X7 ) )  goto L19446;
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L19449;
        scrt1__24__car_2derror( X7 );
L19449:
        X9 = PAIR_CAR( X7 );
        if  ( EQ( TSCPTAG( X9 ), PAIRTAG ) )  goto L19452;
        scrt1__24__cdr_2derror( X9 );
L19452:
        X8 = PAIR_CDR( X9 );
        X9 = CONS( pregexp_lace_2daux_580391d8( s16015, 
                                                i16016, X1, X7 ), 
                   EMPTYLIST );
        X11 = PAIR_CAR( X7 );
        if  ( EQ( TSCPTAG( X11 ), PAIRTAG ) )  goto L19456;
        scrt1__24__car_2derror( X11 );
L19456:
        X10 = PAIR_CAR( X11 );
        X9 = CONS( scrt3_substring( s16015, X5, X10 ), 
                   X9 );
        X6 = scrt3_string_2dappend( CONS( X6, X9 ) );
        X5 = X8;
        GOBACK( L19436 );
L19446:
        if  ( BITAND( BITOR( _S2CINT( X5 ), 
                             _S2CINT( _TSCP( 0 ) ) ), 
                      3 ) )  goto L19459;
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L19463;
        POPSTACKTRACE( s16015 );
L19459:
        if  ( FALSE( scrt2__3d_2dtwo( X5, _TSCP( 0 ) ) ) )  goto L19463;
        POPSTACKTRACE( s16015 );
L19463:
        X7 = CONS( scrt3_substring( s16015, X5, X2 ), 
                   EMPTYLIST );
        POPSTACKTRACE( scrt3_string_2dappend( CONS( X6, X7 ) ) );
}

DEFTSCP( pregexp_pregexp_2dquote_v );
DEFCSTRING( t19466, "PREGEXP-QUOTE" );

TSCP  pregexp_pregexp_2dquote( s16077 )
        TSCP  s16077;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t19466 );
        if  ( AND( EQ( TSCPTAG( s16077 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s16077 ), STRINGTAG ) )
            )  goto L19469;
        scdebug_error( c12259, 
                       c12260, CONS( s16077, EMPTYLIST ) );
L19469:
        X2 = C_FIXED( STRING_LENGTH( s16077 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19472;
        X1 = _TSCP( IDIFFERENCE( _S2CINT( X2 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L19473;
L19472:
        X1 = scrt2__2d_2dtwo( X2, _TSCP( 4 ) );
L19473:
        X2 = X1;
        X3 = EMPTYLIST;
L19476:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 0 ) ) ), 
                      3 ) )  goto L19478;
        if  ( LT( _S2CINT( X2 ), _S2CINT( _TSCP( 0 ) ) ) )  goto L19482;
        goto L19483;
L19478:
        if  ( TRUE( scrt2__3c_2dtwo( X2, _TSCP( 0 ) ) ) )  goto L19482;
L19483:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L19486;
        X4 = _TSCP( IDIFFERENCE( _S2CINT( X2 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L19487;
L19486:
        X4 = scrt2__2d_2dtwo( X2, _TSCP( 4 ) );
L19487:
        if  ( EQ( TSCPTAG( X2 ), FIXNUMTAG ) )  goto L19489;
        scdebug_error( c12237, 
                       c12238, CONS( X2, EMPTYLIST ) );
L19489:
        X6 = BOOLEAN( LT( _S2CINT( X2 ), 0 ) );
        if  ( TRUE( X6 ) )  goto L19495;
        X7 = C_FIXED( STRING_LENGTH( s16077 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X7 ) ), 
                      3 ) )  goto L19499;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X7 ) ) )  goto L19495;
        goto L19506;
L19499:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X2, X7 ) ) )  goto L19506;
L19495:
        scdebug_error( c12237, 
                       c12261, CONS( X2, EMPTYLIST ) );
L19506:
        X5 = C_CHAR( STRING_CHAR( s16077, X2 ) );
        if  ( FALSE( scrt1_memv( X5, c16100 ) ) )  goto L19508;
        X6 = sc_cons( X5, X3 );
        X3 = sc_cons( _TSCP( 23570 ), X6 );
        goto L19509;
L19508:
        X3 = sc_cons( X5, X3 );
L19509:
        X2 = X4;
        GOBACK( L19476 );
L19482:
        POPSTACKTRACE( scrt3_list_2d_3estring( X3 ) );
}

void scrt3__init();
void qobischeme__init();
void scrt6__init();
void scrt1__init();
void scrt2__init();
void scdebug__init();

static void  init_modules( compiler_version )
        char *compiler_version;
{
        scrt3__init();
        qobischeme__init();
        scrt6__init();
        scrt1__init();
        scrt2__init();
        scdebug__init();
        MAXDISPLAY( 22 );
}

void  pregexp__init()
{
        TSCP  X3, X2, X1;

        static int  init = 0;
        if  (init)  return;
        init = 1;
        INITHEAP( 0, 0, 0, 0 );
        init_constants();
        init_modules( "(pregexp SCHEME->C COMPILER 15mar93jfb)" );
        sc_segv__handlers();
        INITIALIZEVAR( t16810, 
                       ADR( pregexp_xp_2d1_2d0_d5be5fd9_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      pregexp_xp_2d1_2d0_d5be5fd9, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16812, 
                       ADR( pregexp_xp_2d3_2d0_af7e0cb9_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      pregexp_xp_2d3_2d0_af7e0cb9, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16814, 
                       ADR( pregexp_xp_2d5_2d0_203ef919_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      pregexp_xp_2d5_2d0_203ef919, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16816, 
                       ADR( pregexp_version_2a_627fa14e_v ), 
                       _TSCP( 80202008 ) );
        INITIALIZEVAR( t16817, 
                       ADR( pregexp__2dchar_2a_8489832_v ), 
                       _TSCP( 15122 ) );
        if  ( EQ( TSCPIMMEDIATETAG( _TSCP( 24850 ) ), 
                  CHARACTERTAG ) )  goto L16820;
        scdebug_error( c12070, 
                       c12071, 
                       CONS( _TSCP( 24850 ), EMPTYLIST ) );
L16820:
        X1 = CHAR_FIX( _TSCP( 24850 ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 388 ) ) ), 
                      3 ) )  goto L16823;
        X2 = _TSCP( IDIFFERENCE( _S2CINT( X1 ), 
                                 _S2CINT( _TSCP( 388 ) ) ) );
        goto L16824;
L16823:
        X2 = scrt2__2d_2dtwo( X1, _TSCP( 388 ) );
L16824:
        INITIALIZEVAR( t16818, 
                       ADR( pregexp_r_2dint_2a_a0f5bbd1_v ), X2 );
        X2 = pregexp_r_2dint_2a_a0f5bbd1_v;
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 52 ) ), 
                             _S2CINT( X2 ) ), 
                      3 ) )  goto L16827;
        X1 = _TSCP( IPLUS( _S2CINT( _TSCP( 52 ) ), 
                           _S2CINT( X2 ) ) );
        goto L16828;
L16827:
        X1 = scrt2__2b_2dtwo( _TSCP( 52 ), X2 );
L16828:
        X2 = BOOLEAN( NEQ( TSCPTAG( X1 ), FIXNUMTAG ) );
        if  ( TRUE( X2 ) )  goto L16834;
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 0 ) ) ), 
                      3 ) )  goto L16835;
        X3 = BOOLEAN( LT( _S2CINT( X1 ), 
                          _S2CINT( _TSCP( 0 ) ) ) );
        goto L16836;
L16835:
        X3 = scrt2__3c_2dtwo( X1, _TSCP( 0 ) );
L16836:
        if  ( TRUE( X3 ) )  goto L16834;
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 1020 ) ) ), 
                      3 ) )  goto L16843;
        if  ( GT( _S2CINT( X1 ), _S2CINT( _TSCP( 1020 ) ) ) )  goto L16834;
        goto L16850;
L16843:
        if  ( FALSE( scrt2__3e_2dtwo( X1, _TSCP( 1020 ) ) ) )  goto L16850;
L16834:
        scdebug_error( c12100, 
                       c12101, CONS( X1, EMPTYLIST ) );
L16850:
        INITIALIZEVAR( t16825, 
                       ADR( pregexp__2dchar_2a_2f258f12_v ), 
                       FIX_CHAR( X1 ) );
        X2 = pregexp_r_2dint_2a_a0f5bbd1_v;
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 36 ) ), 
                             _S2CINT( X2 ) ), 
                      3 ) )  goto L16853;
        X1 = _TSCP( IPLUS( _S2CINT( _TSCP( 36 ) ), 
                           _S2CINT( X2 ) ) );
        goto L16854;
L16853:
        X1 = scrt2__2b_2dtwo( _TSCP( 36 ), X2 );
L16854:
        X2 = BOOLEAN( NEQ( TSCPTAG( X1 ), FIXNUMTAG ) );
        if  ( TRUE( X2 ) )  goto L16860;
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 0 ) ) ), 
                      3 ) )  goto L16861;
        X3 = BOOLEAN( LT( _S2CINT( X1 ), 
                          _S2CINT( _TSCP( 0 ) ) ) );
        goto L16862;
L16861:
        X3 = scrt2__3c_2dtwo( X1, _TSCP( 0 ) );
L16862:
        if  ( TRUE( X3 ) )  goto L16860;
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 1020 ) ) ), 
                      3 ) )  goto L16869;
        if  ( GT( _S2CINT( X1 ), _S2CINT( _TSCP( 1020 ) ) ) )  goto L16860;
        goto L16876;
L16869:
        if  ( FALSE( scrt2__3e_2dtwo( X1, _TSCP( 1020 ) ) ) )  goto L16876;
L16860:
        scdebug_error( c12100, 
                       c12101, CONS( X1, EMPTYLIST ) );
L16876:
        INITIALIZEVAR( t16851, 
                       ADR( pregexp__2dchar_2a_cd905c7c_v ), 
                       FIX_CHAR( X1 ) );
        INITIALIZEVAR( t16877, 
                       ADR( pregexp_tive_3f_2a_bd6b8339_v ), 
                       TRUEVALUE );
        INITIALIZEVAR( t16878, 
                       ADR( pregexp_pregexp_2dreverse_21_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      pregexp_pregexp_2dreverse_21, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16889, 
                       ADR( pregexp_pregexp_2derror_v ), 
                       MAKEPROCEDURE( 0, 
                                      1, 
                                      pregexp_pregexp_2derror, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16901, 
                       ADR( pregexp__2dpattern_829cfa27_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp__2dpattern_829cfa27, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16985, 
                       ADR( pregexp_d_2dbranch_201e770d_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_d_2dbranch_201e770d, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t17043, 
                       ADR( pregexp_ad_2dpiece_b70ed9c5_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_ad_2dpiece_b70ed9c5, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t17229, 
                       ADR( pregexp_d_2dnumber_1f1ad78b_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_d_2dnumber_1f1ad78b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t17309, 
                       ADR( pregexp_ped_2dchar_b91fbb8c_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_ped_2dchar_b91fbb8c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t17401, 
                       ADR( pregexp_ar_2dclass_27b9b680_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_ar_2dclass_27b9b680, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t17501, 
                       ADR( pregexp_ter_2dtype_740a2ea3_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_ter_2dtype_740a2ea3, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t17649, 
                       ADR( pregexp_subpattern_ac026cd3_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_subpattern_ac026cd3, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t17716, 
                       ADR( pregexp_2dif_2dany_74203067_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_2dif_2dany_74203067, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t17941, 
                       ADR( pregexp_pregexp_2dread_2dnums_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_pregexp_2dread_2dnums, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t18053, 
                       ADR( pregexp_har_2dlist_c3a17f27_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      pregexp_har_2dlist_c3a17f27, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t18061, 
                       ADR( pregexp_har_2dlist_9cba0ef7_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_har_2dlist_9cba0ef7, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t18241, 
                       ADR( pregexp_ng_2dmatch_8f735cce_v ), 
                       MAKEPROCEDURE( 6, 
                                      0, 
                                      pregexp_ng_2dmatch_8f735cce, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t18325, 
                       ADR( pregexp__2dword_3f_96ff223a_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      pregexp__2dword_3f_96ff223a, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t18336, 
                       ADR( pregexp_2dclass_3f_7022b0e_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      pregexp_2dclass_3f_7022b0e, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t18460, 
                       ADR( pregexp_oundary_3f_80a8c00c_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_oundary_3f_80a8c00c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t18530, 
                       ADR( pregexp_pregexp_2dlist_2dref_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      pregexp_pregexp_2dlist_2dref, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t18553, 
                       ADR( pregexp_ref_2dlist_bf9bf990_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      pregexp_ref_2dlist_bf9bf990, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t18564, 
                       ADR( pregexp_ions_2daux_a110402e_v ), 
                       MAKEPROCEDURE( 6, 
                                      0, 
                                      pregexp_ions_2daux_a110402e, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t19145, 
                       ADR( pregexp_lace_2daux_580391d8_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      pregexp_lace_2daux_580391d8, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t19275, 
                       ADR( pregexp_pregexp_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      pregexp_pregexp, EMPTYLIST ) );
        INITIALIZEVAR( t19284, 
                       ADR( pregexp_dpositions_4faf9e1_v ), 
                       MAKEPROCEDURE( 2, 
                                      1, 
                                      pregexp_dpositions_4faf9e1, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t19322, 
                       ADR( pregexp_pregexp_2dmatch_v ), 
                       MAKEPROCEDURE( 2, 
                                      1, 
                                      pregexp_pregexp_2dmatch, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t19349, 
                       ADR( pregexp_pregexp_2dsplit_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      pregexp_pregexp_2dsplit, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t19400, 
                       ADR( pregexp_pregexp_2dreplace_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_pregexp_2dreplace, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t19423, 
                       ADR( pregexp_pregexp_2dreplace_2a_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      pregexp_pregexp_2dreplace_2a, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t19466, 
                       ADR( pregexp_pregexp_2dquote_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      pregexp_pregexp_2dquote, 
                                      EMPTYLIST ) );
        return;
}
