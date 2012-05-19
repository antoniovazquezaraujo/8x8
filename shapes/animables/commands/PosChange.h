#ifndef POS_CHANGE
#define POS_CHANGE
#include "Change.h"
#include "Pos.h"
#include "PosStep.h"
class Form;
class PosChange: public Change{
public:
	PosChange(Pos from, Pos to, PosStep step, int repeats=1);
	PosChange(Pos from, Pos to,               int repeats=1);
	PosChange(PosStep step,                   int repeats=1);
	PosChange(Pos pos);
	bool isCompleted();
	void update(Form * b);
	void resetData();
private:
	Pos from, to, actual;
	PosStep step;
	bool isRelative;
};
#endif
