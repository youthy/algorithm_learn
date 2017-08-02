#include <stdio.h>

int partition(int [], int ,int);
void swap(int [], int, int);
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pindex = partition(arr, low, high);
        quickSort(arr, low, pindex - 1);
        quickSort(arr, pindex + 1, high);
    }
}

int partition(int arr[], int low, int high){
    if(low < high){
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        do{
            while(arr[i] <= pivot && i != j){
                i++;
            };
            swap(arr, i, j);
            while(arr[j] > pivot && i != j){
                j--;
            }
            swap(arr, i, j);
        }while(i != j);
        if (arr[i] < arr[low])
        {
            swap(arr, low, i);
        }
        return i;
    }
    return low;
}

void swap(int arr[], int i, int j){
    if(i != j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int main(){
    int a[] = {1,3,4,2,5,7,8,6};
    quickSort(a, 0, 7);
    for(int i = 0; i < 8; i++){
        printf("%d", a[i]);
    }
}