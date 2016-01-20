
/* SCHEME->C */

#include <objects.h>

int main();
DEFCSTRING( t16073, "-" );
DEFSTATICTSCP( c15865 );
DEFCSTRING( t16074, "_" );
DEFSTATICTSCP( c15864 );
DEFCSTRING( t16075, 
            "/home/yu239/darpa-collaboration/sentence-codetection/videos-fil\
es/" );
DEFSTATICTSCP( c15863 );
DEFCSTRING( t16076, "~a/videos-~a-amt-~a.sc" );
DEFSTATICTSCP( c15862 );
DEFCSTRING( t16077, "~a/~a/folds/~a.txt" );
DEFSTATICTSCP( c15861 );
DEFCSTRING( t16078, "/net/zhineng/aux/yu239/~a/~a.avi" );
DEFSTATICTSCP( c15860 );
DEFCSTRING( t16079, "house" );
DEFSTATICTSCP( c15815 );
DEFCSTRING( t16080, "VIDEOS (sorted in alphabet order):~%" );
DEFSTATICTSCP( c15802 );
DEFCSTRING( t16081, 
            "(MAP (LAMBDA (FRAMES-MOVIE VIDEO-PATH) (PROPOSALS-WITH-FRAMES P\
OOL-SIZE FRAMES-MOVIE (STRIP-EXTENSION VIDEO-PATH) ON-THE-FLY? WRITE?)) FRAM\
ES-MENU VIDEO-PATHS)" );
DEFSTATICTSCP( c15539 );
DEFCSTRING( t16082, "~a~~a : ~a~%" );
DEFSTATICTSCP( c15537 );
DEFCSTRING( t16083, "~a ~%" );
DEFSTATICTSCP( c14977 );
DEFCSTRING( t16084, 
            " f-max:~a f-median:~a f-min:~a~% u-max:~a u-median:~a u-min:~a~\
% h-max:~a h-median:~a h-min:~a~%" );
DEFSTATICTSCP( c14392 );
DEFSTATICTSCP( c14217 );
DEFSTATICTSCP( t16085 );
DEFCSTRING( t16086, "~a/~a-~a-~a-~a" );
DEFSTATICTSCP( c14193 );
DEFCSTRING( t16087, "~a/tracks.sc" );
DEFSTATICTSCP( c14192 );
DEFCSTRING( t16088, "writing tracks to file...~%" );
DEFSTATICTSCP( c14102 );
DEFCSTRING( t16089, "~a/tracked" );
DEFSTATICTSCP( c14101 );
DEFCSTRING( t16090, "generating result video...~%" );
DEFSTATICTSCP( c14100 );
DEFCSTRING( t16091, "mkdir -p ~a" );
DEFSTATICTSCP( c14099 );
DEFCSTRING( t16092, "wrong mode" );
DEFSTATICTSCP( c13854 );
DEFCSTRING( t16093, "complete" );
DEFSTATICTSCP( c13853 );
DEFCSTRING( t16094, "loop" );
DEFSTATICTSCP( c13852 );
DEFCSTRING( t16095, "output-tracks-dir:              ~a~%" );
DEFSTATICTSCP( c13836 );
DEFCSTRING( t16096, "handle-rotation?:               ~a~%" );
DEFSTATICTSCP( c13835 );
DEFCSTRING( t16097, "try-hard?:                      ~a~%" );
DEFSTATICTSCP( c13834 );
DEFCSTRING( t16098, "write-proposals?:               ~a~%" );
DEFSTATICTSCP( c13833 );
DEFCSTRING( t16099, "tracks-on-the-fly?:             ~a~%" );
DEFSTATICTSCP( c13832 );
DEFCSTRING( t16100, "proposals-on-the-fly?:          ~a~%" );
DEFSTATICTSCP( c13831 );
DEFCSTRING( t16101, "track-constraint?:              ~a~%" );
DEFSTATICTSCP( c13830 );
DEFCSTRING( t16102, "with-sentence" );
DEFSTATICTSCP( c13829 );
DEFCSTRING( t16103, "with-movement" );
DEFSTATICTSCP( c13828 );
DEFCSTRING( t16104, "without-sentence" );
DEFSTATICTSCP( c13827 );
DEFCSTRING( t16105, "sentence-directed?:             ~a~%" );
DEFSTATICTSCP( c13826 );
DEFCSTRING( t16106, "gamma (similarity):             ~a~%" );
DEFSTATICTSCP( c13825 );
DEFCSTRING( t16107, "alpha (temporal coherence):     ~a~%" );
DEFSTATICTSCP( c13824 );
DEFCSTRING( t16108, "theta (f score):                ~a~%" );
DEFSTATICTSCP( c13823 );
DEFCSTRING( t16109, "top-k:                          ~a~%" );
DEFSTATICTSCP( c13822 );
DEFCSTRING( t16110, "pool-size:                      ~a~%" );
DEFSTATICTSCP( c13821 );
DEFCSTRING( t16111, "only-proposals?                 ~a~%" );
DEFSTATICTSCP( c13820 );
DEFCSTRING( t16112, "-usage" );
DEFSTATICTSCP( c13671 );
DEFCSTRING( t16113, "-output-tracks-dir" );
DEFSTATICTSCP( c13670 );
DEFCSTRING( t16114, "-without-sentence" );
DEFSTATICTSCP( c13669 );
DEFCSTRING( t16115, "-with-movement" );
DEFSTATICTSCP( c13668 );
DEFCSTRING( t16116, "-with-sentence" );
DEFSTATICTSCP( c13667 );
DEFCSTRING( t16117, "-only-proposals" );
DEFSTATICTSCP( c13666 );
DEFCSTRING( t16118, "-try-hard" );
DEFSTATICTSCP( c13665 );
DEFCSTRING( t16119, "-write" );
DEFSTATICTSCP( c13664 );
DEFCSTRING( t16120, "-up-right" );
DEFSTATICTSCP( c13663 );
DEFCSTRING( t16121, "-tracks-on-the-fly" );
DEFSTATICTSCP( c13662 );
DEFCSTRING( t16122, "-on-the-fly" );
DEFSTATICTSCP( c13661 );
DEFCSTRING( t16123, "-no-track-constraint" );
DEFSTATICTSCP( c13660 );
DEFCSTRING( t16124, "-gamma" );
DEFSTATICTSCP( c13659 );
DEFCSTRING( t16125, "-theta" );
DEFSTATICTSCP( c13658 );
DEFCSTRING( t16126, "-alpha" );
DEFSTATICTSCP( c13657 );
DEFCSTRING( t16127, "-pool-size" );
DEFSTATICTSCP( c13656 );
DEFCSTRING( t16128, "-top-k" );
DEFSTATICTSCP( c13655 );
DEFCSTRING( t16129, "-videos" );
DEFSTATICTSCP( c13654 );
DEFCSTRING( t16130, "-video2" );
DEFSTATICTSCP( c13653 );
DEFCSTRING( t16131, "-video" );
DEFSTATICTSCP( c13652 );
DEFCSTRING( t16132, 
            "usage: ~a [-video video-path|-video2 video-path1 video-path2|-v\
ideos file mode] [-top-k top-k] [-pool-size pool-size] [-alpha weightalpha] \
[-theta weighttheta] [-gamma weightgamma] [-no-track-constraint] [-on-the-fl\
y] [-tracks-on-the-fly] [-up-right] [-write] [-try-hard] [-only-proposals] [\
-with-sentence|-with-movement|-without-sentence] [-output-tracks-dir directo\
ry]~%" );
DEFSTATICTSCP( c13609 );
DEFCSTRING( t16133, "fuck up" );
DEFSTATICTSCP( c13258 );
DEFSTATICTSCP( c12999 );
DEFCSTRING( t16134, "~a~%" );
DEFSTATICTSCP( c12774 );
DEFCSTRING( t16135, "mm = ~a~%" );
DEFSTATICTSCP( c12773 );
DEFSTATICTSCP( c12635 );
DEFSTATICTSCP( t16136 );
DEFCSTRING( t16137, 
            "computing c similarity on the fly between ~a and ~a...~%" );
DEFSTATICTSCP( c12601 );
DEFCSTRING( t16138, "tmp=simi(:,:,~a,~a);" );
DEFSTATICTSCP( c12562 );
DEFCSTRING( t16139, 
            "simi=similarity_between_videos(frames1,frames2,boxes1,boxes2,'~\
a','~a',~a,~a,~a);" );
DEFSTATICTSCP( c12557 );
DEFCSTRING( t16140, "boxes2" );
DEFSTATICTSCP( c12556 );
DEFCSTRING( t16141, "boxes1" );
DEFSTATICTSCP( c12555 );
DEFCSTRING( t16142, "frames2" );
DEFSTATICTSCP( c12554 );
DEFCSTRING( t16143, "frames1" );
DEFSTATICTSCP( c12553 );
DEFCSTRING( t16144, 
            "computing matlab similarity on the fly between ~a and ~a...~%" );
DEFSTATICTSCP( c12552 );
DEFCSTRING( t16145, 
            "[computed,simi] = check_similarity_between_videos('~a','~a',~a,\
~a,~a);" );
DEFSTATICTSCP( c12541 );
DEFCSTRING( t16146, "/codetection-data/tracks.sc" );
DEFSTATICTSCP( c12498 );
DEFSTATICTSCP( c12477 );
DEFCSTRING( t16147, "reselecting boxes for ~a...~%" );
DEFSTATICTSCP( c12460 );
DEFCSTRING( t16148, "reading precomputed tracks for ~a...~%" );
DEFSTATICTSCP( c12414 );
DEFCSTRING( t16149, "/tmp/buffer/boxes" );
DEFSTATICTSCP( c12394 );
DEFSTATICTSCP( c12369 );
DEFCSTRING( t16150, "Argument not a PAIR: ~s" );
DEFSTATICTSCP( c12317 );
DEFSTATICTSCP( c12316 );
DEFCSTRING( t16151, "rendering boxes video...~%" );
DEFSTATICTSCP( c12274 );
DEFCSTRING( t16152, "bboxes_t" );
DEFSTATICTSCP( c12256 );
DEFCSTRING( t16153, "tmp" );
DEFSTATICTSCP( c12255 );
DEFCSTRING( t16154, "tmp=bboxes(:,:,~a);tmp(:,1:4)=tmp(:,1:4)-1;" );
DEFSTATICTSCP( c12248 );
DEFCSTRING( t16155, "[bboxes_t,bboxes]=proposals(~a,frames,'~a',~a);" );
DEFSTATICTSCP( c12245 );
DEFCSTRING( t16156, 
            "computing proposals on the fly (matlab) for video ~a...~%" );
DEFSTATICTSCP( c12244 );
DEFCSTRING( t16157, "frames" );
DEFSTATICTSCP( c12243 );
DEFCSTRING( t16158, "computed" );
DEFSTATICTSCP( c12241 );
DEFCSTRING( t16159, 
            "[computed,bboxes_t,bboxes]=check_proposals(~a,'~a');" );
DEFSTATICTSCP( c12227 );
DEFCSTRING( t16160, "~a(:,:,:,~a)=uint8(frame);" );
DEFSTATICTSCP( c12213 );
DEFCSTRING( t16161, "frame=imread('~a');" );
DEFSTATICTSCP( c12212 );
DEFCSTRING( t16162, "/tmp/imlib-frame.ppm" );
DEFSTATICTSCP( c12209 );
DEFCSTRING( t16163, "~a=zeros(~a,~a,~a,~a,'uint8');" );
DEFSTATICTSCP( c12204 );
DEFCSTRING( t16164, "rm -f /tmp/buffer/frame-*.png" );
DEFSTATICTSCP( c12175 );
DEFCSTRING( t16165, 
            "ffmpeg -y -framerate 30 -i /tmp/buffer/frame-~a-%06d.png -r 30 \
-pix_fmt yuv420p ~a.mp4 > /dev/null 2>&1" );
DEFSTATICTSCP( c12174 );
DEFCSTRING( t16166, "/tmp/buffer/frame-~a-~a.png" );
DEFSTATICTSCP( c12159 );
DEFCSTRING( t16167, "mkdir -p /tmp/buffer" );
DEFSTATICTSCP( c12144 );
DEFCSTRING( t16168, "/tmp/buffer" );
DEFSTATICTSCP( c12143 );
DEFCSTRING( t16169, "codetection" );
DEFSTATICTSCP( c12043 );

static void  init_constants()
{
        c15865 = CSTRING_TSCP( t16073 );
        CONSTANTEXP( ADR( c15865 ) );
        c15864 = CSTRING_TSCP( t16074 );
        CONSTANTEXP( ADR( c15864 ) );
        c15863 = CSTRING_TSCP( t16075 );
        CONSTANTEXP( ADR( c15863 ) );
        c15862 = CSTRING_TSCP( t16076 );
        CONSTANTEXP( ADR( c15862 ) );
        c15861 = CSTRING_TSCP( t16077 );
        CONSTANTEXP( ADR( c15861 ) );
        c15860 = CSTRING_TSCP( t16078 );
        CONSTANTEXP( ADR( c15860 ) );
        c15815 = CSTRING_TSCP( t16079 );
        CONSTANTEXP( ADR( c15815 ) );
        c15802 = CSTRING_TSCP( t16080 );
        CONSTANTEXP( ADR( c15802 ) );
        c15539 = CSTRING_TSCP( t16081 );
        CONSTANTEXP( ADR( c15539 ) );
        c15537 = CSTRING_TSCP( t16082 );
        CONSTANTEXP( ADR( c15537 ) );
        c14977 = CSTRING_TSCP( t16083 );
        CONSTANTEXP( ADR( c14977 ) );
        c14392 = CSTRING_TSCP( t16084 );
        CONSTANTEXP( ADR( c14392 ) );
        c14217 = EMPTYLIST;
        t16085 = STRINGTOSYMBOL( CSTRING_TSCP( "LIST" ) );
        c14217 = CONS( t16085, c14217 );
        CONSTANTEXP( ADR( c14217 ) );
        c14193 = CSTRING_TSCP( t16086 );
        CONSTANTEXP( ADR( c14193 ) );
        c14192 = CSTRING_TSCP( t16087 );
        CONSTANTEXP( ADR( c14192 ) );
        c14102 = CSTRING_TSCP( t16088 );
        CONSTANTEXP( ADR( c14102 ) );
        c14101 = CSTRING_TSCP( t16089 );
        CONSTANTEXP( ADR( c14101 ) );
        c14100 = CSTRING_TSCP( t16090 );
        CONSTANTEXP( ADR( c14100 ) );
        c14099 = CSTRING_TSCP( t16091 );
        CONSTANTEXP( ADR( c14099 ) );
        c13854 = CSTRING_TSCP( t16092 );
        CONSTANTEXP( ADR( c13854 ) );
        c13853 = CSTRING_TSCP( t16093 );
        CONSTANTEXP( ADR( c13853 ) );
        c13852 = CSTRING_TSCP( t16094 );
        CONSTANTEXP( ADR( c13852 ) );
        c13836 = CSTRING_TSCP( t16095 );
        CONSTANTEXP( ADR( c13836 ) );
        c13835 = CSTRING_TSCP( t16096 );
        CONSTANTEXP( ADR( c13835 ) );
        c13834 = CSTRING_TSCP( t16097 );
        CONSTANTEXP( ADR( c13834 ) );
        c13833 = CSTRING_TSCP( t16098 );
        CONSTANTEXP( ADR( c13833 ) );
        c13832 = CSTRING_TSCP( t16099 );
        CONSTANTEXP( ADR( c13832 ) );
        c13831 = CSTRING_TSCP( t16100 );
        CONSTANTEXP( ADR( c13831 ) );
        c13830 = CSTRING_TSCP( t16101 );
        CONSTANTEXP( ADR( c13830 ) );
        c13829 = CSTRING_TSCP( t16102 );
        CONSTANTEXP( ADR( c13829 ) );
        c13828 = CSTRING_TSCP( t16103 );
        CONSTANTEXP( ADR( c13828 ) );
        c13827 = CSTRING_TSCP( t16104 );
        CONSTANTEXP( ADR( c13827 ) );
        c13826 = CSTRING_TSCP( t16105 );
        CONSTANTEXP( ADR( c13826 ) );
        c13825 = CSTRING_TSCP( t16106 );
        CONSTANTEXP( ADR( c13825 ) );
        c13824 = CSTRING_TSCP( t16107 );
        CONSTANTEXP( ADR( c13824 ) );
        c13823 = CSTRING_TSCP( t16108 );
        CONSTANTEXP( ADR( c13823 ) );
        c13822 = CSTRING_TSCP( t16109 );
        CONSTANTEXP( ADR( c13822 ) );
        c13821 = CSTRING_TSCP( t16110 );
        CONSTANTEXP( ADR( c13821 ) );
        c13820 = CSTRING_TSCP( t16111 );
        CONSTANTEXP( ADR( c13820 ) );
        c13671 = CSTRING_TSCP( t16112 );
        CONSTANTEXP( ADR( c13671 ) );
        c13670 = CSTRING_TSCP( t16113 );
        CONSTANTEXP( ADR( c13670 ) );
        c13669 = CSTRING_TSCP( t16114 );
        CONSTANTEXP( ADR( c13669 ) );
        c13668 = CSTRING_TSCP( t16115 );
        CONSTANTEXP( ADR( c13668 ) );
        c13667 = CSTRING_TSCP( t16116 );
        CONSTANTEXP( ADR( c13667 ) );
        c13666 = CSTRING_TSCP( t16117 );
        CONSTANTEXP( ADR( c13666 ) );
        c13665 = CSTRING_TSCP( t16118 );
        CONSTANTEXP( ADR( c13665 ) );
        c13664 = CSTRING_TSCP( t16119 );
        CONSTANTEXP( ADR( c13664 ) );
        c13663 = CSTRING_TSCP( t16120 );
        CONSTANTEXP( ADR( c13663 ) );
        c13662 = CSTRING_TSCP( t16121 );
        CONSTANTEXP( ADR( c13662 ) );
        c13661 = CSTRING_TSCP( t16122 );
        CONSTANTEXP( ADR( c13661 ) );
        c13660 = CSTRING_TSCP( t16123 );
        CONSTANTEXP( ADR( c13660 ) );
        c13659 = CSTRING_TSCP( t16124 );
        CONSTANTEXP( ADR( c13659 ) );
        c13658 = CSTRING_TSCP( t16125 );
        CONSTANTEXP( ADR( c13658 ) );
        c13657 = CSTRING_TSCP( t16126 );
        CONSTANTEXP( ADR( c13657 ) );
        c13656 = CSTRING_TSCP( t16127 );
        CONSTANTEXP( ADR( c13656 ) );
        c13655 = CSTRING_TSCP( t16128 );
        CONSTANTEXP( ADR( c13655 ) );
        c13654 = CSTRING_TSCP( t16129 );
        CONSTANTEXP( ADR( c13654 ) );
        c13653 = CSTRING_TSCP( t16130 );
        CONSTANTEXP( ADR( c13653 ) );
        c13652 = CSTRING_TSCP( t16131 );
        CONSTANTEXP( ADR( c13652 ) );
        c13609 = CSTRING_TSCP( t16132 );
        CONSTANTEXP( ADR( c13609 ) );
        c13258 = CSTRING_TSCP( t16133 );
        CONSTANTEXP( ADR( c13258 ) );
        c12999 = DOUBLE_TSCP( 0.5 );
        CONSTANTEXP( ADR( c12999 ) );
        c12774 = CSTRING_TSCP( t16134 );
        CONSTANTEXP( ADR( c12774 ) );
        c12773 = CSTRING_TSCP( t16135 );
        CONSTANTEXP( ADR( c12773 ) );
        c12635 = EMPTYLIST;
        t16136 = STRINGTOSYMBOL( CSTRING_TSCP( "VECTOR" ) );
        c12635 = CONS( t16136, c12635 );
        c12635 = CONS( t16136, c12635 );
        c12635 = CONS( t16085, c12635 );
        c12635 = CONS( t16085, c12635 );
        CONSTANTEXP( ADR( c12635 ) );
        c12601 = CSTRING_TSCP( t16137 );
        CONSTANTEXP( ADR( c12601 ) );
        c12562 = CSTRING_TSCP( t16138 );
        CONSTANTEXP( ADR( c12562 ) );
        c12557 = CSTRING_TSCP( t16139 );
        CONSTANTEXP( ADR( c12557 ) );
        c12556 = CSTRING_TSCP( t16140 );
        CONSTANTEXP( ADR( c12556 ) );
        c12555 = CSTRING_TSCP( t16141 );
        CONSTANTEXP( ADR( c12555 ) );
        c12554 = CSTRING_TSCP( t16142 );
        CONSTANTEXP( ADR( c12554 ) );
        c12553 = CSTRING_TSCP( t16143 );
        CONSTANTEXP( ADR( c12553 ) );
        c12552 = CSTRING_TSCP( t16144 );
        CONSTANTEXP( ADR( c12552 ) );
        c12541 = CSTRING_TSCP( t16145 );
        CONSTANTEXP( ADR( c12541 ) );
        c12498 = CSTRING_TSCP( t16146 );
        CONSTANTEXP( ADR( c12498 ) );
        c12477 = EMPTYLIST;
        c12477 = CONS( t16085, c12477 );
        c12477 = CONS( t16085, c12477 );
        c12477 = CONS( t16085, c12477 );
        CONSTANTEXP( ADR( c12477 ) );
        c12460 = CSTRING_TSCP( t16147 );
        CONSTANTEXP( ADR( c12460 ) );
        c12414 = CSTRING_TSCP( t16148 );
        CONSTANTEXP( ADR( c12414 ) );
        c12394 = CSTRING_TSCP( t16149 );
        CONSTANTEXP( ADR( c12394 ) );
        c12369 = EMPTYLIST;
        c12369 = CONS( _TSCP( 0 ), c12369 );
        c12369 = CONS( _TSCP( 0 ), c12369 );
        c12369 = CONS( _TSCP( 0 ), c12369 );
        c12369 = LISTTOVECTOR( c12369 );
        CONSTANTEXP( ADR( c12369 ) );
        c12317 = CSTRING_TSCP( t16150 );
        CONSTANTEXP( ADR( c12317 ) );
        c12316 = STRINGTOSYMBOL( CSTRING_TSCP( "SET-CDR!" ) );
        CONSTANTEXP( ADR( c12316 ) );
        c12274 = CSTRING_TSCP( t16151 );
        CONSTANTEXP( ADR( c12274 ) );
        c12256 = CSTRING_TSCP( t16152 );
        CONSTANTEXP( ADR( c12256 ) );
        c12255 = CSTRING_TSCP( t16153 );
        CONSTANTEXP( ADR( c12255 ) );
        c12248 = CSTRING_TSCP( t16154 );
        CONSTANTEXP( ADR( c12248 ) );
        c12245 = CSTRING_TSCP( t16155 );
        CONSTANTEXP( ADR( c12245 ) );
        c12244 = CSTRING_TSCP( t16156 );
        CONSTANTEXP( ADR( c12244 ) );
        c12243 = CSTRING_TSCP( t16157 );
        CONSTANTEXP( ADR( c12243 ) );
        c12241 = CSTRING_TSCP( t16158 );
        CONSTANTEXP( ADR( c12241 ) );
        c12227 = CSTRING_TSCP( t16159 );
        CONSTANTEXP( ADR( c12227 ) );
        c12213 = CSTRING_TSCP( t16160 );
        CONSTANTEXP( ADR( c12213 ) );
        c12212 = CSTRING_TSCP( t16161 );
        CONSTANTEXP( ADR( c12212 ) );
        c12209 = CSTRING_TSCP( t16162 );
        CONSTANTEXP( ADR( c12209 ) );
        c12204 = CSTRING_TSCP( t16163 );
        CONSTANTEXP( ADR( c12204 ) );
        c12175 = CSTRING_TSCP( t16164 );
        CONSTANTEXP( ADR( c12175 ) );
        c12174 = CSTRING_TSCP( t16165 );
        CONSTANTEXP( ADR( c12174 ) );
        c12159 = CSTRING_TSCP( t16166 );
        CONSTANTEXP( ADR( c12159 ) );
        c12144 = CSTRING_TSCP( t16167 );
        CONSTANTEXP( ADR( c12144 ) );
        c12143 = CSTRING_TSCP( t16168 );
        CONSTANTEXP( ADR( c12143 ) );
        c12043 = CSTRING_TSCP( t16169 );
        CONSTANTEXP( ADR( c12043 ) );
}

DEFTSCP( detection_on_2d1_2d0_9fcc6ee3_v );
DEFCSTRING( t16170, "gensym-codetection-1-0" );

TSCP  detection_on_2d1_2d0_9fcc6ee3(  )
{
        PUSHSTACKTRACE( t16170 );
        POPSTACKTRACE( 0 );}
  #include<stddef.h>
int gensym_codetection_2_0(){ return 1;gensym_codetection_2_0( );
}

DEFTSCP( detection_on_2d3_2d0_e50c3d83_v );
DEFCSTRING( t16172, "gensym-codetection-3-0" );

TSCP  detection_on_2d3_2d0_e50c3d83(  )
{
        PUSHSTACKTRACE( t16172 );
        POPSTACKTRACE( 0 );}
  #include<stdlib.h>
int gensym_codetection_4_0(){ return 1;gensym_codetection_4_0( );
}

DEFTSCP( detection_on_2d5_2d0_6a4cc823_v );
DEFCSTRING( t16174, "gensym-codetection-5-0" );

TSCP  detection_on_2d5_2d0_6a4cc823(  )
{
        PUSHSTACKTRACE( t16174 );
        POPSTACKTRACE( 0 );}
  #include<string.h>
