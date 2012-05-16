#include "Program.h"
Program::Program()
	:finished(false){

}
void Program::update(Form* f){
	finished=true;
	for(int i=0; i< colorChanges.size();i++){
		if(!colorChanges[i].isCompleted()){
			colorChanges[i].update(f);
			finished=false;
		}
	}
	for(int i=0; i< posChanges.size();i++){
		if(!posChanges[i].isCompleted()){
			posChanges[i].update(f);
			finished=false;
		}
	}
	for(int i=0; i< sizeChanges.size();i++){
		if(!sizeChanges[i].isCompleted()){
			sizeChanges[i].update(f);
			finished=false;
		}
	}
}
bool Program::isFinished(){
	return finished;
}
void Program::reset(){
	finished= false;
}
void Program::addChange(ColorChange c){
	colorChanges.push_back(c);
}
void Program::addChange(PosChange p){
	posChanges.push_back(p);
}
void Program::addChange(SizeChange s){
	sizeChanges.push_back(s);
}

