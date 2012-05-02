#ifndef TABLET_CONTROLLER_H
#define TABLET_CONTROLLER_H
#include "FltkTabletView.h"
class FltkTabletController{
public:
	FltkTabletController();
	void setup();
	void start();
	void end();
	void onClick(int col, int row);
	void onRelease(int col, int row);
	void onDrag(int col, int row);
private:
	Tablet tablet;
	FltkTabletView * view;
};
#endif