int gensym_codetection_6_0(){ return 1;gensym_codetection_6_0( );
}

DEFTSCP( detection_on_2d7_2d0_108c9b43_v );
DEFCSTRING( t16176, "gensym-codetection-7-0" );

TSCP  detection_on_2d7_2d0_108c9b43(  )
{
        PUSHSTACKTRACE( t16176 );
        POPSTACKTRACE( 0 );}
  #include<codetectionlib-c.h>
int gensym_codetection_8_0(){ return 1;gensym_codetection_8_0( );
}

DEFTSCP( detection_on_2d9_2d0_afbc2522_v );
DEFCSTRING( t16178, "gensym-codetection-9-0" );

TSCP  detection_on_2d9_2d0_afbc2522(  )
{
        PUSHSTACKTRACE( t16178 );
        POPSTACKTRACE( 0 );}
  #include<inference.h>
int gensym_codetection_10_0(){ return 1;gensym_codetection_10_0( );
}

EXTERNTSCP( qobischeme__2aprogram_2a_v );
EXTERNTSCP( qobischeme__2apanic_3f_2a_v );
DEFTSCP( detection_hard_3f_2a_5334b1c_v );
DEFCSTRING( t16180, "*TRY-HARD?*" );
DEFTSCP( detection_ideo_3f_2a_99b8f220_v );
DEFCSTRING( t16181, "*SINGLE-VIDEO?*" );
DEFTSCP( detection_tations_2a_bae473a_v );
DEFCSTRING( t16182, "*N-ORIENTATIONS*" );
DEFTSCP( detection_mes_2dn_2a_f0f9bc16_v );
DEFCSTRING( t16183, "*SAMPLE-FRAMES-N*" );
DEFTSCP( codetection__2aobjects_2a_v );
DEFCSTRING( t16184, "*OBJECTS*" );
DEFTSCP( codetection_time_2dthunk_v );
DEFCSTRING( t16185, "TIME-THUNK" );
EXTERNTSCPP( nlib_2dsc_ent_2dtime_b0674773, XAL0(  ) );
EXTERNTSCP( nlib_2dsc_ent_2dtime_b0674773_v );
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

