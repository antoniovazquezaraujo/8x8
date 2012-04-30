INCLUDES = -I"GUI" -I"$(FLTK)"
CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = $(INCLUDES) -Wall -time -O3 -DEBUG -ggdb -I/usr/local/include -I/usr/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT
INCPATH       = -IGUI -I.
LINK          = g++
LFLAGS        = -L "GUI" -Wl,-O1 -L/usr/local/lib -lfltk -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11
LIBS          = -lstdc++ -lfltk -lfltk_images /usr/local/lib/libfltk.a
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

SOURCES = \
		FLTKSurface.cpp \
		Animation.cpp \
		Box.cpp \
		Main.cpp \
		Tablet.cpp 

OBJECTS = \
		FLTKSurface.o \
		Animation.o \
		Box.o \
		Main.o \
		Tablet.o 

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

all: $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Compile


FLTKSurface.o: FLTKSurface.cpp FLTKSurface.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FLTKSurface.o FLTKSurface.cpp

Animation.o: Animation.cpp Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Animation.o Animation.cpp

Box.o: Box.cpp Box.h \
		Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Box.o Box.cpp

Main.o: Main.cpp Tablet.h \
		Box.h \
		Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Main.o Main.cpp

Tablet.o: Tablet.cpp Tablet.h \
		Box.h \
		Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Tablet.o Tablet.cpp


