#ifndef COLOR_CHANGE
#define COLOR_CHANGE
#include "Change.h"
#include "Color.h"
class Form;
class ColorChange: public Change{
public:
	ColorChange(Color from, Color to, ColorStep step, int speed=1, int repeats=1);
	ColorChange(Color from=Color(), Color to=Color(), int speed=1, int repeats=1);
	ColorChange(ColorStep step=ColorStep(), int speed=1, int repeats=1);
	bool isCompleted();	
	void update(Form * f);
	void resetData();
private:
	Color from, to, actual;
	ColorStep step;
	bool isRelative;
};
#endif
