#include "Box.h"

Box::Box(int col, int row, int width, int height, bool filled) :
		col(col), row(row), width(width), height(height), filled(filled) {
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
void Box::start(int times ) {
	stopped= false;
	this->times = times;
	this->actualTimes = times;
	terminated = false;
	numAnimation = -1;
	reset();
}
void Box::start(int numAnimation, int times) {
	stopped= false;
	this->numAnimation = numAnimation;
	this->times = times;
	this->actualTimes = times;
	terminated = false;
	reset();
}

void Box::stop() {
	stopped= true;
}

void Box::update() {
	if(stopped) return;
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
	if (actualTimes == -1) {
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
void Box::hide(){

}
void Box::show(){

}
void Box::fill(bool filled){

}
void Box::move(int deltaCol, int deltaRow) {
	col += deltaCol;
	row += deltaRow;
}
void Box::setPos(int col, int row) {
	this->col = col;
	this->row = row;
}
void Box::grow(int deltaWidth,int deltaHeight ){

}
