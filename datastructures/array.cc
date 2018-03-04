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

int main(void)
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    left_rotote(a, 13, 10);
    print_array(a, 10);
    return 0;
}