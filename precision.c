#include "main.h"
#include <ctype.h>

/**
 * is_digit - Check if a character is a digit.
 * @c: The character to check.
 * Return: 1 if it's a digit, 0 otherwise.
 */
int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments.
 * @i: Index in the format string.
 * @list: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
<<<<<<< HEAD
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
=======
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return (precision);

    precision = 0;

    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *i = curr_i - 1;

    return (precision);
>>>>>>> 404fb238f9e35960c52308f910922b4aba9010ae
}


