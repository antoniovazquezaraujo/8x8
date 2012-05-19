#ifndef BOX_H_
#define BOX_H_
#include <stdlib.h>
#include <vector>
#include "Rect.h"
#include "Color.h"
#include "ColorChange.h"
#include "PosChange.h"
#include "SizeChange.h"
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
	void addSizeChange (int widthDelta, int heightDelta, int time, int repetitions);
	void addPosChange (int colDelta, int rowDelta, int time, int repetitions);
	void addColorChange(int fromR, int toR, int fromG, int toG, int fromB,
			int toB, int time);
	void startColorChanges(int times = -1);
	void startColorChanges(int numColorChange, int times);
	void startPosChanges(int numPosChange=-1);
	void startSizeChanges(int numSizeChange=-1);
	void stop();
	void update();

	bool isTerminated();
	void nextTurn();
	void reset();
	void spaceReset();
	void sizeReset();
	void hide();
	void show();
	void fill(bool filled);
	void move(int deltaRow, int deltaCol);
	void setPos(Rect r);
	void setSize(int width, int height);
	Rect getPos();
	void grow(int deltaHeight, int deltaWidth);
private:

	Rect rect;
	bool filled;
	unsigned char r, g, b;
	int times, actualTimes;
	int spaceTimes, actualSpaceTimes;
	int sizeTimes, actualSizeTimes;

	vector<ColorChange> colorChanges;
	vector<PosChange>posChanges;
	vector<SizeChange>sizeChanges;

	unsigned int actualColorChange;
	unsigned int actualPosChange;
	unsigned int actualSizeChange;

	int numColorChange;
	int numPosChange;
	int numSizeChange;

	bool terminated;
	bool spaceTerminated;
	bool sizeTerminated;
	bool allFinished;
	bool allSpaceFinished;
	bool allSizeFinished;
	bool stopped;

};

#endif
