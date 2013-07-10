#include <iostream>

using namespace std;

unsigned long
hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int main()
{
    unsigned char test[] = "my test";
    unsigned long t = hash(test);
    
    cout << " hash is " << t << endl;

    return 0;
}
