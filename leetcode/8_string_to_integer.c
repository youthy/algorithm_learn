#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int myAtoi(char *s)
{
    long long tmp = 0;
    int i = 0;
    int flag = 0;
    int pos = 0;
    char ch;
    // pos for not overflow tmp
    while((ch = *(s + i)) && pos <= 11)
    {
        // 符号位只有在flag还没定义 且tmp为0时有效 否则break 45 = '-' 43='+'
        if(ch == 45) if(!tmp && !flag) flag = -1;else break;
        else if(ch == 43) if(!tmp && !flag) flag = 1;else break;
        // 0 ~ 9
        else if(48 <= ch && ch <= 57)
        {
            tmp = tmp * 10 + ch % 48;
            pos++;
        }
        // 非空白符直接break 空白符只有在tmp和flag均为0时有效
        else if(!isspace(ch) || (isspace(ch) && (tmp || flag))) break;
        i++;
    }
    if (tmp)
    {
        if(flag) tmp = flag * tmp;
        return tmp > INT_MAX ? INT_MAX:(tmp < INT_MIN ? INT_MIN : tmp);
    }
    return 0;
}

int main(void)
{
    printf("%d", myAtoi("9223372036854775809"));
    printf("%d", myAtoi("+-2"));
    printf("%d", myAtoi("-2213"));
}