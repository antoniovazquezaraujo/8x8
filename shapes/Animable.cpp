#include "Animable.h"
Animable::Animable()
	:
	times(0),
	actualTimes(0),
	numChange(-1),
	actualChange (0),
	allFinished (true),
	finished (false){

}

void update(){
	//Nunca se debe llegar aqui!
	assert(false);
}
void Animable::startChanges(int times ) {
	this->times = times;
	actualTimes = times;
	stopped= false;
	numChange = -1;
	finished = false;
	reset();
}
void Animable::startChange(int numChange, int times) {
	this->numChange = numChange;
	this->times = times;
	actualTimes = times;
	stopped= false;
	finished = false;
	reset();
}

void Animable::stop() {
	stopped= true;
}

bool Animable::isFinished() {
	return finished ;
}

void Animable::nextTurn() {
	if (actualTimes == -1) {
		finished = false;
	} else {
		if (actualTimes > 0) {
			actualTimes--;
			finished = false;
		} else {
			actualTimes = times;
			finished = true;
		}
	}
	allFinished = true;
}
void Animable::reset() {
	if (numChange != -1) {
		actualChange = numChange;
	} else {
		actualChange = 0;
	}
}
