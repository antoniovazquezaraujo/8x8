#ifndef SIZE_CHANGE
#define SIZE_CHANGE
class SizeChange: public Change{
public:
	SizeChange(Size from, Size to, int speed, int repeats)
		:Change(speed, repeats)
		,from(from)
		,to(to)
		,step(from.stepTo(to))
		,isRelative(false) {
			resetData();

	}
	SizeChange(SizeStep step, int speed, int repeats)
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
private:
	void resetData(){
		if(!isRelative){
			actual= from;
		}
	}
	Size from, to, actual;
	SizeStep step;
	bool isRelative;
};
#endif
