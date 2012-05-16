#ifndef BASE
#define BASE
#include <iostream>
using namespace std;
#include "Box.h"
#include "Color.h"
#include "ColorStep.h"
#include "Pos.h"
#include "Size.h"
ostream & operator<<(ostream &o, const Box & b){
	o << b.pos << b.size << b.color;
	return o;
}
ostream & operator<<(ostream& o, Color c){
	o << "R:"<< c.r<<" G:"<<c.g<<" B:"<<c.b<< " ";
	return o;
}
ostream & operator<<(ostream &o, const ColorStep & c){
	o << "["<<c.r <<","<< c.g<<","<< c.b<<"]";
	return o;
}
ostream & operator<<(ostream& o, Pos p){
	o << " X:"<< p.x<<" Y:"<<p.y << " ";
	return o;
}
ostream & operator<<(ostream& o, Size s){
	o << " W:"<< s.w<<" H:"<<s.h<<" ";
	return o;
}
#endif
