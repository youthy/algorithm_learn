#include <stdio.h>

// util
int member(char chr, char *str)
{
    while(*str)
    {
        if(*str == chr) return 1;

        str++;
    }
    return 0;
}

void swap(char *str, int i, int j)
{
    char tmp = *(str + i);
    *(str + i) = *(str + j);
    *(str + j) = tmp;
}
//********* print reverse of string
void reverse(char *str)
{   
    // end of str is 0
    if(*str)
    {
        reverse(str + 1);
        printf("%c", *str);
    }
}

//********* print reverse of string with special chracters stay
void reverse_except_sp(char *str, char *sp, int n)
{
    printf("add:%X", str);
    int l = 0;
    // ignore '\0'
    int r = n - 2;
    while(l < r)
    {
        if (member(*(str + l), sp))
            l++;
        else if (member(*(str + r), sp))
            r--;
        else
        {
            swap(str, l, r);
            l++;
            r--;
        }
    }
}
int main(void)
{
    char str[] = "El psy congroo!";
    //reverse(str);
    char sp[] = " !";
    printf("add0:%X", &str);
    reverse_except_sp(str, sp, sizeof(str)/sizeof(char));
    printf("%s", str);
    return 0;
}