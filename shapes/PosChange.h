#ifndef POS_CHANGE_H
#define POS_CHANGE_H
#include <stdlib.h>
#include "Rect.h" 

using namespace std;
class PosChange {
public:
	PosChange(int colDelta, int rowDelta, int time, int repeats);
	void update();
	Rect getRect(Rect original);
private:
	int colDelta, rowDelta;
};

#endif
