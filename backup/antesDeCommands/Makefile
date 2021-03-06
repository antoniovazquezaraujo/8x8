INCLUDES = -I"$(FLTK)" -I/usr/local/include -I/usr/include/freetype2 
CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = $(INCLUDES) -time -O3 -Wall -DEBUG -ggdb -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT
INCPATH       = -IGUI -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -L/usr/local/lib -lfltk -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11
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

BASE = ColorChange.o\
		PosChange.o        \
		SizeChange.o       \
		Box.o              \
		TabletModel.o      \
		TabletView.o       \
		TabletController.o  

OBJECTS = ColorChange.o\
		PosChange.o        \
		SizeChange.o       \
		Box.o              \
		TabletModel.o      \
		TabletView.o       \
		TabletController.o \
		FltkTabletView.o   \
		Prueba1.o          \
		FltkPrueba1.o

OBJECTS_DEMO1  = $(BASE)   \
		FltkTabletView.o   \
		Demo1.o           

QMAKE_TARGET  = 8x8
DESTDIR       = 
TARGET        = 8x8
DEMO1         = demo1 

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

all: Makefile $(TARGET) $(DEMO1)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

$(DEMO1):  $(OBJECTS_DEMO1)  
	$(LINK) $(LFLAGS) -o $(DEMO1) $(OBJECTS_DEMO1) $(OBJCOMP) $(LIBS)

clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Compile

SizeChange.o: SizeChange.cpp SizeChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SizeChange.o SizeChange.cpp

ColorChange.o: ColorChange.cpp ColorChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ColorChange.o ColorChange.cpp

PosChange.o: PosChange.cpp PosChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PosChange.o PosChange.cpp

Box.o:	Box.cpp          \
		Box.h            \
		ColorChange.h    \
		PosChange.h      \
		SizeChange.h     \
		Rect.h           \
		Color.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Box.o Box.cpp

FltkPrueba1.o: FltkPrueba1.cpp     \
		FltkTabletView.h           \
		Prueba1.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FltkPrueba1.o FltkPrueba1.cpp

Demo1.o: Demo1.cpp         \
		FltkTabletView.h       \
		TabletView.h           \
		TabletController.h     \
		TabletModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Demo1.o Demo1.cpp

Prueba1.o: Prueba1.cpp         \
		Prueba1.h              \
		TabletView.h           \
		TabletModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Prueba1.o Prueba1.cpp

TabletController.o: TabletController.cpp         \
		TabletView.h                             \
		TabletModel.h                            \
		Box.h                                    \
		ColorChange.h                            \
		SizeChange.h                             \
		PosChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TabletController.o TabletController.cpp

FltkTabletView.o: FltkTabletView.cpp \
		FltkTabletView.h             \
		TabletView.h                 \
		TabletModel.h                \
		Box.h                        \
		SizeChange.h                 \
		PosChange.h                   
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FltkTabletView.o FltkTabletView.cpp

TabletModel.o: TabletModel.cpp  \
		TabletModel.h           \
		Box.h                   \
		ColorChange.h           \
		SizeChange.h            \
		PosChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TabletModel.o TabletModel.cpp

TabletView.o: TabletView.cpp  \
		TabletView.h          \
		TabletModel.h         \
		TabletController.h     
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TabletView.o TabletView.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

