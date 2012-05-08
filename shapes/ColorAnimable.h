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

