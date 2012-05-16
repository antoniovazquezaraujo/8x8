#include "Box.h" 
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
