#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int tempa[n1];
    int tempb[n2];
    for(i = 0; i < n1; i++){
        tempa[i] = arr[l + i];
    }
    for(j = 0; j < n2; j++){
        tempb[j] = arr[j + m + 1];
    }
    i = j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(tempa[i] <= tempb[j]){
            arr[k] = tempa[i];
            i++;
            k++;
        }
        else{
            arr[k] = tempb[j];
            j++;
            k++;
        }
    }
    while(i < n1){
        arr[k] = tempa[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = tempb[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(void)
{
    int arr[8] = {1,5,6,2,7,3,4,8};
    mergeSort(arr, 0, 7);
    int i;
    for(i = 0; i < 8; i++){
        printf("%d", arr[i]);
    }
    return 0;
}