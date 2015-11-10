
/* SCHEME->C */

#include <objects.h>

void toollib_2dc_2dbindings__init();
DEFCSTRING( t12770, "Argument is not a VECTOR: ~s" );
DEFSTATICTSCP( c12358 );
DEFSTATICTSCP( c12357 );
DEFCSTRING( t12771, "Argument not a CHAR: ~s" );
DEFSTATICTSCP( c12264 );
DEFSTATICTSCP( c12263 );
DEFCSTRING( t12772, "Argument is not a STRING: ~s" );
DEFSTATICTSCP( c12252 );
DEFSTATICTSCP( c12251 );
DEFCSTRING( t12773, "Argument not a PAIR: ~s" );
DEFSTATICTSCP( c12192 );
DEFSTATICTSCP( c12191 );
DEFCSTRING( t12774, "_" );
DEFSTATICTSCP( c12154 );
DEFCSTRING( t12775, "Argument is not a SYMBOL: ~s" );
DEFSTATICTSCP( c12153 );
DEFSTATICTSCP( c12152 );
DEFCSTRING( t12776, "-" );
DEFSTATICTSCP( c12147 );

static void  init_constants()
{
        c12358 = CSTRING_TSCP( t12770 );
        CONSTANTEXP( ADR( c12358 ) );
        c12357 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR-LENGTH" ) );
        CONSTANTEXP( ADR( c12357 ) );
        c12264 = CSTRING_TSCP( t12771 );
        CONSTANTEXP( ADR( c12264 ) );
        c12263 = STRINGTOSYMBOL( CSTRING_TSCP( "CHAR->INTEGER" ) );
        CONSTANTEXP( ADR( c12263 ) );
        c12252 = CSTRING_TSCP( t12772 );
        CONSTANTEXP( ADR( c12252 ) );
        c12251 = STRINGTOSYMBOL( CSTRING_TSCP( "STRING-LENGTH" ) );
        CONSTANTEXP( ADR( c12251 ) );
        c12192 = CSTRING_TSCP( t12773 );
        CONSTANTEXP( ADR( c12192 ) );
        c12191 = STRINGTOSYMBOL( CSTRING_TSCP( "SET-CDR!" ) );
        CONSTANTEXP( ADR( c12191 ) );
        c12154 = CSTRING_TSCP( t12774 );
        CONSTANTEXP( ADR( c12154 ) );
        c12153 = CSTRING_TSCP( t12775 );
        CONSTANTEXP( ADR( c12153 ) );
        c12152 = STRINGTOSYMBOL( CSTRING_TSCP( "SYMBOL->STRING" ) );
        CONSTANTEXP( ADR( c12152 ) );
        c12147 = CSTRING_TSCP( t12776 );
        CONSTANTEXP( ADR( c12147 ) );
}

DEFTSCP( dbindings_gs_2d1_2d0_67ee31d0_v );
DEFCSTRING( t12777, "gensym-toollib_2dc_2dbindings-1-0" );

TSCP  dbindings_gs_2d1_2d0_67ee31d0(  )
{
        PUSHSTACKTRACE( t12777 );
        POPSTACKTRACE( 0 );}
  #include<stddef.h>
int gensym_toollib_2dc_2dbindings_2_0(){ return 1;gensym_toollib_2dc_2dbindings_2_0( );
}

DEFTSCP( dbindings_gs_2d3_2d0_1d2e62b0_v );
DEFCSTRING( t12779, "gensym-toollib_2dc_2dbindings-3-0" );

TSCP  dbindings_gs_2d3_2d0_1d2e62b0(  )
{
        PUSHSTACKTRACE( t12779 );
        POPSTACKTRACE( 0 );}
  #include<stdlib.h>
int gensym_toollib_2dc_2dbindings_4_0(){ return 1;gensym_toollib_2dc_2dbindings_4_0( );
}

DEFTSCP( dbindings_gs_2d5_2d0_926e9710_v );
DEFCSTRING( t12781, "gensym-toollib_2dc_2dbindings-5-0" );

TSCP  dbindings_gs_2d5_2d0_926e9710(  )
{
        PUSHSTACKTRACE( t12781 );
        POPSTACKTRACE( 0 );}
  #include<string.h>
int gensym_toollib_2dc_2dbindings_6_0(){ return 1;gensym_toollib_2dc_2dbindings_6_0( );
}

DEFTSCP( dbindings_gs_2d7_2d0_e8aec470_v );
DEFCSTRING( t12783, "gensym-toollib_2dc_2dbindings-7-0" );

TSCP  dbindings_gs_2d7_2d0_e8aec470(  )
{
        PUSHSTACKTRACE( t12783 );
        POPSTACKTRACE( 0 );}
  #include<stdlib.h>
int gensym_toollib_2dc_2dbindings_8_0(){ return 1;gensym_toollib_2dc_2dbindings_8_0( );
}

DEFTSCP( dbindings_gs_2d9_2d0_579e7a11_v );
DEFCSTRING( t12785, "gensym-toollib_2dc_2dbindings-9-0" );

TSCP  dbindings_gs_2d9_2d0_579e7a11(  )
{
        PUSHSTACKTRACE( t12785 );
        POPSTACKTRACE( 0 );}
  #include<stdio.h>
int gensym_toollib_2dc_2dbindings_10_0(){ return 1;gensym_toollib_2dc_2dbindings_10_0( );
}

DEFTSCP( dbindings_s_2d11_2d0_f9c520e9_v );
DEFCSTRING( t12787, "gensym-toollib_2dc_2dbindings-11-0" );

TSCP  dbindings_s_2d11_2d0_f9c520e9(  )
{
        PUSHSTACKTRACE( t12787 );
        POPSTACKTRACE( 0 );}
  #include<sys/types.h>
int gensym_toollib_2dc_2dbindings_12_0(){ return 1;gensym_toollib_2dc_2dbindings_12_0( );
}

DEFTSCP( dbindings_s_2d13_2d0_83057389_v );
DEFCSTRING( t12789, "gensym-toollib_2dc_2dbindings-13-0" );

TSCP  dbindings_s_2d13_2d0_83057389(  )
{
        PUSHSTACKTRACE( t12789 );
        POPSTACKTRACE( 0 );}
  #include<unistd.h>
int gensym_toollib_2dc_2dbindings_14_0(){ return 1;gensym_toollib_2dc_2dbindings_14_0( );
}

DEFTSCP( dbindings_s_2d15_2d0_c458629_v );
DEFCSTRING( t12791, "gensym-toollib_2dc_2dbindings-15-0" );

TSCP  dbindings_s_2d15_2d0_c458629(  )
{
        PUSHSTACKTRACE( t12791 );
        POPSTACKTRACE( 0 );}
  #include<gmp.h>
int gensym_toollib_2dc_2dbindings_16_0(){ return 1;gensym_toollib_2dc_2dbindings_16_0( );
}

DEFTSCP( toollib_2dc_2dbindings_curry2_v );
DEFCSTRING( t12793, "CURRY2" );

TSCP  toollib_2dc_2dbindings_l12111( y12112, c12797 )
        TSCP  y12112, c12797;
{
        TSCP  X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12111 [inside CURRY2]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12797, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12797, 1 );
        X4 = DISPLAY( 0 );
        X4 = UNKNOWNCALL( X4, 2 );
        X3 = VIA( PROCEDURE_CODE( X4 ) )( DISPLAY( 1 ), 
                                          y12112, 
                                          PROCEDURE_CLOSURE( X4 ) );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        POPSTACKTRACE( X3 );
}

TSCP  toollib_2dc_2dbindings_l12109( x12110, c12795 )
        TSCP  x12110, c12795;
{
        TSCP  X2, X1;
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12109 [inside CURRY2]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12795, 0 );
        DISPLAY( 1 ) = x12110;
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12111, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ) ) );
        DISPLAY( 0 ) = X1;
        SDVAL = X2;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

TSCP  toollib_2dc_2dbindings_curry2( f12108 )
        TSCP  f12108;
{
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12793 );
        DISPLAY( 0 ) = f12108;
        SDVAL = MAKEPROCEDURE( 1, 
                               0, 
                               toollib_2dc_2dbindings_l12109, 
                               MAKECLOSURE( EMPTYLIST, 
                                            1, DISPLAY( 0 ) ) );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( toollib_2dc_2dbindings_malloc_v );
DEFCSTRING( t12799, "MALLOC" );

TSCP  toollib_2dc_2dbindings_malloc( g12114 )
        TSCP  g12114;
{
        PUSHSTACKTRACE( t12799 );
        POPSTACKTRACE( POINTER_TSCP( malloc( sc_tscp_int( g12114 ) ) ) );
}

DEFTSCP( toollib_2dc_2dbindings_memcpy_v );
DEFCSTRING( t12801, "MEMCPY" );

