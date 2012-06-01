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
	imagen     = new Container(Pos(0,0),Size(8,8),Color(10,10,10, 255));
	chooserBack= new Container(Pos(0,0),Size(8,8),Color(0,0,0, 150));
	model->getSelectedPage().addComponent("imagen", 0, imagen);
	chooser = new ColorChooser(0,0,3,3);
	chooser->addColorChooserListener(this);
	editing = false;
}
void Prueba1::start(){
	view->start();
}
void Prueba1::stop(){
	view->stop();
}
bool Prueba1::onClick(int col, int row){
	lastPos=Pos(col, row);
	if(!TabletController::onClick(col, row)){
	}
	return true;
}
bool Prueba1::onRelease(int col, int row){
	if(!TabletController::onRelease(col, row)){
		if(lastPos == Pos(col, row)){
			if(!editing){
				editing=true;
				Component * clicked = imagen->getComponentAt(Pos(col, row));
				if(clicked){
					chooser->setActualColor(clicked->getColor());
				}
				model->getSelectedPage().addComponent("chooserBack", 1, chooserBack);
				model->getSelectedPage().addComponent("chooser", 2, chooser);
			}
		}
	}
	return true;
}
bool Prueba1::onDrag(int col, int row){
	if(!TabletController::onDrag(col, row)){
		Component * clicked = imagen->getComponentAt(Pos(col,row));
		if(!clicked){
			clicked = new Button(col, row, 1,1);
			imagen->add(clicked);
		}
		clicked->setColor(actualColor);
	}
	return true;
}
void Prueba1::accepted(ColorChooser *){
	editing=false;
	actualColor = chooser->actualColor;
	model->getSelectedPage().removeComponent("chooser");
	model->getSelectedPage().removeComponent("chooserBack");
}
void Prueba1::canceled(ColorChooser *){
	editing=false;
	model->getSelectedPage().removeComponent("chooser");
	model->getSelectedPage().removeComponent("chooserBack");
}
