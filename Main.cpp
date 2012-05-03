#include "Tablet.h"
#include "TabletView.h"
#include "Box.h"
#include "Animation.h"
int main(int argc, char *argv[]) {
	Fl::scheme("plastic");
	Fl::visible_focus(0);
	Tablet t;
	int blancas = 10, negras = 0;

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
	for (int col = 0; col < COLS ; col++) {
		t.addBox(1, col, 1, 1, 1);
		t.lastBox(1).setColor(155,0,0);
		t.lastBox(1).addAnimation(125,150,0,0,0,0,15);
		t.lastBox(1).addAnimation(185,150,0,0,0,0,30);
		t.lastBox(1).start();
		t.addBox(1, col, 6, 1, 1);
		t.lastBox(1).setColor(0,0,155);
		t.lastBox(1).addAnimation(0,0,0,0,155,150,10);
		t.lastBox(1).addAnimation(0,0,0,0,100, 80,20);
		t.lastBox(1).start();
	}
	TabletView *bw = new TabletView(t); 
	bw->show(argc, argv);
	return (Fl::run());
}