TSCP  codetection_time_2dthunk( f12053, t12054 )
        TSCP  f12053, t12054;
{
        TSCP  X14, 
              X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t16185 );
        X1 = nlib_2dsc_ent_2dtime_b0674773(  );
        X3 = t12054;
        X3 = UNKNOWNCALL( X3, 0 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( PROCEDURE_CLOSURE( X3 ) );
        X3 = nlib_2dsc_ent_2dtime_b0674773(  );
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L16190;
        X5 = _TSCP( IDIFFERENCE( _S2CINT( X3 ), 
                                 _S2CINT( X1 ) ) );
        goto L16191;
L16190:
        X5 = scrt2__2d_2dtwo( X3, X1 );
L16191:
        if  ( BITAND( BITOR( _S2CINT( X5 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16194;
        if  ( LT( _S2CINT( X5 ), _S2CINT( _TSCP( 4 ) ) ) )  goto L16198;
        goto L16199;
L16194:
        if  ( TRUE( scrt2__3c_2dtwo( X5, _TSCP( 4 ) ) ) )  goto L16198;
L16199:
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 4 ) ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L16203;
        X8 = _TSCP( IPLUS( _S2CINT( _TSCP( 4 ) ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L16204;
L16203:
        X8 = scrt2__2b_2dtwo( _TSCP( 4 ), _TSCP( 8 ) );
L16204:
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L16205;
        X12 = _TSCP( IDIFFERENCE( _S2CINT( X3 ), 
                                  _S2CINT( X1 ) ) );
        goto L16206;
L16205:
        X12 = scrt2__2d_2dtwo( X3, X1 );
L16206:
        X11 = scrt2_log( X12 );
        X12 = scrt2_log( _TSCP( 40 ) );
        X13 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( X11 ), 
                                           _S2CINT( X12 ) ), 
                                    3 ) ) );
        if  ( FALSE( X13 ) )  goto L16218;
        if  ( EQ( _S2CUINT( X12 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L16218;
        X14 = _TSCP( REMAINDER( _S2CINT( X11 ), 
                                _S2CINT( X12 ) ) );
        if  ( NEQ( _S2CUINT( X14 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L16218;
        X10 = C_FIXED( QUOTIENT( _S2CINT( X11 ), 
                                 _S2CINT( X12 ) ) );
        goto L16219;
L16218:
        X10 = scrt2__2f_2dtwo( X11, X12 );
L16219:
        if  ( BITAND( BITOR( _S2CINT( X10 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16221;
        X9 = _TSCP( IPLUS( _S2CINT( X10 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L16222;
L16221:
        X9 = scrt2__2b_2dtwo( X10, _TSCP( 4 ) );
L16222:
        if  ( BITAND( BITOR( _S2CINT( X9 ), _S2CINT( X8 ) ), 
                      3 ) )  goto L16224;
        X7 = _TSCP( IPLUS( _S2CINT( X9 ), _S2CINT( X8 ) ) );
        goto L16225;
L16224:
        X7 = scrt2__2b_2dtwo( X9, X8 );
L16225:
        X6 = scrt2_floor( X7 );
        X4 = scrt2_inexact_2d_3eexact( X6 );
        goto L16227;
L16198:
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 8 ) ), 
                             _S2CINT( _TSCP( 8 ) ) ), 
                      3 ) )  goto L16226;
        X4 = _TSCP( IPLUS( _S2CINT( _TSCP( 8 ) ), 
                           _S2CINT( _TSCP( 8 ) ) ) );
        goto L16227;
L16226:
        X4 = scrt2__2b_2dtwo( _TSCP( 8 ), _TSCP( 8 ) );
L16227:
        if  ( BITAND( BITOR( _S2CINT( X3 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L16229;
        X6 = _TSCP( IDIFFERENCE( _S2CINT( X3 ), 
                                 _S2CINT( X1 ) ) );
        goto L16230;
L16229:
        X6 = scrt2__2d_2dtwo( X3, X1 );
L16230:
        X5 = CONS( obischeme_dprecision_2841f1d3( X6, 
                                                  X4, _TSCP( 8 ) ), 
                   EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( f12053, X5 ) );
        POPSTACKTRACE( X2 );
}

DEFTSCP( detection_2ddepth_2a_8800758e_v );
DEFCSTRING( t16231, "*TIME-DEPTH*" );
DEFTSCP( codetection_frames_2d_3evideo_v );
DEFCSTRING( t16232, "FRAMES->VIDEO" );
EXTERNTSCPP( qobischeme_file_2dexists_3f, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_file_2dexists_3f_v );
EXTERNTSCPP( scrt4_system, XAL1( TSCP ) );
EXTERNTSCP( scrt4_system_v );
EXTERNTSCPP( obischeme__2dindexed_d1069d4, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( obischeme__2dindexed_d1069d4_v );
EXTERNTSCPP( scrt2_modulo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_modulo_v );
EXTERNTSCPP( scrt2_zero_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt2_zero_3f_v );
EXTERNTSCPP( nlib_2dsc_ve_2dimage_497f8fa, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( nlib_2dsc_ve_2dimage_497f8fa_v );
EXTERNTSCPP( obischeme_f_2dlength_385ce898, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( obischeme_f_2dlength_385ce898_v );
EXTERNTSCPP( scrt2_quotient, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_quotient_v );
EXTERNTSCPP( qobischeme_getpid, XAL0(  ) );
EXTERNTSCP( qobischeme_getpid_v );

TSCP  codetection_l12145( f12146, i12147, c16236 )
        TSCP  f12146, i12147, c16236;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "codetection_l12145 [inside FRAMES->VIDEO]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c16236, 0 );
        X3 = scrt2_modulo( i12147, DISPLAY( 0 ) );
        if  ( NEQ( TSCPTAG( X3 ), FIXNUMTAG ) )  goto L16240;
        if  ( EQ( _S2CUINT( X3 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L16244;
        X2 = FALSEVALUE;
        goto L16247;
L16240:
        if  ( TRUE( scrt2_zero_3f( X3 ) ) )  goto L16244;
        X2 = FALSEVALUE;
        goto L16247;
L16244:
        X6 = DISPLAY( 0 );
        X7 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( i12147 ), 
                                          _S2CINT( X6 ) ), 
                                   3 ) ) );
        if  ( FALSE( X7 ) )  goto L16255;
        if  ( EQ( _S2CUINT( X6 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L16255;
        X5 = C_FIXED( QUOTIENT( _S2CINT( i12147 ), 
                                _S2CINT( X6 ) ) );
        goto L16256;
L16255:
        X5 = scrt2_quotient( i12147, X6 );
L16256:
        X4 = CONS( obischeme_f_2dlength_385ce898( X5, _TSCP( 24 ) ), 
                   EMPTYLIST );
        X4 = CONS( qobischeme_getpid(  ), X4 );
        X3 = scrt6_format( FALSEVALUE, CONS( c12159, X4 ) );
        X2 = nlib_2dsc_ve_2dimage_497f8fa( f12146, X3 );
L16247:
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  codetection_frames_2d_3evideo( f12140, v12141, d12142 )
        TSCP  f12140, v12141, d12142;
{
        TSCP  X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t16232 );
        DISPLAY( 0 ) = d12142;
        if  ( TRUE( qobischeme_file_2dexists_3f( c12143 ) ) )  goto L16234;
        scrt4_system( c12144 );
L16234:
        X1 = MAKEPROCEDURE( 2, 
                            0, 
                            codetection_l12145, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        obischeme__2dindexed_d1069d4( X1, f12140 );
        X2 = CONS( v12141, EMPTYLIST );
        X2 = CONS( qobischeme_getpid(  ), X2 );
        X1 = scrt6_format( FALSEVALUE, CONS( c12174, X2 ) );
        scrt4_system( X1 );
        SDVAL = scrt4_system( c12175 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( codetection_video_2d_3eframes_v );
DEFCSTRING( t16257, "VIDEO->FRAMES" );
EXTERNTSCP( nlib_2dsc_en_2dvideo_9771a33c_v );
EXTERNTSCPP( nlib_2dsc_2dframe_21_c9b06fc, XAL1( TSCP ) );
EXTERNTSCP( nlib_2dsc_2dframe_21_c9b06fc_v );
EXTERNTSCP( nlib_2dsc_se_2dvideo_44bfe0bf_v );
EXTERNTSCPP( scrt1_reverse, XAL1( TSCP ) );
EXTERNTSCP( scrt1_reverse_v );
EXTERNTSCPP( sc_cons, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_cons_v );
EXTERNTSCP( nlib_2dsc_as_2dimlib_f25d19a4_v );

TSCP  codetection_video_2d_3eframes( v12178 )
        TSCP  v12178;
{
        TSCP  X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t16257 );
        X2 = nlib_2dsc_en_2dvideo_9771a33c_v;
        X2 = UNKNOWNCALL( X2, 1 );
        X1 = VIA( PROCEDURE_CODE( X2 ) )( v12178, 
                                          PROCEDURE_CLOSURE( X2 ) );
        X2 = EMPTYLIST;
        X3 = TRUEVALUE;
L16261:
        if  ( TRUE( X3 ) )  goto L16265;
        if  ( TRUE( nlib_2dsc_2dframe_21_c9b06fc( X1 ) ) )  goto L16265;
        X4 = nlib_2dsc_se_2dvideo_44bfe0bf_v;
        X4 = UNKNOWNCALL( X4, 1 );
        VIA( PROCEDURE_CODE( X4 ) )( X1, PROCEDURE_CLOSURE( X4 ) );
        POPSTACKTRACE( scrt1_reverse( X2 ) );
L16265:
        X6 = nlib_2dsc_as_2dimlib_f25d19a4_v;
        X6 = UNKNOWNCALL( X6, 1 );
        X5 = VIA( PROCEDURE_CODE( X6 ) )( X1, 
                                          PROCEDURE_CLOSURE( X6 ) );
        X4 = sc_cons( X5, X2 );
        X3 = FALSEVALUE;
        X2 = X4;
        GOBACK( L16261 );
}

DEFTSCP( detection_2dmatrices_c6981307_v );
DEFCSTRING( t16269, "IMLIB-FRAMES->MATLAB-MATRICES" );
EXTERNTSCPP( qobischeme_first, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_first_v );
EXTERNTSCPP( nlib_2dsc_b_3aheight_cb673bff, XAL1( TSCP ) );
EXTERNTSCP( nlib_2dsc_b_3aheight_cb673bff_v );
EXTERNTSCPP( nlib_2dsc_ib_3awidth_c7d91eee, XAL1( TSCP ) );
EXTERNTSCP( nlib_2dsc_ib_3awidth_c7d91eee_v );
EXTERNTSCPP( _2dmatlab_dmatlab_21_16b982d3, XAL0(  ) );
EXTERNTSCP( _2dmatlab_dmatlab_21_16b982d3_v );
EXTERNTSCPP( toollib_2dmatlab_matlab, XAL1( TSCP ) );
EXTERNTSCP( toollib_2dmatlab_matlab_v );
EXTERNTSCPP( scrt1_length, XAL1( TSCP ) );
EXTERNTSCP( scrt1_length_v );
EXTERNTSCPP( obischeme_ary_2dfile_15e4569d, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( obischeme_ary_2dfile_15e4569d_v );

TSCP  codetection_l12210( t12211, c16276 )
        TSCP  t12211, c16276;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "codetection_l12210 [inside IMLIB-FRAMES->MATLAB-MAT\
RICES]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c16276, 0 );
        X2 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c16276, 1 );
        X3 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c16276, 2 );
        nlib_2dsc_ve_2dimage_497f8fa( DISPLAY( 1 ), t12211 );
        X5 = CONS( t12211, EMPTYLIST );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12212, X5 ) ), 
                                       EMPTYLIST ) );
        X6 = DISPLAY( 2 );
        if  ( BITAND( BITOR( _S2CINT( X6 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16279;
        X7 = _TSCP( IPLUS( _S2CINT( X6 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L16280;
L16279:
        X7 = scrt2__2b_2dtwo( X6, _TSCP( 4 ) );
L16280:
        X5 = CONS( X7, EMPTYLIST );
        X5 = CONS( DISPLAY( 0 ), X5 );
        X4 = toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                          CONS( c12213, 
                                                                X5 ) ), 
                                            EMPTYLIST ) );
        DISPLAY( 1 ) = X1;
        DISPLAY( 2 ) = X2;
        DISPLAY( 0 ) = X3;
        POPSTACKTRACE( X4 );
}

TSCP  codetection_l12206( f12207, i12208, c16274 )
        TSCP  f12207, i12208, c16274;
{
        TSCP  X3, X2, X1;
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "codetection_l12206 [inside IMLIB-FRAMES->MATLAB-MAT\
RICES]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c16274, 0 );
        DISPLAY( 1 ) = f12207;
        DISPLAY( 2 ) = i12208;
        X3 = MAKEPROCEDURE( 1, 
                            0, 
                            codetection_l12210, 
                            MAKECLOSURE( EMPTYLIST, 
                                         3, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 2 ), 
                                         DISPLAY( 0 ) ) );
        X2 = obischeme_ary_2dfile_15e4569d( c12209, X3 );
        DISPLAY( 0 ) = X1;
        SDVAL = X2;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

TSCP  detection_2dmatrices_c6981307( f12196, m12197 )
        TSCP  f12196, m12197;
{
        TSCP  X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t16269 );
        DISPLAY( 0 ) = m12197;
        X1 = qobischeme_first( f12196 );
        X2 = nlib_2dsc_b_3aheight_cb673bff( X1 );
        X3 = nlib_2dsc_ib_3awidth_c7d91eee( X1 );
        _2dmatlab_dmatlab_21_16b982d3(  );
        X4 = CONS( scrt1_length( f12196 ), EMPTYLIST );
        X4 = CONS( _TSCP( 12 ), X4 );
        X4 = CONS( X3, X4 );
        X4 = CONS( X2, X4 );
        X4 = CONS( DISPLAY( 0 ), X4 );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12204, X4 ) ), 
                                       EMPTYLIST ) );
        X4 = MAKEPROCEDURE( 2, 
                            0, 
                            codetection_l12206, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        SDVAL = obischeme__2dindexed_d1069d4( X4, f12196 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( detection_h_2dframes_d6c0ddee_v );
DEFCSTRING( t16281, "PROPOSALS-WITH-FRAMES" );
EXTERNTSCPP( qobischeme_x, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_x_v );
EXTERNTSCPP( _2dmatlab_2dvariable_a304468f, XAL1( TSCP ) );
EXTERNTSCP( _2dmatlab_2dvariable_a304468f_v );
EXTERNTSCPP( qobischeme_strip_2ddirectory, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_strip_2ddirectory_v );
EXTERNTSCPP( qobischeme_map_2dn, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_map_2dn_v );

TSCP  codetection_l12246( t12247, c16302 )
        TSCP  t12247, c16302;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "codetection_l12246 [inside PROPOSALS-WITH-FRAMES]" );
        if  ( BITAND( BITOR( _S2CINT( t12247 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16304;
        X2 = _TSCP( IPLUS( _S2CINT( t12247 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L16305;
L16304:
        X2 = scrt2__2b_2dtwo( t12247, _TSCP( 4 ) );
L16305:
        X1 = CONS( X2, EMPTYLIST );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12248, X1 ) ), 
                                       EMPTYLIST ) );
        POPSTACKTRACE( _2dmatlab_2dvariable_a304468f( c12255 ) );
}

TSCP  detection_h_2dframes_d6c0ddee( t12222, 
                                     f12223, 
                                     v12224, o12225, w12226 )
        TSCP  t12222, f12223, v12224, o12225, w12226;
{
        TSCP  X4, X3, X2, X1;

        PUSHSTACKTRACE( t16281 );
        _2dmatlab_dmatlab_21_16b982d3(  );
        if  ( TRUE( o12225 ) )  goto L16283;
        X1 = CONS( v12224, EMPTYLIST );
        X1 = CONS( t12222, X1 );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12227, X1 ) ), 
                                       EMPTYLIST ) );
L16283:
        if  ( TRUE( o12225 ) )  goto L16288;
        X3 = _2dmatlab_2dvariable_a304468f( c12241 );
        X2 = qobischeme_x( X3 );
        X1 = qobischeme_x( X2 );
        if  ( NEQ( TSCPTAG( X1 ), FIXNUMTAG ) )  goto L16291;
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L16288;
        goto L16298;
L16291:
        if  ( FALSE( scrt2_zero_3f( X1 ) ) )  goto L16298;
L16288:
        detection_2dmatrices_c6981307( f12223, c12243 );
        X1 = CONS( qobischeme_strip_2ddirectory( v12224 ), 
                   EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c12244, X1 ) );
        if  ( FALSE( w12226 ) )  goto L16300;
        X2 = _TSCP( 4 );
        goto L16301;
L16300:
        X2 = _TSCP( 0 );
L16301:
        X1 = CONS( X2, EMPTYLIST );
        X1 = CONS( v12224, X1 );
        X1 = CONS( t12222, X1 );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12245, X1 ) ), 
                                       EMPTYLIST ) );
L16298:
        X1 = MAKEPROCEDURE( 1, 
                            0, codetection_l12246, EMPTYLIST );
        X4 = _2dmatlab_2dvariable_a304468f( c12256 );
        X3 = qobischeme_x( X4 );
        X2 = qobischeme_x( X3 );
        POPSTACKTRACE( qobischeme_map_2dn( X1, X2 ) );
}

DEFTSCP( detection_2dtracking_1add9051_v );
DEFCSTRING( t16306, "RESELECT-BOXES-AND-TRACKING" );
EXTERNTSCPP( qobischeme_strip_2dextension, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_strip_2dextension_v );
EXTERNTSCPP( scrt3_string_2dappend, XAL1( TSCP ) );
EXTERNTSCP( scrt3_string_2dappend_v );
EXTERNTSCPP( obischeme_rom_2dfile_92544bb1, XAL1( TSCP ) );
EXTERNTSCP( obischeme_rom_2dfile_92544bb1_v );
EXTERNTSCPP( scrt1_list_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt1_list_3f_v );
EXTERNTSCPP( codetectionlib_2dsc_take, XAL2( TSCP, TSCP ) );
EXTERNTSCP( codetectionlib_2dsc_take_v );
EXTERNTSCPP( scrt1__24__car_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__car_2derror_v );
EXTERNTSCPP( scdebug_error, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scdebug_error_v );
EXTERNTSCP( asy_2dffi_e_2dto_2dc_6e7b37fb_v );
EXTERNTSCPP( qobischeme_make_2dmatrix, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_make_2dmatrix_v );

TSCP  codetection_l12495( __12496, c16359 )
        TSCP  __12496, c16359;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "codetection_l12495 [inside RESELECT-BOXES-AND-TRACK\
ING]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c16359, 0 );
        X2 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c16359, 1 );
        X3 = qobischeme_make_2dmatrix( DISPLAY( 0 ), 
                                       DISPLAY( 1 ), 
                                       CONS( _TSCP( 0 ), EMPTYLIST ) );
        DISPLAY( 1 ) = X1;
        DISPLAY( 0 ) = X2;
        POPSTACKTRACE( X3 );
}

EXTERNTSCP( asy_2dffi_d_2dto_2dc_5b40207f_v );
EXTERNTSCP( asy_2dffi_2dfrom_2dc_5625c28b_v );
EXTERNTSCPP( easy_2dffi_easy_2dffi_3afree, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( easy_2dffi_easy_2dffi_3afree_v );
EXTERNTSCPP( obischeme_dto_2dfile_ae5c74d4, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( obischeme_dto_2dfile_ae5c74d4_v );
EXTERNTSCPP( qobischeme_second, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_second_v );
EXTERNTSCPP( qobischeme_third, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_third_v );
EXTERNTSCPP( nlib_2dsc_drectangle_8a5856a3, 
             XAL7( TSCP, 
                   TSCP, TSCP, TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( nlib_2dsc_drectangle_8a5856a3_v );
EXTERNTSCPP( qobischeme_fourth, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_fourth_v );
EXTERNTSCP( screp_exit_v );

TSCP  detection_2dtracking_1add9051( b12259, 
                                     f12260, 
                                     p12261, 
                                     t12262, v12263, t12264 )
        TSCP  b12259, 
              f12260, p12261, t12262, v12263, t12264;
{
        TSCP  X21, 
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
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t16306 );
        DISPLAY( 0 ) = t12262;
        X1 = qobischeme_strip_2dextension( v12263 );
        X3 = CONS( c12498, EMPTYLIST );
        X2 = scrt3_string_2dappend( CONS( X1, X3 ) );
        if  ( FALSE( qobischeme_file_2dexists_3f( X2 ) ) )  goto L16310;
        X3 = obischeme_rom_2dfile_92544bb1( X2 );
        goto L16311;
L16310:
        X3 = FALSEVALUE;
L16311:
        if  ( TRUE( t12264 ) )  goto L16316;
        if  ( FALSE( X3 ) )  goto L16317;
        X6 = FALSEVALUE;
        goto L16318;
L16317:
        X6 = TRUEVALUE;
L16318:
        if  ( FALSE( X6 ) )  goto L16320;
        X5 = X6;
        goto L16323;
L16320:
        if  ( FALSE( scrt1_list_3f( X3 ) ) )  goto L16322;
        X5 = FALSEVALUE;
        goto L16323;
L16322:
        X5 = TRUEVALUE;
L16323:
        if  ( TRUE( X5 ) )  goto L16316;
        X7 = qobischeme_first( X3 );
        X6 = scrt1_length( X7 );
        X7 = DISPLAY( 0 );
        if  ( BITAND( BITOR( _S2CINT( X6 ), _S2CINT( X7 ) ), 
                      3 ) )  goto L16331;
        if  ( LT( _S2CINT( X6 ), _S2CINT( X7 ) ) )  goto L16316;
        goto L16336;
L16331:
        if  ( TRUE( scrt2__3c_2dtwo( X6, X7 ) ) )  goto L16316;
L16336:
        X5 = CONS( v12263, EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c12414, X5 ) );
        X5 = X3;
        X6 = EMPTYLIST;
        X7 = EMPTYLIST;
L16342:
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L16343;
        X4 = X6;
        goto L16339;
L16343:
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L16346;
        scrt1__24__car_2derror( X5 );
L16346:
        X10 = PAIR_CAR( X5 );
        X9 = codetectionlib_2dsc_take( DISPLAY( 0 ), X10 );
        X8 = sc_cons( X9, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X6 ), _S2CUINT( EMPTYLIST ) ) )  goto L16349;
        X9 = PAIR_CDR( X5 );
        X7 = X8;
        X6 = X8;
        X5 = X9;
        GOBACK( L16342 );
L16349:
        X9 = PAIR_CDR( X5 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L16354;
        scdebug_error( c12316, 
                       c12317, CONS( X7, EMPTYLIST ) );
L16354:
        X7 = SETGEN( PAIR_CDR( X7 ), X8 );
        X5 = X9;
        GOBACK( L16342 );
L16316:
        X5 = CONS( v12263, EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c12460, X5 ) );
        X6 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X6 = UNKNOWNCALL( X6, 2 );
        X5 = VIA( PROCEDURE_CODE( X6 ) )( _TSCP( 12 ), 
                                          b12259, 
                                          PROCEDURE_CLOSURE( X6 ) );
        DISPLAY( 1 ) = _TSCP( 28 );
        X7 = MAKEPROCEDURE( 0, 
                            1, 
                            codetection_l12495, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 1 ), 
                                         DISPLAY( 0 ) ) );
        X8 = scrt1_length( b12259 );
        X6 = qobischeme_map_2dn( X7, X8 );
        X8 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X8 = UNKNOWNCALL( X8, 2 );
        X7 = VIA( PROCEDURE_CODE( X8 ) )( _TSCP( 12 ), 
                                          X6, 
                                          PROCEDURE_CLOSURE( X8 ) );
        X9 = asy_2dffi_d_2dto_2dc_5b40207f_v;
        X9 = UNKNOWNCALL( X9, 2 );
        X8 = VIA( PROCEDURE_CODE( X9 ) )( _TSCP( 4 ), 
                                          f12260, 
                                          PROCEDURE_CLOSURE( X9 ) );
        X10 = scrt1_length( b12259 );
        X11 = DISPLAY( 0 );
        X12 = DISPLAY( 1 );
        reselect_proposals( TSCP_POINTER( X5 ), 
                            TSCP_POINTER( X8 ), 
                            sc_tscp_int( X10 ), 
                            sc_tscp_int( p12261 ), 
                            sc_tscp_int( X11 ), 
                            sc_tscp_int( X12 ), 
                            TSCP_POINTER( X7 ) );
        X9 = FALSEVALUE;
        X14 = scrt1_length( b12259 );
        X16 = sc_cons( DISPLAY( 1 ), EMPTYLIST );
        X15 = sc_cons( DISPLAY( 0 ), X16 );
        X13 = sc_cons( X14, X15 );
        X12 = X13;
        X11 = asy_2dffi_2dfrom_2dc_5625c28b_v;
        X11 = UNKNOWNCALL( X11, 3 );
        X10 = VIA( PROCEDURE_CODE( X11 ) )( X12, 
                                            c12477, 
                                            X7, 
                                            PROCEDURE_CLOSURE( X11 ) );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 12 ), b12259, X5 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 12 ), X10, X7 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 4 ), f12260, X8 );
        obischeme_dto_2dfile_ae5c74d4( X10, X2 );
        X4 = X10;
L16339:
        if  ( FALSE( detection_ideo_3f_2a_99b8f220_v ) )  goto L16370;
        scrt6_format( TRUEVALUE, CONS( c12274, EMPTYLIST ) );
        X6 = X4;
        X7 = f12260;
        X8 = EMPTYLIST;
        X9 = EMPTYLIST;
L16374:
        if  ( NEQ( _S2CUINT( X6 ), _S2CUINT( EMPTYLIST ) ) )  goto L16375;
        X5 = X8;
        goto L16412;
L16375:
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L16378;
        scrt1__24__car_2derror( X6 );
L16378:
        X12 = PAIR_CAR( X6 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L16381;
        scrt1__24__car_2derror( X7 );
L16381:
        X13 = PAIR_CAR( X7 );
        X14 = X12;
L16386:
        if  ( EQ( _S2CUINT( X14 ), _S2CUINT( EMPTYLIST ) ) )  goto L16387;
        if  ( EQ( TSCPTAG( X14 ), PAIRTAG ) )  goto L16391;
        scrt1__24__car_2derror( X14 );
L16391:
        X15 = PAIR_CAR( X14 );
        X16 = qobischeme_first( X15 );
        X17 = qobischeme_second( X15 );
        X20 = qobischeme_third( X15 );
        if  ( BITAND( BITOR( _S2CINT( X20 ), 
                             _S2CINT( X16 ) ), 
                      3 ) )  goto L16397;
        X19 = _TSCP( IDIFFERENCE( _S2CINT( X20 ), 
                                  _S2CINT( X16 ) ) );
        goto L16398;
L16397:
        X19 = scrt2__2d_2dtwo( X20, X16 );
L16398:
        if  ( BITAND( BITOR( _S2CINT( X19 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16400;
        X18 = _TSCP( IPLUS( _S2CINT( X19 ), 
                            _S2CINT( _TSCP( 4 ) ) ) );
        goto L16401;
L16400:
        X18 = scrt2__2b_2dtwo( X19, _TSCP( 4 ) );
L16401:
        X21 = qobischeme_fourth( X15 );
        if  ( BITAND( BITOR( _S2CINT( X21 ), 
                             _S2CINT( X17 ) ), 
                      3 ) )  goto L16404;
        X20 = _TSCP( IDIFFERENCE( _S2CINT( X21 ), 
                                  _S2CINT( X17 ) ) );
        goto L16405;
L16404:
        X20 = scrt2__2d_2dtwo( X21, X17 );
L16405:
        if  ( BITAND( BITOR( _S2CINT( X20 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16407;
        X19 = _TSCP( IPLUS( _S2CINT( X20 ), 
                            _S2CINT( _TSCP( 4 ) ) ) );
        goto L16408;
L16407:
        X19 = scrt2__2b_2dtwo( X20, _TSCP( 4 ) );
L16408:
        nlib_2dsc_drectangle_8a5856a3( X13, 
                                       X16, 
                                       X17, 
                                       X18, 
                                       X19, c12369, _TSCP( 12 ) );
        X14 = PAIR_CDR( X14 );
        GOBACK( L16386 );
L16387:
        X11 = X13;
        X10 = sc_cons( X11, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X8 ), _S2CUINT( EMPTYLIST ) ) )  goto L16411;
        X11 = PAIR_CDR( X6 );
        X12 = PAIR_CDR( X7 );
        X9 = X10;
        X8 = X10;
        X7 = X12;
        X6 = X11;
        GOBACK( L16374 );
L16411:
        X11 = PAIR_CDR( X6 );
        X12 = PAIR_CDR( X7 );
        if  ( EQ( TSCPTAG( X9 ), PAIRTAG ) )  goto L16418;
        scdebug_error( c12316, 
                       c12317, CONS( X9, EMPTYLIST ) );
L16418:
        X9 = SETGEN( PAIR_CDR( X9 ), X10 );
        X7 = X12;
        X6 = X11;
        GOBACK( L16374 );
L16412:
        codetection_frames_2d_3evideo( X5, c12394, _TSCP( 4 ) );
        X5 = screp_exit_v;
        X5 = UNKNOWNCALL( X5, 0 );
        VIA( PROCEDURE_CODE( X5 ) )( PROCEDURE_CLOSURE( X5 ) );
L16370:
        SDVAL = X4;
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( codetection_get_2dpairs_v );
DEFCSTRING( t16420, "GET-PAIRS" );
EXTERNTSCPP( qobischeme_sort, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_sort_v );
EXTERNTSCPP( nlib_2dsc_ll_2dpairs_15170d9a, XAL1( TSCP ) );
EXTERNTSCP( nlib_2dsc_ll_2dpairs_15170d9a_v );
EXTERNTSCPP( qobischeme_identity, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_identity_v );
EXTERNTSCPP( scrt2__3d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3d_2dtwo_v );

TSCP  codetection_l12502( p12503, q12504, c16422 )
        TSCP  p12503, q12504, c16422;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "codetection_l12502 [inside GET-PAIRS]" );
        X1 = qobischeme_first( q12504 );
        X2 = qobischeme_first( p12503 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L16426;
        if  ( GTE( _S2CINT( X2 ), _S2CINT( X1 ) ) )  goto L16430;
        POPSTACKTRACE( TRUEVALUE );
L16426:
        if  ( FALSE( scrt2__3c_2dtwo( X2, X1 ) ) )  goto L16430;
        POPSTACKTRACE( TRUEVALUE );
L16430:
        X1 = qobischeme_first( p12503 );
        X2 = qobischeme_first( q12504 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L16435;
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( X2 ) ) )  goto L16439;
        POPSTACKTRACE( FALSEVALUE );
L16435:
        if  ( TRUE( scrt2__3d_2dtwo( X1, X2 ) ) )  goto L16439;
        POPSTACKTRACE( FALSEVALUE );
L16439:
        X1 = qobischeme_second( q12504 );
        X2 = qobischeme_second( p12503 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X1 ) ), 
                      3 ) )  goto L16443;
        POPSTACKTRACE( BOOLEAN( LT( _S2CINT( X2 ), 
                                    _S2CINT( X1 ) ) ) );
L16443:
        POPSTACKTRACE( scrt2__3c_2dtwo( X2, X1 ) );
}

TSCP  codetection_get_2dpairs( n12501 )
        TSCP  n12501;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( t16420 );
        X2 = qobischeme_map_2dn( qobischeme_identity_v, n12501 );
        X1 = nlib_2dsc_ll_2dpairs_15170d9a( X2 );
        X2 = MAKEPROCEDURE( 2, 
                            0, codetection_l12502, EMPTYLIST );
        POPSTACKTRACE( qobischeme_sort( X1, 
                                        X2, qobischeme_identity_v ) );
}

DEFTSCP( detection_s_2dmatlab_cd7c75e6_v );
DEFCSTRING( t16445, "SIMILARITY-BETWEEN-VIDEOS-MATLAB" );
EXTERNTSCPP( _2dmatlab_ematlab_21_8d661f42, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( _2dmatlab_ematlab_21_8d661f42_v );
EXTERNTSCPP( nlib_2dsc_d_3ematrix_eaa6578d, XAL1( TSCP ) );
EXTERNTSCP( nlib_2dsc_d_3ematrix_eaa6578d_v );
EXTERNTSCPP( codetectionlib_2dsc_join, XAL1( TSCP ) );
EXTERNTSCP( codetectionlib_2dsc_join_v );

TSCP  codetection_l12560( i12561, c16463 )
        TSCP  i12561, c16463;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "codetection_l12560 [inside SIMILARITY-BETWEEN-VIDEO\
S-MATLAB]" );
        X1 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c16463, 0 );
        X4 = DISPLAY( 1 );
        if  ( BITAND( BITOR( _S2CINT( X4 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16466;
        X5 = _TSCP( IPLUS( _S2CINT( X4 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L16467;
L16466:
        X5 = scrt2__2b_2dtwo( X4, _TSCP( 4 ) );
L16467:
        X3 = CONS( X5, EMPTYLIST );
        if  ( BITAND( BITOR( _S2CINT( i12561 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16468;
        X4 = _TSCP( IPLUS( _S2CINT( i12561 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L16469;
L16468:
        X4 = scrt2__2b_2dtwo( i12561, _TSCP( 4 ) );
L16469:
        X3 = CONS( X4, X3 );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12562, X3 ) ), 
                                       EMPTYLIST ) );
        X2 = _2dmatlab_2dvariable_a304468f( c12255 );
        DISPLAY( 1 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  codetection_l12558( t12559, c16461 )
        TSCP  t12559, c16461;
{
        TSCP  X1;
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( "codetection_l12558 [inside SIMILARITY-BETWEEN-VIDEO\
S-MATLAB]" );
        DISPLAY( 1 ) = t12559;
        X1 = MAKEPROCEDURE( 1, 
                            0, 
                            codetection_l12560, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 1 ) ) );
        SDVAL = qobischeme_map_2dn( X1, detection_tations_2a_bae473a_v );
        DISPLAY( 1 ) = SD1;
        POPSTACKTRACE( SDVAL );
}

TSCP  codetection_l12538( __12539, c16472 )
        TSCP  __12539, c16472;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "codetection_l12538 [inside SIMILARITY-BETWEEN-VIDEO\
S-MATLAB]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c16472, 0 );
        X2 = qobischeme_make_2dmatrix( DISPLAY( 0 ), 
                                       DISPLAY( 0 ), 
                                       CONS( _TSCP( 0 ), EMPTYLIST ) );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  codetection_l12536( __12537, c16470 )
        TSCP  __12537, c16470;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "codetection_l12536 [inside SIMILARITY-BETWEEN-VIDEO\
S-MATLAB]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c16470, 0 );
        X3 = MAKEPROCEDURE( 0, 
                            1, 
                            codetection_l12538, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X2 = qobischeme_map_2dn( X3, detection_tations_2a_bae473a_v );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  detection_s_2dmatlab_cd7c75e6( f12528, 
                                     f12529, 
                                     b12530, 
                                     b12531, 
                                     v12532, 
                                     v12533, f12534, t12535 )
        TSCP  f12528, 
              f12529, 
              b12530, 
              b12531, v12532, v12533, f12534, t12535;
{
        TSCP  X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t16445 );
        DISPLAY( 0 ) = t12535;
        if  ( FALSE( detection_hard_3f_2a_5334b1c_v ) )  goto L16447;
        _2dmatlab_dmatlab_21_16b982d3(  );
        X1 = CONS( detection_tations_2a_bae473a_v, EMPTYLIST );
        X1 = CONS( DISPLAY( 0 ), X1 );
        X1 = CONS( f12534, X1 );
        X1 = CONS( v12533, X1 );
        X1 = CONS( v12532, X1 );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12541, X1 ) ), 
                                       EMPTYLIST ) );
        X3 = _2dmatlab_2dvariable_a304468f( c12241 );
        X2 = qobischeme_x( X3 );
        X1 = qobischeme_x( X2 );
        if  ( NEQ( TSCPTAG( X1 ), FIXNUMTAG ) )  goto L16452;
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L16456;
        goto L16459;
L16452:
        if  ( FALSE( scrt2_zero_3f( X1 ) ) )  goto L16459;
L16456:
        X2 = CONS( v12533, EMPTYLIST );
        X2 = CONS( v12532, X2 );
        scrt6_format( TRUEVALUE, CONS( c12552, X2 ) );
        detection_2dmatrices_c6981307( f12528, c12553 );
        detection_2dmatrices_c6981307( f12529, c12554 );
        X3 = codetectionlib_2dsc_join( b12530 );
        X2 = nlib_2dsc_d_3ematrix_eaa6578d( X3 );
        _2dmatlab_ematlab_21_8d661f42( c12555, X2 );
        X3 = codetectionlib_2dsc_join( b12531 );
        X2 = nlib_2dsc_d_3ematrix_eaa6578d( X3 );
        _2dmatlab_ematlab_21_8d661f42( c12556, X2 );
        X2 = CONS( detection_tations_2a_bae473a_v, EMPTYLIST );
        X2 = CONS( DISPLAY( 0 ), X2 );
        X2 = CONS( f12534, X2 );
        X2 = CONS( v12533, X2 );
        X2 = CONS( v12532, X2 );
        toollib_2dmatlab_matlab( CONS( scrt6_format( FALSEVALUE, 
                                                     CONS( c12557, X2 ) ), 
                                       EMPTYLIST ) );
L16459:
        X1 = MAKEPROCEDURE( 1, 
                            0, codetection_l12558, EMPTYLIST );
        SDVAL = qobischeme_map_2dn( X1, f12534 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
L16447:
        X1 = MAKEPROCEDURE( 0, 
                            1, 
                            codetection_l12536, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        SDVAL = qobischeme_map_2dn( X1, f12534 );
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( detection_videos_2dc_c7669283_v );
DEFCSTRING( t16474, "SIMILARITY-BETWEEN-VIDEOS-C" );

TSCP  codetection_l12650( __12651, c16478 )
        TSCP  __12651, c16478;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "codetection_l12650 [inside SIMILARITY-BETWEEN-VIDEO\
S-C]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c16478, 0 );
        X2 = qobischeme_make_2dmatrix( DISPLAY( 0 ), 
                                       DISPLAY( 0 ), 
                                       CONS( _TSCP( 0 ), EMPTYLIST ) );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  codetection_l12648( __12649, c16476 )
        TSCP  __12649, c16476;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "codetection_l12648 [inside SIMILARITY-BETWEEN-VIDEO\
S-C]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c16476, 0 );
        X3 = MAKEPROCEDURE( 0, 
                            1, 
                            codetection_l12650, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X2 = qobischeme_map_2dn( X3, detection_tations_2a_bae473a_v );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

TSCP  detection_videos_2dc_c7669283( f12577, 
                                     f12578, 
                                     b12579, 
                                     b12580, 
                                     v12581, 
                                     v12582, f12583, t12584 )
        TSCP  f12577, 
              f12578, 
              b12579, 
              b12580, v12581, v12582, f12583, t12584;
{
        TSCP  X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t16474 );
        DISPLAY( 0 ) = t12584;
        X2 = MAKEPROCEDURE( 0, 
                            1, 
                            codetection_l12648, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        X1 = qobischeme_map_2dn( X2, f12583 );
        X3 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X3 = UNKNOWNCALL( X3, 2 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( _TSCP( 16 ), 
                                          X1, 
                                          PROCEDURE_CLOSURE( X3 ) );
        X3 = sc_int_tscp( check_similarity_between_videos( TSCP_POINTER( v12581 ), 
                                                           TSCP_POINTER( v12582 ), 
                                                           sc_tscp_int( f12583 ), 
                                                           sc_tscp_int( DISPLAY( 0 ) ), 
                                                           TSCP_POINTER( X2 ) ) );
        if  ( NEQ( TSCPTAG( X3 ), FIXNUMTAG ) )  goto L16484;
        if  ( EQ( _S2CUINT( X3 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L16488;
        goto L16491;
L16484:
        if  ( FALSE( scrt2_zero_3f( X3 ) ) )  goto L16491;
L16488:
        X4 = CONS( v12582, EMPTYLIST );
        X4 = CONS( v12581, X4 );
        scrt6_format( TRUEVALUE, CONS( c12601, X4 ) );
        X5 = asy_2dffi_d_2dto_2dc_5b40207f_v;
        X5 = UNKNOWNCALL( X5, 2 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( _TSCP( 4 ), 
                                          f12577, 
                                          PROCEDURE_CLOSURE( X5 ) );
        X6 = asy_2dffi_d_2dto_2dc_5b40207f_v;
        X6 = UNKNOWNCALL( X6, 2 );
        X5 = VIA( PROCEDURE_CODE( X6 ) )( _TSCP( 4 ), 
                                          f12578, 
                                          PROCEDURE_CLOSURE( X6 ) );
        X7 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X7 = UNKNOWNCALL( X7, 2 );
        X6 = VIA( PROCEDURE_CODE( X7 ) )( _TSCP( 12 ), 
                                          b12579, 
                                          PROCEDURE_CLOSURE( X7 ) );
        X8 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X8 = UNKNOWNCALL( X8, 2 );
        X7 = VIA( PROCEDURE_CODE( X8 ) )( _TSCP( 12 ), 
                                          b12580, 
                                          PROCEDURE_CLOSURE( X8 ) );
        X8 = DISPLAY( 0 );
        similarity_between_videos( TSCP_POINTER( X4 ), 
                                   TSCP_POINTER( X5 ), 
                                   TSCP_POINTER( X6 ), 
                                   TSCP_POINTER( X7 ), 
                                   TSCP_POINTER( v12581 ), 
                                   TSCP_POINTER( v12582 ), 
                                   sc_tscp_int( f12583 ), 
                                   sc_tscp_int( X8 ), 
                                   TSCP_POINTER( X2 ) );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 4 ), f12577, X4 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 4 ), f12578, X5 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 12 ), b12579, X6 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 12 ), b12580, X7 );
L16491:
        X10 = sc_cons( DISPLAY( 0 ), EMPTYLIST );
        X9 = sc_cons( DISPLAY( 0 ), X10 );
        X8 = sc_cons( detection_tations_2a_bae473a_v, X9 );
        X7 = sc_cons( f12583, X8 );
        X6 = X7;
        X5 = asy_2dffi_2dfrom_2dc_5625c28b_v;
        X5 = UNKNOWNCALL( X5, 3 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( X6, 
                                          c12635, 
                                          X2, 
                                          PROCEDURE_CLOSURE( X5 ) );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 16 ), X4, X2 );
        SDVAL = X4;
        DISPLAY( 0 ) = SD0;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( detection__2dsampled_11a49785_v );
DEFCSTRING( t16501, "SIMILARITY-AMONG-VIDEOS-SAMPLED" );
EXTERNTSCPP( scrt1_append_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_append_2dtwo_v );

TSCP  codetection_l12715( i12716, c16506 )
        TSCP  i12716, c16506;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "codetection_l12715 [inside SIMILARITY-AMONG-VIDEOS-\
SAMPLED]" );
        if  ( BITAND( BITOR( _S2CINT( i12716 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16508;
        X3 = _TSCP( IPLUS( _S2CINT( i12716 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L16509;
L16508:
        X3 = scrt2__2b_2dtwo( i12716, _TSCP( 4 ) );
L16509:
        X2 = sc_cons( X3, EMPTYLIST );
        X1 = sc_cons( i12716, X2 );
        POPSTACKTRACE( X1 );
}

EXTERNTSCPP( scrt1_list_2dref, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_list_2dref_v );

TSCP  detection__2dsampled_11a49785( s12655, 
                                     f12656, 
                                     b12657, 
                                     v12658, 
                                     f12659, t12660, m12661 )
        TSCP  s12655, 
              f12656, 
              b12657, v12658, f12659, t12660, m12661;
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

        PUSHSTACKTRACE( t16501 );
        X1 = scrt1_length( f12656 );
        if  ( NEQ( _S2CUINT( m12661 ), 
                   _S2CUINT( _TSCP( 4 ) ) ) )  goto L16504;
        X4 = MAKEPROCEDURE( 1, 
                            0, codetection_l12715, EMPTYLIST );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16511;
        X5 = _TSCP( IDIFFERENCE( _S2CINT( X1 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L16512;
L16511:
        X5 = scrt2__2d_2dtwo( X1, _TSCP( 4 ) );
L16512:
        X3 = qobischeme_map_2dn( X4, X5 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16513;
        X9 = _TSCP( IDIFFERENCE( _S2CINT( X1 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L16514;
L16513:
        X9 = scrt2__2d_2dtwo( X1, _TSCP( 4 ) );
L16514:
        X8 = sc_cons( X9, EMPTYLIST );
        X7 = sc_cons( _TSCP( 0 ), X8 );
        X6 = X7;
        X5 = sc_cons( X6, EMPTYLIST );
        X4 = X5;
        X2 = scrt1_append_2dtwo( X3, X4 );
        goto L16505;
L16504:
        X2 = codetection_get_2dpairs( X1 );
L16505:
        X3 = X2;
        X4 = EMPTYLIST;
        X5 = EMPTYLIST;
L16519:
        if  ( EQ( _S2CUINT( X3 ), _S2CUINT( EMPTYLIST ) ) )  goto L16520;
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L16523;
        scrt1__24__car_2derror( X3 );
L16523:
        X8 = PAIR_CAR( X3 );
        X11 = qobischeme_first( X8 );
        X10 = scrt1_list_2dref( f12656, X11 );
        X12 = qobischeme_second( X8 );
        X11 = scrt1_list_2dref( f12656, X12 );
        X13 = qobischeme_first( X8 );
        X12 = scrt1_list_2dref( b12657, X13 );
        X14 = qobischeme_second( X8 );
        X13 = scrt1_list_2dref( b12657, X14 );
        X15 = qobischeme_first( X8 );
        X14 = scrt1_list_2dref( v12658, X15 );
        X16 = qobischeme_second( X8 );
        X15 = scrt1_list_2dref( v12658, X16 );
        X9 = s12655;
        X9 = UNKNOWNCALL( X9, 8 );
        X7 = VIA( PROCEDURE_CODE( X9 ) )( X10, 
                                          X11, 
                                          X12, 
                                          X13, 
                                          X14, 
                                          X15, 
                                          f12659, 
                                          t12660, 
                                          PROCEDURE_CLOSURE( X9 ) );
        X6 = sc_cons( X7, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L16527;
        X7 = PAIR_CDR( X3 );
        X5 = X6;
        X4 = X6;
        X3 = X7;
        GOBACK( L16519 );
L16527:
        X7 = PAIR_CDR( X3 );
        if  ( EQ( TSCPTAG( X5 ), PAIRTAG ) )  goto L16532;
        scdebug_error( c12316, 
                       c12317, CONS( X5, EMPTYLIST ) );
L16532:
        X5 = SETGEN( PAIR_CDR( X5 ), X6 );
        X3 = X7;
        GOBACK( L16519 );
L16520:
        POPSTACKTRACE( X4 );
}

DEFTSCP( detection_g_2dvideos_bd193643_v );
DEFCSTRING( t16534, "SIMILARITY-AMONG-VIDEOS" );
EXTERNTSCPP( scrt2__2a_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2a_2dtwo_v );
EXTERNTSCPP( sc_apply_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_apply_2dtwo_v );
EXTERNTSCPP( scrt2_min, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_min_v );
EXTERNTSCPP( scrt2__3e_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3e_2dtwo_v );
EXTERNTSCPP( qobischeme_panic, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_panic_v );
EXTERNTSCPP( nlib_2dsc_2dpick_2dm_2b0fa3e, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( nlib_2dsc_2dpick_2dm_2b0fa3e_v );
EXTERNTSCPP( qobischeme_reduce, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_reduce_v );
EXTERNTSCPP( dbindings_trix_2dmax_de624a4f, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( dbindings_trix_2dmax_de624a4f_v );
EXTERNTSCPP( qobischeme_k_2am, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_k_2am_v );
EXTERNTSCPP( qobischeme_m_2b, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_m_2b_v );
EXTERNTSCP( sc_emptyvector );

TSCP  detection_g_2dvideos_bd193643( f12744, 
                                     b12745, 
                                     v12746, 
                                     f12747, t12748, m12749 )
        TSCP  f12744, 
              b12745, v12746, f12747, t12748, m12749;
{
        TSCP  X38, 
              X37, 
              X36, 
              X35, 
              X34, 
              X33, 
              X32, 
              X31, 
              X30, 
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

        PUSHSTACKTRACE( t16534 );
        X1 = scrt1_length( f12744 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16538;
        if  ( EQ( _S2CUINT( X1 ), _S2CUINT( _TSCP( 4 ) ) ) )  goto L16542;
        goto L16543;
L16538:
        if  ( FALSE( scrt2__3d_2dtwo( X1, _TSCP( 4 ) ) ) )  goto L16543;
L16542:
        X3 = sc_cons( _TSCP( 0 ), EMPTYLIST );
        X2 = sc_cons( EMPTYLIST, X3 );
        X1 = sc_cons( EMPTYLIST, X2 );
        POPSTACKTRACE( X1 );
L16543:
        X1 = scrt1_length( f12744 );
        if  ( NEQ( _S2CUINT( m12749 ), 
                   _S2CUINT( _TSCP( 4 ) ) ) )  goto L16548;
        X2 = X1;
        goto L16567;
L16548:
        if  ( BITAND( BITOR( _S2CINT( X1 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L16550;
        X4 = _TSCP( IDIFFERENCE( _S2CINT( X1 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L16551;
L16550:
        X4 = scrt2__2d_2dtwo( X1, _TSCP( 4 ) );
L16551:
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X4 ) ), 
                      3 ) )  goto L16553;
        X3 = _TSCP( ITIMES( FIXED_C( X1 ), _S2CINT( X4 ) ) );
        goto L16554;
L16553:
        X3 = scrt2__2a_2dtwo( X1, X4 );
L16554:
        X4 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( X3 ), 
                                          _S2CINT( _TSCP( 8 ) ) ), 
                                   3 ) ) );
        if  ( FALSE( X4 ) )  goto L16566;
        if  ( EQ( _S2CUINT( _TSCP( 8 ) ), 
                  _S2CUINT( _TSCP( 0 ) ) ) )  goto L16566;
        X5 = _TSCP( REMAINDER( _S2CINT( X3 ), 
                               _S2CINT( _TSCP( 8 ) ) ) );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L16566;
        X2 = C_FIXED( QUOTIENT( _S2CINT( X3 ), 
                                _S2CINT( _TSCP( 8 ) ) ) );
        goto L16567;
L16566:
        X2 = scrt2__2f_2dtwo( X3, _TSCP( 8 ) );
L16567:
        X4 = f12744;
        X5 = EMPTYLIST;
        X6 = EMPTYLIST;
L16571:
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L16572;
        X3 = X5;
        goto L16579;
L16572:
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L16575;
        scrt1__24__car_2derror( X4 );
L16575:
        X9 = PAIR_CAR( X4 );
        X8 = scrt1_length( X9 );
        X7 = sc_cons( X8, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L16578;
        X8 = PAIR_CDR( X4 );
        X6 = X7;
        X5 = X7;
        X4 = X8;
        GOBACK( L16571 );
L16578:
        X8 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L16583;
        scdebug_error( c12316, 
                       c12317, CONS( X6, EMPTYLIST ) );
L16583:
        X6 = SETGEN( PAIR_CDR( X6 ), X7 );
        X4 = X8;
        GOBACK( L16571 );
L16579:
        X5 = sc_apply_2dtwo( scrt2_min_v, X3 );
        if  ( BITAND( BITOR( _S2CINT( f12747 ), 
                             _S2CINT( X5 ) ), 
                      3 ) )  goto L16588;
        if  ( GT( _S2CINT( f12747 ), _S2CINT( X5 ) ) )  goto L16592;
        X4 = f12747;
        goto L16595;
L16588:
        if  ( TRUE( scrt2__3e_2dtwo( f12747, X5 ) ) )  goto L16592;
        X4 = f12747;
        goto L16595;
L16592:
        X4 = qobischeme_panic( c13258, EMPTYLIST );
L16595:
        X6 = X3;
        X7 = EMPTYLIST;
        X8 = EMPTYLIST;
L16598:
        if  ( NEQ( _S2CUINT( X6 ), _S2CUINT( EMPTYLIST ) ) )  goto L16599;
        X5 = X7;
        goto L16607;
L16599:
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L16602;
        scrt1__24__car_2derror( X6 );
L16602:
        X11 = PAIR_CAR( X6 );
        X12 = qobischeme_map_2dn( qobischeme_identity_v, X11 );
        X10 = nlib_2dsc_2dpick_2dm_2b0fa3e( X12, X4 );
        X9 = sc_cons( X10, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X7 ), _S2CUINT( EMPTYLIST ) ) )  goto L16606;
        X10 = PAIR_CDR( X6 );
        X8 = X9;
        X7 = X9;
        X6 = X10;
        GOBACK( L16598 );
L16606:
        X10 = PAIR_CDR( X6 );
        if  ( EQ( TSCPTAG( X8 ), PAIRTAG ) )  goto L16611;
        scdebug_error( c12316, 
                       c12317, CONS( X8, EMPTYLIST ) );
L16611:
        X8 = SETGEN( PAIR_CDR( X8 ), X9 );
        X6 = X10;
        GOBACK( L16598 );
L16607:
        X7 = f12744;
        X8 = X5;
        X9 = EMPTYLIST;
        X10 = EMPTYLIST;
L16615:
        if  ( NEQ( _S2CUINT( X7 ), _S2CUINT( EMPTYLIST ) ) )  goto L16616;
        X6 = X9;
        goto L16642;
L16616:
        if  ( EQ( TSCPTAG( X8 ), PAIRTAG ) )  goto L16619;
        scrt1__24__car_2derror( X8 );
L16619:
        X13 = PAIR_CAR( X8 );
        if  ( EQ( TSCPTAG( X7 ), PAIRTAG ) )  goto L16622;
        scrt1__24__car_2derror( X7 );
L16622:
        X14 = PAIR_CAR( X7 );
        X15 = X13;
        X16 = EMPTYLIST;
        X17 = EMPTYLIST;
L16626:
        if  ( NEQ( _S2CUINT( X15 ), _S2CUINT( EMPTYLIST ) ) )  goto L16627;
        X12 = X16;
        goto L16634;
L16627:
        if  ( EQ( TSCPTAG( X15 ), PAIRTAG ) )  goto L16630;
        scrt1__24__car_2derror( X15 );
L16630:
        X20 = PAIR_CAR( X15 );
        X19 = scrt1_list_2dref( X14, X20 );
        X18 = sc_cons( X19, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X16 ), _S2CUINT( EMPTYLIST ) ) )  goto L16633;
        X19 = PAIR_CDR( X15 );
        X17 = X18;
        X16 = X18;
        X15 = X19;
        GOBACK( L16626 );
L16633:
        X19 = PAIR_CDR( X15 );
        if  ( EQ( TSCPTAG( X17 ), PAIRTAG ) )  goto L16638;
        scdebug_error( c12316, 
                       c12317, CONS( X17, EMPTYLIST ) );
L16638:
        X17 = SETGEN( PAIR_CDR( X17 ), X18 );
        X15 = X19;
        GOBACK( L16626 );
L16634:
        X11 = sc_cons( X12, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X9 ), _S2CUINT( EMPTYLIST ) ) )  goto L16641;
        X12 = PAIR_CDR( X7 );
        X13 = PAIR_CDR( X8 );
        X10 = X11;
        X9 = X11;
        X8 = X13;
        X7 = X12;
        GOBACK( L16615 );
L16641:
        X12 = PAIR_CDR( X7 );
        X13 = PAIR_CDR( X8 );
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L16648;
        scdebug_error( c12316, 
                       c12317, CONS( X10, EMPTYLIST ) );
L16648:
        X10 = SETGEN( PAIR_CDR( X10 ), X11 );
        X8 = X13;
        X7 = X12;
        GOBACK( L16615 );
L16642:
        X8 = b12745;
        X9 = X5;
        X10 = EMPTYLIST;
        X11 = EMPTYLIST;
L16652:
        if  ( NEQ( _S2CUINT( X8 ), _S2CUINT( EMPTYLIST ) ) )  goto L16653;
        X7 = X10;
        goto L16679;
L16653:
        if  ( EQ( TSCPTAG( X9 ), PAIRTAG ) )  goto L16656;
        scrt1__24__car_2derror( X9 );
L16656:
        X14 = PAIR_CAR( X9 );
        if  ( EQ( TSCPTAG( X8 ), PAIRTAG ) )  goto L16659;
        scrt1__24__car_2derror( X8 );
L16659:
        X15 = PAIR_CAR( X8 );
        X16 = X14;
        X17 = EMPTYLIST;
        X18 = EMPTYLIST;
L16663:
        if  ( NEQ( _S2CUINT( X16 ), _S2CUINT( EMPTYLIST ) ) )  goto L16664;
        X13 = X17;
        goto L16671;
L16664:
        if  ( EQ( TSCPTAG( X16 ), PAIRTAG ) )  goto L16667;
        scrt1__24__car_2derror( X16 );
L16667:
        X21 = PAIR_CAR( X16 );
        X20 = scrt1_list_2dref( X15, X21 );
        X19 = sc_cons( X20, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X17 ), _S2CUINT( EMPTYLIST ) ) )  goto L16670;
        X20 = PAIR_CDR( X16 );
        X18 = X19;
        X17 = X19;
        X16 = X20;
        GOBACK( L16663 );
L16670:
        X20 = PAIR_CDR( X16 );
        if  ( EQ( TSCPTAG( X18 ), PAIRTAG ) )  goto L16675;
        scdebug_error( c12316, 
                       c12317, CONS( X18, EMPTYLIST ) );
L16675:
        X18 = SETGEN( PAIR_CDR( X18 ), X19 );
        X16 = X20;
        GOBACK( L16663 );
L16671:
        X12 = sc_cons( X13, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X10 ), _S2CUINT( EMPTYLIST ) ) )  goto L16678;
        X13 = PAIR_CDR( X8 );
        X14 = PAIR_CDR( X9 );
        X11 = X12;
        X10 = X12;
        X9 = X14;
        X8 = X13;
        GOBACK( L16652 );
L16678:
        X13 = PAIR_CDR( X8 );
        X14 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X11 ), PAIRTAG ) )  goto L16685;
        scdebug_error( c12316, 
                       c12317, CONS( X11, EMPTYLIST ) );
L16685:
        X11 = SETGEN( PAIR_CDR( X11 ), X12 );
        X9 = X14;
        X8 = X13;
        GOBACK( L16652 );
L16679:
        X8 = CONS( X2, EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c12773, X8 ) );
        X8 = CONS( X5, EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c12774, X8 ) );
        X9 = X6;
        X10 = EMPTYLIST;
        X11 = EMPTYLIST;
L16690:
        if  ( NEQ( _S2CUINT( X9 ), _S2CUINT( EMPTYLIST ) ) )  goto L16691;
        X12 = X10;
        goto L16698;
L16691:
        if  ( EQ( TSCPTAG( X9 ), PAIRTAG ) )  goto L16694;
        scrt1__24__car_2derror( X9 );
L16694:
        X15 = PAIR_CAR( X9 );
        X14 = scrt1_length( X15 );
        X13 = sc_cons( X14, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X10 ), _S2CUINT( EMPTYLIST ) ) )  goto L16697;
        X14 = PAIR_CDR( X9 );
        X11 = X13;
        X10 = X13;
        X9 = X14;
        GOBACK( L16690 );
L16697:
        X14 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X11 ), PAIRTAG ) )  goto L16702;
        scdebug_error( c12316, 
                       c12317, CONS( X11, EMPTYLIST ) );
L16702:
        X11 = SETGEN( PAIR_CDR( X11 ), X13 );
        X9 = X14;
        GOBACK( L16690 );
L16698:
        X8 = CONS( X12, EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c12774, X8 ) );
        X10 = detection__2dsampled_11a49785( detection_s_2dmatlab_cd7c75e6_v, 
                                             X6, 
                                             X7, 
                                             v12746, 
                                             X4, t12748, m12749 );
        X11 = detection__2dsampled_11a49785( detection_videos_2dc_c7669283_v, 
                                             X6, 
                                             X7, 
                                             v12746, 
                                             X4, t12748, m12749 );
        X12 = X11;
        X13 = X10;
        X14 = EMPTYLIST;
        X15 = EMPTYLIST;
L16706:
        if  ( NEQ( _S2CUINT( X12 ), _S2CUINT( EMPTYLIST ) ) )  goto L16707;
        X9 = X14;
        goto L16762;
L16707:
        if  ( EQ( TSCPTAG( X13 ), PAIRTAG ) )  goto L16710;
        scrt1__24__car_2derror( X13 );
L16710:
        X18 = PAIR_CAR( X13 );
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L16713;
        scrt1__24__car_2derror( X12 );
L16713:
        X19 = PAIR_CAR( X12 );
        X20 = X19;
        X21 = X18;
        X22 = EMPTYLIST;
        X23 = EMPTYLIST;
L16717:
        if  ( NEQ( _S2CUINT( X20 ), _S2CUINT( EMPTYLIST ) ) )  goto L16718;
        X17 = X22;
        goto L16752;
L16718:
        if  ( EQ( TSCPTAG( X20 ), PAIRTAG ) )  goto L16721;
        scrt1__24__car_2derror( X20 );
L16721:
        X26 = PAIR_CAR( X20 );
        if  ( EQ( TSCPTAG( X21 ), PAIRTAG ) )  goto L16724;
        scrt1__24__car_2derror( X21 );
L16724:
        X27 = PAIR_CAR( X21 );
        X29 = X26;
        X30 = X27;
        X31 = EMPTYLIST;
        X32 = EMPTYLIST;
L16728:
        if  ( NEQ( _S2CUINT( X29 ), _S2CUINT( EMPTYLIST ) ) )  goto L16729;
        X28 = X31;
        goto L16742;
L16729:
        if  ( EQ( TSCPTAG( X30 ), PAIRTAG ) )  goto L16732;
        scrt1__24__car_2derror( X30 );
L16732:
        X35 = PAIR_CAR( X30 );
        if  ( EQ( TSCPTAG( X29 ), PAIRTAG ) )  goto L16735;
        scrt1__24__car_2derror( X29 );
L16735:
        X36 = PAIR_CAR( X29 );
        if  ( FALSE( detection_hard_3f_2a_5334b1c_v ) )  goto L16738;
        X37 = c12999;
        goto L16739;
L16738:
        X37 = _TSCP( 4 );
L16739:
        X38 = qobischeme_m_2b( X36, X35 );
        X34 = qobischeme_k_2am( X37, X38 );
        X33 = sc_cons( X34, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X31 ), _S2CUINT( EMPTYLIST ) ) )  goto L16741;
        X34 = PAIR_CDR( X29 );
        X35 = PAIR_CDR( X30 );
        X32 = X33;
        X31 = X33;
        X30 = X35;
        X29 = X34;
        GOBACK( L16728 );
L16741:
        X34 = PAIR_CDR( X29 );
        X35 = PAIR_CDR( X30 );
        if  ( EQ( TSCPTAG( X32 ), PAIRTAG ) )  goto L16748;
        scdebug_error( c12316, 
                       c12317, CONS( X32, EMPTYLIST ) );
L16748:
        X32 = SETGEN( PAIR_CDR( X32 ), X33 );
        X30 = X35;
        X29 = X34;
        GOBACK( L16728 );
L16742:
        X25 = qobischeme_reduce( dbindings_trix_2dmax_de624a4f_v, 
                                 X28, sc_emptyvector );
        X24 = sc_cons( X25, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X22 ), _S2CUINT( EMPTYLIST ) ) )  goto L16751;
        X25 = PAIR_CDR( X20 );
        X26 = PAIR_CDR( X21 );
        X23 = X24;
        X22 = X24;
        X21 = X26;
        X20 = X25;
        GOBACK( L16717 );
L16751:
        X25 = PAIR_CDR( X20 );
        X26 = PAIR_CDR( X21 );
        if  ( EQ( TSCPTAG( X23 ), PAIRTAG ) )  goto L16758;
        scdebug_error( c12316, 
                       c12317, CONS( X23, EMPTYLIST ) );
L16758:
        X23 = SETGEN( PAIR_CDR( X23 ), X24 );
        X21 = X26;
        X20 = X25;
        GOBACK( L16717 );
L16752:
        X16 = sc_cons( X17, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X14 ), _S2CUINT( EMPTYLIST ) ) )  goto L16761;
        X17 = PAIR_CDR( X12 );
        X18 = PAIR_CDR( X13 );
        X15 = X16;
        X14 = X16;
        X13 = X18;
        X12 = X17;
        GOBACK( L16706 );
