#ifndef BOX
#define BOX
#include "Color.h"
#include "Pos.h"
#include "Size.h"
#include <ostream> 
using namespace std;
class Box{
public:
	Box(int col, int row, int width, int height, bool filled); 
	void setColor(Color color);
	void setColor(int r, int g, int b);
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
