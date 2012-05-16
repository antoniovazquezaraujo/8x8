#ifndef SIZE
#define SIZE
class Size{
public:
	Size(int w=0, int h=0)
		:w(w), h(h){
		}
	SizeStep stepTo(Size s){
		return SizeStep(
			s.w==w?0:s.w>w?1:-1,
			s.h==h?0:s.h>h?1:-1 
		);
	}
	void operator+=(SizeStep step){
		w+=step.w;
		h+=step.h;
		w=w<0?0:w;
		h=h<0?0:h;
	}
	void approachTo(Size to, SizeStep step){
		w+=step.w;
		h+=step.h;

		if(step.w >0 && w>to.w) w= to.w;
		if(step.w <0 && w<to.w) w= to.w;

		if(step.h >0 && h>to.h) h= to.h;
		if(step.h <0 && h<to.h) h= to.h;
	}
	int w,h;
};
bool operator==(const Size & p, const Size & q){
	return ((p.w == q.w) && (p.h == q.h));
}
ostream & operator<<(ostream& o, Size s){
	o << " W:"<< s.w<<" H:"<<s.h<<" ";
	return o;
}
#endif
