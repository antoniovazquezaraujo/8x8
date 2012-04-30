#include "Tablet.h"
#include "Box.h"
#include "Animation.h"
#include "TextSurface.h"
int main(){
	Tablet t;
	int blancas = 50, negras = 20;

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS - 1; col++) {
			t.addBox(0, row, col, 1, 1);
			t.lastBox(0).setColor(blancas, blancas, blancas);
			col++;
			t.addBox(0, row, col, 1, 1);
			t.lastBox(0).setColor(negras, negras, negras);
		}
		row++;
		for (int col = 0; col < COLS - 1; col++) {
			t.addBox(0, row, col, 1, 1);
			t.lastBox(0).setColor(negras, negras, negras);
			col++;
			t.addBox(0, row, col, 1, 1);
			t.lastBox(0).setColor(blancas, blancas, blancas);
		}
	}
	for (int row = 0; row < ROWS - 4; row++) {
		for (int col = 0; col < COLS - 4; col++) {
			t.addBox(0, row, col, 1, 1);
			t.lastBox(0).setColor(0, 0, 0);
			t.lastBox(0).addAnimation(155, 0, 0, 0, 0, 0, 5);
			t.lastBox(0).addAnimation(0, 0, 100, 0, 0, 0, 5);
			t.lastBox(1).addAnimation(0, 0, 0, 0, 100, 0, 5);
			t.lastBox(1).addAnimation(0, 200, 0, 0, 0, 0, 5);
			t.lastBox(1).addAnimation(0, 0, 0, 200, 0, 0, 5);
			t.lastBox(1).addAnimation(0, 0, 0, 0, 0, 200, 5);
			t.lastBox(0).animate();
		}
	}
	Fl_Double_Window win(220, 220);
	Surface s(&t, 10, 10, win.w()-20, win.h()-20);
	win.show();
	return(Fl::run());
}
