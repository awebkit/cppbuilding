#include <iostream>

using namespace std;

int compare(int a, int b)
{
    return (a - b);
}

int main()
{
    int a[] = {5, 3, 7, 9, 20, 10};

    int n = 6;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            //if (a[j] > a[j+1]){
            if (compare(a[j], a[j+1]) > 0){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        } 
    }

    for (int i = 0; i < n - 1; i++){
        cout << a[i] << endl;
    }

    return 0;
}
