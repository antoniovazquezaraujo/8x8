#include "TabletController.h"
TabletController::TabletController()
	:view(new TabletView(tablet, this)){
	Fl::scheme("plastic");
	Fl::visible_focus(0);
}
void TabletController::setup(){
	int time = 60;
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			tablet.addBox(0, row, col, 1, 1);
			tablet.lastBox(0).setColor(0,0,0);
			unsigned char r    = col*32;
			unsigned char g    = row*32;
			unsigned char b    = row*16+col*16;
			unsigned char x    = 0; 
			tablet.lastBox(0).addAnimation(r,x,g,x,b,x,time);
			for(int n=0; n<100; n++){
				unsigned char r    = rand()%255;
				unsigned char g    = r/2; 
				unsigned char b    = 255-g; 
				unsigned char x    = rand()%255; 
				time = 10 + rand()%200; 
				tablet.lastBox(0).addAnimation(r,x,g,x,b,x,time);
				tablet.lastBox(0).addAnimation(x,r,x,g,x,b,time);
			}
			tablet.lastBox(0).start();
		}
	}
}
void TabletController::start(){
	view->show();
	(Fl::run());
}
void TabletController::end(){

}
void TabletController::onClick(int row, int col){

}
void TabletController::onRelease(int row, int col){

}
void TabletController::onDrag(int row, int col){

}
