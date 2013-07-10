#include "Expr.h"

using namespace std;

class Expr_node {
    friend ostream& operator<<(ostream&, const Expr_node&);
    friend class Expr;

    int use;
protected:
    Expr_node():use(1){}
    virtual ~Expr_node() {}
public:
    virtual void print(ostream&) const = 0;
};

ostream& operator<<(ostream& o, const Expr_node& e){
    e.print(o);
    return o;
}

class Int_node : public Expr_node {
    friend class Expr;
    int n;

    Int_node(int k) : n(k){}
    void print(ostream& o) const {o << n;}
};

class Unary_node : public Expr_node {
    friend class Expr;
    string op;
    Expr opnd;

    Unary_node(const string& a, Expr b) : op(a), opnd(b){}
    void print(ostream& o) const { o << "(" << op << opnd << ")";}
};

class Binary_node : public Expr_node {
    friend class Expr;
    string op;
    Expr left;
    Expr right;

    Binary_node(const string& a, Expr b, Expr c) : op(a), left(b), right(c){}
    void print(ostream& o) const { o << "(" << left << op << right << ")";}
};


Expr::Expr(int n)
{
    p = new Int_node(n);
}

Expr::Expr(const string& op, Expr t)
{
    p = new Unary_node(op, t);
}

Expr::Expr(const string& op, Expr left, Expr right)
{
    p = new Binary_node(op, left, right);
}

ostream& operator<<(ostream& o, const Expr& t)
{
    t.p->print(o);
    return o;
}

Expr&
Expr::operator=(const Expr& rhs)
{
    rhs.p->use++;
    if (--p->use == 0)
        delete p;
    p = rhs.p;
    return *this;
}

Expr::Expr(const Expr& t)
{
    p=t.p;
    ++p->use;
}

Expr::~Expr()
{
    if (--p->use == 0) delete p;
}

int main()
{
    Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
    cout << t << endl;

    t = Expr("*", t, t);
    cout << t << endl;

    return 0;
}
