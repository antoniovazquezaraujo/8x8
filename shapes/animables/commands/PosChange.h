#ifndef POS_CHANGE
#define POS_CHANGE
class PosChange: public Change{
public:
	PosChange(Pos from, Pos to, int speed, int repeats)
		:Change(speed, repeats)
		,from(from)
		,to(to)
		,step(from.stepTo(to))
		,isRelative(false) {
			resetData();

	}
	PosChange(PosStep step, int speed, int repeats)
		:Change(speed, repeats)
		,step(step)
		,isRelative(true){

	}
	bool isCompleted(){
		return repeatsCompleted();
	}
	void update(Form * b){
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
private:
	void resetData(){
		if(!isRelative){
			actual= from;
		}
	}
	Pos from, to, actual;
	PosStep step;
	bool isRelative;
};
#endif
