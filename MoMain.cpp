#include "MoTabletController.h"
extern "C" int MAMain() {
	MoTabletController t;
	t.setup();
	t.start();
}
