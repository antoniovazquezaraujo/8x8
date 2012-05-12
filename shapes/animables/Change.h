#ifndef CHANGE_H 
#define CHANGE_H 
#include <cstdlib>
#include <cassert>
using namespace std;
class Change {
public:
	Change(int time, int repeats);
	void reset();
	void update();
	bool isFinished();
	void start();
	void stop();
protected:
	int time, actualTime;
	int repeats, actualRepeats;
	bool finished;
};
#endif
