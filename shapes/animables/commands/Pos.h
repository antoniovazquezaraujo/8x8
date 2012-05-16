#ifndef POS
#define POS
class Pos{
public:
	Pos(int x=0, int y=0)
		:x(x), y(y){

	}
	PosStep stepTo(Pos p){
		return PosStep(
			p.x==x?0:p.x>x?1:-1,
			p.y==y?0:p.y>y?1:-1 
		);
	}
	void operator+=(PosStep step){
		x+=step.x;
		y+=step.y;
	}
	void approachTo(Pos to, PosStep step){
		x+=step.x;
		y+=step.y;
		if(step.x >0 && x>to.x) x= to.x;
		if(step.x <0 && x<to.x) x= to.x;

		if(step.y >0 && y>to.y) y= to.y;
		if(step.y <0 && y<to.y) y= to.y;
	}
	int x,y;
};
bool operator==(const Pos & p, const Pos & q){
	return ((p.x == q.x) && (p.y == q.y));
}
ostream & operator<<(ostream& o, Pos p){
	o << " X:"<< p.x<<" Y:"<<p.y << " ";
	return o;
}
#endif
