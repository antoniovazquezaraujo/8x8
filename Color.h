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
