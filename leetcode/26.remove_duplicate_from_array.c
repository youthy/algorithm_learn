#include <stdlib.h>
#include <stdio.h>

// 如果是有序的则移除排序的部分。目前看提交结果 移去排序是beat 100%的解决方案
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int removeDuplicates(int* nums, int numsSize) {
    if(numsSize < 2) return numsSize;
    qsort(nums, numsSize, sizeof(int), cmp);
    int pos = 0, next = 1;
    while(next < numsSize)
    {
        if(nums[next] == nums[pos])
            next++;
        else
        {
            nums[++pos] = nums[next++];
        }
    }
    return pos+1;
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
    int a[] = {1,1,2};
    int newsize = removeDuplicates(a, 3);
    printf_array(a, newsize);
}