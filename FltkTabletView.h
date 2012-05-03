#ifndef TABLET_VIEW_H
#define TABLET_VIEW_H
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Preferences.H>
#include <FL/fl_draw.H>
#include <FL/x.H>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "TabletModel.h" 
using namespace std;
class FltkTabletController;
#ifndef WIN32
#  include <unistd.h>
#  include <sys/time.h>
#endif // !WIN32

const int BLOCK_SIZE=80;
const double DRAW_TIME=0.025;

class FltkTabletView : public Fl_Double_Window {
public:

	FltkTabletView(TabletModel & t, FltkTabletController * controller);
	~FltkTabletView();
	int	  handle(int event);

protected:
	void  draw();

private:
	TabletModel & model;
	void  onClick(int col, int row);
	void  onDrag(int col, int row);
	void  onRelease(int col, int row);
	void  setup();
	static void	timeout_cb(FltkTabletView *bw);
	FltkTabletController * controller;
};

#endif
