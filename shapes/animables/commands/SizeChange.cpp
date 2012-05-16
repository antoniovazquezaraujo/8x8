#include "SizeChange.h"
#include "Form.h"
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
void SizeChange::update(Form * b){
	if(needUpdate()){
		if(isRelative){
			Size c = b->getSize();
			c+=step;
			b->setSize(c);
			setChangeCompleted();
		}else{
			actual.approachTo(to, step);
			b->setSize(actual);
			if(actual== to){
				resetData();	
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
