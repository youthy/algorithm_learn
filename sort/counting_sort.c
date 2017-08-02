// use counting sort when you know the range of elements in array
// best O(n) average O(n) worst O(n)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 10
#define RANGE 20
void countSort(int arr[], int len, int max);
int main(void){
    srand(time(NULL));
    int arr[RANGE];
    for(int i = 0; i < RANGE; i++){
        arr[i] = rand() % MAX;
    }
    countSort(arr, RANGE, MAX);
    for(int i = 0; i < RANGE; i++){
        printf("%d\n", arr[i]);
    }
}

void countSort(int arr[], int len, int max){
    int count[max];
    memset(count, 0, sizeof(int)*max);
    int temp = 0;
    for(int i = 0; i < len; i++){
        int v = arr[i];
        temp = count[v];
        count[v] = temp + 1;
    }
    int index = 0;
    for(int i = 0; i < max; i++){
        int c = count[i];
        while(c > 0){
            arr[index] = i;
            index++;
            c--;
        }
    }
}
