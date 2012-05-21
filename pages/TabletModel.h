#ifndef TABLET_MODEL_H_
#define TABLET_MODEL_H_
#include <stdlib.h>
#include <vector>
#include <map>
#include "Form.h"
using namespace std;

const int COLS = 8;
const int ROWS = 8;

enum PagePosition{
	FIRST, PREV, NEXT, LAST
};

class TabletModel {
public:
	TabletModel();
	void newPage(string name);
	void selectPage(PagePosition pos);
	void selectPage(string name);
	Page & getSelectedPage();
	Page & getPage(string name);
	void update();
	ColorField & getColorField();
private:
	vector<Page> pages;
	map<string, int> namesToPages;
	int formW, formH;
	int selectedPage;
};
#endif /* TABLET_MODEL_H_ */
