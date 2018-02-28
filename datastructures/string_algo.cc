#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <deque>

int member(const char *str, char ch)
{
    while(*str)
    {
        if(ch == *str)
        {
            return 1;
        }
        str++;
    }
    return 0;
}


// find the smallest window of str which contains all characters of match
char *smallest_window(const char *str, const char *match, char *buf, int mcount)
{
    int appear_count[256] = {0};
    int match_max = 0;
    std::deque<int> match_index;
    char c;
    int i = 0;
    while((c = *(str + i)))
    {
        if(member(match, c))
        {
            if(appear_count[c] == 0)
                match_max++;
            appear_count[c]++;
            match_index.push_back(i);
        }
        i++;
    }
    // can not find window contain all characters of match string
    if(match_max < mcount)
        return NULL;
    c = *(str + match_index.front());
    while(appear_count[c] > 1)
    {
        match_index.pop_front();
        appear_count[c]--;
        c = *(str + match_index.front());
    }
    
    c = *(str + match_index.back());
    while(appear_count[c] > 1)
    {
        match_index.pop_back();
        appear_count[c]--;
        c = *(str + match_index.back());
    }
    int front = match_index.front();
    int end = match_index.back();
    strncpy(buf, &str[front], end - front + 1);
    return buf;
}
int main(void)
{
    const char src[] = "hello, erlang";
    const char match[] = "el";
    char buf[20] = {0};
    char *ret = smallest_window(src, match, buf, 2);
    printf("%s\n", ret);

    return 0;
}