
/* SCHEME->C */

#include <objects.h>

void toollib_2dc_2dbindings__init();
DEFCSTRING( t12789, "Argument is not a VECTOR: ~s" );
DEFSTATICTSCP( c12377 );
DEFSTATICTSCP( c12376 );
DEFCSTRING( t12790, "Argument not a CHAR: ~s" );
DEFSTATICTSCP( c12283 );
DEFSTATICTSCP( c12282 );
DEFCSTRING( t12791, "Argument is not a STRING: ~s" );
DEFSTATICTSCP( c12271 );
DEFSTATICTSCP( c12270 );
DEFCSTRING( t12792, "Argument not a PAIR: ~s" );
DEFSTATICTSCP( c12196 );
DEFSTATICTSCP( c12195 );
DEFCSTRING( t12793, "_" );
DEFSTATICTSCP( c12158 );
DEFCSTRING( t12794, "Argument is not a SYMBOL: ~s" );
DEFSTATICTSCP( c12157 );
DEFSTATICTSCP( c12156 );
DEFCSTRING( t12795, "-" );
DEFSTATICTSCP( c12151 );

static void  init_constants()
{
        c12377 = CSTRING_TSCP( t12789 );
        CONSTANTEXP( ADR( c12377 ) );
        c12376 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR-LENGTH" ) );
        CONSTANTEXP( ADR( c12376 ) );
        c12283 = CSTRING_TSCP( t12790 );
        CONSTANTEXP( ADR( c12283 ) );
        c12282 = STRINGTOSYMBOL( CSTRING_TSCP( "CHAR->INTEGER" ) );
        CONSTANTEXP( ADR( c12282 ) );
        c12271 = CSTRING_TSCP( t12791 );
        CONSTANTEXP( ADR( c12271 ) );
        c12270 = STRINGTOSYMBOL( CSTRING_TSCP( "STRING-LENGTH" ) );
        CONSTANTEXP( ADR( c12270 ) );
        c12196 = CSTRING_TSCP( t12792 );
        CONSTANTEXP( ADR( c12196 ) );
        c12195 = STRINGTOSYMBOL( CSTRING_TSCP( "SET-CDR!" ) );
        CONSTANTEXP( ADR( c12195 ) );
        c12158 = CSTRING_TSCP( t12793 );
        CONSTANTEXP( ADR( c12158 ) );
        c12157 = CSTRING_TSCP( t12794 );
        CONSTANTEXP( ADR( c12157 ) );
        c12156 = STRINGTOSYMBOL( CSTRING_TSCP( "SYMBOL->STRING" ) );
        CONSTANTEXP( ADR( c12156 ) );
        c12151 = CSTRING_TSCP( t12795 );
        CONSTANTEXP( ADR( c12151 ) );
}

DEFTSCP( dbindings_gs_2d1_2d0_67ee31d0_v );
DEFCSTRING( t12796, "gensym-toollib_2dc_2dbindings-1-0" );

TSCP  dbindings_gs_2d1_2d0_67ee31d0(  )
{
        PUSHSTACKTRACE( t12796 );
        POPSTACKTRACE( 0 );}
  #include<stddef.h>
int gensym_toollib_2dc_2dbindings_2_0(){ return 1;gensym_toollib_2dc_2dbindings_2_0( );
}

DEFTSCP( dbindings_gs_2d3_2d0_1d2e62b0_v );
DEFCSTRING( t12798, "gensym-toollib_2dc_2dbindings-3-0" );

TSCP  dbindings_gs_2d3_2d0_1d2e62b0(  )
{
        PUSHSTACKTRACE( t12798 );
        POPSTACKTRACE( 0 );}
  #include<stdlib.h>
int gensym_toollib_2dc_2dbindings_4_0(){ return 1;gensym_toollib_2dc_2dbindings_4_0( );
}

DEFTSCP( dbindings_gs_2d5_2d0_926e9710_v );
DEFCSTRING( t12800, "gensym-toollib_2dc_2dbindings-5-0" );

TSCP  dbindings_gs_2d5_2d0_926e9710(  )
{
        PUSHSTACKTRACE( t12800 );
        POPSTACKTRACE( 0 );}
  #include<string.h>
int gensym_toollib_2dc_2dbindings_6_0(){ return 1;gensym_toollib_2dc_2dbindings_6_0( );
}

DEFTSCP( dbindings_gs_2d7_2d0_e8aec470_v );
DEFCSTRING( t12802, "gensym-toollib_2dc_2dbindings-7-0" );

TSCP  dbindings_gs_2d7_2d0_e8aec470(  )
{
        PUSHSTACKTRACE( t12802 );
        POPSTACKTRACE( 0 );}
  #include<stdlib.h>
int gensym_toollib_2dc_2dbindings_8_0(){ return 1;gensym_toollib_2dc_2dbindings_8_0( );
}

DEFTSCP( dbindings_gs_2d9_2d0_579e7a11_v );
DEFCSTRING( t12804, "gensym-toollib_2dc_2dbindings-9-0" );

TSCP  dbindings_gs_2d9_2d0_579e7a11(  )
{
        PUSHSTACKTRACE( t12804 );
        POPSTACKTRACE( 0 );}
  #include<stdio.h>
int gensym_toollib_2dc_2dbindings_10_0(){ return 1;gensym_toollib_2dc_2dbindings_10_0( );
}

DEFTSCP( dbindings_s_2d11_2d0_f9c520e9_v );
DEFCSTRING( t12806, "gensym-toollib_2dc_2dbindings-11-0" );

TSCP  dbindings_s_2d11_2d0_f9c520e9(  )
{
        PUSHSTACKTRACE( t12806 );
        POPSTACKTRACE( 0 );}
  #include<sys/types.h>
int gensym_toollib_2dc_2dbindings_12_0(){ return 1;gensym_toollib_2dc_2dbindings_12_0( );
}

DEFTSCP( dbindings_s_2d13_2d0_83057389_v );
DEFCSTRING( t12808, "gensym-toollib_2dc_2dbindings-13-0" );

TSCP  dbindings_s_2d13_2d0_83057389(  )
{
        PUSHSTACKTRACE( t12808 );
        POPSTACKTRACE( 0 );}
  #include<unistd.h>
int gensym_toollib_2dc_2dbindings_14_0(){ return 1;gensym_toollib_2dc_2dbindings_14_0( );
}

DEFTSCP( dbindings_s_2d15_2d0_c458629_v );
DEFCSTRING( t12810, "gensym-toollib_2dc_2dbindings-15-0" );

TSCP  dbindings_s_2d15_2d0_c458629(  )
{
        PUSHSTACKTRACE( t12810 );
        POPSTACKTRACE( 0 );}
  #include<gmp.h>
int gensym_toollib_2dc_2dbindings_16_0(){ return 1;gensym_toollib_2dc_2dbindings_16_0( );
}

DEFTSCP( toollib_2dc_2dbindings_curry2_v );
DEFCSTRING( t12812, "CURRY2" );

TSCP  toollib_2dc_2dbindings_l12115( y12116, c12816 )
        TSCP  y12116, c12816;
{
        TSCP  X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12115 [inside CURRY2]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12816, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12816, 1 );
        X4 = DISPLAY( 0 );
        X4 = UNKNOWNCALL( X4, 2 );
        X3 = VIA( PROCEDURE_CODE( X4 ) )( DISPLAY( 1 ), 
                                          y12116, 
                                          PROCEDURE_CLOSURE( X4 ) );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        POPSTACKTRACE( X3 );
}

TSCP  toollib_2dc_2dbindings_l12113( x12114, c12814 )
        TSCP  x12114, c12814;
{
        TSCP  X2, X1;
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12113 [inside CURRY2]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12814, 0 );
        DISPLAY( 1 ) = x12114;
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12115, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ) ) );
        DISPLAY( 0 ) = X1;
        SDVAL = X2;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

TSCP  toollib_2dc_2dbindings_curry2( f12112 )
        TSCP  f12112;
{
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12812 );
        DISPLAY( 0 ) = f12112;
        SDVAL = MAKEPROCEDURE( 1, 
                               0, 
                               toollib_2dc_2dbindings_l12113, 
                               MAKECLOSURE( EMPTYLIST, 
                                            1, DISPLAY( 0 ) ) );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( toollib_2dc_2dbindings_malloc_v );
