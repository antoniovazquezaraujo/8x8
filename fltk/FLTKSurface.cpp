#include "FLTKSurface.h"
FLTKSurface::FLTKSurface(ColorField & colorField, int X,int Y,int W,int H,const char*L) 
	: Fl_Box(X,Y,W,H,L),
	colorField(colorField){
		box(FL_FLAT_BOX);
		color(BG_COLOR);
		Fl::add_timeout(TICKS, callBack, (void*)this);
}
void FLTKSurface::draw() {
	Fl_Box::draw();

	for (int level = 0; level < LEVELS; level++) {
		for (int row = 0; row < ROWS; row++) {
			for (int col = 0; col < COLS; col++) {
				fl_rectf(
						row*10, 
						col*10, 
						10, 
						10,  
						colorField[level][row][col][0],
						colorField[level][row][col][1],
						colorField[level][row][col][2]
				);
			}
		}
	}
}
void callBack(void *object) {
	FLTKSurface *o = (FLTKSurface*)object;
	o->redraw();
	Fl::repeat_timeout(TICKS, callBack, object);
}
