#ifndef SIZE_CHANGE_H_
#define SIZE_CHANGE_H_
#include <stdlib.h>
#include "Rect.h" 

using namespace std;
class SizeChange {
public:
	static void test();
	SizeChange(int widthDelta, int heightDelta, int time, int repetitions);
	void reset();
	void update();
	bool isFinished();
	void start();
	void stop();
	Rect getRect(Rect original);
private:
	int widthDelta, heightDelta;
	int time, actualTime;
	int repetitions, actualRepetitions;
	bool finished;
};

#endif
