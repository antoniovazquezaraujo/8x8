#include "Container.h" 
#include <iostream>
Container::Container(const Pos &pos, const Size &size, const Color & color)
	:Component(pos, size, color){

}
void Container::add(Component * c){
	components.push_back(c);
}
void Container::update(){
	Component::update();
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
bool Container::onClick(Pos pos){
	Component * c = getComponentAt(pos);
	if(c){
		return c->onClick(pos);	
	}else{
		return Component::onClick(pos);
	}
}
Component * Container::getComponentAt(const Pos& pos){
	for(Component* c:components){
		if(c->getPos()+this->pos == pos){
			return c;
		}
	}
	return 0;
}
