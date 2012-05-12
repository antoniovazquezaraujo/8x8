#ifndef COLOR_H
#define COLOR_H
class ColorVariation{
public:
	ColorVariation(
		signed char r=0, 
		signed char g=0, 
		signed char b=0, 
		signed char alpha=0
	):
		r(r), 
		g(g), 
		b(b), 
		alpha(alpha){

	}
	signed char r,g,b,alpha;
};
class Color {
public:
	Color(
		unsigned char r=0, 
		unsigned char g=0, 
		unsigned char b=0, 
		unsigned char alpha=0
	):
		r(r), 
		g(g), 
		b(b), 
		alpha(alpha){

	}
	void setR(unsigned char r){this->r = r;}
	void setG(unsigned char g){this->g = g;}
	void setB(unsigned char b){this->b = b;}
    void setAlpha(unsigned char alpha) { this->alpha=alpha; }

	unsigned char getR() {return r;}
	unsigned char getG() {return g;}
	unsigned char getB() {return b;}
    unsigned char getAlpha() const { return alpha; } 

    unsigned int getRGB()  const  {return (r<<16) |(g<<8) | b;} 
    void setRGB( unsigned char r, unsigned char g, unsigned char b){
		this->r=r; this->g=g; this->b=b;
	}
//    unsigned int getRGBA() const  {return (r<<16) |(g<<8) | b |(alpha << 32);} 
//    void setRGBA( unsigned char r, unsigned char g, unsigned char b, unsigned char alpha){
//		this->r=r; this->g=g; this->b=b; this->alpha=alpha;
//	}
	void operator+=(const ColorVariation & c){
		r+=c.r;
		g+=c.g;
		b+=c.b;
		alpha+=c.alpha;
	}
private:
    unsigned char r,g,b;
    unsigned char alpha;    
};
#endif
