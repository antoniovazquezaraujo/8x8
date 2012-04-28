#ifndef FLTK_SURFACE_H 
#define FLTK_SURFACE_H_
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <math.h>
#include <time.h>
#define BG_COLOR  0 
#define TICKS 0.025
#include "Tablet.h"
class Tablet;
class FLTKSurface : public Surface , public Fl_Box {
public:
    Surface(Tablet * tablet, int X,int Y,int W,int H,const char*L=0);
	void draw(int row, int col, int r, int g, int b);
private:
};
#endif
