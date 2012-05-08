#ifndef POS_ANIMABLE_H
#define POS_ANIMABLE_H
class PosAnimable: public Animable{
public:
	void addChange (int dx, int dy, int time, int repetitions);
	void update();
	Point getPos();
private:
	vector<PosChange> changes;
	Point pos;
};
#endif

