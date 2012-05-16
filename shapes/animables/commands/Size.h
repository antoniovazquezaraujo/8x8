#ifndef SIZE
#define SIZE
#include "SizeStep.h"
class Size{
public:
	Size(int w=0, int h=0);
	SizeStep stepTo(Size s);
	void operator+=(SizeStep step);
	void approachTo(Size to, SizeStep step);
	int w,h;
};
bool operator==(const Size & p, const Size & q){
	return ((p.w == q.w) && (p.h == q.h));
}
#endif
