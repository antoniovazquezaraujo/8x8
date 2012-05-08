#ifndef COLOR_H
#define COLOR_H
struct Color{
	Color(
			unsigned char r=0,
			unsigned char g=0,
			unsigned char b=0)
		:r(r), g(g), b(b){

	}
	void rnd(){
		r = (unsigned char)rand()%255;
		g = (unsigned char)rand()%255;
		b = (unsigned char)rand()%255;
	}

	unsigned char r;
	unsigned char g;
	unsigned char b;
};
#endif
struct Color {
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha=0)
		:r(r), g(g), b(b), alpha(alpha){

	}
	setR(unsigned char r){this->r = r;}
	setG(unsigned char g){this->g = g;}
	setB(unsigned char b){this->b = b;}
	unsigned char getR(){return r;}
	unsigned char getG(){return g;}
	unsigned char getB(){return b;}
    int getRGB()  const {return (r<<16) |(g<<8) | b;} 
    int getRGBA() const {return (r<<16) |(g<<8) | b |(alpha << 32);} 
    unsigned char getAlpha() const { return alpha; } 
    void setAlpha(unsigned char alpha) { this->alpha=alpha; }
private:
    unsigned char r,g,b;
    unsigned char alpha;    
};
