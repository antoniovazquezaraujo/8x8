#ifndef BOX_H_
#define BOX_H_
#include <stdlib.h>
#include <vector>
#include "Rect.h"
#include "Color.h"
#include "Animation.h"
#include "SpaceAnimation.h"
using namespace std;
class Box {
public:
	static void test();
	Box(int col = 0, int row = 0, int width= 1, int height= 1, bool filled=true);
	void setColor(unsigned char r, unsigned char g, unsigned char b);

	unsigned char getR();
	unsigned char getG();
	unsigned char getB();

	int getRow();
	int getCol();
	int getHeight();
	int getWidth();
	void addSpaceAnimation (int fromCol , int toCol, int fromRow, int toRow,
			int fromWidth, int toWidth, int fromHeight, int toHeight,  int time);
	void addAnimation(int fromR, int toR, int fromG, int toG, int fromB,
			int toB, int time);
	void start(int times = -1);
	void start(int numAnimation, int times);
	void startSpaceAnimation(int numAnimation, int times);
	void startSpaceAnimation(int times = -1);
	void stop();
	void update();

	bool isTerminated();
	void nextTurn();
	void nextSpaceTurn();
	void reset();
	void spaceReset();
	void hide();
	void show();
	void fill(bool filled);
	void move(int deltaRow, int deltaCol);
	void setPos(Rect r);
	void grow(int deltaHeight, int deltaWidth);
private:

	Rect rect;
	bool filled;
	unsigned char r, g, b;
	int times, actualTimes;
	int spaceTimes, actualSpaceTimes;
	vector<Animation> animations;
	//provisional
	vector<SpaceAnimation>spaceAnimations;
	unsigned int actualAnimation;
	unsigned int actualSpaceAnimation;
	int numAnimation;
	int numSpaceAnimation;
	bool terminated;
	bool spaceTerminated;
	bool allFinished;
	bool allSpaceFinished;
	bool stopped;

};

#endif
