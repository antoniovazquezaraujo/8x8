#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Preferences.H>
#include <FL/fl_draw.H>
#include <FL/x.H>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "Tablet.h" 
using namespace std;

#ifndef WIN32
#  include <unistd.h>
#  include <sys/time.h>
#endif // !WIN32

const int BLOCK_COLS=8;
const int BLOCK_ROWS=8;
const int BLOCK_SIZE=40;
const int DRAW_TIME=0.025;

class TabletView : public Fl_Double_Window {
public:

	TabletView(Tablet & t);
	~TabletView();
	void  draw();
	int	  handle(int event);
	void  new_game();

private:
	Tablet & tablet;
	void  onClick(int x, int y);
	void  onDrag(int x, int y);
	void  onRelease(int x, int y);
	void  setup();
	int   click(int col, int row);
	void  reset();

	static void	timeout_cb(TabletView *bw);
};


int main(int argc, char *argv[]) {
	Fl::scheme("plastic");
	Fl::visible_focus(0);
	Tablet t;
	for (int row = 0; row < ROWS ; row++) {
		for (int col = 0; col < COLS ; col++) {
			t.addBox(0, row, col, 1, 1);
			t.lastBox(0).setColor(0, 0, 0);
			t.lastBox(0).addAnimation(155, 0, 0, 0, 0, 0, 5);
			t.lastBox(0).addAnimation(0, 0, 100, 0, 0, 0, 5);
			t.lastBox(0).start();
		}
	}
	for (int row = 0; row < ROWS ; row++) {
		for (int col = 0; col < COLS-4 ; col++) {
			t.addBox(1, row, col, 1, 1);
			t.lastBox(1).setColor(3, 3, 3);
			t.lastBox(1).addAnimation(10, 0, 0, 0, 0, 0, 2);
			t.lastBox(1).addAnimation(0, 0, 200, 0, 0, 0, 3);
			t.lastBox(1).start(3);
		}
	}
	for (int row = 0; row < ROWS ; row++) {
		for (int col = 5; col < COLS ; col++) {
			t.addBox(1, row, col, 1, 1);
			t.lastBox(1).setColor(3, 3, 3);
			t.lastBox(1).addAnimation(10, 0, 0, 0, 0, 0, 2);
			t.lastBox(1).addAnimation(0, 0, 200, 0, 0, 0, 4);
			t.lastBox(1).start(1, 2);
		}
	}


	TabletView *bw = new TabletView(t); 
	bw->show(argc, argv);
	return (Fl::run());
}

TabletView::TabletView(Tablet & tablet)
	: Fl_Double_Window(0,0,200,200,"8x8"),
	tablet(tablet){
	setup();
}


TabletView::~TabletView() {
	Fl::remove_timeout((Fl_Timeout_Handler)timeout_cb, (void *)this);
}

void TabletView::setup() {
	reset();
	Fl::add_timeout(DRAW_TIME, (Fl_Timeout_Handler)timeout_cb, (void *)this);
}

void TabletView::onClick(int col, int row) {
}
void TabletView::onDrag(int col, int row) {
}
void TabletView::onRelease(int col, int row) {
}


void TabletView::draw() {
	ColorField &f = tablet.getColorField();
	fl_color(FL_BLACK);
	fl_rectf(0, 0, w(), h());
	for (int level = 0; level < LEVELS; level++ ){
		for (int row = 0; row< ROWS; row++ ){
			for (int col= 0; col< COLS; col++ ){
				fl_rectf( 
					row*BLOCK_SIZE, 
					col*BLOCK_SIZE, 
					BLOCK_SIZE, 
					BLOCK_SIZE,
					f[level][row][col][0],
					f[level][row][col][1],
					f[level][row][col][2]
					);
			}
		}
	}
}



int TabletView::handle(int event) {
	if (Fl_Double_Window::handle(event)){
		return (1);
	} 
	int x = w() - Fl::event_x() + BLOCK_SIZE;
	int y = h() - Fl::event_y();
	switch (event) {
	case FL_PUSH :
		onClick(x,y);
		break;
	case FL_DRAG:
		onDrag(x,y);
		break;
	case FL_RELEASE:
		onRelease(x,y);
		break;
	}
	return (1);
}



// Initialize the block window...
void TabletView::reset() {
}


// Start a new game...
void TabletView::new_game() {
	srand(time(NULL));
	reset();
	redraw();
}


// Animate the game...
void TabletView::timeout_cb(TabletView *bw) {
	bw->redraw();
	Fl::repeat_timeout(DRAW_TIME, (Fl_Timeout_Handler)timeout_cb, (void *)bw);
}

