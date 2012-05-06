#include "TabletModel.h"
#include "Box.h"
//provisional
#include <iostream>
void TabletModel::test() {

}
TabletModel::TabletModel() {
	boxW = 200/ COLS;
	boxH = 200/ ROWS;
	for (int level = 0; level < LEVELS; level++) {
		levelBoxes.push_back(vector<Box>());
	}
	reset();
}
void TabletModel::reset() {
	for (int level = 0; level < LEVELS; level++) {
		for (int col = 0; col < COLS; col++) {
			for (int row = 0; row < ROWS; row++) {
				colorField[level][col][row].r = 0;
				colorField[level][col][row].g = 0;
				colorField[level][col][row].b = 0;
			}
		}
		vector<Box>::iterator actualBox = levelBoxes[level].begin();
		while (actualBox != levelBoxes[level].end()) {
			actualBox->reset();
		}
	}
}
void TabletModel::addBox(int level, int col, int row, int width, int height,
		bool filled) {
	levelBoxes[level].push_back(Box(col, row, width, height, filled));
}
void TabletModel::addBox(int level, Box box) {
	levelBoxes[level].push_back(box);
}
Box & TabletModel::box(int level, int n) {
	return levelBoxes[level][n];
}
Box & TabletModel::lastBox(int level) {
	return levelBoxes[level][levelBoxes[level].size() - 1];
}
ColorField & TabletModel::getColorField(){
	return colorField;
}
void TabletModel::update() {
	for (int level = 1; level < LEVELS; level++) {
		for (int col = 0; col < COLS; col++) {
			for (int row = 0; row < ROWS; row++) {
				colorField[level][col][row].r = 0;
				colorField[level][col][row].g = 0;
				colorField[level][col][row].b = 0;
			}
		}
	}
	for (int level = 0; level < LEVELS; level++) {
		for (unsigned int n = 0; n < levelBoxes[level].size(); n++) {
			if (!levelBoxes[level][n].isTerminated()) {
				levelBoxes[level][n].update();
			}
			Box b = levelBoxes[level][n];
			for (int col = b.getCol(); col < b.getCol() + b.getWidth(); col++) {
				for (int row = b.getRow(); row < b.getRow() + b.getHeight(); row++) {
					colorField[level][col][row].r = b.getR();
					colorField[level][col][row].g = b.getG();
					colorField[level][col][row].b = b.getB();
				}
			}
		}
	}
}
