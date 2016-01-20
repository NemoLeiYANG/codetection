
/* SCHEME->C */

#include <objects.h>

void codetectionlib_2dsc__init();
DEFCSTRING( t13688, "DejaVuSans/~a" );
DEFSTATICTSCP( c13534 );
DEFCSTRING( t13689, "Can't find a font directory" );
DEFSTATICTSCP( c13504 );
DEFCSTRING( t13690, "/usr/share/fonts/TTF" );
DEFSTATICTSCP( c13503 );
DEFCSTRING( t13691, "/usr/share/fonts/dejavu" );
DEFSTATICTSCP( c13502 );
DEFCSTRING( t13692, "/usr/share/fonts/truetype/ttf-dejavu" );
DEFSTATICTSCP( c13501 );
DEFCSTRING( t13693, "Index is not in bounds: ~s" );
DEFSTATICTSCP( c13243 );
DEFCSTRING( t13694, "Argument is not an INTEGER: ~s" );
DEFSTATICTSCP( c13239 );
DEFSTATICTSCP( c13236 );
DEFCSTRING( t13695, "yy" );
DEFSTATICTSCP( c13135 );
DEFCSTRING( t13696, 
            "pp=spline(t,points'); yy=ppval(linspace(0,max(t),~a),pp);" );
DEFSTATICTSCP( c13127 );
DEFCSTRING( t13697, "Argument is not a VECTOR: ~s" );
DEFSTATICTSCP( c13126 );
DEFSTATICTSCP( c13125 );
DEFCSTRING( t13698, "t" );
DEFSTATICTSCP( c13120 );
DEFCSTRING( t13699, "points" );
DEFSTATICTSCP( c13119 );
DEFSTATICTSCP( c13101 );
DEFCSTRING( t13700, " " );
DEFSTATICTSCP( c12439 );
DEFCSTRING( t13701, "-" );
DEFSTATICTSCP( c12437 );
DEFCSTRING( t13702, "date > ~a" );
DEFSTATICTSCP( c12434 );
DEFCSTRING( t13703, "/tmp/host-" );
DEFSTATICTSCP( c12430 );
DEFCSTRING( t13704, "hostname > ~a" );
DEFSTATICTSCP( c12427 );
DEFCSTRING( t13705, "/tmp/time-" );
DEFSTATICTSCP( c12423 );
DEFCSTRING( t13706, "." );
DEFSTATICTSCP( c12380 );
DEFCSTRING( t13707, "date +'%s %N' > ~a" );
DEFSTATICTSCP( c12377 );
DEFCSTRING( t13708, "Argument not a PAIR: ~s" );
DEFSTATICTSCP( c12168 );
DEFSTATICTSCP( c12167 );

static void  init_constants()
{
        c13534 = CSTRING_TSCP( t13688 );
        CONSTANTEXP( ADR( c13534 ) );
        c13504 = CSTRING_TSCP( t13689 );
        CONSTANTEXP( ADR( c13504 ) );
        c13503 = CSTRING_TSCP( t13690 );
        CONSTANTEXP( ADR( c13503 ) );
        c13502 = CSTRING_TSCP( t13691 );
        CONSTANTEXP( ADR( c13502 ) );
        c13501 = CSTRING_TSCP( t13692 );
        CONSTANTEXP( ADR( c13501 ) );
        c13243 = CSTRING_TSCP( t13693 );
        CONSTANTEXP( ADR( c13243 ) );
        c13239 = CSTRING_TSCP( t13694 );
        CONSTANTEXP( ADR( c13239 ) );
        c13236 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR-REF" ) );
        CONSTANTEXP( ADR( c13236 ) );
        c13135 = CSTRING_TSCP( t13695 );
        CONSTANTEXP( ADR( c13135 ) );
        c13127 = CSTRING_TSCP( t13696 );
        CONSTANTEXP( ADR( c13127 ) );
        c13126 = CSTRING_TSCP( t13697 );
        CONSTANTEXP( ADR( c13126 ) );
        c13125 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR-LENGTH" ) );
        CONSTANTEXP( ADR( c13125 ) );
        c13120 = CSTRING_TSCP( t13698 );
        CONSTANTEXP( ADR( c13120 ) );
        c13119 = CSTRING_TSCP( t13699 );
        CONSTANTEXP( ADR( c13119 ) );
        c13101 = DOUBLE_TSCP( 0. );
        CONSTANTEXP( ADR( c13101 ) );
        c12439 = CSTRING_TSCP( t13700 );
        CONSTANTEXP( ADR( c12439 ) );
        c12437 = CSTRING_TSCP( t13701 );
        CONSTANTEXP( ADR( c12437 ) );
        c12434 = CSTRING_TSCP( t13702 );
        CONSTANTEXP( ADR( c12434 ) );
        c12430 = CSTRING_TSCP( t13703 );
        CONSTANTEXP( ADR( c12430 ) );
        c12427 = CSTRING_TSCP( t13704 );
        CONSTANTEXP( ADR( c12427 ) );
        c12423 = CSTRING_TSCP( t13705 );
        CONSTANTEXP( ADR( c12423 ) );
        c12380 = CSTRING_TSCP( t13706 );
        CONSTANTEXP( ADR( c12380 ) );
        c12377 = CSTRING_TSCP( t13707 );
        CONSTANTEXP( ADR( c12377 ) );
        c12168 = CSTRING_TSCP( t13708 );
        CONSTANTEXP( ADR( c12168 ) );
        c12167 = STRINGTOSYMBOL( CSTRING_TSCP( "SET-CDR!" ) );
        CONSTANTEXP( ADR( c12167 ) );
}

DEFTSCP( nlib_2dsc_sc_2d1_2d0_eb7e557_v );
DEFCSTRING( t13709, "gensym-codetectionlib_2dsc-1-0" );

TSCP  nlib_2dsc_sc_2d1_2d0_eb7e557(  )
{
        PUSHSTACKTRACE( t13709 );
        POPSTACKTRACE( 0 );}
  #include<stddef.h>
int gensym_codetectionlib_2dsc_2_0(){ return 1;gensym_codetectionlib_2dsc_2_0( );
}

DEFTSCP( nlib_2dsc_sc_2d3_2d0_7477b637_v );
DEFCSTRING( t13711, "gensym-codetectionlib_2dsc-3-0" );

TSCP  nlib_2dsc_sc_2d3_2d0_7477b637(  )
{
        PUSHSTACKTRACE( t13711 );
        POPSTACKTRACE( 0 );}
  #include<stdlib.h>
int gensym_codetectionlib_2dsc_4_0(){ return 1;gensym_codetectionlib_2dsc_4_0( );
}

DEFTSCP( nlib_2dsc_sc_2d5_2d0_fb374397_v );
DEFCSTRING( t13713, "gensym-codetectionlib_2dsc-5-0" );

TSCP  nlib_2dsc_sc_2d5_2d0_fb374397(  )
{
        PUSHSTACKTRACE( t13713 );
        POPSTACKTRACE( 0 );}
  #include<string.h>
int gensym_codetectionlib_2dsc_6_0(){ return 1;gensym_codetectionlib_2dsc_6_0( );
}

DEFTSCP( nlib_2dsc_sc_2d7_2d0_81f710f7_v );
DEFCSTRING( t13715, "gensym-codetectionlib_2dsc-7-0" );

TSCP  nlib_2dsc_sc_2d7_2d0_81f710f7(  )
{
        PUSHSTACKTRACE( t13715 );
        POPSTACKTRACE( 0 );}
  #include<codetectionlib-c.h>
int gensym_codetectionlib_2dsc_8_0(){ return 1;gensym_codetectionlib_2dsc_8_0( );
}

DEFTSCP( codetectionlib_2dsc_o_v );
DEFCSTRING( t13717, "O" );
EXTERNTSCPP( sc_cons, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_cons_v );
EXTERNTSCPP( toollib_2dmatlab_foldl, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( toollib_2dmatlab_foldl_v );

TSCP  codetectionlib_2dsc_l12126( x12127, f12128, c13722 )
        TSCP  x12127, f12128, c13722;
{
        TSCP  X1;

        PUSHSTACKTRACE( "codetectionlib_2dsc_l12126 [inside O]" );
        X1 = f12128;
        X1 = UNKNOWNCALL( X1, 1 );
        POPSTACKTRACE( VIA( PROCEDURE_CODE( X1 ) )( x12127, 
                                                    PROCEDURE_CLOSURE( X1 ) ) );
}

EXTERNTSCPP( qobischeme_rest, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_rest_v );
EXTERNTSCPP( scrt1_reverse, XAL1( TSCP ) );
EXTERNTSCP( scrt1_reverse_v );
EXTERNTSCPP( sc_apply_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_apply_2dtwo_v );
EXTERNTSCPP( qobischeme_last, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_last_v );

TSCP  codetectionlib_2dsc_l12124( d12125, c13720 )
        TSCP  d12125, c13720;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "codetectionlib_2dsc_l12124 [inside O]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13720, 0 );
        X3 = MAKEPROCEDURE( 2, 
                            0, 
                            codetectionlib_2dsc_l12126, EMPTYLIST );
        X5 = scrt1_reverse( DISPLAY( 0 ) );
        X4 = qobischeme_rest( X5 );
        X6 = qobischeme_last( DISPLAY( 0 ) );
        X5 = sc_apply_2dtwo( X6, d12125 );
        X2 = toollib_2dmatlab_foldl( X3, X4, X5 );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  codetectionlib_2dsc_o( a12119, b12120, c12121 )
        TSCP  a12119, b12120, c12121;
{
        TSCP  X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13717 );
        X1 = sc_cons( b12120, c12121 );
        DISPLAY( 0 ) = sc_cons( a12119, X1 );
        SDVAL = MAKEPROCEDURE( 0, 
                               1, 
                               codetectionlib_2dsc_l12124, 
                               MAKECLOSURE( EMPTYLIST, 
                                            1, DISPLAY( 0 ) ) );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( codetectionlib_2dsc_zip_v );
DEFCSTRING( t13724, "ZIP" );
EXTERNTSCPP( scrt1__24__car_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__car_2derror_v );
EXTERNTSCPP( scdebug_error, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scdebug_error_v );

TSCP  codetectionlib_2dsc_l12178( a12179, b12180, c13726 )
        TSCP  a12179, b12180, c13726;
{
        TSCP  X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "codetectionlib_2dsc_l12178 [inside ZIP]" );
        X1 = b12180;
        X2 = a12179;
        X3 = EMPTYLIST;
        X4 = EMPTYLIST;
L13730:
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( EMPTYLIST ) ) )  goto L13731;
        if  ( EQ( TSCPTAG( X1 ), PAIRTAG ) )  goto L13734;
        scrt1__24__car_2derror( X1 );
L13734:
        X7 = PAIR_CAR( X1 );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L13737;
        scrt1__24__car_2derror( X2 );
L13737:
        X8 = PAIR_CAR( X2 );
        X6 = sc_cons( X7, X8 );
        X5 = sc_cons( X6, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( EMPTYLIST ) ) )  goto L13740;
        X6 = PAIR_CDR( X1 );
        X7 = PAIR_CDR( X2 );
        X4 = X5;
        X3 = X5;
        X2 = X7;
        X1 = X6;
        GOBACK( L13730 );
L13740:
        X6 = PAIR_CDR( X1 );
        X7 = PAIR_CDR( X2 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L13747;
        scdebug_error( c12167, 
                       c12168, CONS( X4, EMPTYLIST ) );
L13747:
        X4 = SETGEN( PAIR_CDR( X4 ), X5 );
        X2 = X7;
        X1 = X6;
        GOBACK( L13730 );
L13731:
        POPSTACKTRACE( X3 );
}

EXTERNTSCPP( scrt1_list, XAL1( TSCP ) );
EXTERNTSCP( scrt1_list_v );

TSCP  codetectionlib_2dsc_zip( a12130, b12131, c12132 )
        TSCP  a12130, b12131, c12132;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13724 );
        X2 = MAKEPROCEDURE( 2, 
                            0, 
                            codetectionlib_2dsc_l12178, EMPTYLIST );
        X3 = sc_cons( b12131, c12132 );
        X5 = a12130;
        X6 = EMPTYLIST;
        X7 = EMPTYLIST;
L13751:
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L13752;
        X4 = X6;
        goto L13759;
L13752:
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L13755;
        scrt1__24__car_2derror( X5 );
L13755:
        X9 = scrt1_list( CONS( PAIR_CAR( X5 ), EMPTYLIST ) );
        X8 = sc_cons( X9, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X6 ), _S2CUINT( EMPTYLIST ) ) )  goto L13758;
        X9 = PAIR_CDR( X5 );
        X7 = X8;
        X6 = X8;
        X5 = X9;
        GOBACK( L13751 );
L13758:
        X9 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L13763;
        scdebug_error( c12167, 
                       c12168, CONS( X7, EMPTYLIST ) );
L13763:
        X7 = SETGEN( PAIR_CDR( X7 ), X8 );
        X5 = X9;
        GOBACK( L13751 );
L13759:
        X1 = toollib_2dmatlab_foldl( X2, X3, X4 );
        X2 = X1;
        X3 = EMPTYLIST;
        X4 = EMPTYLIST;
