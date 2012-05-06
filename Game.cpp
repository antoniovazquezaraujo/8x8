class TabletView{
public:
	void setModel(TabletModel* model){
		this->model = model;
	}
	void setController(TabletController* controller){
		this->controller = controller;
	}
	virtual void start()=0;
	virtual void stop()=0;
private:
	TabletModel * model;
	TabletController* controller;
};

class TabletController{
public:
	TabletController(TabletView * view)
		view(view){
		view->setModel(model);
		view->setController(this);
	}
	~TabletController(){
		delete view;
	}
	void start(){
		view->start();
	}
	void stop(){
		view->stop();
	}
	virtual void onClick(int col, int row)=0;
	virtual void onDoubleClick(int col, int row)=0;
	virtual void onRelease(int col, int row)=0;
	virtual void onDrag(int col, int row)=0;
private:
	TabletModel  model;
	TabletView * view;
};
class Packman: public TabletController{
public:
	Pacman(TabletView* view)
		:TabletControler(view){

	}
	void onClick(int col, int row){
		//Pac, pac, pac ...
	}
};
int main(){
	TabletController * t = new Packman((new FltkTabletView()));
	TabletController * t2= new Packman((new MoTabletView()));
	t.start();
	t2.start();
}
class FltkTabletController : public TabletController{
	FltkTablet()
	:Tablet(new FltkTabletView()){
	Fl::scheme("plastic");
	Fl::visible_focus(0);
};
class MoTabletController: public TabletController{
	MoTablet()
	:Tablet(new MoTabletView()){
	Fl::scheme("plastic");
	Fl::visible_focus(0);
};
