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
	model->addBox(0, 0,1, 1,1, true);
	model->lastBox(0).setColor(120,120,120);
	model->lastBox(0).addColorChange(40,60,40,60,40,60,100);
	model->lastBox(0).addColorChange(60,40,60,40,60,40,100);
	model->lastBox(0).startColorChanges();
	model->addBox(0, 1,1, 1,1, true);
	model->lastBox(0).setColor(120,120,120);
	model->addBox(0, 2,1, 1,1, true);
	model->lastBox(0).setColor(140,140,140);
	model->addBox(0, 3,1, 1,1, true);
	model->lastBox(0).setColor(140,140,140);
	model->addBox(0, 0,2, 1,1, true);
	model->lastBox(0).setColor(160,160,160);
	model->addBox(0, 1,3, 1,1, true);
	model->lastBox(0).setColor(160,160,160);
	model->addBox(0, 2,2, 1,1, true);
	model->lastBox(0).setColor(190,190,190);
	model->addBox(0, 3,3, 1,1, true);
	model->lastBox(0).setColor(190,190,190);

	model->addBox(1, 0,0, 1,1, true);
	model->lastBox(1).setColor(  0,155,  0);
	model->addBox(1, 1,0, 1,1, true);
	model->lastBox(1).setColor(0,  255,  0);
	model->addBox(1, 2,0, 1,1, true);
	model->lastBox(1).setColor(  0,255,  0);
	model->addBox(1, 3,0, 1,1, true);
	model->lastBox(1).setColor(  0,155,  0);

	model->addBox(1, 0,3, 1,1, true);
	model->lastBox(1).setColor(  0,155,  0);
	model->addBox(1, 1,2, 1,1, true);
	model->lastBox(1).setColor(0,  255,  0);
	model->addBox(1, 2,3, 1,1, true);
	model->lastBox(1).setColor(0,  255,  0);
	model->addBox(1, 3,2, 1,1, true);
	model->lastBox(1).setColor(  0,155,  0);

}
void Demo1::start(){
	view->start();
}
void Demo1::stop(){
	view->stop();
}
void Demo1::onClick(int col, int row){
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
