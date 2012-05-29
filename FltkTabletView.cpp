#include "FltkTabletView.h" 
#include "TabletController.h" 
#include "TabletModel.h" 

FltkTabletView::FltkTabletView()
	: Fl_Double_Window(20,20,640,640,"8x8"){
	end();
	setup();
}

FltkTabletView::~FltkTabletView() {
	Fl::remove_timeout((Fl_Timeout_Handler)timeout_cb, (void *)this);
}

void FltkTabletView::start(){
	show();
	Fl::run();
}
void FltkTabletView::stop(){

}
void FltkTabletView::setup() {
	Fl::scheme("plastic");
	Fl::visible_focus(0);
	Fl::add_timeout(DRAW_TIME, (Fl_Timeout_Handler)timeout_cb, (void *)this);
	redraw();
}

void FltkTabletView::onDoubleClick(int col, int row) {
	controller->onDoubleClick(col, row);
}
void FltkTabletView::onClick(int col, int row) {
	controller->onClick(col, row);
}
void FltkTabletView::onDrag(int col, int row) {
	controller->onDrag(col, row);
}
void FltkTabletView::onRelease(int col, int row) {
	controller->onRelease(col, row);
}


void FltkTabletView::draw() {
	int level=0;
	model->update();
	ColorBlock &f = model->getSelectedPage().getColorBlock();
	for (int col= 0; col< COLS; col++ ){
		//Aquí hay que manejar la transparencia, y que cada
		//nivel tenga en cuenta al anterior, si quiere.
		//Transparencia por nivel o por componente???
		//Buena pregunta. Lo veremos más adelante.
		for (int row = 0; row< ROWS; row++ ){
			level=0;
			float percent= f[level][col][row].a /255;
			f[level][col][row].r*= percent;
			f[level][col][row].g*= percent;
			f[level][col][row].b*= percent;
			for (level = 1; level < f.getNumLevels(); level++ ){
				float percent= f[level][col][row].a /255;
				f[level][col][row].r= f[level-1][col][row].r*(1-percent) + f[level][col][row].r* percent;
				f[level][col][row].g= f[level-1][col][row].g*(1-percent) + f[level][col][row].g* percent;
				f[level][col][row].b= f[level-1][col][row].b*(1-percent) + f[level][col][row].b* percent;
			}
			fl_color(
				f[level-1][col][row].r,
				f[level-1][col][row].g,
				f[level-1][col][row].b
			);
			fl_rectf( 
				col*BLOCK_SIZE, 
				row*BLOCK_SIZE, 
				BLOCK_SIZE, 
				BLOCK_SIZE
			);
		}
	}
}

int FltkTabletView::handle(int event) {
	if (Fl_Double_Window::handle(event)){
		return (1);
	} 
	int col = Fl::event_x() / BLOCK_SIZE;
	int row = Fl::event_y() / BLOCK_SIZE;
	if(col >= COLS) col=COLS-1;
	if(row >= ROWS) row=ROWS-1;
	switch (event) {
	case FL_PUSH :
		//El doble click va muy lento aqui.
		//Arreglar esto!!
	//	if(Fl::event_clicks() != 0){
	//		onDoubleClick(col, row);
	//	}else{
			onClick(col, row);
	//	}
		break;
	case FL_DRAG:
		onDrag(col, row);
		break;
	case FL_RELEASE:
		onRelease(col, row);
		break;
	}
	return (1);
}

void FltkTabletView::timeout_cb(FltkTabletView *bw) {
	bw->redraw();
	Fl::repeat_timeout(DRAW_TIME, (Fl_Timeout_Handler)timeout_cb, (void *)bw);
}

