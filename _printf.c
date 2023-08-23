#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdeff.h>
void print_inbuffer(char buffer[], int *buffindex);
/**
* print_inbuffer - print what is in buffer
* @buffer: array
* @buffindex: index position
*/
void print_inbuffer(char buffer[], int *buffindex)
{
	if (*buffindex > 0)
	{
		write(1, &buffer[0], *buffindex);
	}
	*buffindex = 0;
}
/**
* _printf - main function
* @format: format string
* Return: printed x'ters
*/
int _printf(const char *format, ...)
{
	int i;
	int total_printed = 0;
	int printed = 0;
	int flags, width, size, precision;
	int buffindex = 0;

	va_list listname;
	char buffer[BUFFERSIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(listname, format);

	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffindex++] = format[i];
			if (buffindex == BUFFERSIZE)
			{
				print_inbuffer(buffer, &buffindex);
			}
			total_printed++;
		}
		else
		{
			print_inbuffer(buffer, &buffindex);
			flags = find_flags(format, &i);
			width = find_width(format, &i, listname);
			precision = find_precision(format, &i, listname);
			size = find_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
			{
				return (-1);
			}
			total_printed += printed;
		}
	}
	print_inbuffer(buffer, &buffindex);
	va_end(listname);
	return (total_printed);
}
