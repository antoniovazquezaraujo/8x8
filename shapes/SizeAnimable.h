#ifndef SIZE_ANIMABLE_H
#define SIZE_ANIMABLE_H
class SizeAnimable: public Animable{
public:
	void addChange(int dw, int dh, int duration, int repeats);
	void update();
	Size getSize();
private:
	vector<SizeChange> changes;
	Size size;
};
#endif

