#include "Form.h"
void Form::setColor(Color color){
	this->color = color;
}
Color Form::getColor(){
	return color;
}
void Form::setPos(Pos pos){
	this->pos=pos;
}
Pos Form::getPos(){
	return pos;
}
void Form::setSize(Size size){
	this->size = size;
}
Size Form::getSize(){
	return size;
}
void Form::addProgram(Program p){
	programs.push_back(p);
}
void Form::update(){
	if(actualProgram != programs.end()){
		actualProgram.update(this);
		actualProgram++;
	}else{
		actualProgram = programs.begin();
	}
}
