#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isMatch(const char *s, const char *p)
{
    if(!*p) return !*s;
    if(*(p + 1) == '*')
    {
        if(isMatch(s, p + 2)) return true;
        else
        {
            return ((*p == '.' && *s) || *p == *s) && isMatch(s+1, p);
        }
    }
    return ((*p == '.' && *s) || *p == *s) && isMatch(s + 1, p + 1);
}

int main(void)
{
    //printf("%d\n", isMatch("aa", ".*"));
    //printf("%d\n", isMatch("aa", "aa"));
    printf("%d\n", isMatch("aaa", "ab*a*c*a"));
    printf("%d\n", isMatch("a", "ab*"));
    printf("%d\n", isMatch("bbbba", ".*a*a"));
    printf("%d\n", isMatch("aaa", "ab*a*c*a"));
    printf("%d\n", isMatch("a", "ab*"));
    printf("%d\n", isMatch("bbbba", ".*a*a"));
    printf("%d\n", isMatch("ab", ".*.."));
    printf("%d\n", isMatch("aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s"));
    //printf("%d\n", isMatch("aa", "aaa"));
    //printf("%d\n", isMatch("aa", "a*"));
}