TSCP  toollib_2dc_2dbindings_memcpy( g12118, g12119, g12120 )
        TSCP  g12118, g12119, g12120;
{
        PUSHSTACKTRACE( t12801 );
        POPSTACKTRACE( POINTER_TSCP( memcpy( TSCP_POINTER( g12118 ), 
                                             TSCP_POINTER( g12119 ), 
                                             sc_tscp_int( g12120 ) ) ) );
}

DEFTSCP( toollib_2dc_2dbindings_bzero_v );
DEFCSTRING( t12803, "BZERO" );

TSCP  toollib_2dc_2dbindings_bzero( g12126, g12127 )
        TSCP  g12126, g12127;
{
        PUSHSTACKTRACE( t12803 );
        bzero( TSCP_POINTER( g12126 ), 
               sc_tscp_int( g12127 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( toollib_2dc_2dbindings_free_v );
DEFCSTRING( t12806, "FREE" );

TSCP  toollib_2dc_2dbindings_free( g12133 )
        TSCP  g12133;
{
        PUSHSTACKTRACE( t12806 );
        free( TSCP_POINTER( g12133 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( dbindings_th_2dalloc_20298354_v );
DEFCSTRING( t12809, "WITH-ALLOC" );

TSCP  dbindings_th_2dalloc_20298354( x12138, f12139 )
        TSCP  x12138, f12139;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t12809 );
        X1 = toollib_2dc_2dbindings_malloc( x12138 );
        toollib_2dc_2dbindings_bzero( X1, x12138 );
        X3 = f12139;
        X3 = UNKNOWNCALL( X3, 1 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( X1, 
                                          PROCEDURE_CLOSURE( X3 ) );
        toollib_2dc_2dbindings_free( X1 );
        POPSTACKTRACE( X2 );
}

DEFTSCP( dbindings_c_2dstring_a000da03_v );
DEFCSTRING( t12814, "SYMBOL->C-STRING" );
EXTERNTSCPP( pregexp_pregexp_2dreplace_2a, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( pregexp_pregexp_2dreplace_2a_v );
EXTERNTSCPP( qobischeme_string_2ddowncase, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_string_2ddowncase_v );
EXTERNTSCPP( scdebug_error, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scdebug_error_v );

TSCP  dbindings_c_2dstring_a000da03( s12146 )
        TSCP  s12146;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t12814 );
        if  ( AND( EQ( TSCPTAG( s12146 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12146 ), SYMBOLTAG ) )
            )  goto L12817;
        scdebug_error( c12152, 
                       c12153, CONS( s12146, EMPTYLIST ) );
L12817:
        X2 = SYMBOL_NAME( s12146 );
        X1 = qobischeme_string_2ddowncase( X2 );
        POPSTACKTRACE( pregexp_pregexp_2dreplace_2a( c12147, 
                                                     X1, c12154 ) );
}

DEFTSCP( dbindings_d_3esymbol_d89bd1b0_v );
DEFCSTRING( t12819, "C-STRING->SYMBOL" );
EXTERNTSCPP( sc_string_2d_3esymbol, XAL1( TSCP ) );
EXTERNTSCP( sc_string_2d_3esymbol_v );
EXTERNTSCPP( scrt3_list_2d_3estring, XAL1( TSCP ) );
EXTERNTSCP( scrt3_list_2d_3estring_v );
EXTERNTSCPP( scrt3_string_2d_3elist, XAL1( TSCP ) );
EXTERNTSCP( scrt3_string_2d_3elist_v );
EXTERNTSCPP( scrt3_char_2dupcase, XAL1( TSCP ) );
EXTERNTSCP( scrt3_char_2dupcase_v );
EXTERNTSCPP( sc_cons, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_cons_v );
EXTERNTSCPP( scrt1__24__car_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__car_2derror_v );

TSCP  dbindings_d_3esymbol_d89bd1b0( s12156 )
        TSCP  s12156;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t12819 );
        X4 = pregexp_pregexp_2dreplace_2a( c12154, s12156, c12147 );
        X3 = scrt3_string_2d_3elist( X4 );
        X4 = X3;
        X5 = EMPTYLIST;
        X6 = EMPTYLIST;
L12823:
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L12824;
        X2 = X5;
        goto L12831;
L12824:
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L12827;
        scrt1__24__car_2derror( X4 );
L12827:
        X9 = PAIR_CAR( X4 );
        X8 = scrt3_char_2dupcase( X9 );
        X7 = sc_cons( X8, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L12830;
        X8 = PAIR_CDR( X4 );
        X6 = X7;
        X5 = X7;
        X4 = X8;
        GOBACK( L12823 );
L12830:
        X8 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L12835;
        scdebug_error( c12191, 
                       c12192, CONS( X6, EMPTYLIST ) );
L12835:
        X6 = SETGEN( PAIR_CDR( X6 ), X7 );
        X4 = X8;
        GOBACK( L12823 );
L12831:
        X1 = scrt3_list_2d_3estring( X2 );
        POPSTACKTRACE( sc_string_2d_3esymbol( X1 ) );
}

DEFTSCP( dbindings_e_2dstream_4a3d87a7_v );
DEFCSTRING( t12837, "WITH-FILE-STREAM" );
EXTERNTSCPP( toollib_2dc_2dbindings_fopen, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( toollib_2dc_2dbindings_fopen_v );
EXTERNTSCPP( toollib_2dc_2dbindings_fclose, XAL1( TSCP ) );
EXTERNTSCP( toollib_2dc_2dbindings_fclose_v );

TSCP  dbindings_e_2dstream_4a3d87a7( f12203, f12204, m12205 )
        TSCP  f12203, f12204, m12205;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t12837 );
        X1 = toollib_2dc_2dbindings_fopen( f12204, m12205 );
        X3 = f12203;
        X3 = UNKNOWNCALL( X3, 1 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( X1, 
                                          PROCEDURE_CLOSURE( X3 ) );
        toollib_2dc_2dbindings_fclose( X1 );
        POPSTACKTRACE( X2 );
}

DEFTSCP( dbindings_r_2dstream_f6149db3_v );
DEFCSTRING( t12841, "WITH-BUFFER-STREAM" );
EXTERNTSCPP( dbindings_fmemopen_3521495d, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_fmemopen_3521495d_v );

TSCP  dbindings_r_2dstream_f6149db3( f12211, 
                                     b12212, s12213, m12214 )
        TSCP  f12211, b12212, s12213, m12214;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t12841 );
        X1 = dbindings_fmemopen_3521495d( b12212, s12213, m12214 );
        X3 = f12211;
        X3 = UNKNOWNCALL( X3, 1 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( X1, 
                                          PROCEDURE_CLOSURE( X3 ) );
        toollib_2dc_2dbindings_fclose( X1 );
        POPSTACKTRACE( X2 );
}

DEFTSCP( toollib_2dc_2dbindings_fclose_v );
DEFCSTRING( t12845, "FCLOSE" );

TSCP  toollib_2dc_2dbindings_fclose( g12220 )
        TSCP  g12220;
{
        PUSHSTACKTRACE( t12845 );
        fclose( TSCP_POINTER( g12220 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( toollib_2dc_2dbindings_fopen_v );
DEFCSTRING( t12848, "FOPEN" );

TSCP  toollib_2dc_2dbindings_fopen( g12225, g12226 )
        TSCP  g12225, g12226;
{
        PUSHSTACKTRACE( t12848 );
        POPSTACKTRACE( POINTER_TSCP( fopen( TSCP_POINTER( g12225 ), 
                                            TSCP_POINTER( g12226 ) ) ) );
}

DEFTSCP( dbindings_fmemopen_3521495d_v );
DEFCSTRING( t12850, "FMEMOPEN" );

TSCP  dbindings_fmemopen_3521495d( g12231, g12232, g12233 )
        TSCP  g12231, g12232, g12233;
{
        PUSHSTACKTRACE( t12850 );
        POPSTACKTRACE( POINTER_TSCP( fmemopen( TSCP_POINTER( g12231 ), 
                                               TSCP_S2CUINT( g12232 ), 
                                               TSCP_POINTER( g12233 ) ) ) );
}

DEFTSCP( dbindings_c_2dstring_6099dec9_v );
DEFCSTRING( t12852, "WITH-C-STRING" );
EXTERNTSCPP( scrt2__2b_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2b_2dtwo_v );
EXTERNTSCPP( obischeme__2dindexed_d1069d4, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( obischeme__2dindexed_d1069d4_v );
EXTERNTSCPP( scrt4_c_2dbyte_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dbyte_2dset_21_v );

TSCP  toollib_2dc_2dbindings_l12256( c12257, i12258, c12862 )
        TSCP  c12257, i12258, c12862;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12256 [inside WITH-C-STRING\
]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12862, 0 );
        if  ( EQ( TSCPIMMEDIATETAG( c12257 ), CHARACTERTAG ) )  goto L12865;
        scdebug_error( c12263, 
                       c12264, CONS( c12257, EMPTYLIST ) );
L12865:
        X3 = CHAR_FIX( c12257 );
        X2 = scrt4_c_2dbyte_2dset_21( DISPLAY( 2 ), 
                                      i12258, X3 );
        DISPLAY( 2 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  toollib_2dc_2dbindings_l12254( b12255, c12860 )
        TSCP  b12255, c12860;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12254 [inside WITH-C-STRING\
]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12860, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12860, 1 );
        DISPLAY( 2 ) = b12255;
        X4 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dc_2dbindings_l12256, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 2 ) ) );
        X5 = scrt3_string_2d_3elist( DISPLAY( 0 ) );
        obischeme__2dindexed_d1069d4( X4, X5 );
        X5 = DISPLAY( 0 );
        if  ( AND( EQ( TSCPTAG( X5 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X5 ), STRINGTAG ) ) )  goto L12868;
        scdebug_error( c12251, 
                       c12252, CONS( X5, EMPTYLIST ) );
L12868:
        X4 = C_FIXED( STRING_LENGTH( X5 ) );
        scrt4_c_2dbyte_2dset_21( DISPLAY( 2 ), 
                                 X4, _TSCP( 0 ) );
        X7 = DISPLAY( 0 );
        if  ( AND( EQ( TSCPTAG( X7 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X7 ), STRINGTAG ) ) )  goto L12871;
        scdebug_error( c12251, 
                       c12252, CONS( X7, EMPTYLIST ) );
L12871:
        X6 = C_FIXED( STRING_LENGTH( X7 ) );
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12874;
        X5 = _TSCP( IPLUS( _S2CINT( X6 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L12875;
L12874:
        X5 = scrt2__2b_2dtwo( X6, _TSCP( 4 ) );
L12875:
        X4 = DISPLAY( 1 );
        X4 = UNKNOWNCALL( X4, 2 );
        X3 = VIA( PROCEDURE_CODE( X4 ) )( DISPLAY( 2 ), 
                                          X5, 
                                          PROCEDURE_CLOSURE( X4 ) );
        DISPLAY( 0 ) = X1;
        DISPLAY( 1 ) = X2;
        SDVAL = X3;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

TSCP  dbindings_c_2dstring_6099dec9( s12239, f12240 )
        TSCP  s12239, f12240;
{
        TSCP  X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12852 );
        DISPLAY( 0 ) = s12239;
        DISPLAY( 1 ) = f12240;
        X3 = DISPLAY( 0 );
        if  ( AND( EQ( TSCPTAG( X3 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X3 ), STRINGTAG ) ) )  goto L12855;
        scdebug_error( c12251, 
                       c12252, CONS( X3, EMPTYLIST ) );
L12855:
        X2 = C_FIXED( STRING_LENGTH( X3 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12858;
        X1 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L12859;
L12858:
        X1 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L12859:
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12254, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        SDVAL = dbindings_th_2dalloc_20298354( X1, X2 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings__2dstrings_2bd4c34c_v );
DEFCSTRING( t12876, "WITH-C-STRINGS" );
EXTERNTSCPP( qobischeme_map_2dvector, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dvector_v );
EXTERNTSCPP( dbindings_c_2dstring_64a7b683, XAL1( TSCP ) );
EXTERNTSCP( dbindings_c_2dstring_64a7b683_v );

TSCP  toollib_2dc_2dbindings_l12288( s12289, c12878 )
        TSCP  s12289, c12878;
{
        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12288 [inside WITH-C-STRING\
S]" );
        POPSTACKTRACE( dbindings_c_2dstring_64a7b683( s12289 ) );
}

EXTERNTSCPP( dbindings_2dpointers_a3114ab5, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_2dpointers_a3114ab5_v );
EXTERNTSCPP( obischeme_h_2dvector_fe309b1e, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( obischeme_h_2dvector_fe309b1e_v );

TSCP  toollib_2dc_2dbindings_l12286( c12287, c12882 )
        TSCP  c12287, c12882;
{
        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12286 [inside WITH-C-STRING\
S]" );
        POPSTACKTRACE( toollib_2dc_2dbindings_free( c12287 ) );
}

TSCP  dbindings__2dstrings_2bd4c34c( f12280, s12281 )
        TSCP  f12280, s12281;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t12876 );
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12288, EMPTYLIST );
        X1 = qobischeme_map_2dvector( X2, s12281, EMPTYLIST );
        X2 = dbindings_2dpointers_a3114ab5( f12280, X1 );
        X3 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12286, EMPTYLIST );
        obischeme_h_2dvector_fe309b1e( X3, X1, EMPTYLIST );
        POPSTACKTRACE( X2 );
}

DEFTSCP( dbindings_c_2dstring_64a7b683_v );
DEFCSTRING( t12884, "STRING->C-STRING" );

TSCP  toollib_2dc_2dbindings_l12294( c12295, i12296, c12893 )
        TSCP  c12295, i12296, c12893;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12294 [inside STRING->C-STR\
ING]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12893, 0 );
        if  ( EQ( TSCPIMMEDIATETAG( c12295 ), CHARACTERTAG ) )  goto L12896;
        scdebug_error( c12263, 
                       c12264, CONS( c12295, EMPTYLIST ) );
L12896:
        X3 = CHAR_FIX( c12295 );
        X2 = scrt4_c_2dbyte_2dset_21( DISPLAY( 0 ), 
                                      i12296, X3 );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  dbindings_c_2dstring_64a7b683( s12291 )
        TSCP  s12291;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12884 );
        if  ( AND( EQ( TSCPTAG( s12291 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12291 ), STRINGTAG ) )
            )  goto L12887;
        scdebug_error( c12251, 
                       c12252, CONS( s12291, EMPTYLIST ) );
L12887:
        X2 = C_FIXED( STRING_LENGTH( s12291 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12890;
        X1 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L12891;
L12890:
        X1 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L12891:
        DISPLAY( 0 ) = toollib_2dc_2dbindings_malloc( X1 );
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dc_2dbindings_l12294, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X2 = scrt3_string_2d_3elist( s12291 );
        obischeme__2dindexed_d1069d4( X1, X2 );
        X1 = C_FIXED( STRING_LENGTH( s12291 ) );
        scrt4_c_2dbyte_2dset_21( DISPLAY( 0 ), 
                                 X1, _TSCP( 0 ) );
        SDVAL = DISPLAY( 0 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings__3estrings_3b44cc18_v );
DEFCSTRING( t12899, "C-NULL-SEPARATED-STRINGS->STRINGS" );
EXTERNTSCPP( scrt4_c_2ds2cuint_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ds2cuint_2dref_v );
EXTERNTSCPP( scrt2__3d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3d_2dtwo_v );
EXTERNTSCPP( sc_c_2dstring_2d_3estring, XAL1( TSCP ) );
EXTERNTSCP( sc_c_2dstring_2d_3estring_v );
EXTERNTSCPP( scrt1_reverse, XAL1( TSCP ) );
EXTERNTSCP( scrt1_reverse_v );

TSCP  dbindings__3estrings_3b44cc18( c12316 )
        TSCP  c12316;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t12899 );
        X1 = c12316;
        X2 = EMPTYLIST;
        X3 = _TSCP( 0 );
L12902:
        X4 = scrt4_c_2ds2cuint_2dref( X1, _TSCP( 0 ) );
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 0 ) ), 
                             _S2CINT( X4 ) ), 
                      3 ) )  goto L12905;
        if  ( EQ( _S2CUINT( _TSCP( 0 ) ), _S2CUINT( X4 ) ) )  goto L12909;
        goto L12910;
