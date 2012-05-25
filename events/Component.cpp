#include "Component.h"
Component::Component(Pos pos, Size size, Color color)
	:pos(pos)
	,size(size)
	,color(color)
	,actualCommand(0){ 

}
Component::Component(const Component & c)
	:pos(c.pos)
	,size(c.size)
	,color(c.color)
	,actualCommand(c.actualCommand){ 

}
Component::~Component(){

}
void Component::update(){
	if(actualCommand < commands.size()){
		if(commands[actualCommand].isFinished()){
			commands[actualCommand].reset();
			commandFinished();
		}else{
			commands[actualCommand].update(this);
		}
	}else{
		//Con esto se reiniciaría al terminar todos.
		//Puede ser interesante.
		actualCommand = 0;
	}
}
bool Component::containsPoint(const Pos & p){
	return (p.x >=pos.x && p.x <pos.x+size.w
			&& p.y >=pos.y && p.y <pos.y+size.h)
		;
}

void Component::addListener(EventListener * l){
	listeners.push_back(l);
}
//crear todos los eventos...
bool Component::onClick(Pos pos){
	for(EventListener *l: listeners){
		if(l->pressed(this, pos)){
			return true;
		}
	}
	return false;
}
void Component::paint(ColorSpace & space, const Pos& p, const Size & s){
	//llena pixels con su color
	for(int x=pos.x; x<pos.x+size.w; x++){
		for(int y= pos.y; y <pos.y+size.h; y++){
			space[x+p.x][y+p.y]=color;
		}
	}
}
const Pos & Component::getPos(){
	return pos;
}
void Component::setPos(const Pos & p){
	pos= p;
}
const Size & Component::getSize(){
	return size;
}
void Component::setSize(const Size & s){
	size= s;
}
const Color & Component::getColor(){
	return color;
}
void Component::setColor(const Color & c){
	color = c;
}
void Component::commandFinished(){
	if(events.find(actualCommand) != events.end()){
		actualCommand = events[actualCommand];
	}else{
 		actualCommand++;
	}
}
void Component::operator()(string title, int speed){
	Command c;
	c.setSpeed(speed);
	commands.push_back(c);
	names[title] = commands.size()-1;
}
void Component::operator()(const Pos & pos){
	commands.back().addChange(PosChange(pos));	
}
void Component::operator()(const Size & size){
	commands.back().addChange(SizeChange(size));	
}
void Component::operator()(const Color & color){
	commands.back().addChange(ColorChange(color));	
}
void Component::operator()(const Pos   & from, const Pos   & to, int times){
	commands.back().addChange(PosChange(from, to, times));	
}
void Component::operator()(const Size  & from, const Size  & to, int times){
	commands.back().addChange(SizeChange(from, to, times));	
}
void Component::operator()(const Color & from, const Color & to, int times){
	commands.back().addChange(ColorChange(from, to, times));	
}
void Component::operator()(const Pos   & from, const Pos   & to, const PosStep & step,   int times){
	commands.back().addChange(PosChange(from, to,step, times));	
}
void Component::operator()(const Size  & from, const Size  & to, const SizeStep & step,  int times){
	commands.back().addChange(SizeChange(from, to,step, times));	
}
void Component::operator()(const Color & from, const Color & to, const ColorStep & step, int times){
	commands.back().addChange(ColorChange(from, to,step, times));	
}
void Component::operator()(const PosStep & step,   int times){
	commands.back().addChange(PosChange(step, times));	
}
void Component::operator()(const SizeStep & step,  int times){
	commands.back().addChange(SizeChange(step, times));	
}
void Component::operator()(const ColorStep & step, int times){
	commands.back().addChange(ColorChange(step, times));	
}
void Component::on(string onTitle, string doTitle){
	events[names[onTitle]] = names[doTitle];
}
void Component::go(string title){
	if(names.find(title) == names.end()) return;
	if(events.find(names[title]) == events.end()) return;
	actualCommand = events[names[title]];
}
