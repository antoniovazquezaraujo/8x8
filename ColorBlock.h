#ifndef COLOR_BLOCK
#define COLOR_BLOCK
#include "ColorSpace.h"
class ColorBlock{
public:
	ColorBlock(int levels, int cols, int rows);
	const int getNumLevels() const;
	ColorSpace & operator[](int pos);
	void addLevel();
	void reset();
	int cols, rows;
	vector<ColorSpace> spaces;
};
#endif