L13767:
        if  ( EQ( _S2CUINT( X2 ), _S2CUINT( EMPTYLIST ) ) )  goto L13768;
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L13771;
        scrt1__24__car_2derror( X2 );
L13771:
        X7 = PAIR_CAR( X2 );
        X6 = scrt1_reverse( X7 );
        X5 = sc_cons( X6, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( EMPTYLIST ) ) )  goto L13774;
        X6 = PAIR_CDR( X2 );
        X4 = X5;
        X3 = X5;
        X2 = X6;
        GOBACK( L13767 );
L13774:
        X6 = PAIR_CDR( X2 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L13779;
        scdebug_error( c12167, 
                       c12168, CONS( X4, EMPTYLIST ) );
L13779:
        X4 = SETGEN( PAIR_CDR( X4 ), X5 );
        X2 = X6;
        GOBACK( L13767 );
L13768:
        POPSTACKTRACE( X3 );
}

DEFTSCP( nlib_2dsc_dpositions_88b95f2f_v );
DEFCSTRING( t13781, "ALL-POSITIONS" );
EXTERNTSCPP( qobischeme_removeq, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_removeq_v );
EXTERNTSCPP( qobischeme_map_2dindexed, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dindexed_v );
EXTERNTSCPP( scrt1_equal_3f, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_equal_3f_v );

TSCP  codetectionlib_2dsc_l12283( e12284, i12285, c13783 )
        TSCP  e12284, i12285, c13783;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "codetectionlib_2dsc_l12283 [inside ALL-POSITIONS]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13783, 0 );
        if  ( FALSE( scrt1_equal_3f( e12284, DISPLAY( 0 ) ) )
            )  goto L13785;
        X2 = i12285;
        goto L13786;
L13785:
        X2 = FALSEVALUE;
L13786:
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  nlib_2dsc_dpositions_88b95f2f( x12281, l12282 )
        TSCP  x12281, l12282;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13781 );
        DISPLAY( 0 ) = x12281;
        X2 = MAKEPROCEDURE( 2, 
                            0, 
                            codetectionlib_2dsc_l12283, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X1 = qobischeme_map_2dindexed( X2, l12282 );
        SDVAL = qobischeme_removeq( FALSEVALUE, X1 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( nlib_2dsc_ll_2dpairs_15170d9a_v );
DEFCSTRING( t13787, "ALL-PAIRS" );
EXTERNTSCPP( scrt1_append_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_append_2dtwo_v );
EXTERNTSCPP( nlib_2dsc_ll_2dpairs_15170d9a, XAL1( TSCP ) );
EXTERNTSCP( nlib_2dsc_ll_2dpairs_15170d9a_v );
EXTERNTSCPP( scrt1__24__cdr_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__cdr_2derror_v );

TSCP  nlib_2dsc_ll_2dpairs_15170d9a( l12287 )
        TSCP  l12287;
{
        TSCP  X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13787 );
        if  ( EQ( _S2CUINT( l12287 ), 
                  _S2CUINT( EMPTYLIST ) ) )  goto L13789;
        if  ( EQ( TSCPTAG( l12287 ), PAIRTAG ) )  goto L13792;
        scrt1__24__cdr_2derror( l12287 );
L13792:
        X2 = PAIR_CDR( l12287 );
        X1 = nlib_2dsc_ll_2dpairs_15170d9a( X2 );
        X3 = PAIR_CDR( l12287 );
        X4 = X3;
        X5 = EMPTYLIST;
        X6 = EMPTYLIST;
L13797:
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L13798;
        X2 = X5;
        goto L13808;
L13798:
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L13801;
        scrt1__24__car_2derror( X4 );
L13801:
        X9 = PAIR_CAR( X4 );
        X11 = PAIR_CAR( l12287 );
        X12 = sc_cons( X9, EMPTYLIST );
        X10 = sc_cons( X11, X12 );
        X8 = X10;
        X7 = sc_cons( X8, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L13807;
        X8 = PAIR_CDR( X4 );
        X6 = X7;
        X5 = X7;
        X4 = X8;
        GOBACK( L13797 );
L13807:
        X8 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L13812;
        scdebug_error( c12167, 
                       c12168, CONS( X6, EMPTYLIST ) );
L13812:
        X6 = SETGEN( PAIR_CDR( X6 ), X7 );
        X4 = X8;
        GOBACK( L13797 );
L13808:
        POPSTACKTRACE( scrt1_append_2dtwo( X1, X2 ) );
L13789:
        POPSTACKTRACE( EMPTYLIST );
}

DEFTSCP( codetectionlib_2dsc_median_v );
DEFCSTRING( t13814, "MEDIAN" );
EXTERNTSCPP( scrt1_list_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_list_2dref_v );
EXTERNTSCPP( qobischeme_sort, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_sort_v );
EXTERNTSCPP( scrt2__3c, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt2__3c_v );
EXTERNTSCPP( qobischeme_identity, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_identity_v );
EXTERNTSCPP( scrt1_length, XAL1( TSCP ) );
EXTERNTSCP( scrt1_length_v );
EXTERNTSCPP( scrt2__2f_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2f_2dtwo_v );

TSCP  codetectionlib_2dsc_median( l12352 )
        TSCP  l12352;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13814 );
        X1 = qobischeme_sort( l12352, 
                              scrt2__3c_v, qobischeme_identity_v );
        X3 = scrt1_length( l12352 );
        X4 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( X3 ), 
                                          _S2CINT( _TSCP( 8 ) ) ), 
                                   3 ) ) );
        if  ( FALSE( X4 ) )  goto L13827;
        if  ( EQ( _S2CUINT( _TSCP( 8 ) ), 
                  _S2CUINT( _TSCP( 0 ) ) ) )  goto L13827;
        X5 = _TSCP( REMAINDER( _S2CINT( X3 ), 
                               _S2CINT( _TSCP( 8 ) ) ) );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13827;
        X2 = C_FIXED( QUOTIENT( _S2CINT( X3 ), 
                                _S2CINT( _TSCP( 8 ) ) ) );
        goto L13828;
L13827:
        X2 = scrt2__2f_2dtwo( X3, _TSCP( 8 ) );
L13828:
        POPSTACKTRACE( scrt1_list_2dref( X1, X2 ) );
}

DEFTSCP( nlib_2dsc_ent_2dtime_b0674773_v );
DEFCSTRING( t13829, "CURRENT-TIME" );
EXTERNTSCPP( scrt3_string_2dappend, XAL1( TSCP ) );
EXTERNTSCP( scrt3_string_2dappend_v );
EXTERNTSCPP( scrt2_number_2d_3estring, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_number_2d_3estring_v );
EXTERNTSCPP( qobischeme_getpid, XAL0(  ) );
EXTERNTSCP( qobischeme_getpid_v );
EXTERNTSCPP( scrt4_system, XAL1( TSCP ) );
EXTERNTSCP( scrt4_system_v );
EXTERNTSCPP( scrt6_format, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt6_format_v );
EXTERNTSCPP( qobischeme_first, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_first_v );
EXTERNTSCPP( qobischeme_read_2dfile, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_read_2dfile_v );
EXTERNTSCPP( qobischeme_fields, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_fields_v );
EXTERNTSCPP( qobischeme_rm, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_rm_v );
EXTERNTSCPP( scrt2_string_2d_3enumber, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_string_2d_3enumber_v );
EXTERNTSCPP( qobischeme_second, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_second_v );

TSCP  nlib_2dsc_ent_2dtime_b0674773(  )
{
        TSCP  X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13829 );
        X3 = qobischeme_getpid(  );
        X2 = CONS( scrt2_number_2d_3estring( X3, EMPTYLIST ), 
                   EMPTYLIST );
        X1 = scrt3_string_2dappend( CONS( c12423, X2 ) );
        X3 = CONS( X1, EMPTYLIST );
        X2 = scrt6_format( FALSEVALUE, CONS( c12377, X3 ) );
        scrt4_system( X2 );
        X4 = qobischeme_read_2dfile( X1 );
        X5 = X4;
        X6 = EMPTYLIST;
        X7 = EMPTYLIST;
L13834:
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L13835;
        X3 = X6;
        goto L13842;
L13835:
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L13838;
        scrt1__24__car_2derror( X5 );
L13838:
        X10 = PAIR_CAR( X5 );
        X9 = qobischeme_fields( X10 );
        X8 = sc_cons( X9, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X6 ), _S2CUINT( EMPTYLIST ) ) )  goto L13841;
        X9 = PAIR_CDR( X5 );
        X7 = X8;
        X6 = X8;
        X5 = X9;
        GOBACK( L13834 );
L13841:
        X9 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L13846;
        scdebug_error( c12167, 
                       c12168, CONS( X7, EMPTYLIST ) );
L13846:
        X7 = SETGEN( PAIR_CDR( X7 ), X8 );
        X5 = X9;
        GOBACK( L13834 );
L13842:
        X2 = qobischeme_first( X3 );
        qobischeme_rm( X1 );
        X4 = CONS( qobischeme_second( X2 ), EMPTYLIST );
        X4 = CONS( c12380, X4 );
        X3 = scrt3_string_2dappend( CONS( qobischeme_first( X2 ), 
                                          X4 ) );
        POPSTACKTRACE( scrt2_string_2d_3enumber( X3, EMPTYLIST ) );
}

DEFTSCP( codetectionlib_2dsc_hostname_v );
DEFCSTRING( t13849, "HOSTNAME" );

TSCP  codetectionlib_2dsc_hostname(  )
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t13849 );
        X3 = qobischeme_getpid(  );
        X2 = CONS( scrt2_number_2d_3estring( X3, EMPTYLIST ), 
                   EMPTYLIST );
        X1 = scrt3_string_2dappend( CONS( c12430, X2 ) );
        X3 = CONS( X1, EMPTYLIST );
        X2 = scrt6_format( FALSEVALUE, CONS( c12427, X3 ) );
        scrt4_system( X2 );
        X2 = qobischeme_read_2dfile( X1 );
        qobischeme_rm( X1 );
        POPSTACKTRACE( qobischeme_first( X2 ) );
}

DEFTSCP( nlib_2dsc_and_2dtime_940355d5_v );
DEFCSTRING( t13853, "CURRENT-DATE-AND-TIME" );
EXTERNTSCPP( parser_string_2djoin, XAL2( TSCP, TSCP ) );
EXTERNTSCP( parser_string_2djoin_v );
EXTERNTSCPP( codetectionlib_2dsc_take, XAL2( TSCP, TSCP ) );
EXTERNTSCP( codetectionlib_2dsc_take_v );
EXTERNTSCPP( scrt1_remove, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_remove_v );
EXTERNTSCP( sc_emptystring );
EXTERNTSCPP( pregexp_pregexp_2dsplit, XAL2( TSCP, TSCP ) );
EXTERNTSCP( pregexp_pregexp_2dsplit_v );

TSCP  nlib_2dsc_and_2dtime_940355d5(  )
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13853 );
        X3 = qobischeme_getpid(  );
        X2 = CONS( scrt2_number_2d_3estring( X3, EMPTYLIST ), 
                   EMPTYLIST );
        X1 = scrt3_string_2dappend( CONS( c12423, X2 ) );
        X3 = CONS( X1, EMPTYLIST );
        X2 = scrt6_format( FALSEVALUE, CONS( c12434, X3 ) );
        scrt4_system( X2 );
        X7 = qobischeme_read_2dfile( X1 );
        X6 = qobischeme_first( X7 );
        X5 = pregexp_pregexp_2dsplit( c12439, X6 );
        X4 = scrt1_remove( sc_emptystring, X5 );
        X3 = codetectionlib_2dsc_take( _TSCP( 16 ), X4 );
        X2 = parser_string_2djoin( c12437, X3 );
        qobischeme_rm( X1 );
        POPSTACKTRACE( X2 );
}

DEFTSCP( nlib_2dsc_ist_2dmean_b3ce463_v );
DEFCSTRING( t13857, "LIST-MEAN" );
EXTERNTSCPP( qobischeme_k_2av, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_k_2av_v );
EXTERNTSCPP( qobischeme_reduce, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_reduce_v );
EXTERNTSCPP( qobischeme_v_2b, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_v_2b_v );
EXTERNTSCPP( scrt2__2b, XAL1( TSCP ) );
EXTERNTSCP( scrt2__2b_v );

TSCP  nlib_2dsc_ist_2dmean_b3ce463( p12441 )
        TSCP  p12441;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13857 );
        if  ( EQ( TSCPTAG( p12441 ), PAIRTAG ) )  goto L13862;
        scrt1__24__car_2derror( p12441 );
