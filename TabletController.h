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
	virtual bool onClick(int col, int row);
	virtual bool onDoubleClick(int col, int row);
	virtual bool onRelease(int col, int row);
	virtual bool onDrag(int col, int row);
protected:
	TabletModel* model;
	TabletView * view;
};
#endif
