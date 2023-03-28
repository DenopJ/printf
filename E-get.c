#include "main.h"

/**
 * get_size - Function calculates size to cast the argument
 * @format: First parameter
 * @i: Second parameter
 *
 * Return: Always 0 (Success)
 */

int get_size(const char *format, int *i)
{
	int x = *i + 1;
	int y = 0;

	if (format[x] == 'l')
		y = S_LONG;
	else if (format[x] == 'h')
		y = S_SHORT;

	if (y == 0)
		*i = x - 1;
	else
		*i = x;

	return (y);
}
