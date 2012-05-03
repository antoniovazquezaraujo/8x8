#include <stdio.h>
#include <stdint.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

// Timer callback: determine the number of clicks
static void wait_click(void *v) {
    intptr_t cc = (intptr_t)v;
    int ic = (int)(cc & 0x0F) + 1;
    // If it's a single click, print 1.
    // If it's a double click, print 2 *without* printing the first click!
    printf("Number of clicks: %d\n", ic);
}

// Set up a timer to differentiate single and double clicks
static void timer_extend(int cc) {
    if (cc) Fl::remove_timeout(wait_click);
    Fl::add_timeout(0.25, wait_click, (void*)cc);
}

class MyWindow : public Fl_Window {
public:
    MyWindow(int W,int H,const char *L=0) : Fl_Window(W,H,L) {
    }
    int handle(int e) {
        switch (e) {
              case FL_PUSH:
                // Set a timer to count clicks
                timer_extend(Fl::event_clicks());
                break;
        }
        return(Fl_Window::handle(e));
   }
};

int main() {
    MyWindow win(300,200,"Identify single and double clicks");
    win.show();
    return Fl::run();
}
