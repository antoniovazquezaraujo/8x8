#include "Box.h" 
Box::Box(int col, int row, int width, int height, bool filled){
// hacer esto.
}
void Box::setColor(int r, int g, int b){
	this->color = Color(r,g,b);
}
void Box::setColor(Color color){
	this->color = color;
}
Color Box::getColor(){
	return color;
}
void Box::setPos(Pos pos){
	this->pos=pos;
}
Pos Box::getPos(){
	return pos;
}
void Box::setSize(Size size){
	this->size = size;
}
Size Box::getSize(){
	return size;
}
