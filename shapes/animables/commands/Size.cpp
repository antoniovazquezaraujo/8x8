#include "Size.h" 
Size::Size(int w=0, int h=0)
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
void Size::approachTo(Size to, SizeStep step){
	w+=step.w;
	h+=step.h;

	if(step.w >0 && w>to.w) w= to.w;
	if(step.w <0 && w<to.w) w= to.w;

	if(step.h >0 && h>to.h) h= to.h;
	if(step.h <0 && h<to.h) h= to.h;
}
