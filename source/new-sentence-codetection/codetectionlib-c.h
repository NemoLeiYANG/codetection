/* LaHaShem HaAretz U'Mloah */
/* Copyright 2015 Purdue University. All rights reserved. */

#include <stdarg.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
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

// #ifdef S2CINTBITS
// /* Scheme->C */
// TSCP bool_tscp(int bool);

// int tscp_bool(TSCP bool);

// /* Fix Scheme->C signed integers */
// TSCP sc_int_tscp(int n);

// int sc_tscp_int(TSCP p);
// #endif

// /* ffmpeg */

// int ffmpeg_first_video_stream(struct ffmpeg_video *ffmpeg_video);

// AVCodecContext *ffmpeg_get_codec(struct ffmpeg_video *ffmpeg_video);

// int ffmpeg_next_frame(struct ffmpeg_video *ffmpeg_video);

// int ffmpeg_video_finished(struct ffmpeg_video *ffmpeg_video);

// void ffmpeg_close_and_free_video(struct ffmpeg_video *ffmpeg_video);

// struct ffmpeg_video *ffmpeg_open_video(char *filename);

// Imlib_Image ffmpeg_get_frame_as_imlib(struct ffmpeg_video *ffmpeg_video);

void *codetection_malloc(size_t size);

/* Tam V'Nishlam Shevah L'El Borei Olam */
