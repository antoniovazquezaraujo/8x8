#ifndef COMPONENT
#define COMPONENT
#include <vector> 
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
	Pos pos;
	Size size;
	Color color;
	vector<Command*> commands;
	vector<EventListener*>listeners;
	vector<vector<Color> >pixels;
};
#endif
