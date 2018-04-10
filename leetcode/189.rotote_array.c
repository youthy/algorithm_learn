#include <stdlib.h>
#include <stdio.h>

void swap(int *nums, int i, int j)
{
    int tmp = nums[j];
    nums[j] = nums[i];
    nums[i] = tmp;
}
// 提交的时候是100% beats c solutions
void rotate(int *nums, int numsSize, int k)
{
    k = k % numsSize; // 一开始没有这句。在{1，2}， 2， 3 这种情况下会失败。
   int tmp = numsSize - k - 1;
   int i = 0, j = tmp - i;
   while(i < j)
   {
       swap(nums, i, j);
       i++;
       j--;
   }
   i = tmp + 1, j = numsSize - i + tmp;
   while (i < j)
   {
       swap(nums, i, j);
       i++;
       j--;
   }
   i = 0, j = numsSize - i - 1;
   while(i < j)
   {
       swap(nums, i, j);
       i++;
       j--;
   }
}
void printf_array(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
    }
}
int main(void)
{
    int a[] = {1,2,3,4,5,6};
    rotate(a, 6, 3);
    printf_array(a, 6);

}