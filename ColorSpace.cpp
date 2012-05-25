#include "ColorSpace.h"
ColorSpace::ColorSpace(int cols, int rows)
	:cols(cols)
	 ,rows(rows)
	 ,space(cols, col(rows, Color())){

}

void ColorSpace::reset(){
	const Color black;
	for(colorSpace::iterator i = space.begin(); i != space.end(); i++){
		for(col::iterator i2 = (*i).begin(); i2 != (*i).end(); i2++){
			(*i2) = black; 
		}
	}
}
ColorSpace::col & ColorSpace::operator[](int c){
	return space[c];
}
