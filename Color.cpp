#include "Color.h"
Color::Color(const Color & color)
	:r(color.r)
	,g(color.g)
	,b(color.b) 
	,a(color.a){

}
Color::Color(int r, int g, int b, int a)
	:r(r), g(g), b(b), a(a){
}
ColorStep Color::stepTo(const Color &c){
	return ColorStep(
		c.r==r?0:c.r>r?1:-1,
		c.g==g?0:c.g>g?1:-1,
		c.b==b?0:c.b>b?1:-1,
		c.a==a?0:c.a>a?1:-1 
	);
}
void Color::operator+=(const ColorStep &step){
	r+=step.r;
	g+=step.g;
	b+=step.b;
	a+=step.a;
	r=r<0?0:r % 256;
	g=g<0?0:g % 256;
	b=b<0?0:b % 256;
	a=a<0?0:a % 256;
}
Color Color::operator+(const Color &c)const {
	Color ret(r+c.r, g+c.g, b+c.b, a+c.a);
	ret.r=ret.r<0?0:ret.r % 256;
	ret.g=ret.g<0?0:ret.g % 256;
	ret.b=ret.b<0?0:ret.b % 256;
	ret.a=ret.a<0?0:ret.a % 256;
	return ret;
}
void Color::approachTo(const Color &to, const  ColorStep &step){
	r+=step.r;
	g+=step.g;
	b+=step.b;
	a+=step.a;

	if(step.r >0 && r>to.r) r= to.r;
	if(step.r <0 && r<to.r) r= to.r;

	if(step.g >0 && g>to.g) g= to.g;
	if(step.g <0 && g<to.g) g= to.g;

	if(step.b >0 && b>to.b) b= to.b;
	if(step.b <0 && b<to.b) b= to.b;

	if(step.a >0 && a>to.a) a= to.a;
	if(step.a <0 && a<to.a) a= to.a;
}
bool operator==(const Color& a, const Color& b){
	return((a.r==b.r) && (a.g==b.g) && (a.b==b.b) && (a.a==b.a));
}
