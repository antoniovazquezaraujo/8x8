#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <map>
using namespace std;
class Change;
class Box;
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
		int r,g,b;
};
bool operator==(const Color& a, const Color& b){
	return(a.r==b.r && a.g==b.g && a.b==b.b);
}
ostream & operator<<(ostream& o, Color c){
	o << "R:"<< c.r<<"G:"<<c.g<<"B:"<<c.b<<endl;
	return o;
}
////////////////
class Size{
	public:
		Size(int w=0, int h=0)
			:w(w), h(h){
		}
		int w,h;
};
bool operator==(const Size & p, const Size & q){
	return (p.w == q.w && p.h == q.h);
}
ostream & operator<<(ostream& o, Size s){
	o << "W:"<< s.w<<"H:"<<s.h<<endl;
	return o;
}
////////////////
class Point{
	public:
		Point(int x=0, int y=0)
			:x(x), y(y){

			}
		int x,y;
};
bool operator==(const Point & p, const Point & q){
	return (p.x == q.x && p.y == q.y);
}
ostream & operator<<(ostream& o, Point p){
	o << "X:"<< p.x<<"Y:"<<p.y<<endl;
	return o;
}
////////////////
const int MAX_SPEED=10000;
class Change{
	public:
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

		Change()
			:speed(0)
			 ,stopped(true)
			 ,actualCount(0)
			 ,initialCount(0){

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
			:dr(dr), dg(dg), db(db) {

			}
		void doChange(Box*){
			cout << "Mod color " << dr << "/" << dg << "/" << db<<endl;
			//actualiza actualColor según los rangos de que dispone
			//Le pone a la box el actualColor
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
		int dr, dg, db;
};
////////////////
class AbsColorChange: public Change{
	public:
		AbsColorChange(Color fromColor, Color toColor)
			:fromColor(fromColor)
			 ,toColor(toColor)
			 ,step(fromColor.stepTo(toColor)){

			 }
		void doChange(Box* b){
			cout << "Abs color " << fromColor << "/" << toColor << "/"<< actualColor << endl;
			//actualiza actualColor según los rangos de que dispone
			//Le pone a la box el actualColor
			actualColor+=step;
			//b->setColor(actualColor);
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
			:fromPos(fromPos),
			toPos(toPos){
			}
		void doChange(Box*){
			cout << "Abs Pos" << fromPos<< "/" << toPos<< "/"<< actualPos<< endl;
			//desplaza a box con el desplazamiento calculado
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
};
////////////////
class RelPosChange: public Change{
	public:
		RelPosChange(int dx, int dy)
			:dx(dx),
			dy(dy){

			}
		void doChange(Box*){
			//desplaza a box con el desplazamiento calculado
			cout << "Rel Pos" << dx<< "/" << dy<< endl;
		}
		string toString(){
			stringstream ss;
			ss << "RelPosChange. Dx: " << dx<< " dy: "<< dy<<" ";
			return ss.str();
		}
		bool isFinished()const {
			return true;
		}
		void reset(){
			//nada
		}
	private:
		int dx, dy;	
};

////////////////
class AbsSizeChange: public Change{
	public:
		AbsSizeChange(Size fromSize, Size toSize)
			:fromSize(fromSize),
			toSize(toSize){

			}
		void doChange(Box*){
			cout << "Abs Size" << fromSize<< "/" << toSize<<"/" << actualSize<< endl;
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
};
////////////////
class RelSizeChange: public Change{
	public:
		RelSizeChange(int dw, int dh)
			:dw(dw), 
			dh(dh){

			}
		void doChange(Box*){
			cout << "Rel Size" << dw<< "/" << dh << endl;
		}
		bool isFinished()const{
			return true;
		}
		void reset(){
			//nada
		}
	private:
		int dw, dh;	
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
		void addChange(Change * change, int repeats){
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
class Box{
	public:
		void setColor(Color);
		void setPos(Point);
		void setSize(Size);
		void setSound(Sound);
		friend ostream & operator<<(ostream& o, Box b);
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
	int addProgram(Program p){
		programs.push_back(p);
	}
	int addBox(Box b){
		boxes.push_back(b);
	}

	Box & box(int key){
		return boxes[key];
	}
	Program & program(int key){
		return programs[key];
	}

	void start();
	void stop();

	vector<Box> boxes;
	vector<Program> programs;
};
////////////////
int main(){
	Tablet t;
	Command * c = new Command;
	c->addChange(new RelPosChange(-1,0), 10);
	c->addChange(new AbsPosChange(Point(1,2), Point(3,3)),20);
	c->addChange(new AbsColorChange(Color(1,2,3), Color(40,30,40)),10);
	c->addChange(new RelColorChange(2,3,4),10);
	c->addChange(new RelSizeChange(-1,0),4);
	c->addChange(new AbsSizeChange(Size(1,3), Size(4,5)),4);
	c->addChange(new SoundChange( new Sound),1);
	Program p;
	p.addCommand(c,10);
	t.addProgram(p);
}