L16761:
        X17 = PAIR_CDR( X12 );
        X18 = PAIR_CDR( X13 );
        if  ( EQ( TSCPTAG( X15 ), PAIRTAG ) )  goto L16768;
        scdebug_error( c12316, 
                       c12317, CONS( X15, EMPTYLIST ) );
L16768:
        X15 = SETGEN( PAIR_CDR( X15 ), X16 );
        X13 = X18;
        X12 = X17;
        GOBACK( L16706 );
L16762:
        X11 = sc_cons( X4, EMPTYLIST );
        X10 = sc_cons( X5, X11 );
        X8 = sc_cons( X9, X10 );
        POPSTACKTRACE( X8 );
}

DEFTSCP( detection_appearance_369afa03_v );
DEFCSTRING( t16771, "GET-AVERAGE-OBJECT-APPEARANCE" );
EXTERNTSCPP( qobischeme_sublist, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_sublist_v );
EXTERNTSCPP( qobischeme_rest, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_rest_v );
EXTERNTSCP( asy_2dffi_t_2dto_2dc_d3906c33_v );

TSCP  detection_appearance_369afa03( b13342, 
                                     t13343, p13344, f13345 )
        TSCP  b13342, t13343, p13344, f13345;
{
        TSCP  X18, 
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

        PUSHSTACKTRACE( t16771 );
        X2 = _TSCP( 0 );
        X3 = EMPTYLIST;
        X4 = t13343;
L16774:
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L16775;
        X1 = scrt1_reverse( X3 );
        goto L16776;
L16775:
        X6 = qobischeme_first( X4 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X6 ) ), 
                      3 ) )  goto L16778;
        X5 = _TSCP( IPLUS( _S2CINT( X2 ), _S2CINT( X6 ) ) );
        goto L16779;
L16778:
        X5 = scrt2__2b_2dtwo( X2, X6 );
L16779:
        X9 = qobischeme_first( X4 );
        if  ( BITAND( BITOR( _S2CINT( X2 ), _S2CINT( X9 ) ), 
                      3 ) )  goto L16781;
        X8 = _TSCP( IPLUS( _S2CINT( X2 ), _S2CINT( X9 ) ) );
        goto L16782;
L16781:
        X8 = scrt2__2b_2dtwo( X2, X9 );
L16782:
        X7 = qobischeme_sublist( b13342, X2, X8 );
        X6 = sc_cons( X7, X3 );
        X4 = qobischeme_rest( X4 );
        X3 = X6;
        X2 = X5;
        GOBACK( L16774 );
L16776:
        X3 = X1;
        X4 = p13344;
        X5 = EMPTYLIST;
        X6 = EMPTYLIST;
L16785:
        if  ( NEQ( _S2CUINT( X3 ), _S2CUINT( EMPTYLIST ) ) )  goto L16786;
        X2 = X5;
        goto L16817;
L16786:
        if  ( EQ( TSCPTAG( X3 ), PAIRTAG ) )  goto L16789;
        scrt1__24__car_2derror( X3 );
L16789:
        X9 = PAIR_CAR( X3 );
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L16792;
        scrt1__24__car_2derror( X4 );
L16792:
        X10 = PAIR_CAR( X4 );
        X11 = X9;
        X12 = X10;
        X13 = EMPTYLIST;
        X14 = EMPTYLIST;
L16796:
        if  ( NEQ( _S2CUINT( X11 ), _S2CUINT( EMPTYLIST ) ) )  goto L16797;
        X8 = X13;
        goto L16807;
L16797:
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L16800;
        scrt1__24__car_2derror( X12 );
L16800:
        X17 = PAIR_CAR( X12 );
        if  ( EQ( TSCPTAG( X11 ), PAIRTAG ) )  goto L16803;
        scrt1__24__car_2derror( X11 );
L16803:
        X18 = PAIR_CAR( X11 );
        X16 = scrt1_list_2dref( X17, X18 );
        X15 = sc_cons( X16, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X13 ), _S2CUINT( EMPTYLIST ) ) )  goto L16806;
        X16 = PAIR_CDR( X11 );
        X17 = PAIR_CDR( X12 );
        X14 = X15;
        X13 = X15;
        X12 = X17;
        X11 = X16;
        GOBACK( L16796 );
L16806:
        X16 = PAIR_CDR( X11 );
        X17 = PAIR_CDR( X12 );
        if  ( EQ( TSCPTAG( X14 ), PAIRTAG ) )  goto L16813;
        scdebug_error( c12316, 
                       c12317, CONS( X14, EMPTYLIST ) );
L16813:
        X14 = SETGEN( PAIR_CDR( X14 ), X15 );
        X12 = X17;
        X11 = X16;
        GOBACK( L16796 );
L16807:
        X7 = sc_cons( X8, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X5 ), _S2CUINT( EMPTYLIST ) ) )  goto L16816;
        X8 = PAIR_CDR( X3 );
        X9 = PAIR_CDR( X4 );
        X6 = X7;
        X5 = X7;
        X4 = X9;
        X3 = X8;
        GOBACK( L16785 );
L16816:
        X8 = PAIR_CDR( X3 );
        X9 = PAIR_CDR( X4 );
        if  ( EQ( TSCPTAG( X6 ), PAIRTAG ) )  goto L16823;
        scdebug_error( c12316, 
                       c12317, CONS( X6, EMPTYLIST ) );
L16823:
        X6 = SETGEN( PAIR_CDR( X6 ), X7 );
        X4 = X9;
        X3 = X8;
        GOBACK( L16785 );
L16817:
        X4 = asy_2dffi_d_2dto_2dc_5b40207f_v;
        X4 = UNKNOWNCALL( X4, 2 );
        X3 = VIA( PROCEDURE_CODE( X4 ) )( _TSCP( 8 ), 
                                          f13345, 
                                          PROCEDURE_CLOSURE( X4 ) );
        X5 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X5 = UNKNOWNCALL( X5, 2 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( _TSCP( 12 ), 
                                          X2, 
                                          PROCEDURE_CLOSURE( X5 ) );
        X6 = asy_2dffi_t_2dto_2dc_d3906c33_v;
        X6 = UNKNOWNCALL( X6, 2 );
        X5 = VIA( PROCEDURE_CODE( X6 ) )( _TSCP( 4 ), 
                                          t13343, 
                                          PROCEDURE_CLOSURE( X6 ) );
        X6 = scrt1_length( f13345 );
        average_object_appearance( TSCP_POINTER( X3 ), 
                                   TSCP_POINTER( X4 ), 
                                   sc_tscp_int( X6 ), 
                                   TSCP_POINTER( X5 ) );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 8 ), f13345, X3 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 12 ), X2, X4 );
        POPSTACKTRACE( easy_2dffi_easy_2dffi_3afree( _TSCP( 4 ), 
                                                     t13343, X5 ) );
}

DEFTSCP( detection_dinference_299999ac_v );
DEFCSTRING( t16831, "BP-SENTENCES-INFERENCE" );

TSCP  detection_dinference_299999ac( g13516, 
                                     g13517, 
                                     g13518, 
                                     g13519, 
                                     g13520, 
                                     g13521, 
                                     g13522, 
                                     g13523, 
                                     g13524, 
                                     g13525, 
                                     g13526, 
                                     g13527, 
                                     g13528, 
                                     g13529, 
                                     g13530, g13531, g13532 )
        TSCP  g13516, 
              g13517, 
              g13518, 
              g13519, 
              g13520, 
              g13521, 
              g13522, 
              g13523, 
              g13524, 
              g13525, 
              g13526, 
              g13527, 
              g13528, g13529, g13530, g13531, g13532;
{
        PUSHSTACKTRACE( t16831 );
        POPSTACKTRACE( DOUBLE_TSCP( bp_sentences_inference( TSCP_POINTER( g13516 ), 
                                                            TSCP_POINTER( g13517 ), 
                                                            TSCP_POINTER( g13518 ), 
                                                            TSCP_POINTER( g13519 ), 
                                                            TSCP_POINTER( g13520 ), 
                                                            sc_tscp_int( g13521 ), 
                                                            TSCP_POINTER( g13522 ), 
                                                            TSCP_POINTER( g13523 ), 
                                                            TSCP_POINTER( g13524 ), 
                                                            TSCP_POINTER( g13525 ), 
                                                            sc_tscp_int( g13526 ), 
                                                            TSCP_POINTER( g13527 ), 
                                                            TSCP_POINTER( g13528 ), 
                                                            TSCP_POINTER( g13529 ), 
                                                            sc_tscp_int( g13530 ), 
                                                            sc_tscp_int( g13531 ), 
                                                            TSCP_POINTER( g13532 ) ) ) );
}

DEFTSCP( codetection_main_v );
DEFCSTRING( t16833, "MAIN" );

TSCP  codetection_s13557( s13559, u13560 )
        TSCP  s13559, u13560;
{
        PUSHSTACKTRACE( "STRING-ARGUMENT [inside MAIN]" );
        POPSTACKTRACE( s13559 );
}

EXTERNTSCPP( scrt2_string_2d_3enumber, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_string_2d_3enumber_v );
EXTERNTSCPP( scrt2_round, XAL1( TSCP ) );
EXTERNTSCP( scrt2_round_v );

TSCP  codetection_i13556( s13562, u13563 )
        TSCP  s13562, u13563;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "INTEGER-ARGUMENT [inside MAIN]" );
        X1 = scrt2_string_2d_3enumber( s13562, EMPTYLIST );
        if  ( EQ( TSCPTAG( X1 ), FIXNUMTAG ) )  goto L16854;
        if  ( NOT( AND( EQ( TSCPTAG( X1 ), EXTENDEDTAG ), 
                        EQ( TSCP_EXTENDEDTAG( X1 ), 
                            DOUBLEFLOATTAG ) ) ) )  goto L16853;
        X2 = scrt2_round( X1 );
        if  ( BITAND( BITOR( _S2CINT( X1 ), _S2CINT( X2 ) ), 
                      3 ) )  goto L16846;
        if  ( NEQ( _S2CUINT( X1 ), _S2CUINT( X2 ) ) )  goto L16853;
        goto L16854;
