
/* SCHEME->C */

#include <objects.h>

void easy_2dffi__init();
DEFCSTRING( t12396, "Argument is not a SYMBOL: ~s" );
DEFSTATICTSCP( c12314 );
DEFSTATICTSCP( c12313 );
DEFCSTRING( t12397, "Argument(s) not CHAR: ~s ~s" );
DEFSTATICTSCP( c12307 );
DEFSTATICTSCP( c12306 );
DEFSTATICTSCP( c12166 );
DEFSTATICTSCP( c12162 );
DEFSTATICTSCP( c12025 );
DEFCSTRING( t12398, "Index is not in bounds: ~s" );
DEFSTATICTSCP( c12020 );
DEFCSTRING( t12399, "Argument is not an INTEGER: ~s" );
DEFSTATICTSCP( c12016 );
DEFCSTRING( t12400, "Argument is not a VECTOR: ~s" );
DEFSTATICTSCP( c12013 );
DEFSTATICTSCP( c12012 );
DEFCSTRING( t12401, "Not a list or vector" );
DEFSTATICTSCP( c11990 );

static void  init_constants()
{
        c12314 = CSTRING_TSCP( t12396 );
        CONSTANTEXP( ADR( c12314 ) );
        c12313 = STRINGTOSYMBOL( CSTRING_TSCP( "SYMBOL->STRING" ) );
        CONSTANTEXP( ADR( c12313 ) );
        c12307 = CSTRING_TSCP( t12397 );
        CONSTANTEXP( ADR( c12307 ) );
        c12306 = STRINGTOSYMBOL( CSTRING_TSCP( "CHAR=?" ) );
        CONSTANTEXP( ADR( c12306 ) );
        c12166 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR" ) );
        CONSTANTEXP( ADR( c12166 ) );
        c12162 = STRINGTOSYMBOL( CSTRING_TSCP( "LIST" ) );
        CONSTANTEXP( ADR( c12162 ) );
        c12025 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR-LENGTH" ) );
        CONSTANTEXP( ADR( c12025 ) );
        c12020 = CSTRING_TSCP( t12398 );
        CONSTANTEXP( ADR( c12020 ) );
        c12016 = CSTRING_TSCP( t12399 );
        CONSTANTEXP( ADR( c12016 ) );
        c12013 = CSTRING_TSCP( t12400 );
        CONSTANTEXP( ADR( c12013 ) );
        c12012 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR-REF" ) );
        CONSTANTEXP( ADR( c12012 ) );
        c11990 = CSTRING_TSCP( t12401 );
        CONSTANTEXP( ADR( c11990 ) );
}

DEFTSCP( asy_2dffi_fi_2d1_2d0_8506d0f9_v );
DEFCSTRING( t12402, "gensym-easy_2dffi-1-0" );

TSCP  asy_2dffi_fi_2d1_2d0_8506d0f9(  )
{
        PUSHSTACKTRACE( t12402 );
        POPSTACKTRACE( 0 );}
  #include<stddef.h>
int gensym_easy_2dffi_2_0(){ return 1;gensym_easy_2dffi_2_0( );
}

DEFTSCP( asy_2dffi_fi_2d3_2d0_ffc68399_v );
DEFCSTRING( t12404, "gensym-easy_2dffi-3-0" );

TSCP  asy_2dffi_fi_2d3_2d0_ffc68399(  )
{
        PUSHSTACKTRACE( t12404 );
        POPSTACKTRACE( 0 );}
  #include<stdlib.h>
int gensym_easy_2dffi_4_0(){ return 1;gensym_easy_2dffi_4_0( );
}

DEFTSCP( asy_2dffi_fi_2d5_2d0_70867639_v );
DEFCSTRING( t12406, "gensym-easy_2dffi-5-0" );

TSCP  asy_2dffi_fi_2d5_2d0_70867639(  )
{
        PUSHSTACKTRACE( t12406 );
        POPSTACKTRACE( 0 );}
  #include<string.h>
int gensym_easy_2dffi_6_0(){ return 1;gensym_easy_2dffi_6_0( );
}

