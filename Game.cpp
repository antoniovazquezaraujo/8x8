//Fichero Tablet.h
class TabletController{
public:
	TabletController(TabletView * view)
		view(view){
		view->setModel(model);
		view->setController(this);

	}
	void start();
	void stop();
	virtual void onClick(int col, int row)=0;
	virtual void onDoubleClick(int col, int row)=0;
	virtual void onRelease(int col, int row)=0;
	virtual void onDrag(int col, int row)=0;
private:
	TabletModel  model;
	TabletView * view;
};
class Packman: public TabletController{
public:
	void onClick(int col, int row){
		//Pac, pac, pac ...
	}
};
int main(){
	TabletController * t = new Packman((new FltkTabletView()));
	TabletController * t2= new Packman((new MoTabletView()));
	t.start();
	t2.start();
}
class FltkTabletController : public TabletController{
	FltkTablet()
	:Tablet(new FltkTabletView()){
	Fl::scheme("plastic");
	Fl::visible_focus(0);
};
class MoTabletController: public TabletController{
	MoTablet()
	:Tablet(new MoTabletView()){
	Fl::scheme("plastic");
	Fl::visible_focus(0);
};
//////////////////////////////// Programa ejemplo //////////////////////////////////////
#include "TabletListener.h"
#include "FltkTablet.h"
class MyGame: public TabletListener{
public:
	MyGame()
		:tablet(new FltkTablet(this)){ 
		setup();
	}
	~MyGame(){
		delete game;
	}
	void start(){
		game->start();
	}
	void setup(){

	}
	void onClick(int col, int row){

	}
	void onDoubleClick(int col, int row){

	}
	void onRelease(int col, int row){

	}
	void onDrag(int col, int row){

	}
private:
	Tablet * tablet;
};

int main(){
	MyGame g();
	g.start();
}
