#ifndef EVENT_LISTENER 
#define EVENT_LISTENER  
#include <vector> 
#include "Pos.h"
#include "Size.h"
#include "Color.h"
#include "Command.h"
#include "EventListener.h"
using namespace std;
class EventListener{
public:
	virtual bool pressed       (Component* c, Pos pos)=0;
	virtual bool released      (Component* c, Pos pos)=0;
	virtual bool clicked       (Component* c, Pos pos)=0;
	virtual bool doubleClicked (Component* c, Pos pos)=0;
	virtual bool dragged       (Component* c, Pos pos)=0;
};
#endif
