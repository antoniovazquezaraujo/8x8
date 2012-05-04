#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <stdlib.h>


using namespace std;
class ColorChange {

public:
	static void test();
	ColorChange(int fromR = 0, int toR = 0, int fromG = 0, int toG = 0,
			int fromB = 0, int toB = 0, int time = 1);
	void reset();
	void update();
	bool isFinished();
	void start();
	void stop();
	unsigned char getR();
	unsigned char getG();
	unsigned char getB();

private:
	unsigned char fromR, toR, fromG, toG, fromB, toB;
	int rDelta, gDelta, bDelta;
	int rLapse, gLapse, bLapse;
	int rRange, gRange, bRange;
	int rCount, gCount, bCount;
	unsigned char r, g, b;
	int time, actualTime;
	bool finished;
};

#endif
