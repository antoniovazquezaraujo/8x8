#include "Tablet.h"
#include "TabletView.h"
#include "Box.h"
#include "Animation.h"
int main(int argc, char *argv[]) {
	Fl::scheme("plastic");
	Fl::visible_focus(0);
	Tablet t;
	int time = 100;
	int x    = 0; 
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			t.addBox(0, row, col, 1, 1);
			t.lastBox(0).setColor(0,0,0);
				int r    = col*32;
				int g    = row*32;
				int b    = (row+col)*16; 
				int x    = rand()%255;
				t.lastBox(0).addAnimation(r,x,g,x,b,x,time);
				t.lastBox(0).addAnimation(x,r,x,g,x,b,time);
			t.lastBox(0).start();
		}
	}


	TabletView *bw = new TabletView(t); 
	bw->show(argc, argv);
	return (Fl::run());
}
