
/* SCHEME->C */

#include <objects.h>

int main();
DEFCSTRING( t12875, "-usage" );
DEFSTATICTSCP( c12487 );
DEFCSTRING( t12876, "-box-size" );
DEFSTATICTSCP( c12486 );
DEFCSTRING( t12877, "-downsample" );
DEFSTATICTSCP( c12485 );
DEFCSTRING( t12878, "-top-k" );
DEFSTATICTSCP( c12484 );
DEFCSTRING( t12879, "-video" );
DEFSTATICTSCP( c12483 );
DEFCSTRING( t12880, 
            "usage: ~a [-video video-path] [-top-k top-k] [-downsample rate]\
 [-box-size size]~%" );
DEFSTATICTSCP( c12462 );
DEFCSTRING( t12881, "tmp=simi(:,:,~a);" );
DEFSTATICTSCP( c12372 );
DEFCSTRING( t12882, "tmp" );
DEFSTATICTSCP( c12369 );
DEFCSTRING( t12883, "tmp=bboxes(:,:,~a);" );
DEFSTATICTSCP( c12362 );
DEFCSTRING( t12884, 
            "[bboxes,simi]=proposals_and_similarity(~a,frames,~a);" );
DEFSTATICTSCP( c12357 );
DEFCSTRING( t12885, "frames(:,:,:,~a)=uint8(frame);" );
DEFSTATICTSCP( c12350 );
DEFCSTRING( t12886, "frame=imread('~a');" );
DEFSTATICTSCP( c12349 );
DEFCSTRING( t12887, "/tmp/imlib-frame.ppm" );
DEFSTATICTSCP( c12346 );
DEFCSTRING( t12888, "frames=zeros(~a,~a,~a,~a,'uint8');" );
DEFSTATICTSCP( c12341 );
DEFCSTRING( t12889, "/tmp/time-" );
DEFSTATICTSCP( c12285 );
DEFCSTRING( t12890, "Argument not a PAIR: ~s" );
DEFSTATICTSCP( c12276 );
DEFSTATICTSCP( c12275 );
DEFCSTRING( t12891, "." );
DEFSTATICTSCP( c12240 );
DEFCSTRING( t12892, "date +'%s %N' > ~a" );
DEFSTATICTSCP( c12237 );
DEFCSTRING( t12893, "SET-IMLIB-IMAGE-HANDLE! error" );
DEFSTATICTSCP( c12056 );
DEFCSTRING( t12894, "IMLIB-IMAGE-HANDLE error" );
DEFSTATICTSCP( c12041 );
DEFCSTRING( t12895, "LOCAL-SET-IMLIB-IMAGE-HANDLE! error" );
DEFSTATICTSCP( c12037 );
DEFSTATICTSCP( c12027 );
DEFSTATICTSCP( c12017 );
DEFSTATICTSCP( c11978 );
DEFCSTRING( t12896, "Index is not in bounds: ~s" );
DEFSTATICTSCP( c11976 );
DEFCSTRING( t12897, "Argument is not an INTEGER: ~s" );
DEFSTATICTSCP( c11972 );
DEFCSTRING( t12898, "Argument is not a VECTOR: ~s" );
DEFSTATICTSCP( c11969 );
DEFSTATICTSCP( c11968 );
DEFCSTRING( t12899, "codetection" );
DEFSTATICTSCP( c11956 );

static void  init_constants()
{
        c12487 = CSTRING_TSCP( t12875 );
        CONSTANTEXP( ADR( c12487 ) );
        c12486 = CSTRING_TSCP( t12876 );
        CONSTANTEXP( ADR( c12486 ) );
        c12485 = CSTRING_TSCP( t12877 );
        CONSTANTEXP( ADR( c12485 ) );
        c12484 = CSTRING_TSCP( t12878 );
        CONSTANTEXP( ADR( c12484 ) );
        c12483 = CSTRING_TSCP( t12879 );
        CONSTANTEXP( ADR( c12483 ) );
        c12462 = CSTRING_TSCP( t12880 );
        CONSTANTEXP( ADR( c12462 ) );
        c12372 = CSTRING_TSCP( t12881 );
        CONSTANTEXP( ADR( c12372 ) );
        c12369 = CSTRING_TSCP( t12882 );
        CONSTANTEXP( ADR( c12369 ) );
        c12362 = CSTRING_TSCP( t12883 );
        CONSTANTEXP( ADR( c12362 ) );
        c12357 = CSTRING_TSCP( t12884 );
        CONSTANTEXP( ADR( c12357 ) );
        c12350 = CSTRING_TSCP( t12885 );
        CONSTANTEXP( ADR( c12350 ) );
        c12349 = CSTRING_TSCP( t12886 );
        CONSTANTEXP( ADR( c12349 ) );
        c12346 = CSTRING_TSCP( t12887 );
        CONSTANTEXP( ADR( c12346 ) );
        c12341 = CSTRING_TSCP( t12888 );
        CONSTANTEXP( ADR( c12341 ) );
        c12285 = CSTRING_TSCP( t12889 );
        CONSTANTEXP( ADR( c12285 ) );
        c12276 = CSTRING_TSCP( t12890 );
        CONSTANTEXP( ADR( c12276 ) );
        c12275 = STRINGTOSYMBOL( CSTRING_TSCP( "SET-CDR!" ) );
        CONSTANTEXP( ADR( c12275 ) );
        c12240 = CSTRING_TSCP( t12891 );
        CONSTANTEXP( ADR( c12240 ) );
        c12237 = CSTRING_TSCP( t12892 );
        CONSTANTEXP( ADR( c12237 ) );
        c12056 = CSTRING_TSCP( t12893 );
        CONSTANTEXP( ADR( c12056 ) );
        c12041 = CSTRING_TSCP( t12894 );
        CONSTANTEXP( ADR( c12041 ) );
        c12037 = CSTRING_TSCP( t12895 );
        CONSTANTEXP( ADR( c12037 ) );
        c12027 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR-REF" ) );
        CONSTANTEXP( ADR( c12027 ) );
        c12017 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR-LENGTH" ) );
        CONSTANTEXP( ADR( c12017 ) );
        c11978 = STRINGTOSYMBOL( CSTRING_TSCP( "IMLIB-IMAGE" ) );
        CONSTANTEXP( ADR( c11978 ) );
        c11976 = CSTRING_TSCP( t12896 );
        CONSTANTEXP( ADR( c11976 ) );
        c11972 = CSTRING_TSCP( t12897 );
        CONSTANTEXP( ADR( c11972 ) );
        c11969 = CSTRING_TSCP( t12898 );
        CONSTANTEXP( ADR( c11969 ) );
        c11968 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR-SET!" ) );
        CONSTANTEXP( ADR( c11968 ) );
        c11956 = CSTRING_TSCP( t12899 );
        CONSTANTEXP( ADR( c11956 ) );
}

DEFTSCP( detection_on_2d1_2d0_9fcc6ee3_v );
DEFCSTRING( t12900, "gensym-codetection-1-0" );

TSCP  detection_on_2d1_2d0_9fcc6ee3(  )
{
        PUSHSTACKTRACE( t12900 );
        POPSTACKTRACE( 0 );}
  #include<stddef.h>
int gensym_codetection_2_0(){ return 1;gensym_codetection_2_0( );
}

DEFTSCP( detection_on_2d3_2d0_e50c3d83_v );
DEFCSTRING( t12902, "gensym-codetection-3-0" );

TSCP  detection_on_2d3_2d0_e50c3d83(  )
{
        PUSHSTACKTRACE( t12902 );
        POPSTACKTRACE( 0 );}
  #include<stdlib.h>
int gensym_codetection_4_0(){ return 1;gensym_codetection_4_0( );
}

DEFTSCP( detection_on_2d5_2d0_6a4cc823_v );
DEFCSTRING( t12904, "gensym-codetection-5-0" );

TSCP  detection_on_2d5_2d0_6a4cc823(  )
{
        PUSHSTACKTRACE( t12904 );
        POPSTACKTRACE( 0 );}
  #include<string.h>
int gensym_codetection_6_0(){ return 1;gensym_codetection_6_0( );
}

DEFTSCP( detection_on_2d7_2d0_108c9b43_v );
DEFCSTRING( t12906, "gensym-codetection-7-0" );

