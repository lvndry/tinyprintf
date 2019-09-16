#include <stdio.h>
#include <stdarg.h>

#include "tinyprintf.h"

#define BUFFER_SIZE 128

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

int tinyprintf(const char *format, ...) {
    va_list ap;
    char *string = NULL;
    char letter;
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
                    fputs(string, stdout);
                    break;
                case 'c':
                    letter = va_arg(ap, int);
                    putchar(letter);
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
    tinyprintf("Hello %s it'working fine!", "landry");

    return 0;
}
