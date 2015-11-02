/* == HEADER == */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		buffer;

	buffer = 0;
	va_start(list, format);
	ft_putstr(format);
	buffer = ft_strlen(format);
	return (buffer);
}
