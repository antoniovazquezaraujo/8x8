#include "Component.h"
#include "Page.h"
#include <algorithm> 
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
void Page::removeComponent(string name){
	int key = namesToComponents[name]; 
	namesToComponents.erase(name);
	int level = componentsToLevels[key];
	componentsToLevels.erase(key);
	auto newEnd = remove(levels[level].begin(), levels[level].end(), key);
	levels[level].erase(newEnd, levels[level].end());
	components.erase(components.begin()+key);
}
Component * Page::getComponent(string name){
	return components[namesToComponents[name]];
}
vector<Component*> Page::getComponentsAt(Pos pos){
	vector<Component*> ret;
	//niveles desde el último
	vector<vector<int> >::reverse_iterator i=levels.rbegin();
	for(;i!=levels.rend();i++){
		//componentes de ese nivel
		for(vector<int>::iterator i2=(*i).begin();
				i2 != (*i).end();
				i2++){
			int componentKey = *i2;
			Component * c = components[componentKey];
			if(c->containsPoint(pos)){
				ret.push_back(c);
			}

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