L16846:
        if  ( TRUE( scrt2__3d_2dtwo( X1, X2 ) ) )  goto L16854;
L16853:
        X2 = u13563;
        X2 = UNKNOWNCALL( X2, 0 );
        VIA( PROCEDURE_CODE( X2 ) )( PROCEDURE_CLOSURE( X2 ) );
L16854:
        POPSTACKTRACE( X1 );
}

TSCP  codetection_r13555( s13590, u13591 )
        TSCP  s13590, u13591;
{
        TSCP  X2, X1;

        PUSHSTACKTRACE( "REAL-ARGUMENT [inside MAIN]" );
        X1 = scrt2_string_2d_3enumber( s13590, EMPTYLIST );
        if  ( EQ( TSCPTAG( X1 ), FIXNUMTAG ) )  goto L16859;
        if  ( AND( EQ( TSCPTAG( X1 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( X1 ), DOUBLEFLOATTAG ) )
            )  goto L16859;
        X2 = u13591;
        X2 = UNKNOWNCALL( X2, 0 );
        VIA( PROCEDURE_CODE( X2 ) )( PROCEDURE_CLOSURE( X2 ) );
L16859:
        POPSTACKTRACE( X1 );
}

EXTERNTSCP( scrt5_stderr_2dport_v );

TSCP  codetection_u13607( c16863 )
        TSCP  c16863;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "USAGE [inside MAIN]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c16863, 0 );
        X3 = CONS( DISPLAY( 0 ), EMPTYLIST );
        scrt6_format( scrt5_stderr_2dport_v, 
                      CONS( c13609, X3 ) );
        X3 = screp_exit_v;
        X3 = UNKNOWNCALL( X3, 1 );
        X2 = VIA( PROCEDURE_CODE( X3 ) )( _TSCP( -4 ), 
                                          PROCEDURE_CLOSURE( X3 ) );
        DISPLAY( 0 ) = X1;
        POPSTACKTRACE( X2 );
}

EXTERNTSCP( sc_emptystring );
EXTERNTSCPP( scrt3_string_3d_3f, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt3_string_3d_3f_v );
EXTERNTSCPP( scrt6_newline, XAL1( TSCP ) );
EXTERNTSCP( scrt6_newline_v );
EXTERNTSCPP( scrt1_equal_3f, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_equal_3f_v );
EXTERNTSCPP( scrt1_cons_2a, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_cons_2a_v );
EXTERNTSCPP( pregexp_pregexp_2dsplit, XAL2( TSCP, TSCP ) );
EXTERNTSCP( pregexp_pregexp_2dsplit_v );
EXTERNTSCP( parser__2aobjects_2dhouse_2a_v );
EXTERNTSCP( parser__2aobjects_2dcad_2a_v );
EXTERNTSCPP( qobischeme_read_2dfile, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_read_2dfile_v );
EXTERNTSCPP( scrt1_assoc, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_assoc_v );
EXTERNTSCPP( scrt3_string_3c_3f, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt3_string_3c_3f_v );
EXTERNTSCPP( scrt6_pp, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt6_pp_v );
EXTERNTSCPP( scrt2_exact_2d_3einexact, XAL1( TSCP ) );
EXTERNTSCP( scrt2_exact_2d_3einexact_v );
EXTERNTSCPP( sc_make_2dstring, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_make_2dstring_v );

TSCP  codetection_l15540( c17202 )
        TSCP  c17202;
{
        TSCP  X18, 
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

        PUSHSTACKTRACE( "codetection_l15540 [inside MAIN]" );
        X1 = DISPLAY( 4 );
        DISPLAY( 4 ) = CLOSURE_VAR( c17202, 0 );
        X2 = DISPLAY( 5 );
        DISPLAY( 5 ) = CLOSURE_VAR( c17202, 1 );
        X3 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c17202, 2 );
        X4 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c17202, 3 );
        X5 = DISPLAY( 3 );
        DISPLAY( 3 ) = CLOSURE_VAR( c17202, 4 );
        X7 = detection_2ddepth_2a_8800758e_v;
        if  ( BITAND( BITOR( _S2CINT( X7 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17205;
        X8 = _TSCP( IPLUS( _S2CINT( X7 ), 
                           _S2CINT( _TSCP( 4 ) ) ) );
        goto L17206;
L17205:
        X8 = scrt2__2b_2dtwo( X7, _TSCP( 4 ) );
L17206:
        detection_2ddepth_2a_8800758e_v = X8;
        X8 = DISPLAY( 5 );
        X9 = DISPLAY( 4 );
        X10 = X8;
        X11 = X9;
        X12 = EMPTYLIST;
        X13 = EMPTYLIST;
L17209:
        if  ( NEQ( _S2CUINT( X10 ), _S2CUINT( EMPTYLIST ) ) )  goto L17210;
        X7 = X12;
        goto L17221;
L17210:
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L17213;
        scrt1__24__car_2derror( X10 );
L17213:
        X16 = PAIR_CAR( X10 );
        if  ( EQ( TSCPTAG( X11 ), PAIRTAG ) )  goto L17216;
        scrt1__24__car_2derror( X11 );
L17216:
        X17 = PAIR_CAR( X11 );
        X18 = qobischeme_strip_2dextension( X17 );
        X15 = detection_h_2dframes_d6c0ddee( PAIR_CAR( DISPLAY( 3 ) ), 
                                             X16, 
                                             X18, 
                                             PAIR_CAR( DISPLAY( 2 ) ), 
                                             PAIR_CAR( DISPLAY( 1 ) ) );
        X14 = sc_cons( X15, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X12 ), _S2CUINT( EMPTYLIST ) ) )  goto L17220;
        X15 = PAIR_CDR( X10 );
        X16 = PAIR_CDR( X11 );
        X13 = X14;
        X12 = X14;
        X11 = X16;
        X10 = X15;
        GOBACK( L17209 );
L17220:
        X15 = PAIR_CDR( X10 );
        X16 = PAIR_CDR( X11 );
        if  ( EQ( TSCPTAG( X13 ), PAIRTAG ) )  goto L17227;
        scdebug_error( c12316, 
                       c12317, CONS( X13, EMPTYLIST ) );
L17227:
        X13 = SETGEN( PAIR_CDR( X13 ), X14 );
        X11 = X16;
        X10 = X15;
        GOBACK( L17209 );
L17221:
        X8 = detection_2ddepth_2a_8800758e_v;
        if  ( BITAND( BITOR( _S2CINT( X8 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17231;
        X9 = _TSCP( IDIFFERENCE( _S2CINT( X8 ), 
                                 _S2CINT( _TSCP( 4 ) ) ) );
        goto L17232;
L17231:
        X9 = scrt2__2d_2dtwo( X8, _TSCP( 4 ) );
L17232:
        detection_2ddepth_2a_8800758e_v = X9;
        X6 = X7;
        DISPLAY( 4 ) = X1;
        DISPLAY( 5 ) = X2;
        DISPLAY( 1 ) = X3;
        DISPLAY( 2 ) = X4;
        DISPLAY( 3 ) = X5;
        POPSTACKTRACE( X6 );
}

EXTERNTSCPP( qobischeme_fifth, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_fifth_v );
EXTERNTSCPP( qobischeme_sixth, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_sixth_v );
EXTERNTSCPP( qobischeme_seventh, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_seventh_v );
EXTERNTSCPP( parser__2dobjects_dc2331e6, XAL2( TSCP, TSCP ) );
EXTERNTSCP( parser__2dobjects_dc2331e6_v );
EXTERNTSCPP( qobischeme_last, XAL1( TSCP ) );
EXTERNTSCP( qobischeme_last_v );
EXTERNTSCPP( nlib_2dsc_group_2dby_96ef2b55, 
             XAL2( TSCP, TSCP ) );
EXTERNTSCP( nlib_2dsc_group_2dby_96ef2b55_v );
EXTERNTSCPP( nlib_2dsc_of_2dlists_ff272f8f, XAL1( TSCP ) );
EXTERNTSCP( nlib_2dsc_of_2dlists_ff272f8f_v );
EXTERNTSCPP( codetectionlib_2dsc_median, XAL1( TSCP ) );
EXTERNTSCP( codetectionlib_2dsc_median_v );
EXTERNTSCPP( scrt2_max, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_max_v );

TSCP  codetection_l14262( __14263, c17750 )
        TSCP  __14263, c17750;
{
        PUSHSTACKTRACE( "codetection_l14262 [inside MAIN]" );
        POPSTACKTRACE( _TSCP( 0 ) );
}

EXTERNTSCP( asy_2dffi_2dfrom_2dc_a9bfaa5a_v );
EXTERNTSCPP( scrt4_vector, XAL1( TSCP ) );
EXTERNTSCP( scrt4_vector_v );
EXTERNTSCPP( qobischeme_rand, XAL0(  ) );
EXTERNTSCP( qobischeme_rand_v );
EXTERNTSCPP( scrt1__24__cdr_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__cdr_2derror_v );
EXTERNTSCPP( qobischeme_position, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_position_v );
EXTERNTSCPP( qobischeme_find_2dif, XAL2( TSCP, TSCP ) );
EXTERNTSCP( qobischeme_find_2dif_v );
EXTERNTSCPP( scrt1_member, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_member_v );

TSCP  codetection_l14050( g14051, c17788 )
        TSCP  g14051, c17788;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "codetection_l14050 [inside MAIN]" );
        X1 = DISPLAY( 6 );
        DISPLAY( 6 ) = CLOSURE_VAR( c17788, 0 );
        X3 = qobischeme_first( DISPLAY( 6 ) );
        X2 = scrt1_member( X3, g14051 );
        DISPLAY( 6 ) = X1;
        POPSTACKTRACE( X2 );
}

EXTERNTSCPP( dbindings_c_2dstring_a000da03, XAL1( TSCP ) );
EXTERNTSCP( dbindings_c_2dstring_a000da03_v );
EXTERNTSCPP( nlib_2dsc_ext_2ddraw_ec7a9cc9, 
             XAL6( TSCP, TSCP, TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( nlib_2dsc_ext_2ddraw_ec7a9cc9_v );
EXTERNTSCPP( codetectionlib_2dsc_drop, XAL2( TSCP, TSCP ) );
EXTERNTSCP( codetectionlib_2dsc_drop_v );
EXTERNTSCPP( codetectionlib_2dsc_hostname, XAL0(  ) );
EXTERNTSCP( codetectionlib_2dsc_hostname_v );

TSCP  codetection_l14190( __14191, c17833 )
        TSCP  __14191, c17833;
{
        PUSHSTACKTRACE( "codetection_l14190 [inside MAIN]" );
        POPSTACKTRACE( EMPTYLIST );
}

EXTERNTSCPP( qobischeme_list_2dreplace, 
             XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( qobischeme_list_2dreplace_v );
EXTERNTSCPP( nlib_2dsc__2ddecache_e023ee48, XAL1( TSCP ) );
EXTERNTSCP( nlib_2dsc__2ddecache_e023ee48_v );

TSCP  codetection_main( a13553 )
        TSCP  a13553;
{
        TSCP  X92, 
              X91, 
              X90, 
              X89, 
              X88, 
              X87, 
              X86, 
              X85, 
              X84, 
              X83, 
              X82, 
              X81, 
              X80, 
              X79, 
              X78, 
              X77, 
              X76, 
              X75, 
              X74, 
              X73, 
              X72, 
              X71, 
              X70, 
              X69, 
              X68, 
              X67, 
              X66, 
              X65, 
              X64, 
              X63, 
              X62, 
              X61, 
              X60, 
              X59, 
              X58, 
              X57, 
              X56, 
              X55, 
              X54, 
              X53, 
              X52, 
              X51, 
              X50, 
              X49, 
              X48, 
              X47, 
              X46, 
              X45, 
              X44, 
              X43, 
              X42, 
              X41, 
              X40, 
              X39, 
              X38, 
              X37, 
              X36, 
              X35, 
              X34, 
              X33, 
              X32, 
              X31, 
              X30, 
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
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SD3 = DISPLAY( 3 );
        TSCP  SD4 = DISPLAY( 4 );
        TSCP  SD5 = DISPLAY( 5 );
        TSCP  SD6 = DISPLAY( 6 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t16833 );
        a13553 = CONS( a13553, EMPTYLIST );
        DISPLAY( 0 ) = qobischeme_first( PAIR_CAR( a13553 ) );
        X1 = _TSCP( 0 );
        X1 = CONS( X1, EMPTYLIST );
        X2 = MAKEPROCEDURE( 0, 
                            0, 
                            codetection_u13607, 
                            MAKECLOSURE( EMPTYLIST, 
                                         1, DISPLAY( 0 ) ) );
        SETGEN( PAIR_CAR( X1 ), X2 );
        X2 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X2 );
        X2 = sc_emptystring;
        X3 = FALSEVALUE;
        X4 = FALSEVALUE;
        X5 = FALSEVALUE;
        X6 = FALSEVALUE;
        X7 = FALSEVALUE;
        X8 = FALSEVALUE;
        DISPLAY( 1 ) = FALSEVALUE;
        X9 = FALSEVALUE;
        X10 = FALSEVALUE;
        DISPLAY( 2 ) = FALSEVALUE;
        X11 = FALSEVALUE;
        X12 = _TSCP( 8 );
        X13 = FALSEVALUE;
        X14 = _TSCP( 4 );
        X15 = FALSEVALUE;
        X16 = _TSCP( 0 );
        X17 = FALSEVALUE;
        DISPLAY( 3 ) = _TSCP( 2000 );
        X18 = FALSEVALUE;
        X19 = _TSCP( 960 );
        X20 = FALSEVALUE;
        X21 = c13853;
        X22 = sc_emptystring;
        X23 = FALSEVALUE;
        X24 = sc_emptystring;
        X25 = sc_emptystring;
        X26 = FALSEVALUE;
        X27 = sc_emptystring;
        X28 = FALSEVALUE;
        X28 = CONS( X28, EMPTYLIST );
        X27 = CONS( X27, EMPTYLIST );
        X26 = CONS( X26, EMPTYLIST );
        X25 = CONS( X25, EMPTYLIST );
        X24 = CONS( X24, EMPTYLIST );
        X23 = CONS( X23, EMPTYLIST );
        X22 = CONS( X22, EMPTYLIST );
        X21 = CONS( X21, EMPTYLIST );
        X20 = CONS( X20, EMPTYLIST );
        X19 = CONS( X19, EMPTYLIST );
        X18 = CONS( X18, EMPTYLIST );
        DISPLAY( 3 ) = CONS( DISPLAY( 3 ), EMPTYLIST );
        X17 = CONS( X17, EMPTYLIST );
        X16 = CONS( X16, EMPTYLIST );
        X15 = CONS( X15, EMPTYLIST );
        X14 = CONS( X14, EMPTYLIST );
        X13 = CONS( X13, EMPTYLIST );
        X12 = CONS( X12, EMPTYLIST );
        X11 = CONS( X11, EMPTYLIST );
        DISPLAY( 2 ) = CONS( DISPLAY( 2 ), EMPTYLIST );
        X10 = CONS( X10, EMPTYLIST );
        X9 = CONS( X9, EMPTYLIST );
        DISPLAY( 1 ) = CONS( DISPLAY( 1 ), EMPTYLIST );
        X8 = CONS( X8, EMPTYLIST );
        X7 = CONS( X7, EMPTYLIST );
        X6 = CONS( X6, EMPTYLIST );
        X5 = CONS( X5, EMPTYLIST );
        X4 = CONS( X4, EMPTYLIST );
        X3 = CONS( X3, EMPTYLIST );
        X2 = CONS( X2, EMPTYLIST );
L16866:
        if  ( EQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                  _S2CUINT( EMPTYLIST ) ) )  goto L17053;
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13652 ) ) )  goto L16870;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        X29 = PAIR_CAR( X28 );
        if  ( TRUE( X29 ) )  goto L16877;
        X30 = PAIR_CAR( X26 );
        if  ( TRUE( X30 ) )  goto L16877;
        if  ( FALSE( PAIR_CAR( X23 ) ) )  goto L16885;
L16877:
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16885:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X28 ), X29 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L16886;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16886:
        X30 = qobischeme_first( PAIR_CAR( a13553 ) );
        X29 = codetection_s13557( X30, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X27 ), X29 );
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        GOBACK( L16866 );
L16870:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13653 ) ) )  goto L16888;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        X29 = PAIR_CAR( X28 );
        if  ( TRUE( X29 ) )  goto L16895;
        X30 = PAIR_CAR( X26 );
        if  ( TRUE( X30 ) )  goto L16895;
        if  ( FALSE( PAIR_CAR( X23 ) ) )  goto L16903;
L16895:
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16903:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X26 ), X29 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L16904;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16904:
        X30 = qobischeme_first( PAIR_CAR( a13553 ) );
        X29 = codetection_s13557( X30, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X25 ), X29 );
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L16906;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16906:
        X30 = qobischeme_first( PAIR_CAR( a13553 ) );
        X29 = codetection_s13557( X30, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X24 ), X29 );
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        GOBACK( L16866 );
L16888:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13654 ) ) )  goto L16908;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        X29 = PAIR_CAR( X28 );
        if  ( TRUE( X29 ) )  goto L16915;
        X30 = PAIR_CAR( X26 );
        if  ( TRUE( X30 ) )  goto L16915;
        if  ( FALSE( PAIR_CAR( X23 ) ) )  goto L16923;
L16915:
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16923:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X23 ), X29 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L16924;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16924:
        X30 = qobischeme_first( PAIR_CAR( a13553 ) );
        X29 = codetection_s13557( X30, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X22 ), X29 );
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L16926;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16926:
        X30 = qobischeme_first( PAIR_CAR( a13553 ) );
        X29 = codetection_s13557( X30, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X21 ), X29 );
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        GOBACK( L16866 );
L16908:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13655 ) ) )  goto L16928;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( X20 ) ) )  goto L16931;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16931:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X20 ), X29 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L16933;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16933:
        X30 = qobischeme_first( PAIR_CAR( a13553 ) );
        X29 = codetection_i13556( X30, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X19 ), X29 );
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        GOBACK( L16866 );
L16928:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13656 ) ) )  goto L16935;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( X18 ) ) )  goto L16938;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16938:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X18 ), X29 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L16940;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16940:
        X30 = qobischeme_first( PAIR_CAR( a13553 ) );
        X29 = codetection_i13556( X30, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( DISPLAY( 3 ) ), X29 );
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        GOBACK( L16866 );
L16935:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13657 ) ) )  goto L16942;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( X17 ) ) )  goto L16945;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16945:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X17 ), X29 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L16947;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16947:
        X30 = qobischeme_first( PAIR_CAR( a13553 ) );
        X29 = codetection_r13555( X30, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X16 ), X29 );
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        GOBACK( L16866 );
L16942:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13658 ) ) )  goto L16949;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( X15 ) ) )  goto L16952;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16952:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X15 ), X29 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L16954;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16954:
        X30 = qobischeme_first( PAIR_CAR( a13553 ) );
        X29 = codetection_r13555( X30, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X14 ), X29 );
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        GOBACK( L16866 );
L16949:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13659 ) ) )  goto L16956;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( X13 ) ) )  goto L16959;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16959:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X13 ), X29 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L16961;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16961:
        X30 = qobischeme_first( PAIR_CAR( a13553 ) );
        X29 = codetection_r13555( X30, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X12 ), X29 );
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        GOBACK( L16866 );
L16956:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13660 ) ) )  goto L16963;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( X11 ) ) )  goto L16966;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16966:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X11 ), X29 );
        GOBACK( L16866 );
L16963:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13661 ) ) )  goto L16968;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( DISPLAY( 2 ) ) ) )  goto L16971;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16971:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( DISPLAY( 2 ) ), X29 );
        GOBACK( L16866 );
L16968:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13662 ) ) )  goto L16973;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( X10 ) ) )  goto L16976;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16976:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X10 ), X29 );
        GOBACK( L16866 );
L16973:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13663 ) ) )  goto L16978;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( X9 ) ) )  goto L16981;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16981:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X9 ), X29 );
        GOBACK( L16866 );
L16978:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13664 ) ) )  goto L16983;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( DISPLAY( 1 ) ) ) )  goto L16986;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16986:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( DISPLAY( 1 ) ), X29 );
        GOBACK( L16866 );
L16983:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13665 ) ) )  goto L16988;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( X8 ) ) )  goto L16991;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16991:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X8 ), X29 );
        GOBACK( L16866 );
L16988:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13666 ) ) )  goto L16993;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( X7 ) ) )  goto L16996;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L16996:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X7 ), X29 );
        GOBACK( L16866 );
L16993:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13667 ) ) )  goto L16998;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        X29 = PAIR_CAR( X6 );
        if  ( TRUE( X29 ) )  goto L17005;
        X30 = PAIR_CAR( X5 );
        if  ( TRUE( X30 ) )  goto L17005;
        if  ( FALSE( PAIR_CAR( X4 ) ) )  goto L17013;
L17005:
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L17013:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X6 ), X29 );
        GOBACK( L16866 );
L16998:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13668 ) ) )  goto L17014;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        X29 = PAIR_CAR( X6 );
        if  ( TRUE( X29 ) )  goto L17021;
        X30 = PAIR_CAR( X5 );
        if  ( TRUE( X30 ) )  goto L17021;
        if  ( FALSE( PAIR_CAR( X4 ) ) )  goto L17029;
L17021:
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L17029:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X5 ), X29 );
        GOBACK( L16866 );
L17014:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13669 ) ) )  goto L17030;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        X29 = PAIR_CAR( X6 );
        if  ( TRUE( X29 ) )  goto L17037;
        X30 = PAIR_CAR( X5 );
        if  ( TRUE( X30 ) )  goto L17037;
        if  ( FALSE( PAIR_CAR( X4 ) ) )  goto L17045;
L17037:
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L17045:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X4 ), X29 );
        GOBACK( L16866 );
L17030:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13670 ) ) )  goto L17046;
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        if  ( FALSE( PAIR_CAR( X3 ) ) )  goto L17049;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L17049:
        X29 = TRUEVALUE;
        SETGEN( PAIR_CAR( X3 ), X29 );
        if  ( NEQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                   _S2CUINT( EMPTYLIST ) ) )  goto L17051;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L17051:
        X30 = qobischeme_first( PAIR_CAR( a13553 ) );
        X29 = codetection_s13557( X30, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X2 ), X29 );
        X29 = qobischeme_rest( PAIR_CAR( a13553 ) );
        SETGEN( PAIR_CAR( a13553 ), X29 );
        GOBACK( L16866 );
L17046:
        X29 = qobischeme_first( PAIR_CAR( a13553 ) );
        if  ( FALSE( scrt3_string_3d_3f( X29, c13671 ) ) )  goto L17053;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L17053:
        if  ( TRUE( PAIR_CAR( X28 ) ) )  goto L17059;
        if  ( TRUE( PAIR_CAR( X26 ) ) )  goto L17059;
        if  ( TRUE( PAIR_CAR( X23 ) ) )  goto L17059;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L17059:
        if  ( TRUE( PAIR_CAR( X6 ) ) )  goto L17065;
        if  ( TRUE( PAIR_CAR( X5 ) ) )  goto L17065;
        if  ( TRUE( PAIR_CAR( X4 ) ) )  goto L17065;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L17065:
        if  ( EQ( _S2CUINT( PAIR_CAR( a13553 ) ), 
                  _S2CUINT( EMPTYLIST ) ) )  goto L17067;
        codetection_u13607( PROCEDURE_CLOSURE( PAIR_CAR( X1 ) ) );
L17067:
        if  ( FALSE( PAIR_CAR( X9 ) ) )  goto L17069;
        X29 = _TSCP( 4 );
        goto L17070;
L17069:
        X29 = _TSCP( 16 );
L17070:
        detection_tations_2a_bae473a_v = X29;
        X29 = detection_tations_2a_bae473a_v;
        set_n_orientations( sc_tscp_int( X29 ) );
        detection_hard_3f_2a_5334b1c_v = PAIR_CAR( X8 );
        detection_ideo_3f_2a_99b8f220_v = PAIR_CAR( X28 );
        scrt6_newline( EMPTYLIST );
        X29 = CONS( PAIR_CAR( X7 ), EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13820, X29 ) );
        X29 = CONS( PAIR_CAR( DISPLAY( 3 ) ), EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13821, X29 ) );
        X29 = CONS( PAIR_CAR( X19 ), EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13822, X29 ) );
        X29 = CONS( PAIR_CAR( X14 ), EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13823, X29 ) );
        X29 = CONS( PAIR_CAR( X16 ), EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13824, X29 ) );
        X29 = CONS( PAIR_CAR( X12 ), EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13825, X29 ) );
        if  ( FALSE( PAIR_CAR( X6 ) ) )  goto L17073;
        X30 = c13829;
        goto L17076;
L17073:
        if  ( FALSE( PAIR_CAR( X5 ) ) )  goto L17075;
        X30 = c13828;
        goto L17076;
L17075:
        X30 = c13827;
L17076:
        X29 = CONS( X30, EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13826, X29 ) );
        if  ( FALSE( PAIR_CAR( X11 ) ) )  goto L17077;
        X30 = FALSEVALUE;
        goto L17078;
L17077:
        X30 = TRUEVALUE;
