#include "ColorChange.h"
#include "Form.h"
ColorChange::ColorChange(Color from, Color to, ColorStep step, int speed, int repeats)
	:Change(speed, repeats)
	,from(from)
	,to(to)
	,step(step)
	,isRelative(false) {
		 resetData();

}
ColorChange::ColorChange(Color from, Color to, int speed, int repeats)
	:Change(speed, repeats)
	,from(from)
	,to(to)
	,step(from.stepTo(to))
	,isRelative(false) {
		 resetData();

}
ColorChange::ColorChange(ColorStep step, int speed, int repeats)
	:Change(speed, repeats)
	,step(step)
	,isRelative(true){

}
bool ColorChange::isCompleted(){
	return repeatsCompleted();
}
void ColorChange::update(Form * f){
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
				resetData();	
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
