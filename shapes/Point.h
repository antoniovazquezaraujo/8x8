struct Point{
	int col, row;
};
struct Point {
    int x, y;
    Point(int x, int y) 
		: x(x), y(y) { 
	}
    Point() 
		:x(0), y(0) { 
	}
};

inline bool operator==(Point a, Point b) { return a.x==b.x && a.y==b.y; } 
inline bool operator!=(Point a, Point b) { return !(a==b); }