TSCP  detection_on_2d7_2d0_108c9b43(  )
{
        PUSHSTACKTRACE( t12906 );
        POPSTACKTRACE( 0 );}
  #include<codetectionlib-c.h>
int gensym_codetection_8_0(){ return 1;gensym_codetection_8_0( );
}

DEFTSCP( detection_on_2d9_2d0_afbc2522_v );
DEFCSTRING( t12908, "gensym-codetection-9-0" );

TSCP  detection_on_2d9_2d0_afbc2522(  )
{
        PUSHSTACKTRACE( t12908 );
        POPSTACKTRACE( 0 );}
  #include<inference.h>
int gensym_codetection_10_0(){ return 1;gensym_codetection_10_0( );
}

EXTERNTSCP( qobischeme__2aprogram_2a_v );
EXTERNTSCP( qobischeme__2apanic_3f_2a_v );
DEFTSCP( detection_ib_2dimage_37692324_v );
DEFCSTRING( t12910, "MAKE-IMLIB-IMAGE" );
EXTERNTSCPP( sc_make_2dvector, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_make_2dvector_v );
EXTERNTSCPP( scdebug_error, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scdebug_error_v );

TSCP  detection_ib_2dimage_37692324( h11959 )
        TSCP  h11959;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12910 );
        X1 = sc_make_2dvector( _TSCP( 8 ), EMPTYLIST );
        if  ( AND( EQ( TSCPTAG( X1 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X1 ), VECTORTAG ) ) )  goto L12914;
        scdebug_error( c11968, 
                       c11969, CONS( X1, EMPTYLIST ) );
L12914:
        if  ( EQ( TSCPTAG( _TSCP( 0 ) ), FIXNUMTAG ) )  goto L12916;
        scdebug_error( c11968, 
                       c11972, CONS( _TSCP( 0 ), EMPTYLIST ) );
L12916:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 0 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( X1 ) ) ) )  goto L12918;
        scdebug_error( c11968, 
                       c11976, CONS( _TSCP( 0 ), EMPTYLIST ) );
L12918:
        SETGEN( VECTOR_ELEMENT( X1, _TSCP( 0 ) ), c11978 );
        if  ( EQ( TSCPTAG( _TSCP( 4 ) ), FIXNUMTAG ) )  goto L12921;
        scdebug_error( c11968, 
                       c11972, CONS( _TSCP( 4 ), EMPTYLIST ) );
L12921:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 4 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( X1 ) ) ) )  goto L12923;
        scdebug_error( c11968, 
                       c11976, CONS( _TSCP( 4 ), EMPTYLIST ) );
L12923:
        SETGEN( VECTOR_ELEMENT( X1, _TSCP( 4 ) ), h11959 );
        POPSTACKTRACE( X1 );
}

DEFTSCP( codetection_imlib_2dimage_3f_v );
DEFCSTRING( t12925, "IMLIB-IMAGE?" );
EXTERNTSCPP( scrt2__3d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3d_2dtwo_v );

TSCP  codetection_imlib_2dimage_3f( o11994 )
        TSCP  o11994;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t12925 );
        if  ( NOT( AND( EQ( TSCPTAG( o11994 ), EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( o11994 ), 
                            VECTORTAG ) ) ) )  goto L12927;
        X2 = C_FIXED( VECTOR_LENGTH( o11994 ) );
        if  ( BITAND( BITOR( _S2CINT( X2 ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L12931;
        X1 = BOOLEAN( EQ( _S2CUINT( X2 ), 
                          _S2CUINT( _TSCP( 8 ) ) ) );
        goto L12932;
L12931:
        X1 = scrt2__3d_2dtwo( X2, _TSCP( 8 ) );
L12932:
        if  ( FALSE( X1 ) )  goto L12934;
        if  ( EQ( TSCPTAG( _TSCP( 0 ) ), FIXNUMTAG ) )  goto L12937;
        scdebug_error( c12027, 
                       c11972, CONS( _TSCP( 0 ), EMPTYLIST ) );
L12937:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 0 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( o11994 ) ) ) )  goto L12939;
        scdebug_error( c12027, 
                       c11976, CONS( _TSCP( 0 ), EMPTYLIST ) );
L12939:
        X2 = VECTOR_ELEMENT( o11994, _TSCP( 0 ) );
        POPSTACKTRACE( BOOLEAN( EQ( _S2CUINT( X2 ), 
                                    _S2CUINT( c11978 ) ) ) );
L12934:
        POPSTACKTRACE( X1 );
L12927:
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( detection_dhandle_21_b97b087a_v );
DEFCSTRING( t12941, "LOCAL-SET-IMLIB-IMAGE-HANDLE!" );
EXTERNTSCPP( qobischeme_panic, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_panic_v );
EXTERNTSCPP( obischeme_r_2dset_21_3e0bb247, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( obischeme_r_2dset_21_3e0bb247_v );

TSCP  detection_dhandle_21_b97b087a( t12035, o12036 )
        TSCP  t12035, o12036;
{
        PUSHSTACKTRACE( t12941 );
        if  ( TRUE( codetection_imlib_2dimage_3f( t12035 ) ) )  goto L12943;
        qobischeme_panic( c12037, EMPTYLIST );
L12943:
        POPSTACKTRACE( obischeme_r_2dset_21_3e0bb247( t12035, 
                                                      _TSCP( 4 ), 
                                                      o12036 ) );
}

DEFTSCP( detection_e_2dhandle_f4eee504_v );
DEFCSTRING( t12945, "IMLIB-IMAGE-HANDLE" );

TSCP  detection_e_2dhandle_f4eee504( t12040 )
        TSCP  t12040;
{
        PUSHSTACKTRACE( t12945 );
        if  ( TRUE( codetection_imlib_2dimage_3f( t12040 ) ) )  goto L12947;
        qobischeme_panic( c12041, EMPTYLIST );
L12947:
        if  ( AND( EQ( TSCPTAG( t12040 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( t12040 ), VECTORTAG ) )
            )  goto L12950;
        scdebug_error( c12027, 
                       c11969, CONS( t12040, EMPTYLIST ) );
L12950:
        if  ( EQ( TSCPTAG( _TSCP( 4 ) ), FIXNUMTAG ) )  goto L12952;
        scdebug_error( c12027, 
                       c11972, CONS( _TSCP( 4 ), EMPTYLIST ) );
L12952:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 4 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( t12040 ) ) ) )  goto L12954;
        scdebug_error( c12027, 
                       c11976, CONS( _TSCP( 4 ), EMPTYLIST ) );
L12954:
        POPSTACKTRACE( VECTOR_ELEMENT( t12040, _TSCP( 4 ) ) );
}

DEFTSCP( detection_dhandle_21_b251c829_v );
DEFCSTRING( t12956, "SET-IMLIB-IMAGE-HANDLE!" );

TSCP  detection_dhandle_21_b251c829( t12054, o12055 )
        TSCP  t12054, o12055;
{
        PUSHSTACKTRACE( t12956 );
        if  ( TRUE( codetection_imlib_2dimage_3f( t12054 ) ) )  goto L12958;
        qobischeme_panic( c12056, EMPTYLIST );
L12958:
        if  ( AND( EQ( TSCPTAG( t12054 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( t12054 ), VECTORTAG ) )
            )  goto L12961;
        scdebug_error( c11968, 
                       c11969, CONS( t12054, EMPTYLIST ) );
L12961:
        if  ( EQ( TSCPTAG( _TSCP( 4 ) ), FIXNUMTAG ) )  goto L12963;
        scdebug_error( c11968, 
                       c11972, CONS( _TSCP( 4 ), EMPTYLIST ) );
L12963:
        if  ( LT( _S2CUINT( FIXED_C( _TSCP( 4 ) ) ), 
                  _S2CUINT( VECTOR_LENGTH( t12054 ) ) ) )  goto L12965;
        scdebug_error( c11968, 
                       c11976, CONS( _TSCP( 4 ), EMPTYLIST ) );
L12965:
        POPSTACKTRACE( SETGEN( VECTOR_ELEMENT( t12054, _TSCP( 4 ) ), 
                               o12055 ) );
}

DEFTSCP( detection_en_2dvideo_533bdb80_v );
DEFCSTRING( t12967, "FFMPEG-OPEN-VIDEO" );

TSCP  detection_en_2dvideo_533bdb80( g12070 )
        TSCP  g12070;
{
        PUSHSTACKTRACE( t12967 );
        POPSTACKTRACE( POINTER_TSCP( ffmpeg_open_video( TSCP_POINTER( g12070 ) ) ) );
}

DEFTSCP( detection_as_2dimlib_568385cf_v );
DEFCSTRING( t12969, "FFMPEG-VIDEO-FRAME-DATA-AS-IMLIB" );

TSCP  detection_as_2dimlib_568385cf( g12075 )
        TSCP  g12075;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12969 );
        X1 = POINTER_TSCP( ffmpeg_get_frame_as_imlib( TSCP_POINTER( g12075 ) ) );
        POPSTACKTRACE( detection_ib_2dimage_37692324( X1 ) );
}

