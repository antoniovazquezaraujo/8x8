#ifndef COMMAND 
#define COMMAND 
#include <vector>
#include <cassert>
using namespace std;
#include "ColorChange.h"
#include "PosChange.h"
#include "SizeChange.h"

class Component;
class Command{
public:
	static void test();
	Command();
	void update(Component* f);
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
