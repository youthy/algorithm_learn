#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int reverse(int x)
{
    int pos = 0;
    int min = 1 << 31;
    int max = ~(1 << 31);
    int reverse = x >= 0 ? 0 : 1;
    if(x == min) return 0;
    // if x == min then abs(x) will overflow
    int absx = abs(x);
    int tmp = 0;
    do
    {
        if(pos >= 9)
        {
            if (!reverse)
            {
                if (max / 10 < tmp ||
                    (max / 10 == tmp && max % 10 < absx % 10))
                    return 0;
            }
            else if (-(min / 10) < tmp ||
                     (-(min / 10) == tmp && -(min % 10) < absx % 10))
                return 0;
        }
        tmp = tmp * 10 + absx % 10;
        absx /= 10;
        if(tmp != 0) pos++;
    } while (absx);
    return reverse ? -tmp : tmp;
}

int reverse2(int x)
{
    long long tmp;
    do
    {
        tmp = tmp * 10 + x % 10;
        x /= 10;
    }while(x);
    if (tmp > INT_MAX || tmp < INT_MIN)
        return 0;
    return tmp;
}
int main(void)
{
    printf("%d\n", WINT_MIN);
    printf("%d\n", WINT_MAX);
    printf("%d\n", reverse(-2147483648));
    printf("%d\n", reverse2(-2147483648));
    return 0;
}