#include "TabletView.h"
#include "TabletModel.h"
#include "TabletController.h"
void TabletView::setModel(TabletModel * model){
	this->model = model;
}		
void TabletView::setController(TabletController *controller){
	this->controller = controller;
}
