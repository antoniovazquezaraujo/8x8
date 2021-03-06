#ifndef PROGRAM
#define PROGRAM
#include <vector>
using namespace std;
#include "ColorChange.h"
#include "PosChange.h"
#include "SizeChange.h"

class Form;
class Command{
public:
	Command();
	void update(Form* f);
	bool isFinished();
	void setSpeed(int speed);
	void reset();
	void addChange(const ColorChange &c);
	void addChange(const PosChange &p);
	void addChange(const SizeChange &s);

	vector<ColorChange> colorChanges;
	vector<PosChange>   posChanges;
	vector<SizeChange>  sizeChanges;

private:
	bool finished;
	int speed;
};
#endif
