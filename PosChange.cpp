#include "PosChange.h"
#include <iostream> 

PosChange::PosChange(int colDelta, int rowDelta, int time, int repetitions) 
	:colDelta(colDelta),
	rowDelta(rowDelta),
	time(time),
	actualTime(time),
	repetitions(repetitions),
	actualRepetitions(repetitions){
	reset();
}
void PosChange::reset() {
	finished = false;
	actualTime = time;
}
void PosChange::update() {
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
bool PosChange::isFinished() {
	return finished;
}

void PosChange::start() {
	actualTime = time;
}
void PosChange::stop() {
	finished = true;
	actualTime = 0;
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

