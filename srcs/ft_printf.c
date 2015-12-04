/* == HEADER == */

#include "ft_printf.h"
#include <stdio.h> // PRINTF PLOPLPOPLPO

void	parse_specifier(char specifier, t_arg *arg, va_list list)
{
	if (specifier == 'd' || specifier == 'i' || specifier == 'D')
		arg_is_int(arg, list);
	else if (specifier == 'u' || specifier == 'U' || specifier == 'o'
		|| specifier == 'O' || specifier == 'x' || specifier == 'X')
		arg_is_u(arg, list);
	else if (specifier == 'c')
		arg_is_c(arg, list);
	else if (specifier == 's' || specifier == 'S') // wchar_t ?
		arg_is_string(arg, list);
	else if (specifier == 'p')
		arg_is_p(arg, list);
	else if (specifier == '%')
		ft_putchar('%');
}

void		parse_number(long long number, char spe)
{
	if (spe == 'o')
	{
		ft_putnbr_octal(number);
		return ;
	}
	else if (spe == 'x' || spe == 'X')
	{
		ft_putnbr_hexa(number, spe);
		return ;
	}
	ft_putllunbr(number);
}

void	parse_args(t_arg *arg, va_list list)
{
	parse_specifier(arg->specifier, arg, list);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	t_arg	*arg;
	int 	i;

    if (!format)
        return (-1);
	i = 0;
	arg = (t_arg*)malloc(sizeof(t_arg));
	arg->flags = (t_flags*)malloc(sizeof(t_flags));
	arg->length = (t_length*)malloc(sizeof(t_length));
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			init_arg(arg);
			i += 1 + parse(&format[i] + 1, arg);
			parse_args(arg, list);
		}
		else
			ft_putchar(format[i++]);
	}
	va_end(list);
	return (ft_strlen(format));
}
