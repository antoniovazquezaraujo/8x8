#include "Component.h"
#include "Page.h"
Page::Page()
	:levels(1, vector<int>())
	,colorBlock(1, COLS, ROWS){
	this->componentW = 200/ COLS;
	this->componentH = 200/ ROWS;
	reset();
}
Page::~Page(){
	for(vector<Component*>::iterator i = components.begin();
			i != components.end(); 
			i++){
		delete (*i);
	}
}
void Page::reset() {
	colorBlock.reset();
}
void Page::addComponent(string name, int level, Component * component) {
	if(level >= colorBlock.getNumLevels()){
		colorBlock.addLevel();
		levels.push_back(vector<int>());
	}
	components.push_back(component);
	int componentKey = components.size()-1; 
	namesToComponents[name] = componentKey; 
	levels[level].push_back(componentKey);
	componentsToLevels[componentKey]=level;
}
Component * Page::getComponent(string name){
	return components[namesToComponents[name]];
}
vector<Component*> Page::getComponentsAt(Pos pos){
	// ordenar esto por NIVEL!!
	vector<Component*> ret;
	for(vector<Component*>::iterator i = components.begin();
			i != components.end(); 
			i++){
		if((*i)->containsPoint(pos)){
			ret.push_back((*i));
		}
	}
	return ret;
}
ColorBlock & Page::getColorBlock(){
	return colorBlock; 
}
void Page::update() {
	reset();
	for(Component * c: components){
		c->update();
	}
	for (int level = 0; level < colorBlock.getNumLevels(); level++) {
		for (unsigned int n = 0; n < levels[level].size(); n++) {
			Component *c = components[levels[level][n]];
			c->paint(colorBlock[level], Pos(0,0), Size(COLS, ROWS));
		}
	}
}