DEFTSCP( asy_2dffi_i_3ato_2dc_4737233d_v );
DEFCSTRING( t12408, "EASY-FFI:TO-C" );
EXTERNTSCPP( scrt2__3d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3d_2dtwo_v );
EXTERNTSCPP( scrt1_list_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt1_list_3f_v );
EXTERNTSCPP( scrt1_length, XAL1( TSCP ) );
EXTERNTSCP( scrt1_length_v );
EXTERNTSCP( scrt4_c_2dsizeof_2ds2cuint_v );
EXTERNTSCPP( scrt2__2a_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2a_2dtwo_v );
EXTERNTSCPP( obischeme__2dindexed_d1069d4, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( obischeme__2dindexed_d1069d4_v );
EXTERNTSCPP( scrt4_c_2ds2cuint_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ds2cuint_2dset_21_v );
EXTERNTSCPP( easy_2dffi_l11974, XAL2( TSCP, TSCP ) );
EXTERNTSCPP( scrt2__2d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2d_2dtwo_v );

TSCP  easy_2dffi_l12042( x12043, i12044, c12430 )
        TSCP  x12043, i12044, c12430;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l12042 [inside EASY-FFI:TO-C]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12430, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12430, 1 );
        X3 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12430, 2 );
        X4 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c12430, 3 );
        X7 = scrt4_c_2dsizeof_2ds2cuint_v;
        if  ( BITAND( BITOR( _S2CINT( i12044 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L12433;
        X6 = _TSCP( ITIMES( FIXED_C( i12044 ), 
                            _S2CINT( X7 ) ) );
        goto L12434;
L12433:
        X6 = scrt2__2a_2dtwo( i12044, X7 );
L12434:
        X9 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( X9 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12436;
        X8 = _TSCP( IDIFFERENCE( _S2CINT( X9 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L12437;
L12436:
        X8 = scrt2__2d_2dtwo( X9, _TSCP( 4 ) );
L12437:
        X7 = easy_2dffi_l11974( X8, x12043 );
        X5 = scrt4_c_2ds2cuint_2dset_21( DISPLAY( 4 ), 
                                         X6, X7 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        DISPLAY( 2 ) = X3;
        DISPLAY( 4 ) = X4;
        POPSTACKTRACE( X5 );
}

EXTERNTSCPP( scdebug_error, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scdebug_error_v );
EXTERNTSCPP( qobischeme_for_2deach_2dn, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_for_2deach_2dn_v );

TSCP  easy_2dffi_l11993( i11994, c12447 )
        TSCP  i11994, c12447;
{
        TSCP  X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l11993 [inside EASY-FFI:TO-C]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12447, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12447, 1 );
        X3 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c12447, 2 );
        X4 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12447, 3 );
        X5 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c12447, 4 );
        X8 = scrt4_c_2dsizeof_2ds2cuint_v;
        if  ( BITAND( BITOR( _S2CINT( i11994 ), 
                             _S2CINT( X8 ) ), 
                      3 ) )  goto L12450;
        X7 = _TSCP( ITIMES( FIXED_C( i11994 ), 
                            _S2CINT( X8 ) ) );
        goto L12451;
L12450:
        X7 = scrt2__2a_2dtwo( i11994, X8 );
L12451:
        X10 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( X10 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12453;
        X9 = _TSCP( IDIFFERENCE( _S2CINT( X10 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L12454;
L12453:
        X9 = scrt2__2d_2dtwo( X10, _TSCP( 4 ) );
L12454:
        X11 = DISPLAY( 3 );
        if  ( AND( EQ( TSCPTAG( X11 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X11 ), VECTORTAG ) )
            )  goto L12456;
        scdebug_error( c12012, 
                       c12013, CONS( X11, EMPTYLIST ) );
L12456:
        if  ( EQ( TSCPTAG( i11994 ), FIXNUMTAG ) )  goto L12458;
        scdebug_error( c12012, 
                       c12016, CONS( i11994, EMPTYLIST ) );
L12458:
        if  ( LT( _S2CUINT( FIXED_C( i11994 ) ), 
                  _S2CUINT( VECTOR_LENGTH( X11 ) ) ) )  goto L12460;
        scdebug_error( c12012, 
                       c12020, CONS( i11994, EMPTYLIST ) );
L12460:
        X10 = VECTOR_ELEMENT( X11, i11994 );
        X8 = easy_2dffi_l11974( X9, X10 );
        X6 = scrt4_c_2ds2cuint_2dset_21( DISPLAY( 4 ), 
                                         X7, X8 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        DISPLAY( 3 ) = X3;
        DISPLAY( 2 ) = X4;
        DISPLAY( 4 ) = X5;
        POPSTACKTRACE( X6 );
}

EXTERNTSCPP( qobischeme_panic, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_panic_v );

TSCP  easy_2dffi_l12109( x12110, i12111, c12471 )
        TSCP  x12110, i12111, c12471;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l12109 [inside EASY-FFI:TO-C]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12471, 0 );
        X2 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c12471, 1 );
        X3 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12471, 2 );
        X7 = DISPLAY( 1 );
        if  ( BITAND( BITOR( _S2CINT( i12111 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L12474;
        X6 = _TSCP( ITIMES( FIXED_C( i12111 ), 
                            _S2CINT( X7 ) ) );
        goto L12475;
L12474:
        X6 = scrt2__2a_2dtwo( i12111, X7 );
L12475:
        X5 = DISPLAY( 0 );
        X5 = UNKNOWNCALL( X5, 3 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( DISPLAY( 4 ), 
                                          X6, 
                                          x12110, 
                                          PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 1 ) = X1;
        DISPLAY( 4 ) = X2;
        DISPLAY( 0 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  easy_2dffi_l12071( i12072, c12485 )
        TSCP  i12072, c12485;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l12071 [inside EASY-FFI:TO-C]" );
        X1 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c12485, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12485, 1 );
        X3 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c12485, 2 );
        X4 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12485, 3 );
        X8 = DISPLAY( 1 );
        if  ( BITAND( BITOR( _S2CINT( i12072 ), 
                             _S2CINT( X8 ) ), 
                      3 ) )  goto L12488;
        X7 = _TSCP( ITIMES( FIXED_C( i12072 ), 
                            _S2CINT( X8 ) ) );
        goto L12489;
L12488:
        X7 = scrt2__2a_2dtwo( i12072, X8 );
L12489:
        X9 = DISPLAY( 3 );
        if  ( AND( EQ( TSCPTAG( X9 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X9 ), VECTORTAG ) ) )  goto L12491;
        scdebug_error( c12012, 
                       c12013, CONS( X9, EMPTYLIST ) );
L12491:
        if  ( EQ( TSCPTAG( i12072 ), FIXNUMTAG ) )  goto L12493;
        scdebug_error( c12012, 
                       c12016, CONS( i12072, EMPTYLIST ) );
L12493:
        if  ( LT( _S2CUINT( FIXED_C( i12072 ) ), 
                  _S2CUINT( VECTOR_LENGTH( X9 ) ) ) )  goto L12495;
        scdebug_error( c12012, 
                       c12020, CONS( i12072, EMPTYLIST ) );
L12495:
        X8 = VECTOR_ELEMENT( X9, i12072 );
        X6 = DISPLAY( 0 );
        X6 = UNKNOWNCALL( X6, 3 );
        X5 = VIA( PROCEDURE_CODE( X6 ) )( DISPLAY( 4 ), 
                                          X7, 
                                          X8, 
                                          PROCEDURE_CLOSURE( X6 ) );
        DISPLAY( 3 ) = X1;
        DISPLAY( 1 ) = X2;
        DISPLAY( 4 ) = X3;
        DISPLAY( 0 ) = X4;
        POPSTACKTRACE( X5 );
}

TSCP  easy_2dffi_l11974( n11976, x11977 )
        TSCP  n11976, x11977;
{
        TSCP  X4, X3, X2, X1;
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SD3 = DISPLAY( 3 );
        TSCP  SD4 = DISPLAY( 4 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "LOOP [inside EASY-FFI:TO-C]" );
        DISPLAY( 2 ) = n11976;
        DISPLAY( 3 ) = x11977;
        X1 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12416;
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( _TSCP( 4 ) ) ) )  goto L12420;
        goto L12421;
L12416:
        if  ( TRUE( scrt2__3d_2dtwo( X1, _TSCP( 4 ) ) ) )  goto L12420;
L12421:
        if  ( FALSE( scrt1_list_3f( DISPLAY( 3 ) ) ) )  goto L12424;
        X2 = scrt1_length( DISPLAY( 3 ) );
        X3 = scrt4_c_2dsizeof_2ds2cuint_v;
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L12427;
        X1 = _TSCP( ITIMES( FIXED_C( X2 ), _S2CINT( X3 ) ) );
        goto L12428;
L12427:
        X1 = scrt2__2a_2dtwo( X2, X3 );
L12428:
        DISPLAY( 4 ) = POINTER_TSCP( malloc( TSCP_S2CUINT( X1 ) ) );
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            easy_2dffi_l12042, 
                            MAKECLOSURE( EMPTYLIST, 
                                         4, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 4 ) ) );
        obischeme__2dindexed_d1069d4( X1, DISPLAY( 3 ) );
        SDVAL = DISPLAY( 4 );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
L12424:
        if  ( NOT( AND( EQ( TSCPTAG( DISPLAY( 3 ) ), 
                            EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( DISPLAY( 3 ) ), 
                            VECTORTAG ) ) ) )  goto L12438;
        X2 = scrt4_c_2dsizeof_2ds2cuint_v;
        X4 = DISPLAY( 3 );
        if  ( AND( EQ( TSCPTAG( X4 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X4 ), VECTORTAG ) ) )  goto L12441;
        scdebug_error( c12025, 
                       c12013, CONS( X4, EMPTYLIST ) );
L12441:
        X3 = C_FIXED( VECTOR_LENGTH( X4 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L12444;
        X1 = _TSCP( ITIMES( FIXED_C( X3 ), _S2CINT( X2 ) ) );
        goto L12445;
L12444:
        X1 = scrt2__2a_2dtwo( X3, X2 );
L12445:
        DISPLAY( 4 ) = POINTER_TSCP( malloc( TSCP_S2CUINT( X1 ) ) );
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            easy_2dffi_l11993, 
                            MAKECLOSURE( EMPTYLIST, 
                                         5, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 4 ) ) );
        X3 = DISPLAY( 3 );
        if  ( AND( EQ( TSCPTAG( X3 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X3 ), VECTORTAG ) ) )  goto L12463;
        scdebug_error( c12025, 
                       c12013, CONS( X3, EMPTYLIST ) );
L12463:
        X2 = C_FIXED( VECTOR_LENGTH( X3 ) );
        qobischeme_for_2deach_2dn( X1, X2 );
        SDVAL = DISPLAY( 4 );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
L12438:
        SDVAL = qobischeme_panic( c11990, EMPTYLIST );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
L12420:
        if  ( FALSE( scrt1_list_3f( DISPLAY( 3 ) ) ) )  goto L12465;
        X2 = scrt1_length( DISPLAY( 3 ) );
        X3 = DISPLAY( 1 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X3 ) ), 
                      3 ) )  goto L12468;
        X1 = _TSCP( ITIMES( FIXED_C( X2 ), _S2CINT( X3 ) ) );
        goto L12469;
L12468:
        X1 = scrt2__2a_2dtwo( X2, X3 );
L12469:
        DISPLAY( 4 ) = POINTER_TSCP( malloc( TSCP_S2CUINT( X1 ) ) );
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            easy_2dffi_l12109, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 0 ) ) );
        obischeme__2dindexed_d1069d4( X1, DISPLAY( 3 ) );
        SDVAL = DISPLAY( 4 );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
