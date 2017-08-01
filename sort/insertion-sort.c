#include <stdio.h>

void insert(int arr[], int i)
{
    int j = i -1;
    int tmp = arr[i];
    while(j >= 0 && arr[j] > tmp){
        arr[j+1] = arr[j];
        j--;
    };
    arr[j+1] = tmp;
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        insert(arr, i);
    }
}

int main(){
    int a[] = {4,2,1,5,3};
    insertionSort(a, 5);
    for (int i = 0; i < 5; i++)
        printf("%d", a[i]);
}
