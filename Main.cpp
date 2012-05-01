#include "Tablet.h"
#include "TabletView.h"
#include "Box.h"
#include "Animation.h"
int main(int argc, char *argv[]) {
	Fl::scheme("plastic");
	Fl::visible_focus(0);
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


	TabletView *bw = new TabletView(t); 
	bw->show(argc, argv);
	return (Fl::run());
}
