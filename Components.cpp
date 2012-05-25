#include "Color.h"
#include "Size.h"
#include "Pos.h"
#include "Page.h"
#include "Button.h"
#include "Prueba1.h"
#include "TabletModel.h"
#include "TabletModel.h"
#include "Command.h"
#include <vector> 
#include <stdlib.h>
#include <map>
#include <iostream>
#include "FltkTabletView.h"
using namespace std;

int main(){
	Prueba1 p(new FltkTabletView());
	p.setup();
	p.start();
}
