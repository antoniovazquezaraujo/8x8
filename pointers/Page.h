#ifndef PAGE
#define PAGE
#include <stdlib.h>
#include <vector>
#include <map>
#include "Form.h"
using namespace std;

#define RGBA(r, g, b, a) ((r)<<16)|((g)<<8)|((b))|((a)<<24)
const int COLS = 8;
const int ROWS = 8;

const int LEVELS = 2;
//typedef unsigned char Cell [3]; //r, g, b
typedef Color Col [ROWS];
typedef Col Level [COLS];
typedef Level ColorField[LEVELS];

class Page{
public:
	Page();
	~Page();
	void reset();
	void addForm(string name, int level, Form b);
	vector<Form *> getFormsAt(Pos pos);
	Form * getForm(string name);
	void update();
	ColorField & getColorField();
private:
	vector<Form*> forms;
	vector<vector<int> > levels;
	map<string, int> namesToForms;
	map<int, int> formsToLevels;
	ColorField colorField;
	int formW, formH;
};
#endif /* PAGE */
