#include <stdio.h>

int a[10] = {7, 9, 3, 2, 5, 6, 6, 1, 4, 8};

int swap(int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void bubbleSort(int n)
{
    for (int j = n-1; j >= 0; --j){
        //invariant: [j,n] sorted
        for (int i = j - 1; i>=0; --i){
            if (a[i] > a[j]){
                swap(i, j);
            }
        }
    }
}

void shellSort(int n)
{
    int gap = n / 2;
    while(gap > 0){
        //insert sort
        for (int i = gap; i < n; ++i){
            for (int j = i; j >= 0; j -= gap){
                if (a[j] < a[j - gap]){
                    swap(j, j - gap);
                }
            }
        }
        gap /= 2;
    }
}

void selectSort(int n)
{
    for (int i = 0; i < n; ++i){
        int min = i;
        for (int j = i; j < n; ++j){
            if (a[min] > a[j])
                min = j;
        }
        swap(i, min);
    }
}

int getLeft(int i)
{
    return 2*i;
}

int getRight(int i)
{
    return 2*i + 1;
}

void max_heap_modify(int i, int heapSize)
{
    int l = getLeft(i);
    int r = getRight(i);

    int max;

    if (l < heapSize && a[l] > a[i])
        max = l;
    else
        max = i;

    if (r < heapSize && a[r] > a[max])
        max = r;

    if (max != i){
        swap(max, i);
        max_heap_modify(max, heapSize);
    }
}

void build_max_heap(int n)
{
    for (int i = (n - 1)/2; i >= 0; --i){
        max_heap_modify(i, n);
    }
}

void heapSort(int n)
{
    build_max_heap(n);
    for (int i = n - 1; i > 0; --i){
        swap(i, 0);
        max_heap_modify(0, i);
    }
}

void build_max_heap2(int n)
{
    for (int i = (n - 1)/2; i >= 1; --i){
        max_heap_modify(i, n);
    }
}
//if start from 0, left child will always be 0
void heapSort2(int n)
{
    build_max_heap2(n);
    for (int i = n - 1; i > 0; --i){
        swap(i, 1);
        max_heap_modify(1, i);
    }
}
void merge(int l, int mid, int u)
{
    int* tmp = new int[u - l];

    int i = l;
    int j = mid;
    int k = 0;

    while(i < mid && j < u){
        if (a[i]<=a[j])
            tmp[k++]=a[i++];
        else
            tmp[k++] = a[j++];
    }

    while(i < mid)
        tmp[k++] = a[i++];

    while(j < u)
        tmp[k++] = a[j++];

    for (int i=l, k=0; i < u;)
        a[i++] = tmp[k++];

    delete []tmp;
}

void mergeSort(int l, int u)
{
    if (l < u) {
        int mid = (l + u) / 2;

        mergeSort(l, mid);
        mergeSort(mid+1, u);
        merge(l, mid+1, u+1);
    }
}

void qsort(int l, int u)
{
    if (l > u)
        return;
    int m = l;
    for(int i = l+1; i <= u; ++i){
        //x[l+1...m] < a[l] && x[m+1...i-1] >= a[l]
        if (a[i] < a[l]){
            swap(++m, i);
        }
    }
    //assert(i==u && x[l+1...m] < a[l] && x[m+1 ... u-1] >=a[l]);
    swap(m, l);
    // a[l...m-1]  < x[m]<=x[m+1...u]
    qsort(l, m-1);
    qsort(m+1, u);
}

void qsort2(int l, int u)
{
    if (l >= u)
        return;
    int i = l;
    int j = u + 1;
    int t = a[l];
    while(true){

        do {
            i++;
        } while((i <= u) && (a[i] < t));

        do {
            j--;
        } while(a[j] > t);

        if (i > j)
            break;
        swap(i, j);
    }
    swap(l, j);

    qsort2(l, j - 1);
    qsort2(j + 1, u);
}

int main()
{
    int n = 10;
    //bubbleSort(n);
    //shellSort(n);
    //selectSort(n);
    //heapSort(n);
#if 0
    for (int i = n; i > 0; --i){
        a[i] = a[i-1];
    }
    a[0] = -1;
    heapSort2(n+1);
#endif
    //mergeSort(0, n-1);
    //qsort(0, n-1);
    qsort2(0, n-1);
    for (int i = 0; i < n; ++i){
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}
