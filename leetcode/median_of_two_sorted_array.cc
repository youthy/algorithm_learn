#include <stdio.h>
#include <stdlib.h>

// find median of two sorted arrays
// take care of '/' method I forgot 3/2 = 1 not 1.5  should return tmp1 + tmp2/2.0
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int index1, index2, acc, tmp1, tmp2;
    index1 = index2 = acc = tmp1 = tmp2 = 0;
    if(nums1Size == 0 && nums2Size == 0) return 0;
    double median_index = (nums1Size + nums2Size + 1)/2.0;
    while (1)
    {
        tmp2 = tmp1;
        if (index1 < nums1Size && index2 < nums2Size)
        {
            if (nums1[index1] <= nums2[index2])
            {
                tmp1 = nums1[index1];
                index1++;
            }
            else
            {
                tmp1 = nums2[index2];
                index2++;
            }
        }
        else if(index1 < nums1Size)
        {
            tmp1 = nums1[index1];
            index1++;
        }
        else 
        {
            tmp1 = nums2[index2];
            index2++;
        }
        acc++;
        // 如果已排序数量等于中位数的index 就只返回一个数
        // 否则 返回两个数和的一半
        if(acc == median_index) return tmp1;
        if(acc > median_index) return (tmp1 + tmp2)/2.0;
    }
}

int main(void)
{
    int a[] = {1, 1, 1};
    int b[] = {2, 3};
    printf("%f", findMedianSortedArrays(a, 3, b, 2));
}