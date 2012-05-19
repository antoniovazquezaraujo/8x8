#include "Command.h"
Command::Command()
	:finished(false){

}
void Command::update(Form* f){
	finished=true;
	for(vector<ColorChange>::iterator i = colorChanges.begin();i!=colorChanges.end();i++){
		if(!((*i).isCompleted())){
			(*i).update(f);
			finished=false;
		}
	}
	for(vector<SizeChange>::iterator i = sizeChanges.begin();i!=sizeChanges.end();i++){
		if(!((*i).isCompleted())){
			(*i).update(f);
			finished=false;
		}
	}
	for(vector<PosChange>::iterator i = posChanges.begin();i!=posChanges.end();i++){
		if(!((*i).isCompleted())){
			(*i).update(f);
			finished=false;
		}
	}
}
bool Command::isFinished(){
	return finished;
}
void Command::setSpeed(int speed){
	this->speed = speed;
	for(vector<ColorChange>::iterator i = colorChanges.begin();i!=colorChanges.end();i++){
		(*i).setSpeed(speed);
	}
	for(vector<SizeChange>::iterator i = sizeChanges.begin();i!=sizeChanges.end();i++){
		(*i).setSpeed(speed);
	}
	for(vector<PosChange>::iterator i = posChanges.begin();i!=posChanges.end();i++){
		(*i).setSpeed(speed);
	}
}
void Command::reset(){
	finished= false;
	for(vector<ColorChange>::iterator i = colorChanges.begin();i!=colorChanges.end();i++){
		(*i).restartRepeats();
		(*i).resetData();
	}
	for(vector<SizeChange>::iterator i = sizeChanges.begin();i!=sizeChanges.end();i++){
		(*i).restartRepeats();
		(*i).resetData();
	}
	for(vector<PosChange>::iterator i = posChanges.begin();i!=posChanges.end();i++){
		(*i).restartRepeats();
		(*i).resetData();
	}
}
void Command::addChange(const ColorChange &c){
	colorChanges.push_back(c);
}
void Command::addChange(const PosChange &p){
	posChanges.push_back(p);
}
void Command::addChange(const SizeChange & s){
	sizeChanges.push_back(s);
}

