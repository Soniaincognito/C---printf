#include "main.h"

/**
 * struct fmt_type - Struct to represent a format type
 * @fmt: The format specifier
 * @fn: The corresponding printing function
 */
typedef struct fmt_type
{
	char fmt;
	int (*fn)(va_list, char *, int, int, int, int);
} fmt_t;

/**
 * print_char - Function to print a character
 * @list: Argument list
 * @buffer: Buffer to store the printed string
 * @flags: Printing flags
 * @width: Printing width
 * @precision: Printing precision
 * @size: Printing size
 * Return: Number of characters printed
 */
int print_char(va_list list, char *buffer, int flags, int width, int precision, int size)
{
	/* Implementation for printing a character */
	/* Modify as needed */
	return (0);
}

/* Define other print functions similarly */

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @ind: Index in the format string
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: Get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
				 int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	/* Iterate through fmt_types array */
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		/* Check if fmt matches the current format type */
		if (fmt[*ind] == fmt_types[i].fmt)
		{
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
		}
	}

	/* If fmt is not found in fmt_types array */
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);

		/* Print '%' character */
		unknow_len += write(1, "%", 1);

		/* Check if previous character is space */
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			/* Decrease index to check for width */
			--(*ind);
			/* Move back until space or '%' is found */
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);

			/* If space is found, move back one more */
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}

		/* Print current character */
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}

	return (printed_chars);
}
