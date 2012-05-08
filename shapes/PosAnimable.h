#ifndef POS_ANIMABLE_H
#define POS_ANIMABLE_H
class PosAnimable: public Animable{
public:
	void addChange (int dx, int dy, int time, int repetitions);
	void update();
	Point getPos();
private:
	vector<PosChange> changes;
	Point pos;
};
#endif

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
