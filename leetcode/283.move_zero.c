/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
#include <stdlib.h>
#include <stdio.h>

void swap(int nums[], int n, int m)
{
    int tmp = nums[n];
    nums[n] = nums[m];
    nums[m] = tmp;
}

// beats 100% 的方案。 想象 从第一个0开始类似冒泡。0与下一个非0交换位置，知道遇到下一个0这时把这两个看为一体
// 把连续0的第一个与下一个非0交换。一直下去。只用遍历一次。
void moveZeroes(int* nums, int numsSize) {
    int zero_start = 0, not_zero_pos = 0;
    while(not_zero_pos < numsSize)
    {
        if(nums[not_zero_pos] == 0 && nums[zero_start] != 0) zero_start = not_zero_pos;
        else if(nums[not_zero_pos] != 0 && nums[zero_start] == 0)
        {
            swap(nums, zero_start, not_zero_pos);
            zero_start++;
        }
        not_zero_pos++;
    }
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
}

int main(void)
{
    int a[] = {0, 1,2,3,0,4};
    moveZeroes(a, 6);
    printArray(a, 6);
}