L13862:
        X3 = PAIR_CAR( p12441 );
        if  ( NOT( AND( EQ( TSCPTAG( X3 ), EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( X3 ), VECTORTAG ) ) )
            )  goto L13859;
        X4 = scrt1_length( p12441 );
        X5 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( _TSCP( 4 ) ), 
                                          _S2CINT( X4 ) ), 
                                   3 ) ) );
        if  ( FALSE( X5 ) )  goto L13875;
        if  ( EQ( _S2CUINT( X4 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13875;
        X6 = _TSCP( REMAINDER( _S2CINT( _TSCP( 4 ) ), 
                               _S2CINT( X4 ) ) );
        if  ( NEQ( _S2CUINT( X6 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13875;
        X3 = C_FIXED( QUOTIENT( _S2CINT( _TSCP( 4 ) ), 
                                _S2CINT( X4 ) ) );
        goto L13876;
L13875:
        X3 = scrt2__2f_2dtwo( _TSCP( 4 ), X4 );
L13876:
        X4 = qobischeme_reduce( qobischeme_v_2b_v, 
                                p12441, _TSCP( 0 ) );
        POPSTACKTRACE( qobischeme_k_2av( X3, X4 ) );
L13859:
        X2 = qobischeme_reduce( scrt2__2b_v, p12441, _TSCP( 0 ) );
        X1 = scrt1_length( p12441 );
        X3 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( X2 ), 
                                          _S2CINT( X1 ) ), 
                                   3 ) ) );
        if  ( FALSE( X3 ) )  goto L13888;
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13888;
        X4 = _TSCP( REMAINDER( _S2CINT( X2 ), 
                               _S2CINT( X1 ) ) );
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13888;
        POPSTACKTRACE( C_FIXED( QUOTIENT( _S2CINT( X2 ), 
                                          _S2CINT( X1 ) ) ) );
L13888:
        POPSTACKTRACE( scrt2__2f_2dtwo( X2, X1 ) );
}

DEFTSCP( codetectionlib_2dsc_randomize_v );
DEFCSTRING( t13889, "RANDOMIZE" );
EXTERNTSCPP( qobischeme_for_2deach_2dn, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_for_2deach_2dn_v );
EXTERNTSCPP( qobischeme_random_2dreal, XAL0(  ) );
EXTERNTSCP( qobischeme_random_2dreal_v );

TSCP  codetectionlib_2dsc_l12490( i12491, c13891 )
        TSCP  i12491, c13891;
{
        PUSHSTACKTRACE( "codetectionlib_2dsc_l12490 [inside RANDOMIZE]" );
        POPSTACKTRACE( qobischeme_random_2dreal(  ) );
}

EXTERNTSCPP( qobischeme_map_2dreduce, 
             XAL5( TSCP, TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dreduce_v );
EXTERNTSCPP( scrt3_char_2d_3einteger, XAL1( TSCP ) );
EXTERNTSCP( scrt3_char_2d_3einteger_v );
EXTERNTSCPP( scrt3_string_2d_3elist, XAL1( TSCP ) );
EXTERNTSCP( scrt3_string_2d_3elist_v );
EXTERNTSCPP( scrt2__2b_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2b_2dtwo_v );

TSCP  codetectionlib_2dsc_randomize(  )
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13889 );
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            codetectionlib_2dsc_l12490, EMPTYLIST );
        X5 = codetectionlib_2dsc_hostname(  );
        X4 = scrt3_string_2d_3elist( X5 );
        X3 = qobischeme_map_2dreduce( scrt2__2b_v, 
                                      _TSCP( 0 ), 
                                      scrt3_char_2d_3einteger_v, 
                                      X4, EMPTYLIST );
        X4 = qobischeme_getpid(  );
        if  ( BITAND( BITOR( _S2CINT( X4 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L13894;
        X2 = _TSCP( IPLUS( _S2CINT( X4 ), _S2CINT( X3 ) ) );
        goto L13895;
L13894:
        X2 = scrt2__2b_2dtwo( X4, X3 );
L13895:
        POPSTACKTRACE( qobischeme_for_2deach_2dn( X1, X2 ) );
}

DEFTSCP( nlib_2dsc_stic_2dmap_a3e1700b_v );
DEFCSTRING( t13896, "NONDETERMINISTIC-MAP" );

TSCP  nlib_2dsc_stic_2dmap_a3e1700b( f12499, l12500 )
        TSCP  f12499, l12500;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13896 );
        X1 = EMPTYLIST;
        X2 = l12500;
L13899:
        if  ( NEQ( _S2CUINT( X2 ), _S2CUINT( EMPTYLIST ) ) )  goto L13900;
        POPSTACKTRACE( scrt1_reverse( X1 ) );
L13900:
        X6 = qobischeme_first( X2 );
        X5 = f12499;
        X5 = UNKNOWNCALL( X5, 1 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( X6, 
                                          PROCEDURE_CLOSURE( X5 ) );
        X3 = sc_cons( X4, X1 );
        X2 = qobischeme_rest( X2 );
        X1 = X3;
        GOBACK( L13899 );
}

DEFTSCP( nlib_2dsc_sublist_3f_9e75a600_v );
DEFCSTRING( t13902, "INITIAL-SUBLIST?" );
EXTERNTSCPP( scrt2__3e_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3e_2dtwo_v );

TSCP  nlib_2dsc_sublist_3f_9e75a600( r12515, l12516 )
        TSCP  r12515, l12516;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13902 );
        X2 = scrt1_length( r12515 );
        X3 = scrt1_length( l12516 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L13905;
        X1 = BOOLEAN( GT( _S2CINT( X2 ), _S2CINT( X3 ) ) );
        goto L13906;
L13905:
        X1 = scrt2__3e_2dtwo( X2, X3 );
L13906:
        if  ( FALSE( X1 ) )  goto L13908;
        X2 = l12516;
        X3 = r12515;
L13911:
        if  ( EQ( _S2CUINT( X2 ), _S2CUINT( EMPTYLIST ) ) )  goto L13912;
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L13915;
        scrt1__24__car_2derror( X2 );
L13915:
        X5 = PAIR_CAR( X2 );
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L13918;
        scrt1__24__car_2derror( X3 );
L13918:
        X6 = PAIR_CAR( X3 );
        X4 = scrt1_equal_3f( X5, X6 );
        if  ( FALSE( X4 ) )  goto L13921;
        X5 = PAIR_CDR( X2 );
        X3 = PAIR_CDR( X3 );
        X2 = X5;
        GOBACK( L13911 );
L13921:
        POPSTACKTRACE( X4 );
L13912:
        POPSTACKTRACE( TRUEVALUE );
L13908:
        POPSTACKTRACE( X1 );
}

DEFTSCP( codetectionlib_2dsc_maximump_v );
DEFCSTRING( t13925, "MAXIMUMP" );

TSCP  codetectionlib_2dsc_maximump( l12561, p12562 )
        TSCP  l12561, p12562;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13925 );
        if  ( EQ( _S2CUINT( l12561 ), 
                  _S2CUINT( EMPTYLIST ) ) )  goto L13928;
        X1 = p12562;
        if  ( EQ( TSCPTAG( l12561 ), PAIRTAG ) )  goto L13931;
        scrt1__24__cdr_2derror( l12561 );
L13931:
        X2 = PAIR_CDR( l12561 );
        X3 = PAIR_CAR( l12561 );
L13934:
        if  ( EQ( _S2CUINT( X2 ), _S2CUINT( EMPTYLIST ) ) )  goto L13935;
        X5 = X1;
        X5 = UNKNOWNCALL( X5, 1 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( X3, 
                                          PROCEDURE_CLOSURE( X5 ) );
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L13938;
        scrt1__24__car_2derror( X2 );
L13938:
        X7 = PAIR_CAR( X2 );
        X6 = X1;
        X6 = UNKNOWNCALL( X6, 1 );
        X5 = VIA( PROCEDURE_CODE( X6 ) )( X7, 
                                          PROCEDURE_CLOSURE( X6 ) );
        if  ( BITAND( BITOR( _S2CINT( X5 ), _S2CINT( X4 ) ), 
                      3 ) )  goto L13942;
        if  ( GT( _S2CINT( X5 ), _S2CINT( X4 ) ) )  goto L13946;
        goto L13947;
L13942:
        if  ( TRUE( scrt2__3e_2dtwo( X5, X4 ) ) )  goto L13946;
        goto L13947;
L13935:
        POPSTACKTRACE( X3 );
L13947:
        X4 = PAIR_CDR( X2 );
        X2 = X4;
        GOBACK( L13934 );
L13946:
        X4 = PAIR_CDR( X2 );
        X3 = PAIR_CAR( X2 );
        X2 = X4;
        GOBACK( L13934 );
L13928:
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( nlib_2dsc_flatten_2a_dee05d56_v );
DEFCSTRING( t13953, "FLATTEN*" );
EXTERNTSCPP( scrt1_list_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt1_list_3f_v );
EXTERNTSCPP( nlib_2dsc_flatten_2a_dee05d56, XAL1( TSCP ) );
EXTERNTSCP( nlib_2dsc_flatten_2a_dee05d56_v );

TSCP  nlib_2dsc_flatten_2a_dee05d56( l12610 )
        TSCP  l12610;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t13953 );
L13954:
        if  ( EQ( _S2CUINT( l12610 ), 
                  _S2CUINT( EMPTYLIST ) ) )  goto L13955;
        if  ( EQ( TSCPTAG( l12610 ), PAIRTAG ) )  goto L13960;
        scrt1__24__car_2derror( l12610 );
L13960:
        X1 = PAIR_CAR( l12610 );
        if  ( FALSE( scrt1_list_3f( X1 ) ) )  goto L13957;
        X1 = PAIR_CAR( l12610 );
        X2 = PAIR_CDR( l12610 );
        l12610 = scrt1_append_2dtwo( X1, X2 );
        GOBACK( L13954 );
L13957:
        if  ( EQ( TSCPTAG( l12610 ), PAIRTAG ) )  goto L13965;
        scrt1__24__car_2derror( l12610 );
L13965:
        X1 = PAIR_CAR( l12610 );
        X3 = PAIR_CDR( l12610 );
        X2 = nlib_2dsc_flatten_2a_dee05d56( X3 );
        POPSTACKTRACE( sc_cons( X1, X2 ) );
L13955:
        POPSTACKTRACE( EMPTYLIST );
}

DEFTSCP( nlib_2dsc_of_2dlists_ff272f8f_v );
DEFCSTRING( t13968, "MATRIX->LIST-OF-LISTS" );
EXTERNTSCPP( scrt4_vector_2d_3elist, XAL1( TSCP ) );
EXTERNTSCP( scrt4_vector_2d_3elist_v );
EXTERNTSCPP( qobischeme_map_2dvector, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dvector_v );

TSCP  nlib_2dsc_of_2dlists_ff272f8f( m12637 )
        TSCP  m12637;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13968 );
        X1 = qobischeme_map_2dvector( scrt4_vector_2d_3elist_v, 
                                      m12637, EMPTYLIST );
        POPSTACKTRACE( scrt4_vector_2d_3elist( X1 ) );
}

DEFTSCP( nlib_2dsc_d_3ematrix_eaa6578d_v );
DEFCSTRING( t13970, "LIST-OF-LISTS->MATRIX" );
EXTERNTSCPP( scrt4_list_2d_3evector, XAL1( TSCP ) );
EXTERNTSCP( scrt4_list_2d_3evector_v );

TSCP  nlib_2dsc_d_3ematrix_eaa6578d( l12639 )
        TSCP  l12639;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13970 );
        X2 = l12639;
        X3 = EMPTYLIST;
        X4 = EMPTYLIST;
L13974:
        if  ( NEQ( _S2CUINT( X2 ), _S2CUINT( EMPTYLIST ) ) )  goto L13975;
        X1 = X3;
        goto L13982;
L13975:
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L13978;
        scrt1__24__car_2derror( X2 );
L13978:
        X7 = PAIR_CAR( X2 );
        X6 = scrt4_list_2d_3evector( X7 );
        X5 = sc_cons( X6, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( EMPTYLIST ) ) )  goto L13981;
        X6 = PAIR_CDR( X2 );
        X4 = X5;
        X3 = X5;
        X2 = X6;
        GOBACK( L13974 );
L13981:
        X6 = PAIR_CDR( X2 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L13986;
        scdebug_error( c12167, 
                       c12168, CONS( X4, EMPTYLIST ) );
L13986:
        X4 = SETGEN( PAIR_CDR( X4 ), X5 );
        X2 = X6;
        GOBACK( L13974 );
L13982:
        POPSTACKTRACE( scrt4_list_2d_3evector( X1 ) );
}

DEFTSCP( nlib_2dsc_lit_2dinto_41bd5faf_v );
DEFCSTRING( t13988, "SPLIT-INTO" );
EXTERNTSCPP( scrt2_inexact_2d_3eexact, XAL1( TSCP ) );
EXTERNTSCP( scrt2_inexact_2d_3eexact_v );
EXTERNTSCPP( scrt2_floor, XAL1( TSCP ) );
EXTERNTSCP( scrt2_floor_v );
EXTERNTSCPP( scrt2_modulo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_modulo_v );
EXTERNTSCPP( scrt2__3d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3d_2dtwo_v );
EXTERNTSCPP( codetectionlib_2dsc_l12691, XAL2( TSCP, TSCP ) );
EXTERNTSCPP( codetectionlib_2dsc_drop, XAL2( TSCP, TSCP ) );
EXTERNTSCP( codetectionlib_2dsc_drop_v );
EXTERNTSCPP( qobischeme_fuck_2dup, XAL0(  ) );
EXTERNTSCP( qobischeme_fuck_2dup_v );
EXTERNTSCPP( scrt2__2d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2d_2dtwo_v );