L12465:
        if  ( NOT( AND( EQ( TSCPTAG( DISPLAY( 3 ) ), 
                            EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( DISPLAY( 3 ) ), 
                            VECTORTAG ) ) ) )  goto L12476;
        X2 = DISPLAY( 1 );
        X4 = DISPLAY( 3 );
        if  ( AND( EQ( TSCPTAG( X4 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X4 ), VECTORTAG ) ) )  goto L12479;
        scdebug_error( c12025, 
                       c12013, CONS( X4, EMPTYLIST ) );
L12479:
        X3 = C_FIXED( VECTOR_LENGTH( X4 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L12482;
        X1 = _TSCP( ITIMES( FIXED_C( X3 ), _S2CINT( X2 ) ) );
        goto L12483;
L12482:
        X1 = scrt2__2a_2dtwo( X3, X2 );
L12483:
        DISPLAY( 4 ) = POINTER_TSCP( malloc( TSCP_S2CUINT( X1 ) ) );
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            easy_2dffi_l12071, 
                            MAKECLOSURE( EMPTYLIST, 
                                         4, 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 0 ) ) );
        X3 = DISPLAY( 3 );
        if  ( AND( EQ( TSCPTAG( X3 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X3 ), VECTORTAG ) ) )  goto L12498;
        scdebug_error( c12025, 
                       c12013, CONS( X3, EMPTYLIST ) );
L12498:
        X2 = C_FIXED( VECTOR_LENGTH( X3 ) );
        qobischeme_for_2deach_2dn( X1, X2 );
        SDVAL = DISPLAY( 4 );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
L12476:
        SDVAL = qobischeme_panic( c11990, EMPTYLIST );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
}

TSCP  easy_2dffi_l11967( n11968, x11969, c12410 )
        TSCP  n11968, x11969, c12410;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l11967 [inside EASY-FFI:TO-C]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12410, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12410, 1 );
        X3 = easy_2dffi_l11974( n11968, x11969 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        POPSTACKTRACE( X3 );
}

TSCP  asy_2dffi_i_3ato_2dc_4737233d( c11965, c11966 )
        TSCP  c11965, c11966;
{
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12408 );
        DISPLAY( 0 ) = c11965;
        DISPLAY( 1 ) = c11966;
        SDVAL = MAKEPROCEDURE( 2, 
                               0, 
                               easy_2dffi_l11967, 
                               MAKECLOSURE( EMPTYLIST, 
                                            2, 
                                            DISPLAY( 1 ), 
                                            DISPLAY( 0 ) ) );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( asy_2dffi_3afrom_2dc_d15f4f72_v );
DEFCSTRING( t12500, "EASY-FFI:FROM-C" );
EXTERNTSCPP( qobischeme_first, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_first_v );
EXTERNTSCPP( qobischeme_map_2dn, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dn_v );
EXTERNTSCPP( easy_2dffi_l12143, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCPP( qobischeme_rest, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_rest_v );
EXTERNTSCPP( scrt4_c_2ds2cuint_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ds2cuint_2dref_v );

TSCP  easy_2dffi_l12175( i12176, c12519 )
        TSCP  i12176, c12519;
{
        TSCP  X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l12175 [inside EASY-FFI:FROM-C]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12519, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12519, 1 );
        X3 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c12519, 2 );
        X4 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c12519, 3 );
        X5 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12519, 4 );
        X7 = qobischeme_rest( DISPLAY( 2 ) );
        X8 = qobischeme_rest( DISPLAY( 3 ) );
        X11 = scrt4_c_2dsizeof_2ds2cuint_v;
        if  ( BITAND( BITOR( _S2CINT( i12176 ), 
                             _S2CINT( X11 ) ), 
                      3 ) )  goto L12522;
        X10 = _TSCP( ITIMES( FIXED_C( i12176 ), 
                             _S2CINT( X11 ) ) );
        goto L12523;
L12522:
        X10 = scrt2__2a_2dtwo( i12176, X11 );
L12523:
        X9 = scrt4_c_2ds2cuint_2dref( DISPLAY( 4 ), X10 );
        X6 = easy_2dffi_l12143( X7, X8, X9 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        DISPLAY( 4 ) = X3;
        DISPLAY( 3 ) = X4;
        DISPLAY( 2 ) = X5;
        POPSTACKTRACE( X6 );
}

EXTERNTSCPP( qobischeme_map_2dn_2dvector, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dn_2dvector_v );