L12905:
        if  ( TRUE( scrt2__3d_2dtwo( _TSCP( 0 ), X4 ) ) )  goto L12909;
L12910:
        X5 = C_FIXED( sizeof( void* ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X5 ) ), 
                      3 ) )  goto L12914;
        X4 = _TSCP( IPLUS( _S2CINT( X1 ), _S2CINT( X5 ) ) );
        goto L12915;
L12914:
        X4 = scrt2__2b_2dtwo( X1, X5 );
L12915:
        X7 = scrt4_c_2ds2cuint_2dref( X1, _TSCP( 0 ) );
        X6 = sc_c_2dstring_2d_3estring( X7 );
        X5 = sc_cons( X6, X2 );
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12916;
        X3 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L12917;
L12916:
        X3 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L12917:
        X2 = X5;
        X1 = X4;
        GOBACK( L12902 );
L12909:
        POPSTACKTRACE( scrt1_reverse( X2 ) );
}

DEFTSCP( dbindings_ec_2darray_a0416023_v );
DEFCSTRING( t12918, "WITH-VECTOR->C-ARRAY" );
EXTERNTSCPP( dbindings_th_2darray_e5b6f976, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_th_2darray_e5b6f976_v );
EXTERNTSCPP( dbindings_ec_2darray_b2adc0a3, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_ec_2darray_b2adc0a3_v );

