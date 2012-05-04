#include "FltkTabletController.h"
FltkTabletController::FltkTabletController()
	:view(new FltkTabletView(model, this)){
	Fl::scheme("plastic");
	Fl::visible_focus(0);
	//provisional
		rect=0;
}
void FltkTabletController::setup(){
	return;
	for (int col = 0; col < COLS; col++) {
		for (int row = 0; row < ROWS; row++) {
			model.addBox(0, col, row, 1, 1);
			model.lastBox(0).setColor(col*32, 32, 16);
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
	if(rect){
		return;
	}
	rect = new Rect(col, row,0,0);
	color.rnd();
	model.drawRect(0,*rect, color, false);

	model.addBox(1,col,row, 1,1, false);
	model.lastBox(1).setColor(255,255,255);
	model.lastBox(1).addColorChange(255,255,255,0,255,255,8);
	model.lastBox(1).addColorChange(255,255,0,255,255,255,8);

	model.lastBox(1).addPosChange(-1,  -1, 1, 1);
	model.lastBox(1).addSizeChange(+2, +2, 1, 1);
	model.lastBox(1).addPosChange(+1,  +1, 1, 1);
	model.lastBox(1).addSizeChange(-2, -2, 1, 1);

	model.lastBox(1).startPosChanges();
	model.lastBox(1).startColorChanges(1);
	model.lastBox(1).startSizeChanges();
}
void FltkTabletController::onRelease(int col, int row){
	if(rect){
		delete rect;
		rect=0;
	}
}
void FltkTabletController::onDrag(int col, int row){
	static int lastCol=-1, lastRow=-1;
	if(lastCol == col && lastRow == row){
		return;
	}
	lastCol = col;
	lastRow = row;
	if(!rect){
		return;
	}
	if(rect->col == col && rect->row == row){
		return;
	}
	model.drawRect(0,*rect, Color(0,0,0), false);
	rect->width = col- rect->col;
	rect->height= row - rect->row;
	if(rect->width<0) rect->width=0;
	if(rect->height<0) rect->height=0;
	model.drawRect(0,*rect, color, false);
}