DEFCSTRING( t12818, "MALLOC" );

TSCP  toollib_2dc_2dbindings_malloc( g12118 )
        TSCP  g12118;
{
        PUSHSTACKTRACE( t12818 );
        POPSTACKTRACE( POINTER_TSCP( malloc( sc_tscp_int( g12118 ) ) ) );
}

DEFTSCP( toollib_2dc_2dbindings_memcpy_v );
DEFCSTRING( t12820, "MEMCPY" );

TSCP  toollib_2dc_2dbindings_memcpy( g12122, g12123, g12124 )
        TSCP  g12122, g12123, g12124;
{
        PUSHSTACKTRACE( t12820 );
        POPSTACKTRACE( POINTER_TSCP( memcpy( TSCP_POINTER( g12122 ), 
                                             TSCP_POINTER( g12123 ), 
                                             sc_tscp_int( g12124 ) ) ) );
}

DEFTSCP( toollib_2dc_2dbindings_bzero_v );
DEFCSTRING( t12822, "BZERO" );

TSCP  toollib_2dc_2dbindings_bzero( g12130, g12131 )
        TSCP  g12130, g12131;
{
        PUSHSTACKTRACE( t12822 );
        bzero( TSCP_POINTER( g12130 ), 
               sc_tscp_int( g12131 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( toollib_2dc_2dbindings_free_v );
DEFCSTRING( t12825, "FREE" );

TSCP  toollib_2dc_2dbindings_free( g12137 )
        TSCP  g12137;
{
        PUSHSTACKTRACE( t12825 );
        free( TSCP_POINTER( g12137 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( dbindings_th_2dalloc_20298354_v );
DEFCSTRING( t12828, "WITH-ALLOC" );

TSCP  dbindings_th_2dalloc_20298354( x12142, f12143 )
        TSCP  x12142, f12143;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t12828 );
        X1 = toollib_2dc_2dbindings_malloc( x12142 );
        toollib_2dc_2dbindings_bzero( X1, x12142 );
        X3 = f12143;
        X3 = UNKNOWNCALL( X3, 1 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( X1, 
                                          PROCEDURE_CLOSURE( X3 ) );
        toollib_2dc_2dbindings_free( X1 );
        POPSTACKTRACE( X2 );
}

DEFTSCP( dbindings_c_2dstring_a000da03_v );
DEFCSTRING( t12833, "SYMBOL->C-STRING" );
EXTERNTSCPP( pregexp_pregexp_2dreplace_2a, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( pregexp_pregexp_2dreplace_2a_v );
EXTERNTSCPP( qobischeme_string_2ddowncase, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_string_2ddowncase_v );
EXTERNTSCPP( scdebug_error, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scdebug_error_v );

TSCP  dbindings_c_2dstring_a000da03( s12150 )
        TSCP  s12150;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t12833 );
        if  ( AND( EQ( TSCPTAG( s12150 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12150 ), SYMBOLTAG ) )
            )  goto L12836;
        scdebug_error( c12156, 
                       c12157, CONS( s12150, EMPTYLIST ) );
L12836:
        X2 = SYMBOL_NAME( s12150 );
        X1 = qobischeme_string_2ddowncase( X2 );
        POPSTACKTRACE( pregexp_pregexp_2dreplace_2a( c12151, 
                                                     X1, c12158 ) );
}

DEFTSCP( dbindings_d_3esymbol_d89bd1b0_v );
DEFCSTRING( t12838, "C-STRING->SYMBOL" );
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

TSCP  dbindings_d_3esymbol_d89bd1b0( s12160 )
        TSCP  s12160;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t12838 );
        X4 = pregexp_pregexp_2dreplace_2a( c12158, s12160, c12151 );
        X3 = scrt3_string_2d_3elist( X4 );
        X4 = X3;
        X5 = EMPTYLIST;
        X6 = EMPTYLIST;
L12842:
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L12843;
        X2 = X5;
        goto L12850;
L12843:
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L12846;
        scrt1__24__car_2derror( X4 );
L12846:
        X9 = PAIR_CAR( X4 );
        X8 = scrt3_char_2dupcase( X9 );
        X7 = sc_cons( X8, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L12849;
        X8 = PAIR_CDR( X4 );
        X6 = X7;
        X5 = X7;
        X4 = X8;
        GOBACK( L12842 );
L12849:
        X8 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L12854;
        scdebug_error( c12195, 
                       c12196, CONS( X6, EMPTYLIST ) );
L12854:
        X6 = SETGEN( PAIR_CDR( X6 ), X7 );
        X4 = X8;
        GOBACK( L12842 );
L12850:
        X1 = scrt3_list_2d_3estring( X2 );
        POPSTACKTRACE( sc_string_2d_3esymbol( X1 ) );
}

DEFTSCP( dbindings_e_2dstream_4a3d87a7_v );
DEFCSTRING( t12856, "WITH-FILE-STREAM" );
EXTERNTSCPP( toollib_2dc_2dbindings_fopen, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( toollib_2dc_2dbindings_fopen_v );
EXTERNTSCPP( toollib_2dc_2dbindings_fclose, XAL1( TSCP ) );
EXTERNTSCP( toollib_2dc_2dbindings_fclose_v );

TSCP  dbindings_e_2dstream_4a3d87a7( f12207, f12208, m12209 )
        TSCP  f12207, f12208, m12209;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t12856 );
        X1 = toollib_2dc_2dbindings_fopen( f12208, m12209 );
        X3 = f12207;
        X3 = UNKNOWNCALL( X3, 1 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( X1, 
                                          PROCEDURE_CLOSURE( X3 ) );
        toollib_2dc_2dbindings_fclose( X1 );
        POPSTACKTRACE( X2 );
}

DEFTSCP( dbindings_r_2dstream_f6149db3_v );
DEFCSTRING( t12860, "WITH-BUFFER-STREAM" );
EXTERNTSCPP( dbindings_fmemopen_3521495d, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_fmemopen_3521495d_v );

TSCP  dbindings_r_2dstream_f6149db3( f12215, 
                                     b12216, s12217, m12218 )
        TSCP  f12215, b12216, s12217, m12218;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t12860 );
        X1 = dbindings_fmemopen_3521495d( b12216, s12217, m12218 );
        X3 = f12215;
        X3 = UNKNOWNCALL( X3, 1 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( X1, 
                                          PROCEDURE_CLOSURE( X3 ) );
        toollib_2dc_2dbindings_fclose( X1 );
        POPSTACKTRACE( X2 );
}

DEFTSCP( dbindings_trix_2dmax_de624a4f_v );
DEFCSTRING( t12864, "ELEMENTWISE-MATRIX-MAX" );
EXTERNTSCPP( qobischeme_map_2dvector, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dvector_v );
EXTERNTSCPP( scrt2_max_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_max_2dtwo_v );

TSCP  toollib_2dc_2dbindings_l12229( e12230, e12231, c12868 )
        TSCP  e12230, e12231, c12868;
{
        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12229 [inside ELEMENTWISE-M\
ATRIX-MAX]" );
        if  ( BITAND( BITOR( _S2CINT( e12230 ), 
                             _S2CINT( e12231 ) ), 
                      3 ) )  goto L12870;
        if  ( GT( _S2CINT( e12230 ), _S2CINT( e12231 ) ) )  goto L12872;
        POPSTACKTRACE( e12231 );
L12872:
        POPSTACKTRACE( e12230 );
L12870:
        POPSTACKTRACE( scrt2_max_2dtwo( e12230, e12231 ) );
}

TSCP  toollib_2dc_2dbindings_l12226( r12227, r12228, c12866 )
        TSCP  r12227, r12228, c12866;
{
        TSCP  X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12226 [inside ELEMENTWISE-M\
ATRIX-MAX]" );
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dc_2dbindings_l12229, EMPTYLIST );
        POPSTACKTRACE( qobischeme_map_2dvector( X1, 
                                                r12227, 
                                                CONS( r12228, 
                                                      EMPTYLIST ) ) );
}

TSCP  dbindings_trix_2dmax_de624a4f( m12224, m12225 )
        TSCP  m12224, m12225;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12864 );
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dc_2dbindings_l12226, EMPTYLIST );
        POPSTACKTRACE( qobischeme_map_2dvector( X1, 
                                                m12224, 
                                                CONS( m12225, 
                                                      EMPTYLIST ) ) );
}

