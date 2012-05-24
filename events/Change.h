#ifndef CHANGE 
#define CHANGE 
const int MAX_SPEED=10000;
class Change{
public:
	Change(int repeats=1);
	void restartRepeats();
	void setSpeed(int speed);
protected:
	bool needUpdate();
	bool repeatsCompleted();
	void setChangeCompleted();
private:	
	void restartLapse();
	bool lapseCompleted();

	int speed;
	int initialRepeats, actualRepeats;
	int initialLapse, actualLapse; 
	bool changeCompleted;
};
#endif
