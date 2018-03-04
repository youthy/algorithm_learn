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
    }
    return 0;
}

int main(void)
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    left_rotote(a, 13, 10);
    print_array(a, 10);
    int arr[4][4]={{1,2,3,4}, {3,5,7,9}, {5,6,7,8}, {7,9,10,11}};
    printf("order 2d member:%d", ordered_2d_array_member(arr, 4, 4, 3));
    return 0;
}