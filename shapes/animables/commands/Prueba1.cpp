#include "Prueba1.h"
#include "TabletModel.h"
#include "TabletView.h"
Prueba1::Prueba1(TabletView * view)
	:TabletController(view){

}
void Prueba1::setup(){
			Form f(1,1, 0,0);
			Box b(0,0, 1,1, false);
			f.addBox(b);
			f.setColor(Color(255,0,0));

			Program p;
			p.addChange(ColorChange(ColorStep(-255,255,0), 3000,1));
			p.addChange(PosChange  (Pos(0,0), Pos(0,7), 3000,1));
			f.addProgram(p);

			Program p2;
			p2.addChange(ColorChange(ColorStep(255,-255,0), 3000,1));
			p2.addChange(PosChange  (Pos(0,7), Pos(7,0), 3000,1));
			f.addProgram(p2);

			model->addForm(0, f);
}
void Prueba1::start(){
	view->start();
}
void Prueba1::stop(){
	view->stop();
}
void Prueba1::onClick(int col, int row){
}
void Prueba1::onRelease(int col, int row){
}
void Prueba1::onDrag(int col, int row){
}
