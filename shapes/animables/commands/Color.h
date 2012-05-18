#ifndef COLOR
#define COLOR
#include "ColorStep.h"
class Color{
public:
	Color(const Color & color);
	Color(int r=0, int g=0, int b=0);
	ColorStep stepTo(const Color &c);
	void operator+=(const ColorStep & step);
	Color operator+(const Color &c)const;
	void approachTo(const Color &to, const ColorStep &step);
	int r,g,b;
};
bool operator==(const Color& a, const Color& b);
#endif
