#ifndef  PRUEBA1_H
#define  PRUEBA1_H 
#include "TabletController.h"
class TabletView;
class Box; 
class Color;
class Prueba1 :public TabletController{
public:
	Prueba1(TabletView * view);
	void setup();
	void start();
	void stop();
	void onClick(int col, int row);
	void onRelease(int col, int row);
	void onDrag(int col, int row);
private:
//Provisional...
	Box * box;
	Color color;
};
#endif
