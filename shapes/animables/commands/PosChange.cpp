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
void PosChange::update(Form * b){
	if(needUpdate()){
		if(isRelative){
			Pos c = b->getPos();
			c+=step;
			b->setPos(c);
			setChangeCompleted();
		}else{
			actual.approachTo(to, step);
			b->setPos(actual);
			if(actual== to){
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
