#include "TabletView.h" 
#include "TabletController.h" 

TabletView::TabletView(Tablet & tablet, TabletController * controller)
	:tablet(tablet),
	controller(controller){
	MAExtent scrSize = maGetScrSize();
	screenWidth = EXTENT_X(scrSize);
	screenHeight = EXTENT_Y(scrSize);
	blockSize = screenWidth<screenHeight?screenWidth/COLS:screenHeight/COLS;
	addTimer(this, TIMER_PERIOD, 0);

	maSetColor(0);
	maFillRect(0, 0, screenWidth, screenHeight);
	maUpdateScreen();
}

TabletView::~TabletView() {

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



void TabletView::runTimerEvent() {
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
			maSetColor((r<<16)|(g<<8)|b);
			maFillRect(
					col*blockSize,
					row*blockSize,
					blockSize,
					blockSize);

		}
	}
	maUpdateScreen();
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
}
void TabletView::pointerPressEvent(MAPoint2d p) {
	controller->onClick(p.x/blockSize, p.y/blockSize);
}
void TabletView::pointerMoveEvent(MAPoint2d p) {
	controller->onDrag(p.x/blockSize, p.y/blockSize);
}
void TabletView::pointerReleaseEvent(MAPoint2d p) {
	controller->onRelease(p.x/blockSize, p.y/blockSize);
}



