class TabletGame{
public:
	void start();
	void pause();
	void stop();
	void reset();
	void addBox(int level, int col, int row, int width, int height, bool filled = false);
	Box & box(int level, int n);
	void start(Box & box, int turns=-1, int numAnimation = -1);
	void stop(Box & box);
	void addAnimation(
			Box & box,
			unsigned char fromR,
			unsigned char toR,
			unsigned char fromG,
			unsigned char toG,
			unsigned char fromB,     
			unsigned char toB,
			int time
			);
	Box & lastBox(int level);
	void onClick(int col, int row);
	void onDoubleClick(int col, int row);
	void onDrag(int col, int row);
	Color getColor(int col, int row);
	void setColor(int col, int row,int width, int height, Color color);
};