TSCP  easy_2dffi_l12167( i12168, c12526 )
        TSCP  i12168, c12526;
{
        TSCP  X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l12167 [inside EASY-FFI:FROM-C]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12526, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12526, 1 );
        X3 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c12526, 2 );
        X4 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c12526, 3 );
        X5 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12526, 4 );
        X7 = qobischeme_rest( DISPLAY( 2 ) );
        X8 = qobischeme_rest( DISPLAY( 3 ) );
        X11 = scrt4_c_2dsizeof_2ds2cuint_v;
        if  ( BITAND( BITOR( _S2CINT( i12168 ), 
                             _S2CINT( X11 ) ), 
                      3 ) )  goto L12529;
        X10 = _TSCP( ITIMES( FIXED_C( i12168 ), 
                             _S2CINT( X11 ) ) );
        goto L12530;
L12529:
        X10 = scrt2__2a_2dtwo( i12168, X11 );
L12530:
        X9 = scrt4_c_2ds2cuint_2dref( DISPLAY( 4 ), X10 );
        X6 = easy_2dffi_l12143( X7, X8, X9 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        DISPLAY( 4 ) = X3;
        DISPLAY( 3 ) = X4;
        DISPLAY( 2 ) = X5;
        POPSTACKTRACE( X6 );
}

TSCP  easy_2dffi_l12199( i12200, c12534 )
        TSCP  i12200, c12534;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l12199 [inside EASY-FFI:FROM-C]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12534, 0 );
        X2 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c12534, 1 );
        X3 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12534, 2 );
        X7 = DISPLAY( 1 );
        if  ( BITAND( BITOR( _S2CINT( i12200 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L12537;
        X6 = _TSCP( ITIMES( FIXED_C( i12200 ), 
                            _S2CINT( X7 ) ) );
        goto L12538;
L12537:
        X6 = scrt2__2a_2dtwo( i12200, X7 );
L12538:
        X5 = DISPLAY( 0 );
        X5 = UNKNOWNCALL( X5, 2 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( DISPLAY( 4 ), 
                                          X6, 
                                          PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 1 ) = X1;
        DISPLAY( 4 ) = X2;
        DISPLAY( 0 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  easy_2dffi_l12191( i12192, c12541 )
        TSCP  i12192, c12541;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l12191 [inside EASY-FFI:FROM-C]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12541, 0 );
        X2 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c12541, 1 );
        X3 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12541, 2 );
        X7 = DISPLAY( 1 );
        if  ( BITAND( BITOR( _S2CINT( i12192 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L12544;
        X6 = _TSCP( ITIMES( FIXED_C( i12192 ), 
                            _S2CINT( X7 ) ) );
        goto L12545;
L12544:
        X6 = scrt2__2a_2dtwo( i12192, X7 );
L12545:
        X5 = DISPLAY( 0 );
        X5 = UNKNOWNCALL( X5, 2 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( DISPLAY( 4 ), 
                                          X6, 
                                          PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 1 ) = X1;
        DISPLAY( 4 ) = X2;
        DISPLAY( 0 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  easy_2dffi_l12143( n12145, t12146, v12147 )
        TSCP  n12145, t12146, v12147;
{
        TSCP  X3, X2, X1;
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SD3 = DISPLAY( 3 );
        TSCP  SD4 = DISPLAY( 4 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "LOOP [inside EASY-FFI:FROM-C]" );
        DISPLAY( 2 ) = n12145;
        DISPLAY( 3 ) = t12146;
        DISPLAY( 4 ) = v12147;
        X1 = scrt1_length( DISPLAY( 2 ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12508;
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( _TSCP( 4 ) ) ) )  goto L12512;
        goto L12513;
L12508:
        if  ( TRUE( scrt2__3d_2dtwo( X1, _TSCP( 4 ) ) ) )  goto L12512;
L12513:
        X1 = qobischeme_first( DISPLAY( 3 ) );
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c12162 ) ) )  goto L12517;
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            easy_2dffi_l12175, 
                            MAKECLOSURE( EMPTYLIST, 
                                         5, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 2 ) ) );
        X3 = qobischeme_first( DISPLAY( 2 ) );
        SDVAL = qobischeme_map_2dn( X2, X3 );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
L12517:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c12166 ) ) )  goto L12524;
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            easy_2dffi_l12167, 
                            MAKECLOSURE( EMPTYLIST, 
                                         5, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 3 ), 
                                         DISPLAY( 2 ) ) );
        X3 = qobischeme_first( DISPLAY( 2 ) );
        SDVAL = qobischeme_map_2dn_2dvector( X2, X3 );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
L12524:
        SDVAL = qobischeme_panic( c11990, EMPTYLIST );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
L12512:
        X1 = qobischeme_first( DISPLAY( 3 ) );
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c12162 ) ) )  goto L12532;
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            easy_2dffi_l12199, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 0 ) ) );
        X3 = qobischeme_first( DISPLAY( 2 ) );
        SDVAL = qobischeme_map_2dn( X2, X3 );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
L12532:
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( c12166 ) ) )  goto L12539;
        X2 = MAKEPROCEDURE( 1, 
                            0, 
                            easy_2dffi_l12191, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 4 ), 
                                         DISPLAY( 0 ) ) );
        X3 = qobischeme_first( DISPLAY( 2 ) );
        SDVAL = qobischeme_map_2dn_2dvector( X2, X3 );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
L12539:
        SDVAL = qobischeme_panic( c11990, EMPTYLIST );
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        POPSTACKTRACE( SDVAL );
}

TSCP  easy_2dffi_l12134( n12135, t12136, v12137, c12502 )
        TSCP  n12135, t12136, v12137, c12502;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l12134 [inside EASY-FFI:FROM-C]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12502, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12502, 1 );
        X3 = easy_2dffi_l12143( n12135, t12136, v12137 );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        POPSTACKTRACE( X3 );
}

TSCP  asy_2dffi_3afrom_2dc_d15f4f72( c12132, c12133 )
        TSCP  c12132, c12133;
{
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t12500 );
        DISPLAY( 0 ) = c12132;
        DISPLAY( 1 ) = c12133;
        SDVAL = MAKEPROCEDURE( 3, 
                               0, 
                               easy_2dffi_l12134, 
                               MAKECLOSURE( EMPTYLIST, 
                                            2, 
                                            DISPLAY( 1 ), 
                                            DISPLAY( 0 ) ) );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( easy_2dffi_easy_2dffi_3afree_v );
DEFCSTRING( t12546, "EASY-FFI:FREE" );
EXTERNTSCPP( easy_2dffi_l12216, XAL3( TSCP, TSCP, TSCP ) );

