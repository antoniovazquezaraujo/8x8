#include "Button.h"
Button::Button(int x, int y, int w, int h)
	:Component(Pos(x,y), Size(w,h), Color(253,2,3)) 
	,pressedColor(Color(0,233,0))
	,releasedColor(Color(1,1,255)){
		 addListener(this);

}
Button::~Button(){

}
bool Button::pressed (Component* c, Pos pos){
	color = pressedColor;
	return true;
}
bool Button::released (Component* c, Pos pos){
	color = releasedColor;
	return true;
}
