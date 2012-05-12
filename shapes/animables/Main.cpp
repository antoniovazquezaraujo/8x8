#include <iostream> 
using namespace std;
#include "Color.h"
#include "ColorAnimable.h"
ostream & operator<<(ostream & o, Color c){
	o << "["<<c.getR()<<"|"<<c.getG()<<"|"<<c.getB()<<"]";
}
int main(){
	ColorAnimable a;
	a.addChange(0,100,0,100,0,100,40,3);
	a.update();
	Color c = a.getColor();
	cout << c;
}
