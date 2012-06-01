#ifndef COLOR_CHOOSER
#define COLOR_CHOOSER
#include "Container.h"
#include "Button.h"
#include "EventListener.h"
#include "ColorChooserListener.h"
class ColorChooser: public Container, public EventListener{
public:
	ColorChooser(int x=0, int y=0, int w=1, int h=1);
	~ColorChooser();
	void setActualColor(const Color & c);
	void addColorChooserListener(ColorChooserListener * c);
	bool pressed       (Component* c, Pos pos);
	bool released      (Component* c, Pos pos);
	bool clicked       (Component* c, Pos pos);
	bool doubleClicked (Component* c, Pos pos);
	bool dragged       (Component* c, Pos pos);
	Color actualColor;
	Button * redInc, *redDec;
	Button * greenInc, *greenDec;
	Button * blueInc, *blueDec;
	Button * accept,  *cancel;
	Button * actual; 
	vector<ColorChooserListener*> listeners;
};
#endif
