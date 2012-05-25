#include "Change.h"
using namespace std;
	Change::Change(int repeats)
	:initialRepeats(repeats)
	,actualRepeats(initialRepeats)
	,changeCompleted(false){
		setSpeed(MAX_SPEED);
}

void Change::setSpeed(int speed){
	this->speed = speed;
	initialLapse= MAX_SPEED/speed;
	actualLapse = initialLapse;
}
bool Change::needUpdate(){
	if(!repeatsCompleted()){
		if(lapseCompleted()){
			restartLapse();
			if(changeCompleted){
				actualRepeats--;
				changeCompleted=false;
				return false; 
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

