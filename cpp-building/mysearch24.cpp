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
#define COUNT 3
int number[COUNT] = {5,6,7};
int used[COUNT] = {0};
int used2[COUNT] = {0};
char op[5] = "+-*/";

int calc2(int a, int f, char o)
{
    //for test, we use a static variable 
    static int calcResult = 100;
    cout << "calc " << a << " " << o << " "<< f << endl;
    cout << "fake result " << ++calcResult << endl;

    return calcResult;
}

int chk(int result)
{
    cout << "Check result " << result << endl;
    return 0;
}

int search24(int a[], int d)
{
    //
    if (d == 1) {
        cout << "search for unused " << endl;
        for (int i = 0; i < COUNT; ++i){
            if (used[i]==1 || used2[i] == 1)
                continue;
            used2[i] = 1;
            return number[i];
        }
        return -1;
    }
    for (){
        if ()
            continue;
        expression[] = ;
        for () {
            //
            expression[] = op[k];
        }
        search24(tmp, arrayNum);
    }
}

int traverse(int leftChild, int root)
{
     expression[] = leftChild;
     expression[] = root;

     for (int i = 0; i < COUNT; ++i) {
         if (number[i].used == 1)
             continue;
         number[i].used = 1;
         for (int j = 0; j < 4; ++j) {
             traverse(number[i].num, op[j]);
         }
         number[i].used = 0;
    }
}


int main()
{
    cout << "Begin search 24 " << endl;
    search24(number, COUNT);
    cout << "End search 24 " << endl;
    return 0;
}
