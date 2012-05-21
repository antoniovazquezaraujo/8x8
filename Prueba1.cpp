#include "Prueba1.h"
#include "TabletModel.h"
#include <cassert> 
#include "TabletView.h"
Prueba1::Prueba1(TabletView * view)
	:TabletController(view){

}
void Prueba1::setup(){
	/*
	Form f(0,0, 1,1);
	f.setColor(Color(255,0,0));

	Box b(0,0, 1,1, false);
	b.setColor(Color(255,0,0));
	f.addBox(b);

	Box c(-1,-1, 1,1, false);
	c.setColor(Color(0,0,100));
	f.addBox(c);

	f("inicio");//agrega comando "inicio". si no hay speed es la máxima
	f(Size(1,1)); //un solo dato es un setter(size, color o pos)
	f(Color(10,0,255));
	f(Pos(0,0));

	f("dcha",1000);//speed es num turnos que tarda el comando
	f(Size(1,1), Size(1,1), 1); //dos datos: desde hasta, y número de veces
	f(Color(10,0,255), Color(10,210,255), ColorStep(0,30,0),1); //dos datos y step
	f(Pos(7,7), Pos(0,7), 1);

	f("bajar", 9000);
	f(Pos(3,3), Pos(0,0), PosStep(-1,-1), 1);
	f(Size(2,2),Size(8,8),SizeStep(2,2) , 1);
	f(Color(0,255,0), Color(240,255,0), ColorStep(80,0,0), 1);

	f("subir",6000);//speed es num turnos que tarda el comando
	f(Size(1,1), Size(1,8), 1); //dos datos: desde hasta, y número de veces
	f(Color(10,0,255), Color(10,210,255), ColorStep(0,30,0),1); //dos datos y step
	f(Pos(0,0), Pos(7,0), 1);

	f("fin");
	f(Pos(1,5));
	f(Size(3,1));
	f(Color(255,0,0));

	//Si se comentan los "on", se ejecutan todos, uno tras otro
	//f.on("inicio", "subir");
	//f.on("subir", "dcha");
	//f.on("dcha","bajar"); 
	//f.on("bajar","fin");

	f.go("inicio"); //ejecutar ahora ese comando

	model->addForm("uno", 0, f);
	*/
}
void Prueba1::start(){
	model->newPage("pagina0");
	model->selectPage(FIRST);
	Form f(0,0,  1,1);
	f.setColor(Color(255,0,0));
	model->getSelectedPage().addForm("uno", 0, f);
	view->start();
}
void Prueba1::stop(){
	view->stop();
}
void Prueba1::onClick(int col, int row){
	//Form & f = model->getForm("uno");
	//Box b(col, row, 1,1, false);
	//b.setColor(Color(255,255,0));
	//f.addBox(b);
}
void Prueba1::onDoubleClick(int col, int row){
	vector<Form *> forms = model->getSelectedPage().getFormsAt(Pos(col, row));
	for(vector<Form*>::iterator i= forms.begin();
			i!=forms.end();
			i++){
		(*i)->setColor(Color(123,234,4));
	}
}
void Prueba1::onRelease(int col, int row){
}
void Prueba1::onDrag(int col, int row){
	Form & f = model->getSelectedPage().getForm("uno");
	Box b(col, row, 1,1, false);
	//b.setColor(Color(255,0,0));
	f.addBox(b);

//	f("a", 8000);
//	f(Color(0,255,0), Color(240,255,0), ColorStep(80,0,0), 1);
//	f(SizeStep(1,1),1);
//
//	f("b", 8000);
//	f(Color(0,255,255), Color(240,255,255), ColorStep(80,0,0), 1);
//	f(SizeStep(-1,-1),1);
//
//	f.on("a","b");
//	f.on("b","a");
//	f.go("a");
}
