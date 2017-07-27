#include <stdio.h>
#include <math.h>

void heapify(int arr[], int n, int m);
void heapSort(int arr[], int size);
void buildMaxHeap(int arr[], int n);
void swap(int arr[], int n, int m);
int main(void){
    int a[] = {3,9,2,6,5,1,7};
    int n = sizeof(a)/sizeof(a[0]);
    heapSort(a, n);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}

void heapSort(int arr[], int size){
    int n = size;
    while(n > 1){
        buildMaxHeap(arr, n);
        swap(arr, 0, n - 1);
        n--;
    }
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void buildMaxHeap(int arr[], int n){
    int start = floor(n/2);
    while(start >= 1){
        heapify(arr, start - 1, n);
    }
}

//n index  len count
void heapify(int arr[], int n, int len){
    int largest = n;
    int lchild = 2*n + 1;
    int rchild = 2*n + 2;
    if(lchild <= len - 1 && arr[lchild] > arr[largest]){
        swap(arr, largest, lchild);
        largest = lchild;
    }
    if(rchild <= len -1 && arr[rchild] > arr[largest]){
        swap(arr, rchild, largest);
        largest = rchild;
    }
    if(largest != n){
        heapify(arr, largest, len);
    }
}