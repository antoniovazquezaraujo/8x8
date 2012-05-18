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
	const Color &getColor() const;
	void setPos(Pos pos);
	const Pos &getPos() const;
	void setSize(Size size);
	const Size &getSize() const;
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
