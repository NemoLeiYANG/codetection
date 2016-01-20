
/* SCHEME->C */

#include <objects.h>

void toollib_2dmatlab__init();
DEFCSTRING( t13261, "addpath(genpath('~a'))" );
DEFSTATICTSCP( c13001 );
DEFCSTRING( t13262, "Bye" );
DEFSTATICTSCP( c12998 );
DEFCSTRING( t13263, "'Can also get the output from matlab'" );
DEFSTATICTSCP( c12997 );
DEFCSTRING( t13264, "D" );
DEFSTATICTSCP( c12996 );
DEFCSTRING( t13265, "D=randn(2,2,2,2)" );
DEFSTATICTSCP( c12995 );
DEFCSTRING( t13266, "C" );
DEFSTATICTSCP( c12994 );
DEFCSTRING( t13267, "B" );
DEFSTATICTSCP( c12993 );
DEFCSTRING( t13268, "A" );
DEFSTATICTSCP( c12992 );
DEFCSTRING( t13269, "C=1" );
DEFSTATICTSCP( c12991 );
DEFCSTRING( t13270, "B='Hi'" );
DEFSTATICTSCP( c12990 );
DEFCSTRING( t13271, "A=[[1,2,3];[4,5,6]]" );
DEFSTATICTSCP( c12989 );
DEFCSTRING( t13272, "~a is ~a~%" );
DEFSTATICTSCP( c12984 );
DEFCSTRING( t13273, "load ~a" );
DEFSTATICTSCP( c12979 );
DEFCSTRING( t13274, "~a " );
DEFSTATICTSCP( c12976 );
DEFCSTRING( t13275, "save ~a ~a" );
DEFSTATICTSCP( c12931 );
DEFCSTRING( t13276, "~a=imread('~a');" );
DEFSTATICTSCP( c12906 );
DEFCSTRING( t13277, "matlab.pbm" );
DEFSTATICTSCP( c12903 );
DEFCSTRING( t13278, "matlab.pgm" );
DEFSTATICTSCP( c12902 );
DEFCSTRING( t13279, "matlab.ppm" );
DEFSTATICTSCP( c12901 );
DEFCSTRING( t13280, "; " );
DEFSTATICTSCP( c12886 );
DEFCSTRING( t13281, "~a=~a" );
DEFSTATICTSCP( c12882 );
DEFCSTRING( t13282, "~a=~a;" );
DEFSTATICTSCP( c12879 );
DEFCSTRING( t13283, "~a = importdata('~a', ' ');" );
DEFSTATICTSCP( c12878 );
DEFCSTRING( t13284, "/tmp/matlabmatrix.m" );
DEFSTATICTSCP( c12875 );
DEFCSTRING( t13285, "]" );
DEFSTATICTSCP( c12833 );
DEFCSTRING( t13286, ", " );
DEFSTATICTSCP( c12818 );
DEFCSTRING( t13287, "[" );
DEFSTATICTSCP( c12814 );
DEFCSTRING( t13288, "Index is not in bounds: ~s" );
DEFSTATICTSCP( c12784 );
DEFCSTRING( t13289, "Argument is not an INTEGER: ~s" );
DEFSTATICTSCP( c12780 );
DEFSTATICTSCP( c12777 );
DEFCSTRING( t13290, "Argument is not a VECTOR: ~s" );
DEFSTATICTSCP( c12768 );
DEFSTATICTSCP( c12767 );
DEFCSTRING( t13291, "~%" );
DEFSTATICTSCP( c12742 );
DEFCSTRING( t13292, " ~a" );
DEFSTATICTSCP( c12740 );
DEFCSTRING( t13293, "Argument not a PAIR: ~s" );
DEFSTATICTSCP( c12661 );
DEFSTATICTSCP( c12660 );
DEFSTATICTSCP( c12543 );
DEFSTATICTSCP( c12420 );
DEFSTATICTSCP( c12404 );
DEFSTATICTSCP( c12388 );
DEFSTATICTSCP( c12378 );
DEFCSTRING( t13294, "MATLAB_LOCAL_ARGS" );
DEFSTATICTSCP( c12225 );
DEFCSTRING( t13295, "matlab -nosplash -nodesktop " );
DEFSTATICTSCP( c12222 );

static void  init_constants()
{
        c13001 = CSTRING_TSCP( t13261 );
        CONSTANTEXP( ADR( c13001 ) );
        c12998 = CSTRING_TSCP( t13262 );
        CONSTANTEXP( ADR( c12998 ) );
        c12997 = CSTRING_TSCP( t13263 );
        CONSTANTEXP( ADR( c12997 ) );
        c12996 = CSTRING_TSCP( t13264 );
        CONSTANTEXP( ADR( c12996 ) );
        c12995 = CSTRING_TSCP( t13265 );
        CONSTANTEXP( ADR( c12995 ) );
        c12994 = CSTRING_TSCP( t13266 );
        CONSTANTEXP( ADR( c12994 ) );
        c12993 = CSTRING_TSCP( t13267 );
        CONSTANTEXP( ADR( c12993 ) );
        c12992 = CSTRING_TSCP( t13268 );
        CONSTANTEXP( ADR( c12992 ) );
        c12991 = CSTRING_TSCP( t13269 );
        CONSTANTEXP( ADR( c12991 ) );
        c12990 = CSTRING_TSCP( t13270 );
        CONSTANTEXP( ADR( c12990 ) );
        c12989 = CSTRING_TSCP( t13271 );
        CONSTANTEXP( ADR( c12989 ) );
        c12984 = CSTRING_TSCP( t13272 );
        CONSTANTEXP( ADR( c12984 ) );
        c12979 = CSTRING_TSCP( t13273 );
        CONSTANTEXP( ADR( c12979 ) );
        c12976 = CSTRING_TSCP( t13274 );
        CONSTANTEXP( ADR( c12976 ) );
        c12931 = CSTRING_TSCP( t13275 );
        CONSTANTEXP( ADR( c12931 ) );
        c12906 = CSTRING_TSCP( t13276 );
        CONSTANTEXP( ADR( c12906 ) );
        c12903 = CSTRING_TSCP( t13277 );
        CONSTANTEXP( ADR( c12903 ) );
        c12902 = CSTRING_TSCP( t13278 );
        CONSTANTEXP( ADR( c12902 ) );
        c12901 = CSTRING_TSCP( t13279 );
        CONSTANTEXP( ADR( c12901 ) );
        c12886 = CSTRING_TSCP( t13280 );
        CONSTANTEXP( ADR( c12886 ) );
        c12882 = CSTRING_TSCP( t13281 );
        CONSTANTEXP( ADR( c12882 ) );
        c12879 = CSTRING_TSCP( t13282 );
        CONSTANTEXP( ADR( c12879 ) );
        c12878 = CSTRING_TSCP( t13283 );
        CONSTANTEXP( ADR( c12878 ) );
        c12875 = CSTRING_TSCP( t13284 );
        CONSTANTEXP( ADR( c12875 ) );
        c12833 = CSTRING_TSCP( t13285 );
        CONSTANTEXP( ADR( c12833 ) );
        c12818 = CSTRING_TSCP( t13286 );
        CONSTANTEXP( ADR( c12818 ) );
        c12814 = CSTRING_TSCP( t13287 );
        CONSTANTEXP( ADR( c12814 ) );
        c12784 = CSTRING_TSCP( t13288 );
        CONSTANTEXP( ADR( c12784 ) );
        c12780 = CSTRING_TSCP( t13289 );
        CONSTANTEXP( ADR( c12780 ) );
        c12777 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR-REF" ) );
        CONSTANTEXP( ADR( c12777 ) );
        c12768 = CSTRING_TSCP( t13290 );
        CONSTANTEXP( ADR( c12768 ) );
        c12767 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR-LENGTH" ) );
        CONSTANTEXP( ADR( c12767 ) );
        c12742 = CSTRING_TSCP( t13291 );
        CONSTANTEXP( ADR( c12742 ) );
        c12740 = CSTRING_TSCP( t13292 );
        CONSTANTEXP( ADR( c12740 ) );
        c12661 = CSTRING_TSCP( t13293 );
        CONSTANTEXP( ADR( c12661 ) );
        c12660 = STRINGTOSYMBOL( CSTRING_TSCP( "SET-CDR!" ) );
        CONSTANTEXP( ADR( c12660 ) );
        c12543 = EMPTYLIST;
        c12543 = CONS( FALSEVALUE, c12543 );
        c12543 = CONS( FALSEVALUE, c12543 );
        CONSTANTEXP( ADR( c12543 ) );
        c12420 = STRINGTOSYMBOL( CSTRING_TSCP( "UNSIGNED" ) );
        CONSTANTEXP( ADR( c12420 ) );
        c12404 = STRINGTOSYMBOL( CSTRING_TSCP( "SIGNED" ) );
        CONSTANTEXP( ADR( c12404 ) );
        c12388 = STRINGTOSYMBOL( CSTRING_TSCP( "INEXACT" ) );
        CONSTANTEXP( ADR( c12388 ) );
        c12378 = STRINGTOSYMBOL( CSTRING_TSCP( "EXACT" ) );
        CONSTANTEXP( ADR( c12378 ) );
        c12225 = CSTRING_TSCP( t13294 );
        CONSTANTEXP( ADR( c12225 ) );
        c12222 = CSTRING_TSCP( t13295 );
        CONSTANTEXP( ADR( c12222 ) );
}

DEFTSCP( _2dmatlab_ab_2d1_2d0_619fbe9b_v );
DEFCSTRING( t13296, "gensym-toollib_2dmatlab-1-0" );

TSCP  _2dmatlab_ab_2d1_2d0_619fbe9b(  )
{
        PUSHSTACKTRACE( t13296 );
        POPSTACKTRACE( 0 );}
  #include<stddef.h>
int gensym_toollib_2dmatlab_2_0(){ return 1;gensym_toollib_2dmatlab_2_0( );
}

DEFTSCP( _2dmatlab_ab_2d3_2d0_1b5fedfb_v );
DEFCSTRING( t13298, "gensym-toollib_2dmatlab-3-0" );

TSCP  _2dmatlab_ab_2d3_2d0_1b5fedfb(  )
{
        PUSHSTACKTRACE( t13298 );
        POPSTACKTRACE( 0 );}
  #include<stdlib.h>
int gensym_toollib_2dmatlab_4_0(){ return 1;gensym_toollib_2dmatlab_4_0( );
}

DEFTSCP( _2dmatlab_ab_2d5_2d0_941f185b_v );
DEFCSTRING( t13300, "gensym-toollib_2dmatlab-5-0" );

TSCP  _2dmatlab_ab_2d5_2d0_941f185b(  )
{
        PUSHSTACKTRACE( t13300 );
        POPSTACKTRACE( 0 );}
  #include<string.h>
int gensym_toollib_2dmatlab_6_0(){ return 1;gensym_toollib_2dmatlab_6_0( );
}

DEFTSCP( _2dmatlab_ab_2d7_2d0_eedf4b3b_v );
DEFCSTRING( t13302, "gensym-toollib_2dmatlab-7-0" );

TSCP  _2dmatlab_ab_2d7_2d0_eedf4b3b(  )
{
        PUSHSTACKTRACE( t13302 );
        POPSTACKTRACE( 0 );}
  #include<engine.h>
int gensym_toollib_2dmatlab_8_0(){ return 1;gensym_toollib_2dmatlab_8_0( );
}

DEFTSCP( toollib_2dmatlab__2aengine_2a_v );
DEFCSTRING( t13304, "*ENGINE*" );
DEFTSCP( _2dmatlab_unknown_2a_69db4cfa_v );
DEFCSTRING( t13305, "*MATLAB-CLASS-UNKNOWN*" );
DEFTSCP( _2dmatlab__2dcell_2a_e48494a5_v );
DEFCSTRING( t13306, "*MATLAB-CLASS-CELL*" );
DEFTSCP( _2dmatlab_dstruct_2a_865a332_v );
DEFCSTRING( t13307, "*MATLAB-CLASS-STRUCT*" );
DEFTSCP( _2dmatlab_logical_2a_578b388_v );
DEFCSTRING( t13308, "*MATLAB-CLASS-LOGICAL*" );
DEFTSCP( _2dmatlab__2dchar_2a_104c6366_v );
DEFCSTRING( t13309, "*MATLAB-CLASS-CHAR*" );
DEFTSCP( _2dmatlab_ddouble_2a_50940a71_v );
DEFCSTRING( t13310, "*MATLAB-CLASS-DOUBLE*" );
DEFTSCP( _2dmatlab_dsingle_2a_6b4e75c9_v );
DEFCSTRING( t13311, "*MATLAB-CLASS-SINGLE*" );
DEFTSCP( _2dmatlab__2dint8_2a_3ecc7f9e_v );
DEFCSTRING( t13312, "*MATLAB-CLASS-INT8*" );
DEFTSCP( _2dmatlab_2duint8_2a_8ba934f3_v );
DEFCSTRING( t13313, "*MATLAB-CLASS-UINT8*" );
DEFTSCP( _2dmatlab_2dint16_2a_b79bafee_v );
DEFCSTRING( t13314, "*MATLAB-CLASS-INT16*" );
DEFTSCP( _2dmatlab_duint16_2a_842dd740_v );
DEFCSTRING( t13315, "*MATLAB-CLASS-UINT16*" );
DEFTSCP( _2dmatlab_2dint32_2a_42396bd9_v );
DEFCSTRING( t13316, "*MATLAB-CLASS-INT32*" );
DEFTSCP( _2dmatlab_duint32_2a_718f1377_v );
DEFCSTRING( t13317, "*MATLAB-CLASS-UINT32*" );
DEFTSCP( _2dmatlab_2dint64_2a_afb2bb75_v );
DEFCSTRING( t13318, "*MATLAB-CLASS-INT64*" );
DEFTSCP( _2dmatlab_duint64_2a_9c04c3db_v );
DEFCSTRING( t13319, "*MATLAB-CLASS-UINT64*" );
DEFTSCP( _2dmatlab_unction_2a_a6175284_v );
DEFCSTRING( t13320, "*MATLAB-CLASS-FUNCTION*" );
DEFTSCP( _2dmatlab_dmwsize_2a_a6db3d23_v );
DEFCSTRING( t13321, "*MATLAB-SIZEOF-MWSIZE*" );
DEFTSCP( _2dmatlab_dstring_2a_91664f11_v );
DEFCSTRING( t13322, "*MATLAB-LARGEST-STRING*" );
DEFTSCP( _2dmatlab_ab_2dstart_c0162d0_v );
DEFCSTRING( t13323, "MATLAB-START" );

