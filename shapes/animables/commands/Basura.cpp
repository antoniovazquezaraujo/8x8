#include <vector>
#include <cassert>
#include <map>
#include <iterator>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
template<typename T>
void print(T col, string sep=" "){
	copy(col.begin(), col.end(), ostream_iterator<typename T::value_type>(cout, sep.c_str()));
}
template<typename P, typename Q>
void print(map<P, Q> col, string sep=" "){
	for(typename map<P,Q>::const_iterator i = col.begin();
			i != col.end();
			i++){
		cout << (*i).first << ":" << (*i).second << sep;
	}
	cout << endl;
}
const int MAX_SPEED=10000;
class Change{
public:
	virtual string toString(){
		stringstream ss;
		ss << "Change. Count: " << actualCount<<" ";
		return ss.str();
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
//		cout << initialCount << endl;
//		cin.get();
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
	void update(int b){
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
	virtual void doChange(int)=0;
private:	
	int initialCount, actualCount; 
	int speed;
	bool stopped;
};

class MyChange: public Change{
public:
	MyChange(int n)
		:x(10000){
	}
	void doChange(int n ){
		int speed;
		cin.clear();
		cin >> speed;
		setSpeed(speed);
	}
	int x;
};
int main(){
	Change * m = new MyChange(1);
	m->setSpeed(100);
	m->start();
	while(!m->isStopped()){
		cout << ".";
		m->update(1);
	}
}
