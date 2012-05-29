#ifndef PAGE 
#define PAGE 
#include <vector> 
#include <map> 
#include <string> 
#include "Pos.h"
#include "Size.h"
#include "Color.h"
#include "Command.h"
#include "ColorBlock.h"
#include "EventListener.h"
using namespace std;
#define RGBA(r, g, b, a) ((r)<<16)|((g)<<8)|((b))|((a)<<24)
const int COLS = 8;
const int ROWS = 8;

class Page{
public:
	Page();
	~Page();
	void reset();
	void addComponent(string name, int level, Component * f);
	void removeComponent(string name);
	vector<Component *> getComponentsAt(Pos pos);
	Component * getComponent(string name);
	void update();
	ColorBlock & getColorBlock();
private:
	vector<Component*> components;
	vector<vector<int> > levels;
	map<string, int> namesToComponents;
	map<int, int> componentsToLevels;
	int componentW, componentH;
	ColorBlock colorBlock;
};
#endif
