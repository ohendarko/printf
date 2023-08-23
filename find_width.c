#include "main.h"
#include <stdarg.h>
/**
* find_width - Finds width
* @format: formatted string
* @i: parameter
* @listname: va_list name
* Return: width.
*/
int find_width(const char *format, int *i, va_list listname)
{
	int currenti;
	int width = 0;

	for (currenti = *i + 1; format[currenti] != '\0'; currenti++)
	{
		if (is_digit(format[currenti]))
		{
			width *= 10;
			width += format[currenti] - '0';
		}
		else if (format[currenti] == '*')
		{
			currenti++;
			width = va_arg(listname, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = currenti - 1;

	return (width);
}
