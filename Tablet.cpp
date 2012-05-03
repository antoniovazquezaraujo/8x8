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
void Tablet::drawRect(
		int level, 
		int c, int r, 
		int width, int height,
		Color color,
		bool filled 
	){
	for (int col = c;col < width; col++) {
		colorField[level][col][r].r = color.r;
		colorField[level][col][r].g = color.g;
		colorField[level][col][r].b = color.b;
		colorField[level][col][r+height].r = color.r;
		colorField[level][col][r+height].g = color.g;
		colorField[level][col][r+height].b = color.b;
	}
	for (int row = r; row < height; row++) {
		colorField[level][c][row].r  = color.r;
		colorField[level][c][row].g  = color.g;
		colorField[level][c][row].b  = color.b;
		colorField[level][c+width][row].r = color.r;
		colorField[level][c+width][row].g = color.g;
		colorField[level][c+width][row].b = color.b;
	}
	if(!filled){
		return;
	}
	for (int col = c+1;col < width-1; col++) {
		for (int row = r+1; row < height-1; row++) {
			colorField[level][col][row].r = color.r;
			colorField[level][col][row].g = color.g;
			colorField[level][col][row].b = color.b;
		}
	}
}
void Tablet::addBox(int level, int col, int row, int width, int height,
		bool filled) {
	levelBoxes[level].push_back(Box(col, row, width, height));
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
