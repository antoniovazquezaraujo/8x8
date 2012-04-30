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
class FLTKSurface : public Fl_Box {
public:
	FLTKSurface(ColorField & field, int X,int Y,int W,int H,const char*L=0); 
	void draw();
private:
	ColorField &colorField;
};
void callBack(void *object);
#endif
