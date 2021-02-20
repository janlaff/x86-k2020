#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <stdarg.h>

static int print(const char *data, size_t length)
{
    const unsigned char *bytes = (const unsigned char *)data;
    for (size_t i = 0; i < length; i++)
        if (putchar(bytes[i]) == -1)
            return 0;
    return 1;
}

int printf(const char *format, ...)
{
    va_list parameters;
    va_start(parameters, format);
    
    int written = 0;
    int index = 0;
    while (format[index] != '\0') {
        if (format[index] == '%' && format[index + 1] == 's')
        {
            const char *str = va_arg(parameters, const char *);
            size_t len = strlen(str);
            print(str, len);
            written += len;
            index++;
        }
        else if (format[index] == '%' && format[index + 1] == 'd')
        {
            char buf[32];
            int arg = va_arg(parameters, int);
            char *str = itoa(arg, buf, 10);
            size_t len = strlen(str);
            print(str, len);
            written += len;
            index++;
        }
        else if (format[index] == '%' && format[index + 1] == 'x')
        {
            char buf[32];
            int arg = va_arg(parameters, int);
            char *str = itoa(arg, buf, 16);
            size_t len = strlen(str);
            print(str, len);
            written += len;
            index++;
        }
        else
        {
            putchar(format[index]);
            written++;
        }
        index++;
    }
    return written;
}