TSCP  _2dmatlab_ab_2dstart_c0162d0( g12143 )
        TSCP  g12143;
{
        PUSHSTACKTRACE( t13323 );
        POPSTACKTRACE( POINTER_TSCP( engOpen( TSCP_POINTER( g12143 ) ) ) );
}

DEFTSCP( _2dmatlab_lab_2dstop_c7f4a41d_v );
DEFCSTRING( t13325, "MATLAB-STOP" );

TSCP  _2dmatlab_lab_2dstop_c7f4a41d( g12147 )
        TSCP  g12147;
{
        PUSHSTACKTRACE( t13325 );
        POPSTACKTRACE( sc_int_tscp( engClose( TSCP_POINTER( g12147 ) ) ) );
}

DEFTSCP( _2dmatlab_2dvariable_9a356ebb_v );
DEFCSTRING( t13327, "MATLAB-VARIABLE" );

TSCP  _2dmatlab_2dvariable_9a356ebb( g12151, g12152 )
        TSCP  g12151, g12152;
{
        PUSHSTACKTRACE( t13327 );
        POPSTACKTRACE( POINTER_TSCP( engGetVariable( TSCP_POINTER( g12151 ), 
                                                     TSCP_POINTER( g12152 ) ) ) );
}

DEFTSCP( _2dmatlab_e_2dset_21_bf7b6c17_v );
DEFCSTRING( t13329, "MATLAB-VARIABLE-SET!" );

TSCP  _2dmatlab_e_2dset_21_bf7b6c17( g12157, g12158, g12159 )
        TSCP  g12157, g12158, g12159;
{
        PUSHSTACKTRACE( t13329 );
        POPSTACKTRACE( sc_int_tscp( engPutVariable( TSCP_POINTER( g12157 ), 
                                                    TSCP_POINTER( g12158 ), 
                                                    TSCP_POINTER( g12159 ) ) ) );
}

DEFTSCP( _2dmatlab_l_2dstring_886dffe8_v );
DEFCSTRING( t13331, "C-MATLAB-EVAL-STRING" );

TSCP  _2dmatlab_l_2dstring_886dffe8( g12165, g12166 )
        TSCP  g12165, g12166;
{
        PUSHSTACKTRACE( t13331 );
        POPSTACKTRACE( sc_int_tscp( engEvalString( TSCP_POINTER( g12165 ), 
                                                   TSCP_POINTER( g12166 ) ) ) );
}

DEFTSCP( _2dmatlab_t_2dbuffer_abe73f78_v );
DEFCSTRING( t13333, "MATLAB-SET-OUTPUT-BUFFER" );

TSCP  _2dmatlab_t_2dbuffer_abe73f78( g12171, g12172, g12173 )
        TSCP  g12171, g12172, g12173;
{
        PUSHSTACKTRACE( t13333 );
        POPSTACKTRACE( sc_int_tscp( engOutputBuffer( TSCP_POINTER( g12171 ), 
                                                     TSCP_POINTER( g12172 ), 
                                                     sc_tscp_int( g12173 ) ) ) );
}

DEFTSCP( _2dmatlab__2dvisible_f8d2b7e5_v );
DEFCSTRING( t13335, "MATLAB-SET-VISIBLE" );

TSCP  _2dmatlab__2dvisible_f8d2b7e5( g12179, g12180 )
        TSCP  g12179, g12180;
{
        PUSHSTACKTRACE( t13335 );
        POPSTACKTRACE( sc_int_tscp( engSetVisible( TSCP_POINTER( g12179 ), 
                                                   sc_tscp_int( g12180 ) ) ) );
}

DEFTSCP( _2dmatlab__2dvisible_8c6c7ba9_v );
DEFCSTRING( t13337, "MATLAB-GET-VISIBLE" );

TSCP  _2dmatlab__2dvisible_8c6c7ba9( g12185, g12186 )
        TSCP  g12185, g12186;
{
        PUSHSTACKTRACE( t13337 );
        POPSTACKTRACE( sc_int_tscp( engGetVisible( TSCP_POINTER( g12185 ), 
                                                   TSCP_POINTER( g12186 ) ) ) );
}

DEFTSCP( _2dmatlab_l_2dstring_42ef7035_v );
DEFCSTRING( t13339, "MATLAB-EVAL-STRING" );
EXTERNTSCPP( _2dmatlab_dmatlab_21_16b982d3, XAL0(  ) );
EXTERNTSCP( _2dmatlab_dmatlab_21_16b982d3_v );

TSCP  _2dmatlab_l_2dstring_42ef7035( s12191 )
        TSCP  s12191;
{
        PUSHSTACKTRACE( t13339 );
        _2dmatlab_dmatlab_21_16b982d3(  );
        POPSTACKTRACE( _2dmatlab_l_2dstring_886dffe8( toollib_2dmatlab__2aengine_2a_v, 
                                                      s12191 ) );
}

DEFTSCP( _2dmatlab__2dstrings_9ffd0bd5_v );
DEFCSTRING( t13341, "MATLAB-EVAL-STRINGS" );
EXTERNTSCPP( scrt1__24__car_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__car_2derror_v );

TSCP  _2dmatlab__2dstrings_9ffd0bd5( s12193 )
        TSCP  s12193;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t13341 );
        X1 = s12193;
L13344:
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( EMPTYLIST ) ) )  goto L13345;
        if  ( EQ( TSCPTAG( X1 ), PAIRTAG ) )  goto L13349;
        scrt1__24__car_2derror( X1 );
L13349:
        X2 = PAIR_CAR( X1 );
        _2dmatlab_l_2dstring_42ef7035( X2 );
        X1 = PAIR_CDR( X1 );
        GOBACK( L13344 );
L13345:
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( toollib_2dmatlab_matlab_v );
DEFCSTRING( t13352, "MATLAB" );
EXTERNTSCPP( _2dmatlab_t_2dbuffer_7a8e4db7, XAL1( TSCP ) );
EXTERNTSCP( _2dmatlab_t_2dbuffer_7a8e4db7_v );
EXTERNTSCPP( sc_apply_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_apply_2dtwo_v );

