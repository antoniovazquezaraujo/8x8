#ifndef TABLET_VIEW_H
#define TABLET_VIEW_H

#include <conprint.h>
#include <MAUtil/Environment.h>
#include <MAUtil/Moblet.h>
#include <madmath.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#ifndef WIN32
#  include <unistd.h>
#  include <sys/time.h>
#endif // !WIN32

#include "Tablet.h"

using namespace MAUtil;
using namespace std;

#ifdef MA_PROF_SUPPORT_STYLUS
#define MESSAGE "Tap screen to bounce"
#else
#define MESSAGE "Press fire to bounce"
#endif

#define TIMER_PERIOD 20
const int BLOCK_SIZE=80;

class TabletController;
class TabletView :  public Moblet, public TimerListener{
public:

	TabletView(Tablet & t, TabletController * controller);
	~TabletView();

private:
	Tablet & tablet;
	void runTimerEvent();
	void keyPressEvent(int keyCode, int nativeCode);
	virtual void pointerPressEvent(MAPoint2d p);
	virtual void pointerMoveEvent(MAPoint2d p);
	virtual void pointerReleaseEvent(MAPoint2d p) ;
	TabletController * controller;
	int screenWidth;
	int screenHeight;
	int blockSize;
};

#endif
