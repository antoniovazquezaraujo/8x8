INCLUDES = -I"$(FLTK)" -I/usr/local/include
CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = $(INCLUDES) -time -O3 -Wall -DEBUG -ggdb
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

SOURCES = \
		Main.cpp \
		TabletView.cpp \
		TabletController.cpp \
		Animation.cpp \
		Box.cpp \
		Tablet.cpp 

OBJECTS = \
		Main.o \
		TabletView.o \
		TabletController.o\
		Animation.o \
		Box.o \
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

Main.o: Main.cpp TabletController.h 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Main.o Main.cpp

TabletController.o: TabletController.cpp TabletController.h TabletView.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TabletController.o TabletController.cpp

TabletView.o: TabletView.cpp TabletView.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TabletView.o TabletView.cpp

Animation.o: Animation.cpp Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Animation.o Animation.cpp

Box.o: Box.cpp Box.h \
		Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Box.o Box.cpp

Tablet.o: Tablet.cpp Tablet.h \
		Box.h \
		Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Tablet.o Tablet.cpp


