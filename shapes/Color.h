#ifndef COLOR_H
#define COLOR_H
class Color {
public:
	Color(
		unsigned char r, 
		unsigned char g, 
		unsigned char b, 
		unsigned char alpha=0
	):
		r(r), 
		g(g), 
		b(b), 
		alpha(alpha){

	}
	setR(unsigned char r){this->r = r;}
	setG(unsigned char g){this->g = g;}
	setB(unsigned char b){this->b = b;}
	unsigned char getR() {return r;}
	unsigned char getG() {return g;}
	unsigned char getB() {return b;}
    int getRGB()  const  {return (r<<16) |(g<<8) | b;} 
    int getRGBA() const  {return (r<<16) |(g<<8) | b |(alpha << 32);} 
    unsigned char getAlpha() const { return alpha; } 
    void setAlpha(unsigned char alpha) { this->alpha=alpha; }
private:
    unsigned char r,g,b;
    unsigned char alpha;    
};
#endif
