#ifndef TABLET_H_
#define TABLET_H_
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include "Box.h"
using namespace std;

#define RGBA(r, g, b, a) ((r)<<16)|((g)<<8)|((b))|((a)<<24)
const int BOX_LEVELS = 2;
const int ROWS = 8;
const int COLS = 8;

class Tablet {
public:
	static void test();
	Tablet();
	void reset();
	void addBox(int level, int row, int col, int height, int width,
			bool filled = false);
	Box & box(int level, int n);
	Box & lastBox(int level);
	void update();
	void paint();
private:
	vector<vector<Box> > levelBoxes;
	unsigned int levelCells[BOX_LEVELS][ROWS][COLS][3];
	int boxH, boxW;
};
#endif /* TABLET_H_ */
