#include "main.h"
int print_f(char spec, va_list arg)
{
	int count = 0;
	switch (spec)
	{
		case 'c':
			count += print_c(va_arg(arg, int));
			break;
		case 's':
			count += print_s(va_arg(arg, char *));
			break;
		case 'i':
		case 'd':
			count += print_dig((long)(va_arg(arg, int)), 10);
			break;
		case 'x':
			count += print_dig((long)(va_arg(arg, unsigned int)), 16);
			break;
		default:
			count += print_c(spec);
			break;
	}
	return count;
}
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
    
    va_start(arg, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            count += print_f(*format, arg);
        }
        else
        {
            count += print_c(*format);
        }
        format++;
    }
    va_end(arg);
    return count;
}

