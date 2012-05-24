#ifndef SIZE_CHANGE
#define SIZE_CHANGE
#include "Change.h"
#include "Size.h"
class Component;
class SizeChange: public Change{
public:
	SizeChange(Size from, Size to, SizeStep step, int repeats=1);
	SizeChange(Size from, Size to,                int repeats=1);
	SizeChange(SizeStep step,                     int repeats=1);
	SizeChange(Size size);
	bool isCompleted();
	void update(Component* b);
	void resetData();
private:
	Size from, to, actual;
	SizeStep step;
	bool isRelative;
};
#endif
