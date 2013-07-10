#include <iostream>
#include <string.h>

using namespace std;

int find1(int* A, int n)
{
    int max = 0;
    int sum = 0;
    //sum[i...j] 0<=i<=j<n 
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            for (int k = i; k <= j; ++k){
                sum += A[k];
                cout << i << " " << j << ":" << sum << endl;
            }
            if (max < sum)
                max = sum;
            sum = 0;
        }
    }
    return max;
}
/*
 * sum[i]为包含<strong>a[i]</strong>的最大连续子串和
 * sum[i] = max(a[i], sum[i -1] + a[i]);
 * result = max(result, sum[i]);
 */
int find2(int* A, int n)
{
    int sum[n];
    memset(sum, 0, sizeof(sum));
    sum[0] = A[0];
    int mymax = A[0];
    for (int i = 1; i < n; ++i){
        sum[i] = max(A[i], sum[i - 1] + A[i]);
        if (mymax < sum[i]){
            mymax = sum[i];
        }
        cout << i << ":" << sum[i] << ", " << mymax << endl;
    }
    return mymax;
}

int find3(int* A, int n)
{
    int max = 0;
    int sum = 0;
    //sum[i...j] 0<=i<=j<n 
    for (int i = 0; i < n; ++i){
        sum = 0;
        for (int j = i; j < n; ++j){
            sum += A[j];
            cout << i << " " << j << ":" << sum << endl;
            if (max < sum)
                max = sum;
        }
    }
    return max;
}

int main()
{
    int a[8] = {1, -2, 3, 10, -4, 7, 2, -5};
    //int a[] = {4, 5, 6, 7};
    int r = find2(a, sizeof(a)/sizeof(a[0]));
    cout << " max " << r << endl;
    return 0;
}
