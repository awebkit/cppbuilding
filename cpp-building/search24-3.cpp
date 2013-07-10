/*
 *
 * (a + (b - c) * d 
 * ====>
 * d * (a + (b - c))
 * ====>
 *     (*)
 *    /  \
 *   d    +
 *       / \
 *      a   -
 *        / \
 *       b   c
 *
 * Our target is traverse the trees in the forest.
               
       +             +            +             +             -
      / \           / \          / \           / \           / \
     a  f(b,c,d)   b   f(a,c,d) c   f(a,b,d)  d  f(a,b,c)   a  f(b,c,d)
 */
#include <iostream>
#include <string.h>

using namespace std;
#define NUMBER 3
int number[NUMBER] = {5,6,7};
int used[NUMBER] = {0};

char op[5] = "+-*/";

int calc2(int a, int f, char o)
{
    int result;
    cout << "calc " << a << " " << o << " "<< f << endl;
    switch(o) {
        case '+':
            result = a+f;
            break;
        case '-':
            result = a-f;
            break;
        case '*':
            result = a*f;
            break;
        case '/':
            result = a/f;
            break;

    }
    cout << "Result is " << result << endl;
    /*
    //for test, we use a static variable 
    static int calcResult = 1;
    cout << "calc " << a << " " << o << " "<< f << endl;
    cout << "fake result " << calcResult++ << endl;

    return calcResult;
    */
}

int chk(int result)
{
    cout << "Check result " << result << endl;
    return 0;
}

int search24(int d)
{
    //
    if (d == 1) {
        int result = 0;
        int mycount = 0;
        cout << "search for unused " << endl;
        for (int i = 0; i < NUMBER; ++i){
            if (used[i]==1)
                continue;
            mycount++;
            result = number[i];
        }
        if (mycount > 1)
            cout << "Error !!! " << endl;
        return result;
    }
    for (int i = 0; i < NUMBER; ++i){ // operator
        if (used[i] == 1)
            continue;
        used[i] = 1;
        for(int k = 0; k < 4; ++k) { //
            cout << "calc using " << op[k] << endl;
            int result = calc2(number[i], search24(d - 1), op[k]);
        }
        used[i] = 0;
    }
}


int main()
{
    cout << "Begin search 24 " << endl;
    //search24(NUMBER);
    for (){
        for (){
            :wq
        }
    }
    cout << "End search 24 " << endl;
    return 0;
}
