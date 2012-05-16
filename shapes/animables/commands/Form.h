#ifndef FORM
#define FORM
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
#endif
