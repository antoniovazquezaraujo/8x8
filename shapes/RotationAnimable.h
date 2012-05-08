#ifndef ROTATION_ANIMABLE_H
#define ROTATION_ANIMABLE_H
class RotationAnimable: public Animable{
public:
	void addChange(int degrees, int duration, int repeats);
	void update();
	int getDegrees();
private:
	vector<RotationChange> changes;
	int degrees;
};
#endif

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
