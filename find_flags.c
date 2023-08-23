#include "main.h"
/**
* find_flags - find active flags
* @format: formatted string
* @i: parameter.
* Return: flags
*/
int find_flags(const char *format, int *i)
{
	int j, currenti;
	int flags = 0;
	const char FLAGS_A[] = {'+', '-', '0', ' ', '#', '\0'};
	const int FLAGS_B[] = {PLUS, MINUS, ZERO, SPACE, HASH, 0};

	for (currenti = *i + 1; format[currenti] != '\0'; currenti++)
	{
		for (j = 0; FLAGS_A[j] != '\0'; j++)
		{
			if (format[currenti] == FLAGS_A[j])
			{
				flags |= FLAGS_B[j];
				break;
			}
		}
		if (FLAGS_B[j] == 0)
		{
			break;
		}
	}

	*i = currenti - 1;

	return (flags);
}
