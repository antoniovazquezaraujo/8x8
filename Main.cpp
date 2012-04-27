#include "Tablet.h"
#include "Box.h"
#include "Animation.h"
int main(){
	//Animation::test();
	//Box::test();
	Tablet::test();
}
/*
extern "C" {
int MAMain() {


	Animation::test();
	Box::test();
	Tablet::test();

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
	bool run = true;
	bool focus = true;

	while (run) {
		if (focus) {
			t.update();
			t.paint();
			maUpdateScreen();
			maResetBacklight();
		} else {
			maWait(0);
		}

		MAEvent event;
		while (maGetEvent(&event)) {
			if (event.type == EVENT_TYPE_KEY_PRESSED) {
				switch (event.key) {
				case MAK_1:
					break;
				case MAK_2:
					break;
				case MAK_0:
					run = false;
					break;
				}
			} else if (event.type == EVENT_TYPE_POINTER_PRESSED) {
			} else if (event.type == EVENT_TYPE_CLOSE) {
				run = false;
			} else if (event.type == EVENT_TYPE_FOCUS_LOST) {
				focus = false;
			} else if (event.type == EVENT_TYPE_FOCUS_GAINED) {
				focus = true;
			}
		}
	}
	return 0;
}
}
*/