TSCP  easy_2dffi_l12267( x12268, i12269, c12563 )
        TSCP  x12268, i12269, c12563;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l12267 [inside EASY-FFI:FREE]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12563, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12563, 1 );
        X5 = DISPLAY( 0 );
        if  ( BITAND( BITOR( _S2CINT( X5 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12566;
        X4 = _TSCP( IDIFFERENCE( _S2CINT( X5 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L12567;
L12566:
        X4 = scrt2__2d_2dtwo( X5, _TSCP( 4 ) );
L12567:
        X7 = scrt4_c_2dsizeof_2ds2cuint_v;
        if  ( BITAND( BITOR( _S2CINT( i12269 ), 
                             _S2CINT( X7 ) ), 
                      3 ) )  goto L12569;
        X6 = _TSCP( ITIMES( FIXED_C( i12269 ), 
                            _S2CINT( X7 ) ) );
        goto L12570;
L12569:
        X6 = scrt2__2a_2dtwo( i12269, X7 );
L12570:
        X5 = scrt4_c_2ds2cuint_2dref( DISPLAY( 2 ), X6 );
        X3 = easy_2dffi_l12216( X4, x12268, X5 );
        DISPLAY( 2 ) = X1;
        DISPLAY( 0 ) = X2;
        POPSTACKTRACE( X3 );
}

TSCP  easy_2dffi_l12233( i12234, c12576 )
        TSCP  i12234, c12576;
{
        TSCP  X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "easy_2dffi_l12233 [inside EASY-FFI:FREE]" );
        X1 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c12576, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c12576, 1 );
        X3 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c12576, 2 );
        X6 = DISPLAY( 0 );
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12579;
        X5 = _TSCP( IDIFFERENCE( _S2CINT( X6 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L12580;
L12579:
        X5 = scrt2__2d_2dtwo( X6, _TSCP( 4 ) );
L12580:
        X7 = DISPLAY( 1 );
        if  ( AND( EQ( TSCPTAG( X7 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X7 ), VECTORTAG ) ) )  goto L12582;
        scdebug_error( c12012, 
                       c12013, CONS( X7, EMPTYLIST ) );
L12582:
        if  ( EQ( TSCPTAG( i12234 ), FIXNUMTAG ) )  goto L12584;
        scdebug_error( c12012, 
                       c12016, CONS( i12234, EMPTYLIST ) );
L12584:
        if  ( LT( _S2CUINT( FIXED_C( i12234 ) ), 
                  _S2CUINT( VECTOR_LENGTH( X7 ) ) ) )  goto L12586;
        scdebug_error( c12012, 
                       c12020, CONS( i12234, EMPTYLIST ) );
L12586:
        X6 = VECTOR_ELEMENT( X7, i12234 );
        X9 = scrt4_c_2dsizeof_2ds2cuint_v;
        if  ( BITAND( BITOR( _S2CINT( i12234 ), 
                             _S2CINT( X9 ) ), 
                      3 ) )  goto L12589;
        X8 = _TSCP( ITIMES( FIXED_C( i12234 ), 
                            _S2CINT( X9 ) ) );
        goto L12590;
L12589:
        X8 = scrt2__2a_2dtwo( i12234, X9 );
L12590:
        X7 = scrt4_c_2ds2cuint_2dref( DISPLAY( 2 ), X8 );
        X4 = easy_2dffi_l12216( X5, X6, X7 );
        DISPLAY( 2 ) = X1;
        DISPLAY( 1 ) = X2;
        DISPLAY( 0 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  easy_2dffi_l12216( n12218, x12219, v12220 )
        TSCP  n12218, x12219, v12220;
{
        TSCP  X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "LOOP [inside EASY-FFI:FREE]" );
        DISPLAY( 0 ) = n12218;
        DISPLAY( 1 ) = x12219;
        DISPLAY( 2 ) = v12220;
        X1 = DISPLAY( 0 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12552;
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( _TSCP( 4 ) ) ) )  goto L12556;
        goto L12557;
L12552:
        if  ( TRUE( scrt2__3d_2dtwo( X1, _TSCP( 4 ) ) ) )  goto L12556;
L12557:
        if  ( FALSE( scrt1_list_3f( DISPLAY( 1 ) ) ) )  goto L12560;
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            easy_2dffi_l12267, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 0 ) ) );
        obischeme__2dindexed_d1069d4( X1, DISPLAY( 1 ) );
        X1 = DISPLAY( 2 );
        free( TSCP_POINTER( X1 ) );
        SDVAL = FALSEVALUE;
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
L12560:
        if  ( NOT( AND( EQ( TSCPTAG( DISPLAY( 1 ) ), 
                            EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( DISPLAY( 1 ) ), 
                            VECTORTAG ) ) ) )  goto L12573;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            easy_2dffi_l12233, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ) ) );
        X3 = DISPLAY( 1 );
        if  ( AND( EQ( TSCPTAG( X3 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X3 ), VECTORTAG ) ) )  goto L12592;
        scdebug_error( c12025, 
                       c12013, CONS( X3, EMPTYLIST ) );
L12592:
        X2 = C_FIXED( VECTOR_LENGTH( X3 ) );
        qobischeme_for_2deach_2dn( X1, X2 );
        X1 = DISPLAY( 2 );
        free( TSCP_POINTER( X1 ) );
        SDVAL = FALSEVALUE;
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
L12573:
        SDVAL = qobischeme_panic( c11990, EMPTYLIST );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
L12556:
        X1 = DISPLAY( 2 );
        free( TSCP_POINTER( X1 ) );
        SDVAL = FALSEVALUE;
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

TSCP  easy_2dffi_easy_2dffi_3afree( n12208, x12209, v12210 )
        TSCP  n12208, x12209, v12210;
{
        PUSHSTACKTRACE( t12546 );
        POPSTACKTRACE( easy_2dffi_l12216( n12208, x12209, v12210 ) );
}

DEFTSCP( asy_2dffi_e_2dto_2dc_f497c900_v );
DEFCSTRING( t12598, "EASY-FFI:BYTE-TO-C" );
EXTERNTSCPP( scrt4_c_2dbyte_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dbyte_2dset_21_v );
DEFTSCP( asy_2dffi_e_2dto_2dc_6e7b37fb_v );
DEFCSTRING( t12599, "EASY-FFI:DOUBLE-TO-C" );
EXTERNTSCPP( scrt4_c_2ddouble_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ddouble_2dset_21_v );
EXTERNTSCP( scrt4_c_2dsizeof_2ddouble_v );
DEFTSCP( asy_2dffi_t_2dto_2dc_61925e17_v );
DEFCSTRING( t12600, "EASY-FFI:FLOAT-TO-C" );
EXTERNTSCPP( scrt4_c_2dfloat_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dfloat_2dset_21_v );
EXTERNTSCP( scrt4_c_2dsizeof_2dfloat_v );
DEFTSCP( asy_2dffi_t_2dto_2dc_d3906c33_v );
DEFCSTRING( t12601, "EASY-FFI:INT-TO-C" );
EXTERNTSCPP( scrt4_c_2dint_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dint_2dset_21_v );
EXTERNTSCP( scrt4_c_2dsizeof_2dint_v );
DEFTSCP( asy_2dffi_t_2dto_2dc_ca84e256_v );
DEFCSTRING( t12602, "EASY-FFI:LONGINT-TO-C" );
EXTERNTSCPP( scrt4_c_2dlongint_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dlongint_2dset_21_v );
EXTERNTSCP( scrt4_c_2dsizeof_2dlong_v );
DEFTSCP( asy_2dffi_d_2dto_2dc_5b40207f_v );
DEFCSTRING( t12603, "EASY-FFI:LONGUNSIGNED-TO-C" );
EXTERNTSCPP( scrt4_d_2dset_21_2e97375c, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_d_2dset_21_2e97375c_v );
DEFTSCP( asy_2dffi_t_2dto_2dc_2259710f_v );
DEFCSTRING( t12604, "EASY-FFI:SHORTINT-TO-C" );
EXTERNTSCPP( scrt4_c_2dshortint_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dshortint_2dset_21_v );
EXTERNTSCP( scrt4_c_2dsizeof_2dshort_v );
DEFTSCP( asy_2dffi_d_2dto_2dc_d2401c08_v );
DEFCSTRING( t12605, "EASY-FFI:SHORTUNSIGNED-TO-C" );
EXTERNTSCPP( scrt4_d_2dset_21_828269c5, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_d_2dset_21_828269c5_v );
DEFTSCP( asy_2dffi_d_2dto_2dc_873bbbfe_v );
DEFCSTRING( t12606, "EASY-FFI:UNSIGNED-TO-C" );
EXTERNTSCPP( scrt4_c_2dunsigned_2dset_21, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dunsigned_2dset_21_v );
DEFTSCP( asy_2dffi_2dfrom_2dc_fb68bf0a_v );
DEFCSTRING( t12607, "EASY-FFI:BYTE-FROM-C" );
EXTERNTSCPP( scrt4_c_2dbyte_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dbyte_2dref_v );
DEFTSCP( asy_2dffi_2dfrom_2dc_5625c28b_v );
DEFCSTRING( t12608, "EASY-FFI:DOUBLE-FROM-C" );
EXTERNTSCPP( scrt4_c_2ddouble_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2ddouble_2dref_v );
DEFTSCP( asy_2dffi_2dfrom_2dc_9080a87e_v );
DEFCSTRING( t12609, "EASY-FFI:FLOAT-FROM-C" );
EXTERNTSCPP( scrt4_c_2dfloat_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dfloat_2dref_v );
DEFTSCP( asy_2dffi_2dfrom_2dc_a9bfaa5a_v );
DEFCSTRING( t12610, "EASY-FFI:INT-FROM-C" );
EXTERNTSCPP( scrt4_c_2dint_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dint_2dref_v );
DEFTSCP( asy_2dffi_2dfrom_2dc_bb35828b_v );
DEFCSTRING( t12611, "EASY-FFI:LONGINT-FROM-C" );
EXTERNTSCPP( scrt4_c_2dlongint_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dlongint_2dref_v );
DEFTSCP( asy_2dffi_2dfrom_2dc_8a192f38_v );
DEFCSTRING( t12612, "EASY-FFI:LONGUNSIGNED-FROM-C" );
EXTERNTSCPP( scrt4_c_2dlongunsigned_2dref, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dlongunsigned_2dref_v );
DEFTSCP( asy_2dffi_2dfrom_2dc_b94a4eb5_v );
DEFCSTRING( t12613, "EASY-FFI:SHORTINT-FROM-C" );
EXTERNTSCPP( scrt4_c_2dshortint_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dshortint_2dref_v );
DEFTSCP( asy_2dffi_2dfrom_2dc_c508358e_v );
DEFCSTRING( t12614, "EASY-FFI:SHORTUNSIGNED-FROM-C" );
EXTERNTSCPP( scrt4_c_2dshortunsigned_2dref, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dshortunsigned_2dref_v );
DEFTSCP( asy_2dffi_2dfrom_2dc_cf5c1085_v );
DEFCSTRING( t12615, "EASY-FFI:UNSIGNED-FROM-C" );
EXTERNTSCPP( scrt4_c_2dunsigned_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt4_c_2dunsigned_2dref_v );
DEFTSCP( asy_2dffi_ng_2dstars_fc382be5_v );
DEFCSTRING( t12616, "EASY-FFI:REMOVE-LEADING-STARS" );
EXTERNTSCPP( sc_string_2d_3esymbol, XAL1( TSCP ) );
EXTERNTSCP( sc_string_2d_3esymbol_v );
EXTERNTSCPP( scrt3_list_2d_3estring, XAL1( TSCP ) );
EXTERNTSCP( scrt3_list_2d_3estring_v );
EXTERNTSCPP( scrt3_string_2d_3elist, XAL1( TSCP ) );
EXTERNTSCP( scrt3_string_2d_3elist_v );

TSCP  asy_2dffi_ng_2dstars_fc382be5( t12293 )
        TSCP  t12293;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t12616 );
        if  ( AND( EQ( TSCPTAG( t12293 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( t12293 ), SYMBOLTAG ) )
            )  goto L12619;
        scdebug_error( c12313, 
                       c12314, CONS( t12293, EMPTYLIST ) );
L12619:
        X4 = SYMBOL_NAME( t12293 );
        X3 = scrt3_string_2d_3elist( X4 );
        X4 = X3;
L12623:
        X5 = qobischeme_first( X4 );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X5 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 10770 ) ), 
                       CHARACTERTAG ) ) )  goto L12625;
        X6 = CONS( _TSCP( 10770 ), EMPTYLIST );
        scdebug_error( c12306, c12307, CONS( X5, X6 ) );
