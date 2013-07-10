#include <iostream>

using namespace std;

#define MEM_FISRT 1

int main()
{
    double len;
#if MEM_FIRST 
    while(cin >> len && len != 0.00){
        double sum = 0.0;
        double n = 2.0;
        while(1){
            sum += 1.0 / n;
            if (sum >= len) break;
            n += 1.0;
        }
        cout << (double)n-1 << " card(s)"<< endl;
    }
#else
    double res[300] = {0.0, 0.5};
    for (int i = 2; i < 300;++i){
        res[i] = res[i-1] + 1.0/(i+1);
    }
    while(cin >> len && len != 0.00){
        for (int i = 0; i < 300; ++i){
            if (res[i] >= len) {
                cout << i << " card(s)"<< endl;
                break;
            }
        }
    }
#endif

    return 0;
}
