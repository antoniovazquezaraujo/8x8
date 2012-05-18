#ifndef SIZE_CHANGE
#define SIZE_CHANGE
#include "Change.h"
#include "Size.h"
class Form;
class SizeChange: public Change{
public:
	SizeChange(Size from=Size(), Size to=Size(), int speed=1, int repeats=1);
	SizeChange(SizeStep step=SizeStep(), int speed=1, int repeats=1);
	bool isCompleted();
	void update(Form * b);
private:
	void resetData();
	Size from, to, actual;
	SizeStep step;
	bool isRelative;
};
#endif
