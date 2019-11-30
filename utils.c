#include "utils.h"

int intlen(int n)
{
    int len = 0;

    if(n < 0) n = -n;
    
    while(n > 0)
    {
        len++;
        n /= 10;
    }

    return len;
}

int tiny_strlen(const char *str)
{
    int len = 0;
    while(str[len] != '\0')
        len++;
    return len;
}
