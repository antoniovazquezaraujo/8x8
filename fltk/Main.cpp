#include "Tablet.h"
#include "FLTKSurface.h"
int main() {
	Tablet t;
	for (int row = 0; row < ROWS ; row++) {
		for (int col = 0; col < COLS ; col++) {
			t.addBox(0, row, col, 1, 1);
			t.lastBox(0).setColor(0, 0, 0);
			t.lastBox(0).addAnimation(155, 0, 0, 0, 0, 0, 5);
			t.lastBox(0).addAnimation(0, 0, 100, 0, 0, 0, 5);
			t.lastBox(0).start();
		}
	}
	for (int row = 0; row < ROWS ; row++) {
		for (int col = 0; col < COLS-4 ; col++) {
			t.addBox(1, row, col, 1, 1);
			t.lastBox(1).setColor(3, 3, 3);
			t.lastBox(1).addAnimation(10, 0, 0, 0, 0, 0, 2);
			t.lastBox(1).addAnimation(0, 0, 200, 0, 0, 0, 3);
			t.lastBox(1).start(3);
		}
	}
	for (int row = 0; row < ROWS ; row++) {
		for (int col = 5; col < COLS ; col++) {
			t.addBox(1, row, col, 1, 1);
			t.lastBox(1).setColor(3, 3, 3);
			t.lastBox(1).addAnimation(10, 0, 0, 0, 0, 0, 2);
			t.lastBox(1).addAnimation(0, 0, 200, 0, 0, 0, 4);
			t.lastBox(1).start(1, 2);
		}
	}
	Fl_Double_Window win(220, 220);
	FLTKSurface s(t.getColorField(), 10, 10, win.w()-20, win.h()-20);
	win.show();
	return(Fl::run());
}

