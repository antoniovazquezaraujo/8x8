#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
class Change;
class Box;
class Sound{

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
	int r,g,b;
};
ostream & operator<<(ostream& o, Color c){
	o << "R:"<< c.r<<"G:"<<c.g<<"B:"<<c.b<<endl;
	return o;
}
class Size{
public:
	Size(int w=0, int h=0)
		:w(w), h(h){
	}
	int w,h;
};
ostream & operator<<(ostream& o, Size s){
	o << "W:"<< s.w<<"H:"<<s.h<<endl;
	return o;
}
class Point{
public:
	Point(int x=0, int y=0)
		:x(x), y(y){

	}
	int x,y;
};
ostream & operator<<(ostream& o, Point p){
	o << "X:"<< p.x<<"Y:"<<p.y<<endl;
	return o;
}
////////////////////////////////////////////////////
class Change{
public:
	virtual string toString(){
		stringstream ss;
		ss << "Change. Count: " << actualCount<<" ";
		return ss.str();
	}
	Change(int interval)
		:initialCount(interval),
		actualCount(initialCount){

	}
	void update(Box * b){
		if(actualCount> 0){
			actualCount--;
		}else{
			actualCount= initialCount;
			set(b);
		}
	}
	virtual void doChange(Box*)=0;
private:	
	int initialCount, actualCount; 
};
class RelColorChange: public Change{
public:
	RelColorChange(int dr, int dg, int db, int interval)
		:dr(dr), dg(dg), db(db),
		Change(interval){

	}
	void doChange(Box*){
		cout << "Mod color " << dr << "/" << dg << "/" << db<<endl;
		//actualiza actualColor según los rangos de que dispone
		//Le pone a la box el actualColor
	}
	string toString(){
		stringstream ss;
		return ss.str();
	}
private:
	int dr, dg, db;
};
class AbsColorChange: public Change{
public:
	AbsColorChange(Color fromColor, Color toColor, int interval)
		:fromColor(fromColor),
		toColor(toColor),
		Change(interval){

	}
	void doChange(Box*){
		cout << "Abs color " << fromColor << "/" << toColor << "/"<< actualColor << endl;
		//actualiza actualColor según los rangos de que dispone
		//Le pone a la box el actualColor
	}
private:
	Color fromColor, toColor;
	Color actualColor;
};

class AbsPosChange: public Change{
public:
	AbsPosChange(Point fromPos, Point toPos, int interval)
		:fromPos(fromPos),
		toPos(toPos),
		Change(interval){
			//segun intervalo y distancia entre puntos calcula 
			//desplazamiento para cada turno
	}
	void doChange(Box*){
		cout << "Abs Pos" << fromPos<< "/" << toPos<< "/"<< actualPos<< endl;
		//desplaza a box con el desplazamiento calculado
	}
private:
	Point fromPos, toPos;
	Point actualPos;
};
class RelPosChange: public Change{
public:
	RelPosChange(int dx, int dy, int interval)
		:dx(dx),
		dy(dy),
		Change(interval){

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
private:
	int dx, dy;	
};

class AbsSizeChange: public Change{
public:
	AbsSizeChange(Size fromSize, Size toSize, int interval)
		:fromSize(fromSize),
		toSize(toSize),
		Change(interval){

	}
	void doChange(Box*){
		cout << "Abs Size" << fromSize<< "/" << toSize<<"/" << actualSize<< endl;
	}
private:
	Size fromSize, toSize;
	Size actualSize; 
};
class RelSizeChange: public Change{
public:
	RelSizeChange(int dw, int dh, int interval)
		:dw(dw), 
		dh(dh),
		Change(interval){

	}
	void doChange(Box*){
		cout << "Rel Size" << dw<< "/" << dh << endl;
	}
private:
	int dw, dh;	
};
class SoundChange: public Change{
public:
	SoundChange(Sound * sound, int interval)
		:sound(sound),
		Change(interval){

	}
	void doChange(Box* b){
		//b->setSound(sound);	
		cout << "sound change" << endl;
	}
private:
 	Sound * sound;	
};

class Command{
public:
	Command(){

	}
	~Command(){
		//liberar los changes
	}
	void addChange(Change * change){
		changes.push_back(change);
	}
	void start(int times, int speed){
		cout << "Starting at "<< times << " with " << speed<< " of speed" << endl;
	}
	void stop();
	void update(Box * b){
		for(vector<Change *>::iterator i= changes.begin();
				i!= changes.end();
				i++){
			(*i)->update(b);
		}
	}
private:
	vector<Change*>changes;

	friend ostream & operator<<(ostream& o, Command c);
};


class Box{
public:
	void setColor(Color);
	void setPos(Point);
	void setSize(Size);
	void setSound(Sound);
	void start(int commandKey, int times, int speed){
		if(commands.find(commandKey) != commands.end()){
			commands[commandKey].start(times, speed);
		}else{
			//error
		}
	}
	void addCommand(int commandKey, Command c=Command()){
		commands.insert(pair<int, Command>(commandKey, c));
	}
	void addChange(int commandKey, Change * change){
		if(commands.find(commandKey) != commands.end()){
			commands[commandKey].addChange(change);
		}
	}
	void update(){
		for(map<int,Command>::iterator i= commands.begin();
				i!= commands.end();
				i++){
			(*i).second.update(this);
		}

	}
private:
	map<int, Command> commands;
	friend ostream & operator<<(ostream& o, Box b);
};
ostream & operator<<(ostream& o, Command c){
	for(vector<Change *>::iterator i= c.changes.begin();
			i!= c.changes.end();
			i++){
		cout << (*i)->toString() << endl;
	}
	return o;
}
ostream & operator<<(ostream& o, Box b){
	for(map<int,Command>::iterator i= b.commands.begin();
			i!= b.commands.end();
			i++){
		cout << (*i).second << endl;
	}
	return o;
}
int main(){
	Box b;
	b.addCommand(123);
	b.addChange(123,new RelPosChange(-1,0,100));
	b.addChange(123,new AbsPosChange(Point(1,2), Point(3,3),100));
	b.addChange(123,new AbsColorChange(Color(1,2,3), Color(40,30,40),100));
	b.addChange(123,new RelColorChange(2,3,4, 100));
	b.addChange(123,new RelSizeChange(-1,0,100));
	b.addChange(123,new AbsSizeChange(Size(1,3), Size(4,5),100));
	b.addChange(123,new SoundChange( new Sound,100));
	Command c;
	b.addCommand(124, c);
	b.start(123, 10, 4);
	b.start(124, 1, 3);
	while(true){
		b.update();
		cout << b;
		cin.get();
	}
}
/*
   Vale, tengo comandos que tienen cambios.
   Puedo ejecutar un comando n veces o siempre.
   Puedo ejecutarlo más rápido o más lento
   Todos sus cambios se ejecutarán SIMULTANEAMENTE, cada uno a su ritmo
   Una vez que se termina el comando las veces que sean, paso al siguiente
   Puedo ejecutar uno o una lista de ellos.
   Mejor sacarlos fuera de Box. Crearemos la clase Program o algo así.
   Podríamos tener un conjunto de programas ya creados y de repente hacer que
   una serie de cajas "ejecuten" algunos de ellos.
   Algo como 
   	boxAt(row, col)->doProgram("Saltos");
	o bien
	boxAt(row, col)->onClick("Explosion");

	De esta forma, los programas estan separados de las cajas, y podemos crear muchos 
	diferentes y tenerlos listos para funcionar.
	Más adelante, no serán Box sino Forms los que los ejecutarán, aunque es igual.

