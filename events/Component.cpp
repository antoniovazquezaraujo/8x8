#include "Component.h"
Component::Component(Pos pos, Size size, Color color)
	:pos(pos)
	,size(size)
	 ,color(color)
	 ,pixels(size.h, vector<Color>(size.w)){

}
Component::~Component(){

}
void Component::update(){
	for(Command *c: commands){
		c->update(this);
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
