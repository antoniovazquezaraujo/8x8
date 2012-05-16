#ifndef POS_CHANGE
#define POS_CHANGE
#include "Change.h"
#include "Pos.h"
#include "PosStep.h"
class Form;
class PosChange: public Change{
public:
	PosChange(Pos from, Pos to, int speed, int repeats);
	PosChange(PosStep step, int speed, int repeats);
	bool isCompleted();
	void update(Form * b);
private:
	void resetData();
	Pos from, to, actual;
	PosStep step;
	bool isRelative;
};
#endif