TSCP  toollib_2dmatlab_l12220( m12221, c13354 )
        TSCP  m12221, c13354;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12220 [inside MATLAB]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13354, 0 );
        sc_apply_2dtwo( _2dmatlab__2dstrings_9ffd0bd5_v, 
                        DISPLAY( 0 ) );
        X3 = m12221;
        X3 = UNKNOWNCALL( X3, 0 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( PROCEDURE_CLOSURE( X3 ) );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  toollib_2dmatlab_matlab( s12219 )
        TSCP  s12219;
{
        TSCP  X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13352 );
        DISPLAY( 0 ) = s12219;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l12220, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        SDVAL = _2dmatlab_t_2dbuffer_7a8e4db7( X1 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( _2dmatlab_command_2a_623f14aa_v );
DEFCSTRING( t13356, "*DEFAULT-MATLAB-ENGINE-COMMAND*" );
EXTERNTSCPP( scrt3_string_2dappend, XAL1( TSCP ) );
EXTERNTSCP( scrt3_string_2dappend_v );
EXTERNTSCPP( qobischeme_getenv, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_getenv_v );
EXTERNTSCP( sc_emptystring );
DEFTSCP( _2dmatlab__2dsize_2a_c1ed6d46_v );
DEFCSTRING( t13360, "*DEFAULT-MATLAB-BUFFER-SIZE*" );
DEFTSCP( _2dmatlab_t_2dengine_3085bf6d_v );
DEFCSTRING( t13361, "WITH-MATLAB-DEFAULT-ENGINE" );
EXTERNTSCPP( _2dmatlab_b_2dengine_825e1e81, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( _2dmatlab_b_2dengine_825e1e81_v );

TSCP  _2dmatlab_t_2dengine_3085bf6d( f12228 )
        TSCP  f12228;
{
        PUSHSTACKTRACE( t13361 );
        POPSTACKTRACE( _2dmatlab_b_2dengine_825e1e81( _2dmatlab_command_2a_623f14aa_v, 
                                                      f12228 ) );
}

DEFTSCP( _2dmatlab_b_2dengine_825e1e81_v );
DEFCSTRING( t13363, "WITH-MATLAB-ENGINE" );

TSCP  _2dmatlab_b_2dengine_825e1e81( s12230, f12231 )
        TSCP  s12230, f12231;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t13363 );
        toollib_2dmatlab__2aengine_2a_v = _2dmatlab_ab_2dstart_c0162d0( s12230 );
        X2 = f12231;
        X2 = UNKNOWNCALL( X2, 0 );
        X1 = VIA( PROCEDURE_CODE( X2 ) )( PROCEDURE_CLOSURE( X2 ) );
        _2dmatlab_lab_2dstop_c7f4a41d( toollib_2dmatlab__2aengine_2a_v );
        POPSTACKTRACE( X1 );
}

DEFTSCP( _2dmatlab_t_2dbuffer_7a8e4db7_v );
DEFCSTRING( t13366, "WITH-MATLAB-DEFAULT-OUTPUT-BUFFER" );
EXTERNTSCPP( _2dmatlab_t_2dbuffer_3ead3d9b, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( _2dmatlab_t_2dbuffer_3ead3d9b_v );

TSCP  _2dmatlab_t_2dbuffer_7a8e4db7( f12235 )
        TSCP  f12235;
{
        PUSHSTACKTRACE( t13366 );
        POPSTACKTRACE( _2dmatlab_t_2dbuffer_3ead3d9b( _2dmatlab__2dsize_2a_c1ed6d46_v, 
                                                      f12235 ) );
}

DEFTSCP( _2dmatlab_t_2dbuffer_3ead3d9b_v );
DEFCSTRING( t13368, "WITH-MATLAB-OUTPUT-BUFFER" );
EXTERNTSCPP( dbindings_th_2dalloc_20298354, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_th_2dalloc_20298354_v );
EXTERNTSCPP( sc_c_2dstring_2d_3estring, XAL1( TSCP ) );
EXTERNTSCP( sc_c_2dstring_2d_3estring_v );

TSCP  toollib_2dmatlab_l12243( c13372 )
        TSCP  c13372;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12243 [inside WITH-MATLAB-OUTPUT-\
BUFFER]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c13372, 0 );
        X2 = sc_c_2dstring_2d_3estring( DISPLAY( 2 ) );
        DISPLAY( 2 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  toollib_2dmatlab_l12239( b12240, c13370 )
        TSCP  b12240, c13370;
{
        TSCP  X6, X5, X4, X3, X2, X1;
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12239 [inside WITH-MATLAB-OUTPUT-\
BUFFER]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13370, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13370, 1 );
        DISPLAY( 2 ) = b12240;
        _2dmatlab_t_2dbuffer_abe73f78( toollib_2dmatlab__2aengine_2a_v, 
                                       DISPLAY( 2 ), 
                                       DISPLAY( 0 ) );
        X6 = MAKEPROCEDURE( 0, 
                            0, 
                            toollib_2dmatlab_l12243, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 2 ) ) );
        X5 = DISPLAY( 1 );
        X5 = UNKNOWNCALL( X5, 1 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( X6, 
                                          PROCEDURE_CLOSURE( X5 ) );
        _2dmatlab_t_2dbuffer_abe73f78( toollib_2dmatlab__2aengine_2a_v, 
                                       _TSCP( 0 ), _TSCP( 0 ) );
        X3 = X4;
        DISPLAY( 0 ) = X1;
        DISPLAY( 1 ) = X2;
        SDVAL = X3;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

TSCP  _2dmatlab_t_2dbuffer_3ead3d9b( s12237, f12238 )
        TSCP  s12237, f12238;
{
        TSCP  X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13368 );
        DISPLAY( 0 ) = s12237;
        DISPLAY( 1 ) = f12238;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l12239, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        SDVAL = dbindings_th_2dalloc_20298354( DISPLAY( 0 ), X1 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( _2dmatlab_dmatlab_21_16b982d3_v );
DEFCSTRING( t13375, "START-MATLAB!" );

TSCP  _2dmatlab_dmatlab_21_16b982d3(  )
{
        PUSHSTACKTRACE( t13375 );
        if  ( TRUE( toollib_2dmatlab__2aengine_2a_v ) )  goto L13377;
        POPSTACKTRACE( SET( toollib_2dmatlab__2aengine_2a_v, 
                            _2dmatlab_ab_2dstart_c0162d0( _2dmatlab_command_2a_623f14aa_v ) ) );
L13377:
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( _2dmatlab_class_2did_6f364104_v );
DEFCSTRING( t13379, "MATLAB-CLASS-ID" );

TSCP  _2dmatlab_class_2did_6f364104( g12246 )
        TSCP  g12246;
{
        PUSHSTACKTRACE( t13379 );
        POPSTACKTRACE( sc_int_tscp( mxGetClassID( TSCP_POINTER( g12246 ) ) ) );
}

DEFTSCP( _2dmatlab_ass_2dname_1320a15b_v );
DEFCSTRING( t13381, "MATLAB-CLASS-NAME" );

TSCP  _2dmatlab_ass_2dname_1320a15b( g12250 )
        TSCP  g12250;
{
        PUSHSTACKTRACE( t13381 );
        POPSTACKTRACE( CSTRING_TSCP( mxGetClassName( TSCP_POINTER( g12250 ) ) ) );
}

DEFTSCP( _2dmatlab_d_3estring_73505745_v );
DEFCSTRING( t13383, "MATLAB-ARRAY->STRING" );

TSCP  _2dmatlab_d_3estring_73505745( g12254 )
        TSCP  g12254;
{
        PUSHSTACKTRACE( t13383 );
        POPSTACKTRACE( CSTRING_TSCP( mxArrayToString( TSCP_POINTER( g12254 ) ) ) );
}

DEFTSCP( _2dmatlab_b_2dcalloc_b4566400_v );
DEFCSTRING( t13385, "MATLAB-CALLOC" );

TSCP  _2dmatlab_b_2dcalloc_b4566400( g12258, g12259 )
        TSCP  g12258, g12259;
{
        PUSHSTACKTRACE( t13385 );
        POPSTACKTRACE( POINTER_TSCP( mxCalloc( sc_tscp_int( g12258 ), 
                                               sc_tscp_int( g12259 ) ) ) );
}

DEFTSCP( _2dmatlab_b_2dmalloc_8e5c0570_v );
DEFCSTRING( t13387, "MATLAB-MALLOC" );

TSCP  _2dmatlab_b_2dmalloc_8e5c0570( g12264 )
        TSCP  g12264;
{
        PUSHSTACKTRACE( t13387 );
        POPSTACKTRACE( POINTER_TSCP( mxMalloc( sc_tscp_int( g12264 ) ) ) );
}

DEFTSCP( _2dmatlab_lab_2dfree_338c7363_v );
DEFCSTRING( t13389, "MATLAB-FREE" );

TSCP  _2dmatlab_lab_2dfree_338c7363( g12268 )
        TSCP  g12268;
{
        PUSHSTACKTRACE( t13389 );
        mxFree( TSCP_POINTER( g12268 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( _2dmatlab_c_2dmatrix_c3b5fb97_v );
DEFCSTRING( t13392, "MATLAB-MAKE-NUMERIC-MATRIX" );

TSCP  _2dmatlab_c_2dmatrix_c3b5fb97( g12273, 
                                     g12274, g12275, g12276 )
        TSCP  g12273, g12274, g12275, g12276;
{
        PUSHSTACKTRACE( t13392 );
        POPSTACKTRACE( POINTER_TSCP( mxCreateNumericMatrix( sc_tscp_int( g12273 ), 
                                                            sc_tscp_int( g12274 ), 
                                                            sc_tscp_int( g12275 ), 
                                                            sc_tscp_int( g12276 ) ) ) );
}

DEFTSCP( _2dmatlab__2ddestroy_b80de368_v );
DEFCSTRING( t13394, "MATLAB-DESTROY" );

TSCP  _2dmatlab__2ddestroy_b80de368( g12283 )
        TSCP  g12283;
{
        PUSHSTACKTRACE( t13394 );
        mxDestroyArray( TSCP_POINTER( g12283 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( _2dmatlab_dnr_2drows_5a611f40_v );
DEFCSTRING( t13397, "MATLAB-NR-ROWS" );

TSCP  _2dmatlab_dnr_2drows_5a611f40( g12288 )
        TSCP  g12288;
{
        PUSHSTACKTRACE( t13397 );
        POPSTACKTRACE( sc_int_tscp( mxGetM( TSCP_POINTER( g12288 ) ) ) );
}

DEFTSCP( _2dmatlab__2dcolumns_6fa8223_v );
DEFCSTRING( t13399, "MATLAB-NR-COLUMNS" );

TSCP  _2dmatlab__2dcolumns_6fa8223( g12292 )
        TSCP  g12292;
{
        PUSHSTACKTRACE( t13399 );
        POPSTACKTRACE( sc_int_tscp( mxGetN( TSCP_POINTER( g12292 ) ) ) );
}

DEFTSCP( _2dmatlab_dimensions_4dd9b03_v );
DEFCSTRING( t13401, "MATLAB-NR-DIMENSIONS" );

TSCP  _2dmatlab_dimensions_4dd9b03( g12296 )
        TSCP  g12296;
{
        PUSHSTACKTRACE( t13401 );
        POPSTACKTRACE( sc_int_tscp( mxGetNumberOfDimensions( TSCP_POINTER( g12296 ) ) ) );
}

DEFTSCP( _2dmatlab_2delements_61808bcf_v );
DEFCSTRING( t13403, "MATLAB-NR-ELEMENTS" );

TSCP  _2dmatlab_2delements_61808bcf( g12300 )
        TSCP  g12300;
{
        PUSHSTACKTRACE( t13403 );
        POPSTACKTRACE( sc_int_tscp( mxGetNumberOfElements( TSCP_POINTER( g12300 ) ) ) );
}

DEFTSCP( _2dmatlab_2dinternal_5070321b_v );
DEFCSTRING( t13405, "MATLAB-DIMENSIONS-INTERNAL" );

TSCP  _2dmatlab_2dinternal_5070321b( g12304 )
        TSCP  g12304;
{
        PUSHSTACKTRACE( t13405 );
        POPSTACKTRACE( POINTER_TSCP( mxGetDimensions( TSCP_POINTER( g12304 ) ) ) );
}

DEFTSCP( _2dmatlab_a_2dset_21_1add0af_v );
DEFCSTRING( t13407, "MATLAB-DATA-SET!" );

TSCP  _2dmatlab_a_2dset_21_1add0af( g12308, g12309 )
        TSCP  g12308, g12309;
{
        PUSHSTACKTRACE( t13407 );
        mxSetData( TSCP_POINTER( g12308 ), 
                   TSCP_POINTER( g12309 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( _2dmatlab_lab_2ddata_d35141c8_v );
DEFCSTRING( t13410, "MATLAB-DATA" );

TSCP  _2dmatlab_lab_2ddata_d35141c8( g12315 )
        TSCP  g12315;
{
        PUSHSTACKTRACE( t13410 );
        POPSTACKTRACE( POINTER_TSCP( mxGetData( TSCP_POINTER( g12315 ) ) ) );
}

DEFTSCP( _2dmatlab_ble_2ddata_aeaa1d6c_v );
DEFCSTRING( t13412, "MATLAB-REAL-DOUBLE-DATA" );

TSCP  _2dmatlab_ble_2ddata_aeaa1d6c( g12319 )
        TSCP  g12319;
{
        PUSHSTACKTRACE( t13412 );
        POPSTACKTRACE( POINTER_TSCP( mxGetPr( TSCP_POINTER( g12319 ) ) ) );
}

DEFTSCP( _2dmatlab_a_2dset_21_6ba995fa_v );
DEFCSTRING( t13414, "MATLAB-REAL-DOUBLE-DATA-SET!" );

TSCP  _2dmatlab_a_2dset_21_6ba995fa( g12323, g12324 )
        TSCP  g12323, g12324;
{
        PUSHSTACKTRACE( t13414 );
        mxSetPr( TSCP_POINTER( g12323 ), 
                 TSCP_POINTER( g12324 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( _2dmatlab_ble_2ddata_1f72cf98_v );
DEFCSTRING( t13417, "MATLAB-COMPLEX-DOUBLE-DATA" );

TSCP  _2dmatlab_ble_2ddata_1f72cf98( g12330 )
        TSCP  g12330;
{
        PUSHSTACKTRACE( t13417 );
        POPSTACKTRACE( POINTER_TSCP( mxGetPi( TSCP_POINTER( g12330 ) ) ) );
}

DEFTSCP( _2dmatlab_a_2dset_21_ad31fbff_v );
DEFCSTRING( t13419, "MATLAB-COMPLEX-DOUBLE-DATA-SET!" );

TSCP  _2dmatlab_a_2dset_21_ad31fbff( g12334, g12335 )
        TSCP  g12334, g12335;
{
        PUSHSTACKTRACE( t13419 );
        mxSetPi( TSCP_POINTER( g12334 ), 
                 TSCP_POINTER( g12335 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( _2dmatlab_ent_2dsize_4bce1ea6_v );
DEFCSTRING( t13422, "MATLAB-ELEMENT-SIZE" );

TSCP  _2dmatlab_ent_2dsize_4bce1ea6( g12341 )
        TSCP  g12341;
{
        PUSHSTACKTRACE( t13422 );
        POPSTACKTRACE( sc_int_tscp( mxGetElementSize( TSCP_POINTER( g12341 ) ) ) );
}

DEFTSCP( _2dmatlab_2dinternal_81bc4562_v );
DEFCSTRING( t13424, "MATLAB-CALCULATE-INDEX-INTERNAL" );

TSCP  _2dmatlab_2dinternal_81bc4562( g12345, g12346, g12347 )
        TSCP  g12345, g12346, g12347;
{
        PUSHSTACKTRACE( t13424 );
        POPSTACKTRACE( sc_int_tscp( mxCalcSingleSubscript( TSCP_POINTER( g12345 ), 
                                                           sc_tscp_int( g12346 ), 
                                                           TSCP_POINTER( g12347 ) ) ) );
}

DEFTSCP( _2dmatlab_dimensions_f36e048b_v );
DEFCSTRING( t13426, "MATLAB-DIMENSIONS" );
EXTERNTSCPP( dbindings__2d_3elist_28c4290c, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings__2d_3elist_28c4290c_v );

TSCP  _2dmatlab_dimensions_f36e048b( m12353 )
        TSCP  m12353;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t13426 );
        X1 = _2dmatlab_2dinternal_5070321b( m12353 );
        X2 = _2dmatlab_dimensions_4dd9b03( m12353 );
        POPSTACKTRACE( dbindings__2d_3elist_28c4290c( X1, 
                                                      _2dmatlab_dmwsize_2a_a6db3d23_v, 
                                                      X2, FALSEVALUE ) );
}

DEFTSCP( _2dmatlab_te_2dindex_3f628f60_v );
DEFCSTRING( t13428, "MATLAB-CALCULATE-INDEX" );
EXTERNTSCPP( scrt1_length, XAL1( TSCP ) );
EXTERNTSCP( scrt1_length_v );
EXTERNTSCPP( dbindings_ec_2darray_eed5ca2b, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_ec_2darray_eed5ca2b_v );

TSCP  _2dmatlab_te_2dindex_3f628f60( m12355, a12356, s12357 )
        TSCP  m12355, a12356, s12357;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t13428 );
        X1 = scrt1_length( s12357 );
        X2 = dbindings_ec_2darray_eed5ca2b( a12356, 
                                            s12357, 
                                            _2dmatlab_dmwsize_2a_a6db3d23_v, 
                                            FALSEVALUE );
        POPSTACKTRACE( _2dmatlab_2dinternal_81bc4562( m12355, 
                                                      X1, X2 ) );
}

DEFTSCP( _2dmatlab_dstring_3f_f97627ff_v );
DEFCSTRING( t13430, "MATLAB-STRING?" );
EXTERNTSCPP( scrt2__3d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3d_2dtwo_v );

TSCP  _2dmatlab_dstring_3f_f97627ff( m12359 )
        TSCP  m12359;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t13430 );
        X1 = _2dmatlab_class_2did_6f364104( m12359 );
        X2 = _2dmatlab__2dchar_2a_104c6366_v;
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13433;
        POPSTACKTRACE( BOOLEAN( EQ( _S2CUINT( X2 ), 
                                    _S2CUINT( X1 ) ) ) );
L13433:
        POPSTACKTRACE( scrt2__3d_2dtwo( X2, X1 ) );
}

DEFTSCP( _2dmatlab_2dexact_3f_3e0fa593_v );
DEFCSTRING( t13435, "MATLAB-MATRIX-EXACT?" );
EXTERNTSCPP( _2dmatlab_ric_2dtype_7a55d0, XAL1( TSCP ) );
EXTERNTSCP( _2dmatlab_ric_2dtype_7a55d0_v );

TSCP  _2dmatlab_2dexact_3f_3e0fa593( m12370 )
        TSCP  m12370;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t13435 );
        X2 = _2dmatlab_ric_2dtype_7a55d0( m12370 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L13438;
        scrt1__24__car_2derror( X2 );
L13438:
        X1 = PAIR_CAR( X2 );
        POPSTACKTRACE( BOOLEAN( EQ( _S2CUINT( X1 ), 
                                    _S2CUINT( c12378 ) ) ) );
}

DEFTSCP( _2dmatlab_inexact_3f_92ac7463_v );
DEFCSTRING( t13440, "MATLAB-MATRIX-INEXACT?" );

TSCP  _2dmatlab_inexact_3f_92ac7463( m12380 )
        TSCP  m12380;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t13440 );
        X2 = _2dmatlab_ric_2dtype_7a55d0( m12380 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L13443;
        scrt1__24__car_2derror( X2 );
L13443:
        X1 = PAIR_CAR( X2 );
        POPSTACKTRACE( BOOLEAN( EQ( _S2CUINT( X1 ), 
                                    _S2CUINT( c12388 ) ) ) );
}

DEFTSCP( _2dmatlab_dsigned_3f_81c77f5b_v );
DEFCSTRING( t13445, "MATLAB-MATRIX-SIGNED?" );
EXTERNTSCPP( scrt1__24__cdr_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__cdr_2derror_v );

TSCP  _2dmatlab_dsigned_3f_81c77f5b( m12390 )
        TSCP  m12390;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t13445 );
        X2 = _2dmatlab_ric_2dtype_7a55d0( m12390 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L13449;
        scrt1__24__cdr_2derror( X2 );
L13449:
        X3 = PAIR_CDR( X2 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L13452;
        scrt1__24__car_2derror( X3 );
L13452:
        X1 = PAIR_CAR( X3 );
        POPSTACKTRACE( BOOLEAN( EQ( _S2CUINT( X1 ), 
                                    _S2CUINT( c12404 ) ) ) );
}

DEFTSCP( _2dmatlab_nsigned_3f_983a789a_v );
DEFCSTRING( t13454, "MATLAB-MATRIX-UNSIGNED?" );

TSCP  _2dmatlab_nsigned_3f_983a789a( m12406 )
        TSCP  m12406;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t13454 );
        X2 = _2dmatlab_ric_2dtype_7a55d0( m12406 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L13458;
        scrt1__24__cdr_2derror( X2 );
L13458:
        X3 = PAIR_CDR( X2 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L13461;
        scrt1__24__car_2derror( X3 );
L13461:
        X1 = PAIR_CAR( X3 );
        POPSTACKTRACE( BOOLEAN( EQ( _S2CUINT( X1 ), 
                                    _S2CUINT( c12420 ) ) ) );
}

DEFTSCP( _2dmatlab_ric_2dtype_7a55d0_v );
DEFCSTRING( t13463, "MATLAB-MATRIX-NUMERIC-TYPE" );
EXTERNTSCPP( scrt1_cons_2a, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_cons_2a_v );

TSCP  _2dmatlab_ric_2dtype_7a55d0( m12422 )
        TSCP  m12422;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13463 );
        X1 = _2dmatlab_class_2did_6f364104( m12422 );
        X3 = _2dmatlab_ddouble_2a_50940a71_v;
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13467;
        X2 = BOOLEAN( EQ( _S2CUINT( X3 ), _S2CUINT( X1 ) ) );
        goto L13468;
L13467:
        X2 = scrt2__3d_2dtwo( X3, X1 );
L13468:
        if  ( TRUE( X2 ) )  goto L13473;
        X3 = _2dmatlab_dsingle_2a_6b4e75c9_v;
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13476;
        if  ( EQ( _S2CUINT( X3 ), _S2CUINT( X1 ) ) )  goto L13473;
        goto L13481;
L13476:
        if  ( TRUE( scrt2__3d_2dtwo( X3, X1 ) ) )  goto L13473;
L13481:
        X3 = _2dmatlab__2dint8_2a_3ecc7f9e_v;
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13485;
        X2 = BOOLEAN( EQ( _S2CUINT( X3 ), _S2CUINT( X1 ) ) );
        goto L13486;
L13485:
        X2 = scrt2__3d_2dtwo( X3, X1 );
L13486:
        if  ( TRUE( X2 ) )  goto L13491;
        X4 = _2dmatlab_2dint16_2a_b79bafee_v;
        if  ( BITAND( BITOR( _S2CINT( X4 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13493;
        X3 = BOOLEAN( EQ( _S2CUINT( X4 ), _S2CUINT( X1 ) ) );
        goto L13494;
L13493:
        X3 = scrt2__3d_2dtwo( X4, X1 );
L13494:
        if  ( TRUE( X3 ) )  goto L13491;
        X5 = _2dmatlab_2dint32_2a_42396bd9_v;
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13501;
        X4 = BOOLEAN( EQ( _S2CUINT( X5 ), _S2CUINT( X1 ) ) );
        goto L13502;
L13501:
        X4 = scrt2__3d_2dtwo( X5, X1 );
L13502:
        if  ( TRUE( X4 ) )  goto L13491;
        X5 = _2dmatlab_2dint64_2a_afb2bb75_v;
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13510;
        if  ( EQ( _S2CUINT( X5 ), _S2CUINT( X1 ) ) )  goto L13491;
        goto L13515;
L13510:
        if  ( TRUE( scrt2__3d_2dtwo( X5, X1 ) ) )  goto L13491;
L13515:
        X3 = _2dmatlab_2duint8_2a_8ba934f3_v;
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13519;
        X2 = BOOLEAN( EQ( _S2CUINT( X3 ), _S2CUINT( X1 ) ) );
        goto L13520;
L13519:
        X2 = scrt2__3d_2dtwo( X3, X1 );
L13520:
        if  ( TRUE( X2 ) )  goto L13525;
        X4 = _2dmatlab_duint16_2a_842dd740_v;
        if  ( BITAND( BITOR( _S2CINT( X4 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13527;
        X3 = BOOLEAN( EQ( _S2CUINT( X4 ), _S2CUINT( X1 ) ) );
        goto L13528;
L13527:
        X3 = scrt2__3d_2dtwo( X4, X1 );
L13528:
        if  ( TRUE( X3 ) )  goto L13525;
        X5 = _2dmatlab_duint32_2a_718f1377_v;
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13535;
        X4 = BOOLEAN( EQ( _S2CUINT( X5 ), _S2CUINT( X1 ) ) );
        goto L13536;
L13535:
        X4 = scrt2__3d_2dtwo( X5, X1 );
L13536:
        if  ( TRUE( X4 ) )  goto L13525;
        X5 = _2dmatlab_duint64_2a_9c04c3db_v;
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13544;
        if  ( EQ( _S2CUINT( X5 ), _S2CUINT( X1 ) ) )  goto L13525;
        POPSTACKTRACE( c12543 );
L13544:
        if  ( TRUE( scrt2__3d_2dtwo( X5, X1 ) ) )  goto L13525;
        POPSTACKTRACE( c12543 );
L13525:
        X2 = CONS( EMPTYLIST, EMPTYLIST );
        POPSTACKTRACE( scrt1_cons_2a( c12378, 
                                      CONS( c12420, X2 ) ) );
L13491:
        X2 = CONS( EMPTYLIST, EMPTYLIST );
        POPSTACKTRACE( scrt1_cons_2a( c12378, 
                                      CONS( c12404, X2 ) ) );
L13473:
        X2 = CONS( EMPTYLIST, EMPTYLIST );
        POPSTACKTRACE( scrt1_cons_2a( c12388, 
                                      CONS( c12404, X2 ) ) );
}

DEFTSCP( _2dmatlab_size_2dref_826ad607_v );
DEFCSTRING( t13551, "MATLAB-SIZE-REF" );
EXTERNTSCPP( scrt2__2a_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2a_2dtwo_v );
EXTERNTSCPP( dbindings_dptr_2dref_aed54e95, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_dptr_2dref_aed54e95_v );

TSCP  _2dmatlab_size_2dref_826ad607( s12545, x12546 )
        TSCP  s12545, x12546;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t13551 );
        X3 = _2dmatlab_dmwsize_2a_a6db3d23_v;
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( x12546 ) ), 
                      3 ) )  goto L13554;
        X2 = _TSCP( ITIMES( FIXED_C( X3 ), 
                            _S2CINT( x12546 ) ) );
        goto L13555;
L13554:
        X2 = scrt2__2a_2dtwo( X3, x12546 );
L13555:
        X1 = dbindings_dptr_2dref_aed54e95( _2dmatlab_dmwsize_2a_a6db3d23_v, 
                                            FALSEVALUE );
        X1 = UNKNOWNCALL( X1, 2 );
        POPSTACKTRACE( VIA( PROCEDURE_CODE( X1 ) )( s12545, 
                                                    X2, 
                                                    PROCEDURE_CLOSURE( X1 ) ) );
}

DEFTSCP( _2dmatlab__2d_3elist_60ca711a_v );
DEFCSTRING( t13556, "MATLAB-MATRIX->LIST" );
EXTERNTSCPP( scrt4_vector_2d_3elist, XAL1( TSCP ) );
EXTERNTSCP( scrt4_vector_2d_3elist_v );
EXTERNTSCPP( _2dmatlab_d_3ematrix_1fb82e34, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( _2dmatlab_d_3ematrix_1fb82e34_v );

TSCP  _2dmatlab__2d_3elist_60ca711a( m12554, s12555 )
        TSCP  m12554, s12555;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13556 );
        X1 = _2dmatlab_d_3ematrix_1fb82e34( m12554, s12555 );
        POPSTACKTRACE( scrt4_vector_2d_3elist( X1 ) );
}

DEFTSCP( _2dmatlab_d_3ematrix_1fb82e34_v );
DEFCSTRING( t13558, "MATLAB-MATRIX->MATRIX" );
EXTERNTSCPP( _2dmatlab_d_3evector_95c3b62, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( _2dmatlab_d_3evector_95c3b62_v );
EXTERNTSCPP( qobischeme_fuck_2dup, XAL0(  ) );
EXTERNTSCP( qobischeme_fuck_2dup_v );
EXTERNTSCPP( dbindings_d_3evector_85cd03bf, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_d_3evector_85cd03bf_v );

TSCP  toollib_2dmatlab_l12564( a12565, n12566, c13567 )
        TSCP  a12565, n12566, c13567;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12564 [inside MATLAB-MATRIX->MATR\
IX]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13567, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13567, 1 );
        X3 = dbindings_d_3evector_85cd03bf( a12565, 
                                            DISPLAY( 1 ), 
                                            n12566, DISPLAY( 0 ) );
        DISPLAY( 0 ) = X1;
        DISPLAY( 1 ) = X2;
        POPSTACKTRACE( X3 );
}

EXTERNTSCPP( dbindings_d_3evector_8778ce56, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_d_3evector_8778ce56_v );

TSCP  toollib_2dmatlab_l12561( a12562, n12563, c13571 )
        TSCP  a12562, n12563, c13571;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12561 [inside MATLAB-MATRIX->MATR\
IX]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13571, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13571, 1 );
        X3 = dbindings_d_3evector_8778ce56( a12562, 
                                            DISPLAY( 1 ), 
                                            n12563, DISPLAY( 0 ) );
        DISPLAY( 0 ) = X1;
        DISPLAY( 1 ) = X2;
        POPSTACKTRACE( X3 );
}

EXTERNTSCPP( scrt1_reverse, XAL1( TSCP ) );
EXTERNTSCP( scrt1_reverse_v );

TSCP  _2dmatlab_d_3ematrix_1fb82e34( m12557, s12558 )
        TSCP  m12557, s12558;
{
        TSCP  X5, X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13558 );
        DISPLAY( 0 ) = s12558;
        DISPLAY( 1 ) = _2dmatlab_ent_2dsize_4bce1ea6( m12557 );
        if  ( FALSE( _2dmatlab_2dexact_3f_3e0fa593( m12557 ) )
            )  goto L13561;
        X1 = _2dmatlab_ble_2ddata_aeaa1d6c( m12557 );
        goto L13564;
L13561:
        if  ( FALSE( _2dmatlab_inexact_3f_92ac7463( m12557 ) )
            )  goto L13563;
        X1 = _2dmatlab_ble_2ddata_aeaa1d6c( m12557 );
        goto L13564;
L13563:
        X1 = qobischeme_fuck_2dup(  );
L13564:
        if  ( FALSE( _2dmatlab_2dexact_3f_3e0fa593( m12557 ) )
            )  goto L13565;
        X2 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dmatlab_l12564, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        goto L13570;
L13565:
        if  ( FALSE( _2dmatlab_inexact_3f_92ac7463( m12557 ) )
            )  goto L13569;
        X2 = MAKEPROCEDURE( 2, 
                            0, 
                            toollib_2dmatlab_l12561, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        goto L13570;
L13569:
        X2 = qobischeme_fuck_2dup(  );
L13570:
        X3 = _2dmatlab_ent_2dsize_4bce1ea6( m12557 );
        X5 = _2dmatlab_dimensions_f36e048b( m12557 );
        X4 = scrt1_reverse( X5 );
        SDVAL = _2dmatlab_d_3evector_95c3b62( X1, X2, X3, X4 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( _2dmatlab_d_3evector_95c3b62_v );
DEFCSTRING( t13573, "MATLAB-DATA->VECTOR" );
EXTERNTSCPP( scrt2__3c_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3c_2dtwo_v );
EXTERNTSCPP( qobischeme_transpose, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_transpose_v );
EXTERNTSCPP( qobischeme_map_2dn_2dvector, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dn_2dvector_v );
EXTERNTSCPP( dbindings_e_2doffset_548e9bfc, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_e_2doffset_548e9bfc_v );
EXTERNTSCPP( scrt2__2a, XAL1( TSCP ) );
EXTERNTSCP( scrt2__2a_v );

TSCP  toollib_2dmatlab_l12588( n12589, c13598 )
        TSCP  n12589, c13598;
{
        TSCP  X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12588 [inside MATLAB-DATA->VECTOR\
]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13598, 0 );
        X2 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c13598, 1 );
        X3 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c13598, 2 );
        X4 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13598, 3 );
        X9 = DISPLAY( 2 );
        X12 = DISPLAY( 3 );
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L13601;
        scrt1__24__cdr_2derror( X12 );
L13601:
        X11 = PAIR_CDR( X12 );
        X10 = sc_apply_2dtwo( scrt2__2a_v, X11 );
        if  ( BITAND( BITOR( _S2CINT( X9 ), _S2CINT( X10 ) ), 
                      3 ) )  goto L13604;
        X8 = _TSCP( ITIMES( FIXED_C( X9 ), _S2CINT( X10 ) ) );
        goto L13605;
L13604:
        X8 = scrt2__2a_2dtwo( X9, X10 );
L13605:
        if  ( BITAND( BITOR( _S2CINT( n12589 ), 
                             _S2CINT( X8 ) ), 
                      3 ) )  goto L13607;
        X7 = _TSCP( ITIMES( FIXED_C( n12589 ), 
                            _S2CINT( X8 ) ) );
        goto L13608;
L13607:
        X7 = scrt2__2a_2dtwo( n12589, X8 );
L13608:
        X6 = dbindings_e_2doffset_548e9bfc( DISPLAY( 0 ), X7 );
        X8 = DISPLAY( 3 );
        if  ( EQ( TSCPTAG( X8 ), PAIRTAG ) )  goto L13610;
        scrt1__24__cdr_2derror( X8 );
L13610:
        X7 = PAIR_CDR( X8 );
        X5 = _2dmatlab_d_3evector_95c3b62( X6, 
                                           DISPLAY( 1 ), 
                                           DISPLAY( 2 ), X7 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 3 ) = X2;
        DISPLAY( 2 ) = X3;
        DISPLAY( 0 ) = X4;
        POPSTACKTRACE( X5 );
}

TSCP  _2dmatlab_d_3evector_95c3b62( d12568, 
                                    g12569, e12570, d12571 )
        TSCP  d12568, g12569, e12570, d12571;
{
        TSCP  X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SD3 = DISPLAY( 3 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13573 );
        DISPLAY( 0 ) = d12568;
        DISPLAY( 1 ) = g12569;
        DISPLAY( 2 ) = e12570;
        DISPLAY( 3 ) = d12571;
        X1 = scrt1_length( DISPLAY( 3 ) );
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 4 ) ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13577;
        if  ( EQ( _S2CUINT( _TSCP( 4 ) ), _S2CUINT( X1 ) ) )  goto L13581;
        goto L13582;
L13577:
        if  ( FALSE( scrt2__3d_2dtwo( _TSCP( 4 ), X1 ) ) )  goto L13582;
L13581:
        X3 = DISPLAY( 3 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L13586;
        scrt1__24__car_2derror( X3 );
L13586:
        X2 = PAIR_CAR( X3 );
        X1 = DISPLAY( 1 );
        X1 = UNKNOWNCALL( X1, 2 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( DISPLAY( 0 ), 
                                             X2, 
                                             PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        POPSTACKTRACE( SDVAL );
L13582:
        X1 = scrt1_length( DISPLAY( 3 ) );
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 4 ) ), 
                             _S2CINT( X1 ) ), 
                      3 ) )  goto L13590;
        if  ( LT( _S2CINT( _TSCP( 4 ) ), _S2CINT( X1 ) ) )  goto L13594;
        goto L13595;
L13590:
        if  ( TRUE( scrt2__3c_2dtwo( _TSCP( 4 ), X1 ) ) )  goto L13594;
L13595:
        SDVAL = qobischeme_fuck_2dup(  );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        POPSTACKTRACE( SDVAL );
L13594:
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l12588, 
                            MAKECLOSURE( EMPTYLIST, 
                                         4, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 0 ) ) );
        X4 = DISPLAY( 3 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L13613;
        scrt1__24__car_2derror( X4 );
L13613:
        X3 = PAIR_CAR( X4 );
        X1 = qobischeme_map_2dn_2dvector( X2, X3 );
        SDVAL = qobischeme_transpose( X1 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( _2dmatlab_t_2doutput_2b751271_v );
DEFCSTRING( t13615, "MATLAB-LIST-OUTPUT" );
EXTERNTSCPP( _2dmatlab_x_2doutput_2cbcc7bf, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( _2dmatlab_x_2doutput_2cbcc7bf_v );
EXTERNTSCPP( scrt4_list_2d_3evector, XAL1( TSCP ) );
EXTERNTSCP( scrt4_list_2d_3evector_v );
EXTERNTSCPP( sc_cons, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_cons_v );
EXTERNTSCPP( scdebug_error, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scdebug_error_v );

TSCP  _2dmatlab_t_2doutput_2b751271( t12619, f12620 )
        TSCP  t12619, f12620;
{
        TSCP  X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13615 );
        if  ( NEQ( _S2CUINT( f12620 ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L13617;
        X3 = t12619;
        X4 = EMPTYLIST;
        X5 = EMPTYLIST;
L13621:
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( EMPTYLIST ) ) )  goto L13622;
        X2 = X4;
        goto L13629;
L13622:
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L13625;
        scrt1__24__car_2derror( X3 );
L13625:
        X8 = PAIR_CAR( X3 );
        X7 = scrt4_list_2d_3evector( X8 );
        X6 = sc_cons( X7, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L13628;
        X7 = PAIR_CDR( X3 );
        X5 = X6;
        X4 = X6;
        X3 = X7;
        GOBACK( L13621 );
L13628:
        X7 = PAIR_CDR( X3 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L13633;
        scdebug_error( c12660, 
                       c12661, CONS( X5, EMPTYLIST ) );
L13633:
        X5 = SETGEN( PAIR_CDR( X5 ), X6 );
        X3 = X7;
        GOBACK( L13621 );
L13629:
        X1 = scrt4_list_2d_3evector( X2 );
        POPSTACKTRACE( _2dmatlab_x_2doutput_2cbcc7bf( X1, EMPTYLIST ) );
L13617:
        X3 = t12619;
        X4 = EMPTYLIST;
        X5 = EMPTYLIST;
L13637:
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( EMPTYLIST ) ) )  goto L13638;
        X2 = X4;
        goto L13645;
L13638:
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L13641;
        scrt1__24__car_2derror( X3 );
L13641:
        X8 = PAIR_CAR( X3 );
        X7 = scrt4_list_2d_3evector( X8 );
        X6 = sc_cons( X7, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L13644;
        X7 = PAIR_CDR( X3 );
        X5 = X6;
        X4 = X6;
        X3 = X7;
        GOBACK( L13637 );
L13644:
        X7 = PAIR_CDR( X3 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L13649;
        scdebug_error( c12660, 
                       c12661, CONS( X5, EMPTYLIST ) );
L13649:
        X5 = SETGEN( PAIR_CDR( X5 ), X6 );
        X3 = X7;
        GOBACK( L13637 );
L13645:
        X1 = scrt4_list_2d_3evector( X2 );
        if  ( EQ( TSCPTAG( f12620 ), PAIRTAG ) )  goto L13652;
        scrt1__24__car_2derror( f12620 );
L13652:
        POPSTACKTRACE( _2dmatlab_x_2doutput_2cbcc7bf( X1, 
                                                      CONS( PAIR_CAR( f12620 ), 
                                                            EMPTYLIST ) ) );
}

DEFTSCP( _2dmatlab_x_2doutput_2cbcc7bf_v );
DEFCSTRING( t13654, "MATLAB-MATRIX-OUTPUT" );
EXTERNTSCPP( obischeme_h_2dvector_fe309b1e, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( obischeme_h_2dvector_fe309b1e_v );
EXTERNTSCPP( toollib_2dmatlab_l12733, XAL1( TSCP ) );
EXTERNTSCPP( scrt6_format, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt6_format_v );

TSCP  toollib_2dmatlab_l12736( a12737, c13661 )
        TSCP  a12737, c13661;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12736 [inside MATLAB-MATRIX-OUTPU\
T]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c13661, 0 );
        if  ( NOT( AND( EQ( TSCPTAG( a12737 ), EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( a12737 ), 
                            VECTORTAG ) ) ) )  goto L13663;
        toollib_2dmatlab_l12733( a12737 );
        X2 = scrt6_format( DISPLAY( 2 ), 
                           CONS( c12742, EMPTYLIST ) );
        goto L13664;
L13663:
        X3 = CONS( a12737, EMPTYLIST );
        X2 = scrt6_format( DISPLAY( 2 ), 
                           CONS( c12740, X3 ) );
L13664:
        DISPLAY( 2 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  toollib_2dmatlab_l12733( a12735 )
        TSCP  a12735;
{
        TSCP  X1;

        PUSHSTACKTRACE( "LOOP [inside MATLAB-MATRIX-OUTPUT]" );
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l12736, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 2 ) ) );
        POPSTACKTRACE( obischeme_h_2dvector_fe309b1e( X1, 
                                                      a12735, 
                                                      EMPTYLIST ) );
}

TSCP  toollib_2dmatlab_l12728( p12729, c13656 )
        TSCP  p12729, c13656;
{
        TSCP  X3, X2, X1;
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12728 [inside MATLAB-MATRIX-OUTPU\
T]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13656, 0 );
        DISPLAY( 2 ) = p12729;
        X3 = DISPLAY( 0 );
        X2 = toollib_2dmatlab_l12733( X3 );
        DISPLAY( 0 ) = X1;
        SDVAL = X2;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

TSCP  toollib_2dmatlab_l12726( f12727, c13668 )
        TSCP  f12727, c13668;
{
        TSCP  X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12726 [inside MATLAB-MATRIX-OUTPU\
T]" );
        X1 = f12727;
        X1 = UNKNOWNCALL( X1, 1 );
        POPSTACKTRACE( VIA( PROCEDURE_CODE( X1 ) )( TRUEVALUE, 
                                                    PROCEDURE_CLOSURE( X1 ) ) );
}

EXTERNTSCPP( scrt5_put_2dfile_16bb0f3, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt5_put_2dfile_16bb0f3_v );
EXTERNTSCPP( qobischeme_first, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_first_v );

TSCP  toollib_2dmatlab_l12724( f12725, c13670 )
        TSCP  f12725, c13670;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12724 [inside MATLAB-MATRIX-OUTPU\
T]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13670, 0 );
        X3 = qobischeme_first( DISPLAY( 1 ) );
        X2 = scrt5_put_2dfile_16bb0f3( X3, f12725 );
        DISPLAY( 1 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  _2dmatlab_x_2doutput_2cbcc7bf( t12717, f12718 )
        TSCP  t12717, f12718;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13654 );
        DISPLAY( 0 ) = t12717;
        DISPLAY( 1 ) = f12718;
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l12728, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        if  ( NEQ( _S2CUINT( DISPLAY( 1 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L13666;
        X1 = MAKEPROCEDURE( 1, 
                            0, toollib_2dmatlab_l12726, EMPTYLIST );
        goto L13667;
L13666:
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l12724, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 1 ) ) );
L13667:
        X1 = UNKNOWNCALL( X1, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( X2, 
                                             PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( toollib_2dmatlab_matrix_3f_v );
DEFCSTRING( t13672, "MATRIX?" );

TSCP  toollib_2dmatlab_matrix_3f( v12744 )
        TSCP  v12744;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t13672 );
        if  ( NOT( AND( EQ( TSCPTAG( v12744 ), EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( v12744 ), 
                            VECTORTAG ) ) ) )  goto L13674;
        X2 = C_FIXED( VECTOR_LENGTH( v12744 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 0 ) ) ), 
                      3 ) )  goto L13678;
        X1 = BOOLEAN( EQ( _S2CUINT( X2 ), 
                          _S2CUINT( _TSCP( 0 ) ) ) );
        goto L13679;
L13678:
        X1 = scrt2__3d_2dtwo( X2, _TSCP( 0 ) );
L13679:
        if  ( TRUE( X1 ) )  goto L13681;
        if  ( EQ( TSCPTAG( _TSCP( 0 ) ), FIXNUMTAG ) )  goto L13684;
        scdebug_error( c12777, 
                       c12780, CONS( _TSCP( 0 ), EMPTYLIST ) );
L13684:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 0 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( v12744 ) ) ) )  goto L13686;
        scdebug_error( c12777, 
                       c12784, CONS( _TSCP( 0 ), EMPTYLIST ) );
