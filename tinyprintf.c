#include <stdio.h>
#include <stdarg.h>

#include "tinyprintf.h"

#define BUFFER_SIZE 128

void flush_buffer(char buffer[], unsigned int *size)
{
    if (buffer == NULL)
    {
        return;
    }

    buffer[(*size)] = '\0';
    fputs(buffer, stdout);
    *size = 0;
}

int tinyprintf(const char *format, ...) {
    va_list ap;
    char *string = NULL;
    char buffer[BUFFER_SIZE];
    unsigned int buffer_size = 0;
    int output_len = 0;

    va_start(ap, format);

    while(*format != '\0')
    {
        if (*format == '%')
        {
            flush_buffer(buffer, &buffer_size);

            format++;
            char control = *format;

            switch(control)
            {
                case 's':
                    string = va_arg(ap, char *);
                    fputs(string, stdout);
                    break;
                default:
                break;
            }
        }
        else
        {
            if (buffer_size == BUFFER_SIZE || *(format+1) == '\0')
            {
                flush_buffer(buffer, &buffer_size);
            }
            buffer[buffer_size++] = *format;
        }
        format++;
    }

    putchar('\n');

    va_end(ap);

    return output_len;
}

int main(void)
{
    tinyprintf("Hello %s it'working fine!", "landry");

    return 0;
}
