#include "ColorChooser.h"
#include <iostream>  

ColorChooser::ColorChooser(int x, int y, int w, int h)
	:Container(Pos(x,y), Size(w,h), Color(100,10,100,255)) 
	,actualColor(Color(100,100,100,255)){


	redInc = new Button(0,0,1,1);
	redInc->setColor(Color(255,0,0,255));
	redInc->addListener(this);
	add(redInc);

	redDec = new Button(0,1,1,1);
	redDec->setColor(Color(255,0,0,255));
	redDec->addListener(this);
	add(redDec);

	greenInc = new Button(1,0,1,1);
	greenInc->setColor(Color(0, 255,0,255));
	greenInc->addListener(this);
	add(greenInc);

	greenDec = new Button(1,1,1,1);
	greenDec->setColor(Color(0, 255,0,255));
	greenDec->addListener(this);
	add(greenDec);

	blueInc = new Button(2,0,1,1);
	blueInc->setColor(Color(0,0,255,255));
	blueInc->addListener(this);
	add(blueInc);

	blueDec = new Button(2,1,1,1);
	blueDec->setColor(Color(0,0,255,255));
	blueDec->addListener(this);
	add(blueDec);


	cancel = new Button(0,2,1,1);
	cancel->setColor(Color(100,100,100,255));
	cancel->addListener(this);
	add(cancel);

	actual = new Button(1,2,1,1);
	actual->setColor(Color(100,100,100,255));
	add(actual);

	accept = new Button(2,2,1,1);
	accept->setColor(Color(200,200,200,255));
	accept->addListener(this);
	add(accept);
}
ColorChooser::~ColorChooser(){
}
void ColorChooser::setActualColor(const Color & c){
	actualColor = c;
	actual->setColor(c);
}
//interfaz EventListener:
bool ColorChooser::pressed       (Component* c, Pos pos){
	return true;
}
bool ColorChooser::released      (Component* c, Pos pos){
	if      (c == accept){
		for(ColorChooserListener * l: listeners){
			l->accepted(this);
		}
	}else if(c == cancel){
		for(ColorChooserListener * l: listeners){
			l->canceled(this);
		}
	}
	/*
	   Muy primitivo. Se puede hacer mediante drags con 
	   la mitad de botones y más ágil. Queda pendiente!
	*/
	ColorStep step;
	if      (c == redInc){
		step.r+=10;
	}else if(c == greenInc){
		step.g+=10;
	}else if(c == blueInc){
		step.b+=10;
	}else if(c == redDec){
		step.r-=10;
	}else if(c == greenDec){
		step.g-=10;
	}else if(c == blueDec){
		step.b-=10;
	}
	actualColor+=step;
	actual->setColor(actualColor);
	return true;
}
bool ColorChooser::clicked       (Component* c, Pos pos){
	return true;
}
bool ColorChooser::doubleClicked (Component* c, Pos pos){
	return false;
}
bool ColorChooser::dragged       (Component* c, Pos pos){
	return true;

}
void ColorChooser::addColorChooserListener(ColorChooserListener * l){
	listeners.push_back(l);
}