L12625:
        if  ( NEQ( _S2CINT( X5 ), 
                   _S2CINT( _TSCP( 10770 ) ) ) )  goto L12627;
        X4 = qobischeme_rest( X4 );
        GOBACK( L12623 );
L12627:
        X2 = X4;
        X1 = scrt3_list_2d_3estring( X2 );
        POPSTACKTRACE( sc_string_2d_3esymbol( X1 ) );
}

DEFTSCP( asy_2dffi_ng_2dstars_f1256bf1_v );
DEFCSTRING( t12629, "EASY-FFI:COUNT-LEADING-STARS" );
EXTERNTSCPP( easy_2dffi_l12320, XAL1( TSCP ) );
EXTERNTSCPP( scrt2__2b_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2b_2dtwo_v );

TSCP  easy_2dffi_l12320( c12322 )
        TSCP  c12322;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "LOOP [inside EASY-FFI:COUNT-LEADING-STARS]" );
        X1 = qobischeme_first( c12322 );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X1 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 10770 ) ), 
                       CHARACTERTAG ) ) )  goto L12638;
        X2 = CONS( _TSCP( 10770 ), EMPTYLIST );
        scdebug_error( c12306, c12307, CONS( X1, X2 ) );
L12638:
        if  ( NEQ( _S2CINT( X1 ), 
                   _S2CINT( _TSCP( 10770 ) ) ) )  goto L12640;
        X3 = qobischeme_rest( c12322 );
        X2 = easy_2dffi_l12320( X3 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12643;
        POPSTACKTRACE( _TSCP( IPLUS( _S2CINT( X2 ), 
                                     _S2CINT( _TSCP( 4 ) ) ) ) );
L12643:
        POPSTACKTRACE( scrt2__2b_2dtwo( X2, _TSCP( 4 ) ) );
L12640:
        POPSTACKTRACE( _TSCP( 0 ) );
}

