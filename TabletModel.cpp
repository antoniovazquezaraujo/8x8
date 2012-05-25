#include "TabletModel.h"
#include <cassert> 
TabletModel::TabletModel(){
	componentW = 200/ COLS;
	componentH = 200/ ROWS;
}
void TabletModel::newPage(string name) {
	pages.push_back(Page());
	int pageKey = pages.size()-1; 
	namesToPages[name] = pageKey; 
}
Page & TabletModel::getPage(string name){
	assert(namesToPages.find(name) != namesToPages.end());
	return pages[namesToPages[name]];
}
Page & TabletModel::getSelectedPage(){
	assert(selectedPage < pages.size());
	return pages[selectedPage];
}
void TabletModel::selectPage(string name){
	if(namesToPages.find(name) != namesToPages.end()){
		selectedPage = namesToPages[name];
	}
}
void TabletModel::selectPage(PagePosition pos){
	switch(pos){
	case FIRST:
		selectedPage = 0;
		break;
	case PREV:
		if(selectedPage>0){
			selectedPage--;
		}
		break;
	case NEXT:
		if(selectedPage < pages.size()-1){
			selectedPage++;
		}
		break;
	case LAST:
		selectedPage = pages.size()-1;
		break;
	}
}
void TabletModel::update(){
	pages[selectedPage].update();
}
