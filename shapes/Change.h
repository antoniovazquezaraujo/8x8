#ifndef CHANGE_H 
#define CHANGE_H 
#include <stdlib.h>
using namespace std;
class Change {
public:
	void reset();
	void update();
	bool isFinished();
	void start();
	void stop();
private:
	int time, actualTime;
	bool finished;
};
#endif
