Pos::Pos(int x=0, int y=0)
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
void Pos::approachTo(Pos to, PosStep step){
	x+=step.x;
	y+=step.y;
	if(step.x >0 && x>to.x) x= to.x;
	if(step.x <0 && x<to.x) x= to.x;

	if(step.y >0 && y>to.y) y= to.y;
	if(step.y <0 && y<to.y) y= to.y;
}
