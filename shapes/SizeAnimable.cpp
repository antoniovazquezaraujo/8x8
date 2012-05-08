#include "SizeAnimable.h"
void SizeAnimable::addChange(int dw, int dh, int duration, int repeats){
	changes.push_back(SizeChange(dw, dh, time, repeats));
}
void SizeAnimable::update() {
	if(stopped) return;
	if (actualChange < sizeChanges.size()) {
		if (!sizeChanges[actualChange].isFinished()) {
			sizeChanges[actualChange].update();
			Rect rr = sizeChanges[actualChange].getRect(rect);
			setPos(rr); //cambiar el nombre de esto.
		} else {
			sizeChanges[actualChange].reset();
			if (numChange == -1) {
				actualChange++;
			}
		}
	} else {
		sizeTerminated =true;
	}
}
Size SizeAnimable::getSize(){
	return size;
}
