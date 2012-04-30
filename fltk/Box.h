#ifndef BOX_H_
#define BOX_H_

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include "Animation.h"
using namespace std;
class Box {
public:
	static void test();
	Box(int row = 0, int col = 0, int height = 1, int width = 1, bool filled=true);
	void setColor(unsigned char r, unsigned char g, unsigned char b);

	unsigned char getR();
	unsigned char getG();
	unsigned char getB();

	int getRow();
	int getCol();
	int getHeight();
	int getWidth();
	void addAnimation(int fromR, int toR, int fromG, int toG, int fromB,
			int toB, int time);
	void start(int times = -1);
	void start(int numAnimation, int times);
	void stop();
	void update();

	bool isTerminated();
	void nextTurn();
	void reset();
	void hide();
	void show();
	void fill(bool filled);
	void move(int deltaRow, int deltaCol);
	void setPos(int row, int col);
	void grow(int deltaHeight, int deltaWidth);
private:

	unsigned char r, g, b;
	bool filled;
	int row, col, height, width;
	int times, actualTimes;
	vector<Animation> animations;
	int actualAnimation;
	int numAnimation;
	bool terminated;
	bool allFinished;
	bool stopped;
	friend ostream & operator<<(ostream & o, const Box & b);
};

#endif
