#include "TabletController.h"
#include "TabletView.h"
#include "TabletModel.h"
TabletController::TabletController(TabletView * view)
	:model(new TabletModel()),
	view(view){
		view->setModel(model);
		view->setController(this);
	}
TabletController::~TabletController(){
	delete model;
	delete view;
}
void TabletController::start(){
	view->start();
}
void TabletController::stop(){
	view->stop();
}
bool TabletController::onClick(int col, int row){
	vector<Component*> components = model->getSelectedPage().getComponentsAt(Pos(col, row));
	for(vector<Component*>::iterator i = components.begin();
			i != components.end();
			i++){
		return (*i)->onClick(Pos(col, row));
	}
	return false;
}
bool TabletController::onDoubleClick(int col, int row){
	return false;
}
bool TabletController::onRelease(int col, int row){
	vector<Component*> components = model->getSelectedPage().getComponentsAt(Pos(col, row));
	for(vector<Component*>::iterator i = components.begin();
			i != components.end();
			i++){
		return (*i)->onRelease(Pos(col, row));
	}
	return false;
}
bool TabletController::onDrag(int col, int row){
	vector<Component*> components = model->getSelectedPage().getComponentsAt(Pos(col, row));
	for(vector<Component*>::iterator i = components.begin();
			i != components.end();
			i++){
		return (*i)->onDrag(Pos(col, row));
	}
	return false;
}
