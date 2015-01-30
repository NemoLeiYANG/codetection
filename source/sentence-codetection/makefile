all: codetection

OPTFLAGS=-O2 -DRELEASE -fopenmp
ARCHITECTURE_PATH = $(QARCHITECTURE_PATH)

CC = gcc-4.6
CFLAGS = -Wall -O3 -march=native -DLINUX $(OPTIONS)
SCCFLAGS = -O3
EXTRA_LDFLAGS = -lblas /usr/lib/libtbb.so.2

TARGET = codetection

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

SC_SRC = \
	pregexp.sc \
	toollib-matlab.sc \
	toollib-c-bindings.sc \

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
	scc-color -cc $(CC) $@.o $(SCCFLAGS) $(CFLAGS) $(DEBUG) $(MATLAB_LDFLAGS) $(OPTFLAGS) `imlib2-config --cflags` -DGL_GLEXT_PROTOTYPES $(OBJ) -o $@ $(LD_Q) ${EXTRA_LDFLAGS} $(FFMPEG_LDFLAGS) `imlib2-config --libs`
	make clean

%.o: %.sc %.sch toollib-c-macros.sch
	scc-color -cc $(CC) -sch 500 -scmh 800 $(SCCFLAGS) $(DEBUG) -I. -I ~/include $< -c $(CFLAGS) $(ARAVIS_CFLAGS) $(OPTFLAGS) `imlib2-config --cflags` -pthread

%.o: %.c
	$(CC) $(DEBUG) $(CFLAGS) -DGL_GLEXT_PROTOTYPES -I ~/lib/$(ARCHITECTURE_PATH) -I. $(MATLAB_CFLAGS) -std=gnu99 -c $< $(OPTFLAGS) `imlib2-config --cflags` -pthread

%.o: %.cpp
	g++ $(DEBUG) $(CFLAGS) -DGL_GLEXT_PROTOTYPES -I. -c $< $(OPTFLAGS) `imlib2-config --cflags` -pthread

toollib-matlab.o: toollib-matlab.sc toollib-matlab.sch toollib-c-macros.sch
	scc-color -cc $(CC) $(SCCFLAGS) $(CFLAGS) -I. -I ~/include -c toollib-matlab.sc $(MATLAB_CFLAGS) -std=gnu99

clean:
	-rm -f $(OBJ) $(TARGET_SRC:.sc=.c) $(TARGET_SRC:.sc=.o) \
	$(TARGET_SCH) core $(CFILES) $(SCH)

real-clean: clean
	-rm -r -f $(TARGET_SRC:.sc=)
