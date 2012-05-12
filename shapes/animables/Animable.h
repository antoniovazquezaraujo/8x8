#ifndef ANIMABLE_H
#define ANIMABLE_H
class Animable{
public:
	Animable();
	void update();
	void startChanges(int times = -1);
	void startChange(int numChange, int times = -1);
	void stopChanges();
	bool isFinished();
	void nextTurn();
	void reset();
protected:
	int times; 
	int actualTimes;
	int actualChange;
	int numChange;
	bool finished;
	bool allFinished;
};
#endif
