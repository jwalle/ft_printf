/* == HEADER == */

#include "ft_printf.h"
#include <stdio.h> // PRINTF PLOPLPOPLPO

int		check_len(t_spe *spe, char specifier)
{
	int i;

	i  = 0;
	if (spe->string)
		i = ft_strlen(spe->string);
	else if (spe->integer)
		i = ft_parse_len(spe->integer, specifier);
	else if (spe->s_char)
		i = ft_parse_len(spe->s_char, specifier);
	else if (spe->s_integer)
		i = ft_parse_len(spe->s_integer, specifier);
	else if (spe->l_integer)
		i = ft_parse_len(spe->l_integer, specifier);
	else if (spe->ll_integer)
		i = ft_parse_len(spe->ll_integer, specifier);
	else if (spe->max_integer)
		i = ft_parse_len(spe->max_integer, specifier);
	else if (spe->size_t_integer)
		i = ft_parse_len(spe->size_t_integer, specifier);
	else if (spe->u_integer)
		i = ft_parse_len(spe->u_integer, specifier);
	else if (spe->us_char)
		i = ft_parse_len(spe->us_char, specifier);
	else if (spe->us_integer)
		i = ft_parse_len(spe->us_integer, specifier);
	else if (spe->ul_integer)
		i = ft_parse_len(spe->ul_integer, specifier);
	else if (spe->ull_integer)
		i = ft_parse_len(spe->ull_integer, specifier);
	else if (spe->umax_integer)
		i = ft_parse_len(spe->umax_integer, specifier);
	else if (spe->character)
		i = ft_parse_len(spe->character, specifier);
	else if (spe->pointer)
		i = 14;
	return (i);
}

void	append_flag(t_arg *arg, t_spe *spe, int start)
{
	int	i;

	i = check_len(spe, arg->specifier);
	if (!arg->flags->minus && arg->width && start)
	{
		while (i++ < arg->width)
			ft_putchar(' ');
	}
	else if (arg->flags->minus && arg->width && !start)
	{
		while (i++ < arg->width)
			ft_putchar(' ');
	}
}

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
}
void	ft_putnbr_octal(long long int number)
{
	char				*octal;
	int					i;

	i = ft_int_octal_len(number);
	octal = ft_strnew(i);
	ft_bzero(octal, i + 1);
	while (number)
	{
		octal[--i] = number % 8 + '0';
		number = number / 8;
	}
	ft_putstr(octal);
}

void	ft_putnbr_hexa(long long int number, char spe)
{
	char				*base;
	char				*hex;
	int					i;


	if (spe == 'x')
		base = HEXA;
	if (spe == 'X')
		base = HEXA_MAJ;
	i = ft_int_hex_len(number);
	hex = ft_strnew(i);
	ft_bzero(hex, i + 1);
	while (number)
	{
		hex[--i] = base[number % 16];
		number = number / 16;
	}
	ft_putstr(hex);
}

void		parse_number(int number, char spe)
{
	if (spe == 'u')
	{
		ft_putnbr(number);
		return ;
	}
	else if (spe == 'o')
	{
		ft_putnbr_octal(number);
		return ;
	}
	else if (spe == 'x' || spe == 'X')
	{
		ft_putnbr_hexa(number, spe);
		return ;
	}
}

void	parse_args(t_arg *arg, va_list list)
{
//	init_spe(spe);
	parse_specifier(arg->specifier, arg, list);
	// if (arg->width || arg->flags)
	// 	append_flag(arg, spe, 1);
	// if (spe->integer)
	// 	ft_putnbr(spe->integer);
	// else if (spe->s_char)
	// 	ft_putnbr(spe->s_char);
	// else if (spe->s_integer)
	// 	ft_putnbr(spe->s_integer);
	// else if (spe->l_integer)
	// 	ft_putnbr(spe->l_integer);
	// else if (spe->ll_integer)
	// 	ft_putnbr(spe->ll_integer);
	// else if (spe->max_integer)
	// 	ft_putnbr(spe->max_integer);
	// else if (spe->max_integer)
	// 	ft_putnbr(spe->max_integer);
	// else if (spe->u_integer)
	// {
	// 	parse_number(spe->u_integer, arg->specifier);
	// }
	// else if (spe->us_char)
	// 	parse_number(spe->us_char, arg->specifier);
	// else if (spe->us_integer)
	// 	ft_putnbr(spe->us_integer);
	// else if (spe->ul_integer)
	// 	ft_putnbr(spe->ul_integer);
	// else if (spe->ull_integer)
	// 	ft_putnbr(spe->ull_integer);
	// else if (spe->umax_integer)
	// 	ft_putnbr(spe->umax_integer);
	// else if (spe->character)
	// 	ft_putchar(spe->character);
	// else if (spe->string)
	// 	ft_putstr(spe->string);
	// else if (spe->pointer)
	// 	ft_atoi_hex(spe->pointer);
	// else if (spe->size_t_integer)
	// 	ft_putnbr(spe->size_t_integer);
	// if (arg->flags)
	// 	append_flag(arg, spe, 0);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	t_arg	*arg;
	t_spe	*spe;
	int 	i;

    if (!format)
        return (-1);
	i = 0;
	arg = (t_arg*)malloc(sizeof(t_arg));
	arg->flags = (t_flags*)malloc(sizeof(t_flags));
	arg->length = (t_length*)malloc(sizeof(t_length));
	spe = (t_spe*)malloc(sizeof(t_spe));
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
