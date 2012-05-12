#ifndef COLOR_ANIMABLE_H
#define COLOR_ANIMABLE_H
#include "Animable.h"
#include "ColorChange.h"
#include <vector>
class ColorAnimable: public Animable{
public:
	ColorAnimable();
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

