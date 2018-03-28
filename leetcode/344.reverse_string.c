#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s)
{
    int len = strlen(s);
    int i = 0, j = len - 1;
    char tmp;
    while(i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
    return s;
}
int main(void)
{
    char s[] = "hello";
    reverseString(s);
}