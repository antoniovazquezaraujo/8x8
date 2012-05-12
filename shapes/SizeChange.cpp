#include "SizeChange.h"
#include <iostream> 

SizeChange::SizeChange(int widthDelta, int heightDelta, int time, int repeats) 
	:Change(time, repeats)
	 widthDelta(widthDelta),
	heightDelta(heightDelta),
	reset();
}
void SizeChange::update() {
	if(repetitions >0){
		if (actualTime >0) {
			actualTime--;
		} else {
			repetitions--;
			actualTime = time;
		}
	}else{
		finished = true;
	}
}

Rect SizeChange::getRect(Rect original) {
	Rect r = original;
	if(finished)return r;
	if(actualTime == time){
		r.width+=widthDelta;
		r.height+=heightDelta;
	}
	return r;
}

