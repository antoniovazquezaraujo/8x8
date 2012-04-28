#include <iostream>
#include <vector>
using namespace std;
class Surface{
public:
	void paint(int row, int col, int height, int width, int r, int g, int b){
		cout << "Base";

	}
};
class TextSurface:public Surface{
public:
	void paint(int row, int col, int height, int width, int r, int g, int b){
		cout << "Texto" << row << col << height << width << r << g << b; 
	}
};
class GraphicSurface: public Surface{
public:
	void paint(int row, int col, int height, int width, int r, int g, int b){
		cout <<"Graficos" << row << col << height << width << r	<< g << b; 
	}
};
template <typename T>
class Tablet{
public:
	void paint(T & surface){
		surface.paint(1,2, 8,8, 255,255,r);
	}
	void update(){
		r++;
	}
private:
	int r, g, b;
};
int Txtmain(){
	Tablet<TextSurface> t;
	TextSurface surface;
	for(int n=0; n<3; n++){
		t.update();
		t.paint(surface);
	}
}
int FLmain(){
	Tablet<GraphicSurface> t;
	GraphicSurface surface;
	for(int n=0; n<3; n++){
		t.update();
		t.paint(surface);
	}
}
	typedef unsigned char Cell [3];
	typedef Cell Row [8];
	typedef Row Level [8];
	typedef Level ColorField[2];
	ColorField g;
void f(ColorField g){
	cout << g[0][1][2][3];
}
int main(){
	//Txtmain();
	//FLmain();
	g[0][1][2][3]='x';
	f(g);
}
