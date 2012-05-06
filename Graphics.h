#ifndef GRAPHICS
#define GRAPHICS

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

struct Color {
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha=0)
		:r(r), g(g), b(b), alpha(alpha){

	}
	setR(unsigned char r){this->r = r;}
	setG(unsigned char g){this->g = g;}
	setB(unsigned char b){this->b = b;}
	unsigned char getR(){return r;}
	unsigned char getG(){return g;}
	unsigned char getB(){return b;}
    int getRGB()  const {return (r<<16) |(g<<8) | b;} 
    int getRGBA() const {return (r<<16) |(g<<8) | b |(alpha << 32);} 
    unsigned char getAlpha() const { return alpha; } 
    void setAlpha(unsigned char alpha) { this->alpha=alpha; }
private:
    unsigned char r,g,b;
    unsigned char alpha;    
};

template<class T> class vector_ref {
public:
    vector_ref() {
	}
    vector_ref(T& a) { 
		push_back(a); 
	}
    ~vector_ref() { 
		for (int i=0; i<owned.size(); ++i) {
			delete owned[i]; 
		}
	}
    void push_back(T& s) { v.push_back(&s); }
    void push_back(T* p) { v.push_back(p); owned.push_back(p); }
    T&       operator[](int i)       { return *v[i]; }
    const T& operator[](int i) const { return *v[i]; }
    int size() const { return v.size(); }
private:
    vector<T*> v;
    vector<T*> owned;
};


class Shape  {        
public:
    void draw() const;                
    virtual void move(int dx, int dy); 
    void setColor(Color col) { lcolor = col; }
    Color getColor() const { return lcolor; }
    void setFillColor(Color col) { fcolor = col; }
    Color getFillColor() const { return fcolor; }
    Point getPoint(int i) const { return points[i]; } // read only access to points
    int getNumberOfPoints() const { return int(points.size()); }
    virtual ~Shape() { }
protected:
    Shape();    
    virtual void draw() const; 
    void add(Point p);         
    void setPoint(int i,Point p);    
private:
    vector<Point> points;              
    Color lcolor;                      // color for lines 
    Color fcolor;                      // fill color
    Shape(const Shape&);               // prevent copying
    Shape& operator=(const Shape&);
};

struct Line : Shape {            // a Line is a Shape defined by two Points
    Line(Point p1, Point p2);    // construct a line from two points
};

struct Box: Shape {
    Box(Point xy, int w, int h) 
		: w(w), h(h) {
        add(xy);
        if (h<=0 || w<=0) error("Bad rectangle: non-positive side");
    }

    Box(Point x, Point y) 
		: w(y.x-x.x), h(y.y-x.y) {
        add(x);
        if (h<=0 || w<=0) error("Bad rectangle: non-positive width or height");
    }
    void draw() const;
    int getHeight() const { return h; }
    int getWidth()  const { return w; }
private:
    int h;    // height
    int w;    // width
};

struct Circle : Shape {
    Circle(Point p, int rr);    // center and radius
    void draw() const;
    Point center() const ; 
    int getRadius() const { return r; }
    void setRadius(int rr) { r=rr; }
private:
    int r;
};


struct Ellipse : Shape {
    Ellipse(Point p, int w, int h)    // center, min, and max distance from center
        : w(w), h(h) { 
        add(Point(p.x-w,p.y-h));
    }

    void draw() const;
    Point getCenter() const { return Point(point(0).x+w,point(0).y+h); }
    Point getFocus1() const { return Point(center().x+int(sqrt(double(w*w-h*h))),center().y); }
    Point getFocus2() const { return Point(center().x-int(sqrt(double(w*w-h*h))),center().y); }
    void setMajor(int ww) { w=ww; }
    int getMajor() const { return w; }
    void setMinor(int hh) { h=hh; }
    int getMinor() const { return h; }
private:
    int w;
    int h;
};

#endif
