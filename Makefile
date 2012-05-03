INCLUDES = -I"$(FLTK)" -I/usr/local/include
CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = $(INCLUDES) -time -O3 -Wall -DEBUG -ggdb
INCPATH       = -IGUI -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -L/usr/local/lib -lfltk  -ldl -lm -lX11
LIBS          = -lstdc++  -lfltk 
AR            = ar cqs
RANLIB        = 
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES = Animation.cpp \
		Box.cpp \
		FltkMain.cpp \
		FltkTabletController.cpp \
		FltkTabletView.cpp \
		Tablet.cpp 
OBJECTS = Animation.o \
		Box.o \
		FltkMain.o \
		FltkTabletController.o \
		FltkTabletView.o \
		Tablet.o

QMAKE_TARGET  = 8x8
DESTDIR       = 
TARGET        = 8x8

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

dist: 
	@$(CHK_DIR_EXISTS) .tmp/8x81.0.0 || $(MKDIR) .tmp/8x81.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/8x81.0.0/ && $(COPY_FILE) --parents Animation.h Box.h FltkTabletController.h FltkTabletView.h MoTabletController.h MoTabletView.h Tablet.h .tmp/8x81.0.0/ && $(COPY_FILE) --parents Animation.cpp Box.cpp FltkMain.cpp FltkTabletController.cpp FltkTabletView.cpp MoMain.cpp MoTabletController.cpp MoTabletView.cpp Tablet.cpp .tmp/8x81.0.0/ && (cd `dirname .tmp/8x81.0.0` && $(TAR) 8x81.0.0.tar 8x81.0.0 && $(COMPRESS) 8x81.0.0.tar) && $(MOVE) `dirname .tmp/8x81.0.0`/8x81.0.0.tar.gz . && $(DEL_FILE) -r .tmp/8x81.0.0


clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Compile

Animation.o: Animation.cpp Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Animation.o Animation.cpp

Box.o: Box.cpp Box.h \
		Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Box.o Box.cpp

FltkMain.o: FltkMain.cpp FltkTabletController.h \
		FltkTabletView.h \
		Tablet.h \
		Box.h \
		Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FltkMain.o FltkMain.cpp

FltkTabletController.o: FltkTabletController.cpp FltkTabletController.h \
		FltkTabletView.h \
		Tablet.h \
		Box.h \
		Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FltkTabletController.o FltkTabletController.cpp

FltkTabletView.o: FltkTabletView.cpp FltkTabletView.h \
		Tablet.h \
		Box.h \
		Animation.h \
		FltkTabletController.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FltkTabletView.o FltkTabletView.cpp

Tablet.o: Tablet.cpp Tablet.h \
		Box.h \
		Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Tablet.o Tablet.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

