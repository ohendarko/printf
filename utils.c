#include "main.h "
/**
* append_hexa_code - Append ascci in hexadecimal
* @buffer: Array
* @i: Index at which to start appending.
* @ascii_code: ASCCI CODE.
* Return: Always 3 and nothing
*/
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}
/**
* is_printable - Evaluates
* @c: character to evaluate.
* Return: 1 if c is printable, 0 otherwise
*/
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
* is_digit - Verifies if char is digit
* @c: Character to be evaluated
* Return: 1 if c is a digit, 0 otherwise
*/
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
* convert_size_number - Cast number to specified size
* @num: Number to cast.
* @size: Number indicating type to be casted.
* Return: Casted value of num
*/
long int convert_size_number(long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((short)num);

	return ((int)num);
}

/**
* convert_size_unsgnd - Casts a number to the specified size
* @num: Number to be casted
* @size: Number indicating the type to be casted
*
* Return: casted value of num
*/
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);

}
