#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 20
void selectionSort(int arr[], int n);
int main(void){
    int arr[LEN];
    srand(time(NULL));
    // random array
    for(int i = 0; i < LEN; i++){
        arr[i] = rand() % 20;
    }
    //sort
    selectionSort(arr, LEN);
    // print
    for(int i = 0; i < LEN; i++){
        printf("%d\n", arr[i]);
    }
}

void selectionSort(int arr[], int n){
    int min;
    for(int i = 0; i < n; i++){
        min = arr[i];
        for(int j = i + 1; j < n; j++){
            if(arr[j] < min){
                int t = min;
                min = arr[j];
                arr[j] = t;
            }
        };
        arr[i] = min;
    }
}
