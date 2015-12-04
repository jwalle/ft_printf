/* == HEADER == */

#include "ft_printf.h"

// int		find_int(t_arg *arg, va_list list)
// {

// }

long long check_signed(long long n, t_length *length)
{
	if (length->hh)
		return ((signed char)n);
	else if (length->h)
		return ((short int)n);
	else if (length->l)
		return ((long)n);
	else if (length->no)
		return ((int)n);
	return (n);
}

void	print_llint(t_arg *arg, va_list list)
{
	int					len;
	int					signe;
	long long int		n;
	int					temp;

	n = check_signed(va_arg(list, long long int), arg->length);
	//n = va_arg(list, long long int);
	//n = check_signed(n, arg->length);
	(n < 0) ? (signe = -1) : (signe = 1);
	(n < 0) ? (n *= -1) : (n *= 1);
	len = ft_parse_len(n, arg->specifier);
	temp = format_output(len, signe, arg);
	parse_number(n, arg->specifier);
	while (arg->flags->minus && (arg->width > (len - temp++)))
		ft_putchar(' ');
}

void	print_int(t_arg *arg, va_list list)
{
	int		len;
	int		n;
	int		temp;
	int		signe;

	n = check_signed(va_arg(list, int), arg->length);
	(n < 0) ? (signe = -1) : (signe = 1);
	(n < 0) ? (n *= -1) : (n *= 1);
	len = ft_parse_len(n, arg->specifier);
	temp = format_output(len, signe, arg);
	parse_number(n, arg->specifier);
	while (arg->flags->minus && (arg->width > (len - temp++)))
		ft_putchar(' ');
}

void	arg_is_int(t_arg *arg, va_list list)
{
	//if (arg->length->no || arg->length->h || arg->length->hh)
	//	print_int(arg, list);
	//else if ( arg->length->l || arg->length->ll ||
	//	arg->length->z || arg->length->j)
		print_llint(arg, list);
}

