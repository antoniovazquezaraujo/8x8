#include "TabletController.h"
extern "C" int MAMain() {
	TabletController t;
	t.setup();
	t.start();
}