L13686:
        X2 = VECTOR_ELEMENT( v12744, _TSCP( 0 ) );
        POPSTACKTRACE( BOOLEAN( AND( EQ( TSCPTAG( X2 ), 
                                         EXTENDEDTAG ), 
                                     EQ( TSCP_EXTENDEDTAG( X2 ), 
                                         VECTORTAG ) ) ) );
L13681:
        POPSTACKTRACE( X1 );
L13674:
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( toollib_2dmatlab_foldl_v );
DEFCSTRING( t13688, "FOLDL" );
EXTERNTSCPP( qobischeme_rest, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_rest_v );

TSCP  toollib_2dmatlab_foldl( f12786, l12787, i12788 )
        TSCP  f12786, l12787, i12788;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13688 );
        X1 = l12787;
        X2 = i12788;
L13691:
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( EMPTYLIST ) ) )  goto L13692;
        X3 = qobischeme_rest( X1 );
        X5 = qobischeme_first( X1 );
        X4 = f12786;
        X4 = UNKNOWNCALL( X4, 2 );
        X2 = VIA( PROCEDURE_CODE( X4 ) )( X2, 
                                          X5, 
                                          PROCEDURE_CLOSURE( X4 ) );
        X1 = X3;
        GOBACK( L13691 );
L13692:
        POPSTACKTRACE( X2 );
}

