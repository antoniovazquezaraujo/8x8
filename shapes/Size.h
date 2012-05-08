#ifndef SIZE_H
#define SIZE_H
class Size {
public:
    Size(int w=0, int h=0) 
		: w(w), h(h) { 
	}
    int w, h;
};

inline bool operator==(Size a, Size b) { return a.w==b.w && a.h==b.h; } 
inline bool operator!=(Size a, Size b) { return !(a==b); }
#endif
