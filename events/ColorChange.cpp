#include "ColorChange.h"
#include "Component.h"
ColorChange::ColorChange(Color from, Color to, ColorStep step, int repeats)
	:Change(repeats)
	,from(from)
	,to(to)
	,step(step)
	,isRelative(false) {
		 resetData();

}
ColorChange::ColorChange(Color from, Color to, int repeats)
	:Change(repeats)
	,from(from)
	,to(to)
	,step(from.stepTo(to))
	,isRelative(false) {
		 resetData();

}
ColorChange::ColorChange(ColorStep step, int repeats)
	:Change(repeats)
	,step(step)
	,isRelative(true){

}
ColorChange::ColorChange(Color to)
	:Change(1)
	,from(to)
	,to(to)
	,actual(to)
	,isRelative(false) {
		 resetData();

}
bool ColorChange::isCompleted(){
	return repeatsCompleted();
}
void ColorChange::update(Component * f){
	if(needUpdate()){
		if(isRelative){
			Color c = f->getColor();
			c+=step;
			f->setColor(c);
			setChangeCompleted();
		}else{
			f->setColor(actual);
			if(!(actual == to)){
				actual.approachTo(to, step);
			}else{
//				resetData();	
				setChangeCompleted();
			}
		}
	}
}
void ColorChange::resetData(){
	if(!isRelative){
		actual= from;
	}
}
