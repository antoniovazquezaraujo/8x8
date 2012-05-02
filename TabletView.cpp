#include "TabletView.h" 
#include "TabletController.h" 

TabletView::TabletView(Tablet & tablet, TabletController * controller)
	: Fl_Double_Window(20,20,640,640,"8x8"),
	tablet(tablet){
	end();
	setup();
}

TabletView::~TabletView() {
	Fl::remove_timeout((Fl_Timeout_Handler)timeout_cb, (void *)this);
}

void TabletView::setup() {
	Fl::add_timeout(DRAW_TIME, (Fl_Timeout_Handler)timeout_cb, (void *)this);
	srand(time(NULL));
	redraw();
}

void TabletView::onClick(int col, int row) {
	controller->onClick(row, col);
}
void TabletView::onDrag(int col, int row) {
	controller->onDrag(row, col);
}
void TabletView::onRelease(int col, int row) {
	controller->onRelease(row, col);
}


void TabletView::draw() {
	tablet.update();
	ColorField &f = tablet.getColorField();
	for (int row = 0; row< ROWS; row++ ){
		for (int col= 0; col< COLS; col++ ){
			unsigned char r=0,g=0,b=0;
			for (int level = 0; level < LEVELS; level++ ){
				r+= f[level][row][col][0];
				g+= f[level][row][col][1];
				b+= f[level][row][col][2];
			}
			fl_color(r,g,b);
			fl_rectf( 
				row*BLOCK_SIZE, 
				col*BLOCK_SIZE, 
				BLOCK_SIZE, 
				BLOCK_SIZE
			);
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
	return (0);
}

void TabletView::timeout_cb(TabletView *bw) {
	bw->redraw();
	Fl::repeat_timeout(DRAW_TIME, (Fl_Timeout_Handler)timeout_cb, (void *)bw);
}

