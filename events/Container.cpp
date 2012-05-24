#include "Container.h" 
void Container::add(Component * c){
	components.push_back(c);
}
void Container::update(){
	Container::update();
	for(Component* c:components){
		c->update();	
	}
}
void Container::paint(ColorSpace & space, const Pos& p, const Size &s){
	Component::paint(space, p, s);
	Pos newPos(pos.x+p.x, pos.y+p.y);
	for(Component* c:components){
		c->paint(space, newPos, this->size);	
	}
}
