#ifndef COLOR_ANIMABLE_H
#define COLOR_ANIMABLE_H
class ColorAnimable: public Animable{
public:
	void addChange(
		int fromR, int toR, 
		int fromG, int toG, 
		int fromB, int toB, 
		int duration, int repeats
	);
	void update();
	Color getColor();
private:
	vector<ColorChange> changes;
	Color color;
};
#endif

void ColorAnimable::addChange(int fromR, int toR, int fromG, int toG, int fromB,
		int toB, int time, int repeats) {
	changes.push_back(ColorChange(fromR, toR, fromG, toG, fromB, toB, time, repeats));
}
void ColorAnimable::update() {
	if(stopped) return;
	if (actualChange < changes.size()) {
		if (!changes[actualChange].isFinished()) {
			changes[actualChange].update();

			color.setR(changes[actualChange].getR());
			color.setG(changes[actualChange].getG());
			color.setB(changes[actualChange].getB());

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
