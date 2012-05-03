#ifndef TABLET_H_
#define TABLET_H_
#include <stdlib.h>
#include <vector>
#include "Box.h"
using namespace std;

#define RGBA(r, g, b, a) ((r)<<16)|((g)<<8)|((b))|((a)<<24)
const int LEVELS = 2;
const int COLS = 8;
const int ROWS = 8;
struct Color{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};
//typedef unsigned char Cell [3]; //r, g, b
typedef Color Col [ROWS];
typedef Col Level [COLS];
typedef Level ColorField[LEVELS];

class Tablet {
public:
	static void test();
	Tablet();
	void reset();
	void drawRect(
		int level, 
		int col, int row, 
		int width, int height,
		Color color,
		bool filled = false
	);
	void addBox(
		int level, 
		int col, int row, 
		int width, int height,
		bool filled = false
	);
	Box & box(int level, int n);
	Box & lastBox(int level);
	void update();
	ColorField & getColorField();
private:
	vector<vector<Box> > levelBoxes;
	ColorField colorField;
	int boxW, boxH;
};
#endif /* TABLET_H_ */
