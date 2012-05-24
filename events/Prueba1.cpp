#include "Prueba1.h"
#include "TabletModel.h"
#include "TabletController.h"
#include <cassert> 
#include <iostream> 
#include "TabletView.h"
Prueba1::Prueba1(TabletView * view)
	:TabletController(view){

}
void Prueba1::setup(){
	model->newPage("inicio");
	model->selectPage(FIRST);
	model->getSelectedPage().addComponent("pulsar", 0, new Button(3,3,1,2));
	model->getSelectedPage().addComponent("otro", 0, new Button(2,1,3,1));
	/*
	Component * z = new Button(0,0,1,1);
	Command * cp = new Command();
	cp->addChange(ColorChange(Color(1,1,1), Color(0,200,0), ColorStep(0,10,0)));
	z->commands.push_back(cp);
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