DEFTSCP( toollib_2dmatlab_pnm_3f_v );
DEFCSTRING( t13694, "PNM?" );
EXTERNTSCPP( qobischeme_pbm_3f, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_pbm_3f_v );
EXTERNTSCPP( qobischeme_pgm_3f, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_pgm_3f_v );
EXTERNTSCPP( qobischeme_ppm_3f, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_ppm_3f_v );

TSCP  toollib_2dmatlab_pnm_3f( m12803 )
        TSCP  m12803;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t13694 );
        X1 = qobischeme_pbm_3f( m12803 );
        if  ( TRUE( X1 ) )  goto L13697;
        X2 = qobischeme_pgm_3f( m12803 );
        if  ( TRUE( X2 ) )  goto L13700;
        POPSTACKTRACE( qobischeme_ppm_3f( m12803 ) );
L13700:
        POPSTACKTRACE( X2 );
L13697:
        POPSTACKTRACE( X1 );
}

DEFTSCP( _2dmatlab_b_2dstring_c60097f6_v );
DEFCSTRING( t13702, "SCHEME-VECTOR->MATLAB-STRING" );
EXTERNTSCPP( scrt2_number_2d_3estring, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_number_2d_3estring_v );

TSCP  toollib_2dmatlab_l12815( i12816, e12817, c13704 )
        TSCP  i12816, e12817, c13704;
{
        TSCP  X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12815 [inside SCHEME-VECTOR->MATL\
AB-STRING]" );
        X1 = CONS( scrt2_number_2d_3estring( e12817, EMPTYLIST ), 
                   EMPTYLIST );
        X1 = CONS( c12818, X1 );
        POPSTACKTRACE( scrt3_string_2dappend( CONS( i12816, X1 ) ) );
}

TSCP  _2dmatlab_b_2dstring_c60097f6( v12813 )
        TSCP  v12813;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13702 );
        X1 = CONS( c12833, EMPTYLIST );
        X2 = MAKEPROCEDURE( 2, 
                            0, toollib_2dmatlab_l12815, EMPTYLIST );
        X4 = scrt4_vector_2d_3elist( v12813 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L13707;
        scrt1__24__cdr_2derror( X4 );
L13707:
        X3 = PAIR_CDR( X4 );
        if  ( AND( EQ( TSCPTAG( v12813 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( v12813 ), VECTORTAG ) )
            )  goto L13710;
        scdebug_error( c12777, 
                       c12768, CONS( v12813, EMPTYLIST ) );
L13710:
        if  ( EQ( TSCPTAG( _TSCP( 0 ) ), FIXNUMTAG ) )  goto L13712;
        scdebug_error( c12777, 
                       c12780, CONS( _TSCP( 0 ), EMPTYLIST ) );
L13712:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 0 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( v12813 ) ) ) )  goto L13714;
        scdebug_error( c12777, 
                       c12784, CONS( _TSCP( 0 ), EMPTYLIST ) );
L13714:
        X5 = VECTOR_ELEMENT( v12813, _TSCP( 0 ) );
        X4 = scrt2_number_2d_3estring( X5, EMPTYLIST );
        X1 = CONS( toollib_2dmatlab_foldl( X2, X3, X4 ), 
                   X1 );
        POPSTACKTRACE( scrt3_string_2dappend( CONS( c12814, X1 ) ) );
}

DEFTSCP( _2dmatlab_ematlab_21_8d661f42_v );
DEFCSTRING( t13716, "SCHEME->MATLAB!" );
EXTERNTSCPP( obischeme_ary_2dfile_15e4569d, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( obischeme_ary_2dfile_15e4569d_v );
EXTERNTSCPP( qobischeme_write_2dpnm, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_write_2dpnm_v );

TSCP  toollib_2dmatlab_l12904( f12905, c13726 )
        TSCP  f12905, c13726;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12904 [inside SCHEME->MATLAB!]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13726, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13726, 1 );
        qobischeme_write_2dpnm( DISPLAY( 1 ), f12905 );
        X5 = CONS( f12905, EMPTYLIST );
        X5 = CONS( DISPLAY( 0 ), X5 );
        X4 = scrt6_format( FALSEVALUE, CONS( c12906, X5 ) );
        X3 = _2dmatlab_l_2dstring_42ef7035( X4 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        POPSTACKTRACE( X3 );
}

