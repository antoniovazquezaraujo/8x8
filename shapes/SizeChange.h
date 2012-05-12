#ifndef SIZE_CHANGE_H_
#define SIZE_CHANGE_H_
#include <stdlib.h>
#include "Rect.h" 

using namespace std;
class SizeChange {
public:
	SizeChange(int widthDelta, int heightDelta, int time, int repeats);
	void update();
	Rect getRect(Rect original);
private:
	int widthDelta, heightDelta;
};

#endif
