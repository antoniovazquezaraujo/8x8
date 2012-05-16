#ifndef POS_CHANGE
#define POS_CHANGE
class PosChange: public Change{
public:
	PosChange(Pos from, Pos to, int speed, int repeats);
	PosChange(PosStep step, int speed, int repeats);
	bool isCompleted();
	void update(Form * b);
private:
	void resetData();
	Pos from, to, actual;
	PosStep step;
	bool isRelative;
};
#endif
