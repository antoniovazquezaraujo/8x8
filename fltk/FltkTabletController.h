#ifndef TABLET_CONTROLLER_H
#define TABLET_CONTROLLER_H
#include "TabletView.h"
#include "TabletController.h"
class Prueba1 :public TabletController{
public:
	Prueba1();
	void setup();
	void start();
	void end();
	void onClick(int col, int row);
	void onRelease(int col, int row);
	void onDrag(int col, int row);
private:
//Provisional...
	Box * box;
	Color color;
};
#endif
