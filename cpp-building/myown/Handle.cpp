#include <iostream>

using namespace std;

class Point {
public:
    Point() : xval(0), yval(0){}
    Point(int x, int y) : xval(x), yval(y) {}
    int x() const {return xval;}
    int y() const {return yval;}
    Point& x(int xv) {xval = xv; return *this;}
    Point& y(int yv) {yval = yv; return *this;}

private:
    int xval, yval;
};

class UPoint {

    friend class Handle;

    Point p;
    int u;

    UPoint():u(1) {}
    UPoint(int x, int y) : p(x, y), u(1){}
    UPoint(const Point& p0) : p(p0), u(1) {}
};

class Handle {
public:
    Handle(): up(new UPoint) {}
    Handle(int x, int y) : up(new UPoint(x, y)) {}
    Handle(const Point& p) : up(new UPoint(p))  { }
    Handle(const Handle& h) : up(h.up){ ++up->u; }

    Handle& operator=(const Handle& h){
        ++h.up->u;
        if (--up->u == 0)
            delete up;
        up = h.up;
        return *this;
    }

    ~Handle() {
        if (--up->u == 0)
            delete up;
    }

    int x() const {return up->p.x();}
    int y() const {return up->p.y();}
    Handle& x(int xv) {
        if (up->u != 1){
            --up->u;
            up = new UPoint(up->p);
        }
        up->p.x(xv);
        return *this;
    }
    Handle& y(int yv) {
        if (up->u != 1){
            --up->u;
            up = new UPoint(up->p);
        }
        up->p.y(yv);
        return *this;
    }

private:
    UPoint* up;
};

int main()
{
    Handle h(3,4);
    Handle h2 = h;

    h2.x(5);
    int n = h.x();

    cout << n << endl;
    return 0;
}
