#include "ColorChooser.h"
#include <iostream>  

ColorChooser::ColorChooser(int x, int y, int w, int h)
	:Container(Pos(x,y), Size(w,h), Color(100,10,100)) 
	,actualColor(Color(100,100,100)){

	redInc = new Button(0,0,1,1);
	redInc->setColor(Color(255,0,0));
	redInc->addListener(this);
	add(redInc);

	redDec = new Button(0,1,1,1);
	redDec->setColor(Color(255,0,0));
	redDec->addListener(this);
	add(redDec);

	greenInc = new Button(1,0,1,1);
	greenInc->setColor(Color(0, 255,0));
	greenInc->addListener(this);
	add(greenInc);

	greenDec = new Button(1,1,1,1);
	greenDec->setColor(Color(0, 255,0));
	greenDec->addListener(this);
	add(greenDec);

	blueInc = new Button(2,0,1,1);
	blueInc->setColor(Color(0,0,255));
	blueInc->addListener(this);
	add(blueInc);

	blueDec = new Button(2,1,1,1);
	blueDec->setColor(Color(0,0,255));
	blueDec->addListener(this);
	add(blueDec);


	cancel = new Button(0,2,1,1);
	cancel->setColor(Color(100,100,100));
	cancel->addListener(this);
	add(cancel);

	actual = new Button(1,2,1,1);
	actual->setColor(Color(100,100,100));
	add(actual);

	accept = new Button(2,2,1,1);
	accept->setColor(Color(200,200,200));
	accept->addListener(this);
	add(accept);
}
ColorChooser::~ColorChooser(){
}
bool ColorChooser::pressed(Component* c, Pos pos){
	// Cómo terminar esto???
	if(c == accept){
		return true;
	}
	if(c == cancel){
		return true;
	}
	ColorStep step;
	if      (c == redInc){
		step.r= 10;	
	}else if(c == redDec){
		step.r=-10;	
	}else if(c == greenInc){
		step.g= 10;	
	}else if(c == greenDec){
		step.g=-10;	
	}else if(c == blueInc){
		step.b= 10;	
	}else if(c == blueDec){
		step.b=-10;	
	}
	actualColor+=step;
	actual->setColor(actualColor);
	return true;
}
