#include "Box.h"

Box::Box(int col, int row, int width, int height, bool filled) :
		rect(col,row,width,height), filled(filled) {
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
	return rect.row;
}
int Box::getCol() {
	return rect.col;
}
int Box::getHeight() {
	return rect.height;
}
int Box::getWidth() {
	return rect.width;
}
void Box::addSpaceAnimation (int fromCol , int toCol, int fromRow, int toRow,
			int fromWidth, int toWidth, int fromHeight, int toHeight,  int time){
	spaceAnimations.push_back(SpaceAnimation(fromCol, toCol, fromRow, toRow, fromWidth, toWidth, fromHeight, toHeight, time));
	actualSpaceAnimation = 0;
}
void Box::addAnimation(int fromR, int toR, int fromG, int toG, int fromB,
		int toB, int time) {
	animations.push_back(Animation(fromR, toR, fromG, toG, fromB, toB, time));
	actualAnimation = 0;
}
void Box::startSpaceAnimation(int numAnimation, int times){
	stopped= false;
	this->spaceTimes = times;
	this->actualSpaceTimes = times;
	spaceTerminated = false;
	numSpaceAnimation = -1;
	reset();
}
void Box::startSpaceAnimation(int times){
	stopped= false;
	this->spaceTimes = times;
	this->actualSpaceTimes = times;
	spaceTerminated = false;
	numSpaceAnimation = -1;
	reset();
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
	if (actualSpaceAnimation < spaceAnimations.size()) {
		if (!spaceAnimations[actualSpaceAnimation].isFinished()) {
			spaceAnimations[actualSpaceAnimation].update();
			setPos(spaceAnimations[actualSpaceAnimation].getRect(rect));
			allSpaceFinished = false;
		} else {
			spaceAnimations[actualSpaceAnimation].reset();
			if (numSpaceAnimation == -1) {
				actualSpaceAnimation++;
			}else{
				nextSpaceTurn();
			}
		}
	} else {
		spaceReset();
		nextSpaceTurn();
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
void Box::nextSpaceTurn() {
	if (actualSpaceTimes == -1) {
		spaceTerminated = false;
	} else {
		if (actualSpaceTimes > 0) {
			actualSpaceTimes--;
			spaceTerminated = false;
		} else {
			actualSpaceTimes = spaceTimes;
			spaceTerminated = true;
		}
	}
	allSpaceFinished = true;
}
void Box::spaceReset() {
	if (numSpaceAnimation != -1) {
		actualSpaceAnimation = numSpaceAnimation;
	} else {
		actualSpaceAnimation = 0;
	}
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
	rect.col += deltaCol;
	rect.row += deltaRow;
}
void Box::setPos(Rect r) {
	rect = r;
}
void Box::grow(int deltaWidth,int deltaHeight ){

}
