#ifndef TABLET_MODEL_H_
#define TABLET_MODEL_H_
#include <stdlib.h>
#include <vector>
#include <map>
#include "Form.h"
#include "Page.h"
using namespace std;


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
	unsigned int selectedPage;
};
#endif /* TABLET_MODEL_H_ */
