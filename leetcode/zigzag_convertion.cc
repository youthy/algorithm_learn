#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *convert(char *s, int numRows)
{
    char *ret = NULL;
    int len = strlen(s);
    int idx = 0;
    int left, right;
    ret = (char *)malloc(sizeof(char) * (len + 1));
    if(numRows == 1) 
    {
        strcpy(ret, s);
        return ret;
    }
    // 蛇形第一行在原字符串中的索引是0, 2*1(numRow - 1), 2*2(numRows - 1)...2*q(numRows - 1)
    // 第n行是尤上面第一行每个元素发展的左右子树left = 2*q(numRows - 1) - (n - 1)
    // right = 2*q(numRows - 1) + (n - 1),
    // 第一行相当于每个元素的左右索引是一样的，最后一样相当于左索引等于上一个元素的右索引。所以需要去重。
    // 第一行元素最后一个取可以大于len的元素。然后只要判断左右索引都在len以内，省去特殊处理。
    // 值得注意的是这种方式要求numRows > 1 否则第一行元素永远为0，leetcode第一次提交没注意
    // 导致无限循环 time limit exceed了
    for(int i = 1; i <= numRows; i++)
    {
        int j, q;
        // j 相当于第一行的元素索引 最后一个可以大于len 因为存在下面这种情况
        //   0     4
        //   1  3  5  7 
        //   2     6
        // 如果之取到4会忽略7.
        for(j = 0, q = 1; j < len + 2 * (numRows - 1); j = 2 * q * (numRows - 1), q++)
        {
            left = j - (i - 1); //左索引
            right = j + (i - 1); // 右索引
            // 对左索引做不等于上一个元素的右索引判断 用于最后一行
            if (left >= 0 && left != j - 2 * (numRows - 1) + (i - 1) && left < len)
            {
                ret[idx] = s[left];
                idx++;
            }
            // 对右元素做不等于左元素的判断 主要用于第一行
            if(right < len && right != left)
            {
                ret[idx] = s[right];
                idx++;
            }
            
        }
    }
    ret[idx] = '\0';
    return ret;
}

int main(void)
{
    char a[] = "h";
    char *s = convert(a, 1);
    printf("%s", s);
    free(s);
}