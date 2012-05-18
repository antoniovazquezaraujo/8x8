#include "Program.h"
Program::Program()
	:finished(false){

}
void Program::update(Form* f){
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
bool Program::isFinished(){
	return finished;
}
void Program::reset(){
	finished= false;
	for(vector<ColorChange>::iterator i = colorChanges.begin();i!=colorChanges.end();i++){
		(*i).restartRepeats();
	}
	for(vector<SizeChange>::iterator i = sizeChanges.begin();i!=sizeChanges.end();i++){
		(*i).restartRepeats();
	}
	for(vector<PosChange>::iterator i = posChanges.begin();i!=posChanges.end();i++){
		(*i).restartRepeats();
	}
}
void Program::addChange(const ColorChange &c){
	colorChanges.push_back(c);
}
void Program::addChange(const PosChange &p){
	posChanges.push_back(p);
}
void Program::addChange(const SizeChange & s){
	sizeChanges.push_back(s);
}

