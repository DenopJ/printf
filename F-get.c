#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: first parameter
 * @i: second parameter
 * @list: list of arguments.
 *
 * Return: Always 0 (Success)
 */
int get_precision(const char *format, int *i, va_list list)
{
	int x = *i + 1;
	int prec = -1;

	if (format[x] != '.')
		return (prec);

	prec = 0;

	for (x += 1; format[x] != '\0'; x++)
	{
		if (is_digit(format[x]))
		{
			prec *= 10;
			prec += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = x - 1;

	return (prec);
}
