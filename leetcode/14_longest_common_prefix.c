#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    char *ret = NULL;
    char tmp = 0;
    int p = 0;
    int stop = 0;
    if(strsSize == 0) stop = 1;
    while(!stop)
    {
        for (int i = 0; i < strsSize; i++)
        {
            if (i == 0) 
            {
                if(!(tmp = *(strs[i] + p)))
                {
                    stop = 1;
                    break;
                }
            }
            else if (*(strs[i] + p) != tmp)
                {
                    stop = 1;
                    break;
                }
        }
        if(!stop) p++;
    }
    if(p)
    {
        ret = (char *)malloc(sizeof(char) * (p + 1));
        int j;
        for(j = 0; j < p; j++)
            ret[j] = *(strs[0] + j);
        ret[j] = '\0';
    }
    else
    {
        ret = (char *)malloc(sizeof(char));
        ret[0] = '\0';
    }
    return ret;
}

int main(void)
{
    char *strs[] = {"aabb", "aa", "ab"};
    char *strs1[] = {};
    printf("%s\n", longestCommonPrefix(strs, 3));
    printf("%s\n", longestCommonPrefix(strs1, 0));
}