DEFTSCP( detection_se_2dvideo_86ac5560_v );
DEFCSTRING( t12971, "FFMPEG-CLOSE-VIDEO" );

TSCP  detection_se_2dvideo_86ac5560( g12080 )
        TSCP  g12080;
{
        PUSHSTACKTRACE( t12971 );
        ffmpeg_close_and_free_video( TSCP_POINTER( g12080 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( detection_2dframe_21_b1305a3c_v );
DEFCSTRING( t12974, "FFMPEG-NEXT-FRAME!" );

TSCP  detection_2dframe_21_b1305a3c( v12086 )
        TSCP  v12086;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12974 );
        X1 = sc_int_tscp( ffmpeg_next_frame( TSCP_POINTER( v12086 ) ) );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 0 ) ) ), 
                      3 ) )  goto L12977;
        POPSTACKTRACE( BOOLEAN( NEQ( _S2CUINT( X1 ), 
                                     _S2CUINT( _TSCP( 0 ) ) ) ) );
L12977:
        if  ( TRUE( scrt2__3d_2dtwo( X1, _TSCP( 0 ) ) ) )  goto L12979;
        POPSTACKTRACE( TRUEVALUE );
L12979:
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( detection_2dimage_21_95f0e0d1_v );
DEFCSTRING( t12981, "IMLIB-CONTEXT-SET-IMAGE!" );

