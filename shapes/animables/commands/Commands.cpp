#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <map>
using namespace std;

////////////////
class Sound{

};
////////////////
class ColorStep{
	public:
		ColorStep(int r=0, int g=0, int b=0)
			:r(r), g(g), b(b){
		}
	signed int r,g,b;
};
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
		}
		void approachTo(Color to, ColorStep step){
			r+=step.r;
			g+=step.g;
			b+=step.b;
			if(step.r >0 && r>to.r) r= to.r;
			if(step.r <0 && r<to.r) r= to.r;

			if(step.g >0 && r>to.g) g= to.g;
			if(step.g <0 && r<to.g) g= to.g;

			if(step.b >0 && r>to.b) b= to.b;
			if(step.b <0 && r<to.b) b= to.b;
		}
		int r,g,b;
};
bool operator==(const Color& a, const Color& b){
	return((a.r==b.r) && (a.g==b.g) && (a.b==b.b));
}
ostream & operator<<(ostream& o, Color c){
	o << "R:"<< c.r<<"G:"<<c.g<<"B:"<<c.b<<endl;
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
////////////////
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
		void setSound(Sound sound){
			this->sound = sound;
		}
		Sound getSound(){
			return sound;
		}
		friend ostream & operator<<(ostream& o, const Box & b);
		Point pos;
		Size size;
		Color color;
		Sound sound;
};
ostream & operator<<(ostream &o, const Box & b){
	o << b.pos << b.size << b.color;
	return o;
}
const int MAX_SPEED=10000;
class Change{
	public:
		Change()
			:speed(0)
			 ,stopped(true)
			 ,actualCount(0)
			 ,initialCount(0){

		 }
		void setSpeed(int speed){
			this->speed = speed % MAX_SPEED;
			start();
		}
		void start(){
			if(speed <=0){
				stopped= true;
			}else{
				initialCount= MAX_SPEED/speed;
				actualCount=initialCount;
				stopped=false;
			}
		}
		void stop(){
			stopped=true;
		}

		void update(Box *b){
			if(stopped)return;
			if(actualCount > 0){
				actualCount--;
			}else{
				actualCount= initialCount;
				doChange(b);
			}
		}
		bool isStopped(){
			return stopped;
		}
		//el cambio real
		virtual void doChange(Box *)=0;
		//si el cambio alcanzó su objetivo completo 
		virtual bool isFinished()const =0;
		virtual void reset()=0;
	private:	
		int initialCount, actualCount; 
		int speed;
		bool stopped;
};
////////////////
class RelColorChange: public Change{
	public:
		RelColorChange(int dr, int dg, int db)
			:step(dr,dg,db) {

			}
		void doChange(Box* b){
			Color c = b->getColor();
			c+=step;
			b->setColor(c);
		}
		bool isFinished()const {
			return true;
		}
		void reset(){
			//nada
		}
		string toString(){
			stringstream ss;
			return ss.str();
		}
	private:
		ColorStep step;
};
////////////////
class AbsColorChange: public Change{
	public:
		AbsColorChange(Color fromColor, Color toColor)
			:fromColor(fromColor)
			 ,toColor(toColor)
			 ,actualColor(fromColor)
			 ,step(fromColor.stepTo(toColor)){

			 }
		void doChange(Box* b){
			actualColor.approachTo(toColor, step);
			b->setColor(actualColor);
		}
		bool isFinished()const {
			return (actualColor == toColor);
		}
		void reset(){
			actualColor = fromColor;
		}
	private:
		Color fromColor, toColor;
		Color actualColor;
		ColorStep step;
};

////////////////
class AbsPosChange: public Change{
	public:
		AbsPosChange(Point fromPos, Point toPos)
			:fromPos(fromPos)
			 ,toPos(toPos)
			 ,actualPos(fromPos)
			 ,step(fromPos.stepTo(toPos)){
			 }
		void doChange(Box* b){
			actualPos.approachTo(toPos, step);
			b->setPos(actualPos);
		}
		bool isFinished() const{
			return actualPos == toPos;
		}
		void reset(){
			actualPos = fromPos;	
		}
	private:
		Point fromPos, toPos;
		Point actualPos;
		PointStep step;
};
////////////////
class RelPosChange: public Change{
	public:
		RelPosChange(int dx, int dy)
			:step(dx,dy){

			}
		void doChange(Box* b){
			Point p = b->getPos();
			p+=step;
			b->setPos(p);
		}
		string toString(){
			return "!!!"; 
		}
		bool isFinished()const {
			return true;
		}
		void reset(){
			//nada
		}
	private:
		PointStep step;	
};

