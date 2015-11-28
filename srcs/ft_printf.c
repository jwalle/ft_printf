/* == HEADER == */

#include "ft_printf.h"

/*void parse(va_list list)
{

}*/

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		buffer;

	buffer = 0;
	va_start(list, format);
	//parse(list);
	if (!ft_strcmp(format, "%s\n"))
	{
		// ft_putstr("plop");
		ft_putstr(va_arg(list, char*));
	}
	buffer = ft_strlen(format);
	va_end(list);
	return (buffer);
}
