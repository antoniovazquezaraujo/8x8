#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
////////////////
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
////////////////
class PosStep{
public:
	PosStep(int x=0, int y=0)
		:x(x),y(y){
		}
	signed int x, y; 
};
////////////////
class Pos{
public:
	Pos(int x=0, int y=0)
		:x(x), y(y){

	}
	PosStep stepTo(Pos p){
		return PosStep(
			p.x==x?0:p.x>x?1:-1,
			p.y==y?0:p.y>y?1:-1 
		);
	}
	void operator+=(PosStep step){
		x+=step.x;
		y+=step.y;
	}
	void approachTo(Pos to, PosStep step){
		x+=step.x;
		y+=step.y;
		if(step.x >0 && x>to.x) x= to.x;
		if(step.x <0 && x<to.x) x= to.x;

		if(step.y >0 && y>to.y) y= to.y;
		if(step.y <0 && y<to.y) y= to.y;
	}
	int x,y;
};
bool operator==(const Pos & p, const Pos & q){
	return ((p.x == q.x) && (p.y == q.y));
}
ostream & operator<<(ostream& o, Pos p){
	o << " X:"<< p.x<<" Y:"<<p.y << " ";
	return o;
}
///////////////
class Box{
public:
	void setColor(Color color){
		this->color = color;
	}
	Color getColor(){
		return color;
	}
	void setPos(Pos pos){
		this->pos=pos;
	}
	Pos getPos(){
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
	*/
	friend ostream & operator<<(ostream& o, const Box & b);
	Color color;
	Pos pos;
	Size size;
	/*
	Sound sound;
	*/
};
ostream & operator<<(ostream &o, const Box & b){
	o << b.pos << b.size << b.color;
	return o;
}
class Form;
////////////////////////
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
	void update(Form * f){
		if(needUpdate()){
			if(isRelative){
				Color c = f->getColor();
				c+=step;
				f->setColor(c);
				setChangeCompleted();
			}else{
				actual.approachTo(to, step);
				f->setColor(actual);
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
	PosChange(Pos from, Pos to, int speed, int repeats)
		:Change(speed, repeats)
		,from(from)
		,to(to)
		,step(from.stepTo(to))
		,isRelative(false) {
			resetData();

	}
	PosChange(PosStep step, int speed, int repeats)
		:Change(speed, repeats)
		,step(step)
		,isRelative(true){

	}
	bool isCompleted(){
		return repeatsCompleted();
	}
	void update(Form * b){
		if(needUpdate()){
			if(isRelative){
				Pos c = b->getPos();
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
	Pos from, to, actual;
	PosStep step;
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
	void update(Form * b){
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
//////////////////
class Program{
public:
	Program()
		:finished(false){

	}
	void update(Form* f){
		finished=true;
		for(int i=0; i< colorChanges.size();i++){
			if(!colorChanges[i].isCompleted()){
				colorChanges[i].update(f);
				finished=false;
			}
		}
		for(int i=0; i< posChanges.size();i++){
			if(!posChanges[i].isCompleted()){
				posChanges[i].update(f);
				finished=false;
			}
		}
		for(int i=0; i< sizeChanges.size();i++){
			if(!sizeChanges[i].isCompleted()){
				sizeChanges[i].update(f);
				finished=false;
			}
		}
	}
	bool isFinished(){
		return finished;
	}
	void reset(){
		finished= false;
	}
	void addChange(ColorChange c){
		colorChanges.push_back(c);
	}
	void addChange(PosChange p){
		posChanges.push_back(p);
	}
	void addChange(SizeChange s){
		sizeChanges.push_back(s);
	}

	vector<ColorChange> colorChanges;
	vector<PosChange>   posChanges;
	vector<SizeChange>  sizeChanges;

private:
	bool finished;
};
////////////////
//Form es un conjunto de cajas
class Program;
class Form{
public:
	void setColor(Color color){
		this->color = color;
	}
	Color getColor(){
		return color;
	}
	void setPos(Pos pos){
		this->pos=pos;
	}
	Pos getPos(){
		return pos;
	}
	void setSize(Size size){
		this->size = size;
	}
	Size getSize(){
		return size;
	}
	void addProgram(Program p){
		programs.push_back(p);
	}
	void update(){
		if(actualProgram != programs.end()){
			actualProgram.update(this);
			actualProgram++;
		}else{
			actualProgram = programs.begin();
		}
	}
	Color color;
	Pos pos;
	Size size;
	vector<Box> boxes;
	vector<Program>programs;
	vector<Program>::iterator actualProgram;
	friend ostream & operator<<(ostream& o, const Box & b);
};
int main(){
	Program p;
	p.addChange(ColorChange(Color(8,1,10), Color(7,7,4), 9000,3));
	p.addChange(PosChange  (Pos(1,-1),     Pos(4,4),     9990,10));
	p.addChange(SizeChange (Size(1,10),    Size(7,4),    9000,3));

	p.addChange(ColorChange(ColorStep(1,100,-1), 9990,10));
	p.addChange(PosChange  (PosStep(1,-1),       9990,10));
	p.addChange(SizeChange (SizeStep(1,-1),      9990,30));
	Form f;
	while(!p.isFinished()){
		f.update();
		cout << f;
		cin.get();
	}
}
