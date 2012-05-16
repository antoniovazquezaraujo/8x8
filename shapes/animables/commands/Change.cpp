#include "Change.h"
	Change::Change(int speed, int repeats)
	:speed(speed)
	,initialRepeats(repeats)
	,actualRepeats(initialRepeats)
	,initialLapse(MAX_SPEED/speed)
	 ,actualLapse(initialLapse) 
	 ,changeCompleted(false){
	 }
bool Change::needUpdate(){
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
bool Change::repeatsCompleted(){
	return (actualRepeats == 0);
}
void Change::setChangeCompleted(){
	changeCompleted = true;
}
void Change::restartLapse(){
	actualLapse=initialLapse;
}
void Change::restartRepeats(){
	actualRepeats=initialRepeats;
}
bool Change::lapseCompleted(){
	return (actualLapse == 0);
}