DEFTSCP( toollib_2dc_2dbindings_fclose_v );
DEFCSTRING( t12874, "FCLOSE" );

TSCP  toollib_2dc_2dbindings_fclose( g12239 )
        TSCP  g12239;
{
        PUSHSTACKTRACE( t12874 );
        fclose( TSCP_POINTER( g12239 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( toollib_2dc_2dbindings_fopen_v );
DEFCSTRING( t12877, "FOPEN" );

TSCP  toollib_2dc_2dbindings_fopen( g12244, g12245 )
        TSCP  g12244, g12245;
{
        PUSHSTACKTRACE( t12877 );
        POPSTACKTRACE( POINTER_TSCP( fopen( TSCP_POINTER( g12244 ), 
                                            TSCP_POINTER( g12245 ) ) ) );
}

DEFTSCP( dbindings_fmemopen_3521495d_v );
DEFCSTRING( t12879, "FMEMOPEN" );

TSCP  dbindings_fmemopen_3521495d( g12250, g12251, g12252 )
        TSCP  g12250, g12251, g12252;
{
        PUSHSTACKTRACE( t12879 );
        POPSTACKTRACE( POINTER_TSCP( fmemopen( TSCP_POINTER( g12250 ), 
                                               TSCP_S2CUINT( g12251 ), 
                                               TSCP_POINTER( g12252 ) ) ) );
}

DEFTSCP( dbindings_c_2dstring_6099dec9_v );
DEFCSTRING( t12881, "WITH-C-STRING" );
EXTERNTSCPP( scrt2__2b_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2b_2dtwo_v );
EXTERNTSCPP( obischeme__2dindexed_d1069d4, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( obischeme__2dindexed_d1069d4_v );
EXTERNTSCPP( scrt4_c_2dbyte_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dbyte_2dset_21_v );

TSCP  toollib_2dc_2dbindings_l12275( c12276, i12277, c12891 )
        TSCP  c12276, i12277, c12891;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12275 [inside WITH-C-STRING\
]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12891, 0 );
        if  ( EQ( TSCPIMMEDIATETAG( c12276 ), CHARACTERTAG ) )  goto L12894;
        scdebug_error( c12282, 
                       c12283, CONS( c12276, EMPTYLIST ) );
L12894:
        X3 = CHAR_FIX( c12276 );
        X2 = scrt4_c_2dbyte_2dset_21( DISPLAY( 2 ), 
                                      i12277, X3 );
        DISPLAY( 2 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  toollib_2dc_2dbindings_l12273( b12274, c12889 )
        TSCP  b12274, c12889;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12273 [inside WITH-C-STRING\
]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12889, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12889, 1 );
        DISPLAY( 2 ) = b12274;
        X4 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dc_2dbindings_l12275, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 2 ) ) );
        X5 = scrt3_string_2d_3elist( DISPLAY( 0 ) );
        obischeme__2dindexed_d1069d4( X4, X5 );
        X5 = DISPLAY( 0 );
        if  ( AND( EQ( TSCPTAG( X5 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X5 ), STRINGTAG ) ) )  goto L12897;
        scdebug_error( c12270, 
                       c12271, CONS( X5, EMPTYLIST ) );
L12897:
        X4 = C_FIXED( STRING_LENGTH( X5 ) );
        scrt4_c_2dbyte_2dset_21( DISPLAY( 2 ), 
                                 X4, _TSCP( 0 ) );
        X7 = DISPLAY( 0 );
        if  ( AND( EQ( TSCPTAG( X7 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X7 ), STRINGTAG ) ) )  goto L12900;
        scdebug_error( c12270, 
                       c12271, CONS( X7, EMPTYLIST ) );
L12900:
        X6 = C_FIXED( STRING_LENGTH( X7 ) );
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12903;
        X5 = _TSCP( IPLUS( _S2CINT( X6 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L12904;
L12903:
        X5 = scrt2__2b_2dtwo( X6, _TSCP( 4 ) );
L12904:
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

TSCP  dbindings_c_2dstring_6099dec9( s12258, f12259 )
        TSCP  s12258, f12259;
{
        TSCP  X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12881 );
        DISPLAY( 0 ) = s12258;
        DISPLAY( 1 ) = f12259;
        X3 = DISPLAY( 0 );
        if  ( AND( EQ( TSCPTAG( X3 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X3 ), STRINGTAG ) ) )  goto L12884;
        scdebug_error( c12270, 
                       c12271, CONS( X3, EMPTYLIST ) );
L12884:
        X2 = C_FIXED( STRING_LENGTH( X3 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12887;
        X1 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L12888;
L12887:
        X1 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L12888:
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12273, 
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
DEFCSTRING( t12905, "WITH-C-STRINGS" );
EXTERNTSCPP( dbindings_c_2dstring_64a7b683, XAL1( TSCP ) );
EXTERNTSCP( dbindings_c_2dstring_64a7b683_v );

TSCP  toollib_2dc_2dbindings_l12307( s12308, c12907 )
        TSCP  s12308, c12907;
{
        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12307 [inside WITH-C-STRING\
S]" );
        POPSTACKTRACE( dbindings_c_2dstring_64a7b683( s12308 ) );
}

EXTERNTSCPP( dbindings_2dpointers_a3114ab5, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_2dpointers_a3114ab5_v );
EXTERNTSCPP( obischeme_h_2dvector_fe309b1e, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( obischeme_h_2dvector_fe309b1e_v );

TSCP  toollib_2dc_2dbindings_l12305( c12306, c12911 )
        TSCP  c12306, c12911;
{
        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12305 [inside WITH-C-STRING\
S]" );
        POPSTACKTRACE( toollib_2dc_2dbindings_free( c12306 ) );
}

TSCP  dbindings__2dstrings_2bd4c34c( f12299, s12300 )
        TSCP  f12299, s12300;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t12905 );
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12307, EMPTYLIST );
        X1 = qobischeme_map_2dvector( X2, s12300, EMPTYLIST );
        X2 = dbindings_2dpointers_a3114ab5( f12299, X1 );
        X3 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12305, EMPTYLIST );
        obischeme_h_2dvector_fe309b1e( X3, X1, EMPTYLIST );
        POPSTACKTRACE( X2 );
}

DEFTSCP( dbindings_c_2dstring_64a7b683_v );
DEFCSTRING( t12913, "STRING->C-STRING" );

TSCP  toollib_2dc_2dbindings_l12313( c12314, i12315, c12922 )
        TSCP  c12314, i12315, c12922;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12313 [inside STRING->C-STR\
ING]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12922, 0 );
        if  ( EQ( TSCPIMMEDIATETAG( c12314 ), CHARACTERTAG ) )  goto L12925;
        scdebug_error( c12282, 
                       c12283, CONS( c12314, EMPTYLIST ) );
L12925:
        X3 = CHAR_FIX( c12314 );
        X2 = scrt4_c_2dbyte_2dset_21( DISPLAY( 0 ), 
                                      i12315, X3 );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  dbindings_c_2dstring_64a7b683( s12310 )
        TSCP  s12310;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12913 );
        if  ( AND( EQ( TSCPTAG( s12310 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( s12310 ), STRINGTAG ) )
            )  goto L12916;
        scdebug_error( c12270, 
                       c12271, CONS( s12310, EMPTYLIST ) );
L12916:
        X2 = C_FIXED( STRING_LENGTH( s12310 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12919;
        X1 = _TSCP( IPLUS( _S2CINT( X2 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L12920;
L12919:
        X1 = scrt2__2b_2dtwo( X2, _TSCP( 4 ) );
L12920:
        DISPLAY( 0 ) = toollib_2dc_2dbindings_malloc( X1 );
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dc_2dbindings_l12313, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X2 = scrt3_string_2d_3elist( s12310 );
        obischeme__2dindexed_d1069d4( X1, X2 );
        X1 = C_FIXED( STRING_LENGTH( s12310 ) );
        scrt4_c_2dbyte_2dset_21( DISPLAY( 0 ), 
                                 X1, _TSCP( 0 ) );
        SDVAL = DISPLAY( 0 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings__3estrings_3b44cc18_v );
DEFCSTRING( t12928, "C-NULL-SEPARATED-STRINGS->STRINGS" );
EXTERNTSCPP( scrt4_c_2ds2cuint_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ds2cuint_2dref_v );
EXTERNTSCPP( scrt2__3d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3d_2dtwo_v );
EXTERNTSCPP( sc_c_2dstring_2d_3estring, XAL1( TSCP ) );
EXTERNTSCP( sc_c_2dstring_2d_3estring_v );
EXTERNTSCPP( scrt1_reverse, XAL1( TSCP ) );
EXTERNTSCP( scrt1_reverse_v );

TSCP  dbindings__3estrings_3b44cc18( c12335 )
        TSCP  c12335;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t12928 );
        X1 = c12335;
        X2 = EMPTYLIST;
        X3 = _TSCP( 0 );
L12931:
        X4 = scrt4_c_2ds2cuint_2dref( X1, _TSCP( 0 ) );
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 0 ) ), 
                             _S2CINT( X4 ) ), 
                      3 ) )  goto L12934;
        if  ( EQ( _S2CUINT( _TSCP( 0 ) ), _S2CUINT( X4 ) ) )  goto L12938;
        goto L12939;
