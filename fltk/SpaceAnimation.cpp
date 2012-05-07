#include "SpaceAnimation.h"

SpaceAnimation::SpaceAnimation(int fromCol, int toCol , int fromRow , int toRow ,
			int fromWidth , int toWidth , int fromHeight, int toHeight,  int time ):
	from(fromCol, fromRow, fromWidth, fromHeight),
	to(toCol, toRow, toWidth, toHeight), 
	time( time), finished(false) {

	if(from.col == -1){
		colRange = to.col;
	}else{
		colRange = to.col - from.col;
	}
	if (colRange == 0) {
		colDelta = 0;
		colLapse = -1;
		colCount = -1;
	} else if (abs(colRange) >= time) {
		colDelta = colRange / time;
		colLapse = -1;
		colCount = -1;
	} else {
		colDelta = colRange > 0 ? 1 : -1;
		colLapse = abs(time / (colRange != 0 ? colRange : 1));
		colCount = colLapse;
	}
	if(from.row == -1){
		rowRange = to.row;
	 }else{
		rowRange = to.row- from.row;
	 }
	if (rowRange == 0) {
		rowDelta = 0;
		rowLapse = -1;
		rowCount = -1;
	} else if (abs(rowRange) >= time) {
		rowDelta = rowRange / time;
		rowLapse = -1;
		rowCount = -1;
	} else {
		rowDelta = rowRange > 0 ? 1 : -1;
		rowLapse = abs(time / (rowRange != 0 ? rowRange : 1));
		rowCount = rowLapse;
	}
	if(from.width == -1){
		widthRange = to.width;
	}else{
		widthRange = to.width- from.width;
	}
	if (widthRange == 0) {
		widthDelta = 0;
		widthLapse = -1;
		widthCount = -1;
	} else if (abs(widthRange) >= time) {
		widthDelta = widthRange / time;
		widthLapse = -1;
		widthCount = -1;
	} else {
		widthDelta = widthRange > 0 ? 1 : -1;
		widthLapse = abs(time / (widthRange != 0 ? widthRange : 1));
		widthCount = widthLapse;
	}
	if(from.height == -1){
		heightRange = to.height;
	}else{
		heightRange = to.height- from.height;
	}
	if (heightRange == 0) {
		heightDelta = 0;
		heightLapse = -1;
		heightCount = -1;
	} else if (abs(heightRange) >= time) {
		heightDelta = heightRange / time;
		heightLapse = -1;
		heightCount = -1;
	} else {
		heightDelta = heightRange > 0 ? 1 : -1;
		heightLapse = abs(time / (heightRange != 0 ? heightRange : 1));
		heightCount = heightLapse;
	}
	reset();
}
void SpaceAnimation::reset() {
	actualTime    = time;
	actual.col    = from.col   ==-1?0:from.col;
	actual.row    = from.row   ==-1?0:from.row;
	actual.width  = from.width ==-1?0:from.width;
	actual.height = from.height==-1?0:from.height;
	finished      = false;
}
void SpaceAnimation::update() {
	if (actualTime > 0) {
		if (colCount == -1) {
			actual.col += colDelta;
		} else {
			if (colCount > 0) {
				colCount--;
			} else {
				actual.col += colDelta;
				colCount = colLapse;
			}
		}
		if (rowCount == -1) {
			actual.row+= rowDelta;
		} else {
			if (rowCount > 0) {
				rowCount--;
			} else {
				actual.row+= rowDelta;
				rowCount = rowLapse;
			}
		}
		if (widthCount == -1) {
			actual.width += widthDelta;
		} else {
			if (widthCount > 0) {
				widthCount--;
			} else {
				actual.width += widthDelta;
				widthCount = widthLapse;
			}
		}
		if (heightCount == -1) {
			actual.height += heightDelta;
		} else {
			if (heightCount > 0) {
				heightCount--;
			} else {
				actual.height += heightDelta;
				heightCount = heightLapse;
			}
		}
		finished = false;
		actualTime--;
	} else {
		//eliminamos residuos
		actual.col    = to.col;
		actual.row    = to.row;
		actual.width  = to.width;
		actual.height = to.height;
		finished = true;
	}
}
bool SpaceAnimation::isFinished() {
	return finished;
}

void SpaceAnimation::start() {
	actualTime = time;
}
void SpaceAnimation::stop() {
	finished = true;
	actualTime = 0;
}

Rect SpaceAnimation::getRect(Rect original) {
	Rect r = actual;
	if(from.col == -1){
		r.col += original.col;
	}
	if(from.row == -1){
		r.row+= original.row;
	}
	if(from.width== -1){
		r.width+= original.width;
	}
	if(from.height== -1){
		r.height+= original.height;
	}
	return r;
}

