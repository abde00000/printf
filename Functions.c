#include "main.h"
/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 *
 * Return: On success, 1. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * handle_string - Prints a string to stdout
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int handle_string(char *str)
{
int i = 0;
if (str == NULL)
{
str = "(null)";
}
while (str[i])
{
_putchar(str[i]);
i++;
}
return (i);
}
/**
 * handle_int - prints int
 * @num: the number to be printed
 * Return: counts
 */
int handle_int(int num)
{
int count = 0;
int digit;
if (num < 0)
{
_putchar('-');
count++;
num = -num;
}
if (num == 0)
{
_putchar('0');
count++;
}
else
{
int rev = 0;
while (num > 0)
{
digit = num % 10;
rev = rev * 10 + digit;
num /= 10;
}
while (rev > 0)
{
_putchar(rev % 10 + '0');
count++;
rev /= 10;
}
}
return (count);
}
/**
 * _sprintf - formats a string into a buffer
 * @buffer: the buffer to store the formatted string
 * @format: the format string
 * @...: additional arguments for formatting
 * Return: the number of characters formatted
 */
int _sprintf(char *buffer, const char *format, ...)
{
va_list args;
int count;
va_start(args, format);
count = vsprintf(buffer, format, args);
va_end(args);
return (count);
}
