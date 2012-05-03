#ifndef RECT_H
#define RECT_H
struct Rect{
	Rect(int col=1, int row=1, int width=1, int height=1)
		:col(col), row(row),width(width),height(height){

	}
	int col;
	int row;
	int width;
	int height;
};
#endif
