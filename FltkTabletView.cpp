#include "FltkTabletView.h" 
#include "FltkTabletController.h" 

FltkTabletView::FltkTabletView(Tablet & tablet, FltkTabletController * controller)
	: Fl_Double_Window(20,20,640,640,"8x8"),
	tablet(tablet),
	controller(controller){
	end();
	setup();
}

FltkTabletView::~FltkTabletView() {
	Fl::remove_timeout((Fl_Timeout_Handler)timeout_cb, (void *)this);
}

void FltkTabletView::setup() {
	Fl::add_timeout(DRAW_TIME, (Fl_Timeout_Handler)timeout_cb, (void *)this);
	srand(time(NULL));
	redraw();
}

void FltkTabletView::onClick(int col, int row) {
	controller->onClick(row, col);
}
void FltkTabletView::onDrag(int col, int row) {
	controller->onDrag(row, col);
}
void FltkTabletView::onRelease(int col, int row) {
	controller->onRelease(row, col);
}


void FltkTabletView::draw() {
	tablet.update();
	ColorField &f = tablet.getColorField();
	for (int col= 0; col< COLS; col++ ){
		for (int row = 0; row< ROWS; row++ ){
			unsigned char r=0,g=0,b=0;
			for (int level = 0; level < LEVELS; level++ ){
				r+= f[level][col][row][0];
				g+= f[level][col][row][1];
				b+= f[level][col][row][2];
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

int FltkTabletView::handle(int event) {
	if (Fl_Double_Window::handle(event)){
		return (1);
	} 
	int col = Fl::event_x() / BLOCK_SIZE;
	int row = Fl::event_y() / BLOCK_SIZE;
	switch (event) {
	case FL_PUSH :
		onClick(col, row);
		break;
	case FL_DRAG:
		onDrag(col, row);
		break;
	case FL_RELEASE:
		onRelease(col, row);
		break;
	}
	return (0);
}

void FltkTabletView::timeout_cb(FltkTabletView *bw) {
	bw->redraw();
	Fl::repeat_timeout(DRAW_TIME, (Fl_Timeout_Handler)timeout_cb, (void *)bw);
}

