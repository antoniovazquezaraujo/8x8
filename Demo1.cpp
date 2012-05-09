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
	int apagado = 10;
	model->addBox(0, 0,0, 2,2, true);
	model->lastBox(0).setColor(0,100,0);

	model->addBox(1, 0,0, 1,1, true);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).addColorChange(100,100,100,100,100,100,5);
	model->lastBox(1).addColorChange(100,100,100,100,100,100,5);
	model->lastBox(1).addColorChange(100,100,100,100,100,100,5);
	model->lastBox(1).addColorChange(100,100,100,100,100,100,5);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 1,0, 1,1, true);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).addColorChange(100,100,100,100,100,100,5);
	model->lastBox(1).addColorChange(100,100,100,100,100,100,5);
	model->lastBox(1).addColorChange(100,100,100,100,100,100,5);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 1,1, 1,1, true);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).addColorChange(100,100,100,100,100,100,5);
	model->lastBox(1).addColorChange(100,100,100,100,100,100,5);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 0,1, 1,1, true);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).addColorChange(100,100,100,100,100,100,5);
	model->lastBox(1).startColorChanges();
/////////////////////////////////////////////////////////
	model->addBox(0, 2,0, 2,2, true);
	model->lastBox(0).setColor(100,0,0);

	model->addBox(1, 2,0, 1,1, true);
	model->lastBox(1).addColorChange(120,120,120,120,120,120,5);
	model->lastBox(1).addColorChange(120,120,120,120,120,120,5);
	model->lastBox(1).addColorChange(120,120,120,120,120,120,5);
	model->lastBox(1).addColorChange(120,120,120,120,120,120,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 3,0, 1,1, true);
	model->lastBox(1).addColorChange(120,120,120,120,120,120,5);
	model->lastBox(1).addColorChange(120,120,120,120,120,120,5);
	model->lastBox(1).addColorChange(120,120,120,120,120,120,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 3,1, 1,1, true);
	model->lastBox(1).addColorChange(120,120,120,120,120,120,5);
	model->lastBox(1).addColorChange(120,120,120,120,120,120,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 2,1, 1,1, true);
	model->lastBox(1).addColorChange(120,120,120,120,120,120,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).startColorChanges();
/////////////////////////////////////////////////////////
	model->addBox(0, 4,0, 2,2, true);
	model->lastBox(0).setColor(0,0,100);

	model->addBox(1, 4,0, 1,1, true);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 5,0, 1,1, true);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 5,1, 1,1, true);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 4,1, 1,1, true);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(140,140,140,140,140,140,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,apagado);
	model->lastBox(1).startColorChanges();
/////////////////////////////////////////////////////////
	model->addBox(0, 6,0, 2,2, true);
	model->lastBox(0).setColor(100,100,0);
	int todos = 10;

	model->addBox(1, 6,0, 1,1, true);
	model->lastBox(1).addColorChange(160,160,160,160,160,160,todos);
	model->lastBox(1).addColorChange(160,160,160,160,160,160,5);
	model->lastBox(1).addColorChange(160,160,160,160,160,160,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 7,0, 1,1, true);
	model->lastBox(1).addColorChange(160,160,160,160,160,160,todos);
	model->lastBox(1).addColorChange(160,160,160,160,160,160,5);
	model->lastBox(1).addColorChange(160,160,160,160,160,160,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 7,1, 1,1, true);
	model->lastBox(1).addColorChange(160,160,160,160,160,160,todos);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).startColorChanges();

	model->addBox(1, 6,1, 1,1, true);
	model->lastBox(1).addColorChange(160,160,160,160,160,160,todos);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).addColorChange(  0,  0,0,0,0,0,5);
	model->lastBox(1).startColorChanges();
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
