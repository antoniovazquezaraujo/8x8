#ifndef BOX
#define BOX
#include "Color.h"
#include "Pos.h"
#include "Size.h"
#include <ostream> 
using namespace std;
class Box{
public:
	void setColor(Color color);
	Color getColor();
	void setPos(Pos pos);
	Pos getPos();
	void setSize(Size size);
	Size getSize();
private:
	Color color;
	Pos pos;
	Size size;

	friend ostream & operator<<(ostream& o, const Box & b);
};
#endif
