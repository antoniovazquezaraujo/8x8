#ifndef PIXEL_MATRIX 
#define PIXEL_MATRIX 
#include <vector> 
#include "Pos.h"
#include "Size.h"
#include "Color.h"
#include "Command.h"
#include "EventListener.h"
using namespace std;
class PixelMatrix{
public:
	typedef vector<Color> col;
	typedef vector<col> level;
	typedef vector<level> colorSpace;
	PixelMatrix(int levels, int cols, int rows)
		:cols(cols)
		,rows(rows)
		,space(levels, level(cols, col(rows, Color()))){

	}
	void addLevel(){
		space.push_back(level(cols, col(rows, Color())));
	}

	level & operator[](int pos){
		return space[pos];
	}
	const int & getNumLevels() const{
		return space.size();
	}
	void reset(){
		const Color black;
		for(int n=0; n< getNumLevels(); n++){
			for(level::iterator i = space[n].begin(); i != space[n].end(); i++){
				for(col::iterator i2 = (*i).begin(); i2 != (*i).end(); i2++){
					(*i2) = black; 
				}
			}
		}
	}

private:
	colorSpace space; 
	int cols, rows;
};
#endif
