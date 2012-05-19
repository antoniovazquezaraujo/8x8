#include "SizeChange.h"
#include "Form.h"
SizeChange::SizeChange(Size from, Size to, SizeStep step, int speed, int repeats)
	:Change(speed, repeats)
	,from(from)
	,to(to)
	,step(step)
	,isRelative(false) {
		 resetData();

}
SizeChange::SizeChange(Size from, Size to, int speed, int repeats)
	:Change(speed, repeats)
	,from(from)
	,to(to)
	,step(from.stepTo(to))
	,isRelative(false) {
	 resetData();

}
SizeChange::SizeChange(SizeStep step, int speed, int repeats)
	:Change(speed, repeats)
	,step(step)
	,isRelative(true){

}
bool SizeChange::isCompleted(){
	return repeatsCompleted();
}
void SizeChange::update(Form * f){
	if(needUpdate()){
		if(isRelative){
			Size c = f->getSize();
			c+=step;
			f->setSize(c);
			setChangeCompleted();
		}else{
			f->setSize(actual);
			if(!(actual == to)){
				actual.approachTo(to, step);
			}else{
		//		resetData();	
				setChangeCompleted();
			}
		}
	}
}
void SizeChange::resetData(){
	if(!isRelative){
		actual= from;
	}
}
