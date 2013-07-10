#include <iostream>
#include <stdio.h>

using namespace std;

struct mystruct {
    int val;
    struct mystruct *left;
    struct mystruct *right;
};

int main()
{
    struct mystruct testa;
    testa.val = 10;
    testa.left = 0;
    testa.right = 0;
    struct mystruct** a = &testa.left;
    if (!(*a)){
        cout << "a not existed " << endl;
        *a = new struct mystruct();
        printf("testa.left pointer add: %p, %p\n", *a, testa.left);
        (*a)->val = 20;
        //(**a).val = 20;
    }
    if (testa.left){
        cout << "testa left existed" <<endl;
        cout << "left val " << testa.left->val << endl;
    }

    char array[] = "hello";
    printf("%p\n", array);
    char *p = array;
    printf("%p\n", p);
    p = "world";
    printf("%p\n", p);
    cout << array << p << endl;

    return 0;
}
