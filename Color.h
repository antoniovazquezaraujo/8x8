#ifndef COLOR
#define COLOR
#include "ColorStep.h"
class Color{
public:
	Color(const Color & color);
	Color(int r=0, int g=0, int b=0, int a=0);
	ColorStep stepTo(const Color &c);
	void operator+=(const ColorStep & step);
	Color operator+(const Color &c)const;
	void approachTo(const Color &to, const ColorStep &step);
	int r,g,b, a;
	//a es el canal alpha, para la transparencia:
	//Si vale 0 es transparente, y 255 opaco totalmente.
};
bool operator==(const Color& a, const Color& b);
#endif
