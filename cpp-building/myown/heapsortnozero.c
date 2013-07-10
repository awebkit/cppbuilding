#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define MAX 10 
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

void createHeap(int[]); 
void heapSort(int[]); 

int main(void) { 
    srand(time(NULL)); 
    
    int number[MAX+1] = {-1}; 

    printf("排序前："); 
    int i;
    for(i = 1; i <= MAX; i++) { 
        number[i] = rand() % 100; 
        printf("%d ", number[i]); 
    } 

    printf("\n建立堆積樹："); 
    createHeap(number); 
    
    for(i = 1; i <= MAX; i++) 
        printf("%d ", number[i]); 
    printf("\n"); 

    heapSort(number); 
    
    printf("排序後："); 
    for(i = 1; i <= MAX; i++) { 
        printf("%d ", number[i]); 
    } 

    return 0; 
} 

void createHeap(int number[]) { 
    int heap[MAX+1] = {-1}; 

    int i;
    for(i = 1; i <= MAX; i++) { 
        heap[i] = number[i]; 
        int s = i; 
        int p = i / 2; 
        while(s >= 2 && heap[p] > heap[s]) { 
            SWAP(heap[p], heap[s]); 
            s = p; 
            p = s / 2; 
        } 
    }
    int j;
    for(j = 1; j <= MAX; j++) 
        number[j] = heap[j]; 
    
} 

void heapSort(int number[]) { 
    int m = MAX; 
    while(m > 1) { 
        SWAP(number[1], number[m]); 
        m--; 

        int p = 1; 
        int s = 2 * p; 

        while(s <= m) { 
            if(s < m && number[s+1] < number[s]) 
                s++; 
            if(number[p] <= number[s]) 
                break; 
            SWAP(number[p], number[s]); 
            p = s; 
            s = 2 * p; 
        } 
    } 
}
