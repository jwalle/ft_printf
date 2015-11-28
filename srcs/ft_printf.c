/* == HEADER == */

#include "ft_printf.h"
#include <stdio.h> // PRINTF PLOPLPOPLPO

char *ft_strndup(char *str, int i)
{
	int		n;
	char	*ret;

	n = 0;
	if ((ret = (char *)malloc(sizeof(char) * i)) == NULL)
		return NULL;
	ret = ft_strncpy(ret, str, i);
	return (ret);
}

void	parse(const char *format, va_list list, t_arg *arg)
{
	int		i;
	int		n;

	i = 0;
	(void)list;
	while (ft_strchr(FLAGS, format[i]))
		i++;
	arg->flags = ft_strndup((char *)format, i);
	n = i++;
	while (ft_strchr(TYPE, format[i]))
		i++;
	arg->types = ft_strndup((char *)format + n, i);
	printf("FLAGS = %s, TYPE = %s\n", arg->flags, arg->types);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	t_arg	*arg;
	int		buffer;
	int 	i;

	i = 0;
	buffer = 0;
	arg = (t_arg*)malloc(sizeof(t_arg));
	va_start(list, format);
	buffer = ft_strlen(format);
	while (format[i])
	{
		if (ft_strchr(FLAGS, format[i]))
		{
			parse(&format[i], list, arg);
			//ft_putstr("plop");
			ft_putstr(va_arg(list, char*));
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (buffer);
}
