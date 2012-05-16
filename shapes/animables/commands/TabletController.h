#ifndef TABLET_CONTROLLER_H
#define TABLET_CONTROLLER_H
class TabletView;
class TabletModel;
class TabletController{
public:
	TabletController(TabletView * view);
	~TabletController();
	void start();
	void stop();
	virtual void onClick(int col, int row)=0;
	virtual void onRelease(int col, int row)=0;
	virtual void onDrag(int col, int row)=0;
protected:
	TabletModel* model;
	TabletView * view;
};
#endif
