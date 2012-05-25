#ifndef COMPONENT
#define COMPONENT
#include <vector> 
#include <string> 
#include <map> 
#include "Pos.h"
#include "Size.h"
#include "Color.h"
#include "Command.h"
#include "ColorSpace.h"
#include "EventListener.h"
using namespace std;
class Component{
public:
	Component(Pos pos, Size size, Color color);
	Component(const Component & c);
	virtual ~Component();
	void update();
	bool containsPoint(const Pos & p);

	void addListener(EventListener * l);
	bool onClick(Pos pos);
	void paint(ColorSpace & space, const Pos& p, const Size & s);
	const Pos & getPos();
	void setPos(const Pos & p);
	const Size & getSize();
	void setSize(const Size & s);
	const Color & getColor();
	void setColor(const Color & c);

	void operator()(string title, int speed=MAX_SPEED);
	//setters
	void operator()(const Pos & pos);
	void operator()(const Size & size);
	void operator()(const Color & color);

	//changes with step = 1
	void operator()(const Pos   & from, const Pos   & to, int times=1);
	void operator()(const Size  & from, const Size  & to, int times=1);
	void operator()(const Color & from, const Color & to, int times=1);

 	//changes with a step 
	void operator()(const Pos   & from, const Pos   & to, const PosStep   & step, int times=1);
	void operator()(const Size  & from, const Size  & to, const SizeStep  & step, int times=1);
	void operator()(const Color & from, const Color & to, const ColorStep & step, int times=1);

	//relative changes with a step 
	void operator()(const PosStep   & step, int times=1);
	void operator()(const SizeStep  & step, int times=1);
	void operator()(const ColorStep & step, int times=1);

	//on command end...
	void on(string onTitle, string doTitle);
	void go(string title);
	void commandFinished();
	Pos pos;
	Size size;
	Color color;
	vector<Command> commands;
	vector<EventListener*>listeners;
	unsigned int actualCommand;
	map<string, int> names;//command name->position in commands
	map<int, int> events;  //on position->do position
};
#endif