TSCP  codetectionlib_2dsc_l12691( l12693, m12694 )
        TSCP  l12693, m12694;
{
        TSCP  X4, X3, X2, X1;

        PUSHSTACKTRACE( "LOOP [inside SPLIT-INTO]" );
        if  ( EQ( _S2CUINT( l12693 ), 
                  _S2CUINT( EMPTYLIST ) ) )  goto L14007;
        if  ( BITAND( BITOR( _S2CINT( m12694 ), 
                             _S2CINT( _TSCP( 0 ) ) ), 
                      3 ) )  goto L14010;
        if  ( GT( _S2CINT( m12694 ), _S2CINT( _TSCP( 0 ) ) ) )  goto L14014;
        goto L14015;
L14010:
        if  ( TRUE( scrt2__3e_2dtwo( m12694, _TSCP( 0 ) ) ) )  goto L14014;
        goto L14015;
L14007:
        POPSTACKTRACE( EMPTYLIST );
L14015:
        if  ( BITAND( BITOR( _S2CINT( m12694 ), 
                             _S2CINT( _TSCP( 0 ) ) ), 
                      3 ) )  goto L14019;
        if  ( EQ( _S2CUINT( m12694 ), 
                  _S2CUINT( _TSCP( 0 ) ) ) )  goto L14023;
        goto L14024;
L14019:
        if  ( FALSE( scrt2__3d_2dtwo( m12694, _TSCP( 0 ) ) ) )  goto L14024;
L14023:
        X1 = codetectionlib_2dsc_take( DISPLAY( 0 ), l12693 );
        X3 = codetectionlib_2dsc_drop( DISPLAY( 0 ), l12693 );
        X2 = codetectionlib_2dsc_l12691( X3, m12694 );
        POPSTACKTRACE( sc_cons( X1, X2 ) );
L14024:
        POPSTACKTRACE( qobischeme_fuck_2dup(  ) );
L14014:
        if  ( BITAND( BITOR( _S2CINT( DISPLAY( 0 ) ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L14027;
        X2 = _TSCP( IPLUS( _S2CINT( DISPLAY( 0 ) ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L14028;
L14027:
        X2 = scrt2__2b_2dtwo( DISPLAY( 0 ), _TSCP( 4 ) );
L14028:
        X1 = codetectionlib_2dsc_take( X2, l12693 );
        if  ( BITAND( BITOR( _S2CINT( DISPLAY( 0 ) ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L14029;
        X4 = _TSCP( IPLUS( _S2CINT( DISPLAY( 0 ) ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L14030;
L14029:
        X4 = scrt2__2b_2dtwo( DISPLAY( 0 ), _TSCP( 4 ) );
L14030:
        X3 = codetectionlib_2dsc_drop( X4, l12693 );
        if  ( BITAND( BITOR( _S2CINT( m12694 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L14031;
        X4 = _TSCP( IDIFFERENCE( _S2CINT( m12694 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L14032;
L14031:
        X4 = scrt2__2d_2dtwo( m12694, _TSCP( 4 ) );
L14032:
        X2 = codetectionlib_2dsc_l12691( X3, X4 );
        POPSTACKTRACE( sc_cons( X1, X2 ) );
}

TSCP  nlib_2dsc_lit_2dinto_41bd5faf( n12683, l12684 )
        TSCP  n12683, l12684;
{
        TSCP  X5, X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13988 );
        X3 = scrt1_length( l12684 );
        X4 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( X3 ), 
                                          _S2CINT( n12683 ) ), 
                                   3 ) ) );
        if  ( FALSE( X4 ) )  goto L14001;
        if  ( EQ( _S2CUINT( n12683 ), 
                  _S2CUINT( _TSCP( 0 ) ) ) )  goto L14001;
        X5 = _TSCP( REMAINDER( _S2CINT( X3 ), 
                               _S2CINT( n12683 ) ) );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L14001;
        X2 = C_FIXED( QUOTIENT( _S2CINT( X3 ), 
                                _S2CINT( n12683 ) ) );
        goto L14002;
L14001:
        X2 = scrt2__2f_2dtwo( X3, n12683 );
L14002:
        X1 = scrt2_floor( X2 );
        DISPLAY( 0 ) = scrt2_inexact_2d_3eexact( X1 );
        X2 = scrt1_length( l12684 );
        X1 = scrt2_modulo( X2, n12683 );
        SDVAL = codetectionlib_2dsc_l12691( l12684, X1 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( codetectionlib_2dsc_take_v );
DEFCSTRING( t14033, "TAKE" );
EXTERNTSCPP( qobischeme_sublist, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_sublist_v );

TSCP  codetectionlib_2dsc_take( n12754, l12755 )
        TSCP  n12754, l12755;
{
        PUSHSTACKTRACE( t14033 );
        POPSTACKTRACE( qobischeme_sublist( l12755, 
                                           _TSCP( 0 ), n12754 ) );
}

DEFTSCP( codetectionlib_2dsc_drop_v );
DEFCSTRING( t14035, "DROP" );

TSCP  codetectionlib_2dsc_drop( n12757, l12758 )
        TSCP  n12757, l12758;
{
        TSCP  X1;

        PUSHSTACKTRACE( t14035 );
        X1 = scrt1_length( l12758 );
        POPSTACKTRACE( qobischeme_sublist( l12758, n12757, X1 ) );
}

DEFTSCP( codetectionlib_2dsc_split_2dn_v );
DEFCSTRING( t14037, "SPLIT-N" );
EXTERNTSCPP( codetectionlib_2dsc_split_2dn, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( codetectionlib_2dsc_split_2dn_v );

TSCP  codetectionlib_2dsc_split_2dn( n12760, l12761 )
        TSCP  n12760, l12761;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t14037 );
        if  ( EQ( _S2CUINT( l12761 ), 
                  _S2CUINT( EMPTYLIST ) ) )  goto L14039;
        X1 = codetectionlib_2dsc_take( n12760, l12761 );
        X3 = codetectionlib_2dsc_drop( n12760, l12761 );
        X2 = codetectionlib_2dsc_split_2dn( n12760, X3 );
        POPSTACKTRACE( sc_cons( X1, X2 ) );
L14039:
        POPSTACKTRACE( l12761 );
}

DEFTSCP( codetectionlib_2dsc_join_v );
DEFCSTRING( t14041, "JOIN" );
EXTERNTSCPP( scrt1_append, XAL1( TSCP ) );
EXTERNTSCP( scrt1_append_v );

TSCP  codetectionlib_2dsc_join( l12768 )
        TSCP  l12768;
{
        PUSHSTACKTRACE( t14041 );
        POPSTACKTRACE( qobischeme_reduce( scrt1_append_v, 
                                          l12768, EMPTYLIST ) );
}

DEFTSCP( codetectionlib_2dsc_unzip_v );
DEFCSTRING( t14043, "UNZIP" );
EXTERNTSCPP( qobischeme_map_2dn, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dn_v );

TSCP  codetectionlib_2dsc_l12776( i12777, c14047 )
        TSCP  i12777, c14047;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "codetectionlib_2dsc_l12776 [inside UNZIP]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c14047, 0 );
        X3 = DISPLAY( 0 );
        X4 = X3;
        X5 = EMPTYLIST;
        X6 = EMPTYLIST;
L14051:
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L14052;
        X2 = X5;
        goto L14059;
L14052:
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L14055;
        scrt1__24__car_2derror( X4 );
L14055:
        X9 = PAIR_CAR( X4 );
        X8 = scrt1_list_2dref( X9, i12777 );
        X7 = sc_cons( X8, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L14058;
        X8 = PAIR_CDR( X4 );
        X6 = X7;
        X5 = X7;
        X4 = X8;
        GOBACK( L14051 );
L14058:
        X8 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L14063;
        scdebug_error( c12167, 
                       c12168, CONS( X6, EMPTYLIST ) );
L14063:
        X6 = SETGEN( PAIR_CDR( X6 ), X7 );
        X4 = X8;
        GOBACK( L14051 );
L14059:
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  codetectionlib_2dsc_unzip( l12770 )
        TSCP  l12770;
{
        TSCP  X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t14043 );
        DISPLAY( 0 ) = l12770;
        if  ( EQ( _S2CUINT( DISPLAY( 0 ) ), 
                  _S2CUINT( EMPTYLIST ) ) )  goto L14045;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            codetectionlib_2dsc_l12776, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X3 = qobischeme_first( DISPLAY( 0 ) );
        X2 = scrt1_length( X3 );
        SDVAL = qobischeme_map_2dn( X1, X2 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
L14045:
        SDVAL = EMPTYLIST;
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( nlib_2dsc_dnecessary_994e4d49_v );
DEFCSTRING( t14065, "PAD-IF-NECESSARY" );
EXTERNTSCPP( scrt2__3e_3d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3e_3d_2dtwo_v );

TSCP  codetectionlib_2dsc_l12832( __12833, c14076 )
        TSCP  __12833, c14076;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "codetectionlib_2dsc_l12832 [inside PAD-IF-NECESSARY\
]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c14076, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  nlib_2dsc_dnecessary_994e4d49( l12823, l12824, e12825 )
        TSCP  l12823, l12824, e12825;
{
        TSCP  X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t14065 );
        DISPLAY( 0 ) = e12825;
        X1 = scrt1_length( l12823 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( l12824 ) ), 
                      3 ) )  goto L14069;
        if  ( LT( _S2CINT( X1 ), _S2CINT( l12824 ) ) )  goto L14073;
        SDVAL = l12823;
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
L14069:
        if  ( FALSE( scrt2__3e_3d_2dtwo( X1, l12824 ) ) )  goto L14073;
        SDVAL = l12823;
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
L14073:
        X2 = MAKEPROCEDURE( 0, 
                            1, 
                            codetectionlib_2dsc_l12832, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X4 = scrt1_length( l12823 );
        if  ( BITAND( BITOR( _S2CINT( l12824 ), 
                             _S2CINT( X4 ) ), 
                      3 ) )  goto L14079;
        X3 = _TSCP( IDIFFERENCE( _S2CINT( l12824 ), 
                                 _S2CINT( X4 ) ) );
        goto L14080;
L14079:
        X3 = scrt2__2d_2dtwo( l12824, X4 );
L14080:
        X1 = qobischeme_map_2dn( X2, X3 );
        SDVAL = scrt1_append_2dtwo( l12823, X1 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( nlib_2dsc_2dpossible_ced25962_v );
DEFCSTRING( t14081, "TAKE-IF-POSSIBLE" );

TSCP  nlib_2dsc_2dpossible_ced25962( n12841, l12842 )
        TSCP  n12841, l12842;
{
        TSCP  X1;

        PUSHSTACKTRACE( t14081 );
        X1 = scrt1_length( l12842 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( n12841 ) ), 
                      3 ) )  goto L14085;
        if  ( GT( _S2CINT( X1 ), _S2CINT( n12841 ) ) )  goto L14089;
        POPSTACKTRACE( l12842 );
L14085:
        if  ( TRUE( scrt2__3e_2dtwo( X1, n12841 ) ) )  goto L14089;
        POPSTACKTRACE( l12842 );
L14089:
        POPSTACKTRACE( codetectionlib_2dsc_take( n12841, l12842 ) );
}

DEFTSCP( nlib_2dsc_2dpick_2dm_2507cf0b_v );
DEFCSTRING( t14092, "RAND-PICK-M" );

TSCP  nlib_2dsc_2dpick_2dm_2507cf0b( l12850, m12851 )
        TSCP  l12850, m12851;
{
        TSCP  X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t14092 );
        X5 = l12850;
        X6 = EMPTYLIST;
        X7 = EMPTYLIST;
L14095:
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L14096;
        X4 = X6;
        goto L14105;
L14096:
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L14099;
        scrt1__24__car_2derror( X5 );
L14099:
        X10 = PAIR_CAR( X5 );
        X12 = qobischeme_random_2dreal(  );
        X13 = sc_cons( X10, EMPTYLIST );
        X11 = sc_cons( X12, X13 );
        X9 = X11;
        X8 = sc_cons( X9, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X6 ), _S2CUINT( EMPTYLIST ) ) )  goto L14104;
        X9 = PAIR_CDR( X5 );
        X7 = X8;
        X6 = X8;
        X5 = X9;
        GOBACK( L14095 );
L14104:
        X9 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L14109;
        scdebug_error( c12167, 
                       c12168, CONS( X7, EMPTYLIST ) );
L14109:
        X7 = SETGEN( PAIR_CDR( X7 ), X8 );
        X5 = X9;
        GOBACK( L14095 );
L14105:
        X3 = qobischeme_sort( X4, scrt2__3c_v, qobischeme_first_v );
        X4 = X3;
        X5 = EMPTYLIST;
        X6 = EMPTYLIST;
L14113:
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L14114;
        X2 = X5;
        goto L14121;
L14114:
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L14117;
        scrt1__24__car_2derror( X4 );
L14117:
        X9 = PAIR_CAR( X4 );
        X8 = qobischeme_second( X9 );
        X7 = sc_cons( X8, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L14120;
        X8 = PAIR_CDR( X4 );
        X6 = X7;
        X5 = X7;
        X4 = X8;
        GOBACK( L14113 );
L14120:
        X8 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L14125;
        scdebug_error( c12167, 
                       c12168, CONS( X6, EMPTYLIST ) );
L14125:
        X6 = SETGEN( PAIR_CDR( X6 ), X7 );
        X4 = X8;
        GOBACK( L14113 );
L14121:
        X1 = nlib_2dsc_2dpossible_ced25962( m12851, X2 );
        POPSTACKTRACE( qobischeme_sort( X1, 
                                        scrt2__3c_v, 
                                        qobischeme_identity_v ) );
}

DEFTSCP( nlib_2dsc_devery_2dn_da212f5_v );
DEFCSTRING( t14127, "TAKE-EVERY-N" );
EXTERNTSCPP( scrt2_zero_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt2_zero_3f_v );

TSCP  codetectionlib_2dsc_l12943( x12944, i12945, c14129 )
        TSCP  x12944, i12945, c14129;
{
        TSCP  X4, X3, X2, X1;

        PUSHSTACKTRACE( "codetectionlib_2dsc_l12943 [inside TAKE-EVERY-N]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c14129, 0 );
        if  ( BITAND( BITOR( _S2CINT( i12945 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L14131;
        X4 = _TSCP( IPLUS( _S2CINT( i12945 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L14132;
L14131:
        X4 = scrt2__2b_2dtwo( i12945, _TSCP( 4 ) );
L14132:
        X3 = scrt2_modulo( X4, DISPLAY( 0 ) );
        if  ( NEQ( TSCPTAG( X3 ), FIXNUMTAG ) )  goto L14134;
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L14136;
        X2 = x12944;
        goto L14139;
L14136:
        X2 = FALSEVALUE;
        goto L14139;
L14134:
        if  ( FALSE( scrt2_zero_3f( X3 ) ) )  goto L14138;
        X2 = x12944;
        goto L14139;
L14138:
        X2 = FALSEVALUE;
L14139:
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  nlib_2dsc_devery_2dn_da212f5( l12941, n12942 )
        TSCP  l12941, n12942;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t14127 );
        DISPLAY( 0 ) = n12942;
        X2 = MAKEPROCEDURE( 2, 
                            0, 
                            codetectionlib_2dsc_l12943, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X1 = qobischeme_map_2dindexed( X2, l12941 );
        SDVAL = qobischeme_removeq( FALSEVALUE, X1 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( codetectionlib_2dsc_middle_v );
DEFCSTRING( t14140, "MIDDLE" );
EXTERNTSCPP( scrt2_quotient, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_quotient_v );

TSCP  codetectionlib_2dsc_middle( l12962 )
        TSCP  l12962;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t14140 );
        if  ( EQ( _S2CUINT( l12962 ), 
                  _S2CUINT( EMPTYLIST ) ) )  goto L14142;
        X2 = scrt1_length( l12962 );
        X3 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( X2 ), 
                                          _S2CINT( _TSCP( 8 ) ) ), 
                                   3 ) ) );
        if  ( FALSE( X3 ) )  goto L14151;
        if  ( EQ( _S2CUINT( _TSCP( 8 ) ), 
                  _S2CUINT( _TSCP( 0 ) ) ) )  goto L14151;
        X1 = C_FIXED( QUOTIENT( _S2CINT( X2 ), 
                                _S2CINT( _TSCP( 8 ) ) ) );
        goto L14152;
L14151:
        X1 = scrt2_quotient( X2, _TSCP( 8 ) );
L14152:
        POPSTACKTRACE( scrt1_list_2dref( l12962, X1 ) );
L14142:
        POPSTACKTRACE( EMPTYLIST );
}

DEFTSCP( nlib_2dsc_of_2dlists_660f857e_v );
DEFCSTRING( t14153, "TRANSPOSE-LIST-OF-LISTS" );
EXTERNTSCPP( qobischeme_transpose, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_transpose_v );

TSCP  nlib_2dsc_of_2dlists_660f857e( l12982 )
        TSCP  l12982;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t14153 );
        X2 = nlib_2dsc_d_3ematrix_eaa6578d( l12982 );
        X1 = qobischeme_transpose( X2 );
        POPSTACKTRACE( nlib_2dsc_of_2dlists_ff272f8f( X1 ) );
}

DEFTSCP( nlib_2dsc_2dpick_2dm_2b0fa3e_v );
DEFCSTRING( t14155, "EVENLY-PICK-M" );

TSCP  nlib_2dsc_2dpick_2dm_2b0fa3e( l12984, m12985 )
        TSCP  l12984, m12985;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t14155 );
        if  ( BITAND( BITOR( _S2CINT( m12985 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L14158;
        if  ( EQ( _S2CUINT( m12985 ), 
                  _S2CUINT( _TSCP( 4 ) ) ) )  goto L14162;
        goto L14163;
L14158:
        if  ( FALSE( scrt2__3d_2dtwo( m12985, _TSCP( 4 ) ) ) )  goto L14163;
L14162:
        X2 = scrt1_length( l12984 );
        X3 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( X2 ), 
                                          _S2CINT( _TSCP( 8 ) ) ), 
                                   3 ) ) );
        if  ( FALSE( X3 ) )  goto L14173;
        if  ( EQ( _S2CUINT( _TSCP( 8 ) ), 
                  _S2CUINT( _TSCP( 0 ) ) ) )  goto L14173;
        X1 = C_FIXED( QUOTIENT( _S2CINT( X2 ), 
                                _S2CINT( _TSCP( 8 ) ) ) );
        goto L14174;
L14173:
        X1 = scrt2_quotient( X2, _TSCP( 8 ) );
L14174:
        POPSTACKTRACE( scrt1_list_2dref( l12984, X1 ) );
L14163:
        X1 = nlib_2dsc_lit_2dinto_41bd5faf( m12985, l12984 );
        X2 = X1;
        X3 = EMPTYLIST;
        X4 = EMPTYLIST;
L14177:
        if  ( EQ( _S2CUINT( X2 ), _S2CUINT( EMPTYLIST ) ) )  goto L14178;
        if  ( EQ( TSCPTAG( X2 ), PAIRTAG ) )  goto L14181;
        scrt1__24__car_2derror( X2 );
L14181:
        X7 = PAIR_CAR( X2 );
        X6 = codetectionlib_2dsc_middle( X7 );
        X5 = sc_cons( X6, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( EMPTYLIST ) ) )  goto L14184;
        X6 = PAIR_CDR( X2 );
        X4 = X5;
        X3 = X5;
        X2 = X6;
        GOBACK( L14177 );
L14184:
        X6 = PAIR_CDR( X2 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L14189;
        scdebug_error( c12167, 
                       c12168, CONS( X4, EMPTYLIST ) );
L14189:
        X4 = SETGEN( PAIR_CDR( X4 ), X5 );
        X2 = X6;
        GOBACK( L14177 );
L14178:
        POPSTACKTRACE( X3 );
}

DEFTSCP( nlib_2dsc_group_2dby_96ef2b55_v );
DEFCSTRING( t14191, "GROUP-BY" );
EXTERNTSCPP( obischeme_2dclassesp_85ca28a0, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( obischeme_2dclassesp_85ca28a0_v );

TSCP  codetectionlib_2dsc_l13053( a13054, b13055, c14193 )
        TSCP  a13054, b13055, c14193;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "codetectionlib_2dsc_l13053 [inside GROUP-BY]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c14193, 0 );
        X4 = DISPLAY( 0 );
        X4 = UNKNOWNCALL( X4, 1 );
        X3 = VIA( PROCEDURE_CODE( X4 ) )( a13054, 
                                          PROCEDURE_CLOSURE( X4 ) );
        X5 = DISPLAY( 0 );
        X5 = UNKNOWNCALL( X5, 1 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( b13055, 
                                          PROCEDURE_CLOSURE( X5 ) );
        X2 = scrt1_equal_3f( X3, X4 );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  nlib_2dsc_group_2dby_96ef2b55( f13051, l13052 )
        TSCP  f13051, l13052;
{
        TSCP  X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t14191 );
        DISPLAY( 0 ) = f13051;
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            codetectionlib_2dsc_l13053, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        SDVAL = obischeme_2dclassesp_85ca28a0( X1, l13052 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( nlib_2dsc_2dtruncate_eff8e119_v );
DEFCSTRING( t14195, "UPPER-TRUNCATE" );

TSCP  nlib_2dsc_2dtruncate_eff8e119( t13057, x13058 )
        TSCP  t13057, x13058;
{
        PUSHSTACKTRACE( t14195 );
        if  ( BITAND( BITOR( _S2CINT( x13058 ), 
                             _S2CINT( t13057 ) ), 
                      3 ) )  goto L14197;
        if  ( GT( _S2CINT( x13058 ), _S2CINT( t13057 ) ) )  goto L14199;
        POPSTACKTRACE( x13058 );
L14199:
        POPSTACKTRACE( t13057 );
L14197:
        if  ( TRUE( scrt2__3e_2dtwo( x13058, t13057 ) ) )  goto L14201;
        POPSTACKTRACE( x13058 );
L14201:
        POPSTACKTRACE( t13057 );
}

DEFTSCP( codetectionlib_2dsc_sigmoid_v );
DEFCSTRING( t14203, "SIGMOID" );
EXTERNTSCPP( scrt2_exp, XAL1( TSCP ) );
EXTERNTSCP( scrt2_exp_v );
EXTERNTSCPP( scrt2__2a_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2a_2dtwo_v );

TSCP  codetectionlib_2dsc_sigmoid( t13066, a13067, b13068 )
        TSCP  t13066, a13067, b13068;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t14203 );
        if  ( BITAND( BITOR( _S2CINT( t13066 ), 
                             _S2CINT( a13067 ) ), 
                      3 ) )  goto L14205;
        X5 = _TSCP( IDIFFERENCE( _S2CINT( t13066 ), 
                                 _S2CINT( a13067 ) ) );
        goto L14206;
L14205:
        X5 = scrt2__2d_2dtwo( t13066, a13067 );
L14206:
        if  ( BITAND( BITOR( _S2CINT( b13068 ), 
                             _S2CINT( X5 ) ), 
                      3 ) )  goto L14208;
        X4 = _TSCP( ITIMES( FIXED_C( b13068 ), 
                            _S2CINT( X5 ) ) );
        goto L14209;
L14208:
        X4 = scrt2__2a_2dtwo( b13068, X5 );
L14209:
        if  ( NEQ( TSCPTAG( X4 ), FIXNUMTAG ) )  goto L14211;
        X3 = _TSCP( INEGATE( _S2CINT( X4 ) ) );
        goto L14212;
L14211:
        X3 = scrt2__2d_2dtwo( c13101, X4 );
L14212:
        X2 = scrt2_exp( X3 );
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 4 ) ), 
                             _S2CINT( X2 ) ), 
                      3 ) )  goto L14214;
        X1 = _TSCP( IPLUS( _S2CINT( _TSCP( 4 ) ), 
                           _S2CINT( X2 ) ) );
        goto L14215;
L14214:
        X1 = scrt2__2b_2dtwo( _TSCP( 4 ), X2 );
L14215:
        X2 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( _TSCP( 4 ) ), 
                                          _S2CINT( X1 ) ), 
                                   3 ) ) );
        if  ( FALSE( X2 ) )  goto L14227;
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L14227;
        X3 = _TSCP( REMAINDER( _S2CINT( _TSCP( 4 ) ), 
                               _S2CINT( X1 ) ) );
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L14227;
        POPSTACKTRACE( C_FIXED( QUOTIENT( _S2CINT( _TSCP( 4 ) ), 
                                          _S2CINT( X1 ) ) ) );
L14227:
        POPSTACKTRACE( scrt2__2f_2dtwo( _TSCP( 4 ), X1 ) );
}

DEFTSCP( nlib_2dsc__3esplines_183d177c_v );
DEFCSTRING( t14228, "TRACE->SPLINES" );
EXTERNTSCPP( _2dmatlab_ematlab_21_8d661f42, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( _2dmatlab_ematlab_21_8d661f42_v );
EXTERNTSCPP( qobischeme_enumerate_2dvector, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_enumerate_2dvector_v );
EXTERNTSCPP( toollib_2dmatlab_matlab, XAL1( TSCP ) );
EXTERNTSCP( toollib_2dmatlab_matlab_v );
EXTERNTSCPP( _2dmatlab_2dvariable_a304468f, XAL1( TSCP ) );
EXTERNTSCP( _2dmatlab_2dvariable_a304468f_v );

TSCP  codetectionlib_2dsc_l13130( x13131, y13132, c14251 )
        TSCP  x13131, y13132, c14251;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "codetectionlib_2dsc_l13130 [inside TRACE->SPLINES]" );
        X2 = sc_cons( y13132, EMPTYLIST );
        X1 = sc_cons( x13131, X2 );
        POPSTACKTRACE( X1 );
}

EXTERNTSCPP( qobischeme_x, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_x_v );
EXTERNTSCPP( qobischeme_y, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_y_v );

TSCP  nlib_2dsc__3esplines_183d177c( t13115, n13116 )
        TSCP  t13115, n13116;
{
        TSCP  X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t14228 );
        X3 = t13115;
        X4 = EMPTYLIST;
        X5 = EMPTYLIST;
L14232:
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( EMPTYLIST ) ) )  goto L14233;
        X2 = X4;
        goto L14240;
L14233:
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L14236;
        scrt1__24__car_2derror( X3 );
L14236:
        X8 = PAIR_CAR( X3 );
        X7 = scrt4_list_2d_3evector( X8 );
        X6 = sc_cons( X7, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L14239;
        X7 = PAIR_CDR( X3 );
        X5 = X6;
        X4 = X6;
        X3 = X7;
        GOBACK( L14232 );
L14239:
        X7 = PAIR_CDR( X3 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L14244;
        scdebug_error( c12167, 
                       c12168, CONS( X5, EMPTYLIST ) );
L14244:
        X5 = SETGEN( PAIR_CDR( X5 ), X6 );
        X3 = X7;
        GOBACK( L14232 );
L14240:
        X1 = scrt4_list_2d_3evector( X2 );
        _2dmatlab_ematlab_21_8d661f42( c13119, X1 );
        if  ( AND( EQ( TSCPTAG( X1 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X1 ), VECTORTAG ) ) )  goto L14248;
        scdebug_error( c13125, 
                       c13126, CONS( X1, EMPTYLIST ) );
L14248:
        X3 = C_FIXED( VECTOR_LENGTH( X1 ) );
        X2 = qobischeme_enumerate_2dvector( X3 );
        _2dmatlab_ematlab_21_8d661f42( c13120, X2 );
        X2 = CONS( n13116, EMPTYLIST );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c13127, X2 ) ), 
                                       EMPTYLIST ) );
        X2 = _2dmatlab_2dvariable_a304468f( c13135 );
        X4 = MAKEPROCEDURE( 2, 
                            0, 
                            codetectionlib_2dsc_l13130, EMPTYLIST );
        X5 = qobischeme_x( X2 );
        X3 = qobischeme_map_2dvector( X4, 
                                      X5, 
                                      CONS( qobischeme_y( X2 ), 
                                            EMPTYLIST ) );
        POPSTACKTRACE( scrt4_vector_2d_3elist( X3 ) );
}

DEFTSCP( nlib_2dsc_en_2dvideo_9771a33c_v );
DEFCSTRING( t14254, "FFMPEG-OPEN-VIDEO" );

TSCP  nlib_2dsc_en_2dvideo_9771a33c( g13179 )
        TSCP  g13179;
{
        PUSHSTACKTRACE( t14254 );
        POPSTACKTRACE( POINTER_TSCP( ffmpeg_open_video( TSCP_POINTER( g13179 ) ) ) );
}

DEFTSCP( nlib_2dsc_as_2dimlib_f25d19a4_v );
DEFCSTRING( t14256, "FFMPEG-VIDEO-FRAME-DATA-AS-IMLIB" );

TSCP  nlib_2dsc_as_2dimlib_f25d19a4( g13183 )
        TSCP  g13183;
{
        PUSHSTACKTRACE( t14256 );
        POPSTACKTRACE( POINTER_TSCP( ffmpeg_get_frame_as_imlib( TSCP_POINTER( g13183 ) ) ) );
}

DEFTSCP( nlib_2dsc_se_2dvideo_44bfe0bf_v );
DEFCSTRING( t14258, "FFMPEG-CLOSE-VIDEO" );

TSCP  nlib_2dsc_se_2dvideo_44bfe0bf( g13187 )
        TSCP  g13187;
{
        PUSHSTACKTRACE( t14258 );
        ffmpeg_close_and_free_video( TSCP_POINTER( g13187 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( nlib_2dsc_2dframe_21_c9b06fc_v );
DEFCSTRING( t14261, "FFMPEG-NEXT-FRAME!" );

TSCP  nlib_2dsc_2dframe_21_c9b06fc( v13192 )
        TSCP  v13192;
{
        TSCP  X1;

        PUSHSTACKTRACE( t14261 );
        X1 = sc_int_tscp( ffmpeg_next_frame( TSCP_POINTER( v13192 ) ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 0 ) ) ), 
                      3 ) )  goto L14264;
        POPSTACKTRACE( BOOLEAN( NEQ( _S2CUINT( X1 ), 
                                     _S2CUINT( _TSCP( 0 ) ) ) ) );
L14264:
        if  ( TRUE( scrt2__3d_2dtwo( X1, _TSCP( 0 ) ) ) )  goto L14266;
        POPSTACKTRACE( TRUEVALUE );
L14266:
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( nlib_2dsc_2dimage_21_298475cf_v );
DEFCSTRING( t14268, "IMLIB:CONTEXT-SET-IMAGE!" );

TSCP  nlib_2dsc_2dimage_21_298475cf( g13207 )
        TSCP  g13207;
{
        PUSHSTACKTRACE( t14268 );
        imlib_context_set_image( TSCP_POINTER( g13207 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( nlib_2dsc_2dcolor_21_6efb4f17_v );
DEFCSTRING( t14271, "IMLIB:CONTEXT-SET-COLOR!" );

TSCP  nlib_2dsc_2dcolor_21_6efb4f17( g13212, 
                                     g13213, g13214, g13215 )
        TSCP  g13212, g13213, g13214, g13215;
{
        PUSHSTACKTRACE( t14271 );
        imlib_context_set_color( sc_tscp_int( g13212 ), 
                                 sc_tscp_int( g13213 ), 
                                 sc_tscp_int( g13214 ), 
                                 sc_tscp_int( g13215 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( nlib_2dsc_rgb_2fa_21_3ec1163e_v );
DEFCSTRING( t14274, "IMLIB:CONTEXT-SET-COLOR-RGB/A!" );

TSCP  nlib_2dsc_rgb_2fa_21_3ec1163e( c13223 )
        TSCP  c13223;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t14274 );
        X2 = c13223;
        if  ( AND( EQ( TSCPTAG( X2 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X2 ), VECTORTAG ) ) )  goto L14279;
        scdebug_error( c13236, 
                       c13126, CONS( X2, EMPTYLIST ) );
L14279:
        if  ( EQ( TSCPTAG( _TSCP( 0 ) ), FIXNUMTAG ) )  goto L14281;
        scdebug_error( c13236, 
                       c13239, CONS( _TSCP( 0 ), EMPTYLIST ) );
L14281:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 0 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( X2 ) ) ) )  goto L14283;
        scdebug_error( c13236, 
                       c13243, CONS( _TSCP( 0 ), EMPTYLIST ) );
L14283:
        X1 = VECTOR_ELEMENT( X2, _TSCP( 0 ) );
        X3 = c13223;
        if  ( AND( EQ( TSCPTAG( X3 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X3 ), VECTORTAG ) ) )  goto L14287;
        scdebug_error( c13236, 
                       c13126, CONS( X3, EMPTYLIST ) );
L14287:
        if  ( EQ( TSCPTAG( _TSCP( 4 ) ), FIXNUMTAG ) )  goto L14289;
        scdebug_error( c13236, 
                       c13239, CONS( _TSCP( 4 ), EMPTYLIST ) );
L14289:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 4 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( X3 ) ) ) )  goto L14291;
        scdebug_error( c13236, 
                       c13243, CONS( _TSCP( 4 ), EMPTYLIST ) );
L14291:
        X2 = VECTOR_ELEMENT( X3, _TSCP( 4 ) );
        X4 = c13223;
        if  ( AND( EQ( TSCPTAG( X4 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X4 ), VECTORTAG ) ) )  goto L14295;
        scdebug_error( c13236, 
                       c13126, CONS( X4, EMPTYLIST ) );
L14295:
        if  ( EQ( TSCPTAG( _TSCP( 8 ) ), FIXNUMTAG ) )  goto L14297;
        scdebug_error( c13236, 
                       c13239, CONS( _TSCP( 8 ), EMPTYLIST ) );
L14297:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 8 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( X4 ) ) ) )  goto L14299;
        scdebug_error( c13236, 
                       c13243, CONS( _TSCP( 8 ), EMPTYLIST ) );
