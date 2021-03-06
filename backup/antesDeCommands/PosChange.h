#ifndef POS_CHANGE_H
#define POS_CHANGE_H
#include <stdlib.h>
#include "Rect.h" 

using namespace std;
class PosChange {
public:
	static void test();
	PosChange(int colDelta, int rowDelta, int time, int repetitions);
	void reset();
	void update();
	bool isFinished();
	void start();
	void stop();
	Rect getRect(Rect original);
private:
	int colDelta, rowDelta;
	int time, actualTime;
	int repetitions, actualRepetitions;
	bool finished;
};

#endif
