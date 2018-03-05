#include <stdio.h>
#include <stdlib.h>

// util
void print_array(int *arr, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// *** rotation of array
void left_rotote(int *arr, int n, int len)
{
    int n1 = n % len;
    int tmp = 0;
    while(n1)
    {
        tmp = arr[0];
        for(int i = 0; i < len - 1; i++)
            arr[i] = arr[i + 1];
        arr[len - 1] = tmp;
        n1--;
    }
}

int ordered_2d_array_member(int *arr, int m, int n, int num)
{
    int cols, rows;
    cols = rows = 0;
    int tmp;
    while(cols < m && *(arr + cols* m) <= num)
    {
        for(rows = 0; rows < n; rows++)
        {
            tmp = *(arr + cols * m + rows);
            if(tmp == num)
                return 1;
            else if(tmp > num)
                break;
        }
        cols++;
    }
    return 0;
}

int pivot_binary_search(int arr[], int start, int end, int n)
{
    int mid = (start + end)/2;
    if(arr[mid] == n)
        return mid;
    if(start == end)
        return 0;
    if(arr[mid] < n)
    {
        if (arr[end] > arr[mid + 1] && arr[mid + 1] > arr[mid])
            return pivot_binary_search(arr, mid + 1, end, n);
        if(arr[mid + 1] > arr[end])
            return pivot_binary_search(arr, mid + 1, end, n);
        return pivot_binary_search(arr, start, mid - 1, n);
    }
    else
    {
        if(arr[start] > n && arr[mid] > arr[start])
            return pivot_binary_search(arr, mid + 1, end, n);
    }
}

int binary_search(int arr[], int start, int end, int n)
{
    int mid = (start + end)/2;
    if(arr[mid] == n)
        return mid;
    if(start == end)
        return 0;
    if(arr[mid] < n)
        return binary_search(arr, mid + 1, end, n);
    else
        return binary_search(arr, start, mid - 1, n);
}

int main(void)
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    left_rotote(a, 13, 10);
    print_array(a, 10);
    int arr[4][4]={{1,2,3,4}, {3,5,7,9}, {5,6,7,8}, {7,9,10,11}};
    printf("order 2d member:%d", ordered_2d_array_member((int *)arr, 4, 4, 20));
    return 0;
}