L14299:
        X3 = VECTOR_ELEMENT( X4, _TSCP( 8 ) );
        if  ( AND( EQ( TSCPTAG( c13223 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( c13223 ), VECTORTAG ) )
            )  goto L14302;
        scdebug_error( c13125, 
                       c13126, CONS( c13223, EMPTYLIST ) );
L14302:
        X5 = C_FIXED( VECTOR_LENGTH( c13223 ) );
        if  ( BITAND( BITOR( _S2CINT( X5 ), 
                             _S2CINT( _TSCP( 12 ) ) ), 
                      3 ) )  goto L14306;
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( _TSCP( 12 ) ) ) )  goto L14310;
        X4 = _TSCP( 1020 );
        goto L14313;
L14306:
        if  ( FALSE( scrt2__3d_2dtwo( X5, _TSCP( 12 ) ) ) )  goto L14310;
        X4 = _TSCP( 1020 );
        goto L14313;
L14310:
        X6 = c13223;
        if  ( AND( EQ( TSCPTAG( X6 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X6 ), VECTORTAG ) ) )  goto L14316;
        scdebug_error( c13236, 
                       c13126, CONS( X6, EMPTYLIST ) );
L14316:
        if  ( EQ( TSCPTAG( _TSCP( 12 ) ), FIXNUMTAG ) )  goto L14318;
        scdebug_error( c13236, 
                       c13239, 
                       CONS( _TSCP( 12 ), EMPTYLIST ) );
