#include "Prueba1.h"
#include "TabletModel.h"
#include "TabletView.h"
Prueba1::Prueba1(TabletView * view)
	:TabletController(view){

}
void Prueba1::setup(){
	Form f(0,0, 1,1);
	f.setColor(Color(255,0,0));

	Box b(0,0, 1,1, false);
	b.setColor(Color(255,0,0));

	f.addBox(b);

	f("inicio");//agrega comando "inicio". si no hay speed es la máxima
	f(Size(1,1)); //un solo dato es un setter(size, color o pos)
	f(Color(10,0,255));
	f(Pos(0,0));

	f("subir",3000);//speed es num turnos que tarda el comando
	f(Size(1,1), Size(1,8), 1); //dos datos: desde hasta, y número de veces
	f(Color(10,0,255), Color(10,210,255), ColorStep(0,30,0),1); //dos datos y step
	f(Pos(0,0), Pos(7,0), 1);

	f("dcha",3000);//speed es num turnos que tarda el comando
	f(Size(1,1), Size(1,1), 1); //dos datos: desde hasta, y número de veces
	f(Color(10,0,255), Color(10,210,255), ColorStep(0,30,0),1); //dos datos y step
	f(Pos(7,7), Pos(0,7), 1);

	f("bajar", 3000);
	f(Pos(3,3), Pos(0,0), PosStep(-1,-1), 1);
	f(Size(2,2),Size(8,8),SizeStep(2,2) , 1);
	f(Color(0,255,0), Color(240,255,0), ColorStep(80,0,0), 1);


	f.on("inicio", "subir");
	f.on("subir", "dcha");
	f.on("dcha","bajar"); //al terminar un comando vamos a otro
	f.on("bajar","subir");
	//f.on("dcha","inicio");
	f.go("inicio"); //ejecutar ahora ese comando

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
