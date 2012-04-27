#include "Box.h"
ostream & operator<<(ostream & o, const Box & b){
	o << "Estado: --------------------" << endl;
	o 
	<< endl
	<< " R: "       << (int) b.r 
	<< " G: "       << (int) b.g
	<< " B: "       << (int) b.b 
	<<endl
	<< " Times:"    << (int) b.times 
	<< " aTimes: "  << (int) b.actualTimes 
	<< " anim:"     << (int) b.numAnimation 
	<< " aAnim:"    << (int) b.actualAnimation 
	<< " allEnd: "  << (int) b.allFinished 
	<< " termin: "  << (int) b.terminated 
	<< endl
	;
	o << "Animacion actual: --------------------" << endl;
	if(b.actualAnimation < b.animations.size()){
		o << b.animations[b.actualAnimation];
	}
	o << "Fin de la animación: -----------------" << endl;
	return o;
}
void Box::test(){
	Box b(0,0,10,10);
	b.addAnimation(0,255,10,0,100,0,3);
	b.animate(2);
	while(!b.isTerminated()){
		cout << b;
		b.update();
	}
}
Box::Box(int row , int col, int height, int width) :
		row(row), col(col), height(height), width(width) {
	r = g = b = 0;
	times = 0;
	actualTimes = 0;
	numAnimation = -1;
	actualAnimation = 0;
	allFinished = true;
}
void Box::setColor(unsigned char r, unsigned char g, unsigned char b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

unsigned char Box::getR() {
	return r;
}
unsigned char Box::getG() {
	return g;
}
unsigned char Box::getB() {
	return b;
}

int Box::getRow() {
	return row;
}
int Box::getCol() {
	return col;
}
int Box::getHeight() {
	return height;
}
int Box::getWidth() {
	return width;
}
void Box::addAnimation(int fromR, int toR, int fromG, int toG, int fromB,
		int toB, int time) {
	animations.push_back(Animation(fromR, toR, fromG, toG, fromB, toB, time));
	actualAnimation = 0;
}
void Box::animate(int times ) {
	this->times = times;
	this->actualTimes = times;
	terminated = false;
	numAnimation = -1;
	reset();
}
void Box::animate(int numAnimation, int times) {
	this->numAnimation = numAnimation;
	this->times = times;
	this->actualTimes = times;
	terminated = false;
	reset();
}

void Box::update() {
	if (actualAnimation < animations.size()) {
		if (!animations[actualAnimation].isFinished()) {
			animations[actualAnimation].update();
			setColor(animations[actualAnimation].getR(),
					animations[actualAnimation].getG(),
					animations[actualAnimation].getB());
			allFinished = false;
		} else {
			animations[actualAnimation].reset();
			if (numAnimation == -1) {
				actualAnimation++;
			}else{
				nextTurn();
			}
		}
	} else {
		reset();
		nextTurn();
	}
}

bool Box::isTerminated() {
	return terminated;
}

void Box::nextTurn() {
	if (times == -1) {
		terminated = false;
	} else {
		if (actualTimes > 0) {
			actualTimes--;
			terminated = false;
		} else {
			actualTimes = times;
			terminated = true;
		}
	}
	allFinished = true;
}
void Box::reset() {
	if (numAnimation != -1) {
		actualAnimation = numAnimation;
	} else {
		actualAnimation = 0;
	}
}
void Box::stop(){

}
void Box::hide(){

}
void Box::show(){

}
void Box::fill(bool filled){

}
void Box::move(int deltaRow, int deltaCol) {
	row += deltaRow;
	col += deltaCol;
}
void Box::setPos(int row, int col) {
	this->row = row;
	this->col = col;
}
void Box::grow(int deltaHeight, int deltaWidth){

}
