#ifndef COLOR_CHOOSER
#define COLOR_CHOOSER
#include "Container.h"
#include "Button.h"
#include "EventListener.h"
class ColorChooser: public Container, public EventListener{
public:
	ColorChooser(int x=0, int y=0, int w=1, int h=1);
	~ColorChooser();
	bool pressed(Component* c, Pos pos);
	Color actualColor;
	Button * redInc, *redDec;
	Button * greenInc, *greenDec;
	Button * blueInc, *blueDec;
	Button * accept,  *cancel;
	Button * actual; 
};
#endif
