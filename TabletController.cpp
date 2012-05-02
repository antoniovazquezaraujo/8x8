#include "TabletController.h"
TabletController::TabletController()
	:view(new TabletView(tablet, this)){

}
void TabletController::setup(){
	for (int col = 0; col < COLS; col++) {
		for (int row = 0; row < ROWS; row++) {
			tablet.addBox(0, col, row, 1, 1);
			tablet.lastBox(0).setColor(col*32, 32, 16);
		}
	}
}
void TabletController::start(){
	Moblet::run(view);

}
void TabletController::end(){

}
void TabletController::onClick(int col, int row){
	tablet.addBox(1, col,row, 1, 1);
	tablet.lastBox(1).setColor(0,0,0);
	unsigned char r    = rand()%255;
	unsigned char g    = rand()%255; 
	unsigned char b    = rand()%255; 
	unsigned char x    = rand()%255; 
	int time = 10 + rand()%200; 
	tablet.lastBox(1).addAnimation(r,x,g,x,b,x,time);
	tablet.lastBox(1).start();
}
void TabletController::onRelease(int col, int row){

}
void TabletController::onDrag(int col, int row){

}
