#ifndef CONTAINER
#define CONTAINER 
#include <vector> 
#include "Component.h"
#include "Command.h"
#include "EventListener.h"
using namespace std;
class Container: public Component{
public:
	void add(Component * c);
	void update();
	void paint(ColorSpace & space, const Pos& p, const Size &s);
	vector<Component*> components;
};
#endif
