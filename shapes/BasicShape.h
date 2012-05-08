class Animable{
public:
	 void update(){};
	 void startChanges(int times = -1){};
	 void startChange(int numChange, int times = -1){};
	 void stopChanges(){};
	 bool isFinished(){return false;};
	 void nextTurn(){};
	 void reset(){};
};

class PosAnimableShape: public Animable{
public:
	void addPosChange  (int colDelta,   int rowDelta,    int duration, int repeats);

	//Animable interface
	void update();
	void startChanges(int times = -1);
	void startChange(int numChange, int times = -1);
	void stopChanges();
	bool isFinished();
	void nextTurn();
	void reset();
private:
	int times, actualTimes;
	vector<PosChange> changes;
	unsigned int actualChange;
	int numChange;
	bool finished;
	bool allFinished;
};
class ColorAnimableShape: public Animable{
public:
	void addColorChange(int fromR, int toR, int fromG, int toG, int fromB, int toB, 
			int duration, int repeats);
	//Animable interface
	void update();
	void startChanges(int times = -1);
	void startChange(int numChange, int times = -1);
	void stopChanges();
	bool isFinished();
	void nextTurn();
	void reset();
private:
	int times, actualTimes;
	vector<ColorChange> changes;
	unsigned int actualChange;
	int numChange;
	bool finished;
	bool allFinished;
};

class SizeAnimableShape: public Animable{ 
public:
	void addSizeChange (int widthDelta, int heightDelta, int duration, int repeats);
	//Animable interface
	void update();
	void startChanges(int times = -1);
	void startChange(int numChange, int times = -1);
	void stopChanges();
	bool isFinished();
	void nextTurn();
	void reset();
private:
	int times, actualTimes;
	vector<SizeChange> changes;
	unsigned int actualChange;
	int numChange;
	bool finished;
	bool allFinished;
};
class RotationAnimableShape: public Animable{ 
public:
	void addRotationChange (int angleDelta, int duration, int repeats);
	//Animable interface
	void update();
	void startChanges(int times = -1);
	void startChange(int numChange, int times = -1);
	void stopChanges();
	bool isFinished();
	void nextTurn();
	void reset();
private:
	int times, actualTimes;
	vector<RotationChange> changes;
	unsigned int actualChange;
	int numChange;
	bool finished;
	bool allFinished;
};

class BasicShape{
public:
    Point pos;              
	Size size;
    Color color;
     ~Shape(); 
protected:
    Shape();    
private:
	// No es copiable
    Shape(const Shape&);               
    Shape& operator=(const Shape&);
};

class Box:
	public BasicShape, 
	public PosAnimable, 
	public SizeAnimable, 
	public ColorAnimable, 
	public RotationAnimable {

public:
	Box(Point pos, Size size, Color color)
		:BasicShape(pos, size, color){

	}
	void addPosAnimation();
	void addSizeAnimation();
	void addColorAnimation();
	void addRotationAnimation();

	void update();
	void startAnimations(AnimationType type, int times = -1);
	void startAnimation(AnimationType type, int numChange, int times = -1);
	void stopAnimations(AnimationType type);
	bool isFinished(AnimationType type);
	void nextTurn(AnimationType type);
	void reset(AnimationType type);
	enum AnimationType{ POS, SIZE, COLOR, ROTATION };
};

/*
   Conjunto de Boxes, con posición relativa a su origen
*/
class Form{
public:
	void update(){
		for(int n=0; n<boxes.size();n++){
			boxes[n].update();
		}
	}
	void addBox(Box b){
		boxes.push_back(b);
	}

	Point pos;
	int level;
	vector<Box> boxes;
};

class TabletModel{
public:
	void update();
	vector<Form> forms;
};
int main(){
	TabletModel model;
	Box b(0,0,3,4);
	b.addPosAnimation(-1, 0, 10, 10);
	b.addRotationAnimation(-90, 10, 10);
	Form f;
	f.addBox(b);
	model.forms.push_back(f);
	while(true){
		model.update();
		//pintar
	}
}