EXTERNTSCPP( qobischeme_matrix_2drows, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_matrix_2drows_v );
EXTERNTSCPP( qobischeme_matrix_2dcolumns, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_matrix_2dcolumns_v );
EXTERNTSCPP( qobischeme_map_2dvector, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dvector_v );

TSCP  toollib_2dmatlab_l12883( j12884, f12885, c13747 )
        TSCP  j12884, f12885, c13747;
{
        TSCP  X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12883 [inside SCHEME->MATLAB!]" );
        X1 = CONS( f12885, EMPTYLIST );
        X1 = CONS( c12886, X1 );
        POPSTACKTRACE( scrt3_string_2dappend( CONS( j12884, X1 ) ) );
}

TSCP  toollib_2dmatlab_l12876( f12877, c13786 )
        TSCP  f12877, c13786;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12876 [inside SCHEME->MATLAB!]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13786, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13786, 1 );
        _2dmatlab_x_2doutput_2cbcc7bf( DISPLAY( 1 ), 
                                       CONS( f12877, EMPTYLIST ) );
        X5 = CONS( f12877, EMPTYLIST );
        X5 = CONS( DISPLAY( 0 ), X5 );
        X4 = scrt6_format( FALSEVALUE, CONS( c12878, X5 ) );
        X3 = _2dmatlab_l_2dstring_42ef7035( X4 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        POPSTACKTRACE( X3 );
}

EXTERNTSCPP( scrt1_list_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt1_list_3f_v );

TSCP  _2dmatlab_ematlab_21_8d661f42( v12835, s12836 )
        TSCP  v12835, s12836;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13716 );
        DISPLAY( 0 ) = v12835;
        DISPLAY( 1 ) = s12836;
L13717:
        if  ( FALSE( toollib_2dmatlab_pnm_3f( DISPLAY( 1 ) ) )
            )  goto L13718;
        if  ( FALSE( qobischeme_pbm_3f( DISPLAY( 1 ) ) ) )  goto L13720;
        X1 = c12903;
        goto L13725;
L13720:
        if  ( FALSE( qobischeme_pgm_3f( DISPLAY( 1 ) ) ) )  goto L13722;
        X1 = c12902;
        goto L13725;
L13722:
        if  ( FALSE( qobischeme_ppm_3f( DISPLAY( 1 ) ) ) )  goto L13724;
        X1 = c12901;
        goto L13725;
L13724:
        X1 = FALSEVALUE;
L13725:
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l12904, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ) ) );
        SDVAL = obischeme_ary_2dfile_15e4569d( X1, X2 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
L13718:
        X1 = toollib_2dmatlab_matrix_3f( DISPLAY( 1 ) );
        if  ( FALSE( X1 ) )  goto L13745;
        X3 = qobischeme_matrix_2drows( DISPLAY( 1 ) );
        X4 = qobischeme_matrix_2dcolumns( DISPLAY( 1 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X4 ) ), 
                      3 ) )  goto L13733;
        X2 = _TSCP( ITIMES( FIXED_C( X3 ), _S2CINT( X4 ) ) );
        goto L13734;
L13733:
        X2 = scrt2__2a_2dtwo( X3, X4 );
L13734:
        X3 = _2dmatlab_dstring_2a_91664f11_v;
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L13737;
        if  ( LT( _S2CINT( X2 ), _S2CINT( X3 ) ) )  goto L13741;
        goto L13745;
L13737:
        if  ( FALSE( scrt2__3c_2dtwo( X2, X3 ) ) )  goto L13745;
L13741:
        X1 = qobischeme_map_2dvector( _2dmatlab_b_2dstring_c60097f6_v, 
                                      DISPLAY( 1 ), EMPTYLIST );
        X4 = CONS( c12833, EMPTYLIST );
        X5 = MAKEPROCEDURE( 2, 
                            0, toollib_2dmatlab_l12883, EMPTYLIST );
        X7 = scrt4_vector_2d_3elist( X1 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L13750;
        scrt1__24__cdr_2derror( X7 );
L13750:
        X6 = PAIR_CDR( X7 );
        if  ( AND( EQ( TSCPTAG( X1 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X1 ), VECTORTAG ) ) )  goto L13753;
        scdebug_error( c12777, 
                       c12768, CONS( X1, EMPTYLIST ) );
L13753:
        if  ( EQ( TSCPTAG( _TSCP( 0 ) ), FIXNUMTAG ) )  goto L13755;
        scdebug_error( c12777, 
                       c12780, CONS( _TSCP( 0 ), EMPTYLIST ) );
L13755:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 0 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( X1 ) ) ) )  goto L13757;
        scdebug_error( c12777, 
                       c12784, CONS( _TSCP( 0 ), EMPTYLIST ) );
L13757:
        X7 = VECTOR_ELEMENT( X1, _TSCP( 0 ) );
        X4 = CONS( toollib_2dmatlab_foldl( X5, X6, X7 ), 
                   X4 );
        X3 = CONS( scrt3_string_2dappend( CONS( c12814, X4 ) ), 
                   EMPTYLIST );
        X3 = CONS( DISPLAY( 0 ), X3 );
        X2 = scrt6_format( FALSEVALUE, CONS( c12882, X3 ) );
        SDVAL = _2dmatlab_l_2dstring_42ef7035( X2 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
L13745:
        X1 = BOOLEAN( AND( EQ( TSCPTAG( DISPLAY( 1 ) ), 
                               EXTENDEDTAG ), 
                           EQ( TSCP_EXTENDEDTAG( DISPLAY( 1 ) ), 
                               VECTORTAG ) ) );
        if  ( FALSE( X1 ) )  goto L13783;
        if  ( FALSE( toollib_2dmatlab_matrix_3f( DISPLAY( 1 ) ) )
            )  goto L13763;
        X2 = FALSEVALUE;
        goto L13764;
L13763:
        X2 = TRUEVALUE;
L13764:
        if  ( FALSE( X2 ) )  goto L13783;
        X4 = DISPLAY( 1 );
        if  ( AND( EQ( TSCPTAG( X4 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X4 ), VECTORTAG ) ) )  goto L13770;
        scdebug_error( c12767, 
                       c12768, CONS( X4, EMPTYLIST ) );
L13770:
        X3 = C_FIXED( VECTOR_LENGTH( X4 ) );
        X4 = _2dmatlab_dstring_2a_91664f11_v;
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X4 ) ), 
                      3 ) )  goto L13774;
        if  ( LT( _S2CINT( X3 ), _S2CINT( X4 ) ) )  goto L13778;
        goto L13783;
L13774:
        if  ( FALSE( scrt2__3c_2dtwo( X3, X4 ) ) )  goto L13783;
L13778:
        X2 = CONS( _2dmatlab_b_2dstring_c60097f6( DISPLAY( 1 ) ), 
                   EMPTYLIST );
        X2 = CONS( DISPLAY( 0 ), X2 );
        X1 = scrt6_format( FALSEVALUE, CONS( c12879, X2 ) );
        SDVAL = _2dmatlab_l_2dstring_42ef7035( X1 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
L13783:
        if  ( NOT( AND( EQ( TSCPTAG( DISPLAY( 1 ) ), 
                            EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( DISPLAY( 1 ) ), 
                            VECTORTAG ) ) ) )  goto L13784;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l12876, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ) ) );
        SDVAL = obischeme_ary_2dfile_15e4569d( c12875, X1 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
L13784:
        if  ( FALSE( scrt1_list_3f( DISPLAY( 1 ) ) ) )  goto L13788;
        DISPLAY( 1 ) = scrt4_list_2d_3evector( DISPLAY( 1 ) );
        GOBACK( L13717 );
L13788:
        SDVAL = qobischeme_fuck_2dup(  );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( _2dmatlab_d_3escheme_8ae18bc0_v );
DEFCSTRING( t13790, "MATLAB->SCHEME" );

TSCP  _2dmatlab_d_3escheme_8ae18bc0( m12908 )
        TSCP  m12908;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13790 );
        X1 = _2dmatlab_2dexact_3f_3e0fa593( m12908 );
        if  ( TRUE( X1 ) )  goto L13796;
        if  ( TRUE( _2dmatlab_inexact_3f_92ac7463( m12908 ) )
            )  goto L13796;
        if  ( FALSE( _2dmatlab_dstring_3f_f97627ff( m12908 ) )
            )  goto L13799;
        POPSTACKTRACE( _2dmatlab_d_3estring_73505745( m12908 ) );
L13799:
        POPSTACKTRACE( qobischeme_fuck_2dup(  ) );
L13796:
        X1 = _2dmatlab_dsigned_3f_81c77f5b( m12908 );
        POPSTACKTRACE( _2dmatlab_d_3ematrix_1fb82e34( m12908, X1 ) );
}

DEFTSCP( _2dmatlab_2dvariable_264c7491_v );
DEFCSTRING( t13801, "WITH-MATLAB-VARIABLE" );

TSCP  _2dmatlab_2dvariable_264c7491( v12914, f12915 )
        TSCP  v12914, f12915;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t13801 );
        X1 = _2dmatlab_2dvariable_9a356ebb( toollib_2dmatlab__2aengine_2a_v, 
                                            v12914 );
        X3 = f12915;
        X3 = UNKNOWNCALL( X3, 1 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( X1, 
                                          PROCEDURE_CLOSURE( X3 ) );
        _2dmatlab__2ddestroy_b80de368( X1 );
        POPSTACKTRACE( X2 );
}

DEFTSCP( _2dmatlab_2dvariable_a304468f_v );
DEFCSTRING( t13805, "MATLAB-GET-VARIABLE" );

TSCP  toollib_2dmatlab_l12922( v12923, c13807 )
        TSCP  v12923, c13807;
{
        PUSHSTACKTRACE( "toollib_2dmatlab_l12922 [inside MATLAB-GET-VARIABLE\
]" );
        POPSTACKTRACE( _2dmatlab_d_3escheme_8ae18bc0( v12923 ) );
}

TSCP  _2dmatlab_2dvariable_a304468f( n12921 )
        TSCP  n12921;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13805 );
        X1 = MAKEPROCEDURE( 1, 
                            0, toollib_2dmatlab_l12922, EMPTYLIST );
        POPSTACKTRACE( _2dmatlab_2dvariable_264c7491( n12921, X1 ) );
}

DEFTSCP( _2dmatlab_t_2ddouble_b038291c_v );
DEFCSTRING( t13809, "MATLAB-GET-DOUBLE" );
EXTERNTSCPP( qobischeme_x, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_x_v );

TSCP  toollib_2dmatlab_l12926( v12927, c13811 )
        TSCP  v12927, c13811;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12926 [inside MATLAB-GET-DOUBLE]" );
        X2 = _2dmatlab_d_3escheme_8ae18bc0( v12927 );
        X1 = qobischeme_x( X2 );
        POPSTACKTRACE( qobischeme_x( X1 ) );
}

TSCP  _2dmatlab_t_2ddouble_b038291c( n12925 )
        TSCP  n12925;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13809 );
        X1 = MAKEPROCEDURE( 1, 
                            0, toollib_2dmatlab_l12926, EMPTYLIST );
        POPSTACKTRACE( _2dmatlab_2dvariable_264c7491( n12925, X1 ) );
}

DEFTSCP( _2dmatlab_dvariables_881c6a8e_v );
DEFCSTRING( t13813, "MATLAB-SAVE-VARIABLES" );
EXTERNTSCPP( qobischeme_reduce, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_reduce_v );

TSCP  _2dmatlab_dvariables_881c6a8e( f12929, v12930 )
        TSCP  f12929, v12930;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13813 );
        X4 = v12930;
        X5 = EMPTYLIST;
        X6 = EMPTYLIST;
L13816:
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L13817;
        X3 = X5;
        goto L13824;
L13817:
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L13820;
        scrt1__24__car_2derror( X4 );
L13820:
        X9 = CONS( PAIR_CAR( X4 ), EMPTYLIST );
        X8 = scrt6_format( FALSEVALUE, CONS( c12976, X9 ) );
        X7 = sc_cons( X8, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L13823;
        X8 = PAIR_CDR( X4 );
        X6 = X7;
        X5 = X7;
        X4 = X8;
        GOBACK( L13816 );
L13823:
        X8 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L13828;
        scdebug_error( c12660, 
                       c12661, CONS( X6, EMPTYLIST ) );
L13828:
        X6 = SETGEN( PAIR_CDR( X6 ), X7 );
        X4 = X8;
        GOBACK( L13816 );
L13824:
        X2 = CONS( qobischeme_reduce( scrt3_string_2dappend_v, 
                                      X3, sc_emptystring ), 
                   EMPTYLIST );
        X2 = CONS( f12929, X2 );
        X1 = scrt6_format( FALSEVALUE, CONS( c12931, X2 ) );
        POPSTACKTRACE( _2dmatlab_l_2dstring_42ef7035( X1 ) );
}

DEFTSCP( _2dmatlab_dvariables_d34b6476_v );
DEFCSTRING( t13830, "MATLAB-LOAD-VARIABLES" );

TSCP  _2dmatlab_dvariables_d34b6476( f12978 )
        TSCP  f12978;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t13830 );
        X2 = CONS( f12978, EMPTYLIST );
        X1 = scrt6_format( FALSEVALUE, CONS( c12979, X2 ) );
        POPSTACKTRACE( _2dmatlab_l_2dstring_42ef7035( X1 ) );
}

DEFTSCP( _2dmatlab_2dvariable_69d748ba_v );
DEFCSTRING( t13832, "MATLAB-SHOW-VARIABLE" );

