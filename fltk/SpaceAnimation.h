#ifndef SPACE_ANIMATION_H_
#define SPACE_ANIMATION_H_
#include <stdlib.h>
#include "Rect.h" 

using namespace std;
class SpaceAnimation {
public:
	static void test();
	SpaceAnimation(int fromCol = -1, int toCol = 0, int fromRow = -1, int toRow = 0,
			int fromWidth = -1, int toWidth = 0, int fromHeight=-1, int toHeight=0,  int time = 1);
	void reset();
	void update();
	bool isFinished();
	void start();
	void stop();
	Rect getRect(Rect original);
private:
	Rect from, to, actual;
	int colDelta, rowDelta, widthDelta, heightDelta;
	int colLapse, rowLapse, widthLapse, heightLapse;
	int colRange, rowRange, widthRange, heightRange;
	int colCount, rowCount, widthCount, heightCount;
	int time, actualTime;
	bool finished;
};

#endif
