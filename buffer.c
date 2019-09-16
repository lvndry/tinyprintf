#include <stddef.h>
#include <stdio.h>

#include "buffer.h"
#include "utils.h"

void buffer_flush(char buffer[], unsigned int *size)
{
    if (buffer == NULL)
    {
        return;
    }

    buffer[*size] = '\0';
    fputs(buffer, stdout);
    *size = 0;
}

int buffer_write(char buffer[], char c, unsigned int *size)
{
    if(*size == BUFFER_SIZE)
    {
        buffer_flush(buffer, size);
    }

    buffer[*size] = c;
    *size += 1;
    return 1;
}

int buffer_write_int(char buffer[], int n, unsigned *size)
{
    int len = intlen(n);

    if ((*size + len) > BUFFER_SIZE)
    {
        buffer_flush(buffer, size);
    }

    if (n < 0)
    {
        buffer_write(buffer, '-', size);
        n = -n;
    }

    for (int i = len-1; i >= 0; i--)
    {
        buffer[(*size)+i] = (n%10) + 48;
        n /= 10;
    }

    *size += len;

    return 1;
}

int buffer_write_int_base(char buffer[], int n, int base, unsigned int *size)
{
    char *seba = "0123456789abcdef";
    int len = intlen(n);

    if (n < 0) {
        buffer_write(buffer, '-', size);
        n = -n;
    }

    if (n == 0)
    {
        buffer_write(buffer, '0', size);
        return 1;
    }


    for (int i = len - 1; i >= 0; i--)
    {
       int num = n%base;
       buffer[*(size)+i] = seba[num];
       n /= base;
    }

    *size += len;

    return 1;
}
