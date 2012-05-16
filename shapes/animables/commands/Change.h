#ifndef CHANGE 
#define CHANGE 
const int MAX_SPEED=10000;
class Change{
public:
	Change(int speed, int repeats)
		:speed(speed)
		,initialRepeats(repeats)
		,actualRepeats(initialRepeats)
		,initialLapse(MAX_SPEED/speed)
		,actualLapse(initialLapse) 
		,changeCompleted(false){
	}
protected:
	bool needUpdate(){
		if(!repeatsCompleted()){
			if(lapseCompleted()){
				restartLapse();
				if(changeCompleted){
					actualRepeats--;
					changeCompleted=false;
				}
				return true;
			}else{
				actualLapse--;
			}
		}
		return false;
	}
	bool repeatsCompleted(){
		return (actualRepeats == 0);
	}
	void setChangeCompleted(){
		changeCompleted = true;
	}
private:	
	void restartLapse(){
		actualLapse=initialLapse;
	}
	void restartRepeats(){
		actualRepeats=initialRepeats;
	}
	bool lapseCompleted(){
		return (actualLapse == 0);
	}

	int speed;
	int initialLapse, actualLapse; 
	int initialRepeats, actualRepeats;
	bool changeCompleted;
};
#endif
