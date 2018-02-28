#include <stdio.h>
#include <string.h>

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

//********* remove dups
char *remove_dups(char *str)
{
    char map[256] = {0};
    int i = 0;
    int j = 0;
    while(*(str + j))
    {
        if(!map[*(str + j)])
        {
            *(str + i) = *(str + j);
            i++;
        }
        map[*(str + j)]++;
        j++;
    }
    *(str + i) = '\0';
    return str;
}

//********* split  string
void split_str(char *str, char *delimiter)
{
    char *token = strtok(str, delimiter);
    while(token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, delimiter);
    }
}

int main(void)
{
    char str[] = "El psy congroo!";
    //reverse(str);
    char sp[] = " !";
    reverse_except_sp(str, sp, sizeof(str)/sizeof(char));
    printf("%s", str);
    printf("%s", remove_dups(str));
    split_str(str, "o ");
    return 0;
}