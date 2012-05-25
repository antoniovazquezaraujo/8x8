#ifndef COLOR_SPACE 
#define COLOR_SPACE 
#include <vector> 
#include "Pos.h"
#include "Size.h"
#include "Color.h"
#include "Command.h"
#include "EventListener.h"
using namespace std;
class ColorSpace{
public:
	typedef vector<Color> col;
	typedef vector<col> colorSpace;
	ColorSpace(int cols, int rows);
	void reset();
	col & operator[](int c);
private:
	int cols, rows;
	colorSpace space; 
};
#endif
