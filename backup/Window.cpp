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
//#include "Tablet.h" 
using namespace std;

#ifndef WIN32
#  include <unistd.h>
#  include <sys/time.h>
#endif // !WIN32

const int BLOCK_COLS=8;
const int BLOCK_ROWS=8;
const int BLOCK_SIZE=40;

class TabletView : public Fl_Double_Window {
public:

	TabletView();
	~TabletView();
	void  draw();
	int	  handle(int event);
	void  new_game();

private:
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

	TabletView *bw = new TabletView(); 
	bw->show(argc, argv);
	return (Fl::run());
}

TabletView::TabletView()
	: Fl_Double_Window(0,0,200,200,"8x8") {
	setup();
}


TabletView::~TabletView() {
	Fl::remove_timeout((Fl_Timeout_Handler)timeout_cb, (void *)this);
}

void TabletView::setup() {
	reset();
	Fl::add_timeout(1, (Fl_Timeout_Handler)timeout_cb, (void *)this);
}

void TabletView::onClick(int col, int row) {
}
void TabletView::onDrag(int col, int row) {
}
void TabletView::onRelease(int col, int row) {
}


void TabletView::draw() {
	cout << "pintando";
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
	Fl::repeat_timeout(1, (Fl_Timeout_Handler)timeout_cb, (void *)bw);
}

