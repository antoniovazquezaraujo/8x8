#ifndef CHANGE 
#define CHANGE 
const int MAX_SPEED=10000;
class Change{
public:
	Change(int speed=1, int repeats=1);
	void restartRepeats();
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
