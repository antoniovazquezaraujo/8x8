#include "RotationAnimable.h"
void RotationAnimable::addChange(int degrees, int duration, int repeats){
	changes.push_back(RotationChange(degrees, time, repeats));
}
void RotationAnimable::update() {
	if(stopped) return;
	if (actualChange < changes.size()) {
		if (!changes[actualChange].isFinished()) {
			changes[actualChange].update();
			//Rect rr = changes[actualChange].getRect(rect);
			//setPos(rr); //cambiar el nombre de esto.
		} else {
			changes[actualChange].reset();
			if (numChange == -1) {
				actualChange++;
			}
		}
	} else {
		sizeTerminated =true;
	}
}
int RotationAnimable::getDegrees(){
	return degrees;
}
