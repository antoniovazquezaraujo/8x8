#include "Tablet.h"
#include "TabletView.h"
#include "Box.h"
#include "Animation.h"
int main(int argc, char *argv[]) {
	Fl::scheme("plastic");
	Fl::visible_focus(0);
	Tablet t;
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			t.addBox(0, row, col, 1, 1);
			t.lastBox(0).setColor(0, 200, 200);
			t.lastBox(0).addAnimation(155, 0, 0, 0, 0, 0, 50);
			t.lastBox(0).addAnimation(0, 0, 100, 0, 200, 255, 50);
			t.lastBox(0).start();
		}
	}
	for (int row = 3; row < ROWS ; row++) {
		for (int col = 3; col < COLS-4 ; col++) {
			t.addBox(1, row, col, 1, 1);
			t.lastBox(1).setColor(3, 3, 3);
			t.lastBox(1).addAnimation(10, 0, 0, 0, 0, 0, 20);
			t.lastBox(1).addAnimation(0, 0, 200, 0, 0, 0, 30);
			t.lastBox(1).start();
		}
	}
	for (int row = 0; row < ROWS ; row++) {
		for (int col = 5; col < COLS ; col++) {
			t.addBox(1, row, col, 1, 1);
			t.lastBox(1).setColor(3, 3, 3);
			t.lastBox(1).addAnimation(255, 0, 0, 0, 0, 0, 50);
			t.lastBox(1).addAnimation(0, 0, 255, 0, 0, 0, 50);
			t.lastBox(1).addAnimation(0, 0,   0, 0,255,0, 50);
			t.lastBox(1).addAnimation(0, 255,   0, 0,255,0, 50);
			t.lastBox(1).addAnimation(0, 255, 255, 0,255,0, 50);
			t.lastBox(1).start();
		}
	}


	TabletView *bw = new TabletView(t); 
	bw->show(argc, argv);
	return (Fl::run());
}
