#include "Size.h" 
Size::Size(int w, int h)
	:w(w), h(h){
	}
SizeStep Size::stepTo(Size s){
	return SizeStep(
		s.w==w?0:s.w>w?1:-1,
		s.h==h?0:s.h>h?1:-1 
	);
}
void Size::operator+=(SizeStep step){
	w+=step.w;
	h+=step.h;
	w=w<0?0:w;
	h=h<0?0:h;
}
Size Size::operator+(Size size){
	return Size(w+size.w, h+size.h);
}
void Size::approachTo(Size to, SizeStep step){
	w+=step.w;
	h+=step.h;

	if(step.w >0 && w>to.w) w= to.w;
	if(step.w <0 && w<to.w) w= to.w;

	if(step.h >0 && h>to.h) h= to.h;
	if(step.h <0 && h<to.h) h= to.h;
}
bool operator==(const Size & p, const Size & q){
	return ((p.w == q.w) && (p.h == q.h));
}
