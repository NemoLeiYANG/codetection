/* LaHaShem HaAretz U'Mloah */
/* Copyright 2015 Purdue University. All rights reserved. */

#include <math.h>
#include "objects.h" // scheme->c
#undef TRUE
#undef FALSE
#include "codetectionlib-c.h"

/* Scheme->C */

/* TSCP bool_tscp(int bool) { */
/*   if (bool) return TRUEVALUE; */
/*   else return FALSEVALUE; */
/* } */

/* int tscp_bool(TSCP bool) { */
/*   if (bool==TRUEVALUE) return 1; */
/*   if (bool==FALSEVALUE) return 0; */
/*   sc_error("TSCP_BOOL", "~s is not a boolean", CONS(bool, EMPTYLIST)); */
/*   exit(EXIT_FAILURE); */
/* } */

/* /\* Fix Scheme->C signed integers *\/ */

/* TSCP sc_int_tscp(int n) { */
/*   if (n<=MAXTSCPINT&&n>=MINTSCPINT) return C_FIXED(n); */
/*   return MAKEFLOAT((double)n); */
/* } */

/* int sc_tscp_int(TSCP p) { */
/*   switch TSCPTAG(p) { */
/*     case FIXNUMTAG: */
/*       return FIXED_C(p); */
/*       break; */
/*     case EXTENDEDTAG: */
/*       if (TX_U(p)->extendedobj.tag==DOUBLEFLOATTAG) { */
/*         return (S2CINT)FLOAT_VALUE(p); */
/*       } */
/*       break; */
/*     } */
/*   sc_error("TSCP_S2CINT", "Argument cannot be converted to C int", */
/* 	   EMPTYLIST); */
/*   return 0;                     /\* silences warning *\/ */
/* } */

/* /\* ffmpeg *\/ */

/* int ffmpeg_first_video_stream(struct ffmpeg_video *ffmpeg_video) { */
/*   if (av_find_stream_info(ffmpeg_video->pFormatCtx)<0) { */
/*     codetection_error("Can't get video stream information"); */
/*   } */
/*   for (unsigned int i = 0; i<ffmpeg_video->pFormatCtx->nb_streams; i++) { */
/*     if (ffmpeg_video->pFormatCtx->streams[i]->codec->codec_type== */
/* 	AVMEDIA_TYPE_VIDEO) { */
/*       return i; */
/*     } */
/*   } */
/*   codetection_error("Can't find first video stream"); */
/* } */

/* AVCodecContext *ffmpeg_get_codec(struct ffmpeg_video *ffmpeg_video) { */
/*   AVCodecContext *pCodecCtx = */
/*     ffmpeg_video->pFormatCtx->streams[ffmpeg_video->videoStream]->codec; */
/*   AVCodec *pCodec = avcodec_find_decoder(pCodecCtx->codec_id); */
/*   if (pCodec==NULL) codetection_error("Unsupported codec!"); */
/*   if (avcodec_open(pCodecCtx, pCodec)<0) codetection_error("Can't open codec!"); */
/*   return pCodecCtx; */
/* } */

/* int ffmpeg_next_frame(struct ffmpeg_video *ffmpeg_video) { */
/*   av_free_packet(&ffmpeg_video->packet); */
/*   int frameFinished; */
/*   int nextFrameValid = */
/*     av_read_frame(ffmpeg_video->pFormatCtx, &ffmpeg_video->packet)>=0; */
/*   if (nextFrameValid&& */
/*       ffmpeg_video->packet.stream_index==ffmpeg_video->videoStream) { */
/*     avcodec_decode_video2(ffmpeg_video->pCodecCtx, */
/* 			  ffmpeg_video->pFrame, */
/* 			  &frameFinished, */
/* 			  &ffmpeg_video->packet); */
/*     if (frameFinished) ffmpeg_video->frame++; */
/*     else ffmpeg_next_frame(ffmpeg_video); */
/*   } */
/*   else if (nextFrameValid) ffmpeg_next_frame(ffmpeg_video); */
/*   else if (!ffmpeg_video->videoFinished&&!nextFrameValid) { */
/*     /\* This is required because ffmpeg hangs on to many frames internally *\/ */
/*     AVPacket packet; */
/*     packet.data = NULL; */
/*     packet.size = 0; */
/*     avcodec_decode_video2(ffmpeg_video->pCodecCtx, */
/* 			  ffmpeg_video->pFrame, */
/* 			  &frameFinished, */
/* 			  &packet); */
/*     if (frameFinished) ffmpeg_video->frame++; */
/*     else ffmpeg_video->videoFinished = TRUE; */
/*   } */
/*   return !ffmpeg_video->videoFinished; */
/* } */

