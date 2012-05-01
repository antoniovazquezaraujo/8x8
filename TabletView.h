#ifndef TABLET_VIEW_H
#define TABLET_VIEW_H
class TabletModel;
class TabletController;
class TabletView{
public:
	virtual void start()=0;
	virtual void stop() =0;
	void setModel(TabletModel * model);
	void setController(TabletController *controller);
protected:
	TabletModel      * model;
	TabletController * controller;
};
#endif