L14318:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 12 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( X6 ) ) ) )  goto L14320;
        scdebug_error( c13236, 
                       c13243, 
                       CONS( _TSCP( 12 ), EMPTYLIST ) );
L14320:
        X4 = VECTOR_ELEMENT( X6, _TSCP( 12 ) );
L14313:
        POPSTACKTRACE( nlib_2dsc_2dcolor_21_6efb4f17( X1, 
                                                      X2, X3, X4 ) );
}

DEFTSCP( nlib_2dsc_drectangle_8a5856a3_v );
DEFCSTRING( t14322, "IMLIB:DRAW-RECTANGLE" );
EXTERNTSCPP( nlib_2dsc_b_3aheight_cb673bff, XAL1( TSCP ) );
EXTERNTSCP( nlib_2dsc_b_3aheight_cb673bff_v );
EXTERNTSCPP( nlib_2dsc_ib_3awidth_c7d91eee, XAL1( TSCP ) );
EXTERNTSCP( nlib_2dsc_ib_3awidth_c7d91eee_v );
EXTERNTSCPP( scrt2_max_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_max_2dtwo_v );
EXTERNTSCPP( scrt2_min_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_min_2dtwo_v );

TSCP  codetectionlib_2dsc_l13318( i13319, c14385 )
        TSCP  i13319, c14385;
{
        TSCP  X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "codetectionlib_2dsc_l13318 [inside IMLIB:DRAW-RECTA\
NGLE]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c14385, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c14385, 1 );
        X3 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c14385, 2 );
        X4 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c14385, 3 );
        X9 = DISPLAY( 3 );
        if  ( BITAND( BITOR( _S2CINT( X9 ), 
                             _S2CINT( i13319 ) ), 
                      3 ) )  goto L14388;
        X8 = _TSCP( IDIFFERENCE( _S2CINT( X9 ), 
                                 _S2CINT( i13319 ) ) );
        goto L14389;
L14388:
        X8 = scrt2__2d_2dtwo( X9, i13319 );
L14389:
        X10 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( X10 ), 
                             _S2CINT( i13319 ) ), 
                      3 ) )  goto L14391;
        X9 = _TSCP( IPLUS( _S2CINT( X10 ), 
                           _S2CINT( i13319 ) ) );
        goto L14392;
L14391:
        X9 = scrt2__2b_2dtwo( X10, i13319 );
L14392:
        if  ( BITAND( BITOR( _S2CINT( X8 ), _S2CINT( X9 ) ), 
                      3 ) )  goto L14394;
        X7 = _TSCP( IDIFFERENCE( _S2CINT( X8 ), 
                                 _S2CINT( X9 ) ) );
        goto L14395;
L14394:
        X7 = scrt2__2d_2dtwo( X8, X9 );
L14395:
        if  ( BITAND( BITOR( _S2CINT( X7 ), 
                             _S2CINT( _TSCP( -4 ) ) ), 
                      3 ) )  goto L14397;
        X6 = _TSCP( IDIFFERENCE( _S2CINT( X7 ), 
                                 _S2CINT( _TSCP( -4 ) ) ) );
        goto L14398;
L14397:
        X6 = scrt2__2d_2dtwo( X7, _TSCP( -4 ) );
L14398:
        X10 = DISPLAY( 1 );
        if  ( BITAND( BITOR( _S2CINT( X10 ), 
                             _S2CINT( i13319 ) ), 
                      3 ) )  goto L14400;
        X9 = _TSCP( IDIFFERENCE( _S2CINT( X10 ), 
                                 _S2CINT( i13319 ) ) );
        goto L14401;
L14400:
        X9 = scrt2__2d_2dtwo( X10, i13319 );
L14401:
        X11 = DISPLAY( 0 );
        if  ( BITAND( BITOR( _S2CINT( X11 ), 
                             _S2CINT( i13319 ) ), 
                      3 ) )  goto L14403;
        X10 = _TSCP( IPLUS( _S2CINT( X11 ), 
                            _S2CINT( i13319 ) ) );
        goto L14404;
