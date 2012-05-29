#ifndef BUTTON
#define BUTTON
#include "Component.h"
#include "EventListener.h"
class Button: public Component{
public:
	Button(const Pos& pos, const Size& size, const Color & color);
	Button(int x=0, int y=0, int w=1, int h=1);
	~Button();
	Color pressedColor, releasedColor;
};
#endif
