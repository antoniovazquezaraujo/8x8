#ifndef TABLET_CONTROLLER_H
#define TABLET_CONTROLLER_H
#include "TabletView.h"
class TabletController{
public:
	TabletController();
	void setup();
	void start();
	void end();
	void onClick(int col, int row);
	void onRelease(int col, int row);
	void onDrag(int col, int row);
private:
	Tablet tablet;
	TabletView * view;
};
#endif
