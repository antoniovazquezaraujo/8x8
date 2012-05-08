#ifndef COLOR_CHANGE_H 
#define COLOR_CHANGE_H 
class ColorChange {
public:
	static void test();
	ColorChange(
		int fromR = 0, int toR = 0, 
		int fromG = 0, int toG = 0,
		int fromB = 0, int toB = 0, 
		int time = 1
	);
	void reset();
	void update();
	bool isFinished();
	void start();
	void stop();
	Color getColor();

private:
	Color color;
	Color from, to;
	int rDelta, gDelta, bDelta;
	int rLapse, gLapse, bLapse;
	int rRange, gRange, bRange;
	int rCount, gCount, bCount;
};

#endif
