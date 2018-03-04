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
    int front, end, front_ret, end_ret;
    front = end = front_ret = end_ret = 0;
    int smallest_tmp = 0;
    int count_tmp = 0;
    int appear_count[256] = {0};
    char ch = *(str + end);
    std::deque<int> match_index;
    // when ch != '\0'
    while (ch)
    {
        if (member(match, ch))
        {
            // if ch first appear
            if (!appear_count[ch])  
            {
                // inc count_tmp
                count_tmp++;
                // if is the first in match, put front = end
                if (count_tmp == 1) front = end;
            }
            match_index.push_back(end);  // save match index in deque
            appear_count[ch]++; // inc match char appear count
            if (count_tmp >= mcount)
            {
            // if the front char appear more than one and all match chars had found
            // means front can move forward until which char appear_count == 1
                while (appear_count[*(str + front)] > 1)
                {
                    appear_count[*(str + front)]--;
                    match_index.pop_front();
                    front = match_index.front();
                }
                // replace smallest_tmp
                if (!smallest_tmp || end - front < smallest_tmp)
                {
                    smallest_tmp = end - front;
                    front_ret = front;
                    end_ret = end;
                }
            }
        }
        end++; // end always inc until reach the '\0' of str
        ch = *(str + end);
    }
    if(front_ret) // if find window
    {
        strncpy(buf, &str[front], end_ret - front_ret + 1);
        return buf;
    }
    else
        return NULL;
}
int main(void)
{
    const char src[] = "hello, erlang";
    const char match[] = "elo";
    char buf[20] = {0};
    char *ret = smallest_window(src, match, buf, 3);
    printf("%s\n", ret);

    return 0;
}