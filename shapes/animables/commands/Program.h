#ifndef PROGRAM
#define PROGRAM
#include <vector>
using namespace std;
#include "ColorChange.h"
#include "PosChange.h"
#include "SizeChange.h"

class Form;
class Program{
public:
	Program();
	void update(Form* f);
	bool isFinished();
	void reset();
	void addChange(ColorChange c);
	void addChange(PosChange p);
	void addChange(SizeChange s);

	vector<ColorChange> colorChanges;
	vector<PosChange>   posChanges;
	vector<SizeChange>  sizeChanges;

private:
	bool finished;
};
#endif
