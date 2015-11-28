/* == HEADER == */

#include "ft_printf.h"
#include <stdio.h> // PRINTF PLOPLPOPLPO

void	init_spe(t_spe *spe)
{
	spe->str = NULL;
	spe->integer = 0;
	spe->u_integer = 0;
	spe->dble = 0;
	spe->character = 0;
	spe->pointer = NULL;
}

void	append_flag(t_arg *arg, t_spe *spe)
{
	int	i;

	i  = 0;
	if (strchr(arg->flags, '-'))
	{
		if (spe->str)
			i = ft_strlen(spe->str);
		while (i++ < arg->width)
			ft_putchar(' ');
	}
}

void	parse_specifier(char *str, t_spe *spe, va_list list)
{
	if (str[0] == 's')
		spe->str = ft_strdup(va_arg(list, char*));
	else if (str[0] == 'd')
		spe->integer = ft_atoi(va_arg(list, char*));
}

void	parse_args(t_arg *arg, va_list list, t_spe *spe)
{
	init_spe(spe);
	(void)list;
	parse_specifier(arg->specifier, spe, list);
	if (arg->flags)
		append_flag(arg, spe);
	if (spe->str)
		ft_putstr(spe->str);
	else if (spe->integer)
		ft_putnbr(spe->integer);
}

void	init_arg(t_arg *arg)
{

	arg->flags = NULL;
	arg->width = 0;
	arg->precision = 0;
	arg->length = NULL;
	arg->specifier = NULL;
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	t_arg	*arg;
	t_spe	*spe;
	int		buffer;
	int 	i;

	i = 0;
	buffer = 0;
	arg = (t_arg*)malloc(sizeof(t_arg));
	spe = (t_spe*)malloc(sizeof(t_spe));
	va_start(list, format);
	buffer = ft_strlen(format);
	while (format[i])
	{
		init_arg(arg);
		if (format[i] == '%')
		{
			i += parse(&format[i] + 1, arg);
			parse_args(arg, list, spe);
		}
		else
			ft_putchar(format[i++]);
	}
	va_end(list);
	return (buffer);
}
