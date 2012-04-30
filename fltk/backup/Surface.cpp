#include "Surface.h"
Surface::Surface(Tablet * tablet, int X,int Y,int W,int H,const char*L) 
	: Fl_Box(X,Y,W,H,L),
	tablet(tablet){
		box(FL_FLAT_BOX);
		color(BG_COLOR);
		Fl::add_timeout(TICKS, callBack, (void*)this);
}
void Surface::draw(int row, int col, int r, int g, int b){
	fl_rectf(x()+row*10, y()+col*10, 10, 10, r, g, b);
}
void Surface::draw() {
	Fl_Box::draw();
	tablet->draw(this);
}
void Surface::callBack(void *tablet) {
	Surface *o = (Surface*)tablet;
	o->redraw();
	Fl::repeat_timeout(TICKS, callBack, tablet);
}
int main() {
}
