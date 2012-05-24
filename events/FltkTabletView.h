#ifndef FLTKTABLET_VIEW_H
#define FLTKTABLET_VIEW_H
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
#include "TabletView.h" 
using namespace std;
#ifndef WIN32
#  include <unistd.h>
#  include <sys/time.h>
#endif // !WIN32

const int BLOCK_SIZE=80;
const double DRAW_TIME=0.025;

class FltkTabletView : public TabletView,  public Fl_Double_Window {
public:
	FltkTabletView();
	~FltkTabletView();
	void start();
	void stop();
protected:
	void  draw();
private:

	int	  handle(int event);
	void  onClick(int col, int row);
	void  onDoubleClick(int col, int row);
	void  onDrag(int col, int row);
	void  onRelease(int col, int row);
	void  setup();
	static void	timeout_cb(FltkTabletView *bw);
};

#endif
