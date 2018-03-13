#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap(int *nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// swap方法的思想就是 对于求nums中from 到to的全排列就是将from位固定，然后求nums中from
// from+1到to的全排列。from分别和from到to范围按顺序交换分别固定该位置然后继续求from+1到
// to的全排列。知道from 等于to时 只有一个数字的全排列。这时候可以nums交换顺序完成了。直接拷贝
// 到ret中的row所在的位置。row++
void perm(int *nums, int **ret, int numsSize, int from, int to, int *row)
{
    if(from == to)
    {
        memcpy(ret[*row], nums, numsSize * sizeof(int));
        (*row)++;
    }
    else
    {
        for(int j = from; j <= to; j++)
        {
            swap(nums, from, j);
            perm(nums, ret, numsSize, from + 1, to, row);
            swap(nums, j, from);
        }
    }
}

// returnsize 表示返回ret的数组数 实际上就是 numSize的阶乘
int** permute(int* nums, int numsSize, int* returnSize) {
    if(!numsSize) return NULL;
    *returnSize = 1;
    for(int i = 2; i <= numsSize; i++)
    {
        *returnSize *= i;
    }
    // 申请returnSize个指针的存储位置。
    // 然后每个ret里面的指针在指向一个长度为numsize的数组地址
    // 当然现在数组的值是随机的。 
    int **ret = (int **)malloc((*returnSize) * sizeof(int *));
    for(int j = 0; j < *returnSize; j++)
        ret[j] = (int *)malloc(numsSize * sizeof(int));
    // row 用来递增ret的index
    int row = 0; 
    perm(nums, ret, numsSize, 0, numsSize - 1, &row);
    return ret;
}

int main(void)
{
    int arr[] = {1,2,3};
    int retSize;
    int **ret = permute(arr, 3, &retSize);
    for (int i = 0; i < retSize; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", ret[i][j]);
        }
        free(ret[i]);
        printf("\n");
    }
    free(ret);
}