TSCP  detection_2dimage_21_95f0e0d1( g12102 )
        TSCP  g12102;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12981 );
        X1 = detection_e_2dhandle_f4eee504( g12102 );
        imlib_context_set_image( TSCP_POINTER( X1 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( detection__2ddecache_2ab0af57_v );
DEFCSTRING( t12984, "IMLIB:FREE-IMAGE-AND-DECACHE" );

TSCP  detection__2ddecache_2ab0af57( i12108 )
        TSCP  i12108;
{
        PUSHSTACKTRACE( t12984 );
        detection_2dimage_21_95f0e0d1( i12108 );
        imlib_free_image_and_decache(  );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( detection_ve_2dimage_2fa5fc03_v );
DEFCSTRING( t12987, "IMLIB:SAVE-IMAGE" );

TSCP  detection_ve_2dimage_2fa5fc03( i12115, f12116 )
        TSCP  i12115, f12116;
{
        PUSHSTACKTRACE( t12987 );
        detection_2dimage_21_95f0e0d1( i12115 );
        imlib_save_image( TSCP_POINTER( f12116 ) );
        POPSTACKTRACE( FALSEVALUE );
}

DEFTSCP( codetection_imlib_3aheight_v );
DEFCSTRING( t12990, "IMLIB:HEIGHT" );

TSCP  codetection_imlib_3aheight( i12124 )
        TSCP  i12124;
{
        PUSHSTACKTRACE( t12990 );
        detection_2dimage_21_95f0e0d1( i12124 );
        POPSTACKTRACE( sc_int_tscp( imlib_image_get_height(  ) ) );
}

DEFTSCP( codetection_imlib_3awidth_v );
DEFCSTRING( t12992, "IMLIB:WIDTH" );

TSCP  codetection_imlib_3awidth( i12130 )
        TSCP  i12130;
{
        PUSHSTACKTRACE( t12992 );
        detection_2dimage_21_95f0e0d1( i12130 );
        POPSTACKTRACE( sc_int_tscp( imlib_image_get_width(  ) ) );
}

DEFTSCP( codetection_imlib_3aclone_v );
DEFCSTRING( t12994, "IMLIB:CLONE" );

TSCP  codetection_imlib_3aclone( i12136 )
        TSCP  i12136;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12994 );
        detection_2dimage_21_95f0e0d1( i12136 );
        X1 = POINTER_TSCP( imlib_clone_image(  ) );
        POPSTACKTRACE( detection_ib_2dimage_37692324( X1 ) );
}

DEFTSCP( detection_ead_2donly_f41bd75e_v );
DEFCSTRING( t12996, "IMLIB:DATA-PTR-READ-ONLY" );

TSCP  detection_ead_2donly_f41bd75e( i12142 )
        TSCP  i12142;
{
        PUSHSTACKTRACE( t12996 );
        detection_2dimage_21_95f0e0d1( i12142 );
        POPSTACKTRACE( POINTER_TSCP( imlib_image_get_data_for_reading_only(  ) ) );
}

DEFTSCP( detection_of_2dlists_13af153a_v );
DEFCSTRING( t12998, "MATRIX->LIST-OF-LISTS" );
EXTERNTSCPP( scrt4_vector_2d_3elist, XAL1( TSCP ) );
EXTERNTSCP( scrt4_vector_2d_3elist_v );
EXTERNTSCPP( qobischeme_map_2dvector, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dvector_v );

TSCP  detection_of_2dlists_13af153a( m12148 )
        TSCP  m12148;
{
        TSCP  X1;

        PUSHSTACKTRACE( t12998 );
        X1 = qobischeme_map_2dvector( scrt4_vector_2d_3elist_v, 
                                      m12148, EMPTYLIST );
        POPSTACKTRACE( scrt4_vector_2d_3elist( X1 ) );
}

DEFTSCP( codetection_time_2dthunk_v );
DEFCSTRING( t13000, "TIME-THUNK" );
EXTERNTSCPP( codetection_current_2dtime, XAL0(  ) );
EXTERNTSCP( codetection_current_2dtime_v );
EXTERNTSCPP( scrt2__2d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2d_2dtwo_v );
EXTERNTSCPP( scrt2__3c_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3c_2dtwo_v );
EXTERNTSCPP( scrt2_inexact_2d_3eexact, XAL1( TSCP ) );
EXTERNTSCP( scrt2_inexact_2d_3eexact_v );
EXTERNTSCPP( scrt2_floor, XAL1( TSCP ) );
EXTERNTSCP( scrt2_floor_v );
EXTERNTSCPP( scrt2__2b_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2b_2dtwo_v );
EXTERNTSCPP( scrt2_log, XAL1( TSCP ) );
EXTERNTSCP( scrt2_log_v );
EXTERNTSCPP( scrt2__2f_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2f_2dtwo_v );
EXTERNTSCPP( scrt6_format, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt6_format_v );
EXTERNTSCPP( obischeme_dprecision_2841f1d3, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( obischeme_dprecision_2841f1d3_v );

TSCP  codetection_time_2dthunk( f12151, t12152 )
        TSCP  f12151, t12152;
{
        TSCP  X14, 
              X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13000 );
        X1 = codetection_current_2dtime(  );
        X3 = t12152;
        X3 = UNKNOWNCALL( X3, 0 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( PROCEDURE_CLOSURE( X3 ) );
        X3 = codetection_current_2dtime(  );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13005;
        X5 = _TSCP( IDIFFERENCE( _S2CINT( X3 ), 
                                 _S2CINT( X1 ) ) );
        goto L13006;
L13005:
        X5 = scrt2__2d_2dtwo( X3, X1 );
L13006:
        if  ( BITAND( BITOR( _S2CINT( X5 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13009;
        if  ( LT( _S2CINT( X5 ), _S2CINT( _TSCP( 4 ) ) ) )  goto L13013;
        goto L13014;
L13009:
        if  ( TRUE( scrt2__3c_2dtwo( X5, _TSCP( 4 ) ) ) )  goto L13013;
L13014:
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 4 ) ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L13018;
        X8 = _TSCP( IPLUS( _S2CINT( _TSCP( 4 ) ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L13019;
L13018:
        X8 = scrt2__2b_2dtwo( _TSCP( 4 ), _TSCP( 8 ) );
L13019:
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13020;
        X12 = _TSCP( IDIFFERENCE( _S2CINT( X3 ), 
                                  _S2CINT( X1 ) ) );
        goto L13021;
L13020:
        X12 = scrt2__2d_2dtwo( X3, X1 );
L13021:
        X11 = scrt2_log( X12 );
        X12 = scrt2_log( _TSCP( 40 ) );
        X13 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( X11 ), 
                                           _S2CINT( X12 ) ), 
                                    3 ) ) );
        if  ( FALSE( X13 ) )  goto L13033;
        if  ( EQ( _S2CUINT( X12 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13033;
        X14 = _TSCP( REMAINDER( _S2CINT( X11 ), 
                                _S2CINT( X12 ) ) );
        if  ( NEQ( _S2CUINT( X14 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13033;
        X10 = C_FIXED( QUOTIENT( _S2CINT( X11 ), 
                                 _S2CINT( X12 ) ) );
        goto L13034;
L13033:
        X10 = scrt2__2f_2dtwo( X11, X12 );
L13034:
        if  ( BITAND( BITOR( _S2CINT( X10 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13036;
        X9 = _TSCP( IPLUS( _S2CINT( X10 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L13037;
L13036:
        X9 = scrt2__2b_2dtwo( X10, _TSCP( 4 ) );
L13037:
        if  ( BITAND( BITOR( _S2CINT( X9 ), _S2CINT( X8 ) ), 
                      3 ) )  goto L13039;
        X7 = _TSCP( IPLUS( _S2CINT( X9 ), _S2CINT( X8 ) ) );
        goto L13040;
L13039:
        X7 = scrt2__2b_2dtwo( X9, X8 );
L13040:
        X6 = scrt2_floor( X7 );
        X4 = scrt2_inexact_2d_3eexact( X6 );
        goto L13042;
L13013:
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 8 ) ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L13041;
        X4 = _TSCP( IPLUS( _S2CINT( _TSCP( 8 ) ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L13042;
L13041:
        X4 = scrt2__2b_2dtwo( _TSCP( 8 ), _TSCP( 8 ) );
L13042:
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L13044;
        X6 = _TSCP( IDIFFERENCE( _S2CINT( X3 ), 
                                 _S2CINT( X1 ) ) );
        goto L13045;
L13044:
        X6 = scrt2__2d_2dtwo( X3, X1 );
L13045:
        X5 = CONS( obischeme_dprecision_2841f1d3( X6, 
                                                  X4, _TSCP( 8 ) ), 
                   EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( f12151, X5 ) );
        POPSTACKTRACE( X2 );
}

DEFTSCP( detection_2ddepth_2a_8800758e_v );
DEFCSTRING( t13046, "*TIME-DEPTH*" );
DEFTSCP( codetection_current_2dtime_v );
DEFCSTRING( t13047, "CURRENT-TIME" );
EXTERNTSCPP( scrt3_string_2dappend, XAL1( TSCP ) );
EXTERNTSCP( scrt3_string_2dappend_v );
EXTERNTSCPP( scrt2_number_2d_3estring, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_number_2d_3estring_v );
EXTERNTSCPP( qobischeme_getpid, XAL0(  ) );
EXTERNTSCP( qobischeme_getpid_v );
EXTERNTSCPP( scrt4_system, XAL1( TSCP ) );
EXTERNTSCP( scrt4_system_v );
EXTERNTSCPP( qobischeme_first, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_first_v );
EXTERNTSCPP( qobischeme_read_2dfile, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_read_2dfile_v );
EXTERNTSCPP( qobischeme_fields, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_fields_v );
EXTERNTSCPP( sc_cons, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_cons_v );
EXTERNTSCPP( scrt1__24__car_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__car_2derror_v );
EXTERNTSCPP( qobischeme_rm, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_rm_v );
EXTERNTSCPP( scrt2_string_2d_3enumber, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_string_2d_3enumber_v );
EXTERNTSCPP( qobischeme_second, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_second_v );

TSCP  codetection_current_2dtime(  )
{
        TSCP  X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13047 );
        X3 = qobischeme_getpid(  );
        X2 = CONS( scrt2_number_2d_3estring( X3, EMPTYLIST ), 
                   EMPTYLIST );
        X1 = scrt3_string_2dappend( CONS( c12285, X2 ) );
        X3 = CONS( X1, EMPTYLIST );
        X2 = scrt6_format( FALSEVALUE, CONS( c12237, X3 ) );
        scrt4_system( X2 );
        X4 = qobischeme_read_2dfile( X1 );
        X5 = X4;
        X6 = EMPTYLIST;
        X7 = EMPTYLIST;
L13052:
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L13053;
        X3 = X6;
        goto L13060;
L13053:
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L13056;
        scrt1__24__car_2derror( X5 );
L13056:
        X10 = PAIR_CAR( X5 );
        X9 = qobischeme_fields( X10 );
        X8 = sc_cons( X9, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X6 ), _S2CUINT( EMPTYLIST ) ) )  goto L13059;
        X9 = PAIR_CDR( X5 );
        X7 = X8;
        X6 = X8;
        X5 = X9;
        GOBACK( L13052 );
L13059:
        X9 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L13064;
        scdebug_error( c12275, 
                       c12276, CONS( X7, EMPTYLIST ) );
L13064:
        X7 = SETGEN( PAIR_CDR( X7 ), X8 );
        X5 = X9;
        GOBACK( L13052 );
L13060:
        X2 = qobischeme_first( X3 );
        qobischeme_rm( X1 );
        X4 = CONS( qobischeme_second( X2 ), EMPTYLIST );
        X4 = CONS( c12240, X4 );
        X3 = scrt3_string_2dappend( CONS( qobischeme_first( X2 ), 
                                          X4 ) );
        POPSTACKTRACE( scrt2_string_2d_3enumber( X3, EMPTYLIST ) );
}

DEFTSCP( codetection_video_2d_3eframes_v );
DEFCSTRING( t13067, "VIDEO->FRAMES" );
EXTERNTSCPP( scrt1_reverse, XAL1( TSCP ) );
EXTERNTSCP( scrt1_reverse_v );
EXTERNTSCPP( scrt2_modulo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_modulo_v );
EXTERNTSCPP( scrt2_zero_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt2_zero_3f_v );

TSCP  codetection_video_2d_3eframes( d12288, v12289 )
        TSCP  d12288, v12289;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13067 );
        X1 = detection_en_2dvideo_533bdb80( v12289 );
        X2 = EMPTYLIST;
        X3 = TRUEVALUE;
        X4 = _TSCP( 0 );
L13071:
        if  ( TRUE( X3 ) )  goto L13075;
        if  ( TRUE( detection_2dframe_21_b1305a3c( X1 ) ) )  goto L13075;
        detection_se_2dvideo_86ac5560( X1 );
        POPSTACKTRACE( scrt1_reverse( X2 ) );
L13075:
        X5 = scrt2_modulo( X4, d12288 );
        if  ( NEQ( TSCPTAG( X5 ), FIXNUMTAG ) )  goto L13081;
        if  ( EQ( _S2CUINT( X5 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L13085;
        goto L13086;
L13081:
        if  ( FALSE( scrt2_zero_3f( X5 ) ) )  goto L13086;
L13085:
        X6 = detection_as_2dimlib_568385cf( X1 );
        X5 = sc_cons( X6, X2 );
        if  ( BITAND( BITOR( _S2CINT( X4 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13089;
        X4 = _TSCP( IPLUS( _S2CINT( X4 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L13090;
L13089:
        X4 = scrt2__2b_2dtwo( X4, _TSCP( 4 ) );
L13090:
        X3 = FALSEVALUE;
        X2 = X5;
        GOBACK( L13071 );
L13086:
        if  ( BITAND( BITOR( _S2CINT( X4 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13091;
        X4 = _TSCP( IPLUS( _S2CINT( X4 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L13092;
L13091:
        X4 = scrt2__2b_2dtwo( X4, _TSCP( 4 ) );
L13092:
        X3 = FALSEVALUE;
        GOBACK( L13071 );
}

DEFTSCP( detection_h_2dframes_1953d4f1_v );
DEFCSTRING( t13093, "PROPOSALS&SIMILARITY-WITH-FRAMES" );
EXTERNTSCPP( scrt1_length, XAL1( TSCP ) );
EXTERNTSCP( scrt1_length_v );
EXTERNTSCPP( _2dmatlab_dmatlab_21_16b982d3, XAL0(  ) );
EXTERNTSCP( _2dmatlab_dmatlab_21_16b982d3_v );
EXTERNTSCPP( toollib_2dmatlab_matlab, XAL1( TSCP ) );
EXTERNTSCP( toollib_2dmatlab_matlab_v );
EXTERNTSCPP( obischeme__2dindexed_d1069d4, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( obischeme__2dindexed_d1069d4_v );
EXTERNTSCPP( obischeme_ary_2dfile_15e4569d, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( obischeme_ary_2dfile_15e4569d_v );

TSCP  codetection_l12347( t12348, c13101 )
        TSCP  t12348, c13101;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "codetection_l12347 [inside PROPOSALS&SIMILARITY-WIT\
H-FRAMES]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13101, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c13101, 1 );
        detection_ve_2dimage_2fa5fc03( DISPLAY( 0 ), t12348 );
        X4 = CONS( t12348, EMPTYLIST );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12349, X4 ) ), 
                                       EMPTYLIST ) );
        X5 = DISPLAY( 1 );
        if  ( BITAND( BITOR( _S2CINT( X5 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13104;
        X6 = _TSCP( IPLUS( _S2CINT( X5 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L13105;
L13104:
        X6 = scrt2__2b_2dtwo( X5, _TSCP( 4 ) );
L13105:
        X4 = CONS( X6, EMPTYLIST );
        X3 = toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                          CONS( c12350, 
                                                                X4 ) ), 
                                            EMPTYLIST ) );
        DISPLAY( 0 ) = X1;
        DISPLAY( 1 ) = X2;
        POPSTACKTRACE( X3 );
}

TSCP  codetection_l12343( f12344, i12345, c13099 )
        TSCP  f12344, i12345, c13099;
{
        TSCP  X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "codetection_l12343 [inside PROPOSALS&SIMILARITY-WIT\
H-FRAMES]" );
        DISPLAY( 0 ) = f12344;
        DISPLAY( 1 ) = i12345;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            codetection_l12347, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        obischeme_ary_2dfile_15e4569d( c12346, X1 );
        SDVAL = detection__2ddecache_2ab0af57( DISPLAY( 0 ) );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

EXTERNTSCPP( qobischeme_map_2dn, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dn_v );
EXTERNTSCPP( _2dmatlab_2dvariable_a304468f, XAL1( TSCP ) );
EXTERNTSCP( _2dmatlab_2dvariable_a304468f_v );

TSCP  codetection_l12360( t12361, c13106 )
        TSCP  t12361, c13106;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "codetection_l12360 [inside PROPOSALS&SIMILARITY-WIT\
H-FRAMES]" );
        if  ( BITAND( BITOR( _S2CINT( t12361 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13108;
        X2 = _TSCP( IPLUS( _S2CINT( t12361 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L13109;
L13108:
        X2 = scrt2__2b_2dtwo( t12361, _TSCP( 4 ) );
L13109:
        X1 = CONS( X2, EMPTYLIST );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12362, X1 ) ), 
                                       EMPTYLIST ) );
        POPSTACKTRACE( _2dmatlab_2dvariable_a304468f( c12369 ) );
}

TSCP  codetection_l12370( t12371, c13110 )
        TSCP  t12371, c13110;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "codetection_l12370 [inside PROPOSALS&SIMILARITY-WIT\
H-FRAMES]" );
        if  ( BITAND( BITOR( _S2CINT( t12371 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13112;
        X2 = _TSCP( IPLUS( _S2CINT( t12371 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L13113;
L13112:
        X2 = scrt2__2b_2dtwo( t12371, _TSCP( 4 ) );
L13113:
        X1 = CONS( X2, EMPTYLIST );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12372, X1 ) ), 
                                       EMPTYLIST ) );
        POPSTACKTRACE( _2dmatlab_2dvariable_a304468f( c12369 ) );
}

TSCP  detection_h_2dframes_1953d4f1( t12330, b12331, f12332 )
        TSCP  t12330, b12331, f12332;
{
        TSCP  X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t13093 );
        X1 = scrt1_length( f12332 );
        X2 = qobischeme_first( f12332 );
        X3 = codetection_imlib_3aheight( X2 );
        X4 = codetection_imlib_3awidth( X2 );
        _2dmatlab_dmatlab_21_16b982d3(  );
        X5 = CONS( X1, EMPTYLIST );
        X5 = CONS( _TSCP( 12 ), X5 );
        X5 = CONS( X4, X5 );
        X5 = CONS( X3, X5 );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12341, X5 ) ), 
                                       EMPTYLIST ) );
        X5 = MAKEPROCEDURE( 2, 
                            0, codetection_l12343, EMPTYLIST );
        obischeme__2dindexed_d1069d4( X5, f12332 );
        X5 = CONS( b12331, EMPTYLIST );
        X5 = CONS( t12330, X5 );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12357, X5 ) ), 
                                       EMPTYLIST ) );
        X7 = MAKEPROCEDURE( 1, 
                            0, codetection_l12360, EMPTYLIST );
        X6 = qobischeme_map_2dn( X7, X1 );
        X9 = MAKEPROCEDURE( 1, 
                            0, codetection_l12370, EMPTYLIST );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L13114;
        X10 = _TSCP( IDIFFERENCE( _S2CINT( X1 ), 
                                  _S2CINT( _TSCP( 4 ) ) ) );
        goto L13115;
L13114:
        X10 = scrt2__2d_2dtwo( X1, _TSCP( 4 ) );
L13115:
        X8 = qobischeme_map_2dn( X9, X10 );
        X7 = sc_cons( X8, EMPTYLIST );
        X5 = sc_cons( X6, X7 );
        POPSTACKTRACE( X5 );
}

DEFTSCP( detection_similarity_5480bfa9_v );
DEFCSTRING( t13117, "PROPOSALS&SIMILARITY" );

TSCP  detection_similarity_5480bfa9( t12387, 
                                     b12388, d12389, v12390 )
        TSCP  t12387, b12388, d12389, v12390;
{
        TSCP  X1;

        PUSHSTACKTRACE( t13117 );
        X1 = codetection_video_2d_3eframes( d12389, v12390 );
        POPSTACKTRACE( detection_h_2dframes_1953d4f1( t12387, 
                                                      b12388, X1 ) );
}

DEFTSCP( detection_dinference_c51c122d_v );
DEFCSTRING( t13119, "BP-OBJECT-INFERENCE" );

TSCP  detection_dinference_c51c122d( g12393, 
                                     g12394, 
                                     g12395, g12396, g12397 )
        TSCP  g12393, g12394, g12395, g12396, g12397;
{
        PUSHSTACKTRACE( t13119 );
        POPSTACKTRACE( DOUBLE_TSCP( bp_object_inference( TSCP_POINTER( g12393 ), 
                                                         TSCP_POINTER( g12394 ), 
                                                         sc_tscp_int( g12395 ), 
                                                         sc_tscp_int( g12396 ), 
                                                         TSCP_POINTER( g12397 ) ) ) );
}

DEFTSCP( codetection_main_v );
DEFCSTRING( t13121, "MAIN" );
EXTERNTSCPP( scrt2_round, XAL1( TSCP ) );
EXTERNTSCP( scrt2_round_v );

TSCP  codetection_i12409( s12415, u12416 )
        TSCP  s12415, u12416;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "INTEGER-ARGUMENT [inside MAIN]" );
        X1 = scrt2_string_2d_3enumber( s12415, EMPTYLIST );
        if  ( EQ( TSCPTAG( X1 ), FIXNUMTAG ) )  goto L13141;
        if  ( NOT( AND( EQ( TSCPTAG( X1 ), EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( X1 ), 
                            DOUBLEFLOATTAG ) ) ) )  goto L13140;
        X2 = scrt2_round( X1 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L13133;
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( X2 ) ) )  goto L13140;
        goto L13141;
L13133:
        if  ( TRUE( scrt2__3d_2dtwo( X1, X2 ) ) )  goto L13141;
L13140:
        X2 = u12416;
        X2 = UNKNOWNCALL( X2, 0 );
        VIA( PROCEDURE_CODE( X2 ) )( PROCEDURE_CLOSURE( X2 ) );
L13141:
        POPSTACKTRACE( X1 );
}

TSCP  codetection_r12408( s12443, u12444 )
        TSCP  s12443, u12444;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "REAL-ARGUMENT [inside MAIN]" );
        X1 = scrt2_string_2d_3enumber( s12443, EMPTYLIST );
        if  ( EQ( TSCPTAG( X1 ), FIXNUMTAG ) )  goto L13146;
        if  ( AND( EQ( TSCPTAG( X1 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X1 ), DOUBLEFLOATTAG ) )
            )  goto L13146;
        X2 = u12444;
        X2 = UNKNOWNCALL( X2, 0 );
        VIA( PROCEDURE_CODE( X2 ) )( PROCEDURE_CLOSURE( X2 ) );
L13146:
        POPSTACKTRACE( X1 );
}

EXTERNTSCP( scrt5_stderr_2dport_v );
EXTERNTSCP( screp_exit_v );

TSCP  codetection_u12460( c13150 )
        TSCP  c13150;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "USAGE [inside MAIN]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c13150, 0 );
        X3 = CONS( DISPLAY( 0 ), EMPTYLIST );
        scrt6_format( scrt5_stderr_2dport_v, 
                      CONS( c12462, X3 ) );
        X3 = screp_exit_v;
        X3 = UNKNOWNCALL( X3, 1 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( _TSCP( -4 ), 
                                          PROCEDURE_CLOSURE( X3 ) );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

EXTERNTSCPP( qobischeme_rest, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_rest_v );
EXTERNTSCP( sc_emptystring );
EXTERNTSCPP( scrt3_string_3d_3f, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt3_string_3d_3f_v );
EXTERNTSCPP( qobischeme_but_2dlast, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_but_2dlast_v );
EXTERNTSCPP( qobischeme_fifth, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_fifth_v );
EXTERNTSCP( asy_2dffi_e_2dto_2dc_6e7b37fb_v );
EXTERNTSCPP( dbindings_ct_2darray_b6f75c47, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings_ct_2darray_b6f75c47_v );
EXTERNTSCP( scrt4_c_2dsizeof_2dint_v );
EXTERNTSCPP( scrt2__2a_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2a_2dtwo_v );
EXTERNTSCP( toollib_2dc_2dbindings_malloc_v );

TSCP  codetection_l12603( __12604, c13281 )
        TSCP  __12604, c13281;
{
        PUSHSTACKTRACE( "codetection_l12603 [inside MAIN]" );
        POPSTACKTRACE( _TSCP( 0 ) );
}

EXTERNTSCPP( dbindings__2d_3elist_28c4290c, 
             XAL4( TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( dbindings__2d_3elist_28c4290c_v );
EXTERNTSCP( toollib_2dc_2dbindings_free_v );
EXTERNTSCPP( easy_2dffi_easy_2dffi_3afree, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( easy_2dffi_easy_2dffi_3afree_v );
EXTERNTSCPP( scrt6_pp, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt6_pp_v );
EXTERNTSCPP( scrt1_list_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_list_2dref_v );

TSCP  codetection_main( a12406 )
        TSCP  a12406;
{
        TSCP  X30, 
              X29, 
              X28, 
              X27, 
              X26, 
              X25, 
              X24, 
              X23, 
              X22, 
              X21, 
              X20, 
              X19, 
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
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t13121 );
        a12406 = CONS( a12406, EMPTYLIST );
        DISPLAY( 0 ) = qobischeme_first( PAIR_CAR( a12406 ) );
        X1 = _TSCP( 0 );
        X1 = CONS( X1, EMPTYLIST );
        X2 = MAKEPROCEDURE( 0, 
                            0, 
                            codetection_u12460, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        SETGEN( PAIR_CAR( X1 ), X2 );
        X2 = qobischeme_rest( PAIR_CAR( a12406 ) );
        SETGEN( PAIR_CAR( a12406 ), X2 );
        X2 = _TSCP( 256 );
        X3 = FALSEVALUE;
        X4 = _TSCP( 4 );
        X5 = FALSEVALUE;
        X6 = _TSCP( 400 );
        X7 = FALSEVALUE;
        X8 = sc_emptystring;
        X9 = FALSEVALUE;
        X9 = CONS( X9, EMPTYLIST );
        X8 = CONS( X8, EMPTYLIST );
        X7 = CONS( X7, EMPTYLIST );
        X6 = CONS( X6, EMPTYLIST );
        X5 = CONS( X5, EMPTYLIST );
        X4 = CONS( X4, EMPTYLIST );
        X3 = CONS( X3, EMPTYLIST );
        X2 = CONS( X2, EMPTYLIST );
L13153:
        if  ( EQ( _S2CUINT( PAIR_CAR( a12406 ) ), 
                  _S2CUINT( EMPTYLIST ) ) )  goto L13186;
        X10 = qobischeme_first( PAIR_CAR( a12406 ) );
        if  ( FALSE( scrt3_string_3d_3f( X10, c12483 ) ) )  goto L13157;
        X10 = qobischeme_rest( PAIR_CAR( a12406 ) );
        SETGEN( PAIR_CAR( a12406 ), X10 );
        if  ( FALSE( PAIR_CAR( X9 ) ) )  goto L13160;
        codetection_u12460( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L13160:
        X10 = TRUEVALUE;
        SETGEN( PAIR_CAR( X9 ), X10 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a12406 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L13162;
        codetection_u12460( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L13162:
        X11 = qobischeme_first( PAIR_CAR( a12406 ) );
        X12 = PAIR_CAR( X1 );
        X10 = X11;
        SETGEN( PAIR_CAR( X8 ), X10 );
        X10 = qobischeme_rest( PAIR_CAR( a12406 ) );
        SETGEN( PAIR_CAR( a12406 ), X10 );
        GOBACK( L13153 );
L13157:
        X10 = qobischeme_first( PAIR_CAR( a12406 ) );
        if  ( FALSE( scrt3_string_3d_3f( X10, c12484 ) ) )  goto L13165;
        X10 = qobischeme_rest( PAIR_CAR( a12406 ) );
        SETGEN( PAIR_CAR( a12406 ), X10 );
        if  ( FALSE( PAIR_CAR( X7 ) ) )  goto L13168;
        codetection_u12460( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L13168:
        X10 = TRUEVALUE;
        SETGEN( PAIR_CAR( X7 ), X10 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a12406 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L13170;
        codetection_u12460( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L13170:
        X11 = qobischeme_first( PAIR_CAR( a12406 ) );
        X10 = codetection_i12409( X11, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X6 ), X10 );
        X10 = qobischeme_rest( PAIR_CAR( a12406 ) );
        SETGEN( PAIR_CAR( a12406 ), X10 );
        GOBACK( L13153 );
L13165:
        X10 = qobischeme_first( PAIR_CAR( a12406 ) );
        if  ( FALSE( scrt3_string_3d_3f( X10, c12485 ) ) )  goto L13172;
        X10 = qobischeme_rest( PAIR_CAR( a12406 ) );
        SETGEN( PAIR_CAR( a12406 ), X10 );
        if  ( FALSE( PAIR_CAR( X5 ) ) )  goto L13175;
        codetection_u12460( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L13175:
        X10 = TRUEVALUE;
        SETGEN( PAIR_CAR( X5 ), X10 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a12406 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L13177;
        codetection_u12460( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L13177:
        X11 = qobischeme_first( PAIR_CAR( a12406 ) );
        X10 = codetection_i12409( X11, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X4 ), X10 );
        X10 = qobischeme_rest( PAIR_CAR( a12406 ) );
        SETGEN( PAIR_CAR( a12406 ), X10 );
        GOBACK( L13153 );
L13172:
        X10 = qobischeme_first( PAIR_CAR( a12406 ) );
        if  ( FALSE( scrt3_string_3d_3f( X10, c12486 ) ) )  goto L13179;
        X10 = qobischeme_rest( PAIR_CAR( a12406 ) );
        SETGEN( PAIR_CAR( a12406 ), X10 );
        if  ( FALSE( PAIR_CAR( X3 ) ) )  goto L13182;
        codetection_u12460( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L13182:
        X10 = TRUEVALUE;
        SETGEN( PAIR_CAR( X3 ), X10 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a12406 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L13184;
        codetection_u12460( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L13184:
        X11 = qobischeme_first( PAIR_CAR( a12406 ) );
        X10 = codetection_i12409( X11, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X2 ), X10 );
        X10 = qobischeme_rest( PAIR_CAR( a12406 ) );
        SETGEN( PAIR_CAR( a12406 ), X10 );
        GOBACK( L13153 );
L13179:
        X10 = qobischeme_first( PAIR_CAR( a12406 ) );
        if  ( FALSE( scrt3_string_3d_3f( X10, c12487 ) ) )  goto L13186;
        codetection_u12460( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L13186:
        if  ( EQ( _S2CUINT( PAIR_CAR( a12406 ) ), 
                  _S2CUINT( EMPTYLIST ) ) )  goto L13188;
        codetection_u12460( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L13188:
        X10 = detection_similarity_5480bfa9( PAIR_CAR( X6 ), 
                                             PAIR_CAR( X2 ), 
                                             PAIR_CAR( X4 ), 
                                             PAIR_CAR( X8 ) );
        X12 = qobischeme_first( X10 );
        X13 = X12;
        X14 = EMPTYLIST;
        X15 = EMPTYLIST;
L13193:
        if  ( NEQ( _S2CUINT( X13 ), _S2CUINT( EMPTYLIST ) ) )  goto L13194;
        X11 = X14;
        goto L13218;
L13194:
        if  ( EQ( TSCPTAG( X13 ), PAIRTAG ) )  goto L13197;
        scrt1__24__car_2derror( X13 );
L13197:
        X18 = PAIR_CAR( X13 );
        X19 = detection_of_2dlists_13af153a( X18 );
        X20 = X19;
        X21 = EMPTYLIST;
        X22 = EMPTYLIST;
L13202:
        if  ( NEQ( _S2CUINT( X20 ), _S2CUINT( EMPTYLIST ) ) )  goto L13203;
        X17 = X21;
        goto L13210;
L13203:
        if  ( EQ( TSCPTAG( X20 ), PAIRTAG ) )  goto L13206;
        scrt1__24__car_2derror( X20 );
L13206:
        X25 = PAIR_CAR( X20 );
        X24 = qobischeme_but_2dlast( X25 );
        X23 = sc_cons( X24, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X21 ), _S2CUINT( EMPTYLIST ) ) )  goto L13209;
        X24 = PAIR_CDR( X20 );
        X22 = X23;
        X21 = X23;
        X20 = X24;
        GOBACK( L13202 );
L13209:
        X24 = PAIR_CDR( X20 );
        if  ( EQ( TSCPTAG( X22 ), PAIRTAG ) )  goto L13214;
        scdebug_error( c12275, 
                       c12276, CONS( X22, EMPTYLIST ) );
L13214:
        X22 = SETGEN( PAIR_CDR( X22 ), X23 );
        X20 = X24;
        GOBACK( L13202 );
L13210:
        X16 = sc_cons( X17, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X14 ), _S2CUINT( EMPTYLIST ) ) )  goto L13217;
        X17 = PAIR_CDR( X13 );
        X15 = X16;
        X14 = X16;
        X13 = X17;
        GOBACK( L13193 );
L13217:
        X17 = PAIR_CDR( X13 );
        if  ( EQ( TSCPTAG( X15 ), PAIRTAG ) )  goto L13222;
        scdebug_error( c12275, 
                       c12276, CONS( X15, EMPTYLIST ) );
L13222:
        X15 = SETGEN( PAIR_CDR( X15 ), X16 );
        X13 = X17;
        GOBACK( L13193 );
L13218:
        X13 = qobischeme_first( X10 );
        X14 = X13;
        X15 = EMPTYLIST;
        X16 = EMPTYLIST;
L13227:
        if  ( NEQ( _S2CUINT( X14 ), _S2CUINT( EMPTYLIST ) ) )  goto L13228;
        X12 = X15;
        goto L13252;
L13228:
        if  ( EQ( TSCPTAG( X14 ), PAIRTAG ) )  goto L13231;
        scrt1__24__car_2derror( X14 );
L13231:
        X19 = PAIR_CAR( X14 );
        X20 = detection_of_2dlists_13af153a( X19 );
        X21 = X20;
        X22 = EMPTYLIST;
        X23 = EMPTYLIST;
L13236:
        if  ( NEQ( _S2CUINT( X21 ), _S2CUINT( EMPTYLIST ) ) )  goto L13237;
        X18 = X22;
        goto L13244;
L13237:
        if  ( EQ( TSCPTAG( X21 ), PAIRTAG ) )  goto L13240;
        scrt1__24__car_2derror( X21 );
L13240:
        X26 = PAIR_CAR( X21 );
        X25 = qobischeme_fifth( X26 );
        X24 = sc_cons( X25, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X22 ), _S2CUINT( EMPTYLIST ) ) )  goto L13243;
        X25 = PAIR_CDR( X21 );
        X23 = X24;
        X22 = X24;
        X21 = X25;
        GOBACK( L13236 );
L13243:
        X25 = PAIR_CDR( X21 );
        if  ( EQ( TSCPTAG( X23 ), PAIRTAG ) )  goto L13248;
        scdebug_error( c12275, 
                       c12276, CONS( X23, EMPTYLIST ) );
L13248:
        X23 = SETGEN( PAIR_CDR( X23 ), X24 );
        X21 = X25;
        GOBACK( L13236 );
L13244:
        X17 = sc_cons( X18, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X15 ), _S2CUINT( EMPTYLIST ) ) )  goto L13251;
        X18 = PAIR_CDR( X14 );
        X16 = X17;
        X15 = X17;
        X14 = X18;
        GOBACK( L13227 );
L13251:
        X18 = PAIR_CDR( X14 );
        if  ( EQ( TSCPTAG( X16 ), PAIRTAG ) )  goto L13256;
        scdebug_error( c12275, 
                       c12276, CONS( X16, EMPTYLIST ) );
L13256:
        X16 = SETGEN( PAIR_CDR( X16 ), X17 );
        X14 = X18;
        GOBACK( L13227 );
L13252:
        X14 = qobischeme_second( X10 );
        X15 = X14;
        X16 = EMPTYLIST;
        X17 = EMPTYLIST;
L13261:
        if  ( NEQ( _S2CUINT( X15 ), _S2CUINT( EMPTYLIST ) ) )  goto L13262;
        X13 = X16;
        goto L13269;
L13262:
        if  ( EQ( TSCPTAG( X15 ), PAIRTAG ) )  goto L13265;
        scrt1__24__car_2derror( X15 );
L13265:
        X20 = PAIR_CAR( X15 );
        X19 = detection_of_2dlists_13af153a( X20 );
        X18 = sc_cons( X19, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X16 ), _S2CUINT( EMPTYLIST ) ) )  goto L13268;
        X19 = PAIR_CDR( X15 );
        X17 = X18;
        X16 = X18;
        X15 = X19;
        GOBACK( L13261 );
L13268:
        X19 = PAIR_CDR( X15 );
        if  ( EQ( TSCPTAG( X17 ), PAIRTAG ) )  goto L13273;
        scdebug_error( c12275, 
                       c12276, CONS( X17, EMPTYLIST ) );
L13273:
        X17 = SETGEN( PAIR_CDR( X17 ), X18 );
        X15 = X19;
        GOBACK( L13261 );
L13269:
        X15 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X15 = UNKNOWNCALL( X15, 2 );
        X14 = VIA( PROCEDURE_CODE( X15 ) )( _TSCP( 8 ), 
                                            X12, 
                                            PROCEDURE_CLOSURE( X15 ) );
        X16 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X16 = UNKNOWNCALL( X16, 2 );
        X15 = VIA( PROCEDURE_CODE( X16 ) )( _TSCP( 12 ), 
                                            X13, 
                                            PROCEDURE_CLOSURE( X16 ) );
        X20 = scrt1_length( X12 );
        X21 = scrt4_c_2dsizeof_2dint_v;
        if  ( BITAND( BITOR( _S2CINT( X21 ), 
                             _S2CINT( X20 ) ), 
                      3 ) )  goto L13279;
        X19 = _TSCP( ITIMES( FIXED_C( X21 ), 
                             _S2CINT( X20 ) ) );
        goto L13280;
L13279:
        X19 = scrt2__2a_2dtwo( X21, X20 );
L13280:
        X18 = toollib_2dc_2dbindings_malloc_v;
        X18 = UNKNOWNCALL( X18, 1 );
        X17 = VIA( PROCEDURE_CODE( X18 ) )( X19, 
                                            PROCEDURE_CLOSURE( X18 ) );
        X19 = MAKEPROCEDURE( 0, 
                             1, codetection_l12603, EMPTYLIST );
        X20 = scrt1_length( X12 );
        X18 = qobischeme_map_2dn( X19, X20 );
        X16 = dbindings_ct_2darray_b6f75c47( X17, 
                                             X18, 
                                             scrt4_c_2dsizeof_2dint_v, 
                                             TRUEVALUE );
        X18 = scrt1_length( X12 );
        X17 = detection_dinference_c51c122d( X14, 
                                             X15, 
                                             X18, 
                                             PAIR_CAR( X6 ), X16 );
        X19 = scrt1_length( X12 );
        X18 = dbindings__2d_3elist_28c4290c( X16, 
                                             scrt4_c_2dsizeof_2dint_v, 
                                             X19, TRUEVALUE );
        X19 = toollib_2dc_2dbindings_free_v;
        X19 = UNKNOWNCALL( X19, 1 );
        VIA( PROCEDURE_CODE( X19 ) )( X16, 
                                      PROCEDURE_CLOSURE( X19 ) );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 8 ), X12, X14 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 12 ), X13, X15 );
        X20 = X18;
        X21 = X11;
        X22 = EMPTYLIST;
        X23 = EMPTYLIST;
L13287:
        if  ( NEQ( _S2CUINT( X20 ), _S2CUINT( EMPTYLIST ) ) )  goto L13288;
        X19 = X22;
        goto L13300;
L13288:
        if  ( EQ( TSCPTAG( X20 ), PAIRTAG ) )  goto L13291;
        scrt1__24__car_2derror( X20 );
L13291:
        X26 = PAIR_CAR( X20 );
        if  ( EQ( TSCPTAG( X21 ), PAIRTAG ) )  goto L13294;
        scrt1__24__car_2derror( X21 );
L13294:
        X27 = PAIR_CAR( X21 );
        X30 = scrt1_list_2dref( X27, X26 );
        X29 = sc_cons( X30, EMPTYLIST );
        X28 = sc_cons( X26, X29 );
        X25 = X28;
        X24 = sc_cons( X25, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X22 ), _S2CUINT( EMPTYLIST ) ) )  goto L13299;
        X25 = PAIR_CDR( X20 );
        X26 = PAIR_CDR( X21 );
        X23 = X24;
        X22 = X24;
        X21 = X26;
        X20 = X25;
        GOBACK( L13287 );
L13299:
        X25 = PAIR_CDR( X20 );
        X26 = PAIR_CDR( X21 );
        if  ( EQ( TSCPTAG( X23 ), PAIRTAG ) )  goto L13306;
        scdebug_error( c12275, 
                       c12276, CONS( X23, EMPTYLIST ) );
L13306:
        X23 = SETGEN( PAIR_CDR( X23 ), X24 );
        X21 = X26;
        X20 = X25;
        GOBACK( L13287 );
L13300:
        SDVAL = scrt6_pp( X19, EMPTYLIST );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

void  codetection__init(){}
void toollib_2dc_2dbindings__init();
void easy_2dffi__init();
void screp__init();
void scrt5__init();
void toollib_2dmatlab__init();
void scrt1__init();
void scrt3__init();
void scrt6__init();
void scrt4__init();
void scrt2__init();
void scdebug__init();
void qobischeme__init();
void qobischeme__init();
void xlib__init();
void pregexp__init();
void toollib_2dmatlab__init();
void toollib_2dc_2dbindings__init();
void easy_2dffi__init();

static void  init_modules( compiler_version )
        char *compiler_version;
{
        toollib_2dc_2dbindings__init();
        easy_2dffi__init();
        screp__init();
        scrt5__init();
        toollib_2dmatlab__init();
        scrt1__init();
        scrt3__init();
        scrt6__init();
        scrt4__init();
        scrt2__init();
        scdebug__init();
        qobischeme__init();
        qobischeme__init();
        xlib__init();
        pregexp__init();
        toollib_2dmatlab__init();
        toollib_2dc_2dbindings__init();
        easy_2dffi__init();
        MAXDISPLAY( 2 );
}

int main( int argc, char *argv[] )
{
        static int  init = 0;
        if  (init)  return 1;
        init = 1;
        INITHEAP( 0, argc, argv, codetection_main );
        init_constants();
        init_modules( "(codetection SCHEME->C COMPILER 15mar93jfb)" );
        sc_segv__handlers();
        INITIALIZEVAR( t12900, 
                       ADR( detection_on_2d1_2d0_9fcc6ee3_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      detection_on_2d1_2d0_9fcc6ee3, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12902, 
                       ADR( detection_on_2d3_2d0_e50c3d83_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      detection_on_2d3_2d0_e50c3d83, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12904, 
                       ADR( detection_on_2d5_2d0_6a4cc823_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      detection_on_2d5_2d0_6a4cc823, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12906, 
                       ADR( detection_on_2d7_2d0_108c9b43_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      detection_on_2d7_2d0_108c9b43, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12908, 
                       ADR( detection_on_2d9_2d0_afbc2522_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      detection_on_2d9_2d0_afbc2522, 
                                      EMPTYLIST ) );
        qobischeme__2aprogram_2a_v = c11956;
        qobischeme__2apanic_3f_2a_v = FALSEVALUE;
        INITIALIZEVAR( t12910, 
                       ADR( detection_ib_2dimage_37692324_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      detection_ib_2dimage_37692324, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12925, 
                       ADR( codetection_imlib_2dimage_3f_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetection_imlib_2dimage_3f, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12941, 
                       ADR( detection_dhandle_21_b97b087a_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      detection_dhandle_21_b97b087a, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12945, 
                       ADR( detection_e_2dhandle_f4eee504_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      detection_e_2dhandle_f4eee504, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12956, 
                       ADR( detection_dhandle_21_b251c829_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      detection_dhandle_21_b251c829, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12967, 
                       ADR( detection_en_2dvideo_533bdb80_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      detection_en_2dvideo_533bdb80, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12969, 
                       ADR( detection_as_2dimlib_568385cf_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      detection_as_2dimlib_568385cf, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12971, 
                       ADR( detection_se_2dvideo_86ac5560_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      detection_se_2dvideo_86ac5560, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12974, 
                       ADR( detection_2dframe_21_b1305a3c_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      detection_2dframe_21_b1305a3c, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12981, 
                       ADR( detection_2dimage_21_95f0e0d1_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      detection_2dimage_21_95f0e0d1, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12984, 
                       ADR( detection__2ddecache_2ab0af57_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      detection__2ddecache_2ab0af57, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12987, 
                       ADR( detection_ve_2dimage_2fa5fc03_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      detection_ve_2dimage_2fa5fc03, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12990, 
                       ADR( codetection_imlib_3aheight_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetection_imlib_3aheight, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12992, 
                       ADR( codetection_imlib_3awidth_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetection_imlib_3awidth, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12994, 
                       ADR( codetection_imlib_3aclone_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetection_imlib_3aclone, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12996, 
                       ADR( detection_ead_2donly_f41bd75e_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      detection_ead_2donly_f41bd75e, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t12998, 
                       ADR( detection_of_2dlists_13af153a_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      detection_of_2dlists_13af153a, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13000, 
                       ADR( codetection_time_2dthunk_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      codetection_time_2dthunk, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13046, 
                       ADR( detection_2ddepth_2a_8800758e_v ), 
                       _TSCP( 0 ) );
        INITIALIZEVAR( t13047, 
                       ADR( codetection_current_2dtime_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      codetection_current_2dtime, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13067, 
                       ADR( codetection_video_2d_3eframes_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      codetection_video_2d_3eframes, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13093, 
                       ADR( detection_h_2dframes_1953d4f1_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      detection_h_2dframes_1953d4f1, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13117, 
                       ADR( detection_similarity_5480bfa9_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      detection_similarity_5480bfa9, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13119, 
                       ADR( detection_dinference_c51c122d_v ), 
                       MAKEPROCEDURE( 5, 
                                      0, 
                                      detection_dinference_c51c122d, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t13121, 
                       ADR( codetection_main_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetection_main, EMPTYLIST ) );
        codetection_main( CLARGUMENTS( argc, argv ) );
        SCHEMEEXIT();
        return 0;
}
