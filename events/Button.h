#ifndef BUTTON
#define BUTTON
#include "Component.h"
#include "EventListener.h"
class Button: public Component, public EventListener{
public:
	Button(int x=0, int y=0, int w=1, int h=1);
	~Button();
	bool pressed (Component* c, Pos pos);
	bool released (Component* c, Pos pos);
	Color pressedColor, releasedColor;
};
#endif
