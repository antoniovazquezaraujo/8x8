#include "Tablet.h"
#include "Box.h"
void Tablet::test() {

}
Tablet::Tablet() {
	boxW = 200/ COLS;
	boxH = 200/ ROWS;
	for (int level = 0; level < LEVELS; level++) {
		levelBoxes.push_back(vector<Box>());
	}
	reset();
}
void Tablet::reset() {
	for (int level = 0; level < LEVELS; level++) {
		for (int row = 0; row < ROWS; row++) {
			for (int col = 0; col < COLS; col++) {
				colorField[level][row][col][0] = 0;
				colorField[level][row][col][1] = 0;
				colorField[level][row][col][2] = 0;
			}
		}
		vector<Box>::iterator actualBox = levelBoxes[level].begin();
		while (actualBox != levelBoxes[level].end()) {
			actualBox->reset();
		}
	}
}
void Tablet::addBox(int level, int row, int col, int height, int width,
		bool filled) {
	levelBoxes[level].push_back(Box(row, col, height, width));
}
Box & Tablet::box(int level, int n) {
	return levelBoxes[level][n];
}
Box & Tablet::lastBox(int level) {
	return levelBoxes[level][levelBoxes[level].size() - 1];
}
ColorField & Tablet::getColorField(){
	return colorField;
}
void Tablet::update() {
	for (int level = 0; level < LEVELS; level++) {
		for (unsigned int n = 0; n < levelBoxes[level].size(); n++) {
			Box & b = levelBoxes[level][n];
			if (!b.isTerminated()) {
				b.update();
			}
			for (int row = b.getRow(); row < b.getRow() + b.getHeight(); row++) {
				for (int col = b.getCol(); col < b.getCol() + b.getWidth(); col++) {
					colorField[level][row][col][0] = b.getR();
					colorField[level][row][col][1] = b.getG();
					colorField[level][row][col][2] = b.getB();
				}
			}
		}
	}
}
