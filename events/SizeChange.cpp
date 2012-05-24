#include "SizeChange.h"
#include "Component.h"
SizeChange::SizeChange(Size from, Size to, SizeStep step, int repeats)
	:Change(repeats)
	,from(from)
	,to(to)
	,step(step)
	,isRelative(false) {
		 resetData();

}
SizeChange::SizeChange(Size from, Size to, int repeats)
	:Change(repeats)
	,from(from)
	,to(to)
	,step(from.stepTo(to))
	,isRelative(false) {
	 resetData();

}
SizeChange::SizeChange(SizeStep step, int repeats)
	:Change(repeats)
	,step(step)
	,isRelative(true){

}
SizeChange::SizeChange(Size to)
	:Change(1)
	,from(to)
	,to(to)
	,actual(to)
	,isRelative(false) {
		 resetData();

}
bool SizeChange::isCompleted(){
	return repeatsCompleted();
}
void SizeChange::update(Component * f){
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
