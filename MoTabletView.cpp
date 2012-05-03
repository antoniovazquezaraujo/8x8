#include "MoTabletView.h" 
#include "MoTabletController.h" 

MoTabletView::MoTabletView(TabletModel & model, MoTabletController * controller)
	:model(model),
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
	model.update();
	ColorField &f = model.getColorField();
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
	int x = p.x/blockSize;
	int y = p.y/blockSize;
	if(x >= COLS) x = COLS -1;
	if(y >= ROWS) y = ROWS -1;
	
	controller->onClick(x,y);
}
void MoTabletView::pointerMoveEvent(MAPoint2d p) {
	int x = p.x/blockSize;
	int y = p.y/blockSize;
	if(x >= COLS) x = COLS -1;
	if(y >= ROWS) y = ROWS -1;
	controller->onDrag(x,y);
}
void MoTabletView::pointerReleaseEvent(MAPoint2d p) {
	int x = p.x/blockSize;
	int y = p.y/blockSize;
	if(x >= COLS) x = COLS -1;
	if(y >= ROWS) y = ROWS -1;
	controller->onRelease(x,y);
}