TSCP  asy_2dffi_ng_2dstars_f1256bf1( t12316 )
        TSCP  t12316;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t12629 );
        if  ( AND( EQ( TSCPTAG( t12316 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( t12316 ), SYMBOLTAG ) )
            )  goto L12632;
        scdebug_error( c12313, 
                       c12314, CONS( t12316, EMPTYLIST ) );
L12632:
        X2 = SYMBOL_NAME( t12316 );
        X1 = scrt3_string_2d_3elist( X2 );
        POPSTACKTRACE( easy_2dffi_l12320( X1 ) );
}

DEFTSCP( asy_2dffi_ng_2dstars_b2b7822_v );
DEFCSTRING( t12645, "EASY-FFI:REMOVE-TRAILING-STARS" );
EXTERNTSCPP( scrt1_reverse, XAL1( TSCP ) );
EXTERNTSCP( scrt1_reverse_v );

TSCP  asy_2dffi_ng_2dstars_b2b7822( t12340 )
        TSCP  t12340;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t12645 );
        if  ( AND( EQ( TSCPTAG( t12340 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( t12340 ), SYMBOLTAG ) )
            )  goto L12648;
        scdebug_error( c12313, 
                       c12314, CONS( t12340, EMPTYLIST ) );
L12648:
        X6 = SYMBOL_NAME( t12340 );
        X5 = scrt3_string_2d_3elist( X6 );
        X4 = scrt1_reverse( X5 );
        X5 = X4;
L12652:
        X6 = qobischeme_first( X5 );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X6 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 10770 ) ), 
                       CHARACTERTAG ) ) )  goto L12654;
        X7 = CONS( _TSCP( 10770 ), EMPTYLIST );
        scdebug_error( c12306, c12307, CONS( X6, X7 ) );
L12654:
        if  ( NEQ( _S2CINT( X6 ), 
                   _S2CINT( _TSCP( 10770 ) ) ) )  goto L12656;
        X5 = qobischeme_rest( X5 );
        GOBACK( L12652 );
L12656:
        X3 = X5;
        X2 = scrt1_reverse( X3 );
        X1 = scrt3_list_2d_3estring( X2 );
        POPSTACKTRACE( sc_string_2d_3esymbol( X1 ) );
}

DEFTSCP( asy_2dffi_ng_2dstars_11fcb11f_v );
DEFCSTRING( t12658, "EASY-FFI:COUNT-TRAILING-STARS" );
EXTERNTSCPP( easy_2dffi_l12362, XAL1( TSCP ) );

TSCP  easy_2dffi_l12362( c12364 )
        TSCP  c12364;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "LOOP [inside EASY-FFI:COUNT-TRAILING-STARS]" );
        X1 = qobischeme_first( c12364 );
        if  ( AND( EQ( TSCPIMMEDIATETAG( X1 ), CHARACTERTAG ), 
                   EQ( TSCPIMMEDIATETAG( _TSCP( 10770 ) ), 
                       CHARACTERTAG ) ) )  goto L12667;
        X2 = CONS( _TSCP( 10770 ), EMPTYLIST );
        scdebug_error( c12306, c12307, CONS( X1, X2 ) );
L12667:
        if  ( NEQ( _S2CINT( X1 ), 
                   _S2CINT( _TSCP( 10770 ) ) ) )  goto L12669;
        X3 = qobischeme_rest( c12364 );
        X2 = easy_2dffi_l12362( X3 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L12672;
        POPSTACKTRACE( _TSCP( IPLUS( _S2CINT( X2 ), 
                                     _S2CINT( _TSCP( 4 ) ) ) ) );
L12672:
        POPSTACKTRACE( scrt2__2b_2dtwo( X2, _TSCP( 4 ) ) );
L12669:
        POPSTACKTRACE( _TSCP( 0 ) );
}

TSCP  asy_2dffi_ng_2dstars_11fcb11f( t12358 )
        TSCP  t12358;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( t12658 );
        if  ( AND( EQ( TSCPTAG( t12358 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( t12358 ), SYMBOLTAG ) )
            )  goto L12661;
        scdebug_error( c12313, 
                       c12314, CONS( t12358, EMPTYLIST ) );
L12661:
        X3 = SYMBOL_NAME( t12358 );
        X2 = scrt3_string_2d_3elist( X3 );
        X1 = scrt1_reverse( X2 );
        POPSTACKTRACE( easy_2dffi_l12362( X1 ) );
}

void scrt3__init();
void scdebug__init();
void qobischeme__init();
void scrt4__init();
void scrt1__init();
void scrt2__init();

static void  init_modules( compiler_version )
        char *compiler_version;
{
        scrt3__init();
        scdebug__init();
        qobischeme__init();
        scrt4__init();
        scrt1__init();
        scrt2__init();
        MAXDISPLAY( 5 );
}

