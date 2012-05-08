#include "TabletModel.h"
#include "TabletView.h"
#include "TabletController.h"
#include "FltkTabletView.h"
class Demo1 :public TabletController{
public:
	Demo1(TabletView * view);
	void setup();
	void start();
	void stop();
	void onClick(int col, int row);
	void onRelease(int col, int row);
	void onDrag(int col, int row);
private:
	Box * box;
};
Demo1::Demo1(TabletView * view)
	:TabletController(view){

}
void Demo1::setup(){
	for(int col =0; col <COLS; col++){
		for(int row = 0; row < ROWS; row++){ 
			model->addBox(0, col, row, 1,1, false);
			model->lastBox(0).addColorChange(     0, col*32,    128,      0,      0,      0, 100);
			model->lastBox(0).addColorChange(col*32, col*32,      0, row*32,      0,      0, 100);
			model->lastBox(0).addColorChange(col*32,      0, row*32,    128,      0, col*32, 100);
			model->lastBox(0).addColorChange(     0, col*32,      0, row*32, col*32, row*32, 100);
			model->lastBox(0).addColorChange(col*32, col*32, row*32,      0, col*32,    128, 100);
			model->lastBox(0).startColorChanges();
		}
	}
}
void Demo1::start(){
	view->start();
}
void Demo1::stop(){
	view->stop();
}
void Demo1::onClick(int col, int row){
	static bool added = false;
	if(!added){
		model->addBox(1, col, 7, 1,1,false);
		model->lastBox(1).setColor(64,64,64);
		model->lastBox(1).addColorChange(255,  0,  0,  0,  0,  0,1);
		model->lastBox(1).addColorChange(  0,255,  0,  0,  0,  0,1);
		model->lastBox(1).startColorChanges();
		model->lastBox(1).addPosChange(0,  -1, 10, 7);
		model->lastBox(1).startPosChanges();
		added=true;
	}
	model->lastBox(1).setPos(Rect(col,7));
}
void Demo1::onRelease(int col, int row){
}
void Demo1::onDrag(int col, int row){
}
int main(){
	Demo1 p((new FltkTabletView()));
	p.setup();
	p.start();
}
