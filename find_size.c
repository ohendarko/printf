#include "main.h"
#include <stdarg.h>
/**
* find_size - Calculates the size to cast the argument
* @format: Formatted string in which to print the arguments
* @i: List of arguments to be printed.
*
* Return: Precision.
*/
int find_size(const char *format, int *i)
{
	int currenti = *i + 1;
	int size = 0;

	if (format[currenti] == 'l')
	{
		size = LONG;
	}
	else if (format[currenti] == 'h')
	{
		size = SHORT;
	}

	if (size == 0)
	{
		*i = currenti - 1;
	}
	else
	{
		*i = currenti;
	}

	return (size);
}
