#include "Box.h"
#include <iostream> 

Box::Box(int col, int row, int width, int height, bool filled) :
		rect(col,row,width,height), filled(filled) {
	r = g = b = 0;
	times = 0;
	actualTimes = 0;
	numColorChange = -1;
	numPosChange = -1;
	numSizeChange = -1;

	actualColorChange = 0;
	actualPosChange = 0;
	actualSizeChange = 0;

	allFinished = true;
	terminated= false;
	spaceTerminated= false;
	sizeTerminated= false;
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
void Box::addPosChange (int colDelta, int rowDelta, int time, int repetitions){
	posChanges.push_back(PosChange(colDelta, rowDelta, time, repetitions));
	actualPosChange = 0;
}
void Box::addSizeChange (int widthDelta, int heightDelta, int time, int repetitions){
	sizeChanges.push_back(SizeChange(widthDelta, heightDelta, time, repetitions));
	actualSizeChange = 0;
}
void Box::addColorChange(int fromR, int toR, int fromG, int toG, int fromB,
		int toB, int time) {
	colorChanges.push_back(ColorChange(fromR, toR, fromG, toG, fromB, toB, time));
	actualColorChange = 0;
}
void Box::startPosChanges(int numPosChange){
	stopped= false;
	this->numPosChange = numPosChange;
	spaceTerminated = false;
	spaceReset();
}
void Box::startSizeChanges(int numSizeChange){
	stopped= false;
	this->numSizeChange = numSizeChange;
	sizeTerminated = false;
	sizeReset();
}
void Box::startColorChanges(int times ) {
	stopped= false;
	this->numColorChange = -1;
	this->times = times;
	this->actualTimes = times;

	terminated = false;
	reset();
}
void Box::startColorChanges(int numColorChange, int times) {
	stopped= false;
	this->numColorChange = numColorChange;
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
	if (actualColorChange < colorChanges.size()) {
		if (!colorChanges[actualColorChange].isFinished()) {
			colorChanges[actualColorChange].update();
			setColor(colorChanges[actualColorChange].getR(),
					colorChanges[actualColorChange].getG(),
					colorChanges[actualColorChange].getB());
			allFinished = false;
		} else {
			colorChanges[actualColorChange].reset();
			if (numColorChange == -1) {
				actualColorChange++;
			}else{
				nextTurn();
			}
		}
	} else {
		reset();
		nextTurn();
	}
	if (actualPosChange < posChanges.size()) {
		if (!posChanges[actualPosChange].isFinished()) {
			posChanges[actualPosChange].update();
			Rect rr = posChanges[actualPosChange].getRect(rect);
			setPos(rr);
		} else {
			posChanges[actualPosChange].reset();
			if (numPosChange == -1) {
				actualPosChange++;
			}
		}
	} else {
		spaceTerminated =true;
	}
	if (actualSizeChange < sizeChanges.size()) {
		if (!sizeChanges[actualSizeChange].isFinished()) {
			sizeChanges[actualSizeChange].update();
			Rect rr = sizeChanges[actualSizeChange].getRect(rect);
			setPos(rr); //cambiar el nombre de esto.
		} else {
			sizeChanges[actualSizeChange].reset();
			if (numSizeChange == -1) {
				actualSizeChange++;
			}
		}
	} else {
		sizeTerminated =true;
	}
}

bool Box::isTerminated() {
	return terminated && spaceTerminated && sizeTerminated;
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
void Box::spaceReset() {
	if (numPosChange != -1) {
		actualPosChange = numPosChange;
	} else {
		actualPosChange = 0;
	}
}
void Box::sizeReset() {
	if (numSizeChange != -1) {
		actualSizeChange = numSizeChange;
	} else {
		actualSizeChange = 0;
	}
}
void Box::reset() {
	if (numColorChange != -1) {
		actualColorChange = numColorChange;
	} else {
		actualColorChange = 0;
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
Rect Box::getPos() {
	return rect;
}
void Box::grow(int deltaWidth,int deltaHeight ){
	rect.width+=deltaWidth;
	rect.height+=deltaHeight;
}
void Box::setSize(int width,int height ){
	rect.width=width;
	rect.height=height;
}
