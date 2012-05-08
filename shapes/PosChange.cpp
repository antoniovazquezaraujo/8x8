#include "PosChange.h"

PosChange::PosChange(int colDelta, int rowDelta, int time, int repeats) 
	:Change(time, repeats),
	colDelta(colDelta),
	rowDelta(rowDelta),
}
void PosChange::update() {
	if(repeats >0){
		if (actualTime >0) {
			actualTime--;
		} else {
			repeats--;
			actualTime = time;
		}
	}else{
		finished = true;
	}
}

Rect PosChange::getRect(Rect original) {
	Rect r = original;
	if(finished)return r;
	if(actualTime == time){
		r.col+=colDelta;
		r.row+=rowDelta;
	}
	return r;
}

