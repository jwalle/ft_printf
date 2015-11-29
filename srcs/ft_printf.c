/* == HEADER == */

#include "ft_printf.h"
#include <stdio.h> // PRINTF PLOPLPOPLPO

void	init_spe(t_spe *spe)
{
	spe->integer = 0;
	spe->s_char = 0;
	spe->s_integer = 0;
	spe->l_integer = 0;
	spe->ll_integer = 0;
	spe->max_integer = 0;
	spe->size_t_integer = 0;
	spe->u_integer = 0;
	spe->us_char = 0;
	spe->us_integer = 0;
	spe->ul_integer = 0;
	spe->ull_integer = 0;
	spe->umax_integer = 0;
	spe->character = 0;
	spe->w_integer = 0;
	spe->string = NULL;
	spe->w_string = NULL;
	spe->pointer = NULL;
}

int		ft_intlen(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		check_len(t_spe *spe)
{
	int i;

	i  = 0;
	if (spe->string)
		i = ft_strlen(spe->string);
	else if (spe->integer)
		i = ft_intlen(spe->integer);
	else if (spe->s_char)
		i = ft_intlen(spe->s_char);
	else if (spe->s_integer)
		i = ft_intlen(spe->s_integer);
	else if (spe->l_integer)
		i = ft_intlen(spe->l_integer);
	else if (spe->ll_integer)
		i = ft_intlen(spe->ll_integer);
	else if (spe->max_integer)
		i = ft_intlen(spe->max_integer);
	else if (spe->size_t_integer)
		i = ft_intlen(spe->size_t_integer);
	else if (spe->u_integer)
		i = ft_intlen(spe->u_integer);
	else if (spe->us_char)
		i = ft_intlen(spe->us_char);
	else if (spe->us_integer)
		i = ft_intlen(spe->us_integer);
	else if (spe->ul_integer)
		i = ft_intlen(spe->ul_integer);
	else if (spe->ull_integer)
		i = ft_intlen(spe->ull_integer);
	else if (spe->umax_integer)
		i = ft_intlen(spe->umax_integer);
	else if (spe->character)
		i = ft_intlen(spe->character);
	else if (spe->pointer)
		i = 14;
	return (i);
}

void	append_flag(t_arg *arg, t_spe *spe, int start)
{
	int	i;

	i = check_len(spe);
	if (!strchr(arg->flags, '-') && arg->width && start)
	{
		while (i++ < arg->width)
			ft_putchar(' ');
	}
	else if (strchr(arg->flags, '-') && arg->width && !start)
	{
		while (i++ < arg->width)
			ft_putchar(' ');
	}
}

void	parse_specifier(char specifier, t_arg *arg, t_spe *spe, va_list list)
{
	//printf("spe = %c\n", specifier);
	if (specifier == 'd' || specifier == 'i' || specifier == 'D')
		arg_is_int(arg, spe, list);
	else if (specifier == 'u' || specifier == 'U' || specifier == 'o'
		|| specifier == 'O' || specifier == 'x' || specifier == 'X')
		arg_is_u(arg, spe, list);
	else if (specifier == 'c')
		arg_is_c(arg, spe, list);
	else if (specifier == 's' || specifier == 'S') // wchar_t ?
		arg_is_string(arg, spe, list);
	else if (specifier == 'p')
		arg_is_p(arg, spe, list);
}

void	ft_putnbr_base(long long int number, char spe)
{
	char				*base;
	char				hex[12];
	int					i;

	if (spe == 'u')
	{
		ft_putnbr(number);
		return ;
	}
	if (spe == 'o')
		base = OCTAL;
	if (spe == 'x')
		base = HEXA;
	if (spe == 'X')
		base = HEXA_MAJ;
	i = ft_intlen(number);
	ft_bzero(hex, i + 1);
	while (number)
	{
		hex[i] = base[number % 16];
		number = number / 16;
		i--;
	}
	ft_putstr(hex);
}

void	parse_args(t_arg *arg, va_list list, t_spe *spe)
{
	init_spe(spe);
	parse_specifier(arg->specifier, arg, spe, list);
	if (arg->width || arg->flags)
		append_flag(arg, spe, 1);
	if (spe->integer)
		ft_putnbr(spe->integer);
	else if (spe->s_char)
		ft_putnbr(spe->s_char);
	else if (spe->s_integer)
		ft_putnbr(spe->s_integer);
	else if (spe->l_integer)
		ft_putnbr(spe->l_integer);
	else if (spe->ll_integer)
		ft_putnbr(spe->ll_integer);
	else if (spe->max_integer)
		ft_putnbr(spe->max_integer);
	else if (spe->max_integer)
		ft_putnbr(spe->max_integer);
	else if (spe->u_integer)
	{
		ft_putnbr_base(spe->u_integer, arg->specifier);
	}
	else if (spe->us_char)
		ft_putnbr(spe->us_char);
	else if (spe->us_integer)
		ft_putnbr(spe->us_integer);
	else if (spe->ul_integer)
		ft_putnbr(spe->ul_integer);
	else if (spe->ull_integer)
		ft_putnbr(spe->ull_integer);
	else if (spe->umax_integer)
		ft_putnbr(spe->umax_integer);
	else if (spe->character)
		ft_putchar(spe->character);
	else if (spe->string)
		ft_putstr(spe->string);
	else if (spe->pointer)
		ft_atoi_hex(spe->pointer);
	else if (spe->size_t_integer)
		ft_putnbr(spe->size_t_integer);
	if (arg->flags)
		append_flag(arg, spe, 0);
}

void	init_arg(t_arg *arg)
{
	arg->flags = NULL;
	arg->width = 0;
	arg->precision = 0;
	arg->length = NULL;
	arg->specifier = 0;
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
		if (format[i] == '%')
		{
			init_arg(arg);
			i += 1 + parse(&format[i] + 1, arg);
			parse_args(arg, list, spe);
		}
		else
			ft_putchar(format[i++]);
	}
	va_end(list);
	return (buffer);
}
