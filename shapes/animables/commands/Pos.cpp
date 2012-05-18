#include "Pos.h"
Pos::Pos(int x, int y)
	:x(x), y(y){

}
PosStep Pos::stepTo(Pos p){
	return PosStep(
		p.x==x?0:p.x>x?1:-1,
		p.y==y?0:p.y>y?1:-1 
	);
}
void Pos::operator+=(PosStep step){
	x+=step.x;
	y+=step.y;
}
Pos Pos::operator+(Pos pos){
	return Pos(x+pos.x, y+pos.y);
}
void Pos::approachTo(Pos to, PosStep step){
	x+=step.x;
	y+=step.y;
	if(step.x >0 && x>to.x) x= to.x;
	if(step.x <0 && x<to.x) x= to.x;

	if(step.y >0 && y>to.y) y= to.y;
	if(step.y <0 && y<to.y) y= to.y;
}
bool operator==(const Pos & p, const Pos & q){
	return ((p.x == q.x) && (p.y == q.y));
}
