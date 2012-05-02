#include "MoTabletView.h" 
#include "MoTabletController.h" 

MoTabletView::MoTabletView(Tablet & tablet, MoTabletController * controller)
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

MoTabletView::~MoTabletView() {

}




void MoTabletView::runTimerEvent() {
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
void MoTabletView::keyPressEvent(int keyCode, int nativeCode) {
	switch(keyCode) {
		case MAK_FIRE:
			break;
		case MAK_SOFTRIGHT:
		case MAK_0:
		case MAK_BACK:
			maExit(0);
		default:
			break;
	}
}
void MoTabletView::pointerPressEvent(MAPoint2d p) {
	controller->onClick(p.x/blockSize, p.y/blockSize);
}
void MoTabletView::pointerMoveEvent(MAPoint2d p) {
	controller->onDrag(p.x/blockSize, p.y/blockSize);
}
void MoTabletView::pointerReleaseEvent(MAPoint2d p) {
	controller->onRelease(p.x/blockSize, p.y/blockSize);
}



