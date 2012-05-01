#include "TabletView.h" 

TabletView::TabletView(Tablet & tablet)
	: Fl_Double_Window(100,100,300,300,"8x8"),
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

