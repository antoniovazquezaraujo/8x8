#ifndef BOX
#define BOX
#include "Color.h"
#include "Pos.h"
#include "Size.h"
class Box{
public:
	void setColor(Color color){
	Color getColor(){
	void setPos(Pos pos){
	Pos getPos(){
	void setSize(Size size){
	Size getSize(){
	friend ostream & operator<<(ostream& o, const Box & b);
	Color color;
	Pos pos;
	Size size;
};
ostream & operator<<(ostream &o, const Box & b){
	o << b.pos << b.size << b.color;
	return o;
}
#endif
