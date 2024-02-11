#include "main.h"
/**
 * _printf - functions as printf
 * @format: specifiers
 * Return:  the number of characters print
 * (excluding the null byte used to end output to stringsi)
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list arg;
    char buffer[1024];
    if (format == NULL)
        return (-1);
    va_start(arg, format);
    while (*format)
    {
        if (*format == '%' && format[1])
        {
        format++;
        if (*format == 'c')
            count += _putchar(va_arg(args, int));
        else if (*format == 's')
            count += handle_string(va_arg(args, char *));
        else if (*format == 'i' || *format == 'd')
        {
            _sprintf(buffer, "%d", va_arg(args, int));
            count += handle_string(buffer);
        }
        else if (*format == '%')
            count += _putchar('%');
        else
        {
            count += _putchar('%');
            count += _putchar(*format);
        }
        }
            else if (*format == '%' && format[1] == '\0')
        {
            return (-1);
        }
        else
            count += _putchar(*format);
        format++;
    }
va_end(args);
return (count);
}
