class TabletGame{
public:
	void start();
	void pause();
	void stop();
	void reset();
	void drawRect( int level, Rect rect, Color color, bool filled = false);
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
	Color getColor(int col, int row);
	void setColor(int col, int row,int width, int height, Color color);
};
class FltkTabletGame:public TabletGame{

};
class MoTabletGame: public TabletGame{

};

class TabletEventListener{
public:
	virtual void onClick(int col, int row)=0;
	virtual void onDoubleClick(int col, int row)=0;
	virtual void onRelease(int col, int row)=0;
	virtual void onDrag(int col, int row)=0;
};

class MyGame: public TabletEventListener{
public:
	MyGame()
		:game(new FltkTabletGame(this)){ 
		setup();
	}
	~MyGame(){
		delete game;
	}
	void start(){
		game->start();
	}
	void setup(){

	}
	void onClick(int col, int row){

	}
	void onDoubleClick(int col, int row){

	}
	void onRelease(int col, int row){

	}
	void onDrag(int col, int row){

	}
private:
	TabletGame * game;
};

int main(){
	MyGame g();
	g.start();
}
