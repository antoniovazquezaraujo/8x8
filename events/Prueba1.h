#ifndef  PRUEBA1_H
#define  PRUEBA1_H 
#include "TabletController.h"
#include "Color.h"
#include "Size.h"
#include "Pos.h"
#include "Page.h"
#include "Button.h"
#include "TabletModel.h"
#include "Command.h"
#include <vector> 
#include <stdlib.h>
#include <map>
#include <iostream>
using namespace std;
class TabletView;
class Color;
class Prueba1 :public TabletController{
public:
	Prueba1(TabletView * view);
	void setup();
	void start();
	void stop();
	void onClick(int col, int row);
	void onDoubleClick(int col, int row);
	void onRelease(int col, int row);
	void onDrag(int col, int row);
private:
};
#endif