TSCP  toollib_2dmatlab_l12982( v12983, c13834 )
        TSCP  v12983, c13834;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12982 [inside MATLAB-SHOW-VARIABL\
E]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13834, 0 );
        X3 = CONS( _2dmatlab_d_3escheme_8ae18bc0( v12983 ), 
                   EMPTYLIST );
        X3 = CONS( DISPLAY( 0 ), X3 );
        X2 = scrt6_format( TRUEVALUE, CONS( c12984, X3 ) );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  _2dmatlab_2dvariable_69d748ba( n12981 )
        TSCP  n12981;
{
        TSCP  X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13832 );
        DISPLAY( 0 ) = n12981;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l12982, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        SDVAL = _2dmatlab_2dvariable_264c7491( DISPLAY( 0 ), X1 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( _2dmatlab_t_2dmatlab_24735d04_v );
DEFCSTRING( t13836, "TEST-MATLAB" );
EXTERNTSCPP( scrt6_display, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt6_display_v );
EXTERNTSCPP( scrt6_newline, XAL1( TSCP ) );
EXTERNTSCP( scrt6_newline_v );

TSCP  toollib_2dmatlab_l12987( m12988, c13840 )
        TSCP  m12988, c13840;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12987 [inside TEST-MATLAB]" );
        _2dmatlab_l_2dstring_42ef7035( c12989 );
        _2dmatlab_l_2dstring_42ef7035( c12990 );
        _2dmatlab_l_2dstring_42ef7035( c12991 );
        _2dmatlab_2dvariable_69d748ba( c12992 );
        _2dmatlab_2dvariable_69d748ba( c12993 );
        _2dmatlab_2dvariable_69d748ba( c12994 );
        _2dmatlab_l_2dstring_42ef7035( c12995 );
        X2 = m12988;
        X2 = UNKNOWNCALL( X2, 0 );
        X1 = VIA( PROCEDURE_CODE( X2 ) )( PROCEDURE_CLOSURE( X2 ) );
        scrt6_display( X1, EMPTYLIST );
        _2dmatlab_2dvariable_69d748ba( c12996 );
        _2dmatlab_l_2dstring_42ef7035( c12997 );
        X2 = m12988;
        X2 = UNKNOWNCALL( X2, 0 );
        X1 = VIA( PROCEDURE_CODE( X2 ) )( PROCEDURE_CLOSURE( X2 ) );
        scrt6_display( X1, EMPTYLIST );
        scrt6_newline( EMPTYLIST );
        scrt6_display( c12998, EMPTYLIST );
        POPSTACKTRACE( scrt6_newline( EMPTYLIST ) );
}

TSCP  toollib_2dmatlab_l12986( c13838 )
        TSCP  c13838;
{
        TSCP  X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l12986 [inside TEST-MATLAB]" );
        X1 = MAKEPROCEDURE( 1, 
                            0, toollib_2dmatlab_l12987, EMPTYLIST );
        POPSTACKTRACE( _2dmatlab_t_2dbuffer_7a8e4db7( X1 ) );
}

TSCP  _2dmatlab_t_2dmatlab_24735d04(  )
{
        TSCP  X1;

        PUSHSTACKTRACE( t13836 );
        X1 = MAKEPROCEDURE( 0, 
                            0, toollib_2dmatlab_l12986, EMPTYLIST );
        POPSTACKTRACE( _2dmatlab_t_2dengine_3085bf6d( X1 ) );
}

DEFTSCP( _2dmatlab_dto_2dpath_9b4baf8c_v );
DEFCSTRING( t13842, "MATLAB-APPEND-TO-PATH" );

TSCP  _2dmatlab_dto_2dpath_9b4baf8c( d13000 )
        TSCP  d13000;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13842 );
        X1 = scrt6_format( c13001, CONS( d13000, EMPTYLIST ) );
        POPSTACKTRACE( _2dmatlab_l_2dstring_42ef7035( X1 ) );
}

DEFTSCP( _2dmatlab__2dlooping_f095de31_v );
DEFCSTRING( t13844, "MAYBE-LOOPING" );
EXTERNTSCPP( qobischeme_map_2dn, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dn_v );
EXTERNTSCPP( scrt2__2d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2d_2dtwo_v );
EXTERNTSCPP( scrt2__2f_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2f_2dtwo_v );
EXTERNTSCPP( scrt2__2b_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2b_2dtwo_v );

TSCP  toollib_2dmatlab_l13028( n13029, c13869 )
        TSCP  n13029, c13869;
{
        TSCP  X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l13028 [inside MAYBE-LOOPING]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13869, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13869, 1 );
        X3 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c13869, 2 );
        X11 = DISPLAY( 0 );
        if  ( EQ( TSCPTAG( X11 ), PAIRTAG ) )  goto L13873;
        scrt1__24__cdr_2derror( X11 );
L13873:
        X12 = PAIR_CDR( X11 );
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L13876;
        scrt1__24__car_2derror( X12 );
L13876:
        X10 = PAIR_CAR( X12 );
        X12 = DISPLAY( 0 );
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L13879;
        scrt1__24__car_2derror( X12 );
L13879:
        X11 = PAIR_CAR( X12 );
        if  ( BITAND( BITOR( _S2CINT( X10 ), 
                             _S2CINT( X11 ) ), 
                      3 ) )  goto L13882;
        X9 = _TSCP( IDIFFERENCE( _S2CINT( X10 ), 
                                 _S2CINT( X11 ) ) );
        goto L13883;
L13882:
        X9 = scrt2__2d_2dtwo( X10, X11 );
