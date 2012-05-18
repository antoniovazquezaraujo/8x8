#ifndef TABLET_MODEL_H_
#define TABLET_MODEL_H_
#include <stdlib.h>
#include <vector>
#include "Form.h"
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
	void addForm(int level, Form b);
	Form & form(int level, int n);
	Form & lastForm(int level);
	void update();
	ColorField & getColorField();
private:
	vector<vector<Form> > levelForms;
	ColorField colorField;
	int formW, formH;
};
#endif /* TABLET_MODEL_H_ */
