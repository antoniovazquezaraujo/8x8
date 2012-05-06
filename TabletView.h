#ifndef TABLET_VIEW_H
#define TABLET_VIEW_H
class TabletView{
	void start(){

	}
	void stop(){

	}
	void setModel(TabletModel * model){
		this->model = model;
	}		
	void setController(TabletController controller){
		this->controller = controller;
	}
private:
	TabletModel * model;
	TabletController * controller;
};
#endif
