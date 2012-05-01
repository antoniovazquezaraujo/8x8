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
using namespace std;

#ifndef WIN32
#  include <unistd.h>
#  include <sys/time.h>
#endif // !WIN32

const int BLOCK_COLS=8;
const int BLOCK_ROWS=8;
const int BLOCK_SIZE=20;

class BlockWindow : public Fl_Double_Window {
public:

	BlockWindow(int X, int Y, int W, int H, const char *L = 0);
	BlockWindow(int W, int H, const char *L = 0);
	~BlockWindow();

	void  draw();
	int	  handle(int event);
	void  new_game();

private:

	bool	paused_;
	void	setup();
	int	    click(int col, int row);
	void	reset();
	static void	timeout_cb(BlockWindow *bw);
};


int main(int argc, char *argv[]) {
	Fl::scheme("plastic");
	Fl::visible_focus(0);

	BlockWindow *bw = new BlockWindow(
		BLOCK_COLS * BLOCK_SIZE,
		BLOCK_ROWS * BLOCK_SIZE + 20,
		"8x8"
	);

	bw->show(argc, argv);
	return (Fl::run());
}

BlockWindow::BlockWindow(int X, int Y, int W, int H, const char *L)
	: Fl_Double_Window(X, Y, W, H, L) {
	setup();
}

BlockWindow::BlockWindow(int W, int H, const char *L)
	: Fl_Double_Window(W, H, L) {
	setup();
}

BlockWindow::~BlockWindow() {
	Fl::remove_timeout((Fl_Timeout_Handler)timeout_cb, (void *)this);
}

void BlockWindow::setup() {
	reset();
	Fl::add_timeout(0.1, (Fl_Timeout_Handler)timeout_cb, (void *)this);
}

int BlockWindow::click(int col, int row) {
	cout << "click"<<endl;
}


void BlockWindow::draw() {
	fl_color(FL_BLACK);
	fl_rectf(0, 0, w(), h());
	static int red=0;
	// Draw the blocks...
	for (int row = 0; row< 8; row++ ){
		for (int col= 0; col< 8; col++ ){
			fl_rectf( row*BLOCK_SIZE, col*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE,red,0 ,0);
		}
	}
	red++;
}


int BlockWindow::handle(int event) {
	if (Fl_Double_Window::handle(event)){
		return (1);
	} 

	int mx, my;
	switch (event) {
	case FL_PUSH :
		if(Fl::event_clicks()!=0){
			cout << "Doble click" << endl;
		}else{
			cout << "Click" << endl;
		}
		mx    = w() - Fl::event_x() + BLOCK_SIZE;
		my    = h() - Fl::event_y();
		//return (1);
		break;
	case FL_DRAG:
		cout << "Arrastrando" << endl;
		break;
	case FL_RELEASE:
		cout << "Soltando" << endl;
		break;
	}
	return (0);
}



// Initialize the block window...
void BlockWindow::reset() {
}


// Start a new game...
void BlockWindow::new_game() {
	srand(time(NULL));
	reset();
	redraw();
}


// Animate the game...
void BlockWindow::timeout_cb(BlockWindow *bw) {
	bw->redraw();
	Fl::repeat_timeout(0.1, (Fl_Timeout_Handler)timeout_cb, (void *)bw);
}

