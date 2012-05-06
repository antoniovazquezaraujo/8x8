Shape::Shape() 
	:lcolor(fl_color()),      // default color for lines and characters
    fcolor(Color::invisible) {
	
}

void Shape::add(Point p) {
    points.push_back(p);
}

void Shape::setPoint(int i,Point p){
    points[i] = p;
}


void Shape::draw() const {
    Fl_Color oldc = fl_color();
    // there is no good portable way of retrieving the current style
    fl_color(lcolor.as_int());            // set color
    fl_line_style(ls.style(),ls.width()); // set style
    if (color().visibility() && 1<points.size())    // draw sole pixel?
        for (unsigned int i=1; i<points.size(); ++i)
            fl_line(points[i-1].x,points[i-1].y,points[i].x,points[i].y);
    fl_color(oldc);      // reset color (to previous)
    fl_line_style(0);    // reset line style to default
}

void Shape::move(int dx, int dy){
    for (int i = 0; i<points.size(); ++i) {
        points[i].x+=dx;
        points[i].y+=dy;
    }
}

Line::Line(Point p1, Point p2)   {
    add(p1);
    add(p2);
}

void Rectangle::draw() const {
    if (fill_color().visibility()) {    // fill
        fl_color(fill_color().as_int());
        fl_rectf(point(0).x,point(0).y,w,h);
    }

    if (color().visibility()) {    // lines on top of fill
        fl_color(color().as_int());
        fl_rect(point(0).x,point(0).y,w,h);
    }
}

Circle::Circle(Point p, int rr)    // center and radius
	:r(rr) {
    add(Point(p.x-r,p.y-r));       // store top-left corner
}

Point Circle::center() const {
    return Point(point(0).x+r, point(0).y+r);
}

void Circle::draw() const {
    if (color().visibility())
        fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
}

void Ellipse::draw() const {
    if (color().visibility())
        fl_arc(point(0).x,point(0).y,w+w,h+h,0,360);
}


