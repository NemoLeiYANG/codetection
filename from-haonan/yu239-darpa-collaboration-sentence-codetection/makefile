all: codetection

OPTFLAGS=-O2 -DRELEASE -fopenmp
ARCHITECTURE_PATH = $(QARCHITECTURE_PATH)

CC = gcc-4.6
CFLAGS = -Wall -O3 -DLINUX $(OPTIONS)
SCCFLAGS = -O3

DEBUG =

TARGET = codetection

OPENGM_I = -D IL_STD -I $(HOME)
LIBDAI_I = -I ~/libDAI/include
LIBDAI_L = -L ~/libDAI/lib -ldai -lgmpxx -lgmp

OPENCV_L = $(HOME)/opencv3/lib/libopencv_core.so \
	$(HOME)/opencv3/lib/libopencv_imgproc.so \
	$(HOME)/opencv3/lib/libopencv_highgui.so \
	$(HOME)/opencv3/lib/libopencv_video.so \
	$(HOME)/opencv3/lib/libopencv_features2d.so \
	$(HOME)/opencv3/lib/libopencv_tracking.so \
	$(HOME)/opencv3/lib/libopencv_videoio.so \
	$(HOME)/opencv3/lib/libopencv_objdetect.so \
	$(HOME)/opencv3/lib/libopencv_imgcodecs.so \
	$(HOME)/opencv3/lib/libopencv_flann.so \
	$(HOME)/opencv3/lib/libopencv_xfeatures2d.so

OPENCV_I = -I $(HOME)/opencv3/include

MATLAB_CFLAGS = $(shell mbuild -f ${MATLAB}/bin/engopts.sh -v 2> /dev/null|grep CFLAGS|cut -d= -f2-)
MATLAB_RAW_LDFLAGS = $(shell mbuild -f ${MATLAB}/bin/engopts.sh -v 2> /dev/null|grep CLIBS|cut -d= -f2-) \
 $(shell mbuild -f ${MATLAB}/bin/engopts.sh -v 2> /dev/null|grep LDFLAGS|cut -d= -f2-)
MATLAB_LDFLAGS = $(MATLAB_RAW_LDFLAGS:-lstdc++=)

LD_Q =  -L~/lib/$(QARCHITECTURE_PATH)/ \
	~/lib/$(QARCHITECTURE_PATH)/QobiScheme.a  \
	~/lib/$(QARCHITECTURE_PATH)/scxl.a -lX11 -lXext

FFMPEG_LDFLAGS = -lavutil -lavformat -lavcodec -lavutil -lm -lswscale

C_SRC = \
	codetectionlib-c.c \

CPP_SRC = \
	inference.cpp \
	codetectionlib-cpp.cpp \

SC_SRC = \
	parser.sc \
	pregexp.sc \
	codetectionlib-sc.sc \
	toollib-matlab.sc \
	toollib-c-bindings.sc \
	easy-ffi.sc \

OBJ = $(SC_SRC:.sc=.o) $(C_SRC:.c=.o) $(CPP_SRC:.cpp=.o)
SCH = $(SC_SRC:.sc=.sch)
TARGET_SRC = $(TARGET:=.sc)
TARGET_SCH = $(TARGET_SRC:.sc=.sch)
CFILES = $(SC_SRC:.sc=.c)

.SECONDEXPANSION:

${SCH}: $$(basename $$@).sc $$(SC_SRC)
	sch $(basename $@) $(SC_SRC)
	touch $(basename $@).sch

${TARGET_SCH}: $$(basename $$@).sc
	sch -main $(basename $@) $(SC_SRC)
	touch $(basename $@).sch

# -Ot -Ob -Og $(OPTFLAGS)
${TARGET}: $$(basename $$@).sc $$(basename $$@).sch $$(SCH) $(OBJ) $$@.o
	scc-color -cc $(CC) $@.o $(SCCFLAGS) $(CFLAGS) $(DEBUG) $(MATLAB_LDFLAGS) $(OPTFLAGS) `imlib2-config --cflags` -DGL_GLEXT_PROTOTYPES $(OBJ) -o $@ $(LD_Q) ${EXTRA_LDFLAGS} $(FFMPEG_LDFLAGS) `imlib2-config --libs` $(LIBDAI_L) $(OPENCV_L)

%.o: %.sc %.sch toollib-c-macros.sch
	scc-color -cc $(CC) -sch 500 -scmh 800 $(SCCFLAGS) $(DEBUG) -I. -I ~/include $< -c $(CFLAGS) $(ARAVIS_CFLAGS) $(OPTFLAGS) `imlib2-config --cflags` -pthread

%.o: %.c
	$(CC) $(DEBUG) $(CFLAGS) -DGL_GLEXT_PROTOTYPES -I ~/lib/$(ARCHITECTURE_PATH) -I. $(MATLAB_CFLAGS) -std=gnu99 -c $< $(OPTFLAGS) `imlib2-config --cflags` -pthread

%.o: %.cpp
	g++ -std=c++11 $(DEBUG) $(CFLAGS) -DGL_GLEXT_PROTOTYPES -I. -c $< $(OPTFLAGS) `imlib2-config --cflags` -pthread $(OPENGM_I) $(LIBDAI_I) $(OPENCV_I)

toollib-matlab.o: toollib-matlab.sc toollib-matlab.sch toollib-c-macros.sch
	scc-color -cc $(CC) $(SCCFLAGS) $(CFLAGS) -I. -I ~/include -c toollib-matlab.sc $(MATLAB_CFLAGS) -std=gnu99

clean:
	-rm -f $(OBJ) $(TARGET_SRC:.sc=.c) $(TARGET_SRC:.sc=.o) \
	$(TARGET_SCH) core $(CFILES) $(SCH)

real-clean: clean
	-rm -r -f $(TARGET_SRC:.sc=)
