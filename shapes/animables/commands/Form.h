#ifndef FORM
#define FORM
#include <vector>
using namespace std;
#include "Color.h"
#include "Pos.h"
#include "Size.h"
#include "Box.h"
#include "Program.h"
class Form{
public:
	Form(const Form & f);
	Form(int col, int row, int width, int height);
	void setColor(Color color);
	Color getColor();
	void setPos(Pos pos);
	Pos getPos();
	void setSize(Size size);
	Size getSize();
	void addProgram(Program p);
	void addBox(Box b);
	void update();
	Color color;
	Pos pos;
	Size size;
	vector<Box> boxes;
	vector<Program>programs;
	vector<Program>::iterator actualProgram;
	friend ostream & operator<<(ostream& o, const Form & f);
};
#endif