void  easy_2dffi__init()
{
        static int  init = 0;
        if  (init)  return;
        init = 1;
        INITHEAP( 0, 0, 0, 0 );
        init_constants();
        init_modules( "(easy_2dffi SCHEME->C COMPILER 15mar93jfb)" );
        sc_segv__handlers();
        INITIALIZEVAR( t12402, 
                       ADR( asy_2dffi_fi_2d1_2d0_8506d0f9_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      asy_2dffi_fi_2d1_2d0_8506d0f9, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12404, 
                       ADR( asy_2dffi_fi_2d3_2d0_ffc68399_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      asy_2dffi_fi_2d3_2d0_ffc68399, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12406, 
                       ADR( asy_2dffi_fi_2d5_2d0_70867639_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      asy_2dffi_fi_2d5_2d0_70867639, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12408, 
                       ADR( asy_2dffi_i_3ato_2dc_4737233d_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      asy_2dffi_i_3ato_2dc_4737233d, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12500, 
                       ADR( asy_2dffi_3afrom_2dc_d15f4f72_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      asy_2dffi_3afrom_2dc_d15f4f72, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12546, 
                       ADR( easy_2dffi_easy_2dffi_3afree_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      easy_2dffi_easy_2dffi_3afree, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12598, 
                       ADR( asy_2dffi_e_2dto_2dc_f497c900_v ), 
                       asy_2dffi_i_3ato_2dc_4737233d( scrt4_c_2dbyte_2dset_21_v, 
                                                      _TSCP( 4 ) ) );
        INITIALIZEVAR( t12599, 
                       ADR( asy_2dffi_e_2dto_2dc_6e7b37fb_v ), 
                       asy_2dffi_i_3ato_2dc_4737233d( scrt4_c_2ddouble_2dset_21_v, 
                                                      scrt4_c_2dsizeof_2ddouble_v ) );
        INITIALIZEVAR( t12600, 
                       ADR( asy_2dffi_t_2dto_2dc_61925e17_v ), 
                       asy_2dffi_i_3ato_2dc_4737233d( scrt4_c_2dfloat_2dset_21_v, 
                                                      scrt4_c_2dsizeof_2dfloat_v ) );
        INITIALIZEVAR( t12601, 
                       ADR( asy_2dffi_t_2dto_2dc_d3906c33_v ), 
                       asy_2dffi_i_3ato_2dc_4737233d( scrt4_c_2dint_2dset_21_v, 
                                                      scrt4_c_2dsizeof_2dint_v ) );
        INITIALIZEVAR( t12602, 
                       ADR( asy_2dffi_t_2dto_2dc_ca84e256_v ), 
                       asy_2dffi_i_3ato_2dc_4737233d( scrt4_c_2dlongint_2dset_21_v, 
                                                      scrt4_c_2dsizeof_2dlong_v ) );
        INITIALIZEVAR( t12603, 
                       ADR( asy_2dffi_d_2dto_2dc_5b40207f_v ), 
                       asy_2dffi_i_3ato_2dc_4737233d( scrt4_d_2dset_21_2e97375c_v, 
                                                      scrt4_c_2dsizeof_2dlong_v ) );
        INITIALIZEVAR( t12604, 
                       ADR( asy_2dffi_t_2dto_2dc_2259710f_v ), 
                       asy_2dffi_i_3ato_2dc_4737233d( scrt4_c_2dshortint_2dset_21_v, 
                                                      scrt4_c_2dsizeof_2dshort_v ) );
        INITIALIZEVAR( t12605, 
                       ADR( asy_2dffi_d_2dto_2dc_d2401c08_v ), 
                       asy_2dffi_i_3ato_2dc_4737233d( scrt4_d_2dset_21_828269c5_v, 
                                                      scrt4_c_2dsizeof_2dshort_v ) );
        INITIALIZEVAR( t12606, 
                       ADR( asy_2dffi_d_2dto_2dc_873bbbfe_v ), 
                       asy_2dffi_i_3ato_2dc_4737233d( scrt4_c_2dunsigned_2dset_21_v, 
                                                      scrt4_c_2dsizeof_2dint_v ) );
        INITIALIZEVAR( t12607, 
                       ADR( asy_2dffi_2dfrom_2dc_fb68bf0a_v ), 
                       asy_2dffi_3afrom_2dc_d15f4f72( scrt4_c_2dbyte_2dref_v, 
                                                      _TSCP( 4 ) ) );
        INITIALIZEVAR( t12608, 
                       ADR( asy_2dffi_2dfrom_2dc_5625c28b_v ), 
                       asy_2dffi_3afrom_2dc_d15f4f72( scrt4_c_2ddouble_2dref_v, 
                                                      scrt4_c_2dsizeof_2ddouble_v ) );
        INITIALIZEVAR( t12609, 
                       ADR( asy_2dffi_2dfrom_2dc_9080a87e_v ), 
                       asy_2dffi_3afrom_2dc_d15f4f72( scrt4_c_2dfloat_2dref_v, 
                                                      scrt4_c_2dsizeof_2dfloat_v ) );
        INITIALIZEVAR( t12610, 
                       ADR( asy_2dffi_2dfrom_2dc_a9bfaa5a_v ), 
                       asy_2dffi_3afrom_2dc_d15f4f72( scrt4_c_2dint_2dref_v, 
                                                      scrt4_c_2dsizeof_2dint_v ) );
        INITIALIZEVAR( t12611, 
                       ADR( asy_2dffi_2dfrom_2dc_bb35828b_v ), 
                       asy_2dffi_3afrom_2dc_d15f4f72( scrt4_c_2dlongint_2dref_v, 
                                                      scrt4_c_2dsizeof_2dlong_v ) );
        INITIALIZEVAR( t12612, 
                       ADR( asy_2dffi_2dfrom_2dc_8a192f38_v ), 
                       asy_2dffi_3afrom_2dc_d15f4f72( scrt4_c_2dlongunsigned_2dref_v, 
                                                      scrt4_c_2dsizeof_2dlong_v ) );
        INITIALIZEVAR( t12613, 
                       ADR( asy_2dffi_2dfrom_2dc_b94a4eb5_v ), 
                       asy_2dffi_3afrom_2dc_d15f4f72( scrt4_c_2dshortint_2dref_v, 
                                                      scrt4_c_2dsizeof_2dshort_v ) );
        INITIALIZEVAR( t12614, 
                       ADR( asy_2dffi_2dfrom_2dc_c508358e_v ), 
                       asy_2dffi_3afrom_2dc_d15f4f72( scrt4_c_2dshortunsigned_2dref_v, 
                                                      scrt4_c_2dsizeof_2dshort_v ) );
        INITIALIZEVAR( t12615, 
                       ADR( asy_2dffi_2dfrom_2dc_cf5c1085_v ), 
                       asy_2dffi_3afrom_2dc_d15f4f72( scrt4_c_2dunsigned_2dref_v, 
                                                      scrt4_c_2dsizeof_2dint_v ) );
        INITIALIZEVAR( t12616, 
                       ADR( asy_2dffi_ng_2dstars_fc382be5_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      asy_2dffi_ng_2dstars_fc382be5, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12629, 
                       ADR( asy_2dffi_ng_2dstars_f1256bf1_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      asy_2dffi_ng_2dstars_f1256bf1, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12645, 
                       ADR( asy_2dffi_ng_2dstars_b2b7822_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      asy_2dffi_ng_2dstars_b2b7822, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12658, 
                       ADR( asy_2dffi_ng_2dstars_11fcb11f_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      asy_2dffi_ng_2dstars_11fcb11f, 
                                      EMPTYLIST ) );
        return;
}
