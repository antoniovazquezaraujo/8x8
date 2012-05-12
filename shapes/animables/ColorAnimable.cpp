#include "ColorAnimable.h"
using namespace std;
ColorAnimable::ColorAnimable()
	:Animable(){
}
void ColorAnimable::addChange(int fromR, int toR, int fromG, int toG, int fromB,
		int toB, int time, int repeats) {
	changes.push_back(ColorChange(fromR, toR, fromG, toG, fromB, toB, time, repeats));
}
void ColorAnimable::update() {
	if (actualChange < changes.size()) {
		if (!changes[actualChange].isFinished()) {
			changes[actualChange].update();
			//actualizar con getColor()

			allFinished = false;
		} else {
			changes[actualChange].reset();
			if (numChange == -1) {
				actualChange++;
			}else{
				nextTurn();
			}
		}
	} else {
		reset();
		nextTurn();
	}
}
Color ColorAnimable::getColor(){
	return color;
}
