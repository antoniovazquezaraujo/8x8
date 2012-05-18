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
	const Color &getColor() const;
	void setPos(Pos pos);
	const Pos &getPos() const;
	void setSize(Size size);
	const Size & getSize() const;
private:
	Color color;
	Pos pos;
	Size size;

	friend ostream & operator<<(ostream& o, const Box & b);
};
#endif
