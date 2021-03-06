#include "MoTabletController.h"
MoTabletController::MoTabletController()
	:view(new MoTabletView(model, this)){

}
void MoTabletController::setup(){
	for (int col = 0; col < COLS; col++) {
		for (int row = 0; row < ROWS; row++) {
			model.addBox(0, col, row, 1, 1);
			model.lastBox(0).setColor(col*32, 32, 16);
		}
	}
}
void MoTabletController::start(){
	Moblet::run(view);

}
void MoTabletController::end(){

}
void MoTabletController::onClick(int col, int row){
}
void MoTabletController::onRelease(int col, int row){

}
void MoTabletController::onDrag(int col, int row){
	model.addBox(1, col,row, 1, 1);
	model.lastBox(1).setColor(0,0,0);
	unsigned char r    = rand()%255;
	unsigned char g    = rand()%255; 
	unsigned char b    = rand()%255; 
	unsigned char x    = rand()%255; 
	int time = 10 + rand()%200; 
	model.lastBox(1).addAnimation(r,x,g,x,b,x,time);
	model.lastBox(1).start();
}
