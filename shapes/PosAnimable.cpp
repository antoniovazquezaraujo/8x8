#include "PosAnimable.h"
void PosAnimable::addChange (int dx, int dy, int time, int repetitions){
	changes.push_back(PosChange(dx, dy, time, repetitions));
}
void PosAnimable::update() {
	if(stopped) return;
	if (actualChange < changes.size()) {
		if (!changes[actualChange].isFinished()) {
			changes[actualChange].update();
			Rect rr = changes[actualChange].getRect(rect);
			setPos(rr);
		} else {
			changes[actualChange].reset();
			if (numChange == -1) {
				actualChange++;
			}
		}
	} else {
		spaceTerminated =true;
	}
}
Point PosAnimable::getPos(){
	return pos;
}
