#include "Prueba1.h"
#include "TabletModel.h"
#include "TabletController.h"
#include <cassert> 
#include "TabletView.h"
#include "ColorChooser.h"
Prueba1::Prueba1(TabletView * view)
	:TabletController(view){

}
void Prueba1::setup(){
	Command::test();
	model->newPage("inicio");
	model->selectPage(FIRST);
	//model->getSelectedPage().addComponent("pulsar", 0, new Button(3,3,1,2));
	//model->getSelectedPage().addComponent("otro", 0, new Button(2,1,3,1));
	model->getSelectedPage().addComponent("chooser", 0, new ColorChooser(3,1,3,3));

	/*
	Component * z = new Button(0,0,1,1);
	Component & c = *z;
	c("pruebas", 10000);
		c(Color(1,0,1), Color(1,200,1), ColorStep(0,1,0), 3);
	c("pruebas2", 7000);
		c(Color(100,0,200), Color(0,200,0), ColorStep(-10,10,-20), 1);
		//c(Pos(1,0), Pos(7,2), PosStep(1,1), 5);
	c.on("pruebas", "pruebas2");
	c.on("pruebas2", "pruebas");
	c.go("pruebas");
	model->getSelectedPage().addComponent("otro", 0, z);
	*/
}
void Prueba1::start(){
	view->start();
}
void Prueba1::stop(){
	view->stop();
}
void Prueba1::onClick(int col, int row){
	vector<Component*> components = model->getSelectedPage().getComponentsAt(Pos(col, row));
	for(vector<Component*>::iterator i = components.begin();
			i != components.end();
			i++){
		(*i)->onClick(Pos(col, row));
	}
}
void Prueba1::onDoubleClick(int col, int row){
}
void Prueba1::onRelease(int col, int row){
}
void Prueba1::onDrag(int col, int row){
}
