#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class ColorStep{
public:
	ColorStep(int r=0, int g=0, int b=0)
		:r(r), g(g), b(b){
		}
	signed int r,g,b;
};
ostream & operator<<(ostream &o, const ColorStep & c){
	o << "["<<c.r <<","<< c.g<<","<< c.b<<"]";
	return o;
}
////////////////
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
////////////////
class SizeStep{
public:
	SizeStep(int w=0, int h=0)
		:w(w),h(h){
		}
	signed int w, h; 
};
////////////////
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
	o << "W:"<< s.w<<"H:"<<s.h<<endl;
	return o;
}
////////////////
class PointStep{
public:
	PointStep(int x=0, int y=0)
		:x(x),y(y){
		}
	signed int x, y; 
};
////////////////
class Point{
public:
	Point(int x=0, int y=0)
		:x(x), y(y){

	}
	PointStep stepTo(Point p){
		return PointStep(
			p.x==x?0:p.x>x?1:-1,
			p.y==y?0:p.y>y?1:-1 
		);
	}
	void operator+=(PointStep step){
		x+=step.x;
		y+=step.y;
	}
	void approachTo(Point to, PointStep step){
		x+=step.x;
		y+=step.y;
		if(step.x >0 && x>to.x) x= to.x;
		if(step.x <0 && x<to.x) x= to.x;

		if(step.y >0 && y>to.y) y= to.y;
		if(step.y <0 && y<to.y) y= to.y;
	}
	int x,y;
};
bool operator==(const Point & p, const Point & q){
	return ((p.x == q.x) && (p.y == q.y));
}
ostream & operator<<(ostream& o, Point p){
	o << "X:"<< p.x<<"Y:"<<p.y<<endl;
	return o;
}
class Box{
public:
	void setColor(Color color){
		this->color = color;
	}
	Color getColor(){
		return color;
	}
	void setPos(Point pos){
		this->pos=pos;
	}
	Point getPos(){
		return pos;
	}
	void setSize(Size size){
		this->size = size;
	}
	Size getSize(){
		return size;
	}
	/*
	void setSound(Sound sound){
		this->sound = sound;
	}
	Sound getSound(){
		return sound;
	}
	void update(){
		for(vector<Program>::iterator i= programs.begin();
				i!= programs.end();
				i++){
			i->update(this);
		}
	}
	*/
	friend ostream & operator<<(ostream& o, const Box & b);
	Color color;
	Point pos;
	Size size;
	/*
	Sound sound;
	vector<Program> programs;
	*/
};
ostream & operator<<(ostream &o, const Box & b){
	o << b.pos << b.size << b.color;
	return o;
}
const int MAX_SPEED=10000;
class Change{
public:
	Change(int speed, int repeats)
		:speed(speed)
		,initialRepeats(repeats)
		,actualRepeats(initialRepeats)
		,initialLapse(MAX_SPEED/speed)
		,actualLapse(initialLapse) 
		,changeCompleted(false){
	}
protected:
	bool needUpdate(){
		if(!repeatsCompleted()){
			if(lapseCompleted()){
				restartLapse();
				if(changeCompleted){
					actualRepeats--;
					changeCompleted=false;
				}
				return true;
			}else{
				actualLapse--;
			}
		}
		return false;
	}
	bool repeatsCompleted(){
		return (actualRepeats == 0);
	}
	void setChangeCompleted(){
		changeCompleted = true;
	}
private:	
	void restartLapse(){
		actualLapse=initialLapse;
	}
	void restartRepeats(){
		actualRepeats=initialRepeats;
	}
	bool lapseCompleted(){
		return (actualLapse == 0);
	}