TSCP  toollib_2dc_2dbindings_l12359( a12360, c12923 )
        TSCP  a12360, c12923;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12359 [inside WITH-VECTOR->\
C-ARRAY]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12923, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12923, 1 );
        X3 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c12923, 2 );
        X4 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12923, 3 );
        X7 = dbindings_ec_2darray_b2adc0a3( a12360, 
                                            DISPLAY( 3 ), 
                                            DISPLAY( 1 ), 
                                            DISPLAY( 2 ) );
        X6 = DISPLAY( 0 );
        X6 = UNKNOWNCALL( X6, 1 );
        X5 = VIA( PROCEDURE_CODE( X6 ) )( X7, 
                                          PROCEDURE_CLOSURE( X6 ) );
        DISPLAY( 2 ) = X1;
        DISPLAY( 1 ) = X2;
        DISPLAY( 3 ) = X3;
        DISPLAY( 0 ) = X4;
        POPSTACKTRACE( X5 );
}

TSCP  dbindings_ec_2darray_a0416023( f12349, 
                                     s12350, e12351, v12352 )
        TSCP  f12349, s12350, e12351, v12352;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SD3 = DISPLAY( 3 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12918 );
        DISPLAY( 0 ) = f12349;
        DISPLAY( 1 ) = s12350;
        DISPLAY( 2 ) = e12351;
        DISPLAY( 3 ) = v12352;
        X2 = DISPLAY( 3 );
        if  ( AND( EQ( TSCPTAG( X2 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X2 ), VECTORTAG ) ) )  goto L12921;
        scdebug_error( c12357, 
                       c12358, CONS( X2, EMPTYLIST ) );
L12921:
        X1 = C_FIXED( VECTOR_LENGTH( X2 ) );
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12359, 
                            MAKECLOSURE( EMPTYLIST, 
                                         4, 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 0 ) ) );
        SDVAL = dbindings_th_2darray_e5b6f976( X1, 
                                               DISPLAY( 2 ), X2 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings_ct_2darray_e7fd79af_v );
DEFCSTRING( t12925, "WITH-VECTOR->C-EXACT-ARRAY" );
EXTERNTSCPP( dbindings_ct_2darray_88cb3000, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_ct_2darray_88cb3000_v );

TSCP  toollib_2dc_2dbindings_l12370( a12371, c12930 )
        TSCP  a12371, c12930;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12370 [inside WITH-VECTOR->\
C-EXACT-ARRAY]" );
        X1 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c12930, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12930, 1 );
        X3 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12930, 2 );
        X4 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12930, 3 );
        X7 = dbindings_ct_2darray_88cb3000( a12371, 
                                            DISPLAY( 2 ), 
                                            DISPLAY( 1 ), 
                                            DISPLAY( 3 ) );
        X6 = DISPLAY( 0 );
        X6 = UNKNOWNCALL( X6, 1 );
        X5 = VIA( PROCEDURE_CODE( X6 ) )( X7, 
                                          PROCEDURE_CLOSURE( X6 ) );
        DISPLAY( 3 ) = X1;
        DISPLAY( 1 ) = X2;
        DISPLAY( 2 ) = X3;
        DISPLAY( 0 ) = X4;
        POPSTACKTRACE( X5 );
}

TSCP  dbindings_ct_2darray_e7fd79af( f12362, 
                                     e12363, v12364, s12365 )
        TSCP  f12362, e12363, v12364, s12365;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SD3 = DISPLAY( 3 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12925 );
        DISPLAY( 0 ) = f12362;
        DISPLAY( 1 ) = e12363;
        DISPLAY( 2 ) = v12364;
        DISPLAY( 3 ) = s12365;
        X2 = DISPLAY( 2 );
        if  ( AND( EQ( TSCPTAG( X2 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X2 ), VECTORTAG ) ) )  goto L12928;
        scdebug_error( c12357, 
                       c12358, CONS( X2, EMPTYLIST ) );
L12928:
        X1 = C_FIXED( VECTOR_LENGTH( X2 ) );
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12370, 
                            MAKECLOSURE( EMPTYLIST, 
                                         4, 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 0 ) ) );
        SDVAL = dbindings_th_2darray_e5b6f976( X1, 
                                               DISPLAY( 1 ), X2 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings_2dpointers_a3114ab5_v );
DEFCSTRING( t12932, "WITH-C-POINTERS" );
EXTERNTSCPP( scrt4_c_2ds2cuint_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ds2cuint_2dset_21_v );
EXTERNTSCP( scrt4_c_2dsizeof_2ds2cuint_v );

TSCP  dbindings_2dpointers_a3114ab5( f12373, v12374 )
        TSCP  f12373, v12374;
{
        PUSHSTACKTRACE( t12932 );
        POPSTACKTRACE( dbindings_ec_2darray_a0416023( f12373, 
                                                      scrt4_c_2ds2cuint_2dset_21_v, 
                                                      scrt4_c_2dsizeof_2ds2cuint_v, 
                                                      v12374 ) );
}

DEFTSCP( dbindings_ec_2darray_eed5ca2b_v );
DEFCSTRING( t12934, "LIST->C-ARRAY" );
EXTERNTSCPP( scrt2__2a_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2a_2dtwo_v );

TSCP  toollib_2dc_2dbindings_l12380( x12381, i12382, c12936 )
        TSCP  x12381, i12382, c12936;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12380 [inside LIST->C-ARRAY\
]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12936, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12936, 1 );
        X3 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12936, 2 );
        X7 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( i12382 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L12939;
        X6 = _TSCP( ITIMES( FIXED_C( i12382 ), 
                            _S2CINT( X7 ) ) );
        goto L12940;
L12939:
        X6 = scrt2__2a_2dtwo( i12382, X7 );
L12940:
        X5 = DISPLAY( 1 );
        X5 = UNKNOWNCALL( X5, 3 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( DISPLAY( 0 ), 
                                          X6, 
                                          x12381, 
                                          PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 2 ) = X1;
        DISPLAY( 0 ) = X2;
        DISPLAY( 1 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  dbindings_ec_2darray_eed5ca2b( a12376, 
                                     l12377, s12378, e12379 )
        TSCP  a12376, l12377, s12378, e12379;
{
        TSCP  X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12934 );
        DISPLAY( 0 ) = a12376;
        DISPLAY( 1 ) = s12378;
        DISPLAY( 2 ) = e12379;
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dc_2dbindings_l12380, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        obischeme__2dindexed_d1069d4( X1, l12377 );
        SDVAL = DISPLAY( 0 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings_ct_2darray_9826cb39_v );
DEFCSTRING( t12941, "LIST->C-INEXACT-ARRAY" );
EXTERNTSCPP( dbindings_r_2dset_21_74788212, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_r_2dset_21_74788212_v );

TSCP  dbindings_ct_2darray_9826cb39( a12390, 
                                     l12391, e12392, s12393 )
        TSCP  a12390, l12391, e12392, s12393;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12941 );
        X1 = dbindings_r_2dset_21_74788212( e12392, s12393 );
        POPSTACKTRACE( dbindings_ec_2darray_eed5ca2b( a12390, 
                                                      l12391, 
                                                      X1, e12392 ) );
}

DEFTSCP( dbindings_ct_2darray_b6f75c47_v );
DEFCSTRING( t12943, "LIST->C-EXACT-ARRAY" );
EXTERNTSCPP( dbindings_r_2dset_21_89994f12, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_r_2dset_21_89994f12_v );

TSCP  dbindings_ct_2darray_b6f75c47( a12395, 
                                     l12396, e12397, s12398 )
        TSCP  a12395, l12396, e12397, s12398;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12943 );
        X1 = dbindings_r_2dset_21_89994f12( e12397, s12398 );
        POPSTACKTRACE( dbindings_ec_2darray_eed5ca2b( a12395, 
                                                      l12396, 
                                                      X1, e12397 ) );
}

DEFTSCP( dbindings_ec_2darray_b2adc0a3_v );
DEFCSTRING( t12945, "VECTOR->C-ARRAY" );

