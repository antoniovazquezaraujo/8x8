#include "FltkTabletView.h"
#include "Prueba1.h"
int main(){
	Prueba1 * p = new Prueba1(new FltkTabletView());
	p->setup();
	p->start();
}
