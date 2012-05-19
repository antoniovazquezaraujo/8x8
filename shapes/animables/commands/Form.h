#ifndef FORM
#define FORM
#include <vector>
#include <map>
using namespace std;
#include "Color.h"
#include "Pos.h"
#include "Size.h"
#include "Box.h"
#include "Command.h"
class Form{
public:
	Form(const Form & f);
	Form(int col, int row, int width, int height);
	void setColor(Color color);
	const Color &getColor() const;
	void setPos(Pos pos);
	const Pos &getPos() const;
	void setSize(Size size);
	const Size &getSize() const;

	//create command "title" at speed
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
	void commandFinished(int pos);

	void addBox(Box b);
	void update();
	Color color;
	Pos pos;
	Size size;
	vector<Box> boxes;
	vector<Command>commands;
	unsigned int actualCommand;
	map<string, int> names;//command name->position in commands
	map<int, int> events;  //on position->do position
	friend ostream & operator<<(ostream& o, const Form & f);
};
#endif
