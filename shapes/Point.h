#ifndef POINT_H
#define POINT_H
struct Point {
    Point(int x=0, int y=0) 
		: x(x), y(y) { 
	}
    int x, y;
};

inline bool operator==(Point a, Point b) { return a.x==b.x && a.y==b.y; } 
inline bool operator!=(Point a, Point b) { return !(a==b); }
#endif
