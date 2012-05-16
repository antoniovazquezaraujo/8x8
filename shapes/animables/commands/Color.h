#ifndef COLOR
#define COLOR
#include "ColorStep"
class Color{
public:
	Color(const Color & color)
		:r(color.r),
		g(color.g),
		b(color.b){

		}
	Color(int r=0, int g=0, int b=0)
		:r(r), g(g), b(b){
		}
	ColorStep stepTo(Color c){
		return ColorStep(
			c.r==r?0:c.r>r?1:-1,
			c.g==g?0:c.g>g?1:-1,
			c.b==b?0:c.b>b?1:-1 
		);
	}
	void operator+=(ColorStep step){
		r+=step.r;
		g+=step.g;
		b+=step.b;
		r=r<0?0:r % 256;
		g=g<0?0:g % 256;
		b=b<0?0:b % 256;;
	}
	void approachTo(Color to, ColorStep step){
		r+=step.r;
		g+=step.g;
		b+=step.b;
		if(step.r >0 && r>to.r) r= to.r;
		if(step.r <0 && r<to.r) r= to.r;

		if(step.g >0 && g>to.g) g= to.g;
		if(step.g <0 && g<to.g) g= to.g;

		if(step.b >0 && b>to.b) b= to.b;
		if(step.b <0 && b<to.b) b= to.b;
	}
	int r,g,b;
};
bool operator==(const Color& a, const Color& b){
	return((a.r==b.r) && (a.g==b.g) && (a.b==b.b));
}
ostream & operator<<(ostream& o, Color c){
	o << "R:"<< c.r<<" G:"<<c.g<<" B:"<<c.b<< " ";
	return o;
}
#endif
