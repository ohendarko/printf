#include "main.h"
#include <stdarg.h>
/**
* find_precision - find the precision for printing
* @format: formatted string
* @i: list of arguments to be printed.
* @listname: va_list name.
* Return: precision.
*/
int find_precision(const char *format, int *i, va_list listname)
{
	int currenti = *i + 1;
	int precision = -1;

	if (format[currenti] != '.')
	{
		return (precision);
	}
	precision = 0;

	for (currenti += 1; format[currenti] != '\0'; currenti++)
	{
		if (is_digit(format[currenti]))
		{
			precision *= 10;
			precision += format[currenti] - '0';
		}
		else if (format[currenti] == '*')
		{
			currenti++;
			precision = va_arg(listname, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = currenti - 1;

	return (precision);
}
