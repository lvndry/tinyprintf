#include <stdio.h>
#include <stdarg.h>

#include "tinyprintf.h"

#define BUFFER_SIZE 128

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

int tiny_strlen(const char *str)
{
    int len = 0;

    while(str[len] != '\0')
    {
        len++;
    }

    return len;
}

char* tiny_itoa(int n, char *str)
{
    int len = intlen(n);
    int num;
    int index = len;

    if (n == 0) return "0";

    while(n > 0)
    {
       num = n%10;
       str[index-1] = num;
       n /= 10;
       index--;
    }

    return str;
}

int tinyprintf(const char *format, ...) {
    va_list ap;
    char *string = NULL;
    char letter;
    int sint;
    unsigned uint;
    char buffer[BUFFER_SIZE];
    unsigned int buffer_size = 0;
    int output_len = 0;

    va_start(ap, format);

    while(*format != '\0')
    {
        if (*format == '%')
        {
            buffer_flush(buffer, &buffer_size);

            format++;
            char control = *format;

            switch(control)
            {
                case 's':
                    string = va_arg(ap, char *);
                    for (int i = 0; i < tiny_strlen(string); i++)
                    {
                        buffer_write(buffer, string[i], &buffer_size);
                    }
                    break;
                case 'c':
                    letter = va_arg(ap, int);
                    buffer_write(buffer, letter, &buffer_size);
                break;
                case 'd':
                    sint = va_arg(ap, int);
                    buffer_write_int(buffer, sint, &buffer_size);
                break;
                case 'u':
                    uint = va_arg(ap, unsigned);
                    buffer_write_int(buffer, uint, &buffer_size);
                break;
                default:
                    buffer_write(buffer, '%', &buffer_size);
                    buffer_write(buffer, control, &buffer_size);
                break;
            }
        }
        else
        {
            buffer_write(buffer, *format, &buffer_size);
        }
        format++;
    }

    va_end(ap);

    buffer_flush(buffer, &buffer_size);
    putchar('\n');

    return output_len;
}

int main(void)
{
    tinyprintf("Hello %s it'working fine! %d is a signed int and %u unsigned", "landry", -15, 2);

    return 0;
}