L17078:
        X29 = CONS( X30, EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13830, X29 ) );
        X29 = CONS( PAIR_CAR( DISPLAY( 2 ) ), EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13831, X29 ) );
        X29 = CONS( PAIR_CAR( X10 ), EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13832, X29 ) );
        X29 = CONS( PAIR_CAR( DISPLAY( 1 ) ), EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13833, X29 ) );
        X29 = CONS( PAIR_CAR( X8 ), EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13834, X29 ) );
        if  ( FALSE( PAIR_CAR( X9 ) ) )  goto L17079;
        X30 = FALSEVALUE;
        goto L17080;
L17079:
        X30 = TRUEVALUE;
L17080:
        X29 = CONS( X30, EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13835, X29 ) );
        X29 = CONS( PAIR_CAR( X2 ), EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c13836, X29 ) );
        scrt6_newline( EMPTYLIST );
        if  ( FALSE( PAIR_CAR( X11 ) ) )  goto L17081;
        X29 = _TSCP( 0 );
        goto L17082;
L17081:
        X29 = _TSCP( 4 );
L17082:
        set_track_constraint( sc_tscp_int( X29 ) );
        if  ( FALSE( PAIR_CAR( X6 ) ) )  goto L17085;
        X29 = _TSCP( 0 );
        goto L17088;
L17085:
        if  ( FALSE( PAIR_CAR( X5 ) ) )  goto L17087;
        X29 = _TSCP( 4 );
        goto L17088;
L17087:
        X29 = _TSCP( 8 );
L17088:
        set_sentence_directed( sc_tscp_int( X29 ) );
        X29 = PAIR_CAR( X12 );
        set_gamma( TSCP_DOUBLE( X29 ) );
        if  ( FALSE( scrt1_equal_3f( PAIR_CAR( X21 ), c13852 ) )
            )  goto L17093;
        X29 = _TSCP( 4 );
        goto L17096;
L17093:
        if  ( FALSE( scrt1_equal_3f( PAIR_CAR( X21 ), c13853 ) )
            )  goto L17095;
        X29 = _TSCP( 8 );
        goto L17096;
L17095:
        X29 = qobischeme_panic( c13854, EMPTYLIST );
L17096:
        SETGEN( PAIR_CAR( X21 ), X29 );
        if  ( FALSE( PAIR_CAR( X28 ) ) )  goto L17097;
        X32 = CONS( EMPTYLIST, EMPTYLIST );
        X32 = CONS( sc_emptystring, X32 );
        X31 = scrt1_cons_2a( PAIR_CAR( X27 ), 
                             CONS( sc_emptystring, X32 ) );
        X30 = scrt1_cons_2a( X31, 
                             CONS( EMPTYLIST, EMPTYLIST ) );
        goto L17119;
L17097:
        if  ( FALSE( PAIR_CAR( X26 ) ) )  goto L17099;
        X32 = CONS( EMPTYLIST, EMPTYLIST );
        X32 = CONS( sc_emptystring, X32 );
        X31 = scrt1_cons_2a( PAIR_CAR( X25 ), 
                             CONS( sc_emptystring, X32 ) );
        X32 = CONS( EMPTYLIST, EMPTYLIST );
        X33 = CONS( EMPTYLIST, EMPTYLIST );
        X33 = CONS( sc_emptystring, X33 );
        X30 = scrt1_cons_2a( X31, 
                             CONS( scrt1_cons_2a( PAIR_CAR( X24 ), 
                                                  CONS( sc_emptystring, 
                                                        X33 ) ), 
                                   X32 ) );
        goto L17119;
L17099:
        X32 = pregexp_pregexp_2dsplit( c15865, PAIR_CAR( X22 ) );
        X31 = qobischeme_first( X32 );
        X33 = pregexp_pregexp_2dsplit( c15865, PAIR_CAR( X22 ) );
        X32 = qobischeme_second( X33 );
        X34 = pregexp_pregexp_2dsplit( c15864, X32 );
        X33 = qobischeme_first( X34 );
        X35 = pregexp_pregexp_2dsplit( c15864, X32 );
        X34 = qobischeme_second( X35 );
        X37 = CONS( X33, EMPTYLIST );
        X37 = CONS( X31, X37 );
        X37 = CONS( c15863, X37 );
        X36 = scrt6_format( FALSEVALUE, CONS( c15862, X37 ) );
        X35 = obischeme_rom_2dfile_92544bb1( X36 );
        if  ( FALSE( scrt3_string_3d_3f( X31, c15815 ) ) )  goto L17106;
        X36 = parser__2aobjects_2dhouse_2a_v;
        goto L17107;
L17106:
        X36 = parser__2aobjects_2dcad_2a_v;
L17107:
        codetection__2aobjects_2a_v = X36;
        X38 = CONS( X34, EMPTYLIST );
        X38 = CONS( X31, X38 );
        X38 = CONS( c15863, X38 );
        X37 = scrt6_format( FALSEVALUE, CONS( c15861, X38 ) );
        X36 = qobischeme_read_2dfile( X37 );
        X37 = X36;
        X38 = EMPTYLIST;
        X39 = EMPTYLIST;
L17110:
        if  ( NEQ( _S2CUINT( X37 ), _S2CUINT( EMPTYLIST ) ) )  goto L17111;
        X30 = X38;
        goto L17119;
L17111:
        if  ( EQ( TSCPTAG( X37 ), PAIRTAG ) )  goto L17114;
        scrt1__24__car_2derror( X37 );
L17114:
        X42 = PAIR_CAR( X37 );
        X44 = CONS( X42, EMPTYLIST );
        X44 = CONS( X31, X44 );
        X43 = scrt6_format( FALSEVALUE, CONS( c15860, X44 ) );
        X41 = scrt1_assoc( X43, X35 );
        X40 = sc_cons( X41, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X38 ), _S2CUINT( EMPTYLIST ) ) )  goto L17118;
        X41 = PAIR_CDR( X37 );
        X39 = X40;
        X38 = X40;
        X37 = X41;
        GOBACK( L17110 );
L17118:
        X41 = PAIR_CDR( X37 );
        if  ( EQ( TSCPTAG( X39 ), PAIRTAG ) )  goto L17123;
        scdebug_error( c12316, 
                       c12317, CONS( X39, EMPTYLIST ) );
L17123:
        X39 = SETGEN( PAIR_CDR( X39 ), X40 );
        X37 = X41;
        GOBACK( L17110 );
L17119:
        X29 = qobischeme_sort( X30, 
                               scrt3_string_3c_3f_v, 
                               qobischeme_first_v );
        scrt6_format( TRUEVALUE, CONS( c15802, EMPTYLIST ) );
        scrt6_pp( X29, EMPTYLIST );
        X30 = scrt6_newline( EMPTYLIST );
        X31 = X29;
        X32 = EMPTYLIST;
        X33 = EMPTYLIST;
L17130:
        if  ( NEQ( _S2CUINT( X31 ), _S2CUINT( EMPTYLIST ) ) )  goto L17131;
        DISPLAY( 4 ) = X32;
        goto L17138;
L17131:
        if  ( EQ( TSCPTAG( X31 ), PAIRTAG ) )  goto L17134;
        scrt1__24__car_2derror( X31 );
L17134:
        X36 = PAIR_CAR( X31 );
        X35 = qobischeme_first( X36 );
        X34 = sc_cons( X35, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X32 ), _S2CUINT( EMPTYLIST ) ) )  goto L17137;
        X35 = PAIR_CDR( X31 );
        X33 = X34;
        X32 = X34;
        X31 = X35;
        GOBACK( L17130 );
L17137:
        X35 = PAIR_CDR( X31 );
        if  ( EQ( TSCPTAG( X33 ), PAIRTAG ) )  goto L17142;
        scdebug_error( c12316, 
                       c12317, CONS( X33, EMPTYLIST ) );
L17142:
        X33 = SETGEN( PAIR_CDR( X33 ), X34 );
        X31 = X35;
        GOBACK( L17130 );
L17138:
        X32 = X29;
        X33 = EMPTYLIST;
        X34 = EMPTYLIST;
L17147:
        if  ( NEQ( _S2CUINT( X32 ), _S2CUINT( EMPTYLIST ) ) )  goto L17148;
        X31 = X33;
        goto L17155;
L17148:
        if  ( EQ( TSCPTAG( X32 ), PAIRTAG ) )  goto L17151;
        scrt1__24__car_2derror( X32 );
L17151:
        X37 = PAIR_CAR( X32 );
        X36 = qobischeme_second( X37 );
        X35 = sc_cons( X36, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X33 ), _S2CUINT( EMPTYLIST ) ) )  goto L17154;
        X36 = PAIR_CDR( X32 );
        X34 = X35;
        X33 = X35;
        X32 = X36;
        GOBACK( L17147 );
L17154:
        X36 = PAIR_CDR( X32 );
        if  ( EQ( TSCPTAG( X34 ), PAIRTAG ) )  goto L17159;
        scdebug_error( c12316, 
                       c12317, CONS( X34, EMPTYLIST ) );
L17159:
        X34 = SETGEN( PAIR_CDR( X34 ), X35 );
        X32 = X36;
        GOBACK( L17147 );
L17155:
        X33 = X29;
        X34 = EMPTYLIST;
        X35 = EMPTYLIST;
L17164:
        if  ( NEQ( _S2CUINT( X33 ), _S2CUINT( EMPTYLIST ) ) )  goto L17165;
        X32 = X34;
        goto L17172;
L17165:
        if  ( EQ( TSCPTAG( X33 ), PAIRTAG ) )  goto L17168;
        scrt1__24__car_2derror( X33 );
L17168:
        X38 = PAIR_CAR( X33 );
        X37 = qobischeme_third( X38 );
        X36 = sc_cons( X37, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X34 ), _S2CUINT( EMPTYLIST ) ) )  goto L17171;
        X37 = PAIR_CDR( X33 );
        X35 = X36;
        X34 = X36;
        X33 = X37;
        GOBACK( L17164 );
L17171:
        X37 = PAIR_CDR( X33 );
        if  ( EQ( TSCPTAG( X35 ), PAIRTAG ) )  goto L17176;
        scdebug_error( c12316, 
                       c12317, CONS( X35, EMPTYLIST ) );
L17176:
        X35 = SETGEN( PAIR_CDR( X35 ), X36 );
        X33 = X37;
        GOBACK( L17164 );
L17172:
        X33 = DISPLAY( 4 );
        X34 = X33;
        X35 = EMPTYLIST;
        X36 = EMPTYLIST;
L17181:
        if  ( NEQ( _S2CUINT( X34 ), _S2CUINT( EMPTYLIST ) ) )  goto L17182;
        DISPLAY( 5 ) = X35;
        goto L17189;
L17182:
        if  ( EQ( TSCPTAG( X34 ), PAIRTAG ) )  goto L17185;
        scrt1__24__car_2derror( X34 );
L17185:
        X39 = PAIR_CAR( X34 );
        X38 = codetection_video_2d_3eframes( X39 );
        X37 = sc_cons( X38, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X35 ), _S2CUINT( EMPTYLIST ) ) )  goto L17188;
        X38 = PAIR_CDR( X34 );
        X36 = X37;
        X35 = X37;
        X34 = X38;
        GOBACK( L17181 );
L17188:
        X38 = PAIR_CDR( X34 );
        if  ( EQ( TSCPTAG( X36 ), PAIRTAG ) )  goto L17193;
        scdebug_error( c12316, 
                       c12317, CONS( X36, EMPTYLIST ) );
L17193:
        X36 = SETGEN( PAIR_CDR( X36 ), X37 );
        X34 = X38;
        GOBACK( L17181 );
L17189:
        X35 = qobischeme_first( DISPLAY( 5 ) );
        X34 = qobischeme_first( X35 );
        X36 = nlib_2dsc_b_3aheight_cb673bff( X34 );
        X35 = scrt2_exact_2d_3einexact( X36 );
        X37 = nlib_2dsc_ib_3awidth_c7d91eee( X34 );
        X36 = scrt2_exact_2d_3einexact( X37 );
        set_imw( TSCP_DOUBLE( X36 ) );
        set_imh( TSCP_DOUBLE( X35 ) );
        X33 = FALSEVALUE;
        X36 = CONS( c15539, EMPTYLIST );
        X36 = CONS( sc_make_2dstring( detection_2ddepth_2a_8800758e_v, 
                                      CONS( _TSCP( 11026 ), EMPTYLIST ) ), 
                    X36 );
        X35 = scrt6_format( FALSEVALUE, CONS( c15537, X36 ) );
        X36 = MAKEPROCEDURE( 0, 
                             0, 
                             codetection_l15540, 
                             MAKECLOSURE( EMPTYLIST, 
                                          5, 
                                          DISPLAY( 4 ), 
                                          DISPLAY( 5 ), 
                                          DISPLAY( 1 ), 
                                          DISPLAY( 2 ), 
                                          DISPLAY( 3 ) ) );
        X34 = codetection_time_2dthunk( X35, X36 );
        if  ( TRUE( PAIR_CAR( X7 ) ) )  goto L17234;
        X36 = DISPLAY( 5 );
        X37 = DISPLAY( 4 );
        X38 = X34;
        X39 = X36;
        X40 = X37;
        X41 = EMPTYLIST;
        X42 = EMPTYLIST;
L17238:
        if  ( NEQ( _S2CUINT( X38 ), _S2CUINT( EMPTYLIST ) ) )  goto L17239;
        X35 = X41;
        goto L17252;
L17239:
        if  ( EQ( TSCPTAG( X38 ), PAIRTAG ) )  goto L17242;
        scrt1__24__car_2derror( X38 );
L17242:
        X45 = PAIR_CAR( X38 );
        if  ( EQ( TSCPTAG( X39 ), PAIRTAG ) )  goto L17245;
        scrt1__24__car_2derror( X39 );
L17245:
        X46 = PAIR_CAR( X39 );
        if  ( EQ( TSCPTAG( X40 ), PAIRTAG ) )  goto L17248;
        scrt1__24__car_2derror( X40 );
L17248:
        X47 = PAIR_CAR( X40 );
        X44 = detection_2dtracking_1add9051( X45, 
                                             X46, 
                                             PAIR_CAR( DISPLAY( 3 ) ), 
                                             PAIR_CAR( X19 ), 
                                             X47, 
                                             PAIR_CAR( X10 ) );
        X43 = sc_cons( X44, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X41 ), _S2CUINT( EMPTYLIST ) ) )  goto L17251;
        X44 = PAIR_CDR( X38 );
        X45 = PAIR_CDR( X39 );
        X46 = PAIR_CDR( X40 );
        X42 = X43;
        X41 = X43;
        X40 = X46;
        X39 = X45;
        X38 = X44;
        GOBACK( L17238 );
L17251:
        X44 = PAIR_CDR( X38 );
        X45 = PAIR_CDR( X39 );
        X46 = PAIR_CDR( X40 );
        if  ( EQ( TSCPTAG( X42 ), PAIRTAG ) )  goto L17260;
        scdebug_error( c12316, 
                       c12317, CONS( X42, EMPTYLIST ) );
L17260:
        X42 = SETGEN( PAIR_CDR( X42 ), X43 );
        X40 = X46;
        X39 = X45;
        X38 = X44;
        GOBACK( L17238 );
L17252:
        if  ( FALSE( PAIR_CAR( X26 ) ) )  goto L17263;
        X38 = DISPLAY( 4 );
        X39 = X38;
        X40 = EMPTYLIST;
        X41 = EMPTYLIST;
L17268:
        if  ( NEQ( _S2CUINT( X39 ), _S2CUINT( EMPTYLIST ) ) )  goto L17269;
        X37 = X40;
        goto L17276;
L17269:
        if  ( EQ( TSCPTAG( X39 ), PAIRTAG ) )  goto L17272;
        scrt1__24__car_2derror( X39 );
L17272:
        X44 = PAIR_CAR( X39 );
        X43 = qobischeme_strip_2dextension( X44 );
        X42 = sc_cons( X43, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X40 ), _S2CUINT( EMPTYLIST ) ) )  goto L17275;
        X43 = PAIR_CDR( X39 );
        X41 = X42;
        X40 = X42;
        X39 = X43;
        GOBACK( L17268 );
L17275:
        X43 = PAIR_CDR( X39 );
        if  ( EQ( TSCPTAG( X41 ), PAIRTAG ) )  goto L17280;
        scdebug_error( c12316, 
                       c12317, CONS( X41, EMPTYLIST ) );
L17280:
        X41 = SETGEN( PAIR_CDR( X41 ), X42 );
        X39 = X43;
        GOBACK( L17268 );
L17276:
        detection_g_2dvideos_bd193643( DISPLAY( 5 ), 
                                       X35, 
                                       X37, 
                                       detection_mes_2dn_2a_f0f9bc16_v, 
                                       PAIR_CAR( X19 ), 
                                       PAIR_CAR( X21 ) );
        X37 = screp_exit_v;
        X37 = UNKNOWNCALL( X37, 0 );
        X36 = VIA( PROCEDURE_CODE( X37 ) )( PROCEDURE_CLOSURE( X37 ) );
        goto L17264;
L17263:
        X36 = FALSEVALUE;
L17264:
        X38 = X35;
        X39 = EMPTYLIST;
        X40 = EMPTYLIST;
L17284:
        if  ( NEQ( _S2CUINT( X38 ), _S2CUINT( EMPTYLIST ) ) )  goto L17285;
        X37 = X39;
        goto L17328;
L17285:
        if  ( EQ( TSCPTAG( X38 ), PAIRTAG ) )  goto L17288;
        scrt1__24__car_2derror( X38 );
L17288:
        X43 = PAIR_CAR( X38 );
        X44 = X43;
        X45 = EMPTYLIST;
        X46 = EMPTYLIST;
L17292:
        if  ( NEQ( _S2CUINT( X44 ), _S2CUINT( EMPTYLIST ) ) )  goto L17293;
        X42 = X45;
        goto L17320;
L17293:
        if  ( EQ( TSCPTAG( X44 ), PAIRTAG ) )  goto L17296;
        scrt1__24__car_2derror( X44 );
L17296:
        X49 = PAIR_CAR( X44 );
        X50 = X49;
        X51 = EMPTYLIST;
        X52 = EMPTYLIST;
L17300:
        if  ( NEQ( _S2CUINT( X50 ), _S2CUINT( EMPTYLIST ) ) )  goto L17301;
        X48 = X51;
        goto L17312;
L17301:
        if  ( EQ( TSCPTAG( X50 ), PAIRTAG ) )  goto L17304;
        scrt1__24__car_2derror( X50 );
L17304:
        X55 = PAIR_CAR( X50 );
        X56 = PAIR_CAR( X14 );
        X57 = qobischeme_fifth( X55 );
        if  ( BITAND( BITOR( _S2CINT( X56 ), 
                             _S2CINT( X57 ) ), 
                      3 ) )  goto L17308;
        X54 = _TSCP( ITIMES( FIXED_C( X56 ), 
                             _S2CINT( X57 ) ) );
        goto L17309;
L17308:
        X54 = scrt2__2a_2dtwo( X56, X57 );
L17309:
        X53 = sc_cons( X54, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X51 ), _S2CUINT( EMPTYLIST ) ) )  goto L17311;
        X54 = PAIR_CDR( X50 );
        X52 = X53;
        X51 = X53;
        X50 = X54;
        GOBACK( L17300 );
L17311:
        X54 = PAIR_CDR( X50 );
        if  ( EQ( TSCPTAG( X52 ), PAIRTAG ) )  goto L17316;
        scdebug_error( c12316, 
                       c12317, CONS( X52, EMPTYLIST ) );
L17316:
        X52 = SETGEN( PAIR_CDR( X52 ), X53 );
        X50 = X54;
        GOBACK( L17300 );
L17312:
        X47 = sc_cons( X48, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X45 ), _S2CUINT( EMPTYLIST ) ) )  goto L17319;
        X48 = PAIR_CDR( X44 );
        X46 = X47;
        X45 = X47;
        X44 = X48;
        GOBACK( L17292 );
L17319:
        X48 = PAIR_CDR( X44 );
        if  ( EQ( TSCPTAG( X46 ), PAIRTAG ) )  goto L17324;
        scdebug_error( c12316, 
                       c12317, CONS( X46, EMPTYLIST ) );
L17324:
        X46 = SETGEN( PAIR_CDR( X46 ), X47 );
        X44 = X48;
        GOBACK( L17292 );
L17320:
        X41 = sc_cons( X42, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X39 ), _S2CUINT( EMPTYLIST ) ) )  goto L17327;
        X42 = PAIR_CDR( X38 );
        X40 = X41;
        X39 = X41;
        X38 = X42;
        GOBACK( L17284 );
L17327:
        X42 = PAIR_CDR( X38 );
        if  ( EQ( TSCPTAG( X40 ), PAIRTAG ) )  goto L17332;
        scdebug_error( c12316, 
                       c12317, CONS( X40, EMPTYLIST ) );
L17332:
        X40 = SETGEN( PAIR_CDR( X40 ), X41 );
        X38 = X42;
        GOBACK( L17284 );
L17328:
        X39 = X35;
        X40 = EMPTYLIST;
        X41 = EMPTYLIST;
L17336:
        if  ( NEQ( _S2CUINT( X39 ), _S2CUINT( EMPTYLIST ) ) )  goto L17337;
        X38 = X40;
        goto L17377;
L17337:
        if  ( EQ( TSCPTAG( X39 ), PAIRTAG ) )  goto L17340;
        scrt1__24__car_2derror( X39 );
L17340:
        X44 = PAIR_CAR( X39 );
        X45 = X44;
        X46 = EMPTYLIST;
        X47 = EMPTYLIST;
L17344:
        if  ( NEQ( _S2CUINT( X45 ), _S2CUINT( EMPTYLIST ) ) )  goto L17345;
        X43 = X46;
        goto L17369;
L17345:
        if  ( EQ( TSCPTAG( X45 ), PAIRTAG ) )  goto L17348;
        scrt1__24__car_2derror( X45 );
L17348:
        X50 = PAIR_CAR( X45 );
        X51 = X50;
        X52 = EMPTYLIST;
        X53 = EMPTYLIST;
L17353:
        if  ( NEQ( _S2CUINT( X51 ), _S2CUINT( EMPTYLIST ) ) )  goto L17354;
        X49 = X52;
        goto L17361;
L17354:
        if  ( EQ( TSCPTAG( X51 ), PAIRTAG ) )  goto L17357;
        scrt1__24__car_2derror( X51 );
L17357:
        X56 = PAIR_CAR( X51 );
        X55 = qobischeme_sixth( X56 );
        X54 = sc_cons( X55, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X52 ), _S2CUINT( EMPTYLIST ) ) )  goto L17360;
        X55 = PAIR_CDR( X51 );
        X53 = X54;
        X52 = X54;
        X51 = X55;
        GOBACK( L17353 );
L17360:
        X55 = PAIR_CDR( X51 );
        if  ( EQ( TSCPTAG( X53 ), PAIRTAG ) )  goto L17365;
        scdebug_error( c12316, 
                       c12317, CONS( X53, EMPTYLIST ) );
L17365:
        X53 = SETGEN( PAIR_CDR( X53 ), X54 );
        X51 = X55;
        GOBACK( L17353 );
L17361:
        X48 = sc_cons( X49, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X46 ), _S2CUINT( EMPTYLIST ) ) )  goto L17368;
        X49 = PAIR_CDR( X45 );
        X47 = X48;
        X46 = X48;
        X45 = X49;
        GOBACK( L17344 );
L17368:
        X49 = PAIR_CDR( X45 );
        if  ( EQ( TSCPTAG( X47 ), PAIRTAG ) )  goto L17373;
        scdebug_error( c12316, 
                       c12317, CONS( X47, EMPTYLIST ) );
L17373:
        X47 = SETGEN( PAIR_CDR( X47 ), X48 );
        X45 = X49;
        GOBACK( L17344 );
L17369:
        X42 = sc_cons( X43, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X40 ), _S2CUINT( EMPTYLIST ) ) )  goto L17376;
        X43 = PAIR_CDR( X39 );
        X41 = X42;
        X40 = X42;
        X39 = X43;
        GOBACK( L17336 );
L17376:
        X43 = PAIR_CDR( X39 );
        if  ( EQ( TSCPTAG( X41 ), PAIRTAG ) )  goto L17381;
        scdebug_error( c12316, 
                       c12317, CONS( X41, EMPTYLIST ) );
L17381:
        X41 = SETGEN( PAIR_CDR( X41 ), X42 );
        X39 = X43;
        GOBACK( L17336 );
L17377:
        X40 = X35;
        X41 = EMPTYLIST;
        X42 = EMPTYLIST;
L17385:
        if  ( NEQ( _S2CUINT( X40 ), _S2CUINT( EMPTYLIST ) ) )  goto L17386;
        X39 = X41;
        goto L17426;
L17386:
        if  ( EQ( TSCPTAG( X40 ), PAIRTAG ) )  goto L17389;
        scrt1__24__car_2derror( X40 );
L17389:
        X45 = PAIR_CAR( X40 );
        X46 = X45;
        X47 = EMPTYLIST;
        X48 = EMPTYLIST;
L17393:
        if  ( NEQ( _S2CUINT( X46 ), _S2CUINT( EMPTYLIST ) ) )  goto L17394;
        X44 = X47;
        goto L17418;
L17394:
        if  ( EQ( TSCPTAG( X46 ), PAIRTAG ) )  goto L17397;
        scrt1__24__car_2derror( X46 );
L17397:
        X51 = PAIR_CAR( X46 );
        X52 = X51;
        X53 = EMPTYLIST;
        X54 = EMPTYLIST;
L17402:
        if  ( NEQ( _S2CUINT( X52 ), _S2CUINT( EMPTYLIST ) ) )  goto L17403;
        X50 = X53;
        goto L17410;
