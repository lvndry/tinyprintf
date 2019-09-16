#include <stdio.h>
#include <stdarg.h>

#include "tinyprintf.h"
#include "utils.h"
#include "buffer.h"

int tinyprintf(const char *format, ...)
{
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
                       output_len += buffer_write(buffer, string[i], &buffer_size);
                    }
                    break;
                case 'c':
                    letter = va_arg(ap, int);
                    buffer_write(buffer, letter, &buffer_size);
                    output_len += 1;
                break;
                case 'd':
                    sint = va_arg(ap, int);
                    output_len += buffer_write_int(buffer, sint, &buffer_size);
                break;
                case 'u':
                    uint = va_arg(ap, unsigned);
                    output_len += buffer_write_int(buffer, uint, &buffer_size);
                break;
                case 'o':
                    uint = va_arg(ap, unsigned);
                    output_len += buffer_write_int_base(buffer, uint, 8, &buffer_size);
                break;
                case 'x':
                    uint = va_arg(ap, unsigned);
                    output_len += buffer_write_int_base(buffer, uint, 16, &buffer_size);
                break;
                case '%':
                    buffer_write(buffer, '%', &buffer_size);
                    output_len += 1;
                break;
                default:
                    buffer_write(buffer, '%', &buffer_size);
                    buffer_write(buffer, control, &buffer_size);
                    output_len += 2;
                break;
            }
        }
        else
        {
            output_len += buffer_write(buffer, *format, &buffer_size);
        }
        format++;
    }

    va_end(ap);

    buffer_flush(buffer, &buffer_size);
    putchar('\n');

    return output_len;
}
