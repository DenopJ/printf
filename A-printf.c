#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function produces output according to format
 * @format: format
 *
 * Return: Always 0 (Success)
 */

int _printf(const char *format, ...)
{
	int i, prt = 0, prt_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			prt_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			prt = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (prt == -1)
				return (-1);
			prt_char += prt;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (prt_char);
}

/**
 * print_buffer - Prints the contents of buffer if it exist
 * @buffer: first parameter
 * @buff_ind: second parameter
 *
 * Return: void
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
