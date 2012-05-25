#include "PosChange.h"
#include "Component.h"
PosChange::PosChange(Pos from, Pos to, PosStep step, int repeats)
	:Change(repeats)
	,from(from)
	,to(to)
	,step(step)
	,isRelative(false) {
		 resetData();

}
PosChange::PosChange(Pos from, Pos to, int repeats)
	:Change(repeats)
	,from(from)
	,to(to)
	,step(from.stepTo(to))
	,isRelative(false) {
		 resetData();

}
PosChange::PosChange(PosStep step, int repeats)
	:Change(repeats)
	,step(step)
	,isRelative(true){

}
PosChange::PosChange(Pos to)
	:Change(1)
	,from(to)
	,to(to)
	,actual(to)
	,isRelative(false) {
		 resetData();

}
bool PosChange::isCompleted(){
	return repeatsCompleted();
}
void PosChange::update(Component * f){
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
			//	resetData();	
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