////////////////
class AbsSizeChange: public Change{
	public:
		AbsSizeChange(Size fromSize, Size toSize)
			:fromSize(fromSize)
			 ,toSize(toSize)
			 ,actualSize(fromSize)
			 ,step(fromSize.stepTo(toSize)){

			 }
		void doChange(Box* b){
			actualSize.approachTo(toSize, step);
			b->setSize(actualSize);
		}
		bool isFinished()const {
			return (actualSize == toSize);
		}
		void reset(){
			actualSize = fromSize;	
		}
	private:
		Size fromSize, toSize;
		Size actualSize; 
		SizeStep step;
};
////////////////
class RelSizeChange: public Change{
	public:
		RelSizeChange(int dw, int dh)
			:step(dh,dh){

			}
		void doChange(Box* b){
			Size s = b->getSize();
			s+=step;
			b->setSize(s);
		}
		bool isFinished()const{
			return true;
		}
		void reset(){
			//nada
		}
	private:
		SizeStep step;
};
////////////////
class SoundChange: public Change{
	public:
		SoundChange(Sound * sound)
			:sound(sound){

			}
		void doChange(Box* b){
			//b->setSound(sound);	
			cout << "sound change" << endl;
		}
		bool isFinished()const{
			return true;
		}
		void reset(){
			//nada
		}
	private:
		Sound * sound;	
};
////////////////
struct Repeats{
	Repeats(int initial=0)
		:initial(initial)
		 ,actual(0){

		 }
	int initial;
	int actual;
};
////////////////
class Command{
	/*Conjunto de cambios que se ejecutan SIMULTANEAMENTE.
	  Se termina cuando todos terminan Cada uno se ejecuta a la velocidad y el
	  número de veces que se le envió al agregarlo
	 */
	public:
		Command()
			:stopped(true)
			 ,finished(false){

			 }
		~Command(){
			//liberar los changes
		}
		void addChange(Change * change, int repeats, int speed){
			change->setSpeed(speed);
			changes[change]= Repeats(repeats);
		}
		void start(){
			stopped = false;
		}
		void reset(){
			while(actualChange != changes.end()){
				(*actualChange).first->reset();
				actualChange++;
			}
		}
		void stop(){
			stopped=true;	
		}
		bool isFinished()const{
			return finished;
		}
		/*
		   Recorremos todos los cambios del comando.
		   El que no ha terminado se actualiza
		   El que sí, se le decrementa el número de veces que se repetirá
		   Si la cuenta llega a cero se deja sin actualizar
		   Cuando todos han terminado, finished queda a true
		 */
		void update(Box * b){
			if(finished) return;
			finished=true;
			actualChange = changes.begin();
			while(actualChange != changes.end()){
				if(!(*actualChange).first->isFinished()){
					(*actualChange).first->update(b);
					finished=false;
				}else{
					if((*actualChange).second.actual == -1){
						(*actualChange).first->reset();
					}else{
						(*actualChange).second.actual --;
						if((*actualChange).second.actual > 0){
							(*actualChange).first->reset();
						}
					}
				}
				actualChange++;
			}
		}
	private:
		map<Change*, Repeats>changes;
		map<Change*, Repeats>::iterator actualChange;
		bool finished;
		bool stopped;

		friend ostream & operator<<(ostream& o, Command c);
};


////////////////
class Program{
	public:
		Program()
			:actualCommand(commands.begin())
			 ,stopped(true){

			 }
		void stop(){
			stopped = true;
		}
		void start(){
			stopped=false;
			actualCommand = commands.begin();
		}
		bool isFinished()const {
			return (actualCommand == commands.end());
		}
		void addCommand(Command * c , int repeats){
			commands[c]= repeats;
		}
		void update(Box * b){
			if(actualCommand == commands.end()){
				return;
			}
			if(!(*actualCommand).first->isFinished()){
				(*actualCommand).first->update(b);
			}else{
				if((*actualCommand).second.actual == -1){
					(*actualCommand).first->reset();
				}else{
					(*actualCommand).second.actual --;
					if((*actualCommand).second.actual > 0){
						//No hay que poner actual a initial aqui????
						(*actualCommand).first->reset();
					}else{
						actualCommand++;
					}
				}
			}
		}

		map<Command *, Repeats> commands;
		map<Command *, Repeats>::iterator actualCommand;
		bool stopped;
};
////////////////
class Tablet{
	public:
		void setup(){
			Command * c = new Command;
			c->addChange(new AbsPosChange(Point(10,2), Point(3,7)),20, 800);
			c->addChange(new RelPosChange(1,1), 10, 10000);
			c->addChange(new AbsColorChange(Color(1,2,3), Color(40,30,40)),10, 300);
			c->addChange(new RelColorChange(2,3,4),10, 300);
			c->addChange(new RelSizeChange(-1,0),4, 300);
			c->addChange(new AbsSizeChange(Size(1,3), Size(4,5)),4, 400);
			c->addChange(new SoundChange( new Sound),1, 100);
			Program * p = new Program;
			p->addCommand(c,10);
			Box * b = new Box;
			boxes[b] = p;
		}
		void start(){
			for(map<Box*,Program*>::iterator i=boxes.begin();
					i!= boxes.end();
					i++){
				(*i).second->start();
			}
		}
		void update(){
			for(map<Box*,Program*>::iterator i=boxes.begin();
					i!= boxes.end();
					i++){
				(*i).second->update((*i).first);
			}
		}

		void show(){
			for(map<Box*,Program*>::iterator i=boxes.begin();
					i!= boxes.end();
					i++){
				cout <<  *((*i).first);
			}
		}
		map<Box*, Program*>boxes;
};
////////////////
int main(){
	Tablet t;
	t.setup();
	t.start();
	while(true){
		t.update();
		t.show();
		cin.get();
	}
}
