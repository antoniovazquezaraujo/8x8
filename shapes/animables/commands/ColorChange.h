#ifndef COLOR_CHANGE
#define COLOR_CHANGE
#include "Change.h"
#include "Color.h"
class Form;
class ColorChange: public Change{
public:
	ColorChange(Color from, Color to, int speed, int repeats);
	ColorChange(ColorStep step, int speed, int repeats);
	bool isCompleted();	
	void update(Form * f);
private:
	void resetData();
	Color from, to, actual;
	ColorStep step;
	bool isRelative;
};
#endif
