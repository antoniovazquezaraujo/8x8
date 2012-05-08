#include "SizeChange.h"
#include <iostream> 

SizeChange::SizeChange(int widthDelta, int heightDelta, int time, int repetitions) 
	:widthDelta(widthDelta),
	heightDelta(heightDelta),
	time(time),
	actualTime(time),
	repetitions(repetitions),
	actualRepetitions(repetitions){
	reset();
}
void SizeChange::reset() {
	finished = false;
	actualTime = time;
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
bool SizeChange::isFinished() {
	return finished;
}

void SizeChange::start() {
	actualTime = time;
}
void SizeChange::stop() {
	finished = true;
	actualTime = 0;
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

