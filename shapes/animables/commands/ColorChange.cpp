#include "ColorChange.h"
#include "Form.h"
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
			actual.approachTo(to, step);
			f->setColor(actual);
			if(actual == to){
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
