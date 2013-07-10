#ifndef Expr_h
#define Expr_h

#include <iostream>
#include <string>
using namespace std;

class Expr_node;
class Expr {
    friend ostream& operator<<(ostream&, const Expr&);
    Expr_node* p;

public:
    Expr():p(0){}
    Expr(int);
    Expr(const string&, Expr);
    Expr(const string&, Expr, Expr);

    Expr(const Expr& t);
    ~Expr();
    Expr& operator=(const Expr& t);
};

#endif
