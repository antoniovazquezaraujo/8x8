#include "FltkTabletView.h" 
#include "FltkTabletController.h" 

FltkTabletView::FltkTabletView(TabletModel & model, FltkTabletController * controller)
	: Fl_Double_Window(20,20,640,640,"8x8"),
	model(model),
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
	controller->onClick(col, row);
}
void FltkTabletView::onDrag(int col, int row) {
	controller->onDrag(col, row);
}
void FltkTabletView::onRelease(int col, int row) {
	controller->onRelease(col, row);
}


void FltkTabletView::draw() {
	model.update();
	ColorField &f = model.getColorField();
	for (int col= 0; col< COLS; col++ ){
		for (int row = 0; row< ROWS; row++ ){
			unsigned char r=0,g=0,b=0;
			for (int level = 0; level < LEVELS; level++ ){
				r+= f[level][col][row].r;
				g+= f[level][col][row].g;
				b+= f[level][col][row].b;
			}
			fl_color(r,g,b);
			fl_rectf( 
				col*BLOCK_SIZE, 
				row*BLOCK_SIZE, 
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
	if(col >= COLS) col=COLS-1;
	if(row >= ROWS) row=ROWS-1;
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

