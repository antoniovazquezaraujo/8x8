#include "PosChange.h"
#include "Form.h"
PosChange::PosChange(Pos from, Pos to, PosStep step, int speed, int repeats)
	:Change(speed, repeats)
	,from(from)
	,to(to)
	,step(step)
	,isRelative(false) {
		 resetData();

}
PosChange::PosChange(Pos from, Pos to, int speed, int repeats)
	:Change(speed, repeats)
	,from(from)
	,to(to)
	,step(from.stepTo(to))
	,isRelative(false) {
		 resetData();

}
PosChange::PosChange(PosStep step, int speed, int repeats)
	:Change(speed, repeats)
	,step(step)
	,isRelative(true){

}
bool PosChange::isCompleted(){
	return repeatsCompleted();
}
void PosChange::update(Form * f){
	if(needUpdate()){
		if(isRelative){
			Pos c = f->getPos();
			c+=step;
			f->setPos(c);
			setChangeCompleted();
		}else{
			f->setPos(actual);
			if(!(actual == to)){
				actual.approachTo(to, step);
			}else{
				resetData();	
				setChangeCompleted();
			}
		}
	}
}
void PosChange::resetData(){
	if(!isRelative){
		actual= from;
	}
}