L12934:
        if  ( TRUE( scrt2__3d_2dtwo( _TSCP( 0 ), X4 ) ) )  goto L12938;
L12939:
        X5 = C_FIXED( sizeof( void* ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X5 ) ), 
                      3 ) )  goto L12943;
        X4 = _TSCP( IPLUS( _S2CINT( X1 ), _S2CINT( X5 ) ) );
        goto L12944;
L12943:
        X4 = scrt2__2b_2dtwo( X1, X5 );
L12944:
        X7 = scrt4_c_2ds2cuint_2dref( X1, _TSCP( 0 ) );
        X6 = sc_c_2dstring_2d_3estring( X7 );
        X5 = sc_cons( X6, X2 );
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12945;
        X3 = _TSCP( IPLUS( _S2CINT( X3 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L12946;
L12945:
        X3 = scrt2__2b_2dtwo( X3, _TSCP( 4 ) );
L12946:
        X2 = X5;
        X1 = X4;
        GOBACK( L12931 );
L12938:
        POPSTACKTRACE( scrt1_reverse( X2 ) );
}

DEFTSCP( dbindings_ec_2darray_a0416023_v );
DEFCSTRING( t12947, "WITH-VECTOR->C-ARRAY" );
EXTERNTSCPP( dbindings_th_2darray_e5b6f976, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_th_2darray_e5b6f976_v );
EXTERNTSCPP( dbindings_ec_2darray_b2adc0a3, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_ec_2darray_b2adc0a3_v );

TSCP  toollib_2dc_2dbindings_l12378( a12379, c12952 )
        TSCP  a12379, c12952;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12378 [inside WITH-VECTOR->\
C-ARRAY]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12952, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12952, 1 );
        X3 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c12952, 2 );
        X4 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12952, 3 );
        X7 = dbindings_ec_2darray_b2adc0a3( a12379, 
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

TSCP  dbindings_ec_2darray_a0416023( f12368, 
                                     s12369, e12370, v12371 )
        TSCP  f12368, s12369, e12370, v12371;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SD3 = DISPLAY( 3 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12947 );
        DISPLAY( 0 ) = f12368;
        DISPLAY( 1 ) = s12369;
        DISPLAY( 2 ) = e12370;
        DISPLAY( 3 ) = v12371;
        X2 = DISPLAY( 3 );
        if  ( AND( EQ( TSCPTAG( X2 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X2 ), VECTORTAG ) ) )  goto L12950;
        scdebug_error( c12376, 
                       c12377, CONS( X2, EMPTYLIST ) );
L12950:
        X1 = C_FIXED( VECTOR_LENGTH( X2 ) );
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12378, 
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
DEFCSTRING( t12954, "WITH-VECTOR->C-EXACT-ARRAY" );
EXTERNTSCPP( dbindings_ct_2darray_88cb3000, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_ct_2darray_88cb3000_v );

TSCP  toollib_2dc_2dbindings_l12389( a12390, c12959 )
        TSCP  a12390, c12959;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12389 [inside WITH-VECTOR->\
C-EXACT-ARRAY]" );
        X1 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c12959, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12959, 1 );
        X3 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12959, 2 );
        X4 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12959, 3 );
        X7 = dbindings_ct_2darray_88cb3000( a12390, 
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

TSCP  dbindings_ct_2darray_e7fd79af( f12381, 
                                     e12382, v12383, s12384 )
        TSCP  f12381, e12382, v12383, s12384;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SD3 = DISPLAY( 3 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12954 );
        DISPLAY( 0 ) = f12381;
        DISPLAY( 1 ) = e12382;
        DISPLAY( 2 ) = v12383;
        DISPLAY( 3 ) = s12384;
        X2 = DISPLAY( 2 );
        if  ( AND( EQ( TSCPTAG( X2 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X2 ), VECTORTAG ) ) )  goto L12957;
        scdebug_error( c12376, 
                       c12377, CONS( X2, EMPTYLIST ) );
L12957:
        X1 = C_FIXED( VECTOR_LENGTH( X2 ) );
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12389, 
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
DEFCSTRING( t12961, "WITH-C-POINTERS" );
EXTERNTSCPP( scrt4_c_2ds2cuint_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ds2cuint_2dset_21_v );
EXTERNTSCP( scrt4_c_2dsizeof_2ds2cuint_v );

TSCP  dbindings_2dpointers_a3114ab5( f12392, v12393 )
        TSCP  f12392, v12393;
{
        PUSHSTACKTRACE( t12961 );
        POPSTACKTRACE( dbindings_ec_2darray_a0416023( f12392, 
                                                      scrt4_c_2ds2cuint_2dset_21_v, 
                                                      scrt4_c_2dsizeof_2ds2cuint_v, 
                                                      v12393 ) );
}

DEFTSCP( dbindings_ec_2darray_eed5ca2b_v );
DEFCSTRING( t12963, "LIST->C-ARRAY" );
EXTERNTSCPP( scrt2__2a_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2a_2dtwo_v );

TSCP  toollib_2dc_2dbindings_l12399( x12400, i12401, c12965 )
        TSCP  x12400, i12401, c12965;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12399 [inside LIST->C-ARRAY\
]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12965, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12965, 1 );
        X3 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12965, 2 );
        X7 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( i12401 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L12968;
        X6 = _TSCP( ITIMES( FIXED_C( i12401 ), 
                            _S2CINT( X7 ) ) );
        goto L12969;
L12968:
        X6 = scrt2__2a_2dtwo( i12401, X7 );
L12969:
        X5 = DISPLAY( 1 );
        X5 = UNKNOWNCALL( X5, 3 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( DISPLAY( 0 ), 
                                          X6, 
                                          x12400, 
                                          PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 2 ) = X1;
        DISPLAY( 0 ) = X2;
        DISPLAY( 1 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  dbindings_ec_2darray_eed5ca2b( a12395, 
                                     l12396, s12397, e12398 )
        TSCP  a12395, l12396, s12397, e12398;
{
        TSCP  X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12963 );
        DISPLAY( 0 ) = a12395;
        DISPLAY( 1 ) = s12397;
        DISPLAY( 2 ) = e12398;
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dc_2dbindings_l12399, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        obischeme__2dindexed_d1069d4( X1, l12396 );
        SDVAL = DISPLAY( 0 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings_ct_2darray_9826cb39_v );
DEFCSTRING( t12970, "LIST->C-INEXACT-ARRAY" );
EXTERNTSCPP( dbindings_r_2dset_21_74788212, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_r_2dset_21_74788212_v );

TSCP  dbindings_ct_2darray_9826cb39( a12409, 
                                     l12410, e12411, s12412 )
        TSCP  a12409, l12410, e12411, s12412;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12970 );
        X1 = dbindings_r_2dset_21_74788212( e12411, s12412 );
        POPSTACKTRACE( dbindings_ec_2darray_eed5ca2b( a12409, 
                                                      l12410, 
                                                      X1, e12411 ) );
}

DEFTSCP( dbindings_ct_2darray_b6f75c47_v );
DEFCSTRING( t12972, "LIST->C-EXACT-ARRAY" );
EXTERNTSCPP( dbindings_r_2dset_21_89994f12, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_r_2dset_21_89994f12_v );

TSCP  dbindings_ct_2darray_b6f75c47( a12414, 
                                     l12415, e12416, s12417 )
        TSCP  a12414, l12415, e12416, s12417;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12972 );
        X1 = dbindings_r_2dset_21_89994f12( e12416, s12417 );
        POPSTACKTRACE( dbindings_ec_2darray_eed5ca2b( a12414, 
                                                      l12415, 
                                                      X1, e12416 ) );
}

