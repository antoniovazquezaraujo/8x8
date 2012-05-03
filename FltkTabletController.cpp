#include "FltkTabletController.h"
FltkTabletController::FltkTabletController()
	:view(new FltkTabletView(tablet, this)){
	Fl::scheme("plastic");
	Fl::visible_focus(0);
	//provisional
	rect=0;
}
void FltkTabletController::setup(){
	return;
	for (int col = 0; col < COLS; col++) {
		for (int row = 0; row < ROWS; row++) {
			tablet.addBox(0, col, row, 1, 1);
			tablet.lastBox(0).setColor(col*32, 32, 16);
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
	tablet.drawRect(1,*rect, color, false);
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
	tablet.drawRect(1,*rect, Color(0,0,0), false);
	rect->width = col- rect->col;
	rect->height= row - rect->row;
	if(rect->width<0) rect->width=0;
	if(rect->height<0) rect->height=0;
	tablet.drawRect(1,*rect, color, false);
}
