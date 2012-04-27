INCLUDES = -I"GUI" -I"$(FLTK)"
CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = $(INCLUDES) -Wall -time -O3 -DEBUG -ggdb
INCPATH       = -IGUI -I.
LINK          = g++
LFLAGS        = -L "GUI" -Wl,-O1
LIBS          = -lstdc++ -lbookgui -lfltk -lfltk_images
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
		Animation.cpp \
		Box.cpp \
		Main.cpp \
		Tablet.cpp 

OBJECTS = \
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

Graph.o: GUI/Graph.cpp GUI/Graph.h \
		GUI/Point.h \
		GUI/std_lib_facilities.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Graph.o GUI/Graph.cpp

GUI.o: GUI/GUI.cpp GUI/GUI.h \
		GUI/Window.h \
		GUI/Point.h \
		GUI/Graph.h \
		GUI/std_lib_facilities.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GUI.o GUI/GUI.cpp

Simple_window.o: GUI/Simple_window.cpp GUI/Simple_window.h \
		GUI/GUI.h \
		GUI/Window.h \
		GUI/Point.h \
		GUI/Graph.h \
		GUI/std_lib_facilities.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Simple_window.o GUI/Simple_window.cpp

Window.o: GUI/Window.cpp GUI/Window.h \
		GUI/Point.h \
		GUI/Graph.h \
		GUI/std_lib_facilities.h \
		GUI/GUI.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Window.o GUI/Window.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

