#include <stdlib.h>
#include <stdio.h>

int lengthOfLongestSubstring(char *s)
{
    int start, end, max;
    if(s == NULL) return 0;
    int index[256];
    for(int i = 0; i < 256; i++) index[i] = -1;
    start = end = max = 0;
    char ch = *(s + end);
    while(ch)
    {
        if(index[ch] != -1)
        {
            max = max > end - start ? max : end - start;
            int i = start;
            start = index[ch] + 1;
            // set the chars between start and ch's last index to -1
            for(; i < index[ch]; i++)
                index[*(s + i)] = -1;
        }
        index[ch] = end;
        end++;
        ch = *(s + end);
    }
    // end points to '\0' don't end - start + ;
    // if the last substring are all different, it won't update the max
    // so returm bigger of max and end - start
    return max > end - start ? max : end - start;
}
int main(void)
{
    char s[] = "dvdf";
    printf("%d", lengthOfLongestSubstring(s));
}