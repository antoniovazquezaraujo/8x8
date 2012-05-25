#include "Command.h"
#include "Button.h"
#include "Component.h"
void Command::test(){
	/*
	Command c;
	Component * b = new Button(0,0,1,1);
	c.addChange(ColorChange(Color(0,0,0), Color(10,10,10), ColorStep(1,1,1), 1000));
	while(!c.isFinished()){
		c.update(b);
		cout << "actualizando";
	}
	c.reset();
	while(!c.isFinished()){
		c.update(b);
		cout << "continuando ";
	}
	*/
	

}
Command::Command()
	:finished(false)
	,speed(MAX_SPEED){

}
void Command::update(Component* f){
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
	colorChanges.back().setSpeed(speed);;
}
void Command::addChange(const PosChange &p){
	posChanges.push_back(p);
	posChanges.back().setSpeed(speed);;
}
void Command::addChange(const SizeChange & s){
	sizeChanges.push_back(s);
	sizeChanges.back().setSpeed(speed);;
}

