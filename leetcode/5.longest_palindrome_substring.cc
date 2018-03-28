#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* longestPalindrome(char* s) 
{
    int idx, p_left, p_right, start, end;
    idx = p_left = p_right = start = end = 0;
    while(*(s + idx))
    {
        // 只对多于一个字符的做计算。一个字符本身就是回文。end = start = 0的时候默认就是返回*s
        // 的第一个字符
        if(idx >= 1)
        {
            // 如果idx右边存在且等于idx左边
            if(*(s + idx + 1) && *(s + idx + 1) == *(s + idx - 1))
            {
                p_right = idx + 1;
                p_left = idx - 1;
                // p_right 没有到达右界 p_left没有到达左界且对应字符还相等
                while (*(s + p_right) && p_left >= 0 && *(s + p_right) == *(s + p_left))
                {
                    p_right++;
                    p_left--;
                }
                //长度比记录的长度长 更新
                if (p_right - p_left - 2 > end - start)
                {
                    end = p_right - 1;
                    start = p_left + 1;
                }
            }
            // 左边等于字符本身 注意这种情况并不与上面互斥，如果使用else if "aaaa" 这种
            // 字符串上面只能得到"aaa"这种结果
            if (*(s + idx) == *(s + idx - 1))
            {
                p_right = idx;
                p_left = idx - 1;
                while (*(s + p_right) && p_left >= 0 && *(s + p_right) == *(s + p_left))
                {
                    p_right++;
                    p_left--;
                }
                if (p_right - p_left - 2 > end - start)
                {
                    end = p_right - 1;
                    start = p_left + 1;
                }
            }
        }
        idx++;
    }
    char *ret = (char *)malloc(sizeof(char) * (end - start + 2));
    for (int i = start; i <= end; i++)
        *(ret + i - start) = *(s + i);
    *(ret + end - start + 1) = '\0';
    return ret;
}

char* longestPalindromeDp(char* s) 
{
    int len = strlen(s);
    bool map[len][len];
    memset(map, 0, sizeof(map));
    for(int i = 0;i < len;i++)
        map[i][i] = true;
}

int main(void)
{
    char s[] = "bbb";
    char *sub = longestPalindrome(s);
    printf("%s", sub);
    if(sub) free(sub);
}