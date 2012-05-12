#include "Change.h"

Change::Change(int time, int repeats) :
	time(time),
	actualTime(time),
	repeats(repeats),
	actualRepeats(repeats){
	reset();
}
void Change::reset() {
	actualTime = time;
	finished = false;
}
void Change::update(){
	assert(false);
}
bool Change::isFinished() {
	return finished;
}

void Change::start() {
	actualTime = time;
}
void Change::stop() {
	finished = true;
	actualTime = 0;
}

