#include "Animation.h"

Animation::Animation(int fromR , int toR , int fromG , int toG ,
		int fromB, int toB, int time) :
		fromR(fromR), toR(toR), fromG(fromG), toG(toG), fromB(fromB), toB(toB), time(
				time), finished(false) {

	rRange = toR - fromR;
	if (rRange == 0) {
		rDelta = 0;
		rLapse = -1;
		rCount = -1;
	} else if (abs(rRange) >= time) {
		rDelta = rRange / time;
		rLapse = -1;
		rCount = -1;
	} else {
		rDelta = rRange > 0 ? 1 : -1;
		rLapse = abs(time / (rRange != 0 ? rRange : 1));
		rCount = rLapse;
	}
	gRange = toG - fromG;
	if (gRange == 0) {
		gDelta = 0;
		gLapse = -1;
		gCount = -1;
	} else if (abs(gRange) >= time) {
		gDelta = gRange / time;
		gLapse = -1;
		gCount = -1;
	} else {
		gDelta = gRange > 0 ? 1 : -1;
		gLapse = abs(time / (gRange != 0 ? gRange : 1));
		gCount = gLapse;
	}
	bRange = toB - fromB;

	if (bRange == 0) {
		bDelta = 0;
		bLapse = -1;
		bCount = -1;
	} else if (abs(bRange) >= time) {
		bDelta = bRange / time;
		bLapse = -1;
		bCount = -1;
	} else {
		bDelta = bRange > 0 ? 1 : -1;
		bLapse = abs(time / (bRange != 0 ? bRange : 1));
		bCount = bLapse;
	}
	reset();
}
void Animation::reset() {
	actualTime = time;
	r = fromR;
	g = fromG;
	b = fromB;
	finished = false;
}
void Animation::update() {
	if (actualTime > 0) {
		if (rCount == -1) {
			r += rDelta;
		} else {
			if (rCount > 0) {
				rCount--;
			} else {
				r += rDelta;
				rCount = rLapse;
			}
		}
		if (gCount == -1) {
			g += gDelta;
		} else {
			if (gCount > 0) {
				gCount--;
			} else {
				g += gDelta;
				gCount = gLapse;
			}
		}
		if (bCount == -1) {
			b += bDelta;
		} else {
			if (bCount > 0) {
				bCount--;
			} else {
				b += bDelta;
				bCount = bLapse;
			}
		}
		finished = false;
		actualTime--;
	} else {
		//eliminamos residuos
		r = toR;
		g = toG;
		b = toB;
		finished = true;
	}
}
bool Animation::isFinished() {
	return finished;
}

void Animation::start() {
	actualTime = time;
}
void Animation::stop() {
	finished = true;
	actualTime = 0;
}

unsigned char Animation::getR() {
	return r;
}
unsigned char Animation::getG() {
	return g;
}
unsigned char Animation::getB() {
	return b;
}