L14403:
        X10 = scrt2__2b_2dtwo( X11, i13319 );
L14404:
        if  ( BITAND( BITOR( _S2CINT( X9 ), _S2CINT( X10 ) ), 
                      3 ) )  goto L14406;
        X8 = _TSCP( IDIFFERENCE( _S2CINT( X9 ), 
                                 _S2CINT( X10 ) ) );
        goto L14407;
L14406:
        X8 = scrt2__2d_2dtwo( X9, X10 );
L14407:
        if  ( BITAND( BITOR( _S2CINT( X8 ), 
                             _S2CINT( _TSCP( -4 ) ) ), 
                      3 ) )  goto L14409;
        X7 = _TSCP( IDIFFERENCE( _S2CINT( X8 ), 
                                 _S2CINT( _TSCP( -4 ) ) ) );
        goto L14410;
L14409:
        X7 = scrt2__2d_2dtwo( X8, _TSCP( -4 ) );
L14410:
        X9 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( X9 ), 
                             _S2CINT( i13319 ) ), 
                      3 ) )  goto L14412;
        X8 = _TSCP( IPLUS( _S2CINT( X9 ), 
                           _S2CINT( i13319 ) ) );
        goto L14413;
L14412:
        X8 = scrt2__2b_2dtwo( X9, i13319 );
L14413:
        X10 = DISPLAY( 0 );
        if  ( BITAND( BITOR( _S2CINT( X10 ), 
                             _S2CINT( i13319 ) ), 
                      3 ) )  goto L14415;
        X9 = _TSCP( IPLUS( _S2CINT( X10 ), 
                           _S2CINT( i13319 ) ) );
        goto L14416;
L14415:
        X9 = scrt2__2b_2dtwo( X10, i13319 );
L14416:
        imlib_image_draw_rectangle( sc_tscp_int( X9 ), 
                                    sc_tscp_int( X8 ), 
                                    sc_tscp_int( X7 ), 
                                    sc_tscp_int( X6 ) );
        X5 = FALSEVALUE;
        DISPLAY( 0 ) = X1;
        DISPLAY( 1 ) = X2;
        DISPLAY( 2 ) = X3;
        DISPLAY( 3 ) = X4;
        POPSTACKTRACE( X5 );
}

TSCP  nlib_2dsc_drectangle_8a5856a3( i13296, 
                                     x13297, 
                                     y13298, 
                                     w13299, 
                                     h13300, c13301, t13302 )
        TSCP  i13296, 
              x13297, 
              y13298, w13299, h13300, c13301, t13302;
{
        TSCP  X6, X5, X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SD3 = DISPLAY( 3 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t14322 );
        X1 = nlib_2dsc_b_3aheight_cb673bff( i13296 );
        X2 = nlib_2dsc_ib_3awidth_c7d91eee( i13296 );
        nlib_2dsc_rgb_2fa_21_3ec1163e( c13301 );
        nlib_2dsc_2dimage_21_298475cf( i13296 );
        if  ( BITAND( BITOR( _S2CINT( w13299 ), 
                             _S2CINT( _TSCP( -4 ) ) ), 
                      3 ) )  goto L14325;
        X4 = _TSCP( IPLUS( _S2CINT( w13299 ), 
                           _S2CINT( _TSCP( -4 ) ) ) );
        goto L14326;
L14325:
        X4 = scrt2__2b_2dtwo( w13299, _TSCP( -4 ) );
L14326:
        if  ( BITAND( BITOR( _S2CINT( x13297 ), 
                             _S2CINT( X4 ) ), 
                      3 ) )  goto L14328;
        X3 = _TSCP( IPLUS( _S2CINT( x13297 ), 
                           _S2CINT( X4 ) ) );
        goto L14329;
L14328:
        X3 = scrt2__2b_2dtwo( x13297, X4 );
L14329:
        if  ( BITAND( BITOR( _S2CINT( h13300 ), 
                             _S2CINT( _TSCP( -4 ) ) ), 
                      3 ) )  goto L14331;
        X5 = _TSCP( IPLUS( _S2CINT( h13300 ), 
                           _S2CINT( _TSCP( -4 ) ) ) );
        goto L14332;
L14331:
        X5 = scrt2__2b_2dtwo( h13300, _TSCP( -4 ) );
L14332:
        if  ( BITAND( BITOR( _S2CINT( y13298 ), 
                             _S2CINT( X5 ) ), 
                      3 ) )  goto L14334;
        X4 = _TSCP( IPLUS( _S2CINT( y13298 ), 
                           _S2CINT( X5 ) ) );
        goto L14335;
L14334:
        X4 = scrt2__2b_2dtwo( y13298, X5 );
L14335:
        if  ( BITAND( BITOR( _S2CINT( x13297 ), 
                             _S2CINT( t13302 ) ), 
                      3 ) )  goto L14337;
        X6 = _TSCP( IDIFFERENCE( _S2CINT( x13297 ), 
                                 _S2CINT( t13302 ) ) );
        goto L14338;
L14337:
        X6 = scrt2__2d_2dtwo( x13297, t13302 );
L14338:
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( -4 ) ) ), 
                      3 ) )  goto L14340;
        X5 = _TSCP( IDIFFERENCE( _S2CINT( X6 ), 
                                 _S2CINT( _TSCP( -4 ) ) ) );
        goto L14341;
L14340:
        X5 = scrt2__2d_2dtwo( X6, _TSCP( -4 ) );
L14341:
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 0 ) ), 
                             _S2CINT( X5 ) ), 
                      3 ) )  goto L14343;
        if  ( LTE( _S2CINT( _TSCP( 0 ) ), _S2CINT( X5 ) ) )  goto L14345;
        DISPLAY( 0 ) = _TSCP( 0 );
        goto L14344;
L14345:
        DISPLAY( 0 ) = X5;
        goto L14344;
L14343:
        DISPLAY( 0 ) = scrt2_max_2dtwo( _TSCP( 0 ), X5 );
L14344:
        if  ( BITAND( BITOR( _S2CINT( t13302 ), 
                             _S2CINT( _TSCP( -4 ) ) ), 
                      3 ) )  goto L14348;
        X6 = _TSCP( IPLUS( _S2CINT( t13302 ), 
                           _S2CINT( _TSCP( -4 ) ) ) );
        goto L14349;
L14348:
        X6 = scrt2__2b_2dtwo( t13302, _TSCP( -4 ) );
L14349:
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L14351;
        X5 = _TSCP( IPLUS( _S2CINT( X3 ), _S2CINT( X6 ) ) );
        goto L14352;
L14351:
        X5 = scrt2__2b_2dtwo( X3, X6 );
L14352:
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L14353;
        X6 = _TSCP( IDIFFERENCE( _S2CINT( X2 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L14354;
L14353:
        X6 = scrt2__2d_2dtwo( X2, _TSCP( 4 ) );
L14354:
        if  ( BITAND( BITOR( _S2CINT( X6 ), _S2CINT( X5 ) ), 
                      3 ) )  goto L14356;
        if  ( GTE( _S2CINT( X6 ), _S2CINT( X5 ) ) )  goto L14358;
        DISPLAY( 1 ) = X6;
        goto L14357;
L14358:
        DISPLAY( 1 ) = X5;
        goto L14357;
L14356:
        DISPLAY( 1 ) = scrt2_min_2dtwo( X6, X5 );
L14357:
        if  ( BITAND( BITOR( _S2CINT( y13298 ), 
                             _S2CINT( t13302 ) ), 
                      3 ) )  goto L14361;
        X6 = _TSCP( IDIFFERENCE( _S2CINT( y13298 ), 
                                 _S2CINT( t13302 ) ) );
        goto L14362;
L14361:
        X6 = scrt2__2d_2dtwo( y13298, t13302 );
L14362:
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( -4 ) ) ), 
                      3 ) )  goto L14364;
        X5 = _TSCP( IDIFFERENCE( _S2CINT( X6 ), 
                                 _S2CINT( _TSCP( -4 ) ) ) );
        goto L14365;
L14364:
        X5 = scrt2__2d_2dtwo( X6, _TSCP( -4 ) );
L14365:
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 0 ) ), 
                             _S2CINT( X5 ) ), 
                      3 ) )  goto L14367;
        if  ( LTE( _S2CINT( _TSCP( 0 ) ), _S2CINT( X5 ) ) )  goto L14369;
        DISPLAY( 2 ) = _TSCP( 0 );
        goto L14368;
L14369:
        DISPLAY( 2 ) = X5;
        goto L14368;
L14367:
        DISPLAY( 2 ) = scrt2_max_2dtwo( _TSCP( 0 ), X5 );
L14368:
        if  ( BITAND( BITOR( _S2CINT( t13302 ), 
                             _S2CINT( _TSCP( -4 ) ) ), 
                      3 ) )  goto L14372;
        X6 = _TSCP( IPLUS( _S2CINT( t13302 ), 
                           _S2CINT( _TSCP( -4 ) ) ) );
        goto L14373;
L14372:
        X6 = scrt2__2b_2dtwo( t13302, _TSCP( -4 ) );
