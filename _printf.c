
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
<<<<<<< HEAD
  *_printf - A printf function that takes in agument
  *@format: an argument that takes char
  *Return: A return value of a printed chars
  */

int _printf(const char *format, ...)
{
	int i;
	int lenght = 0;
	int x;
	int value;
	va_list list;

	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			_putchar(va_arg(list, int));
			i++;
		}

		else if (format[i + 1] == 's')
		{
			x = string(va_arg(list, char *));
			i++;
			lenght += (x - 1);
=======
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
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
			/* write(1, &format[i], 1);*/
                           printed_chars++;
>>>>>>> 404fb238f9e35960c52308f910922b4aba9010ae
		}
		else if (format[i + 1] == '%')
		{
<<<<<<< HEAD
			_putchar('%');
			i++;
=======
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
>>>>>>> 404fb238f9e35960c52308f910922b4aba9010ae
		}
		else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			value = integer_print(va_arg(list, int));
			i++;
			lenght += (value - 1);
		}
	lenght++;
	}
<<<<<<< HEAD
	va_end(list);
	return (lenght);
}

=======

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}



>>>>>>> 404fb238f9e35960c52308f910922b4aba9010ae
