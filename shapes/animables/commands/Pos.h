#ifndef POS
#define POS
#include "PosStep.h"
class Pos{
public:
	Pos(int x=0, int y=0);
	PosStep stepTo(Pos p);
	void operator+=(PosStep step);
	void approachTo(Pos to, PosStep step);
	int x,y;
};
bool operator==(const Pos & p, const Pos & q){
	return ((p.x == q.x) && (p.y == q.y));
}
#endif
