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
const int LEVELS = 2;
const int ROWS = 8;
const int COLS = 8;
typedef unsigned char Cell [3]; //r, g, b
typedef Cell Row [COLS];
typedef Row Level [ROWS];
typedef Level ColorField[LEVELS];

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
	ColorField & getColorField();
private:
	vector<vector<Box> > levelBoxes;
	ColorField colorField;
	int boxH, boxW;
};
#endif /* TABLET_H_ */
