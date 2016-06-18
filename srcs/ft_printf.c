/* == HEADER == */

#include "ft_printf.h"
#include <stdio.h> // PRINTF PLOPLPOPLPO

void	parse_specifier(t_env *e, char specifier, t_arg *arg, va_list list)
{
	if (specifier == 'd' || specifier == 'i' || specifier == 'D')
		arg_is_int(e, arg, list);
	else if (specifier == 'u' || specifier == 'U' || specifier == 'o'
		|| specifier == 'O' || specifier == 'x' || specifier == 'X')
		arg_is_u(e, arg, list);
	else if (specifier == 'c' || specifier == 'C')
		arg_is_c(e, arg, list);
	//else if (specifier == 'C')
	//	arg_is_wchar(e, arg, list);
	else if (specifier == 's' || specifier == 'S')
		arg_is_string(e, arg, list);
	else if (specifier == 'p')
		arg_is_p(e, arg, list);
	else if (specifier == '%')
		print_char(e, arg, '%');
		else
		print_char(e, arg, specifier);
}

void		parse_number(t_env *e, long long number, char spe)
{
	if (spe == 'o' || spe == 'O')
	{
		ft_putnbr_octal(e, number);
		return ;
	}
	else if (spe == 'x' || spe == 'X')
	{
		ft_putnbr_hexa(e, number, spe);
		return ;
	}
	ft_putllunbr(e, number);
}

void	parse_args(t_env *e, t_arg *arg, va_list list)
{
	parse_specifier(e, arg->specifier, arg, list);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	t_arg	*arg;
	int 	i;
	t_env	*e;


    if (!format)
        return (-1);
	i = 0;
	arg = (t_arg*)malloc(sizeof(t_arg));
	e = (t_env*)malloc(sizeof(t_env));
	e->ret = 0;
	arg->flags = (t_flags*)malloc(sizeof(t_flags));
	arg->length = (t_length*)malloc(sizeof(t_length));
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (0);
			init_arg(arg);
			i += 1 + parse(&format[i] + 1, arg);
				/*printf("flags = {minus : %d, plus : %d, zero : %d, htag : %d, space : %d}, width = %d, precision = %d, specifier = %c\n",
			arg->flags->minus,
			arg->flags->plus,
			arg->flags->zero,
			arg->flags->htag,
			arg->flags->space,
			arg->width,
			arg->precision,
			arg->specifier);*/
			parse_args(e, arg, list);
		}
		else
			ft_putchar_ret(e, format[i++]);
	}
	va_end(list);
	return (e->ret);
}
