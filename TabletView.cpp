#include "TabletView.h" 

TabletView::TabletView(Tablet & tablet)
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
	tablet.addBox(1, row/80, col/80, 1, 1);
	tablet.lastBox(1).setColor(0,0,0);
	int r    = rand()%255;
	int x    = 0; 
	tablet.lastBox(1).addAnimation(125,150,0,0,0,0,15);
	tablet.lastBox(1).addAnimation(185,150,100,100,0,0,15);
	tablet.lastBox(1).start();
}
void TabletView::onDrag(int col, int row) {
}
void TabletView::onRelease(int col, int row) {
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
	int col =  Fl::event_x() + BLOCK_SIZE;
	int row =  Fl::event_y() + BLOCK_SIZE;
	switch (event) {
	case FL_PUSH :
		onClick(row, col);
		break;
	case FL_DRAG:
		onDrag(row, col);
		break;
	case FL_RELEASE:
		onRelease(row, col);
		break;
	}
	return (0);
}

void TabletView::timeout_cb(TabletView *bw) {
	bw->redraw();
	Fl::repeat_timeout(DRAW_TIME, (Fl_Timeout_Handler)timeout_cb, (void *)bw);
}

