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

class UseCount {
public:
    UseCount() : p(new int(1)){}
    UseCount(const UseCount& u) : p(u.p){++*p;}
    ~UseCount() { if(--*p == 0) delete p;}

    bool only() { return *p == 1; }
    bool reattach(const UseCount& u){
        ++*u.p;
        if (--*p == 0) {
            delete p;
            p = u.p;
             return true;
        }
        p = u.p;
        return false;
    }
    bool makeonly(){
        if (*p == 1)
            return false;
        --*p;
        p = new int(1);
        return true;
    }
private:
    UseCount& operator=(const UseCount&);
    int* p;
};

class Handle {
public:
    Handle(): p(new Point) {}
    Handle(int x, int y) : p(new Point(x, y)) {}
    Handle(const Point& p) : p(new Point(p))  { }

    Handle& operator=(const Handle& h){
        if (u.reattach(h.u))
            delete p;
        p = h.p;
        return *this;
    }

    ~Handle() {
        if (u.only())
            delete p;
    }

    int x() const {return p->x();}
    int y() const {return p->y();}
    Handle& x(int xv) {
        if (u.makeonly()){
            p = new Point(*p);
        }
        p->x(xv);
        return *this;
    }
    Handle& y(int yv) {
        if (u.makeonly()){
            p = new Point(*p);
        }
        p->y(yv);
        return *this;
    }

private:
    Point* p;
    UseCount u;
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
