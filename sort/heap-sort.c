#include <stdio.h>
#include <math.h>

void heapify(int arr[], int n, int m);
void heapSort(int arr[], int size);
void buildMaxHeap(int arr[], int n);
void swap(int arr[], int n, int m);
int main(void){
    int a[] = {3,5,7,8,2,4,1};
    size_t n = 7;
    heapSort(a, n);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}

void heapSort(int arr[], int size){
    int n = size;
    while(n > 1){
        // make the biggest on the root then swap index 0 and n-1
        // the biggest is the last element of array
        // then repeat build max heap
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

// buildMaxHeap make the biggest if arr on the root
void buildMaxHeap(int arr[], int n){
    int start = floor(n/2);
    while(start >= 1){
        heapify(arr, start - 1, n);
        start--;
    }
}

//n index  len is the length of arr
// heapify make the sub tree from n index biggest on the root
void heapify(int arr[], int n, int len){
    int largest = n;
    int lchild = 2*n + 1;
    int rchild = 2*n + 2;
    if(lchild <= len - 1 && arr[lchild] > arr[largest]){
        swap(arr, largest, lchild);
        largest = lchild;
    }
    if(rchild <= len - 1 && arr[rchild] > arr[largest]){
        swap(arr, rchild, largest);
        largest = rchild;
    }
    if(largest != n){
        heapify(arr, largest, len);
    }
}
