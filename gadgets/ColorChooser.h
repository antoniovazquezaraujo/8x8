#ifndef COLOR_CHOOSER
#define COLOR_CHOOSER
#include <vector>
#include <map>
using namespace std;
#include "Color.h"
#include "Pos.h"
#include "Size.h"
#include "Box.h"
#include "Command.h"
#include "Form.h"
class ColorChooser : public Form{
public:
	ColorChooser(int col, int row, int width, int height)
		:Form(col,row, width, height){
		addBox(Box(col,   row,   1,1));
		addBox(Box(col,   row+1, 1,1));
		addBox(Box(col+1, row,   1,1));
		addBox(Box(col+1, row+1, 1,1));
		addBox(Box(col+2, row,   1,1));
		addBox(Box(col+2, row+1, 1,1));
		addBox(Box(col,   row+2, 1,1));
		addBox(Box(col+1, row+2, 1,1));
		addBox(Box(col+2, row+2, 1,1));

	}
	void onClick(int col, int row){

	}
	const Color & getValue(){
		return value;
	}
private:
	Color value;
};
#endif
