#include "Form.h"
#include <cassert>
#include <iostream>
Form::Form(const Form & f)
	:color(f.color)
	,pos(f.pos)
	,size(f.size)
	,boxes(f.boxes)
	,commands(f.commands)
	,actualCommand(f.actualCommand) 
	,names(f.names)
	,events(f.events){

}
Form::Form(int col, int row, int width, int height)
	:pos(col, row)
	,size(width,height){
	actualCommand = 0; 

}
void Form::setColor(Color color){
	this->color = color;
}
const Color &Form::getColor()const{
	return color;
}
void Form::setPos(Pos pos){
	this->pos=pos;
}
const Pos &Form::getPos() const{
	return pos;
}
void Form::setSize(Size size){
	this->size = size;
}
const Size &Form::getSize() const{
	return size;
}
void Form::addBox(Box b){
	boxes.push_back(b);
}
void Form::commandFinished(int pos){
	if(events.find(pos) != events.end()){
		actualCommand = events[pos];
	}else{
 	//	actualCommand++;
	}
}
void Form::update(){
	if(actualCommand < commands.size()){
		if(commands[actualCommand].isFinished()){
			commands[actualCommand].reset();
			commandFinished(actualCommand);
		}else{
			commands[actualCommand].update(this);
		}
	}else{
		actualCommand = 0;
	}
}
void Form::operator()(string title, int speed){
	Command c;
	c.setSpeed(speed);
	commands.push_back(c);
	names[title] = commands.size()-1;
}
void Form::operator()(const Pos & pos){
	this->pos=pos;
}
void Form::operator()(const Size & size){
	this->size=size;
}
void Form::operator()(const Color & color){
	this->color = color;
}
void Form::operator()(const Pos   & from, const Pos   & to, int times){
	commands.back().addChange(PosChange(from, to, times));	
}
void Form::operator()(const Size  & from, const Size  & to, int times){
	commands.back().addChange(SizeChange(from, to, times));	
}
void Form::operator()(const Color & from, const Color & to, int times){
	commands.back().addChange(ColorChange(from, to, times));	
}
void Form::operator()(const Pos   & from, const Pos   & to, const PosStep & step,   int times){
	commands.back().addChange(PosChange(from, to,step, times));	
}
void Form::operator()(const Size  & from, const Size  & to, const SizeStep & step,  int times){
	commands.back().addChange(SizeChange(from, to,step, times));	
}
void Form::operator()(const Color & from, const Color & to, const ColorStep & step, int times){
	commands.back().addChange(ColorChange(from, to,step, times));	
}
void Form::operator()(const PosStep & step,   int times){
	commands.back().addChange(PosChange(step, times));	
}
void Form::operator()(const SizeStep & step,  int times){
	commands.back().addChange(SizeChange(step, times));	
}
void Form::operator()(const ColorStep & step, int times){
	commands.back().addChange(ColorChange(step, times));	
}
void Form::on(string onTitle, string doTitle){
	events[names[onTitle]] = names[doTitle];
}
void Form::go(string title){
	assert(names.find(title) != names.end());
	assert(events.find(names[title]) != events.end());
	actualCommand = events[names[title]];
}
