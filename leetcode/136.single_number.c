#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int singleNumber(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0; i < numsSize; i+=2)
    {
        if(nums[i] != nums[i + 1])
            return nums[i];
    }
    return -1;
}

int main(void)
{
    int a[] = {1,1,4,2,3,4,3};
    int ret = singleNumber(a, sizeof(a)/sizeof(int));
    printf("%d", ret);
}