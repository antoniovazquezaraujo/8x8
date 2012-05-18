#ifndef SIZE
#define SIZE
#include "SizeStep.h"
class Size{
public:
	Size(int w=0, int h=0);
	SizeStep stepTo(Size s);
	void operator+=(SizeStep step);
	Size operator+(const Size & size)const;
	Size operator*(const Size & size)const;
	void approachTo(Size to, SizeStep step);
	int w,h;
};
bool operator==(const Size & p, const Size & q);
#endif
