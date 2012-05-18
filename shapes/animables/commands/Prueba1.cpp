#include "Prueba1.h"
#include "TabletModel.h"
#include "TabletView.h"
Prueba1::Prueba1(TabletView * view)
	:TabletController(view){

}
void Prueba1::setup(){
			Form f(0,0, 1,1);
			Box b(0,0, 1,1, false);
			b.setColor(Color(255,0,0));
			f.addBox(b);

			f.setColor(Color(255,0,0));

			Program p;
			p.addChange(SizeChange(Size(1,1), Size(1,1), 3000, 1));
			p.addChange(ColorChange(Color(10,0,255), Color(10,210,255), ColorStep(0,30,0),3000, 1));
			p.addChange(PosChange  (Pos(0,0), Pos(0,7), 3000,1));
			f.addProgram(p);

			Program p2;
			p2.addChange(ColorChange(Color(10,255,0), Color(10,255,240), ColorStep(0,0,30),3000, 1));
			p2.addChange(PosChange  (Pos(0,7), Pos(7,7), 3000,1));
			f.addProgram(p2);

			Program p3;
			p3.addChange(PosChange  (Pos(3,3), Pos(0,0), PosStep(-1,-1), 5000,2));
			p3.addChange(SizeChange (Size(2,2),Size(8,8),SizeStep(2,2) , 5000,2));
			f.addProgram(p3);

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