TSCP  toollib_2dc_2dbindings_l12404( x12405, i12406, c12947 )
        TSCP  x12405, i12406, c12947;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12404 [inside VECTOR->C-ARR\
AY]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12947, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12947, 1 );
        X3 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12947, 2 );
        X7 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( i12406 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L12950;
        X6 = _TSCP( ITIMES( FIXED_C( i12406 ), 
                            _S2CINT( X7 ) ) );
        goto L12951;
L12950:
        X6 = scrt2__2a_2dtwo( i12406, X7 );
L12951:
        X5 = DISPLAY( 1 );
        X5 = UNKNOWNCALL( X5, 3 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( DISPLAY( 0 ), 
                                          X6, 
                                          x12405, 
                                          PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 2 ) = X1;
        DISPLAY( 0 ) = X2;
        DISPLAY( 1 ) = X3;
        POPSTACKTRACE( X4 );
}

EXTERNTSCPP( qobischeme_enumerate_2dvector, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_enumerate_2dvector_v );

TSCP  dbindings_ec_2darray_b2adc0a3( a12400, 
                                     v12401, s12402, e12403 )
        TSCP  a12400, v12401, s12402, e12403;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12945 );
        DISPLAY( 0 ) = a12400;
        DISPLAY( 1 ) = s12402;
        DISPLAY( 2 ) = e12403;
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dc_2dbindings_l12404, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        if  ( AND( EQ( TSCPTAG( v12401 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( v12401 ), VECTORTAG ) )
            )  goto L12953;
        scdebug_error( c12357, 
                       c12358, CONS( v12401, EMPTYLIST ) );
L12953:
        X2 = C_FIXED( VECTOR_LENGTH( v12401 ) );
        obischeme_h_2dvector_fe309b1e( X1, 
                                       v12401, 
                                       CONS( qobischeme_enumerate_2dvector( X2 ), 
                                             EMPTYLIST ) );
        SDVAL = DISPLAY( 0 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings_ct_2darray_631a01b4_v );
DEFCSTRING( t12955, "VECTOR->C-INEXACT-ARRAY" );

TSCP  dbindings_ct_2darray_631a01b4( a12418, 
                                     v12419, e12420, s12421 )
        TSCP  a12418, v12419, e12420, s12421;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12955 );
        X1 = dbindings_r_2dset_21_74788212( e12420, s12421 );
        POPSTACKTRACE( dbindings_ec_2darray_b2adc0a3( a12418, 
                                                      v12419, 
                                                      X1, e12420 ) );
}

DEFTSCP( dbindings_ct_2darray_88cb3000_v );
DEFCSTRING( t12957, "VECTOR->C-EXACT-ARRAY" );

TSCP  dbindings_ct_2darray_88cb3000( a12423, 
                                     v12424, e12425, s12426 )
        TSCP  a12423, v12424, e12425, s12426;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12957 );
        X1 = dbindings_r_2dset_21_89994f12( e12425, s12426 );
        POPSTACKTRACE( dbindings_ec_2darray_b2adc0a3( a12423, 
                                                      v12424, 
                                                      X1, e12425 ) );
}

DEFTSCP( dbindings_th_2darray_e5b6f976_v );
DEFCSTRING( t12959, "WITH-ARRAY" );

TSCP  dbindings_th_2darray_e5b6f976( e12428, e12429, f12430 )
        TSCP  e12428, e12429, f12430;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12959 );
        if  ( BITAND( BITOR( _S2CINT( e12428 ), 
                             _S2CINT( e12429 ) ), 
                      3 ) )  goto L12961;
        X1 = _TSCP( ITIMES( FIXED_C( e12428 ), 
                            _S2CINT( e12429 ) ) );
        goto L12962;
L12961:
        X1 = scrt2__2a_2dtwo( e12428, e12429 );
L12962:
        POPSTACKTRACE( dbindings_th_2dalloc_20298354( X1, f12430 ) );
}

DEFTSCP( dbindings__2d_3elist_3ba1dc54_v );
DEFCSTRING( t12963, "C-ARRAY->LIST" );
EXTERNTSCPP( scrt4_vector_2d_3elist, XAL1( TSCP ) );
EXTERNTSCP( scrt4_vector_2d_3elist_v );
EXTERNTSCPP( dbindings_d_3evector_3a78c115, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_d_3evector_3a78c115_v );

TSCP  dbindings__2d_3elist_3ba1dc54( a12438, 
                                     g12439, e12440, n12441 )
        TSCP  a12438, g12439, e12440, n12441;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12963 );
        X1 = dbindings_d_3evector_3a78c115( a12438, 
                                            g12439, e12440, n12441 );
        POPSTACKTRACE( scrt4_vector_2d_3elist( X1 ) );
}

DEFTSCP( dbindings_d_3evector_3a78c115_v );
DEFCSTRING( t12965, "C-ARRAY->VECTOR" );
EXTERNTSCPP( qobischeme_map_2dn_2dvector, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dn_2dvector_v );

TSCP  toollib_2dc_2dbindings_l12447( x12448, c12967 )
        TSCP  x12448, c12967;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12447 [inside C-ARRAY->VECT\
OR]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12967, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12967, 1 );
        X3 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12967, 2 );
        X7 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( x12448 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L12970;
        X6 = _TSCP( ITIMES( FIXED_C( x12448 ), 
                            _S2CINT( X7 ) ) );
        goto L12971;
L12970:
        X6 = scrt2__2a_2dtwo( x12448, X7 );
L12971:
        X5 = DISPLAY( 1 );
        X5 = UNKNOWNCALL( X5, 2 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( DISPLAY( 0 ), 
                                          X6, 
                                          PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 2 ) = X1;
        DISPLAY( 0 ) = X2;
        DISPLAY( 1 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  dbindings_d_3evector_3a78c115( a12443, 
                                     g12444, e12445, n12446 )
        TSCP  a12443, g12444, e12445, n12446;
{
        TSCP  X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12965 );
        DISPLAY( 0 ) = a12443;
        DISPLAY( 1 ) = g12444;
        DISPLAY( 2 ) = e12445;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12447, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        SDVAL = qobischeme_map_2dn_2dvector( X1, n12446 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings__2d_3elist_28c4290c_v );
DEFCSTRING( t12972, "C-EXACT-ARRAY->LIST" );
EXTERNTSCPP( dbindings_d_3evector_85cd03bf, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_d_3evector_85cd03bf_v );

TSCP  dbindings__2d_3elist_28c4290c( a12456, 
                                     e12457, n12458, s12459 )
        TSCP  a12456, e12457, n12458, s12459;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12972 );
        X1 = dbindings_d_3evector_85cd03bf( a12456, 
                                            e12457, n12458, s12459 );
        POPSTACKTRACE( scrt4_vector_2d_3elist( X1 ) );
}

DEFTSCP( dbindings_d_3evector_85cd03bf_v );
DEFCSTRING( t12974, "C-EXACT-ARRAY->VECTOR" );
EXTERNTSCPP( dbindings_dptr_2dref_aed54e95, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_dptr_2dref_aed54e95_v );

TSCP  dbindings_d_3evector_85cd03bf( a12461, 
                                     e12462, n12463, s12464 )
        TSCP  a12461, e12462, n12463, s12464;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12974 );
        X1 = dbindings_dptr_2dref_aed54e95( e12462, s12464 );
        POPSTACKTRACE( dbindings_d_3evector_3a78c115( a12461, 
                                                      X1, 
                                                      e12462, n12463 ) );
}

DEFTSCP( dbindings__2d_3elist_7b0c30a4_v );
DEFCSTRING( t12976, "C-INEXACT-ARRAY->LIST" );
EXTERNTSCPP( dbindings_d_3evector_8778ce56, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_d_3evector_8778ce56_v );

TSCP  dbindings__2d_3elist_7b0c30a4( a12466, 
                                     e12467, n12468, s12469 )
        TSCP  a12466, e12467, n12468, s12469;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12976 );
        X1 = dbindings_d_3evector_8778ce56( a12466, 
                                            e12467, n12468, s12469 );
        POPSTACKTRACE( scrt4_vector_2d_3elist( X1 ) );
}

DEFTSCP( dbindings_d_3evector_8778ce56_v );
DEFCSTRING( t12978, "C-INEXACT-ARRAY->VECTOR" );
EXTERNTSCPP( dbindings_dptr_2dref_e9255e9b, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_dptr_2dref_e9255e9b_v );

TSCP  dbindings_d_3evector_8778ce56( a12471, 
                                     e12472, n12473, s12474 )
        TSCP  a12471, e12472, n12473, s12474;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12978 );
        X1 = dbindings_dptr_2dref_e9255e9b( e12472, s12474 );
        POPSTACKTRACE( dbindings_d_3evector_3a78c115( a12471, 
                                                      X1, 
                                                      e12472, n12473 ) );
}

DEFTSCP( dbindings_e_2doffset_548e9bfc_v );
DEFCSTRING( t12980, "C-PTR-BYTE-OFFSET" );

TSCP  dbindings_e_2doffset_548e9bfc( p12476, o12477 )
        TSCP  p12476, o12477;
{
        PUSHSTACKTRACE( t12980 );
        POPSTACKTRACE( POINTER_TSCP( PLUS( (char*)( TSCP_POINTER( p12476 ) ), 
                                           TSCP_S2CINT( o12477 ) ) ) );
}

