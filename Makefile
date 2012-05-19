INCLUDES = -I"$(FLTK)" -I/usr/local/include -I/usr/include/freetype2 
# Esto sirve para usar gprof. Si no se usa se puede quitar
#PROFILING     = -pg
PROFILING     = 

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = $(INCLUDES) $(PROFILING) -ggdb -time -O3 -Wall -DEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT
INCPATH       = -IGUI -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -L/usr/local/lib $(PROFILING) -lfltk -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11
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

SOURCES       = Box.cpp \
		Change.cpp \
		Color.cpp \
		ColorChange.cpp \
		ColorStep.cpp \
		FltkMain.cpp \
		FltkTabletView.cpp \
		Form.cpp \
		Pos.cpp \
		PosChange.cpp \
		PosStep.cpp \
		Command.cpp \
		Prueba1.cpp \
		Size.cpp \
		SizeChange.cpp \
		SizeStep.cpp \
		TabletController.cpp \
		TabletModel.cpp \
		TabletView.cpp 
OBJECTS       = Box.o \
		Change.o \
		Color.o \
		ColorChange.o \
		ColorStep.o \
		FltkMain.o \
		FltkTabletView.o \
		Form.o \
		Pos.o \
		PosChange.o \
		PosStep.o \
		Command.o \
		Prueba1.o \
		Size.o \
		SizeChange.o \
		SizeStep.o \
		TabletController.o \
		TabletModel.o \
		TabletView.o

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
	-$(DEL_FILE) $(TARGET) 

Box.o: Box.cpp Box.h \
		Color.h \
		ColorStep.h \
		Pos.h \
		PosStep.h \
		Size.h \
		SizeStep.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Box.o Box.cpp

Change.o: Change.cpp Change.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Change.o Change.cpp

Color.o: Color.cpp Color.h \
		ColorStep.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Color.o Color.cpp

ColorChange.o: ColorChange.cpp ColorChange.h \
		Change.h \
		Color.h \
		ColorStep.h \
		Form.h \
		Pos.h \
		PosStep.h \
		Size.h \
		SizeStep.h \
		Box.h \
		Command.h \
		PosChange.h \
		SizeChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ColorChange.o ColorChange.cpp

ColorStep.o: ColorStep.cpp ColorStep.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ColorStep.o ColorStep.cpp

FltkMain.o: FltkMain.cpp FltkTabletView.h \
		TabletView.h \
		Prueba1.h \
		TabletController.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FltkMain.o FltkMain.cpp

FltkTabletView.o: FltkTabletView.cpp FltkTabletView.h \
		TabletView.h \
		TabletController.h \
		TabletModel.h \
		Form.h \
		Color.h \
		ColorStep.h \
		Pos.h \
		PosStep.h \
		Size.h \
		SizeStep.h \
		Box.h \
		Command.h \
		ColorChange.h \
		Change.h \
		PosChange.h \
		SizeChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FltkTabletView.o FltkTabletView.cpp

Form.o: Form.cpp Form.h \
		Color.h \
		ColorStep.h \
		Pos.h \
		PosStep.h \
		Size.h \
		SizeStep.h \
		Box.h \
		Command.h \
		ColorChange.h \
		Change.h \
		PosChange.h \
		SizeChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Form.o Form.cpp

Pos.o: Pos.cpp Pos.h \
		PosStep.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Pos.o Pos.cpp

PosChange.o: PosChange.cpp PosChange.h \
		Change.h \
		Pos.h \
		PosStep.h \
		Form.h \
		Color.h \
		ColorStep.h \
		Size.h \
		SizeStep.h \
		Box.h \
		Command.h \
		ColorChange.h \
		SizeChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PosChange.o PosChange.cpp

PosStep.o: PosStep.cpp PosStep.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PosStep.o PosStep.cpp

Command.o: Command.cpp Command.h \
		ColorChange.h \
		Change.h \
		Color.h \
		ColorStep.h \
		PosChange.h \
		Pos.h \
		PosStep.h \
		SizeChange.h \
		Size.h \
		SizeStep.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Command.o Command.cpp

Prueba1.o: Prueba1.cpp Prueba1.h \
		TabletController.h \
		TabletModel.h \
		Form.h \
		Color.h \
		ColorStep.h \
		Pos.h \
		PosStep.h \
		Size.h \
		SizeStep.h \
		Box.h \
		Command.h \
		ColorChange.h \
		Change.h \
		PosChange.h \
		SizeChange.h \
		TabletView.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Prueba1.o Prueba1.cpp

Size.o: Size.cpp Size.h \
		SizeStep.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Size.o Size.cpp

SizeChange.o: SizeChange.cpp SizeChange.h \
		Change.h \
		Size.h \
		SizeStep.h \
		Form.h \
		Color.h \
		ColorStep.h \
		Pos.h \
		PosStep.h \
		Box.h \
		Command.h \
		ColorChange.h \
		PosChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SizeChange.o SizeChange.cpp

SizeStep.o: SizeStep.cpp SizeStep.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SizeStep.o SizeStep.cpp

TabletController.o: TabletController.cpp TabletController.h \
		TabletView.h \
		TabletModel.h \
		Form.h \
		Color.h \
		ColorStep.h \
		Pos.h \
		PosStep.h \
		Size.h \
		SizeStep.h \
		Box.h \
		Command.h \
		ColorChange.h \
		Change.h \
		PosChange.h \
		SizeChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TabletController.o TabletController.cpp

TabletModel.o: TabletModel.cpp TabletModel.h \
		Form.h \
		Color.h \
		ColorStep.h \
		Pos.h \
		PosStep.h \
		Size.h \
		SizeStep.h \
		Box.h \
		Command.h \
		ColorChange.h \
		Change.h \
		PosChange.h \
		SizeChange.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TabletModel.o TabletModel.cpp

TabletView.o: TabletView.cpp TabletView.h \
		TabletModel.h \
		Form.h \
		Color.h \
		ColorStep.h \
		Pos.h \
		PosStep.h \
		Size.h \
		SizeStep.h \
		Box.h \
		Command.h \
		ColorChange.h \
		Change.h \
		PosChange.h \
		SizeChange.h \
		TabletController.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TabletView.o TabletView.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

