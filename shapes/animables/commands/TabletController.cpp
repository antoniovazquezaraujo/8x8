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