DEFTSCP( dbindings_dptr_2dref_aed54e95_v );
DEFCSTRING( t12982, "C-SIZED-INT-PTR-REF" );
EXTERNTSCPP( scrt4_c_2dbyte_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dbyte_2dref_v );
EXTERNTSCP( scrt4_c_2dsizeof_2dshort_v );
EXTERNTSCPP( scrt4_c_2dshortunsigned_2dref, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dshortunsigned_2dref_v );
EXTERNTSCPP( scrt4_c_2dshortint_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dshortint_2dref_v );
EXTERNTSCP( scrt4_c_2dsizeof_2dint_v );
EXTERNTSCP( scrt4_c_2dsizeof_2dlong_v );
EXTERNTSCPP( scrt4_c_2dlongunsigned_2dref, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dlongunsigned_2dref_v );
EXTERNTSCPP( scrt4_c_2dlongint_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dlongint_2dref_v );
EXTERNTSCPP( qobischeme_fuck_2dup, XAL0(  ) );
EXTERNTSCP( qobischeme_fuck_2dup_v );
EXTERNTSCPP( scrt4_c_2dunsigned_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dunsigned_2dref_v );
EXTERNTSCPP( scrt4_c_2dint_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dint_2dref_v );

TSCP  dbindings_dptr_2dref_aed54e95( s12479, s12480 )
        TSCP  s12479, s12480;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12982 );
        if  ( BITAND( BITOR( _S2CINT( s12479 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12985;
        if  ( NEQ( _S2CUINT( s12479 ), 
                   _S2CUINT( _TSCP( 4 ) ) ) )  goto L12989;
        POPSTACKTRACE( scrt4_c_2dbyte_2dref_v );
L12985:
        if  ( FALSE( scrt2__3d_2dtwo( s12479, _TSCP( 4 ) ) ) )  goto L12989;
        POPSTACKTRACE( scrt4_c_2dbyte_2dref_v );
L12989:
        X1 = scrt4_c_2dsizeof_2dshort_v;
        if  ( BITAND( BITOR( _S2CINT( s12479 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L12994;
        if  ( EQ( _S2CUINT( s12479 ), _S2CUINT( X1 ) ) )  goto L12998;
        goto L12999;
L12994:
        if  ( FALSE( scrt2__3d_2dtwo( s12479, X1 ) ) )  goto L12999;
L12998:
        if  ( TRUE( s12480 ) )  goto L13002;
        POPSTACKTRACE( scrt4_c_2dshortunsigned_2dref_v );
L13002:
        POPSTACKTRACE( scrt4_c_2dshortint_2dref_v );
L12999:
        X1 = scrt4_c_2dsizeof_2dint_v;
        if  ( BITAND( BITOR( _S2CINT( s12479 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13006;
        if  ( EQ( _S2CUINT( s12479 ), _S2CUINT( X1 ) ) )  goto L13010;
        goto L13011;
L13006:
        if  ( TRUE( scrt2__3d_2dtwo( s12479, X1 ) ) )  goto L13010;
L13011:
        X1 = scrt4_c_2dsizeof_2dlong_v;
        if  ( BITAND( BITOR( _S2CINT( s12479 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13016;
        if  ( EQ( _S2CUINT( s12479 ), _S2CUINT( X1 ) ) )  goto L13020;
        goto L13021;
L13016:
        if  ( FALSE( scrt2__3d_2dtwo( s12479, X1 ) ) )  goto L13021;
L13020:
        if  ( TRUE( s12480 ) )  goto L13024;
        POPSTACKTRACE( scrt4_c_2dlongunsigned_2dref_v );
L13024:
        POPSTACKTRACE( scrt4_c_2dlongint_2dref_v );
L13021:
        POPSTACKTRACE( qobischeme_fuck_2dup(  ) );
L13010:
        if  ( TRUE( s12480 ) )  goto L13026;
        POPSTACKTRACE( scrt4_c_2dunsigned_2dref_v );
L13026:
        POPSTACKTRACE( scrt4_c_2dint_2dref_v );
}

DEFTSCP( dbindings_r_2dset_21_89994f12_v );
DEFCSTRING( t13028, "C-SIZED-INT-PTR-SET!" );
EXTERNTSCPP( scrt4_d_2dset_21_828269c5, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_d_2dset_21_828269c5_v );
EXTERNTSCPP( scrt4_c_2dshortint_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dshortint_2dset_21_v );
EXTERNTSCPP( scrt4_d_2dset_21_2e97375c, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_d_2dset_21_2e97375c_v );
EXTERNTSCPP( scrt4_c_2dlongint_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dlongint_2dset_21_v );
EXTERNTSCPP( scrt4_c_2dunsigned_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dunsigned_2dset_21_v );
EXTERNTSCPP( scrt4_c_2dint_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dint_2dset_21_v );

TSCP  dbindings_r_2dset_21_89994f12( s12518, s12519 )
        TSCP  s12518, s12519;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13028 );
        if  ( BITAND( BITOR( _S2CINT( s12518 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13031;
        if  ( NEQ( _S2CUINT( s12518 ), 
                   _S2CUINT( _TSCP( 4 ) ) ) )  goto L13035;
        POPSTACKTRACE( scrt4_c_2dbyte_2dset_21_v );
L13031:
        if  ( FALSE( scrt2__3d_2dtwo( s12518, _TSCP( 4 ) ) ) )  goto L13035;
        POPSTACKTRACE( scrt4_c_2dbyte_2dset_21_v );
L13035:
        X1 = scrt4_c_2dsizeof_2dshort_v;
        if  ( BITAND( BITOR( _S2CINT( s12518 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13040;
        if  ( EQ( _S2CUINT( s12518 ), _S2CUINT( X1 ) ) )  goto L13044;
        goto L13045;
L13040:
        if  ( FALSE( scrt2__3d_2dtwo( s12518, X1 ) ) )  goto L13045;
L13044:
        if  ( TRUE( s12519 ) )  goto L13048;
        POPSTACKTRACE( scrt4_d_2dset_21_828269c5_v );
L13048:
        POPSTACKTRACE( scrt4_c_2dshortint_2dset_21_v );
L13045:
        X1 = scrt4_c_2dsizeof_2dint_v;
        if  ( BITAND( BITOR( _S2CINT( s12518 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13052;
        if  ( EQ( _S2CUINT( s12518 ), _S2CUINT( X1 ) ) )  goto L13056;
        goto L13057;
L13052:
        if  ( TRUE( scrt2__3d_2dtwo( s12518, X1 ) ) )  goto L13056;
L13057:
        X1 = scrt4_c_2dsizeof_2dlong_v;
        if  ( BITAND( BITOR( _S2CINT( s12518 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13062;
        if  ( EQ( _S2CUINT( s12518 ), _S2CUINT( X1 ) ) )  goto L13066;
        goto L13067;
L13062:
        if  ( FALSE( scrt2__3d_2dtwo( s12518, X1 ) ) )  goto L13067;
L13066:
        if  ( TRUE( s12519 ) )  goto L13070;
        POPSTACKTRACE( scrt4_d_2dset_21_2e97375c_v );
L13070:
        POPSTACKTRACE( scrt4_c_2dlongint_2dset_21_v );
L13067:
        POPSTACKTRACE( qobischeme_fuck_2dup(  ) );
L13056:
        if  ( TRUE( s12519 ) )  goto L13072;
        POPSTACKTRACE( scrt4_c_2dunsigned_2dset_21_v );
L13072:
        POPSTACKTRACE( scrt4_c_2dint_2dset_21_v );
}

DEFTSCP( dbindings_dptr_2dref_e9255e9b_v );
DEFCSTRING( t13074, "C-SIZED-INEXACT-PTR-REF" );
EXTERNTSCP( scrt4_c_2dsizeof_2dfloat_v );
EXTERNTSCPP( scrt4_c_2dfloat_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dfloat_2dref_v );
EXTERNTSCP( scrt4_c_2dsizeof_2ddouble_v );
EXTERNTSCPP( scrt4_c_2ddouble_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ddouble_2dref_v );

TSCP  dbindings_dptr_2dref_e9255e9b( s12557, s12558 )
        TSCP  s12557, s12558;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13074 );
        X1 = scrt4_c_2dsizeof_2dfloat_v;
        if  ( BITAND( BITOR( _S2CINT( s12557 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13078;
        if  ( NEQ( _S2CUINT( s12557 ), _S2CUINT( X1 ) ) )  goto L13082;
        POPSTACKTRACE( scrt4_c_2dfloat_2dref_v );
L13078:
        if  ( FALSE( scrt2__3d_2dtwo( s12557, X1 ) ) )  goto L13082;
        POPSTACKTRACE( scrt4_c_2dfloat_2dref_v );
L13082:
        X1 = scrt4_c_2dsizeof_2ddouble_v;
        if  ( BITAND( BITOR( _S2CINT( s12557 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13087;
        if  ( NEQ( _S2CUINT( s12557 ), _S2CUINT( X1 ) ) )  goto L13091;
        POPSTACKTRACE( scrt4_c_2ddouble_2dref_v );
L13087:
        if  ( FALSE( scrt2__3d_2dtwo( s12557, X1 ) ) )  goto L13091;
        POPSTACKTRACE( scrt4_c_2ddouble_2dref_v );
L13091:
        POPSTACKTRACE( qobischeme_fuck_2dup(  ) );
}

DEFTSCP( dbindings_r_2dset_21_74788212_v );
DEFCSTRING( t13094, "C-SIZED-INEXACT-PTR-SET!" );
EXTERNTSCPP( scrt4_c_2dfloat_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dfloat_2dset_21_v );
EXTERNTSCPP( scrt4_c_2ddouble_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ddouble_2dset_21_v );

TSCP  dbindings_r_2dset_21_74788212( s12578, s12579 )
        TSCP  s12578, s12579;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13094 );
        X1 = scrt4_c_2dsizeof_2dfloat_v;
        if  ( BITAND( BITOR( _S2CINT( s12578 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13098;
        if  ( NEQ( _S2CUINT( s12578 ), _S2CUINT( X1 ) ) )  goto L13102;
        POPSTACKTRACE( scrt4_c_2dfloat_2dset_21_v );
L13098:
        if  ( FALSE( scrt2__3d_2dtwo( s12578, X1 ) ) )  goto L13102;
        POPSTACKTRACE( scrt4_c_2dfloat_2dset_21_v );
L13102:
        X1 = scrt4_c_2dsizeof_2ddouble_v;
        if  ( BITAND( BITOR( _S2CINT( s12578 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13107;
        if  ( NEQ( _S2CUINT( s12578 ), _S2CUINT( X1 ) ) )  goto L13111;
        POPSTACKTRACE( scrt4_c_2ddouble_2dset_21_v );
L13107:
        if  ( FALSE( scrt2__3d_2dtwo( s12578, X1 ) ) )  goto L13111;
        POPSTACKTRACE( scrt4_c_2ddouble_2dset_21_v );
L13111:
        POPSTACKTRACE( qobischeme_fuck_2dup(  ) );
}

DEFTSCP( dbindings_ec_2darray_edcfb363_v );
DEFCSTRING( t13114, "MATRIX->C-ARRAY" );
EXTERNTSCPP( qobischeme_for_2deach_2dn, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_for_2deach_2dn_v );
EXTERNTSCPP( qobischeme_matrix_2dcolumns, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_matrix_2dcolumns_v );
EXTERNTSCPP( qobischeme_matrix_2dref, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_matrix_2dref_v );

TSCP  toollib_2dc_2dbindings_l12605( j12606, c13118 )
        TSCP  j12606, c13118;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12605 [inside MATRIX->C-ARR\
AY]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13118, 0 );
        X2 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c13118, 1 );
        X3 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13118, 2 );
        X8 = DISPLAY( 2 );
        X9 = qobischeme_matrix_2dcolumns( DISPLAY( 1 ) );
        if  ( BITAND( BITOR( _S2CINT( X8 ), _S2CINT( X9 ) ), 
                      3 ) )  goto L13121;
        X7 = _TSCP( ITIMES( FIXED_C( X8 ), _S2CINT( X9 ) ) );
        goto L13122;
L13121:
        X7 = scrt2__2a_2dtwo( X8, X9 );
L13122:
        if  ( BITAND( BITOR( _S2CINT( j12606 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L13124;
        X6 = _TSCP( IPLUS( _S2CINT( j12606 ), 
                           _S2CINT( X7 ) ) );
        goto L13125;
L13124:
        X6 = scrt2__2b_2dtwo( j12606, X7 );
L13125:
        X7 = scrt4_c_2dsizeof_2dfloat_v;
        if  ( BITAND( BITOR( _S2CINT( X7 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L13127;
        X5 = _TSCP( ITIMES( FIXED_C( X7 ), _S2CINT( X6 ) ) );
        goto L13128;
L13127:
        X5 = scrt2__2a_2dtwo( X7, X6 );
L13128:
        X6 = qobischeme_matrix_2dref( DISPLAY( 1 ), 
                                      DISPLAY( 2 ), j12606 );
        X4 = scrt4_c_2dfloat_2dset_21( DISPLAY( 0 ), X5, X6 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 2 ) = X2;
        DISPLAY( 0 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  toollib_2dc_2dbindings_l12603( i12604, c13116 )
        TSCP  i12604, c13116;
{
        TSCP  X5, X4, X3, X2, X1;
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12603 [inside MATRIX->C-ARR\
AY]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13116, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13116, 1 );
        DISPLAY( 2 ) = i12604;
        X4 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12605, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 0 ) ) );
        X5 = qobischeme_matrix_2dcolumns( DISPLAY( 1 ) );
        X3 = qobischeme_for_2deach_2dn( X4, X5 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        SDVAL = X3;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

EXTERNTSCPP( qobischeme_matrix_2drows, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_matrix_2drows_v );

TSCP  dbindings_ec_2darray_edcfb363( a12599, 
                                     m12600, s12601, e12602 )
        TSCP  a12599, m12600, s12601, e12602;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13114 );
        DISPLAY( 0 ) = a12599;
        DISPLAY( 1 ) = m12600;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12603, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ) ) );
        X2 = qobischeme_matrix_2drows( DISPLAY( 1 ) );
        SDVAL = qobischeme_for_2deach_2dn( X1, X2 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings_dbuffer_21_3dc46775_v );
DEFCSTRING( t13129, "PGM->FLOAT-BUFFER!" );
EXTERNTSCPP( qobischeme_pnm_2dheight, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_pnm_2dheight_v );
EXTERNTSCPP( qobischeme_pnm_2dwidth, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_pnm_2dwidth_v );
EXTERNTSCPP( qobischeme_pgm_2dmaxval, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_pgm_2dmaxval_v );
EXTERNTSCPP( scrt2__2f_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2f_2dtwo_v );

TSCP  toollib_2dc_2dbindings_l12631( e12632, c13140 )
        TSCP  e12632, c13140;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12631 [inside PGM->FLOAT-BU\
FFER!]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13140, 0 );
        X4 = qobischeme_pgm_2dmaxval( DISPLAY( 0 ) );
        X5 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( e12632 ), 
                                          _S2CINT( X4 ) ), 
                                   3 ) ) );
        if  ( FALSE( X5 ) )  goto L13153;
        if  ( EQ( _S2CUINT( X4 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13153;
        X6 = _TSCP( REMAINDER( _S2CINT( e12632 ), 
                               _S2CINT( X4 ) ) );
        if  ( NEQ( _S2CUINT( X6 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13153;
        X3 = C_FIXED( QUOTIENT( _S2CINT( e12632 ), 
                                _S2CINT( X4 ) ) );
        goto L13154;
L13153:
        X3 = scrt2__2f_2dtwo( e12632, X4 );
L13154:
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 1020 ) ) ), 
                      3 ) )  goto L13156;
        X2 = _TSCP( ITIMES( FIXED_C( X3 ), 
                            _S2CINT( _TSCP( 1020 ) ) ) );
        goto L13157;
L13156:
        X2 = scrt2__2a_2dtwo( X3, _TSCP( 1020 ) );
L13157:
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  toollib_2dc_2dbindings_l12629( e12630, c13138 )
        TSCP  e12630, c13138;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12629 [inside PGM->FLOAT-BU\
FFER!]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13138, 0 );
        X3 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12631, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X2 = qobischeme_map_2dvector( X3, e12630, EMPTYLIST );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

EXTERNTSCPP( qobischeme_pgm_2dgrey, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_pgm_2dgrey_v );

TSCP  dbindings_dbuffer_21_3dc46775( p12626 )
        TSCP  p12626;
{
        TSCP  X5, X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13129 );
        DISPLAY( 0 ) = p12626;
        X4 = qobischeme_pnm_2dheight( DISPLAY( 0 ) );
        X5 = qobischeme_pnm_2dwidth( DISPLAY( 0 ) );
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X4 ) ), 
                      3 ) )  goto L13132;
        X3 = _TSCP( ITIMES( FIXED_C( X5 ), _S2CINT( X4 ) ) );
        goto L13133;
L13132:
        X3 = scrt2__2a_2dtwo( X5, X4 );
L13133:
        X4 = scrt4_c_2dsizeof_2dfloat_v;
        if  ( BITAND( BITOR( _S2CINT( X4 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L13135;
        X2 = _TSCP( ITIMES( FIXED_C( X4 ), _S2CINT( X3 ) ) );
        goto L13136;
L13135:
        X2 = scrt2__2a_2dtwo( X4, X3 );
L13136:
        X1 = toollib_2dc_2dbindings_malloc( X2 );
        X3 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12629, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X4 = qobischeme_pgm_2dgrey( DISPLAY( 0 ) );
        X2 = qobischeme_map_2dvector( X3, X4, EMPTYLIST );
        dbindings_ec_2darray_edcfb363( X1, 
                                       X2, 
                                       scrt4_c_2dfloat_2dset_21_v, 
                                       scrt4_c_2dsizeof_2dfloat_v );
        SDVAL = X1;
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( toollib_2dc_2dbindings_popen_v );
DEFCSTRING( t13158, "POPEN" );

TSCP  toollib_2dc_2dbindings_popen( g12673, g12674 )
        TSCP  g12673, g12674;
{
        PUSHSTACKTRACE( t13158 );
        POPSTACKTRACE( POINTER_TSCP( popen( TSCP_POINTER( g12673 ), 
                                            TSCP_POINTER( g12674 ) ) ) );
}

DEFTSCP( toollib_2dc_2dbindings_pclose_v );
DEFCSTRING( t13160, "PCLOSE" );

TSCP  toollib_2dc_2dbindings_pclose( g12679 )
        TSCP  g12679;
{
        PUSHSTACKTRACE( t13160 );
        POPSTACKTRACE( sc_int_tscp( pclose( TSCP_POINTER( g12679 ) ) ) );
}

DEFTSCP( toollib_2dc_2dbindings_srand_v );
DEFCSTRING( t13162, "SRAND" );

TSCP  toollib_2dc_2dbindings_srand( g12683 )
        TSCP  g12683;
{
        PUSHSTACKTRACE( t13162 );
        srand( TSCP_S2CUINT( g12683 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( toollib_2dc_2dbindings_setenv_v );
DEFCSTRING( t13165, "SETENV" );

TSCP  toollib_2dc_2dbindings_setenv( g12688, g12689, g12690 )
        TSCP  g12688, g12689, g12690;
{
        PUSHSTACKTRACE( t13165 );
        POPSTACKTRACE( sc_int_tscp( setenv( TSCP_POINTER( g12688 ), 
                                            TSCP_POINTER( g12689 ), 
                                            tscp_bool( g12690 ) ) ) );
}

void scrt4__init();
void scrt2__init();
void scrt1__init();
void scrt3__init();
void scdebug__init();
void qobischeme__init();
void pregexp__init();

static void  init_modules( compiler_version )
        char *compiler_version;
{
        scrt4__init();
        scrt2__init();
        scrt1__init();
        scrt3__init();
        scdebug__init();
        qobischeme__init();
        pregexp__init();
        MAXDISPLAY( 4 );
}

void  toollib_2dc_2dbindings__init()
{
        static int  init = 0;
        if  (init)  return;
        init = 1;
        INITHEAP( 0, 0, 0, 0 );
        init_constants();
        init_modules( "(toollib_2dc_2dbindings SCHEME->C COMPILER 15mar93jfb\
)" );
        sc_segv__handlers();
        INITIALIZEVAR( t12777, 
                       ADR( dbindings_gs_2d1_2d0_67ee31d0_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_gs_2d1_2d0_67ee31d0, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12779, 
                       ADR( dbindings_gs_2d3_2d0_1d2e62b0_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_gs_2d3_2d0_1d2e62b0, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12781, 
                       ADR( dbindings_gs_2d5_2d0_926e9710_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_gs_2d5_2d0_926e9710, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12783, 
                       ADR( dbindings_gs_2d7_2d0_e8aec470_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_gs_2d7_2d0_e8aec470, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12785, 
                       ADR( dbindings_gs_2d9_2d0_579e7a11_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_gs_2d9_2d0_579e7a11, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12787, 
                       ADR( dbindings_s_2d11_2d0_f9c520e9_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_s_2d11_2d0_f9c520e9, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12789, 
                       ADR( dbindings_s_2d13_2d0_83057389_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_s_2d13_2d0_83057389, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12791, 
                       ADR( dbindings_s_2d15_2d0_c458629_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_s_2d15_2d0_c458629, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12793, 
                       ADR( toollib_2dc_2dbindings_curry2_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_curry2, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12799, 
                       ADR( toollib_2dc_2dbindings_malloc_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_malloc, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12801, 
                       ADR( toollib_2dc_2dbindings_memcpy_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      toollib_2dc_2dbindings_memcpy, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12803, 
                       ADR( toollib_2dc_2dbindings_bzero_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      toollib_2dc_2dbindings_bzero, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12806, 
                       ADR( toollib_2dc_2dbindings_free_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_free, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12809, 
                       ADR( dbindings_th_2dalloc_20298354_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_th_2dalloc_20298354, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12814, 
                       ADR( dbindings_c_2dstring_a000da03_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      dbindings_c_2dstring_a000da03, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12819, 
                       ADR( dbindings_d_3esymbol_d89bd1b0_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      dbindings_d_3esymbol_d89bd1b0, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12837, 
                       ADR( dbindings_e_2dstream_4a3d87a7_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      dbindings_e_2dstream_4a3d87a7, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12841, 
                       ADR( dbindings_r_2dstream_f6149db3_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_r_2dstream_f6149db3, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12845, 
                       ADR( toollib_2dc_2dbindings_fclose_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_fclose, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12848, 
                       ADR( toollib_2dc_2dbindings_fopen_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      toollib_2dc_2dbindings_fopen, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12850, 
                       ADR( dbindings_fmemopen_3521495d_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      dbindings_fmemopen_3521495d, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12852, 
                       ADR( dbindings_c_2dstring_6099dec9_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_c_2dstring_6099dec9, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12876, 
                       ADR( dbindings__2dstrings_2bd4c34c_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings__2dstrings_2bd4c34c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12884, 
                       ADR( dbindings_c_2dstring_64a7b683_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      dbindings_c_2dstring_64a7b683, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12899, 
                       ADR( dbindings__3estrings_3b44cc18_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      dbindings__3estrings_3b44cc18, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12918, 
                       ADR( dbindings_ec_2darray_a0416023_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ec_2darray_a0416023, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12925, 
                       ADR( dbindings_ct_2darray_e7fd79af_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ct_2darray_e7fd79af, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12932, 
                       ADR( dbindings_2dpointers_a3114ab5_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_2dpointers_a3114ab5, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12934, 
                       ADR( dbindings_ec_2darray_eed5ca2b_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ec_2darray_eed5ca2b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12941, 
                       ADR( dbindings_ct_2darray_9826cb39_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ct_2darray_9826cb39, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12943, 
                       ADR( dbindings_ct_2darray_b6f75c47_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ct_2darray_b6f75c47, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12945, 
                       ADR( dbindings_ec_2darray_b2adc0a3_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ec_2darray_b2adc0a3, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12955, 
                       ADR( dbindings_ct_2darray_631a01b4_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ct_2darray_631a01b4, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12957, 
                       ADR( dbindings_ct_2darray_88cb3000_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ct_2darray_88cb3000, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12959, 
                       ADR( dbindings_th_2darray_e5b6f976_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      dbindings_th_2darray_e5b6f976, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12963, 
                       ADR( dbindings__2d_3elist_3ba1dc54_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings__2d_3elist_3ba1dc54, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12965, 
                       ADR( dbindings_d_3evector_3a78c115_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_d_3evector_3a78c115, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12972, 
                       ADR( dbindings__2d_3elist_28c4290c_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings__2d_3elist_28c4290c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12974, 
                       ADR( dbindings_d_3evector_85cd03bf_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_d_3evector_85cd03bf, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12976, 
                       ADR( dbindings__2d_3elist_7b0c30a4_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings__2d_3elist_7b0c30a4, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12978, 
                       ADR( dbindings_d_3evector_8778ce56_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_d_3evector_8778ce56, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12980, 
                       ADR( dbindings_e_2doffset_548e9bfc_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_e_2doffset_548e9bfc, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12982, 
                       ADR( dbindings_dptr_2dref_aed54e95_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_dptr_2dref_aed54e95, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13028, 
                       ADR( dbindings_r_2dset_21_89994f12_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_r_2dset_21_89994f12, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13074, 
                       ADR( dbindings_dptr_2dref_e9255e9b_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_dptr_2dref_e9255e9b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13094, 
                       ADR( dbindings_r_2dset_21_74788212_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_r_2dset_21_74788212, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13114, 
                       ADR( dbindings_ec_2darray_edcfb363_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ec_2darray_edcfb363, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13129, 
                       ADR( dbindings_dbuffer_21_3dc46775_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      dbindings_dbuffer_21_3dc46775, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13158, 
                       ADR( toollib_2dc_2dbindings_popen_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      toollib_2dc_2dbindings_popen, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13160, 
                       ADR( toollib_2dc_2dbindings_pclose_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_pclose, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13162, 
                       ADR( toollib_2dc_2dbindings_srand_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_srand, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13165, 
                       ADR( toollib_2dc_2dbindings_setenv_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      toollib_2dc_2dbindings_setenv, 
                                      EMPTYLIST ) );
        return;
}
