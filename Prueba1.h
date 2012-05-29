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
#include "Container.h"
#include "ColorChooserListener.h"
#include <vector> 
#include <stdlib.h>
#include <map>
#include <iostream>
using namespace std;
class TabletView;
class Color;
class Prueba1 :public TabletController, public ColorChooserListener{
public:
	Prueba1(TabletView * view);
	void setup();
	void start();
	void stop();
	void accepted(ColorChooser *);
	void canceled(ColorChooser *);

	bool onClick(int col, int row);
	bool onRelease(int col, int row);
	bool onDrag(int col, int row);
	ColorChooser * chooser;
	Container * imagen;
	bool editing;
	Pos lastPos;
	Color actualColor;
private:
};
#endif