L14373:
        if  ( BITAND( BITOR( _S2CINT( X4 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L14375;
        X5 = _TSCP( IPLUS( _S2CINT( X4 ), _S2CINT( X6 ) ) );
        goto L14376;
L14375:
        X5 = scrt2__2b_2dtwo( X4, X6 );
L14376:
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L14377;
        X6 = _TSCP( IDIFFERENCE( _S2CINT( X1 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L14378;
L14377:
        X6 = scrt2__2d_2dtwo( X1, _TSCP( 4 ) );
L14378:
        if  ( BITAND( BITOR( _S2CINT( X6 ), _S2CINT( X5 ) ), 
                      3 ) )  goto L14380;
        if  ( GTE( _S2CINT( X6 ), _S2CINT( X5 ) ) )  goto L14382;
        DISPLAY( 3 ) = X6;
        goto L14381;
L14382:
        DISPLAY( 3 ) = X5;
        goto L14381;
L14380:
        DISPLAY( 3 ) = scrt2_min_2dtwo( X6, X5 );
L14381:
        X5 = MAKEPROCEDURE( 1, 
                            0, 
                            codetectionlib_2dsc_l13318, 
                            MAKECLOSURE( EMPTYLIST, 
                                         4, 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 3 ) ) );
        qobischeme_for_2deach_2dn( X5, t13302 );
        SDVAL = i13296;
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( nlib_2dsc__2dpath_2a_49317cd6_v );
DEFCSTRING( t14419, "*DEFAULT-FONT-PATH*" );
EXTERNTSCPP( qobischeme_file_2dexists_3f, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_file_2dexists_3f_v );
EXTERNTSCPP( qobischeme_panic, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_panic_v );

TSCP  nlib_2dsc__2dpath_2a_49317cd6(  )
{
        PUSHSTACKTRACE( t14419 );
        if  ( TRUE( qobischeme_file_2dexists_3f( c13501 ) ) )  goto L14421;
        if  ( TRUE( qobischeme_file_2dexists_3f( c13502 ) ) )  goto L14423;
        if  ( TRUE( qobischeme_file_2dexists_3f( c13503 ) ) )  goto L14425;
        POPSTACKTRACE( qobischeme_panic( c13504, EMPTYLIST ) );
L14425:
        POPSTACKTRACE( c13503 );
L14423:
        POPSTACKTRACE( c13502 );
L14421:
        POPSTACKTRACE( c13501 );
}

DEFTSCP( nlib_2dsc__2dfont_21_4666cd1c_v );
DEFCSTRING( t14427, "IMLIB:CONTEXT-SET-FONT!" );

TSCP  nlib_2dsc__2dfont_21_4666cd1c( g13506 )
        TSCP  g13506;
{
        PUSHSTACKTRACE( t14427 );
        imlib_context_set_font( TSCP_POINTER( g13506 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( nlib_2dsc_ad_2dimage_fa642fa3_v );
DEFCSTRING( t14430, "IMLIB:LOAD-IMAGE" );

TSCP  nlib_2dsc_ad_2dimage_fa642fa3( g13511 )
        TSCP  g13511;
{
        PUSHSTACKTRACE( t14430 );
        POPSTACKTRACE( POINTER_TSCP( imlib_load_image( TSCP_POINTER( g13511 ) ) ) );
}

DEFTSCP( nlib_2dsc__2dfont_21_c0d5a258_v );
DEFCSTRING( t14432, "IMLIB:LOAD-FONT!" );

TSCP  nlib_2dsc__2dfont_21_c0d5a258( g13515 )
        TSCP  g13515;
{
        PUSHSTACKTRACE( t14432 );
        POPSTACKTRACE( POINTER_TSCP( imlib_load_font( TSCP_POINTER( g13515 ) ) ) );
}

DEFTSCP( nlib_2dsc_ree_2dfont_926a5a1c_v );
DEFCSTRING( t14434, "IMLIB:FREE-FONT" );

TSCP  nlib_2dsc_ree_2dfont_926a5a1c(  )
{
        PUSHSTACKTRACE( t14434 );
        imlib_free_font(  );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( nlib_2dsc_ont_2dpath_836e9e8e_v );
DEFCSTRING( t14437, "IMLIB:ADD-PATH-TO-FONT-PATH" );

TSCP  nlib_2dsc_ont_2dpath_836e9e8e( g13523 )
        TSCP  g13523;
{
        PUSHSTACKTRACE( t14437 );
        imlib_add_path_to_font_path( TSCP_POINTER( g13523 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( nlib_2dsc_ext_2ddraw_ec7a9cc9_v );
DEFCSTRING( t14440, "IMLIB:TEXT-DRAW" );

TSCP  nlib_2dsc_ext_2ddraw_ec7a9cc9( i13528, 
                                     x13529, 
                                     y13530, 
                                     t13531, c13532, f13533 )
        TSCP  i13528, 
              x13529, y13530, t13531, c13532, f13533;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t14440 );
        X1 = nlib_2dsc__2dpath_2a_49317cd6(  );
        nlib_2dsc_ont_2dpath_836e9e8e( X1 );
        X3 = CONS( f13533, EMPTYLIST );
        X2 = scrt6_format( FALSEVALUE, CONS( c13534, X3 ) );
        X1 = nlib_2dsc__2dfont_21_c0d5a258( X2 );
        nlib_2dsc__2dfont_21_4666cd1c( X1 );
        nlib_2dsc_rgb_2fa_21_3ec1163e( c13532 );
        nlib_2dsc_2dimage_21_298475cf( i13528 );
        imlib_text_draw( sc_tscp_int( x13529 ), 
                         sc_tscp_int( y13530 ), 
                         TSCP_POINTER( t13531 ) );
        POPSTACKTRACE( nlib_2dsc_ree_2dfont_926a5a1c(  ) );
}

DEFTSCP( nlib_2dsc__2ddecache_e023ee48_v );
DEFCSTRING( t14443, "IMLIB:FREE-IMAGE-AND-DECACHE" );

TSCP  nlib_2dsc__2ddecache_e023ee48( i13545 )
        TSCP  i13545;
{
        PUSHSTACKTRACE( t14443 );
        nlib_2dsc_2dimage_21_298475cf( i13545 );
        imlib_free_image_and_decache(  );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( nlib_2dsc_ve_2dimage_497f8fa_v );
DEFCSTRING( t14446, "IMLIB:SAVE-IMAGE" );

TSCP  nlib_2dsc_ve_2dimage_497f8fa( i13551, f13552 )
        TSCP  i13551, f13552;
{
        PUSHSTACKTRACE( t14446 );
        nlib_2dsc_2dimage_21_298475cf( i13551 );
        imlib_save_image( TSCP_POINTER( f13552 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( nlib_2dsc_b_3aheight_cb673bff_v );
DEFCSTRING( t14449, "IMLIB:HEIGHT" );

TSCP  nlib_2dsc_b_3aheight_cb673bff( i13559 )
        TSCP  i13559;
{
        PUSHSTACKTRACE( t14449 );
        nlib_2dsc_2dimage_21_298475cf( i13559 );
        POPSTACKTRACE( sc_int_tscp( imlib_image_get_height(  ) ) );
}

DEFTSCP( nlib_2dsc_ib_3awidth_c7d91eee_v );
DEFCSTRING( t14451, "IMLIB:WIDTH" );

TSCP  nlib_2dsc_ib_3awidth_c7d91eee( i13564 )
        TSCP  i13564;
{
        PUSHSTACKTRACE( t14451 );
        nlib_2dsc_2dimage_21_298475cf( i13564 );
        POPSTACKTRACE( sc_int_tscp( imlib_image_get_width(  ) ) );
}

DEFTSCP( nlib_2dsc_ib_3aclone_a7aeb619_v );
DEFCSTRING( t14453, "IMLIB:CLONE" );

TSCP  nlib_2dsc_ib_3aclone_a7aeb619( i13569 )
        TSCP  i13569;
{
        PUSHSTACKTRACE( t14453 );
        nlib_2dsc_2dimage_21_298475cf( i13569 );
        POPSTACKTRACE( POINTER_TSCP( imlib_clone_image(  ) ) );
}

DEFTSCP( nlib_2dsc_ead_2donly_f1443e22_v );
DEFCSTRING( t14455, "IMLIB:DATA-PTR-READ-ONLY" );

TSCP  nlib_2dsc_ead_2donly_f1443e22( i13574 )
        TSCP  i13574;
{
        PUSHSTACKTRACE( t14455 );
        nlib_2dsc_2dimage_21_298475cf( i13574 );
        POPSTACKTRACE( POINTER_TSCP( imlib_image_get_data_for_reading_only(  ) ) );
}

void pregexp__init();
void parser__init();
void scrt6__init();
void scrt4__init();
void scrt3__init();
void scrt2__init();
void scdebug__init();
void scrt1__init();
void qobischeme__init();
void toollib_2dmatlab__init();

static void  init_modules( compiler_version )
        char *compiler_version;
{
        pregexp__init();
        parser__init();
        scrt6__init();
        scrt4__init();
        scrt3__init();
        scrt2__init();
        scdebug__init();
        scrt1__init();
        qobischeme__init();
        toollib_2dmatlab__init();
        MAXDISPLAY( 4 );
}

void  codetectionlib_2dsc__init()
{
        static int  init = 0;
        if  (init)  return;
        init = 1;
        INITHEAP( 0, 0, 0, 0 );
        init_constants();
        init_modules( "(codetectionlib_2dsc SCHEME->C COMPILER 15mar93jfb)" );
        sc_segv__handlers();
        INITIALIZEVAR( t13709, 
                       ADR( nlib_2dsc_sc_2d1_2d0_eb7e557_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      nlib_2dsc_sc_2d1_2d0_eb7e557, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13711, 
                       ADR( nlib_2dsc_sc_2d3_2d0_7477b637_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      nlib_2dsc_sc_2d3_2d0_7477b637, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13713, 
                       ADR( nlib_2dsc_sc_2d5_2d0_fb374397_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      nlib_2dsc_sc_2d5_2d0_fb374397, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13715, 
                       ADR( nlib_2dsc_sc_2d7_2d0_81f710f7_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      nlib_2dsc_sc_2d7_2d0_81f710f7, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13717, 
                       ADR( codetectionlib_2dsc_o_v ), 
                       MAKEPROCEDURE( 2, 
                                      1, 
                                      codetectionlib_2dsc_o, EMPTYLIST ) );
        INITIALIZEVAR( t13724, 
                       ADR( codetectionlib_2dsc_zip_v ), 
                       MAKEPROCEDURE( 2, 
                                      1, 
                                      codetectionlib_2dsc_zip, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13781, 
                       ADR( nlib_2dsc_dpositions_88b95f2f_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc_dpositions_88b95f2f, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13787, 
                       ADR( nlib_2dsc_ll_2dpairs_15170d9a_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_ll_2dpairs_15170d9a, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13814, 
                       ADR( codetectionlib_2dsc_median_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetectionlib_2dsc_median, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13829, 
                       ADR( nlib_2dsc_ent_2dtime_b0674773_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      nlib_2dsc_ent_2dtime_b0674773, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13849, 
                       ADR( codetectionlib_2dsc_hostname_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      codetectionlib_2dsc_hostname, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13853, 
                       ADR( nlib_2dsc_and_2dtime_940355d5_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      nlib_2dsc_and_2dtime_940355d5, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13857, 
                       ADR( nlib_2dsc_ist_2dmean_b3ce463_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_ist_2dmean_b3ce463, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13889, 
                       ADR( codetectionlib_2dsc_randomize_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      codetectionlib_2dsc_randomize, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13896, 
                       ADR( nlib_2dsc_stic_2dmap_a3e1700b_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc_stic_2dmap_a3e1700b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13902, 
                       ADR( nlib_2dsc_sublist_3f_9e75a600_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc_sublist_3f_9e75a600, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13925, 
                       ADR( codetectionlib_2dsc_maximump_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      codetectionlib_2dsc_maximump, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13953, 
                       ADR( nlib_2dsc_flatten_2a_dee05d56_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_flatten_2a_dee05d56, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13968, 
                       ADR( nlib_2dsc_of_2dlists_ff272f8f_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_of_2dlists_ff272f8f, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13970, 
                       ADR( nlib_2dsc_d_3ematrix_eaa6578d_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_d_3ematrix_eaa6578d, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13988, 
                       ADR( nlib_2dsc_lit_2dinto_41bd5faf_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc_lit_2dinto_41bd5faf, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14033, 
                       ADR( codetectionlib_2dsc_take_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      codetectionlib_2dsc_take, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14035, 
                       ADR( codetectionlib_2dsc_drop_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      codetectionlib_2dsc_drop, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14037, 
                       ADR( codetectionlib_2dsc_split_2dn_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      codetectionlib_2dsc_split_2dn, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14041, 
                       ADR( codetectionlib_2dsc_join_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetectionlib_2dsc_join, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14043, 
                       ADR( codetectionlib_2dsc_unzip_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetectionlib_2dsc_unzip, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14065, 
                       ADR( nlib_2dsc_dnecessary_994e4d49_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      nlib_2dsc_dnecessary_994e4d49, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14081, 
                       ADR( nlib_2dsc_2dpossible_ced25962_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc_2dpossible_ced25962, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14092, 
                       ADR( nlib_2dsc_2dpick_2dm_2507cf0b_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc_2dpick_2dm_2507cf0b, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14127, 
                       ADR( nlib_2dsc_devery_2dn_da212f5_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc_devery_2dn_da212f5, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14140, 
                       ADR( codetectionlib_2dsc_middle_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetectionlib_2dsc_middle, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14153, 
                       ADR( nlib_2dsc_of_2dlists_660f857e_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_of_2dlists_660f857e, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14155, 
                       ADR( nlib_2dsc_2dpick_2dm_2b0fa3e_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc_2dpick_2dm_2b0fa3e, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14191, 
                       ADR( nlib_2dsc_group_2dby_96ef2b55_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc_group_2dby_96ef2b55, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14195, 
                       ADR( nlib_2dsc_2dtruncate_eff8e119_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc_2dtruncate_eff8e119, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14203, 
                       ADR( codetectionlib_2dsc_sigmoid_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      codetectionlib_2dsc_sigmoid, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14228, 
                       ADR( nlib_2dsc__3esplines_183d177c_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc__3esplines_183d177c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14254, 
                       ADR( nlib_2dsc_en_2dvideo_9771a33c_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_en_2dvideo_9771a33c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14256, 
                       ADR( nlib_2dsc_as_2dimlib_f25d19a4_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_as_2dimlib_f25d19a4, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14258, 
                       ADR( nlib_2dsc_se_2dvideo_44bfe0bf_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_se_2dvideo_44bfe0bf, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14261, 
                       ADR( nlib_2dsc_2dframe_21_c9b06fc_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_2dframe_21_c9b06fc, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14268, 
                       ADR( nlib_2dsc_2dimage_21_298475cf_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_2dimage_21_298475cf, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14271, 
                       ADR( nlib_2dsc_2dcolor_21_6efb4f17_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      nlib_2dsc_2dcolor_21_6efb4f17, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14274, 
                       ADR( nlib_2dsc_rgb_2fa_21_3ec1163e_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_rgb_2fa_21_3ec1163e, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14322, 
                       ADR( nlib_2dsc_drectangle_8a5856a3_v ), 
                       MAKEPROCEDURE( 7, 
                                      0, 
                                      nlib_2dsc_drectangle_8a5856a3, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14419, 
                       ADR( nlib_2dsc__2dpath_2a_49317cd6_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      nlib_2dsc__2dpath_2a_49317cd6, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14427, 
                       ADR( nlib_2dsc__2dfont_21_4666cd1c_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc__2dfont_21_4666cd1c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14430, 
                       ADR( nlib_2dsc_ad_2dimage_fa642fa3_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_ad_2dimage_fa642fa3, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14432, 
                       ADR( nlib_2dsc__2dfont_21_c0d5a258_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc__2dfont_21_c0d5a258, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14434, 
                       ADR( nlib_2dsc_ree_2dfont_926a5a1c_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      nlib_2dsc_ree_2dfont_926a5a1c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14437, 
                       ADR( nlib_2dsc_ont_2dpath_836e9e8e_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_ont_2dpath_836e9e8e, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14440, 
                       ADR( nlib_2dsc_ext_2ddraw_ec7a9cc9_v ), 
                       MAKEPROCEDURE( 6, 
                                      0, 
                                      nlib_2dsc_ext_2ddraw_ec7a9cc9, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14443, 
                       ADR( nlib_2dsc__2ddecache_e023ee48_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc__2ddecache_e023ee48, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14446, 
                       ADR( nlib_2dsc_ve_2dimage_497f8fa_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      nlib_2dsc_ve_2dimage_497f8fa, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14449, 
                       ADR( nlib_2dsc_b_3aheight_cb673bff_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_b_3aheight_cb673bff, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14451, 
                       ADR( nlib_2dsc_ib_3awidth_c7d91eee_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_ib_3awidth_c7d91eee, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14453, 
                       ADR( nlib_2dsc_ib_3aclone_a7aeb619_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_ib_3aclone_a7aeb619, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t14455, 
                       ADR( nlib_2dsc_ead_2donly_f1443e22_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      nlib_2dsc_ead_2donly_f1443e22, 
                                      EMPTYLIST ) );
        return;
}
