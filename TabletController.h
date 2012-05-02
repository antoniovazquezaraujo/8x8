#ifndef TABLET_CONTROLLER_H
#define TABLET_CONTROLLER_H
#include "TabletView.h"
class TabletController{
public:
	TabletController();
	void setup();
	void start();
	void end();
	void onClick(int row, int col);
	void onRelease(int row, int col);
	void onDrag(int row, int col);
private:
	Tablet tablet;
	TabletView * view;
};
#endif
