#include "FltkTabletController.h"
FltkTabletController::FltkTabletController()
	:view(new FltkTabletView(model, this)){
	Fl::scheme("plastic");
	Fl::visible_focus(0);
}
void FltkTabletController::setup(){
	for(int col =0; col <COLS; col++){
		for(int row = 0; row < ROWS; row++){ 
			model.addBox(0, col, row, 1,1,true);
			model.lastBox(0).addColorChange(     0, col*32,    128,      0,      0,      0, 100);
			model.lastBox(0).addColorChange(col*32, col*32,      0, row*32,      0,      0, 100);
			model.lastBox(0).addColorChange(col*32,      0, row*32,    128,      0, col*32, 100);
			model.lastBox(0).addColorChange(     0, col*32,      0, row*32, col*32, row*32, 100);
			model.lastBox(0).addColorChange(col*32, col*32, row*32,      0, col*32,    128, 100);
			model.lastBox(0).startColorChanges();
		}
	}
}
void FltkTabletController::start(){
	view->show();
	(Fl::run());
}
void FltkTabletController::end(){

}
void FltkTabletController::onClick(int col, int row){
	static bool added = false;
	if(!added){
		model.addBox(1, col, row, 1,1,true);
		model.lastBox(1).setColor(64,64,64);
		model.lastBox(1).addColorChange(255,155,  0,155,100, 40,100);
		model.lastBox(1).addColorChange(155,  0,155,255, 40,  0,100);
		model.lastBox(1).addColorChange(0,   50,255, 25,  0, 50,100);
		model.lastBox(1).addColorChange(50, 255, 25,  0, 50,100,100);
		model.lastBox(1).startColorChanges();
		//added=true;
	}
	model.lastBox(1).setPos(Rect(col,row));
}
void FltkTabletController::onRelease(int col, int row){
}
void FltkTabletController::onDrag(int col, int row){
	Rect pos = model.lastBox(1).getPos();
	model.lastBox(1).setSize(col-pos.col+1, row-pos.row+1);
}