L17403:
        if  ( EQ( TSCPTAG( X52 ), PAIRTAG ) )  goto L17406;
        scrt1__24__car_2derror( X52 );
L17406:
        X57 = PAIR_CAR( X52 );
        X56 = qobischeme_seventh( X57 );
        X55 = sc_cons( X56, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X53 ), _S2CUINT( EMPTYLIST ) ) )  goto L17409;
        X56 = PAIR_CDR( X52 );
        X54 = X55;
        X53 = X55;
        X52 = X56;
        GOBACK( L17402 );
L17409:
        X56 = PAIR_CDR( X52 );
        if  ( EQ( TSCPTAG( X54 ), PAIRTAG ) )  goto L17414;
        scdebug_error( c12316, 
                       c12317, CONS( X54, EMPTYLIST ) );
L17414:
        X54 = SETGEN( PAIR_CDR( X54 ), X55 );
        X52 = X56;
        GOBACK( L17402 );
L17410:
        X49 = sc_cons( X50, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X47 ), _S2CUINT( EMPTYLIST ) ) )  goto L17417;
        X50 = PAIR_CDR( X46 );
        X48 = X49;
        X47 = X49;
        X46 = X50;
        GOBACK( L17393 );
L17417:
        X50 = PAIR_CDR( X46 );
        if  ( EQ( TSCPTAG( X48 ), PAIRTAG ) )  goto L17422;
        scdebug_error( c12316, 
                       c12317, CONS( X48, EMPTYLIST ) );
L17422:
        X48 = SETGEN( PAIR_CDR( X48 ), X49 );
        X46 = X50;
        GOBACK( L17393 );
L17418:
        X43 = sc_cons( X44, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X41 ), _S2CUINT( EMPTYLIST ) ) )  goto L17425;
        X44 = PAIR_CDR( X40 );
        X42 = X43;
        X41 = X43;
        X40 = X44;
        GOBACK( L17385 );
L17425:
        X44 = PAIR_CDR( X40 );
        if  ( EQ( TSCPTAG( X42 ), PAIRTAG ) )  goto L17430;
        scdebug_error( c12316, 
                       c12317, CONS( X42, EMPTYLIST ) );
L17430:
        X42 = SETGEN( PAIR_CDR( X42 ), X43 );
        X40 = X44;
        GOBACK( L17385 );
L17426:
        X41 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X41 = UNKNOWNCALL( X41, 2 );
        X40 = VIA( PROCEDURE_CODE( X41 ) )( _TSCP( 12 ), 
                                            X37, 
                                            PROCEDURE_CLOSURE( X41 ) );
        X42 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X42 = UNKNOWNCALL( X42, 2 );
        X41 = VIA( PROCEDURE_CODE( X42 ) )( _TSCP( 12 ), 
                                            X38, 
                                            PROCEDURE_CLOSURE( X42 ) );
        X43 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X43 = UNKNOWNCALL( X43, 2 );
        X42 = VIA( PROCEDURE_CODE( X43 ) )( _TSCP( 12 ), 
                                            X39, 
                                            PROCEDURE_CLOSURE( X43 ) );
        X44 = X37;
        X45 = EMPTYLIST;
        X46 = EMPTYLIST;
L17438:
        if  ( NEQ( _S2CUINT( X44 ), _S2CUINT( EMPTYLIST ) ) )  goto L17439;
        X43 = X45;
        goto L17446;
L17439:
        if  ( EQ( TSCPTAG( X44 ), PAIRTAG ) )  goto L17442;
        scrt1__24__car_2derror( X44 );
L17442:
        X49 = PAIR_CAR( X44 );
        X48 = scrt1_length( X49 );
        X47 = sc_cons( X48, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X45 ), _S2CUINT( EMPTYLIST ) ) )  goto L17445;
        X48 = PAIR_CDR( X44 );
        X46 = X47;
        X45 = X47;
        X44 = X48;
        GOBACK( L17438 );
L17445:
        X48 = PAIR_CDR( X44 );
        if  ( EQ( TSCPTAG( X46 ), PAIRTAG ) )  goto L17450;
        scdebug_error( c12316, 
                       c12317, CONS( X46, EMPTYLIST ) );
L17450:
        X46 = SETGEN( PAIR_CDR( X46 ), X47 );
        X44 = X48;
        GOBACK( L17438 );
L17446:
        X45 = asy_2dffi_t_2dto_2dc_d3906c33_v;
        X45 = UNKNOWNCALL( X45, 2 );
        X44 = VIA( PROCEDURE_CODE( X45 ) )( _TSCP( 4 ), 
                                            X43, 
                                            PROCEDURE_CLOSURE( X45 ) );
        X45 = parser__2dobjects_dc2331e6( X31, 
                                          codetection__2aobjects_2a_v );
        X47 = CONS( X45, EMPTYLIST );
        X46 = scrt6_format( TRUEVALUE, CONS( c14977, X47 ) );
        X47 = qobischeme_first( X45 );
        X48 = qobischeme_second( X45 );
        X50 = X48;
        X51 = EMPTYLIST;
        X52 = EMPTYLIST;
L17460:
        if  ( NEQ( _S2CUINT( X50 ), _S2CUINT( EMPTYLIST ) ) )  goto L17461;
        X49 = X51;
        goto L17468;
L17461:
        if  ( EQ( TSCPTAG( X50 ), PAIRTAG ) )  goto L17464;
        scrt1__24__car_2derror( X50 );
L17464:
        X55 = PAIR_CAR( X50 );
        X54 = qobischeme_last( X55 );
        X53 = sc_cons( X54, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X51 ), _S2CUINT( EMPTYLIST ) ) )  goto L17467;
        X54 = PAIR_CDR( X50 );
        X52 = X53;
        X51 = X53;
        X50 = X54;
        GOBACK( L17460 );
L17467:
        X54 = PAIR_CDR( X50 );
        if  ( EQ( TSCPTAG( X52 ), PAIRTAG ) )  goto L17472;
        scdebug_error( c12316, 
                       c12317, CONS( X52, EMPTYLIST ) );
L17472:
        X52 = SETGEN( PAIR_CDR( X52 ), X53 );
        X50 = X54;
        GOBACK( L17460 );
L17468:
        X51 = nlib_2dsc_group_2dby_96ef2b55( qobischeme_second_v, X48 );
        X52 = X51;
        X53 = EMPTYLIST;
        X54 = EMPTYLIST;
L17477:
        if  ( NEQ( _S2CUINT( X52 ), _S2CUINT( EMPTYLIST ) ) )  goto L17478;
        X50 = X53;
        goto L17503;
L17478:
        if  ( EQ( TSCPTAG( X52 ), PAIRTAG ) )  goto L17481;
        scrt1__24__car_2derror( X52 );
L17481:
        X57 = PAIR_CAR( X52 );
        X58 = X57;
        X59 = EMPTYLIST;
        X60 = EMPTYLIST;
L17485:
        if  ( NEQ( _S2CUINT( X58 ), _S2CUINT( EMPTYLIST ) ) )  goto L17486;
        X56 = X59;
        goto L17495;
L17486:
        if  ( EQ( TSCPTAG( X58 ), PAIRTAG ) )  goto L17489;
        scrt1__24__car_2derror( X58 );
L17489:
        X63 = PAIR_CAR( X58 );
        X65 = qobischeme_first( X63 );
        X67 = qobischeme_third( X63 );
        X66 = sc_cons( X67, EMPTYLIST );
        X64 = sc_cons( X65, X66 );
        X62 = X64;
        X61 = sc_cons( X62, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X59 ), _S2CUINT( EMPTYLIST ) ) )  goto L17494;
        X62 = PAIR_CDR( X58 );
        X60 = X61;
        X59 = X61;
        X58 = X62;
        GOBACK( L17485 );
L17494:
        X62 = PAIR_CDR( X58 );
        if  ( EQ( TSCPTAG( X60 ), PAIRTAG ) )  goto L17499;
        scdebug_error( c12316, 
                       c12317, CONS( X60, EMPTYLIST ) );
L17499:
        X60 = SETGEN( PAIR_CDR( X60 ), X61 );
        X58 = X62;
        GOBACK( L17485 );
L17495:
        X55 = sc_cons( X56, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X53 ), _S2CUINT( EMPTYLIST ) ) )  goto L17502;
        X56 = PAIR_CDR( X52 );
        X54 = X55;
        X53 = X55;
        X52 = X56;
        GOBACK( L17477 );
L17502:
        X56 = PAIR_CDR( X52 );
        if  ( EQ( TSCPTAG( X54 ), PAIRTAG ) )  goto L17507;
        scdebug_error( c12316, 
                       c12317, CONS( X54, EMPTYLIST ) );
L17507:
        X54 = SETGEN( PAIR_CDR( X54 ), X55 );
        X52 = X56;
        GOBACK( L17477 );
L17503:
        X52 = X50;
        X53 = EMPTYLIST;
        X54 = EMPTYLIST;
L17512:
        if  ( NEQ( _S2CUINT( X52 ), _S2CUINT( EMPTYLIST ) ) )  goto L17513;
        X51 = X53;
        goto L17520;
L17513:
        if  ( EQ( TSCPTAG( X52 ), PAIRTAG ) )  goto L17516;
        scrt1__24__car_2derror( X52 );
L17516:
        X57 = PAIR_CAR( X52 );
        X56 = scrt1_length( X57 );
        X55 = sc_cons( X56, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X53 ), _S2CUINT( EMPTYLIST ) ) )  goto L17519;
        X56 = PAIR_CDR( X52 );
        X54 = X55;
        X53 = X55;
        X52 = X56;
        GOBACK( L17512 );
L17519:
        X56 = PAIR_CDR( X52 );
        if  ( EQ( TSCPTAG( X54 ), PAIRTAG ) )  goto L17524;
        scdebug_error( c12316, 
                       c12317, CONS( X54, EMPTYLIST ) );
L17524:
        X54 = SETGEN( PAIR_CDR( X54 ), X55 );
        X52 = X56;
        GOBACK( L17512 );
L17520:
        X53 = X50;
        X54 = EMPTYLIST;
        X55 = EMPTYLIST;
L17528:
        if  ( NEQ( _S2CUINT( X53 ), _S2CUINT( EMPTYLIST ) ) )  goto L17529;
        X52 = X54;
        goto L17585;
L17529:
        if  ( EQ( TSCPTAG( X53 ), PAIRTAG ) )  goto L17532;
        scrt1__24__car_2derror( X53 );
L17532:
        X58 = PAIR_CAR( X53 );
        X60 = X58;
        X61 = EMPTYLIST;
        X62 = EMPTYLIST;
L17536:
        if  ( NEQ( _S2CUINT( X60 ), _S2CUINT( EMPTYLIST ) ) )  goto L17537;
        X59 = X61;
        goto L17545;
L17537:
        if  ( EQ( TSCPTAG( X60 ), PAIRTAG ) )  goto L17540;
        scrt1__24__car_2derror( X60 );
L17540:
        X65 = PAIR_CAR( X60 );
        X66 = qobischeme_second( X65 );
        X64 = scrt1_list_2dref( DISPLAY( 5 ), X66 );
        X63 = sc_cons( X64, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X61 ), _S2CUINT( EMPTYLIST ) ) )  goto L17544;
        X64 = PAIR_CDR( X60 );
        X62 = X63;
        X61 = X63;
        X60 = X64;
        GOBACK( L17536 );
L17544:
        X64 = PAIR_CDR( X60 );
        if  ( EQ( TSCPTAG( X62 ), PAIRTAG ) )  goto L17549;
        scdebug_error( c12316, 
                       c12317, CONS( X62, EMPTYLIST ) );
L17549:
        X62 = SETGEN( PAIR_CDR( X62 ), X63 );
        X60 = X64;
        GOBACK( L17536 );
L17545:
        X61 = X58;
        X62 = EMPTYLIST;
        X63 = EMPTYLIST;
L17552:
        if  ( NEQ( _S2CUINT( X61 ), _S2CUINT( EMPTYLIST ) ) )  goto L17553;
        X60 = X62;
        goto L17561;
L17553:
        if  ( EQ( TSCPTAG( X61 ), PAIRTAG ) )  goto L17556;
        scrt1__24__car_2derror( X61 );
L17556:
        X66 = PAIR_CAR( X61 );
        X67 = qobischeme_second( X66 );
        X65 = scrt1_list_2dref( X35, X67 );
        X64 = sc_cons( X65, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X62 ), _S2CUINT( EMPTYLIST ) ) )  goto L17560;
        X65 = PAIR_CDR( X61 );
        X63 = X64;
        X62 = X64;
        X61 = X65;
        GOBACK( L17552 );
L17560:
        X65 = PAIR_CDR( X61 );
        if  ( EQ( TSCPTAG( X63 ), PAIRTAG ) )  goto L17565;
        scdebug_error( c12316, 
                       c12317, CONS( X63, EMPTYLIST ) );
L17565:
        X63 = SETGEN( PAIR_CDR( X63 ), X64 );
        X61 = X65;
        GOBACK( L17552 );
L17561:
        X62 = X58;
        X63 = EMPTYLIST;
        X64 = EMPTYLIST;
L17568:
        if  ( NEQ( _S2CUINT( X62 ), _S2CUINT( EMPTYLIST ) ) )  goto L17569;
        X61 = X63;
        goto L17577;
L17569:
        if  ( EQ( TSCPTAG( X62 ), PAIRTAG ) )  goto L17572;
        scrt1__24__car_2derror( X62 );
L17572:
        X67 = PAIR_CAR( X62 );
        X69 = qobischeme_second( X67 );
        X68 = scrt1_list_2dref( DISPLAY( 4 ), X69 );
        X66 = qobischeme_strip_2dextension( X68 );
        X65 = sc_cons( X66, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X63 ), _S2CUINT( EMPTYLIST ) ) )  goto L17576;
        X66 = PAIR_CDR( X62 );
        X64 = X65;
        X63 = X65;
        X62 = X66;
        GOBACK( L17568 );
L17576:
        X66 = PAIR_CDR( X62 );
        if  ( EQ( TSCPTAG( X64 ), PAIRTAG ) )  goto L17581;
        scdebug_error( c12316, 
                       c12317, CONS( X64, EMPTYLIST ) );
L17581:
        X64 = SETGEN( PAIR_CDR( X64 ), X65 );
        X62 = X66;
        GOBACK( L17568 );
L17577:
        X57 = detection_g_2dvideos_bd193643( X59, 
                                             X60, 
                                             X61, 
                                             detection_mes_2dn_2a_f0f9bc16_v, 
                                             PAIR_CAR( X19 ), 
                                             PAIR_CAR( X21 ) );
        X56 = sc_cons( X57, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X54 ), _S2CUINT( EMPTYLIST ) ) )  goto L17584;
        X57 = PAIR_CDR( X53 );
        X55 = X56;
        X54 = X56;
        X53 = X57;
        GOBACK( L17528 );
L17584:
        X57 = PAIR_CDR( X53 );
        if  ( EQ( TSCPTAG( X55 ), PAIRTAG ) )  goto L17589;
        scdebug_error( c12316, 
                       c12317, CONS( X55, EMPTYLIST ) );
L17589:
        X55 = SETGEN( PAIR_CDR( X55 ), X56 );
        X53 = X57;
        GOBACK( L17528 );
L17585:
        X54 = X52;
        X55 = EMPTYLIST;
        X56 = EMPTYLIST;
L17593:
        if  ( NEQ( _S2CUINT( X54 ), _S2CUINT( EMPTYLIST ) ) )  goto L17594;
        X53 = X55;
        goto L17602;
L17594:
        if  ( EQ( TSCPTAG( X54 ), PAIRTAG ) )  goto L17597;
        scrt1__24__car_2derror( X54 );
L17597:
        X59 = PAIR_CAR( X54 );
        X60 = qobischeme_first( X59 );
        X58 = scrt1_length( X60 );
        X57 = sc_cons( X58, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X55 ), _S2CUINT( EMPTYLIST ) ) )  goto L17601;
        X58 = PAIR_CDR( X54 );
        X56 = X57;
        X55 = X57;
        X54 = X58;
        GOBACK( L17593 );
L17601:
        X58 = PAIR_CDR( X54 );
        if  ( EQ( TSCPTAG( X56 ), PAIRTAG ) )  goto L17606;
        scdebug_error( c12316, 
                       c12317, CONS( X56, EMPTYLIST ) );
L17606:
        X56 = SETGEN( PAIR_CDR( X56 ), X57 );
        X54 = X58;
        GOBACK( L17593 );
L17602:
        X55 = X52;
        X56 = X53;
        X57 = X51;
        X58 = EMPTYLIST;
        X59 = EMPTYLIST;
L17610:
        if  ( NEQ( _S2CUINT( X55 ), _S2CUINT( EMPTYLIST ) ) )  goto L17611;
        X54 = X58;
        goto L17673;
L17611:
        if  ( EQ( TSCPTAG( X55 ), PAIRTAG ) )  goto L17614;
        scrt1__24__car_2derror( X55 );
L17614:
        X62 = PAIR_CAR( X55 );
        if  ( EQ( TSCPTAG( X56 ), PAIRTAG ) )  goto L17617;
        scrt1__24__car_2derror( X56 );
L17617:
        X63 = PAIR_CAR( X56 );
        if  ( EQ( TSCPTAG( X57 ), PAIRTAG ) )  goto L17620;
        scrt1__24__car_2derror( X57 );
L17620:
        X64 = PAIR_CAR( X57 );
        X65 = qobischeme_first( X62 );
        X66 = X65;
        X67 = EMPTYLIST;
        X68 = EMPTYLIST;
L17625:
        if  ( NEQ( _S2CUINT( X66 ), _S2CUINT( EMPTYLIST ) ) )  goto L17626;
        X61 = X67;
        goto L17665;
L17626:
        if  ( EQ( TSCPTAG( X66 ), PAIRTAG ) )  goto L17629;
        scrt1__24__car_2derror( X66 );
L17629:
        X71 = PAIR_CAR( X66 );
        X72 = X71;
        X73 = EMPTYLIST;
        X74 = EMPTYLIST;
L17633:
        if  ( NEQ( _S2CUINT( X72 ), _S2CUINT( EMPTYLIST ) ) )  goto L17634;
        X70 = X73;
        goto L17657;
L17634:
        if  ( EQ( TSCPTAG( X72 ), PAIRTAG ) )  goto L17637;
        scrt1__24__car_2derror( X72 );
L17637:
        X77 = PAIR_CAR( X72 );
        X80 = PAIR_CAR( X12 );
        X82 = BOOLEAN( NOT( BITAND( BITOR( _S2CINT( X64 ), 
                                           _S2CINT( X63 ) ), 
                                    3 ) ) );
        if  ( FALSE( X82 ) )  goto L17650;
        if  ( EQ( _S2CUINT( X63 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L17650;
        X83 = _TSCP( REMAINDER( _S2CINT( X64 ), 
                                _S2CINT( X63 ) ) );
        if  ( NEQ( _S2CUINT( X83 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L17650;
        X81 = C_FIXED( QUOTIENT( _S2CINT( X64 ), 
                                 _S2CINT( X63 ) ) );
        goto L17651;
L17650:
        X81 = scrt2__2f_2dtwo( X64, X63 );
L17651:
        if  ( BITAND( BITOR( _S2CINT( X80 ), 
                             _S2CINT( X81 ) ), 
                      3 ) )  goto L17653;
        X79 = _TSCP( ITIMES( FIXED_C( X80 ), 
                             _S2CINT( X81 ) ) );
        goto L17654;
L17653:
        X79 = scrt2__2a_2dtwo( X80, X81 );
L17654:
        X78 = qobischeme_k_2am( X79, X77 );
        X76 = nlib_2dsc_of_2dlists_ff272f8f( X78 );
        X75 = sc_cons( X76, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X73 ), _S2CUINT( EMPTYLIST ) ) )  goto L17656;
        X76 = PAIR_CDR( X72 );
        X74 = X75;
        X73 = X75;
        X72 = X76;
        GOBACK( L17633 );
L17656:
        X76 = PAIR_CDR( X72 );
        if  ( EQ( TSCPTAG( X74 ), PAIRTAG ) )  goto L17661;
        scdebug_error( c12316, 
                       c12317, CONS( X74, EMPTYLIST ) );
L17661:
        X74 = SETGEN( PAIR_CDR( X74 ), X75 );
        X72 = X76;
        GOBACK( L17633 );
L17657:
        X69 = sc_cons( X70, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X67 ), _S2CUINT( EMPTYLIST ) ) )  goto L17664;
        X70 = PAIR_CDR( X66 );
        X68 = X69;
        X67 = X69;
        X66 = X70;
        GOBACK( L17625 );
L17664:
        X70 = PAIR_CDR( X66 );
        if  ( EQ( TSCPTAG( X68 ), PAIRTAG ) )  goto L17669;
        scdebug_error( c12316, 
                       c12317, CONS( X68, EMPTYLIST ) );
L17669:
        X68 = SETGEN( PAIR_CDR( X68 ), X69 );
        X66 = X70;
        GOBACK( L17625 );
L17665:
        X60 = sc_cons( X61, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X58 ), _S2CUINT( EMPTYLIST ) ) )  goto L17672;
        X61 = PAIR_CDR( X55 );
        X62 = PAIR_CDR( X56 );
        X63 = PAIR_CDR( X57 );
        X59 = X60;
        X58 = X60;
        X57 = X63;
        X56 = X62;
        X55 = X61;
        GOBACK( L17610 );
L17672:
        X61 = PAIR_CDR( X55 );
        X62 = PAIR_CDR( X56 );
        X63 = PAIR_CDR( X57 );
        if  ( EQ( TSCPTAG( X59 ), PAIRTAG ) )  goto L17681;
        scdebug_error( c12316, 
                       c12317, CONS( X59, EMPTYLIST ) );
L17681:
        X59 = SETGEN( PAIR_CDR( X59 ), X60 );
        X57 = X63;
        X56 = X62;
        X55 = X61;
        GOBACK( L17610 );
L17673:
        X58 = codetectionlib_2dsc_join( X39 );
        X57 = codetectionlib_2dsc_join( X58 );
        X56 = CONS( sc_apply_2dtwo( scrt2_min_v, X57 ), 
                    EMPTYLIST );
        X58 = codetectionlib_2dsc_join( X39 );
        X57 = codetectionlib_2dsc_join( X58 );
        X56 = CONS( codetectionlib_2dsc_median( X57 ), X56 );
        X58 = codetectionlib_2dsc_join( X39 );
        X57 = codetectionlib_2dsc_join( X58 );
        X56 = CONS( sc_apply_2dtwo( scrt2_max_v, X57 ), X56 );
        X58 = codetectionlib_2dsc_join( X38 );
        X57 = codetectionlib_2dsc_join( X58 );
        X56 = CONS( sc_apply_2dtwo( scrt2_min_v, X57 ), X56 );
        X58 = codetectionlib_2dsc_join( X38 );
        X57 = codetectionlib_2dsc_join( X58 );
        X56 = CONS( codetectionlib_2dsc_median( X57 ), X56 );
        X58 = codetectionlib_2dsc_join( X38 );
        X57 = codetectionlib_2dsc_join( X58 );
        X56 = CONS( sc_apply_2dtwo( scrt2_max_v, X57 ), X56 );
        X58 = codetectionlib_2dsc_join( X37 );
        X57 = codetectionlib_2dsc_join( X58 );
        X56 = CONS( sc_apply_2dtwo( scrt2_min_v, X57 ), X56 );
        X58 = codetectionlib_2dsc_join( X37 );
        X57 = codetectionlib_2dsc_join( X58 );
        X56 = CONS( codetectionlib_2dsc_median( X57 ), X56 );
        X58 = codetectionlib_2dsc_join( X37 );
        X57 = codetectionlib_2dsc_join( X58 );
        X56 = CONS( sc_apply_2dtwo( scrt2_max_v, X57 ), X56 );
        X55 = scrt6_format( TRUEVALUE, CONS( c14392, X56 ) );
        X57 = X52;
        X58 = EMPTYLIST;
        X59 = EMPTYLIST;
L17687:
        if  ( NEQ( _S2CUINT( X57 ), _S2CUINT( EMPTYLIST ) ) )  goto L17688;
        X56 = X58;
        goto L17695;
L17688:
        if  ( EQ( TSCPTAG( X57 ), PAIRTAG ) )  goto L17691;
        scrt1__24__car_2derror( X57 );
L17691:
        X62 = PAIR_CAR( X57 );
        X61 = qobischeme_third( X62 );
        X60 = sc_cons( X61, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X58 ), _S2CUINT( EMPTYLIST ) ) )  goto L17694;
        X61 = PAIR_CDR( X57 );
        X59 = X60;
        X58 = X60;
        X57 = X61;
        GOBACK( L17687 );
L17694:
        X61 = PAIR_CDR( X57 );
        if  ( EQ( TSCPTAG( X59 ), PAIRTAG ) )  goto L17699;
        scdebug_error( c12316, 
                       c12317, CONS( X59, EMPTYLIST ) );
L17699:
        X59 = SETGEN( PAIR_CDR( X59 ), X60 );
        X57 = X61;
        GOBACK( L17687 );
