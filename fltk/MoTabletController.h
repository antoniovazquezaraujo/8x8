#ifndef MO_TABLET_CONTROLLER_H
#define MO_TABLET_CONTROLLER_H
#include "MoTabletView.h"
class MoTabletController{
public:
	MoTabletController();
	void setup();
	void start();
	void end();
	void onClick(int col, int row);
	void onRelease(int col, int row);
	void onDrag(int col, int row);
private:
	Tablet model;
	MoTabletView * view;
};
#endif
