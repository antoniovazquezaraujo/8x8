#ifndef COLOR
#define COLOR
#include "ColorStep.h"
class Color{
public:
	Color(const Color & color);
	Color(int r=0, int g=0, int b=0);
	ColorStep stepTo(Color c);
	void operator+=(ColorStep step);
	void approachTo(Color to, ColorStep step);
	int r,g,b;
};
bool operator==(const Color& a, const Color& b){
	return((a.r==b.r) && (a.g==b.g) && (a.b==b.b));
}
#endif