L17695:
        X58 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X58 = UNKNOWNCALL( X58, 2 );
        X57 = VIA( PROCEDURE_CODE( X58 ) )( _TSCP( 20 ), 
                                            X54, 
                                            PROCEDURE_CLOSURE( X58 ) );
        X59 = asy_2dffi_t_2dto_2dc_d3906c33_v;
        X59 = UNKNOWNCALL( X59, 2 );
        X58 = VIA( PROCEDURE_CODE( X59 ) )( _TSCP( 4 ), 
                                            X53, 
                                            PROCEDURE_CLOSURE( X59 ) );
        X60 = asy_2dffi_t_2dto_2dc_d3906c33_v;
        X60 = UNKNOWNCALL( X60, 2 );
        X59 = VIA( PROCEDURE_CODE( X60 ) )( _TSCP( 4 ), 
                                            X51, 
                                            PROCEDURE_CLOSURE( X60 ) );
        X61 = asy_2dffi_t_2dto_2dc_d3906c33_v;
        X61 = UNKNOWNCALL( X61, 2 );
        X60 = VIA( PROCEDURE_CODE( X61 ) )( _TSCP( 4 ), 
                                            X49, 
                                            PROCEDURE_CLOSURE( X61 ) );
        X62 = asy_2dffi_t_2dto_2dc_d3906c33_v;
        X62 = UNKNOWNCALL( X62, 2 );
        X61 = VIA( PROCEDURE_CODE( X62 ) )( _TSCP( 4 ), 
                                            X56, 
                                            PROCEDURE_CLOSURE( X62 ) );
        X63 = asy_2dffi_t_2dto_2dc_d3906c33_v;
        X63 = UNKNOWNCALL( X63, 2 );
        X62 = VIA( PROCEDURE_CODE( X63 ) )( _TSCP( 8 ), 
                                            X47, 
                                            PROCEDURE_CLOSURE( X63 ) );
        X64 = X50;
        X65 = EMPTYLIST;
        X66 = EMPTYLIST;
L17709:
        if  ( NEQ( _S2CUINT( X64 ), _S2CUINT( EMPTYLIST ) ) )  goto L17710;
        X63 = X65;
        goto L17734;
L17710:
        if  ( EQ( TSCPTAG( X64 ), PAIRTAG ) )  goto L17713;
        scrt1__24__car_2derror( X64 );
L17713:
        X69 = PAIR_CAR( X64 );
        X70 = X69;
        X71 = EMPTYLIST;
        X72 = EMPTYLIST;
L17718:
        if  ( NEQ( _S2CUINT( X70 ), _S2CUINT( EMPTYLIST ) ) )  goto L17719;
        X68 = X71;
        goto L17726;
L17719:
        if  ( EQ( TSCPTAG( X70 ), PAIRTAG ) )  goto L17722;
        scrt1__24__car_2derror( X70 );
L17722:
        X75 = PAIR_CAR( X70 );
        X74 = qobischeme_first( X75 );
        X73 = sc_cons( X74, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X71 ), _S2CUINT( EMPTYLIST ) ) )  goto L17725;
        X74 = PAIR_CDR( X70 );
        X72 = X73;
        X71 = X73;
        X70 = X74;
        GOBACK( L17718 );
L17725:
        X74 = PAIR_CDR( X70 );
        if  ( EQ( TSCPTAG( X72 ), PAIRTAG ) )  goto L17730;
        scdebug_error( c12316, 
                       c12317, CONS( X72, EMPTYLIST ) );
L17730:
        X72 = SETGEN( PAIR_CDR( X72 ), X73 );
        X70 = X74;
        GOBACK( L17718 );
L17726:
        X67 = sc_cons( X68, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X65 ), _S2CUINT( EMPTYLIST ) ) )  goto L17733;
        X68 = PAIR_CDR( X64 );
        X66 = X67;
        X65 = X67;
        X64 = X68;
        GOBACK( L17709 );
L17733:
        X68 = PAIR_CDR( X64 );
        if  ( EQ( TSCPTAG( X66 ), PAIRTAG ) )  goto L17738;
        scdebug_error( c12316, 
                       c12317, CONS( X66, EMPTYLIST ) );
L17738:
        X66 = SETGEN( PAIR_CDR( X66 ), X67 );
        X64 = X68;
        GOBACK( L17709 );
L17734:
        X65 = asy_2dffi_t_2dto_2dc_d3906c33_v;
        X65 = UNKNOWNCALL( X65, 2 );
        X64 = VIA( PROCEDURE_CODE( X65 ) )( _TSCP( 8 ), 
                                            X63, 
                                            PROCEDURE_CLOSURE( X65 ) );
        X67 = X48;
        X68 = EMPTYLIST;
        X69 = EMPTYLIST;
L17743:
        if  ( NEQ( _S2CUINT( X67 ), _S2CUINT( EMPTYLIST ) ) )  goto L17744;
        X66 = X68;
        goto L17754;
L17744:
        if  ( EQ( TSCPTAG( X67 ), PAIRTAG ) )  goto L17747;
        scrt1__24__car_2derror( X67 );
L17747:
        X72 = PAIR_CAR( X67 );
        X73 = MAKEPROCEDURE( 0, 
                             1, codetection_l14262, EMPTYLIST );
        X75 = qobischeme_last( X72 );
        X74 = scrt1_list_2dref( X43, X75 );
        X71 = qobischeme_map_2dn( X73, X74 );
        X70 = sc_cons( X71, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X68 ), _S2CUINT( EMPTYLIST ) ) )  goto L17753;
        X71 = PAIR_CDR( X67 );
        X69 = X70;
        X68 = X70;
        X67 = X71;
        GOBACK( L17743 );
L17753:
        X71 = PAIR_CDR( X67 );
        if  ( EQ( TSCPTAG( X69 ), PAIRTAG ) )  goto L17758;
        scdebug_error( c12316, 
                       c12317, CONS( X69, EMPTYLIST ) );
L17758:
        X69 = SETGEN( PAIR_CDR( X69 ), X70 );
        X67 = X71;
        GOBACK( L17743 );
L17754:
        X65 = codetectionlib_2dsc_join( X66 );
        X67 = asy_2dffi_t_2dto_2dc_d3906c33_v;
        X67 = UNKNOWNCALL( X67, 2 );
        X66 = VIA( PROCEDURE_CODE( X67 ) )( _TSCP( 4 ), 
                                            X65, 
                                            PROCEDURE_CLOSURE( X67 ) );
        X68 = asy_2dffi_e_2dto_2dc_6e7b37fb_v;
        X68 = UNKNOWNCALL( X68, 2 );
        X67 = VIA( PROCEDURE_CODE( X68 ) )( _TSCP( 16 ), 
                                            X35, 
                                            PROCEDURE_CLOSURE( X68 ) );
        X69 = scrt1_length( X63 );
        X70 = scrt1_length( X47 );
        X68 = detection_dinference_299999ac( X40, 
                                             X41, 
                                             X42, 
                                             X67, 
                                             X57, 
                                             X69, 
                                             X44, 
                                             X58, 
                                             X61, 
                                             X62, 
                                             X70, 
                                             X60, 
                                             X64, 
                                             X59, 
                                             PAIR_CAR( X21 ), 
                                             PAIR_CAR( X19 ), 
                                             X66 );
        X73 = scrt1_length( X65 );
        X72 = sc_cons( X73, EMPTYLIST );
        X71 = X72;
        X70 = asy_2dffi_2dfrom_2dc_a9bfaa5a_v;
        X70 = UNKNOWNCALL( X70, 3 );
        X69 = VIA( PROCEDURE_CODE( X70 ) )( X71, 
                                            c14217, 
                                            X66, 
                                            PROCEDURE_CLOSURE( X70 ) );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 12 ), X37, X40 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 12 ), X38, X41 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 12 ), X39, X42 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 4 ), X69, X66 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 4 ), X43, X44 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 20 ), X54, X57 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 4 ), X53, X58 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 4 ), X51, X59 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 4 ), X49, X60 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 4 ), X56, X61 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 16 ), X35, X67 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 8 ), X47, X62 );
        easy_2dffi_easy_2dffi_3afree( _TSCP( 8 ), X63, X64 );
        X71 = X63;
        X72 = EMPTYLIST;
        X73 = EMPTYLIST;
L17767:
        if  ( NEQ( _S2CUINT( X71 ), _S2CUINT( EMPTYLIST ) ) )  goto L17768;
        X70 = X72;
        goto L17772;
L17768:
        X77 = qobischeme_rand(  );
        X76 = CONS( scrt2_modulo( X77, _TSCP( 1024 ) ), 
                    EMPTYLIST );
        X77 = qobischeme_rand(  );
        X76 = CONS( scrt2_modulo( X77, _TSCP( 1024 ) ), X76 );
        X77 = qobischeme_rand(  );
        X75 = scrt4_vector( CONS( scrt2_modulo( X77, _TSCP( 1024 ) ), 
                                  X76 ) );
        X74 = sc_cons( X75, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X72 ), _S2CUINT( EMPTYLIST ) ) )  goto L17771;
        if  ( EQ( TSCPTAG( X71 ), PAIRTAG ) )  goto L17774;
        scrt1__24__cdr_2derror( X71 );
L17774:
        X75 = PAIR_CDR( X71 );
        X73 = X74;
        X72 = X74;
        X71 = X75;
        GOBACK( L17767 );
L17771:
        if  ( EQ( TSCPTAG( X71 ), PAIRTAG ) )  goto L17777;
        scrt1__24__cdr_2derror( X71 );
L17777:
        X75 = PAIR_CDR( X71 );
        if  ( EQ( TSCPTAG( X73 ), PAIRTAG ) )  goto L17780;
        scdebug_error( c12316, 
                       c12317, CONS( X73, EMPTYLIST ) );
L17780:
        X73 = SETGEN( PAIR_CDR( X73 ), X74 );
        X71 = X75;
        GOBACK( L17767 );
L17772:
        X71 = X48;
        X72 = X69;
L17784:
        if  ( EQ( _S2CUINT( X71 ), _S2CUINT( EMPTYLIST ) ) )  goto L17785;
        DISPLAY( 6 ) = qobischeme_first( X71 );
        X75 = MAKEPROCEDURE( 1, 
                             0, 
                             codetection_l14050, 
                             MAKECLOSURE( EMPTYLIST, 
                                          1, DISPLAY( 6 ) ) );
        X74 = qobischeme_find_2dif( X75, X63 );
        X73 = qobischeme_position( X74, X63 );
        X74 = qobischeme_third( DISPLAY( 6 ) );
        X75 = scrt1_list_2dref( X70, X73 );
        X77 = qobischeme_second( DISPLAY( 6 ) );
        X76 = dbindings_c_2dstring_a000da03( X77 );
        X77 = scrt1_list_2dref( DISPLAY( 5 ), X74 );
        X78 = scrt1_list_2dref( X35, X74 );
        X80 = scrt1_list_2dref( X43, X74 );
        X79 = codetectionlib_2dsc_take( X80, X72 );
        X80 = X77;
        X81 = X78;
        X82 = X79;
L17796:
        if  ( EQ( _S2CUINT( X80 ), _S2CUINT( EMPTYLIST ) ) )  goto L17797;
        if  ( EQ( TSCPTAG( X80 ), PAIRTAG ) )  goto L17801;
        scrt1__24__car_2derror( X80 );
L17801:
        X83 = PAIR_CAR( X80 );
        if  ( EQ( TSCPTAG( X81 ), PAIRTAG ) )  goto L17804;
        scrt1__24__car_2derror( X81 );
L17804:
        X84 = PAIR_CAR( X81 );
        if  ( EQ( TSCPTAG( X82 ), PAIRTAG ) )  goto L17807;
        scrt1__24__car_2derror( X82 );
L17807:
        X85 = PAIR_CAR( X82 );
        X86 = scrt1_list_2dref( X84, X85 );
        X87 = qobischeme_first( X86 );
        X88 = qobischeme_second( X86 );
        X91 = qobischeme_third( X86 );
        if  ( BITAND( BITOR( _S2CINT( X91 ), 
                             _S2CINT( X87 ) ), 
                      3 ) )  goto L17814;
        X90 = _TSCP( IDIFFERENCE( _S2CINT( X91 ), 
                                  _S2CINT( X87 ) ) );
        goto L17815;
L17814:
        X90 = scrt2__2d_2dtwo( X91, X87 );
L17815:
        if  ( BITAND( BITOR( _S2CINT( X90 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17817;
        X89 = _TSCP( IPLUS( _S2CINT( X90 ), 
                            _S2CINT( _TSCP( 4 ) ) ) );
        goto L17818;
L17817:
        X89 = scrt2__2b_2dtwo( X90, _TSCP( 4 ) );
L17818:
        X92 = qobischeme_fourth( X86 );
        if  ( BITAND( BITOR( _S2CINT( X92 ), 
                             _S2CINT( X88 ) ), 
                      3 ) )  goto L17822;
        X91 = _TSCP( IDIFFERENCE( _S2CINT( X92 ), 
                                  _S2CINT( X88 ) ) );
        goto L17823;
L17822:
        X91 = scrt2__2d_2dtwo( X92, X88 );
L17823:
        if  ( BITAND( BITOR( _S2CINT( X91 ), 
                             _S2CINT( _TSCP( 4 ) ) ), 
                      3 ) )  goto L17825;
        X90 = _TSCP( IPLUS( _S2CINT( X91 ), 
                            _S2CINT( _TSCP( 4 ) ) ) );
        goto L17826;
L17825:
        X90 = scrt2__2b_2dtwo( X91, _TSCP( 4 ) );
L17826:
        nlib_2dsc_drectangle_8a5856a3( X83, 
                                       X87, 
                                       X88, 
                                       X89, 
                                       X90, X75, _TSCP( 12 ) );
        nlib_2dsc_ext_2ddraw_ec7a9cc9( X83, 
                                       X87, 
                                       X88, 
                                       X76, X75, _TSCP( 60 ) );
        X91 = scrt1_list_2dref( DISPLAY( 4 ), X74 );
        X90 = qobischeme_strip_2ddirectory( X91 );
        nlib_2dsc_ext_2ddraw_ec7a9cc9( X83, 
                                       _TSCP( 40 ), 
                                       _TSCP( 40 ), 
                                       X90, c12369, _TSCP( 40 ) );
        X90 = scrt1_list_2dref( X32, X74 );
        nlib_2dsc_ext_2ddraw_ec7a9cc9( X83, 
                                       _TSCP( 40 ), 
                                       _TSCP( 120 ), 
                                       X90, c12369, _TSCP( 40 ) );
        X83 = PAIR_CDR( X80 );
        X84 = PAIR_CDR( X81 );
        X82 = PAIR_CDR( X82 );
        X81 = X84;
        X80 = X83;
        GOBACK( L17796 );
L17797:
        X77 = qobischeme_rest( X71 );
        X78 = scrt1_list_2dref( X43, X74 );
        X72 = codetectionlib_2dsc_drop( X78, X72 );
        X71 = X77;
        GOBACK( L17784 );
L17785:
        if  ( FALSE( PAIR_CAR( X3 ) ) )  goto L17830;
        X71 = CONS( PAIR_CAR( X14 ), EMPTYLIST );
        X71 = CONS( PAIR_CAR( X12 ), X71 );
        X71 = CONS( qobischeme_getpid(  ), X71 );
        X71 = CONS( codetectionlib_2dsc_hostname(  ), X71 );
        X71 = CONS( PAIR_CAR( X2 ), X71 );
        X70 = scrt6_format( FALSEVALUE, CONS( c14193, X71 ) );
        goto L17831;
L17830:
        X70 = c12143;
L17831:
        X72 = CONS( X70, EMPTYLIST );
        X71 = scrt6_format( FALSEVALUE, CONS( c14099, X72 ) );
        scrt4_system( X71 );
        scrt6_format( TRUEVALUE, CONS( c14100, EMPTYLIST ) );
        X71 = codetectionlib_2dsc_join( DISPLAY( 5 ) );
        X73 = CONS( X70, EMPTYLIST );
        X72 = scrt6_format( FALSEVALUE, CONS( c14101, X73 ) );
        codetection_frames_2d_3evideo( X71, X72, _TSCP( 4 ) );
        scrt6_format( TRUEVALUE, CONS( c14102, EMPTYLIST ) );
        X73 = MAKEPROCEDURE( 0, 
                             1, codetection_l14190, EMPTYLIST );
        X74 = scrt1_length( DISPLAY( 5 ) );
        X72 = qobischeme_map_2dn( X73, X74 );
        X73 = X48;
        X74 = X69;
        X75 = X72;
L17837:
        if  ( NEQ( _S2CUINT( X73 ), _S2CUINT( EMPTYLIST ) ) )  goto L17838;
        X71 = X75;
        goto L17839;
L17838:
        X76 = qobischeme_first( X73 );
        X77 = qobischeme_third( X76 );
        X78 = qobischeme_second( X76 );
        X80 = scrt1_list_2dref( X35, X77 );
        X82 = scrt1_list_2dref( X43, X77 );
        X81 = codetectionlib_2dsc_take( X82, X74 );
        X82 = X80;
        X83 = X81;
        X84 = EMPTYLIST;
        X85 = EMPTYLIST;
L17845:
        if  ( NEQ( _S2CUINT( X82 ), _S2CUINT( EMPTYLIST ) ) )  goto L17846;
        X79 = X84;
        goto L17857;
L17846:
        if  ( EQ( TSCPTAG( X82 ), PAIRTAG ) )  goto L17849;
        scrt1__24__car_2derror( X82 );
L17849:
        X88 = PAIR_CAR( X82 );
        if  ( EQ( TSCPTAG( X83 ), PAIRTAG ) )  goto L17852;
        scrt1__24__car_2derror( X83 );
L17852:
        X89 = PAIR_CAR( X83 );
        X90 = scrt1_list_2dref( X88, X89 );
        X87 = codetectionlib_2dsc_take( _TSCP( 16 ), X90 );
        X86 = sc_cons( X87, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X84 ), _S2CUINT( EMPTYLIST ) ) )  goto L17856;
        X87 = PAIR_CDR( X82 );
        X88 = PAIR_CDR( X83 );
        X85 = X86;
        X84 = X86;
        X83 = X88;
        X82 = X87;
        GOBACK( L17845 );
L17856:
        X87 = PAIR_CDR( X82 );
        X88 = PAIR_CDR( X83 );
        if  ( EQ( TSCPTAG( X85 ), PAIRTAG ) )  goto L17863;
        scdebug_error( c12316, 
                       c12317, CONS( X85, EMPTYLIST ) );
L17863:
        X85 = SETGEN( PAIR_CDR( X85 ), X86 );
        X83 = X88;
        X82 = X87;
        GOBACK( L17845 );
L17857:
        X80 = scrt1_list_2dref( X75, X77 );
        X81 = qobischeme_rest( X73 );
        X83 = scrt1_list_2dref( X43, X77 );
        X82 = codetectionlib_2dsc_drop( X83, X74 );
        X87 = CONS( X79, EMPTYLIST );
        X86 = scrt4_vector( CONS( X78, X87 ) );
        X85 = sc_cons( X86, EMPTYLIST );
        X84 = X85;
        X83 = scrt1_append_2dtwo( X80, X84 );
        X75 = qobischeme_list_2dreplace( X75, X77, X83 );
        X74 = X82;
        X73 = X81;
        GOBACK( L17837 );
L17839:
        X73 = CONS( X70, EMPTYLIST );
        X72 = scrt6_format( FALSEVALUE, CONS( c14192, X73 ) );
        obischeme_dto_2dfile_ae5c74d4( X71, X72 );
        X70 = codetectionlib_2dsc_join( DISPLAY( 5 ) );
        X71 = X70;
L17870:
        if  ( EQ( _S2CUINT( X71 ), _S2CUINT( EMPTYLIST ) ) )  goto L17871;
        if  ( EQ( TSCPTAG( X71 ), PAIRTAG ) )  goto L17875;
        scrt1__24__car_2derror( X71 );
L17875:
        X72 = PAIR_CAR( X71 );
        nlib_2dsc__2ddecache_e023ee48( X72 );
        X71 = PAIR_CDR( X71 );
        GOBACK( L17870 );
L17871:
        SDVAL = FALSEVALUE;
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        DISPLAY( 5 ) = SD5;
        DISPLAY( 6 ) = SD6;
        POPSTACKTRACE( SDVAL );
L17234:
        SDVAL = FALSEVALUE;
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        DISPLAY( 3 ) = SD3;
        DISPLAY( 4 ) = SD4;
        DISPLAY( 5 ) = SD5;
        DISPLAY( 6 ) = SD6;
        POPSTACKTRACE( SDVAL );
}

void  codetection__init(){}
void parser__init();
void pregexp__init();
void scrt5__init();
void toollib_2dc_2dbindings__init();
void screp__init();
void easy_2dffi__init();
void scdebug__init();
void scrt3__init();
void toollib_2dmatlab__init();
void scrt1__init();
void scrt4__init();
void scrt6__init();
void scrt2__init();
void codetectionlib_2dsc__init();
void qobischeme__init();
void qobischeme__init();
void xlib__init();
void parser__init();
void pregexp__init();
void codetectionlib_2dsc__init();
void toollib_2dmatlab__init();
void toollib_2dc_2dbindings__init();
void easy_2dffi__init();

static void  init_modules( compiler_version )
        char *compiler_version;
{
        parser__init();
        pregexp__init();
        scrt5__init();
        toollib_2dc_2dbindings__init();
        screp__init();
        easy_2dffi__init();
        scdebug__init();
        scrt3__init();
        toollib_2dmatlab__init();
        scrt1__init();
        scrt4__init();
        scrt6__init();
        scrt2__init();
        codetectionlib_2dsc__init();
        qobischeme__init();
        qobischeme__init();
        xlib__init();
        parser__init();
        pregexp__init();
        codetectionlib_2dsc__init();
        toollib_2dmatlab__init();
        toollib_2dc_2dbindings__init();
        easy_2dffi__init();
        MAXDISPLAY( 7 );
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
        INITIALIZEVAR( t16170, 
                       ADR( detection_on_2d1_2d0_9fcc6ee3_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      detection_on_2d1_2d0_9fcc6ee3, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16172, 
                       ADR( detection_on_2d3_2d0_e50c3d83_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      detection_on_2d3_2d0_e50c3d83, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16174, 
                       ADR( detection_on_2d5_2d0_6a4cc823_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      detection_on_2d5_2d0_6a4cc823, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16176, 
                       ADR( detection_on_2d7_2d0_108c9b43_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      detection_on_2d7_2d0_108c9b43, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16178, 
                       ADR( detection_on_2d9_2d0_afbc2522_v ), 
                       MAKEPROCEDURE( 0, 
                                      0, 
                                      detection_on_2d9_2d0_afbc2522, 
                                      EMPTYLIST ) );
        qobischeme__2aprogram_2a_v = c12043;
        qobischeme__2apanic_3f_2a_v = FALSEVALUE;
        INITIALIZEVAR( t16180, 
                       ADR( detection_hard_3f_2a_5334b1c_v ), 
                       FALSEVALUE );
        INITIALIZEVAR( t16181, 
                       ADR( detection_ideo_3f_2a_99b8f220_v ), 
                       FALSEVALUE );
        INITIALIZEVAR( t16182, 
                       ADR( detection_tations_2a_bae473a_v ), 
                       _TSCP( 16 ) );
        INITIALIZEVAR( t16183, 
                       ADR( detection_mes_2dn_2a_f0f9bc16_v ), 
                       _TSCP( 80 ) );
        INITIALIZEVAR( t16184, 
                       ADR( codetection__2aobjects_2a_v ), 
                       EMPTYLIST );
        INITIALIZEVAR( t16185, 
                       ADR( codetection_time_2dthunk_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      codetection_time_2dthunk, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16231, 
                       ADR( detection_2ddepth_2a_8800758e_v ), 
                       _TSCP( 0 ) );
        INITIALIZEVAR( t16232, 
                       ADR( codetection_frames_2d_3evideo_v ), 
                       MAKEPROCEDURE( 3, 
                                      0, 
                                      codetection_frames_2d_3evideo, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16257, 
                       ADR( codetection_video_2d_3eframes_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetection_video_2d_3eframes, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16269, 
                       ADR( detection_2dmatrices_c6981307_v ), 
                       MAKEPROCEDURE( 2, 
                                      0, 
                                      detection_2dmatrices_c6981307, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16281, 
                       ADR( detection_h_2dframes_d6c0ddee_v ), 
                       MAKEPROCEDURE( 5, 
                                      0, 
                                      detection_h_2dframes_d6c0ddee, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16306, 
                       ADR( detection_2dtracking_1add9051_v ), 
                       MAKEPROCEDURE( 6, 
                                      0, 
                                      detection_2dtracking_1add9051, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16420, 
                       ADR( codetection_get_2dpairs_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetection_get_2dpairs, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16445, 
                       ADR( detection_s_2dmatlab_cd7c75e6_v ), 
                       MAKEPROCEDURE( 8, 
                                      0, 
                                      detection_s_2dmatlab_cd7c75e6, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16474, 
                       ADR( detection_videos_2dc_c7669283_v ), 
                       MAKEPROCEDURE( 8, 
                                      0, 
                                      detection_videos_2dc_c7669283, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16501, 
                       ADR( detection__2dsampled_11a49785_v ), 
                       MAKEPROCEDURE( 7, 
                                      0, 
                                      detection__2dsampled_11a49785, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16534, 
                       ADR( detection_g_2dvideos_bd193643_v ), 
                       MAKEPROCEDURE( 6, 
                                      0, 
                                      detection_g_2dvideos_bd193643, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16771, 
                       ADR( detection_appearance_369afa03_v ), 
                       MAKEPROCEDURE( 4, 
                                      0, 
                                      detection_appearance_369afa03, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16831, 
                       ADR( detection_dinference_299999ac_v ), 
                       MAKEPROCEDURE( 17, 
                                      0, 
                                      detection_dinference_299999ac, 
                                      EMPTYLIST ) );
        INITIALIZEVAR( t16833, 
                       ADR( codetection_main_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, 
                                      codetection_main, EMPTYLIST ) );
        codetection_main( CLARGUMENTS( argc, argv ) );
        SCHEMEEXIT();
        return 0;
}
