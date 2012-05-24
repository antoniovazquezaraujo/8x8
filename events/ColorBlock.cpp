#include "ColorBlock.h"
	ColorBlock::ColorBlock(int levels, int cols, int rows)
	:cols(cols)
	,rows(rows)
	 ,spaces(levels, ColorSpace(cols, rows)){

}
const int ColorBlock::getNumLevels() const{
	return spaces.size();
}
void ColorBlock::reset(){
	for(vector<ColorSpace>::iterator i = spaces.begin();
			i!= spaces.end();
			i++){
		(*i).reset();
	}
}
ColorSpace & ColorBlock::operator[](int pos){
	return spaces[pos];
}
void ColorBlock::addLevel(){
	spaces.push_back(ColorSpace(cols, rows));
}