DEFTSCP( dbindings_ec_2darray_b2adc0a3_v );
DEFCSTRING( t12974, "VECTOR->C-ARRAY" );

TSCP  toollib_2dc_2dbindings_l12423( x12424, i12425, c12976 )
        TSCP  x12424, i12425, c12976;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12423 [inside VECTOR->C-ARR\
AY]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12976, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12976, 1 );
        X3 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12976, 2 );
        X7 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( i12425 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L12979;
        X6 = _TSCP( ITIMES( FIXED_C( i12425 ), 
                            _S2CINT( X7 ) ) );
        goto L12980;
L12979:
        X6 = scrt2__2a_2dtwo( i12425, X7 );
L12980:
        X5 = DISPLAY( 1 );
        X5 = UNKNOWNCALL( X5, 3 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( DISPLAY( 0 ), 
                                          X6, 
                                          x12424, 
                                          PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 2 ) = X1;
        DISPLAY( 0 ) = X2;
        DISPLAY( 1 ) = X3;
        POPSTACKTRACE( X4 );
}

EXTERNTSCPP( qobischeme_enumerate_2dvector, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_enumerate_2dvector_v );

TSCP  dbindings_ec_2darray_b2adc0a3( a12419, 
                                     v12420, s12421, e12422 )
        TSCP  a12419, v12420, s12421, e12422;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12974 );
        DISPLAY( 0 ) = a12419;
        DISPLAY( 1 ) = s12421;
        DISPLAY( 2 ) = e12422;
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dc_2dbindings_l12423, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        if  ( AND( EQ( TSCPTAG( v12420 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( v12420 ), VECTORTAG ) )
            )  goto L12982;
        scdebug_error( c12376, 
                       c12377, CONS( v12420, EMPTYLIST ) );
L12982:
        X2 = C_FIXED( VECTOR_LENGTH( v12420 ) );
        obischeme_h_2dvector_fe309b1e( X1, 
                                       v12420, 
                                       CONS( qobischeme_enumerate_2dvector( X2 ), 
                                             EMPTYLIST ) );
        SDVAL = DISPLAY( 0 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings_ct_2darray_631a01b4_v );
DEFCSTRING( t12984, "VECTOR->C-INEXACT-ARRAY" );

TSCP  dbindings_ct_2darray_631a01b4( a12437, 
                                     v12438, e12439, s12440 )
        TSCP  a12437, v12438, e12439, s12440;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12984 );
        X1 = dbindings_r_2dset_21_74788212( e12439, s12440 );
        POPSTACKTRACE( dbindings_ec_2darray_b2adc0a3( a12437, 
                                                      v12438, 
                                                      X1, e12439 ) );
}

DEFTSCP( dbindings_ct_2darray_88cb3000_v );
DEFCSTRING( t12986, "VECTOR->C-EXACT-ARRAY" );

TSCP  dbindings_ct_2darray_88cb3000( a12442, 
                                     v12443, e12444, s12445 )
        TSCP  a12442, v12443, e12444, s12445;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12986 );
        X1 = dbindings_r_2dset_21_89994f12( e12444, s12445 );
        POPSTACKTRACE( dbindings_ec_2darray_b2adc0a3( a12442, 
                                                      v12443, 
                                                      X1, e12444 ) );
}

DEFTSCP( dbindings_th_2darray_e5b6f976_v );
DEFCSTRING( t12988, "WITH-ARRAY" );

TSCP  dbindings_th_2darray_e5b6f976( e12447, e12448, f12449 )
        TSCP  e12447, e12448, f12449;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12988 );
        if  ( BITAND( BITOR( _S2CINT( e12447 ), 
                             _S2CINT( e12448 ) ), 
                      3 ) )  goto L12990;
        X1 = _TSCP( ITIMES( FIXED_C( e12447 ), 
                            _S2CINT( e12448 ) ) );
        goto L12991;
L12990:
        X1 = scrt2__2a_2dtwo( e12447, e12448 );
L12991:
        POPSTACKTRACE( dbindings_th_2dalloc_20298354( X1, f12449 ) );
}

DEFTSCP( dbindings__2d_3elist_3ba1dc54_v );
DEFCSTRING( t12992, "C-ARRAY->LIST" );
EXTERNTSCPP( scrt4_vector_2d_3elist, XAL1( TSCP ) );
EXTERNTSCP( scrt4_vector_2d_3elist_v );
EXTERNTSCPP( dbindings_d_3evector_3a78c115, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_d_3evector_3a78c115_v );

TSCP  dbindings__2d_3elist_3ba1dc54( a12457, 
                                     g12458, e12459, n12460 )
        TSCP  a12457, g12458, e12459, n12460;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12992 );
        X1 = dbindings_d_3evector_3a78c115( a12457, 
                                            g12458, e12459, n12460 );
        POPSTACKTRACE( scrt4_vector_2d_3elist( X1 ) );
}

DEFTSCP( dbindings_d_3evector_3a78c115_v );
DEFCSTRING( t12994, "C-ARRAY->VECTOR" );
EXTERNTSCPP( qobischeme_map_2dn_2dvector, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dn_2dvector_v );

TSCP  toollib_2dc_2dbindings_l12466( x12467, c12996 )
        TSCP  x12467, c12996;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12466 [inside C-ARRAY->VECT\
OR]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12996, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12996, 1 );
        X3 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12996, 2 );
        X7 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( x12467 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L12999;
        X6 = _TSCP( ITIMES( FIXED_C( x12467 ), 
                            _S2CINT( X7 ) ) );
        goto L13000;
L12999:
        X6 = scrt2__2a_2dtwo( x12467, X7 );
L13000:
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

TSCP  dbindings_d_3evector_3a78c115( a12462, 
                                     g12463, e12464, n12465 )
        TSCP  a12462, g12463, e12464, n12465;
{
        TSCP  X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12994 );
        DISPLAY( 0 ) = a12462;
        DISPLAY( 1 ) = g12463;
        DISPLAY( 2 ) = e12464;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12466, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        SDVAL = qobischeme_map_2dn_2dvector( X1, n12465 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( dbindings__2d_3elist_28c4290c_v );
DEFCSTRING( t13001, "C-EXACT-ARRAY->LIST" );
EXTERNTSCPP( dbindings_d_3evector_85cd03bf, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_d_3evector_85cd03bf_v );

TSCP  dbindings__2d_3elist_28c4290c( a12475, 
                                     e12476, n12477, s12478 )
        TSCP  a12475, e12476, n12477, s12478;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13001 );
        X1 = dbindings_d_3evector_85cd03bf( a12475, 
                                            e12476, n12477, s12478 );
        POPSTACKTRACE( scrt4_vector_2d_3elist( X1 ) );
}

DEFTSCP( dbindings_d_3evector_85cd03bf_v );
DEFCSTRING( t13003, "C-EXACT-ARRAY->VECTOR" );
EXTERNTSCPP( dbindings_dptr_2dref_aed54e95, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_dptr_2dref_aed54e95_v );

TSCP  dbindings_d_3evector_85cd03bf( a12480, 
                                     e12481, n12482, s12483 )
        TSCP  a12480, e12481, n12482, s12483;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13003 );
        X1 = dbindings_dptr_2dref_aed54e95( e12481, s12483 );
        POPSTACKTRACE( dbindings_d_3evector_3a78c115( a12480, 
                                                      X1, 
                                                      e12481, n12482 ) );
}

DEFTSCP( dbindings__2d_3elist_7b0c30a4_v );
DEFCSTRING( t13005, "C-INEXACT-ARRAY->LIST" );
EXTERNTSCPP( dbindings_d_3evector_8778ce56, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_d_3evector_8778ce56_v );

TSCP  dbindings__2d_3elist_7b0c30a4( a12485, 
                                     e12486, n12487, s12488 )
        TSCP  a12485, e12486, n12487, s12488;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13005 );
        X1 = dbindings_d_3evector_8778ce56( a12485, 
                                            e12486, n12487, s12488 );
        POPSTACKTRACE( scrt4_vector_2d_3elist( X1 ) );
}

