#include "Tablet.h"
#include "Box.h"
#include "Animation.h"
void paint(ColorField & field){
	for (int level = 0; level < LEVELS; level++) {
		cout <<"Nivel " << level << "-------------" << endl;
		for (int row = 0; row < ROWS; row++) {
			for (int col = 0; col < COLS; col++) {
				unsigned int color = 0;
				cout 
					<< "|"
					<< setw(3) << (int)field[level][row][col][0]
					<< setw(3) << (int)field[level][row][col][1] 
					<< setw(3) << (int)field[level][row][col][2]
					;
			}
			cout << endl;
		}
	}

}
int main(){
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
	cout << "Pulsando intro vas viendo la animación";
	while(cin.get()){
		t.update();
		paint(t.getColorField());
	}
}
