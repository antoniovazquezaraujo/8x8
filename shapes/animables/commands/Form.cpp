#include "Form.h"
Form::Form(const Form & f)
	:color(f.color)
	,pos(f.pos)
	,size(f.size)
	,boxes(f.boxes)
	,programs(f.programs){
	actualProgram = programs.begin();

}
Form::Form(int col, int row, int width, int height)
	:pos(col, row)
	,size(width,height){
	actualProgram = programs.begin();

}
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
	actualProgram = programs.begin();
}
void Form::addBox(Box b){
	boxes.push_back(b);
}
void Form::update(){
	if(actualProgram != programs.end()){
		if((*actualProgram).isFinished()){
			(*actualProgram).reset();
			actualProgram++;
		}else{
			(*actualProgram).update(this);
		}
	}else{
		actualProgram = programs.begin();
	}
}
