#include "Tablet.h"
#include "Box.h"
void Tablet::test() {
	Tablet t;
	for (int row = 0; row < ROWS ; row++) {
		for (int col = 0; col < COLS ; col++) {
			t.addBox(0, row, col, 1, 1);
			t.lastBox(0).setColor(0, 0, 0);
			t.lastBox(0).addAnimation(155, 0, 0, 0, 0, 0, 5);
			t.lastBox(0).addAnimation(0, 0, 100, 0, 0, 0, 5);
			t.lastBox(0).animate();
		}
	}
	for (int row = 0; row < ROWS ; row++) {
		for (int col = 0; col < COLS-4 ; col++) {
			t.addBox(1, row, col, 1, 1);
			t.lastBox(1).setColor(3, 3, 3);
			t.lastBox(1).addAnimation(10, 0, 0, 0, 0, 0, 2);
			t.lastBox(1).addAnimation(0, 0, 200, 0, 0, 0, 3);
			t.lastBox(1).animate(3);
		}
	}
	for (int row = 0; row < ROWS ; row++) {
		for (int col = 5; col < COLS ; col++) {
			t.addBox(1, row, col, 1, 1);
			t.lastBox(1).setColor(3, 3, 3);
			t.lastBox(1).addAnimation(10, 0, 0, 0, 0, 0, 2);
			t.lastBox(1).addAnimation(0, 0, 200, 0, 0, 0, 4);
			t.lastBox(1).animate(1, 2);
		}
	}
	while(cin.get()){
		t.update();
		t.paint();
	}

}
Tablet::Tablet() {
	boxW = 200/ COLS;
	boxH = 200/ ROWS;
	for (int level = 0; level < BOX_LEVELS; level++) {
		levelBoxes.push_back(vector<Box>());
	}
	reset();
}
void Tablet::reset() {
	for (int level = 0; level < BOX_LEVELS; level++) {
		for (int row = 0; row < ROWS; row++) {
			for (int col = 0; col < COLS; col++) {
				levelCells[level][row][col][0] = 0;
				levelCells[level][row][col][1] = 0;
				levelCells[level][row][col][2] = 0;
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
void Tablet::update() {
	for (int level = 0; level < BOX_LEVELS; level++) {
		for (int n = 0; n < levelBoxes[level].size(); n++) {
			Box & b = levelBoxes[level][n];
			if (!b.isTerminated()) {
				b.update();
			}
			for (int row = b.getRow(); row < b.getRow() + b.getHeight(); row++) {
				for (int col = b.getCol(); col < b.getCol() + b.getWidth(); col++) {
					levelCells[level][row][col][0] = b.getR();
					levelCells[level][row][col][1] = b.getG();
					levelCells[level][row][col][2] = b.getB();
				}
			}
		}
	}
}
void Tablet::paint() {
	for (int level = 0; level < BOX_LEVELS; level++) {
		cout <<"Nivel " << level << "-------------" << endl;
		for (int row = 0; row < ROWS; row++) {
			for (int col = 0; col < COLS; col++) {
				unsigned int color = 0;
				cout 
					<< "|"
					<< setw(3) << levelCells[level][row][col][0]
					<< setw(3) << levelCells[level][row][col][1] 
					<< setw(3) << levelCells[level][row][col][2]
					;
			}
			cout << endl;
		}
	}
}
