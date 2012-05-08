#ifndef FORM_H
#define FORM_H
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
#endif
