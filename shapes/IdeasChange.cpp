#ifndef CHANGE_H 
#define CHANGE_H 
#include <iostream>
#include "Color.h" 
using namespace std;
enum Mode{ABSOLUTE, RELATIVE};
class Change {
public:
	Change(int time, int repeats=-1);
	void reset();
	void update();
	bool isFinished();
	void setTime(int time);
	int  getTime();
	void setRepeats(int repeats);
	int  getRepeats();

protected:
	virtual void makeChange()=0;
private:
	int  time,    actualTime;
	int  repeats, actualRepeats;
	bool finished;
};
#endif

Change::Change(int time, int repeats) :
	time(time),
	repeats(repeats){
	reset();
}
void Change::reset() {
	actualTime = time;
	actualRepeats= repeats;
	finished = false;
}
void Change::update(){
	//cout << "Updating with actualTime: " <<actualTime << "actualRepeats: " << actualRepeats << endl;
	if(actualTime > 0){
		actualTime--;
	}
	if(actualTime ==0){
		if(actualRepeats==-1){
			makeChange();
			actualTime=time;
			finished=false;	
		}else if(actualRepeats>0){
			actualRepeats--;
			makeChange();
			if(actualRepeats>0){
				actualTime=time;
				finished=false;
			}else{
				finished=true;	
			} 
		}
	}
}
bool Change::isFinished() {
	return finished;
}
void Change::setTime(int time){
	this->time = time;
	this->actualTime = time;
}
int  Change::getTime(){
	return time;	
}
void Change::setRepeats(int repeats){
	this->repeats= repeats;
	this->actualRepeats= repeats;
}
int  Change::getRepeats(){
	return repeats;	
}

//void Change::makeChange(){
//	cout << "Making changes with actualTime: " <<actualTime << "actualRepeats: " << actualRepeats << endl;
//}

class ColorChange :public Change{
public:
	ColorChange(Mode mode, 
		signed char r, 
		signed char g, 
		signed char b,    
		int time, 
		int repeats
	);
	void makeChange();
	void reset();
	Color getColor();
	ColorVariation getColorVariation();

private:
	unsigned char r,g,b;
	signed char varR,varG,varB;
};

ColorChange::ColorChange(Mode mode, 
		signed char r, 
		signed char g, 
		signed char b,    
		int time, 
		int repeats
	):
		Change(time,repeats),
		r(r),g(g),b(b){

	reset();
}
void ColorChange::reset() {
	Change::reset();
	varR=r;
	varG=g;
	varB=b;
}
Color ColorChange::getColor(){
	return Color(r,g,b);
}
ColorVariation ColorChange::getColorVariation(){
	return ColorVariation(varR, varG, varB);
}
void ColorChange::makeChange() {
	//nada que hacer.
}


int main(){
	/*
	Color c(40,40,40);
	Mode m = ABSOLUTE;
	ColorChange d(m, 50,60,70,1,2);
	while(!d.isFinished()){
		d.update();
		if(m == RELATIVE){
			c+=d.getColorVariation();
		}else{
			c= d.getColor();
		}
		cout << "Color: " << c.getR()<< "/"<<c.getB()<< "/"<<c.getR()<<endl;
	}
	*/
	Mode m=ABSOLUTE;
	Color c = Color(80,80,80);
	ColorChange e(m, -1,3,1,1,10);
	while(!e.isFinished()){
		e.update();
		if(m == RELATIVE){
			c+=e.getColorVariation();
		}else{
			c= e.getColor();
		}
		cout << "Color: " << c.getR()<< "/"<<c.getG()<< "/"<<c.getB()<<endl;
	}
}
