#include "main.h"
#include <stdlib.h>
/**
 * print_c - Writes a character to stdout
 * @c: The character to write
 *
 * Return: On success, 1. On error, -1 is returned.
 */
int print_c(char c)
{
	return (write(1, &c, 1));
}
int print_b(int arg)
{
	int count = 0, i = 0, j, len = 0;
	char buff[32];
	if (arg == 0)
		count += print_c('0');
	while (arg > 0)
	{
		buff[i] = (arg % 2) + '0';
		arg /= 2;
		i++;
	}
	len = strlen(buff);
	for (j = 0; j < len / 2; j++)
	{
		char tmp = buff[j];
		buff[j] = buff[len - j - 1];
		buff[len - j - 1] = tmp;
	}
	count += print_s(buff);

	return count;
}
int print_s(char *str)
{
	int count = 0;
	if (str == NULL)
	{
		count += print_s("(null)\n");
	}
	while (*str)
	{
		count += print_c(*str);
		str++;
	}
	return count;
}
int print_dig(long arg, int base)
{
	int count = 0;
	char *sym;
	sym = "0123456789abcdef";

	if (arg < 0)
	{
		count += print_c('-');
		return print_dig(-arg, base);
	}
	else if (arg < base)
	{
		return print_c(sym[arg]);
	}
	else
	{
		count += print_dig(arg / base, base);
		return count + print_dig(arg % base, base);
	}
	return count;
}

