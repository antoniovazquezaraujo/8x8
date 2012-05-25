#ifndef CONTAINER
#define CONTAINER 
#include <vector> 
#include "Component.h"
#include "Command.h"
#include "EventListener.h"
using namespace std;
class Container: public Component{
public:
	Container(const Pos & pos, const Size & size, const Color & color);
	void add(Component * c);
	void update();
	void paint(ColorSpace & space, const Pos& p, const Size &s);
	bool onClick(Pos pos);
	Component * getComponentAt(const Pos& pos);
	vector<Component*> components;
};
#endif