DEFTSCP( dbindings_d_3evector_8778ce56_v );
DEFCSTRING( t13007, "C-INEXACT-ARRAY->VECTOR" );
EXTERNTSCPP( dbindings_dptr_2dref_e9255e9b, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_dptr_2dref_e9255e9b_v );

TSCP  dbindings_d_3evector_8778ce56( a12490, 
                                     e12491, n12492, s12493 )
        TSCP  a12490, e12491, n12492, s12493;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13007 );
        X1 = dbindings_dptr_2dref_e9255e9b( e12491, s12493 );
        POPSTACKTRACE( dbindings_d_3evector_3a78c115( a12490, 
                                                      X1, 
                                                      e12491, n12492 ) );
}

DEFTSCP( dbindings_e_2doffset_548e9bfc_v );
DEFCSTRING( t13009, "C-PTR-BYTE-OFFSET" );

TSCP  dbindings_e_2doffset_548e9bfc( p12495, o12496 )
        TSCP  p12495, o12496;
{
        PUSHSTACKTRACE( t13009 );
        POPSTACKTRACE( POINTER_TSCP( PLUS( (char*)( TSCP_POINTER( p12495 ) ), 
                                           TSCP_S2CINT( o12496 ) ) ) );
}

DEFTSCP( dbindings_dptr_2dref_aed54e95_v );
DEFCSTRING( t13011, "C-SIZED-INT-PTR-REF" );
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

