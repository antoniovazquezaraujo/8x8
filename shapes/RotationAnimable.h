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

