#include <iostream>
#include <math.h>

using namespace std;

#define FLOAT_ZERO 0.0001

struct pf
{     
    float x;     
    float y;     
};

float calcArea(pf A, pf B, pf C)
{
    pf AB, BC;
    AB.x = A.x - B.x;
    AB.y = A.y - B.y;

    BC.x = B.x - C.x;
    BC.y = B.y - C.y;

    return fabs(AB.x * BC.y - AB.y * BC.x)/2.0f;
}

bool isPtInTri(pf A, pf B, pf C, pf P)
{
    float PAB, PAC, PBC, ABC;

    PAB = calcArea(P, A, B);
    PAC = calcArea(P, A, C);
    PBC = calcArea(P, B, C);
    ABC = calcArea(A, B, C);

    float sum = PAB + PAC + PBC;

    if ( ((ABC - sum) > -FLOAT_ZERO) && ((ABC - sum) < FLOAT_ZERO)){
        return true;
    } else
        return false;
}

int main()
{
    pf A, B, C, P;

    A.x = A.y = 0.0;

    B.x = 0.0;
    B.y = 4.0;

    C.x = 4.0;
    C.y = 0.0;

    P.x = 2.0;
    P.y = 2.0;

    float area = calcArea(A, B, C);
   
    cout << area << endl;
    bool ret = isPtInTri(A, B, C, P);
    if (ret)
        cout << "in it" << endl;
    else
        cout << "not in it" << endl;
}