L13883:
        X10 = DISPLAY( 1 );
        X11 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( X9 ), 
                                           _S2CINT( X10 ) ), 
                                    3 ) ) );
        if  ( FALSE( X11 ) )  goto L13895;
        if  ( EQ( _S2CUINT( X10 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13895;
        X12 = _TSCP( REMAINDER( _S2CINT( X9 ), 
                                _S2CINT( X10 ) ) );
        if  ( NEQ( _S2CUINT( X12 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13895;
        X8 = C_FIXED( QUOTIENT( _S2CINT( X9 ), 
                                _S2CINT( X10 ) ) );
        goto L13896;
L13895:
        X8 = scrt2__2f_2dtwo( X9, X10 );
L13896:
        if  ( BITAND( BITOR( _S2CINT( n13029 ), 
                             _S2CINT( X8 ) ), 
                      3 ) )  goto L13898;
        X7 = _TSCP( ITIMES( FIXED_C( n13029 ), 
                            _S2CINT( X8 ) ) );
        goto L13899;
L13898:
        X7 = scrt2__2a_2dtwo( n13029, X8 );
L13899:
        X9 = DISPLAY( 0 );
        if  ( EQ( TSCPTAG( X9 ), PAIRTAG ) )  goto L13901;
        scrt1__24__car_2derror( X9 );
L13901:
        X8 = PAIR_CAR( X9 );
        if  ( BITAND( BITOR( _S2CINT( X8 ), _S2CINT( X7 ) ), 
                      3 ) )  goto L13904;
        X6 = _TSCP( IPLUS( _S2CINT( X8 ), _S2CINT( X7 ) ) );
        goto L13905;
L13904:
        X6 = scrt2__2b_2dtwo( X8, X7 );
L13905:
        X5 = DISPLAY( 2 );
        X5 = UNKNOWNCALL( X5, 1 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( X6, 
                                          PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        DISPLAY( 2 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  toollib_2dmatlab_l13026( f13027, c13867 )
        TSCP  f13027, c13867;
{
        TSCP  X6, X5, X4, X3, X2, X1;
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "toollib_2dmatlab_l13026 [inside MAYBE-LOOPING]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13867, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13867, 1 );
        DISPLAY( 2 ) = f13027;
        X4 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l13028, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 2 ) ) );
        X6 = DISPLAY( 1 );
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13907;
        X5 = _TSCP( IPLUS( _S2CINT( X6 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L13908;
L13907:
        X5 = scrt2__2b_2dtwo( X6, _TSCP( 4 ) );
L13908:
        X3 = qobischeme_map_2dn( X4, X5 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        SDVAL = X3;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

TSCP  toollib_2dmatlab_l13092( f13093, c13909 )
        TSCP  f13093, c13909;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l13092 [inside MAYBE-LOOPING]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13909, 0 );
        X3 = f13093;
        X3 = UNKNOWNCALL( X3, 1 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( DISPLAY( 0 ), 
                                          PROCEDURE_CLOSURE( X3 ) );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  _2dmatlab__2dlooping_f095de31( v13003, s13004 )
        TSCP  v13003, s13004;
{
        TSCP  X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13844 );
        DISPLAY( 0 ) = v13003;
        DISPLAY( 1 ) = s13004;
        X1 = DISPLAY( 0 );
        X2 = BOOLEAN( EQ( TSCPTAG( X1 ), FIXNUMTAG ) );
        if  ( TRUE( X2 ) )  goto L13851;
        if  ( AND( EQ( TSCPTAG( X1 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X1 ), DOUBLEFLOATTAG ) )
            )  goto L13851;
        if  ( FALSE( scrt1_list_3f( DISPLAY( 0 ) ) ) )  goto L13854;
        X3 = scrt1_length( DISPLAY( 0 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L13859;
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( _TSCP( 8 ) ) ) )  goto L13863;
        goto L13866;
L13859:
        if  ( TRUE( scrt2__3d_2dtwo( X3, _TSCP( 8 ) ) ) )  goto L13866;
L13863:
        qobischeme_fuck_2dup(  );
L13866:
        SDVAL = MAKEPROCEDURE( 1, 
                               0, 
                               toollib_2dmatlab_l13026, 
                               MAKECLOSURE( EMPTYLIST, 
                                            2, 
                                            DISPLAY( 1 ), 
                                            DISPLAY( 0 ) ) );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
L13854:
        SDVAL = qobischeme_fuck_2dup(  );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
L13851:
        SDVAL = MAKEPROCEDURE( 1, 
                               0, 
                               toollib_2dmatlab_l13092, 
                               MAKECLOSURE( EMPTYLIST, 
                                            1, DISPLAY( 0 ) ) );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( _2dmatlab_2dfunction_b02fc6d3_v );
DEFCSTRING( t13911, "EVALUATE-FUNCTION" );

TSCP  toollib_2dmatlab_l13103( v13104, c13917 )
        TSCP  v13104, c13917;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l13103 [inside EVALUATE-FUNCTION]" );
        X1 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c13917, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13917, 1 );
        X5 = sc_cons( v13104, DISPLAY( 3 ) );
        X4 = DISPLAY( 1 );
        X4 = UNKNOWNCALL( X4, 1 );
        X3 = VIA( PROCEDURE_CODE( X4 ) )( X5, 
                                          PROCEDURE_CLOSURE( X4 ) );
        DISPLAY( 3 ) = X1;
        DISPLAY( 1 ) = X2;
        POPSTACKTRACE( X3 );
}

TSCP  toollib_2dmatlab_l13101( v13102, c13915 )
        TSCP  v13102, c13915;
{
        TSCP  X5, X4, X3, X2, X1;
        TSCP  SD3 = DISPLAY( 3 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "toollib_2dmatlab_l13101 [inside EVALUATE-FUNCTION]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13915, 0 );
        X2 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c13915, 1 );
        DISPLAY( 3 ) = v13102;
        X5 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l13103, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 1 ) ) );
        X4 = DISPLAY( 2 );
        X4 = UNKNOWNCALL( X4, 1 );
        X3 = VIA( PROCEDURE_CODE( X4 ) )( X5, 
                                          PROCEDURE_CLOSURE( X4 ) );
        DISPLAY( 1 ) = X1;
        DISPLAY( 2 ) = X2;
        SDVAL = X3;
        DISPLAY( 3 ) = SD3;
        POPSTACKTRACE( SDVAL );
}

TSCP  toollib_2dmatlab_l13098( a13099, b13100, c13913 )
        TSCP  a13099, b13100, c13913;
{
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "toollib_2dmatlab_l13098 [inside EVALUATE-FUNCTION]" );
        DISPLAY( 1 ) = a13099;
        DISPLAY( 2 ) = b13100;
        SDVAL = MAKEPROCEDURE( 1, 
                               0, 
                               toollib_2dmatlab_l13101, 
                               MAKECLOSURE( EMPTYLIST, 
                                            2, 
                                            DISPLAY( 1 ), 
                                            DISPLAY( 2 ) ) );
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

TSCP  toollib_2dmatlab_l13149( v13150, c13934 )
        TSCP  v13150, c13934;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "toollib_2dmatlab_l13149 [inside EVALUATE-FUNCTION]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13934, 0 );
        X2 = sc_apply_2dtwo( DISPLAY( 0 ), v13150 );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  _2dmatlab_2dfunction_b02fc6d3( f13095, v13096, s13097 )
        TSCP  f13095, v13096, s13097;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13911 );
        DISPLAY( 0 ) = f13095;
        X2 = MAKEPROCEDURE( 2, 
                            0, toollib_2dmatlab_l13098, EMPTYLIST );
        X4 = v13096;
        X5 = EMPTYLIST;
        X6 = EMPTYLIST;
L13920:
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L13921;
        X3 = X5;
        goto L13928;
L13921:
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L13924;
        scrt1__24__car_2derror( X4 );
L13924:
        X9 = PAIR_CAR( X4 );
        X8 = _2dmatlab__2dlooping_f095de31( X9, s13097 );
        X7 = sc_cons( X8, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L13927;
        X8 = PAIR_CDR( X4 );
        X6 = X7;
        X5 = X7;
        X4 = X8;
        GOBACK( L13920 );
L13927:
        X8 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L13932;
        scdebug_error( c12660, 
                       c12661, CONS( X6, EMPTYLIST ) );
L13932:
        X6 = SETGEN( PAIR_CDR( X6 ), X7 );
        X4 = X8;
        GOBACK( L13920 );
L13928:
        X4 = MAKEPROCEDURE( 1, 
                            0, 
                            toollib_2dmatlab_l13149, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X1 = toollib_2dmatlab_foldl( X2, X3, X4 );
        X1 = UNKNOWNCALL( X1, 1 );
        SDVAL = VIA( PROCEDURE_CODE( X1 ) )( EMPTYLIST, 
                                             PROCEDURE_CLOSURE( X1 ) );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

void scrt5__init();
void scrt6__init();
void scdebug__init();
void scrt4__init();
void scrt2__init();
void toollib_2dc_2dbindings__init();
void qobischeme__init();
void scrt3__init();
void scrt1__init();

static void  init_modules( compiler_version )
        char *compiler_version;
{
        scrt5__init();
        scrt6__init();
        scdebug__init();
        scrt4__init();
        scrt2__init();
        toollib_2dc_2dbindings__init();
        qobischeme__init();
        scrt3__init();
        scrt1__init();
        MAXDISPLAY( 4 );
}

void  toollib_2dmatlab__init()
{
        TSCP  X3, X2, X1;

        static int  init = 0;
        if  (init)  return;
        init = 1;
        INITHEAP( 0, 0, 0, 0 );
        init_constants();
        init_modules( "(toollib_2dmatlab SCHEME->C COMPILER 15mar93jfb)" );
        sc_segv__handlers();
        INITIALIZEVAR( t13296, 
                       ADR( _2dmatlab_ab_2d1_2d0_619fbe9b_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      _2dmatlab_ab_2d1_2d0_619fbe9b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13298, 
                       ADR( _2dmatlab_ab_2d3_2d0_1b5fedfb_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      _2dmatlab_ab_2d3_2d0_1b5fedfb, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13300, 
                       ADR( _2dmatlab_ab_2d5_2d0_941f185b_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      _2dmatlab_ab_2d5_2d0_941f185b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13302, 
                       ADR( _2dmatlab_ab_2d7_2d0_eedf4b3b_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      _2dmatlab_ab_2d7_2d0_eedf4b3b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13304, 
                       ADR( toollib_2dmatlab__2aengine_2a_v ), 
                       FALSEVALUE );
        INITIALIZEVAR( t13305, 
                       ADR( _2dmatlab_unknown_2a_69db4cfa_v ), 
                       sc_int_tscp( mxUNKNOWN_CLASS ) );
        INITIALIZEVAR( t13306, 
                       ADR( _2dmatlab__2dcell_2a_e48494a5_v ), 
                       sc_int_tscp( mxCELL_CLASS ) );
        INITIALIZEVAR( t13307, 
                       ADR( _2dmatlab_dstruct_2a_865a332_v ), 
                       sc_int_tscp( mxSTRUCT_CLASS ) );
        INITIALIZEVAR( t13308, 
                       ADR( _2dmatlab_logical_2a_578b388_v ), 
                       sc_int_tscp( mxLOGICAL_CLASS ) );
        INITIALIZEVAR( t13309, 
                       ADR( _2dmatlab__2dchar_2a_104c6366_v ), 
                       sc_int_tscp( mxCHAR_CLASS ) );
        INITIALIZEVAR( t13310, 
                       ADR( _2dmatlab_ddouble_2a_50940a71_v ), 
                       sc_int_tscp( mxDOUBLE_CLASS ) );
        INITIALIZEVAR( t13311, 
                       ADR( _2dmatlab_dsingle_2a_6b4e75c9_v ), 
                       sc_int_tscp( mxSINGLE_CLASS ) );
        INITIALIZEVAR( t13312, 
                       ADR( _2dmatlab__2dint8_2a_3ecc7f9e_v ), 
                       sc_int_tscp( mxINT8_CLASS ) );
        INITIALIZEVAR( t13313, 
                       ADR( _2dmatlab_2duint8_2a_8ba934f3_v ), 
                       sc_int_tscp( mxUINT8_CLASS ) );
        INITIALIZEVAR( t13314, 
                       ADR( _2dmatlab_2dint16_2a_b79bafee_v ), 
                       sc_int_tscp( mxINT16_CLASS ) );
        INITIALIZEVAR( t13315, 
                       ADR( _2dmatlab_duint16_2a_842dd740_v ), 
                       sc_int_tscp( mxUINT16_CLASS ) );
        INITIALIZEVAR( t13316, 
                       ADR( _2dmatlab_2dint32_2a_42396bd9_v ), 
                       sc_int_tscp( mxINT32_CLASS ) );
        INITIALIZEVAR( t13317, 
                       ADR( _2dmatlab_duint32_2a_718f1377_v ), 
                       sc_int_tscp( mxUINT32_CLASS ) );
        INITIALIZEVAR( t13318, 
                       ADR( _2dmatlab_2dint64_2a_afb2bb75_v ), 
                       sc_int_tscp( mxINT64_CLASS ) );
        INITIALIZEVAR( t13319, 
                       ADR( _2dmatlab_duint64_2a_9c04c3db_v ), 
                       sc_int_tscp( mxUINT64_CLASS ) );
        INITIALIZEVAR( t13320, 
                       ADR( _2dmatlab_unction_2a_a6175284_v ), 
                       sc_int_tscp( mxFUNCTION_CLASS ) );
        INITIALIZEVAR( t13321, 
                       ADR( _2dmatlab_dmwsize_2a_a6db3d23_v ), 
                       C_FIXED( sizeof( mwSize ) ) );
        INITIALIZEVAR( t13322, 
                       ADR( _2dmatlab_dstring_2a_91664f11_v ), 
                       _TSCP( 600 ) );
        INITIALIZEVAR( t13323, 
                       ADR( _2dmatlab_ab_2dstart_c0162d0_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_ab_2dstart_c0162d0, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13325, 
                       ADR( _2dmatlab_lab_2dstop_c7f4a41d_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_lab_2dstop_c7f4a41d, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13327, 
                       ADR( _2dmatlab_2dvariable_9a356ebb_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_2dvariable_9a356ebb, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13329, 
                       ADR( _2dmatlab_e_2dset_21_bf7b6c17_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      _2dmatlab_e_2dset_21_bf7b6c17, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13331, 
                       ADR( _2dmatlab_l_2dstring_886dffe8_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_l_2dstring_886dffe8, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13333, 
                       ADR( _2dmatlab_t_2dbuffer_abe73f78_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      _2dmatlab_t_2dbuffer_abe73f78, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13335, 
                       ADR( _2dmatlab__2dvisible_f8d2b7e5_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab__2dvisible_f8d2b7e5, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13337, 
                       ADR( _2dmatlab__2dvisible_8c6c7ba9_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab__2dvisible_8c6c7ba9, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13339, 
                       ADR( _2dmatlab_l_2dstring_42ef7035_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_l_2dstring_42ef7035, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13341, 
                       ADR( _2dmatlab__2dstrings_9ffd0bd5_v ), 
                       MAKEPROCEDURE( 0, 
                                      1, 
                                      _2dmatlab__2dstrings_9ffd0bd5, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13352, 
                       ADR( toollib_2dmatlab_matlab_v ), 
                       MAKEPROCEDURE( 0, 
                                      1, 
                                      toollib_2dmatlab_matlab, 
                                      EMPTYLIST ) );
        X2 = qobischeme_getenv( c12225 );
        if  ( FALSE( X2 ) )  goto L13358;
        X3 = X2;
        goto L13359;
L13358:
        X3 = sc_emptystring;
L13359:
        X1 = CONS( X3, EMPTYLIST );
        INITIALIZEVAR( t13356, 
                       ADR( _2dmatlab_command_2a_623f14aa_v ), 
                       scrt3_string_2dappend( CONS( c12222, X1 ) ) );
        INITIALIZEVAR( t13360, 
                       ADR( _2dmatlab__2dsize_2a_c1ed6d46_v ), 
                       _TSCP( 20000 ) );
        INITIALIZEVAR( t13361, 
                       ADR( _2dmatlab_t_2dengine_3085bf6d_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_t_2dengine_3085bf6d, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13363, 
                       ADR( _2dmatlab_b_2dengine_825e1e81_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_b_2dengine_825e1e81, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13366, 
                       ADR( _2dmatlab_t_2dbuffer_7a8e4db7_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_t_2dbuffer_7a8e4db7, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13368, 
                       ADR( _2dmatlab_t_2dbuffer_3ead3d9b_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_t_2dbuffer_3ead3d9b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13375, 
                       ADR( _2dmatlab_dmatlab_21_16b982d3_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      _2dmatlab_dmatlab_21_16b982d3, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13379, 
                       ADR( _2dmatlab_class_2did_6f364104_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_class_2did_6f364104, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13381, 
                       ADR( _2dmatlab_ass_2dname_1320a15b_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_ass_2dname_1320a15b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13383, 
                       ADR( _2dmatlab_d_3estring_73505745_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_d_3estring_73505745, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13385, 
                       ADR( _2dmatlab_b_2dcalloc_b4566400_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_b_2dcalloc_b4566400, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13387, 
                       ADR( _2dmatlab_b_2dmalloc_8e5c0570_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_b_2dmalloc_8e5c0570, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13389, 
                       ADR( _2dmatlab_lab_2dfree_338c7363_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_lab_2dfree_338c7363, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13392, 
                       ADR( _2dmatlab_c_2dmatrix_c3b5fb97_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      _2dmatlab_c_2dmatrix_c3b5fb97, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13394, 
                       ADR( _2dmatlab__2ddestroy_b80de368_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab__2ddestroy_b80de368, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13397, 
                       ADR( _2dmatlab_dnr_2drows_5a611f40_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_dnr_2drows_5a611f40, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13399, 
                       ADR( _2dmatlab__2dcolumns_6fa8223_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab__2dcolumns_6fa8223, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13401, 
                       ADR( _2dmatlab_dimensions_4dd9b03_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_dimensions_4dd9b03, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13403, 
                       ADR( _2dmatlab_2delements_61808bcf_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_2delements_61808bcf, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13405, 
                       ADR( _2dmatlab_2dinternal_5070321b_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_2dinternal_5070321b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13407, 
                       ADR( _2dmatlab_a_2dset_21_1add0af_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_a_2dset_21_1add0af, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13410, 
                       ADR( _2dmatlab_lab_2ddata_d35141c8_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_lab_2ddata_d35141c8, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13412, 
                       ADR( _2dmatlab_ble_2ddata_aeaa1d6c_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_ble_2ddata_aeaa1d6c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13414, 
                       ADR( _2dmatlab_a_2dset_21_6ba995fa_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_a_2dset_21_6ba995fa, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13417, 
                       ADR( _2dmatlab_ble_2ddata_1f72cf98_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_ble_2ddata_1f72cf98, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13419, 
                       ADR( _2dmatlab_a_2dset_21_ad31fbff_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_a_2dset_21_ad31fbff, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13422, 
                       ADR( _2dmatlab_ent_2dsize_4bce1ea6_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_ent_2dsize_4bce1ea6, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13424, 
                       ADR( _2dmatlab_2dinternal_81bc4562_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      _2dmatlab_2dinternal_81bc4562, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13426, 
                       ADR( _2dmatlab_dimensions_f36e048b_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_dimensions_f36e048b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13428, 
                       ADR( _2dmatlab_te_2dindex_3f628f60_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      _2dmatlab_te_2dindex_3f628f60, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13430, 
                       ADR( _2dmatlab_dstring_3f_f97627ff_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_dstring_3f_f97627ff, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13435, 
                       ADR( _2dmatlab_2dexact_3f_3e0fa593_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_2dexact_3f_3e0fa593, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13440, 
                       ADR( _2dmatlab_inexact_3f_92ac7463_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_inexact_3f_92ac7463, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13445, 
                       ADR( _2dmatlab_dsigned_3f_81c77f5b_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_dsigned_3f_81c77f5b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13454, 
                       ADR( _2dmatlab_nsigned_3f_983a789a_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_nsigned_3f_983a789a, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13463, 
                       ADR( _2dmatlab_ric_2dtype_7a55d0_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_ric_2dtype_7a55d0, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13551, 
                       ADR( _2dmatlab_size_2dref_826ad607_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_size_2dref_826ad607, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13556, 
                       ADR( _2dmatlab__2d_3elist_60ca711a_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab__2d_3elist_60ca711a, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13558, 
                       ADR( _2dmatlab_d_3ematrix_1fb82e34_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_d_3ematrix_1fb82e34, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13573, 
                       ADR( _2dmatlab_d_3evector_95c3b62_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      _2dmatlab_d_3evector_95c3b62, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13615, 
                       ADR( _2dmatlab_t_2doutput_2b751271_v ), 
                       MAKEPROCEDURE( 1, 
                                      1, 
                                      _2dmatlab_t_2doutput_2b751271, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13654, 
                       ADR( _2dmatlab_x_2doutput_2cbcc7bf_v ), 
                       MAKEPROCEDURE( 1, 
                                      1, 
                                      _2dmatlab_x_2doutput_2cbcc7bf, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13672, 
                       ADR( toollib_2dmatlab_matrix_3f_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dmatlab_matrix_3f, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13688, 
                       ADR( toollib_2dmatlab_foldl_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      toollib_2dmatlab_foldl, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13694, 
                       ADR( toollib_2dmatlab_pnm_3f_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      toollib_2dmatlab_pnm_3f, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13702, 
                       ADR( _2dmatlab_b_2dstring_c60097f6_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_b_2dstring_c60097f6, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13716, 
                       ADR( _2dmatlab_ematlab_21_8d661f42_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_ematlab_21_8d661f42, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13790, 
                       ADR( _2dmatlab_d_3escheme_8ae18bc0_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_d_3escheme_8ae18bc0, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13801, 
                       ADR( _2dmatlab_2dvariable_264c7491_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab_2dvariable_264c7491, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13805, 
                       ADR( _2dmatlab_2dvariable_a304468f_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_2dvariable_a304468f, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13809, 
                       ADR( _2dmatlab_t_2ddouble_b038291c_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_t_2ddouble_b038291c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13813, 
                       ADR( _2dmatlab_dvariables_881c6a8e_v ), 
                       MAKEPROCEDURE( 1, 
                                      1, 
                                      _2dmatlab_dvariables_881c6a8e, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13830, 
                       ADR( _2dmatlab_dvariables_d34b6476_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_dvariables_d34b6476, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13832, 
                       ADR( _2dmatlab_2dvariable_69d748ba_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_2dvariable_69d748ba, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13836, 
                       ADR( _2dmatlab_t_2dmatlab_24735d04_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      _2dmatlab_t_2dmatlab_24735d04, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13842, 
                       ADR( _2dmatlab_dto_2dpath_9b4baf8c_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      _2dmatlab_dto_2dpath_9b4baf8c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13844, 
                       ADR( _2dmatlab__2dlooping_f095de31_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      _2dmatlab__2dlooping_f095de31, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13911, 
                       ADR( _2dmatlab_2dfunction_b02fc6d3_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      _2dmatlab_2dfunction_b02fc6d3, 
                                      EMPTYLIST ) );
        return;
}
