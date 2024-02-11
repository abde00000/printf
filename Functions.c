#include "main.h"
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

