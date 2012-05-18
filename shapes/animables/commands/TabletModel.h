#ifndef TABLET_MODEL_H_
#define TABLET_MODEL_H_
#include <stdlib.h>
#include <vector>
<<<<<<< HEAD
#include "Box.h"
=======
#include "Form.h"
>>>>>>> c1e60e41d4394aed5d15f2cb388a1658cd522597
using namespace std;

#define RGBA(r, g, b, a) ((r)<<16)|((g)<<8)|((b))|((a)<<24)
const int LEVELS = 2;
const int COLS = 8;
const int ROWS = 8;
//typedef unsigned char Cell [3]; //r, g, b
typedef Color Col [ROWS];
typedef Col Level [COLS];
typedef Level ColorField[LEVELS];

class TabletModel {
public:
	static void test();
	TabletModel();
	void reset();
<<<<<<< HEAD
	void addBox(
		int level, 
		int col, int row, 
		int width, int height,
		bool filled = false
	);
	void addBox(int level, Box b);
	Box & box(int level, int n);
	Box & lastBox(int level);
	void update();
	ColorField & getColorField();
private:
	vector<vector<Box> > levelBoxes;
	ColorField colorField;
	int boxW, boxH;
=======
	void addForm(int level, Form b);
	Form & form(int level, int n);
	Form & lastForm(int level);
	void update();
	ColorField & getColorField();
private:
	vector<vector<Form> > levelForms;
	ColorField colorField;
	int formW, formH;
>>>>>>> c1e60e41d4394aed5d15f2cb388a1658cd522597
};
#endif /* TABLET_MODEL_H_ */
