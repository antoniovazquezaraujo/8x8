#ifndef CHANGE 
#define CHANGE 
const int MAX_SPEED=10000;
class Change{
public:
	Change(int speed, int repeats);
protected:
	bool needUpdate();
	bool repeatsCompleted();
	void setChangeCompleted();
private:	
	void restartLapse();
	void restartRepeats();
	bool lapseCompleted();

	int speed;
	int initialLapse, actualLapse; 
	int initialRepeats, actualRepeats;
	bool changeCompleted;
};
#endif
