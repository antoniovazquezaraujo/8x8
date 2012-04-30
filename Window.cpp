#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Preferences.H>
#include <FL/fl_draw.H>
#include <FL/x.H>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


#ifndef WIN32
#  include <unistd.h>
#  include <sys/time.h>
#endif // !WIN32


#define BLOCK_COLS	20
#define BLOCK_ROWS	10
#define BLOCK_SIZE	32
#define BLOCK_BLAST	100

/////////////////////////////////////////////////////////////////////
class BlockWindow : public Fl_Double_Window {
public:
	struct Block {
		int		color;
		bool	bomb;
		int		y;
	};

	struct Column {
		int		num_blocks;
		Block	blocks[BLOCK_ROWS];
		int		x;
	};

	BlockWindow(int X, int Y, int W, int H, const char *L = 0);
	BlockWindow(int W, int H, const char *L = 0);
	~BlockWindow();

	void  draw();
	int	  handle(int event);
	void  new_game();

private:

	Fl_Button	*help_button_, *play_button_;
	int		num_columns_;
	Column	columns_[BLOCK_COLS];
	int		count_;
	bool	help_;
	int		high_score_;
	float	interval_;
	int		level_;
	int		num_colors_;
	int		opened_columns_;
	bool	paused_;
	int		score_;
	char    title_[255];
	int		title_y_;

	void	setup();
	int		bomb(int color);
	int		click(int col, int row);
	void	reset();

	static Fl_Preferences	prefs_;

	static void	help_cb(Fl_Widget *wi, BlockWindow *bw);
	static void	play_cb(Fl_Widget *wi, BlockWindow *bw);
	static void	timeout_cb(BlockWindow *bw);
};

Fl_Preferences	BlockWindow::prefs_(Fl_Preferences::USER, "fltk.org", "blocks");


int main(int argc, char *argv[]) {
	Fl::scheme("plastic");
	Fl::visible_focus(0);

	BlockWindow *bw = new BlockWindow(
		BLOCK_COLS * BLOCK_SIZE,
		BLOCK_ROWS * BLOCK_SIZE + 20,
		"Block Attack!"
	);

	bw->show(argc, argv);
	return (Fl::run());
}

BlockWindow::BlockWindow(int X, int Y, int W, int H, const char *L)
	: Fl_Double_Window(X, Y, W, H, L) {
	setup();
}

BlockWindow::BlockWindow(int W, int H, const char *L)
	: Fl_Double_Window(W, H, L) {
	setup();
}

BlockWindow::~BlockWindow() {
	Fl::remove_timeout((Fl_Timeout_Handler)timeout_cb, (void *)this);
}

void BlockWindow::setup() {
	reset();
	prefs_.get("high_score", high_score_, 0);
	Fl::add_timeout(0.1, (Fl_Timeout_Handler)timeout_cb, (void *)this);
}

// Tag all blocks connected to the clicked block and return the number
// of affected blocks
int BlockWindow::click(int col, int row) {
}


// Draw the block window...
void BlockWindow::draw() {
	int		j, k, xx, yy;
	Block		*b;
	Column	*c;

	// Draw the blocks...
	fl_color(FL_BLACK);
	fl_rectf(0, 0, w(), h());

	// Draw the blocks...
	for (j = num_columns_, c = columns_; j > 0; j --, c ++){
		for (k = c->num_blocks, b = c->blocks; k > 0; k --, b ++) {
			xx = w() - c->x;
			yy = h() - BLOCK_SIZE - b->y;
			fl_rectf( j*xx, k*yy, xx, yy,  200,0,200);
		}
	}

	// Draw the scores and level...
	char s[255];
	sprintf(s, " Score: %d", score_);
	fl_color(FL_WHITE);
	fl_font(FL_HELVETICA, 14);
	fl_draw(s, 40, 0, w() - 40, 20, FL_ALIGN_LEFT);
}


int BlockWindow::handle(int event) {
	int		j, k, mx, my, count;
	Block		*b;
	Column	*c;

	if (Fl_Double_Window::handle(event)){
		return (1);
	} 

	if (interval_ < 0.0 || paused_){
		return (0);
	}

	switch (event) {
	case FL_PUSH :
		if(Fl::event_clicks()!=0){
			//doble click
		}
		mx    = w() - Fl::event_x() + BLOCK_SIZE;
		my    = h() - Fl::event_y();
		return (1);
	case FL_DRAG:
		break;
	case FL_RELEASE:
		break;
	}
	return (0);
}



// Initialize the block window...
void BlockWindow::reset() {
	count_       = 0;
	help_        = false;
	interval_    = -1.0;
	level_       = 1;
	num_colors_  = 3;
	num_columns_ = 0;
	paused_      = false;
	score_       = 0;
	title_[0]    = '\0';
	title_y_     = 0;
}


// Start a new game...
void BlockWindow::new_game() {
	srand(time(NULL));
	reset();
	interval_       = 0.1;
	opened_columns_ = 0;
	strcpy(title_, "Level: 1");
	title_y_ = h();
	redraw();
}


// Animate the game...
void BlockWindow::timeout_cb(BlockWindow *bw) {
	int		i, j;
	Block	*b;
	Column	*c;
	int		lastx, lasty;

	// Update blocks that have been destroyed...
	for (i = 0, c = bw->columns_; i < bw->num_columns_; i ++, c ++){
		for (j = 0, b = c->blocks; j < c->num_blocks; j ++, b ++){
			if (b->color > (BLOCK_BLAST + 1)) {
				bw->redraw();
			}
		}
	}

	Fl::repeat_timeout(0.1, (Fl_Timeout_Handler)timeout_cb, (void *)bw);
}