	int speed;
	int initialLapse, actualLapse; 
	int initialRepeats, actualRepeats;
	bool changeCompleted;
};
///////////////////////////////////
class ColorChange: public Change{
public:
	ColorChange(Color from, Color to, int speed, int repeats)
		:Change(speed, repeats)
		,from(from)
		,to(to)
		,step(from.stepTo(to))
		,isRelative(false) {
			resetData();

	}
	ColorChange(ColorStep step, int speed, int repeats)
		:Change(speed, repeats)
		,step(step)
		,isRelative(true){

	}
	bool isCompleted(){
		return repeatsCompleted();
	}
	void update(Box * b){
		if(needUpdate()){
			if(isRelative){
				Color c = b->getColor();
				c+=step;
				b->setColor(c);
				setChangeCompleted();
			}else{
				actual.approachTo(to, step);
				b->setColor(actual);
				if(actual == to){
					resetData();	
					setChangeCompleted();
				}
			}
		}
	}
private:
	void resetData(){
		if(!isRelative){
			actual= from;
		}
	}
	Color from, to, actual;
	ColorStep step;
	bool isRelative;
};
///////////////////////////////////
class PosChange: public Change{
public:
	PosChange(Point from, Point to, int speed, int repeats)
		:Change(speed, repeats)
		,from(from)
		,to(to)
		,step(from.stepTo(to))
		,isRelative(false) {
			resetData();

	}
	PosChange(PointStep step, int speed, int repeats)
		:Change(speed, repeats)
		,step(step)
		,isRelative(true){

	}
	bool isCompleted(){
		return repeatsCompleted();
	}
	void update(Box * b){
		if(needUpdate()){
			if(isRelative){
				Point c = b->getPos();
				c+=step;
				b->setPos(c);
				setChangeCompleted();
			}else{
				actual.approachTo(to, step);
				b->setPos(actual);
				if(actual== to){
					resetData();	
					setChangeCompleted();
				}
			}
		}
	}
private:
	void resetData(){
		if(!isRelative){
			actual= from;
		}
	}
	Point from, to, actual;
	PointStep step;
	bool isRelative;
};
///////////////////////////////////
class SizeChange: public Change{
public:
	SizeChange(Size from, Size to, int speed, int repeats)
		:Change(speed, repeats)
		,from(from)
		,to(to)
		,step(from.stepTo(to))
		,isRelative(false) {
			resetData();

	}
	SizeChange(SizeStep step, int speed, int repeats)
		:Change(speed, repeats)
		,step(step)
		,isRelative(true){

	}
	bool isCompleted(){
		return repeatsCompleted();
	}
	void update(Box * b){
		if(needUpdate()){
			if(isRelative){
				Size c = b->getSize();
				c+=step;
				b->setSize(c);
				setChangeCompleted();
			}else{
				actual.approachTo(to, step);
				b->setSize(actual);
				if(actual== to){
					resetData();	
					setChangeCompleted();
				}
			}
		}
	}
private:
	void resetData(){
		if(!isRelative){
			actual= from;
		}
	}
	Size from, to, actual;
	SizeStep step;
	bool isRelative;
};
int main(){
	vector<ColorChange> colorChanges;
	vector<PosChange>   posChanges;
	vector<SizeChange>  sizeChanges;
	colorChanges.push_back(ColorChange(Color(8,1,10), Color(7,7,4), 9000,3));
	colorChanges.push_back(ColorChange(ColorStep(1,100,-1), 9990,10));
	posChanges.push_back(PosChange(PointStep(1,-1), 9990,10));
	sizeChanges.push_back(SizeChange(SizeStep(1,-1), 9990,30));
	sizeChanges.push_back(SizeChange(Size(1,10), Size(7,4), 9000,3));
	Box b;
	bool complete = false;
	while(!complete){
		complete=true;
		for(int i=0; i< colorChanges.size();i++){
			if(!colorChanges[i].isCompleted()){
				colorChanges[i].update(&b);
				complete=false;
			}
		}
		for(int i=0; i< posChanges.size();i++){
			if(!posChanges[i].isCompleted()){
				posChanges[i].update(&b);
				complete=false;
			}
		}
		for(int i=0; i< sizeChanges.size();i++){
			if(!sizeChanges[i].isCompleted()){
				sizeChanges[i].update(&b);
				complete=false;
			}
		}
		cout << b;
		cin.get();
	}

}
/*
class Command{
public:
	void addColorChange(Color from, Color to, int speed, int repeats){
		absColorChanges.push_back( AbsColorChange(from, to, speed, repeats));
	}
	void addColorChange(ColorStep step, int speed, int repeats){
		relColorChanges.push_back(RelColorChange(step, speed, repeats));
	}

	void addSizeChange(Size from, Size to, int speed, int repeats)

	void addSizeChange(SizeStep step, int speed, int repeats);

	void addPosChange(Pos from, Pos to, int speed, int repeats);
	void addPosChange(PosStep step, int speed, int repeats);


private:
	vector<AbsColorChange>absColorChanges;
	vector<RelColorChange>relColorChanges;
	//mas vectores para los otros tipos de cambios...
};
*/
