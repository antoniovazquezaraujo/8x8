#ifndef COLOR_CHANGE
#define COLOR_CHANGE
#include "Change.h"
#include "Color.h"
class ColorChange: public Change{
public:
	ColorChange(Color from, Color to, int speed, int repeats)
		:Change(speed, repeats)
		,from(from)
		,to(to)
		,step(from.stepTo(to))
		,isRelative(false) {
			resetData();

	}
	ColorChange(ColorStep step, int speed, int repeats)
		:Change(speed, repeats)
		,step(step)
		,isRelative(true){

	}
	bool isCompleted(){
		return repeatsCompleted();
	}
	void update(Form * f){
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
private:
	void resetData(){
		if(!isRelative){
			actual= from;
		}
	}
	Color from, to, actual;
	ColorStep step;
	bool isRelative;
};
#endif
