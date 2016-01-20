/* LaHaShem HaAretz U'Mloah */
/* Copyright 2015 Purdue University. All rights reserved. */

#ifndef CODETECTIONLIB_C_H
#define CODETECTIONLIB_C_H

#include <stdarg.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#ifndef INT64_C
#define INT64_C(c) (c ## LL)
#define UINT64_C(c) (c ## ULL)
#endif
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <Imlib2.h>
#include <string.h>
#include <errno.h>

#define codetection_error(...) {			\
    fprintf(stderr, "%s:%d: ", __FUNCTION__, __LINE__);	\
    fprintf(stderr, __VA_ARGS__);			\
    fprintf(stderr, "\n");				\
    exit(EXIT_FAILURE); 				\
  }

#ifndef TRUE
#define TRUE (0==0)
#endif
#ifndef FALSE
#define FALSE (0!=0)
#endif
#ifndef MIN
#define MIN(a,b) ((a)>(b)?(b):(a))
#endif
#ifndef MAX
#define MAX(a,b) ((a)>(b)?(a):(b))
#endif

/* Scheme->C */
/* Fix Scheme->C signed integers */

#ifdef S2CINTBITS
void sc_error(char *symbol, char *format, TSCP args);
#endif

/* ffmpeg */

struct ffmpeg_video {
  AVFormatContext *pFormatCtx;
  int videoStream;
  AVCodecContext *pCodecCtx;
  AVFrame *pFrame;
  AVFrame *pFrameBGRA;
  uint8_t *buffer;
  struct SwsContext *img_convert_ctx;
  AVPacket packet;
  int frame;
  int videoFinished;
};

#ifdef S2CINTBITS
/* Scheme->C */
TSCP bool_tscp(int bool);

int tscp_bool(TSCP bool);

/* Fix Scheme->C signed integers */
TSCP sc_int_tscp(int n);

int sc_tscp_int(TSCP p);
#endif

/* ffmpeg */

int ffmpeg_first_video_stream(struct ffmpeg_video *ffmpeg_video);

AVCodecContext *ffmpeg_get_codec(struct ffmpeg_video *ffmpeg_video);

int ffmpeg_next_frame(struct ffmpeg_video *ffmpeg_video);

int ffmpeg_video_finished(struct ffmpeg_video *ffmpeg_video);

void ffmpeg_close_and_free_video(struct ffmpeg_video *ffmpeg_video);

struct ffmpeg_video *ffmpeg_open_video(char *filename);

Imlib_Image ffmpeg_get_frame_as_imlib(struct ffmpeg_video *ffmpeg_video);

void *codetection_malloc(size_t size);

/*========== scheme->c interfaces =============*/

/* temporal coherence */
void temporal_coherence(double **fxy, double ***boxes, int T, int top_k, double ***g);

/* tube candidates */
void reselect_proposals(double ***boxes, Imlib_Image *frames, int T,
			int pool_size, int top_k, int L,
			/*output*/
			double ***new_boxes);

void reselect_proposals_with_movement(double ***boxes, Imlib_Image *frames, int T,
				      int pool_size, int top_k, int movement,
				      /*output*/
				      double ***new_boxes);

int check_similarity_between_videos(char *c_video_dir1, char *c_video_dir2,
				    int T, int top_k, double ****similarities);

void similarity_between_videos(Imlib_Image *frames1, Imlib_Image *frames2,
			       double ***boxes1, double ***boxes2, 
			       char *c_video_dir1, char *c_video_dir2,
			       int T, int top_k,
			       /* output */
			       double ****similarities);
  
void set_track_constraint(int c);

void set_n_orientations(int n);

void set_video_fps(int fps);

void set_sentence_directed(int b);

void set_gamma(double g);

void set_imw(double w);

void set_imh(double h);

void average_object_appearance(Imlib_Image **frames_menu, double ***boxes_menu, int N, int *Ts);

#endif

/* Tam V'Nishlam Shevah L'El Borei Olam */