TSCP  dbindings_dptr_2dref_aed54e95( s12498, s12499 )
        TSCP  s12498, s12499;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13011 );
        if  ( BITAND( BITOR( _S2CINT( s12498 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13014;
        if  ( NEQ( _S2CUINT( s12498 ), 
                   _S2CUINT( _TSCP( 4 ) ) ) )  goto L13018;
        POPSTACKTRACE( scrt4_c_2dbyte_2dref_v );
L13014:
        if  ( FALSE( scrt2__3d_2dtwo( s12498, _TSCP( 4 ) ) ) )  goto L13018;
        POPSTACKTRACE( scrt4_c_2dbyte_2dref_v );
L13018:
        X1 = scrt4_c_2dsizeof_2dshort_v;
        if  ( BITAND( BITOR( _S2CINT( s12498 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13023;
        if  ( EQ( _S2CUINT( s12498 ), _S2CUINT( X1 ) ) )  goto L13027;
        goto L13028;
L13023:
        if  ( FALSE( scrt2__3d_2dtwo( s12498, X1 ) ) )  goto L13028;
L13027:
        if  ( TRUE( s12499 ) )  goto L13031;
        POPSTACKTRACE( scrt4_c_2dshortunsigned_2dref_v );
L13031:
        POPSTACKTRACE( scrt4_c_2dshortint_2dref_v );
L13028:
        X1 = scrt4_c_2dsizeof_2dint_v;
        if  ( BITAND( BITOR( _S2CINT( s12498 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13035;
        if  ( EQ( _S2CUINT( s12498 ), _S2CUINT( X1 ) ) )  goto L13039;
        goto L13040;
L13035:
        if  ( TRUE( scrt2__3d_2dtwo( s12498, X1 ) ) )  goto L13039;
L13040:
        X1 = scrt4_c_2dsizeof_2dlong_v;
        if  ( BITAND( BITOR( _S2CINT( s12498 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13045;
        if  ( EQ( _S2CUINT( s12498 ), _S2CUINT( X1 ) ) )  goto L13049;
        goto L13050;
L13045:
        if  ( FALSE( scrt2__3d_2dtwo( s12498, X1 ) ) )  goto L13050;
L13049:
        if  ( TRUE( s12499 ) )  goto L13053;
        POPSTACKTRACE( scrt4_c_2dlongunsigned_2dref_v );
L13053:
        POPSTACKTRACE( scrt4_c_2dlongint_2dref_v );
L13050:
        POPSTACKTRACE( qobischeme_fuck_2dup(  ) );
L13039:
        if  ( TRUE( s12499 ) )  goto L13055;
        POPSTACKTRACE( scrt4_c_2dunsigned_2dref_v );
L13055:
        POPSTACKTRACE( scrt4_c_2dint_2dref_v );
}

DEFTSCP( dbindings_r_2dset_21_89994f12_v );
DEFCSTRING( t13057, "C-SIZED-INT-PTR-SET!" );
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

TSCP  dbindings_r_2dset_21_89994f12( s12537, s12538 )
        TSCP  s12537, s12538;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13057 );
        if  ( BITAND( BITOR( _S2CINT( s12537 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13060;
        if  ( NEQ( _S2CUINT( s12537 ), 
                   _S2CUINT( _TSCP( 4 ) ) ) )  goto L13064;
        POPSTACKTRACE( scrt4_c_2dbyte_2dset_21_v );
L13060:
        if  ( FALSE( scrt2__3d_2dtwo( s12537, _TSCP( 4 ) ) ) )  goto L13064;
        POPSTACKTRACE( scrt4_c_2dbyte_2dset_21_v );
L13064:
        X1 = scrt4_c_2dsizeof_2dshort_v;
        if  ( BITAND( BITOR( _S2CINT( s12537 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13069;
        if  ( EQ( _S2CUINT( s12537 ), _S2CUINT( X1 ) ) )  goto L13073;
        goto L13074;
L13069:
        if  ( FALSE( scrt2__3d_2dtwo( s12537, X1 ) ) )  goto L13074;
L13073:
        if  ( TRUE( s12538 ) )  goto L13077;
        POPSTACKTRACE( scrt4_d_2dset_21_828269c5_v );
L13077:
        POPSTACKTRACE( scrt4_c_2dshortint_2dset_21_v );
L13074:
        X1 = scrt4_c_2dsizeof_2dint_v;
        if  ( BITAND( BITOR( _S2CINT( s12537 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13081;
        if  ( EQ( _S2CUINT( s12537 ), _S2CUINT( X1 ) ) )  goto L13085;
        goto L13086;
L13081:
        if  ( TRUE( scrt2__3d_2dtwo( s12537, X1 ) ) )  goto L13085;
L13086:
        X1 = scrt4_c_2dsizeof_2dlong_v;
        if  ( BITAND( BITOR( _S2CINT( s12537 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13091;
        if  ( EQ( _S2CUINT( s12537 ), _S2CUINT( X1 ) ) )  goto L13095;
        goto L13096;
L13091:
        if  ( FALSE( scrt2__3d_2dtwo( s12537, X1 ) ) )  goto L13096;
L13095:
        if  ( TRUE( s12538 ) )  goto L13099;
        POPSTACKTRACE( scrt4_d_2dset_21_2e97375c_v );
L13099:
        POPSTACKTRACE( scrt4_c_2dlongint_2dset_21_v );
L13096:
        POPSTACKTRACE( qobischeme_fuck_2dup(  ) );
L13085:
        if  ( TRUE( s12538 ) )  goto L13101;
        POPSTACKTRACE( scrt4_c_2dunsigned_2dset_21_v );
L13101:
        POPSTACKTRACE( scrt4_c_2dint_2dset_21_v );
}

DEFTSCP( dbindings_dptr_2dref_e9255e9b_v );
DEFCSTRING( t13103, "C-SIZED-INEXACT-PTR-REF" );
EXTERNTSCP( scrt4_c_2dsizeof_2dfloat_v );
EXTERNTSCPP( scrt4_c_2dfloat_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dfloat_2dref_v );
EXTERNTSCP( scrt4_c_2dsizeof_2ddouble_v );
EXTERNTSCPP( scrt4_c_2ddouble_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ddouble_2dref_v );

TSCP  dbindings_dptr_2dref_e9255e9b( s12576, s12577 )
        TSCP  s12576, s12577;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13103 );
        X1 = scrt4_c_2dsizeof_2dfloat_v;
        if  ( BITAND( BITOR( _S2CINT( s12576 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13107;
        if  ( NEQ( _S2CUINT( s12576 ), _S2CUINT( X1 ) ) )  goto L13111;
        POPSTACKTRACE( scrt4_c_2dfloat_2dref_v );
L13107:
        if  ( FALSE( scrt2__3d_2dtwo( s12576, X1 ) ) )  goto L13111;
        POPSTACKTRACE( scrt4_c_2dfloat_2dref_v );
L13111:
        X1 = scrt4_c_2dsizeof_2ddouble_v;
        if  ( BITAND( BITOR( _S2CINT( s12576 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13116;
        if  ( NEQ( _S2CUINT( s12576 ), _S2CUINT( X1 ) ) )  goto L13120;
        POPSTACKTRACE( scrt4_c_2ddouble_2dref_v );
L13116:
        if  ( FALSE( scrt2__3d_2dtwo( s12576, X1 ) ) )  goto L13120;
        POPSTACKTRACE( scrt4_c_2ddouble_2dref_v );
L13120:
        POPSTACKTRACE( qobischeme_fuck_2dup(  ) );
}

DEFTSCP( dbindings_r_2dset_21_74788212_v );
DEFCSTRING( t13123, "C-SIZED-INEXACT-PTR-SET!" );
EXTERNTSCPP( scrt4_c_2dfloat_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dfloat_2dset_21_v );
EXTERNTSCPP( scrt4_c_2ddouble_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ddouble_2dset_21_v );

TSCP  dbindings_r_2dset_21_74788212( s12597, s12598 )
        TSCP  s12597, s12598;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13123 );
        X1 = scrt4_c_2dsizeof_2dfloat_v;
        if  ( BITAND( BITOR( _S2CINT( s12597 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13127;
        if  ( NEQ( _S2CUINT( s12597 ), _S2CUINT( X1 ) ) )  goto L13131;
        POPSTACKTRACE( scrt4_c_2dfloat_2dset_21_v );
L13127:
        if  ( FALSE( scrt2__3d_2dtwo( s12597, X1 ) ) )  goto L13131;
        POPSTACKTRACE( scrt4_c_2dfloat_2dset_21_v );
L13131:
        X1 = scrt4_c_2dsizeof_2ddouble_v;
        if  ( BITAND( BITOR( _S2CINT( s12597 ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13136;
        if  ( NEQ( _S2CUINT( s12597 ), _S2CUINT( X1 ) ) )  goto L13140;
        POPSTACKTRACE( scrt4_c_2ddouble_2dset_21_v );
L13136:
        if  ( FALSE( scrt2__3d_2dtwo( s12597, X1 ) ) )  goto L13140;
        POPSTACKTRACE( scrt4_c_2ddouble_2dset_21_v );
L13140:
        POPSTACKTRACE( qobischeme_fuck_2dup(  ) );
}

DEFTSCP( dbindings_ec_2darray_edcfb363_v );
DEFCSTRING( t13143, "MATRIX->C-ARRAY" );
EXTERNTSCPP( qobischeme_for_2deach_2dn, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_for_2deach_2dn_v );
EXTERNTSCPP( qobischeme_matrix_2dcolumns, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_matrix_2dcolumns_v );
EXTERNTSCPP( qobischeme_matrix_2dref, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_matrix_2dref_v );

TSCP  toollib_2dc_2dbindings_l12624( j12625, c13147 )
        TSCP  j12625, c13147;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12624 [inside MATRIX->C-ARR\
AY]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13147, 0 );
        X2 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c13147, 1 );
        X3 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13147, 2 );
        X8 = DISPLAY( 2 );
        X9 = qobischeme_matrix_2dcolumns( DISPLAY( 1 ) );
        if  ( BITAND( BITOR( _S2CINT( X8 ), _S2CINT( X9 ) ), 
                      3 ) )  goto L13150;
        X7 = _TSCP( ITIMES( FIXED_C( X8 ), _S2CINT( X9 ) ) );
        goto L13151;
L13150:
        X7 = scrt2__2a_2dtwo( X8, X9 );
L13151:
        if  ( BITAND( BITOR( _S2CINT( j12625 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L13153;
        X6 = _TSCP( IPLUS( _S2CINT( j12625 ), 
                           _S2CINT( X7 ) ) );
        goto L13154;
L13153:
        X6 = scrt2__2b_2dtwo( j12625, X7 );
L13154:
        X7 = scrt4_c_2dsizeof_2dfloat_v;
        if  ( BITAND( BITOR( _S2CINT( X7 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L13156;
        X5 = _TSCP( ITIMES( FIXED_C( X7 ), _S2CINT( X6 ) ) );
        goto L13157;
L13156:
        X5 = scrt2__2a_2dtwo( X7, X6 );
L13157:
        X6 = qobischeme_matrix_2dref( DISPLAY( 1 ), 
                                      DISPLAY( 2 ), j12625 );
        X4 = scrt4_c_2dfloat_2dset_21( DISPLAY( 0 ), X5, X6 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 2 ) = X2;
        DISPLAY( 0 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  toollib_2dc_2dbindings_l12622( i12623, c13145 )
        TSCP  i12623, c13145;
{
        TSCP  X5, X4, X3, X2, X1;
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12622 [inside MATRIX->C-ARR\
AY]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13145, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13145, 1 );
        DISPLAY( 2 ) = i12623;
        X4 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12624, 
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

TSCP  dbindings_ec_2darray_edcfb363( a12618, 
                                     m12619, s12620, e12621 )
        TSCP  a12618, m12619, s12620, e12621;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13143 );
        DISPLAY( 0 ) = a12618;
        DISPLAY( 1 ) = m12619;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12622, 
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
DEFCSTRING( t13158, "PGM->FLOAT-BUFFER!" );
EXTERNTSCPP( qobischeme_pnm_2dheight, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_pnm_2dheight_v );
EXTERNTSCPP( qobischeme_pnm_2dwidth, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_pnm_2dwidth_v );
EXTERNTSCPP( qobischeme_pgm_2dmaxval, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_pgm_2dmaxval_v );
EXTERNTSCPP( scrt2__2f_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2f_2dtwo_v );

TSCP  toollib_2dc_2dbindings_l12650( e12651, c13169 )
        TSCP  e12651, c13169;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12650 [inside PGM->FLOAT-BU\
FFER!]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13169, 0 );
        X4 = qobischeme_pgm_2dmaxval( DISPLAY( 0 ) );
        X5 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( e12651 ), 
                                          _S2CINT( X4 ) ), 
                                   3 ) ) );
        if  ( FALSE( X5 ) )  goto L13182;
        if  ( EQ( _S2CUINT( X4 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13182;
        X6 = _TSCP( REMAINDER( _S2CINT( e12651 ), 
                               _S2CINT( X4 ) ) );
        if  ( NEQ( _S2CUINT( X6 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13182;
        X3 = C_FIXED( QUOTIENT( _S2CINT( e12651 ), 
                                _S2CINT( X4 ) ) );
        goto L13183;
L13182:
        X3 = scrt2__2f_2dtwo( e12651, X4 );
L13183:
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 1020 ) ) ), 
                      3 ) )  goto L13185;
        X2 = _TSCP( ITIMES( FIXED_C( X3 ), 
                            _S2CINT( _TSCP( 1020 ) ) ) );
        goto L13186;
L13185:
        X2 = scrt2__2a_2dtwo( X3, _TSCP( 1020 ) );
L13186:
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  toollib_2dc_2dbindings_l12648( e12649, c13167 )
        TSCP  e12649, c13167;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dc_2dbindings_l12648 [inside PGM->FLOAT-BU\
FFER!]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13167, 0 );
        X3 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12650, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X2 = qobischeme_map_2dvector( X3, e12649, EMPTYLIST );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

EXTERNTSCPP( qobischeme_pgm_2dgrey, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_pgm_2dgrey_v );

TSCP  dbindings_dbuffer_21_3dc46775( p12645 )
        TSCP  p12645;
{
        TSCP  X5, X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13158 );
        DISPLAY( 0 ) = p12645;
        X4 = qobischeme_pnm_2dheight( DISPLAY( 0 ) );
        X5 = qobischeme_pnm_2dwidth( DISPLAY( 0 ) );
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X4 ) ), 
                      3 ) )  goto L13161;
        X3 = _TSCP( ITIMES( FIXED_C( X5 ), _S2CINT( X4 ) ) );
        goto L13162;
L13161:
        X3 = scrt2__2a_2dtwo( X5, X4 );
L13162:
        X4 = scrt4_c_2dsizeof_2dfloat_v;
        if  ( BITAND( BITOR( _S2CINT( X4 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L13164;
        X2 = _TSCP( ITIMES( FIXED_C( X4 ), _S2CINT( X3 ) ) );
        goto L13165;
L13164:
        X2 = scrt2__2a_2dtwo( X4, X3 );
L13165:
        X1 = toollib_2dc_2dbindings_malloc( X2 );
        X3 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dc_2dbindings_l12648, 
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
DEFCSTRING( t13187, "POPEN" );

TSCP  toollib_2dc_2dbindings_popen( g12692, g12693 )
        TSCP  g12692, g12693;
{
        PUSHSTACKTRACE( t13187 );
        POPSTACKTRACE( POINTER_TSCP( popen( TSCP_POINTER( g12692 ), 
                                            TSCP_POINTER( g12693 ) ) ) );
}

DEFTSCP( toollib_2dc_2dbindings_pclose_v );
DEFCSTRING( t13189, "PCLOSE" );

TSCP  toollib_2dc_2dbindings_pclose( g12698 )
        TSCP  g12698;
{
        PUSHSTACKTRACE( t13189 );
        POPSTACKTRACE( sc_int_tscp( pclose( TSCP_POINTER( g12698 ) ) ) );
}

DEFTSCP( toollib_2dc_2dbindings_srand_v );
DEFCSTRING( t13191, "SRAND" );

TSCP  toollib_2dc_2dbindings_srand( g12702 )
        TSCP  g12702;
{
        PUSHSTACKTRACE( t13191 );
        srand( TSCP_S2CUINT( g12702 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( toollib_2dc_2dbindings_setenv_v );
DEFCSTRING( t13194, "SETENV" );

TSCP  toollib_2dc_2dbindings_setenv( g12707, g12708, g12709 )
        TSCP  g12707, g12708, g12709;
{
        PUSHSTACKTRACE( t13194 );
        POPSTACKTRACE( sc_int_tscp( setenv( TSCP_POINTER( g12707 ), 
                                            TSCP_POINTER( g12708 ), 
                                            tscp_bool( g12709 ) ) ) );
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
        INITIALIZEVAR( t12796, 
                       ADR( dbindings_gs_2d1_2d0_67ee31d0_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_gs_2d1_2d0_67ee31d0, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12798, 
                       ADR( dbindings_gs_2d3_2d0_1d2e62b0_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_gs_2d3_2d0_1d2e62b0, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12800, 
                       ADR( dbindings_gs_2d5_2d0_926e9710_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_gs_2d5_2d0_926e9710, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12802, 
                       ADR( dbindings_gs_2d7_2d0_e8aec470_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_gs_2d7_2d0_e8aec470, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12804, 
                       ADR( dbindings_gs_2d9_2d0_579e7a11_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_gs_2d9_2d0_579e7a11, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12806, 
                       ADR( dbindings_s_2d11_2d0_f9c520e9_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_s_2d11_2d0_f9c520e9, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12808, 
                       ADR( dbindings_s_2d13_2d0_83057389_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_s_2d13_2d0_83057389, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12810, 
                       ADR( dbindings_s_2d15_2d0_c458629_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      dbindings_s_2d15_2d0_c458629, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12812, 
                       ADR( toollib_2dc_2dbindings_curry2_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_curry2, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12818, 
                       ADR( toollib_2dc_2dbindings_malloc_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_malloc, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12820, 
                       ADR( toollib_2dc_2dbindings_memcpy_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      toollib_2dc_2dbindings_memcpy, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12822, 
                       ADR( toollib_2dc_2dbindings_bzero_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      toollib_2dc_2dbindings_bzero, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12825, 
                       ADR( toollib_2dc_2dbindings_free_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_free, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12828, 
                       ADR( dbindings_th_2dalloc_20298354_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_th_2dalloc_20298354, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12833, 
                       ADR( dbindings_c_2dstring_a000da03_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      dbindings_c_2dstring_a000da03, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12838, 
                       ADR( dbindings_d_3esymbol_d89bd1b0_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      dbindings_d_3esymbol_d89bd1b0, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12856, 
                       ADR( dbindings_e_2dstream_4a3d87a7_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      dbindings_e_2dstream_4a3d87a7, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12860, 
                       ADR( dbindings_r_2dstream_f6149db3_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_r_2dstream_f6149db3, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12864, 
                       ADR( dbindings_trix_2dmax_de624a4f_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_trix_2dmax_de624a4f, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12874, 
                       ADR( toollib_2dc_2dbindings_fclose_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_fclose, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12877, 
                       ADR( toollib_2dc_2dbindings_fopen_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      toollib_2dc_2dbindings_fopen, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12879, 
                       ADR( dbindings_fmemopen_3521495d_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      dbindings_fmemopen_3521495d, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12881, 
                       ADR( dbindings_c_2dstring_6099dec9_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_c_2dstring_6099dec9, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12905, 
                       ADR( dbindings__2dstrings_2bd4c34c_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings__2dstrings_2bd4c34c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12913, 
                       ADR( dbindings_c_2dstring_64a7b683_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      dbindings_c_2dstring_64a7b683, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12928, 
                       ADR( dbindings__3estrings_3b44cc18_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      dbindings__3estrings_3b44cc18, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12947, 
                       ADR( dbindings_ec_2darray_a0416023_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ec_2darray_a0416023, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12954, 
                       ADR( dbindings_ct_2darray_e7fd79af_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ct_2darray_e7fd79af, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12961, 
                       ADR( dbindings_2dpointers_a3114ab5_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_2dpointers_a3114ab5, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12963, 
                       ADR( dbindings_ec_2darray_eed5ca2b_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ec_2darray_eed5ca2b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12970, 
                       ADR( dbindings_ct_2darray_9826cb39_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ct_2darray_9826cb39, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12972, 
                       ADR( dbindings_ct_2darray_b6f75c47_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ct_2darray_b6f75c47, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12974, 
                       ADR( dbindings_ec_2darray_b2adc0a3_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ec_2darray_b2adc0a3, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12984, 
                       ADR( dbindings_ct_2darray_631a01b4_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ct_2darray_631a01b4, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12986, 
                       ADR( dbindings_ct_2darray_88cb3000_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ct_2darray_88cb3000, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12988, 
                       ADR( dbindings_th_2darray_e5b6f976_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      dbindings_th_2darray_e5b6f976, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12992, 
                       ADR( dbindings__2d_3elist_3ba1dc54_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings__2d_3elist_3ba1dc54, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12994, 
                       ADR( dbindings_d_3evector_3a78c115_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_d_3evector_3a78c115, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13001, 
                       ADR( dbindings__2d_3elist_28c4290c_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings__2d_3elist_28c4290c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13003, 
                       ADR( dbindings_d_3evector_85cd03bf_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_d_3evector_85cd03bf, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13005, 
                       ADR( dbindings__2d_3elist_7b0c30a4_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings__2d_3elist_7b0c30a4, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13007, 
                       ADR( dbindings_d_3evector_8778ce56_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_d_3evector_8778ce56, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13009, 
                       ADR( dbindings_e_2doffset_548e9bfc_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_e_2doffset_548e9bfc, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13011, 
                       ADR( dbindings_dptr_2dref_aed54e95_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_dptr_2dref_aed54e95, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13057, 
                       ADR( dbindings_r_2dset_21_89994f12_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_r_2dset_21_89994f12, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13103, 
                       ADR( dbindings_dptr_2dref_e9255e9b_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_dptr_2dref_e9255e9b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13123, 
                       ADR( dbindings_r_2dset_21_74788212_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      dbindings_r_2dset_21_74788212, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13143, 
                       ADR( dbindings_ec_2darray_edcfb363_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      dbindings_ec_2darray_edcfb363, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13158, 
                       ADR( dbindings_dbuffer_21_3dc46775_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      dbindings_dbuffer_21_3dc46775, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13187, 
                       ADR( toollib_2dc_2dbindings_popen_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      toollib_2dc_2dbindings_popen, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13189, 
                       ADR( toollib_2dc_2dbindings_pclose_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_pclose, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13191, 
                       ADR( toollib_2dc_2dbindings_srand_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dc_2dbindings_srand, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13194, 
                       ADR( toollib_2dc_2dbindings_setenv_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      toollib_2dc_2dbindings_setenv, 
                                      EMPTYLIST ) );
        return;
}
