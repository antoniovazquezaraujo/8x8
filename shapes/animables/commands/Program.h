#ifndef PROGRAM
#define PROGRAM
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
#endif
