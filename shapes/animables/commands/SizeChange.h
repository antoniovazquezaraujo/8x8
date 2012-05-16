#ifndef SIZE_CHANGE
#define SIZE_CHANGE
#include "Change.h"
#include "Size.h"
#include "Form.h"
class SizeChange: public Change{
public:
	SizeChange(Size from, Size to, int speed, int repeats);
	SizeChange(SizeStep step, int speed, int repeats);
	bool isCompleted();
	void update(Form * b);
private:
	void resetData();
	Size from, to, actual;
	SizeStep step;
	bool isRelative;
};
#endif