/* int ffmpeg_video_finished(struct ffmpeg_video *ffmpeg_video) { */
/*   return ffmpeg_video->videoFinished; */
/* } */

/* void ffmpeg_close_and_free_video(struct ffmpeg_video *ffmpeg_video) { */
/*   av_free(ffmpeg_video->buffer); */
/*   av_free(ffmpeg_video->pFrameBGRA); */
/*   av_free(ffmpeg_video->pFrame); */
/*   avcodec_close(ffmpeg_video->pCodecCtx); */
/*   av_close_input_file(ffmpeg_video->pFormatCtx); */
/*   av_free_packet(&ffmpeg_video->packet); */
/*   ffmpeg_video->videoFinished = TRUE; */
/*   free(ffmpeg_video); */
/* } */

/* struct ffmpeg_video *ffmpeg_open_video(char *filename) { */
/*   // dynamic allocation */
/*   struct ffmpeg_video *ffmpeg_video = */
/*     (struct ffmpeg_video *)codetection_malloc(sizeof(struct ffmpeg_video)); */
/*   /\* needs work: bzero is deprecated, should use memset *\/ */
/*   bzero(ffmpeg_video, sizeof(struct ffmpeg_video)); */
/*   av_register_all(); */
/*   if (avformat_open_input(&ffmpeg_video->pFormatCtx, filename, NULL, NULL)!=0) { */
/*     codetection_error("Can't open video %s", filename); */
/*   } */
/*   ffmpeg_video->videoStream = ffmpeg_first_video_stream(ffmpeg_video); */
/*   ffmpeg_video->pCodecCtx = ffmpeg_get_codec(ffmpeg_video); */
/*   // dynamic allocation */
/*   ffmpeg_video->pFrame = avcodec_alloc_frame(); */
/*   // dynamic allocation */
/*   ffmpeg_video->pFrameBGRA = avcodec_alloc_frame(); */
/*   if (!ffmpeg_video->pFrameBGRA||!ffmpeg_video->pFrame) { */
/*     codetection_error("Can't allocate frame"); */
/*   } */
/*   // dynamic allocation */
/*   ffmpeg_video->buffer = */
/*     (uint8_t *)av_malloc(avpicture_get_size(PIX_FMT_BGRA, */
/* 					    ffmpeg_video->pCodecCtx->width, */
/* 					    ffmpeg_video->pCodecCtx->height)* */
/* 			 sizeof(uint8_t)); */
/*   avpicture_fill((AVPicture *)ffmpeg_video->pFrameBGRA, */
/* 		 ffmpeg_video->buffer, PIX_FMT_BGRA, */
/* 		 ffmpeg_video->pCodecCtx->width, */
/* 		 ffmpeg_video->pCodecCtx->height); */
/*   ffmpeg_video->img_convert_ctx = */
/*     sws_getContext(ffmpeg_video->pCodecCtx->width, */
/* 		   ffmpeg_video->pCodecCtx->height, */
/* 		   ffmpeg_video->pCodecCtx->pix_fmt, */
/* 		   ffmpeg_video->pCodecCtx->width, */
/* 		   ffmpeg_video->pCodecCtx->height, */
/* 		   PIX_FMT_BGRA, SWS_BICUBIC, */
/* 		   NULL, NULL, NULL); */
/*   ffmpeg_video->videoFinished = FALSE; */
/*   ffmpeg_video->frame = 0; */
/*   av_init_packet(&ffmpeg_video->packet); */
/*   ffmpeg_next_frame(ffmpeg_video); */
/*   return ffmpeg_video; */
/* } */

/* Imlib_Image ffmpeg_get_frame_as_imlib(struct ffmpeg_video *ffmpeg_video) { */
/*   sws_scale(ffmpeg_video->img_convert_ctx, */
/* 	    (const uint8_t *const *)ffmpeg_video->pFrame->data, */
/* 	    ffmpeg_video->pFrame->linesize, 0, */
/* 	    ffmpeg_video->pCodecCtx->height, */
/* 	    ffmpeg_video->pFrameBGRA->data, ffmpeg_video->pFrameBGRA->linesize); */
/*   // dynamic allocation */
/*   Imlib_Image image = */
/*     imlib_create_image_using_copied_data(ffmpeg_video->pCodecCtx->width, */
/* 					 ffmpeg_video->pCodecCtx->height, */
/* 					 (uint32_t *)ffmpeg_video->buffer); */
/*   return image; */
/* } */

void *codetection_malloc(size_t size) {
  void *p = malloc(size);
  if (p==NULL) codetection_error("Out of memory");
  return p;
}

/* Tam V'Nishlam Shevah L'El Borei Olam */
