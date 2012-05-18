#include "Box.h" 
Box::Box(int col, int row, int width, int height, bool filled)
	:pos(col, row)
	,size(width, height){

}
void Box::setColor(int r, int g, int b){
	this->color = Color(r,g,b);
}
void Box::setColor(Color color){
	this->color = color;
}
const Color &Box::getColor() const{
	return color;
}
void Box::setPos(Pos pos){
	this->pos=pos;
}
const Pos &Box::getPos() const{
	return pos;
}
void Box::setSize(Size size){
	this->size = size;
}
const Size & Box::getSize() const{
	return size;
}
