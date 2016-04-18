/* == HEADER == */

#include "ft_printf.h"

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
	else if (length->j)
		return ((intmax_t)n);
	else if (length->z)
		return ((size_t)n);
	return (n);
}

void	print_llint(t_arg *arg, va_list list)
{
	int					len;
	int					signe;
	long long int		n;
	int					temp;

	n = check_signed(va_arg(list, long long int), arg->length);
	(n < 0) ? (signe = -1) : (signe = 1);
	if (n == 0)
		signe = 0;
	(n < 0) ? (n *= -1) : (n *= 1);
	len = ft_parse_len(n, arg->specifier);
	temp = format_output(len, signe, arg);
	parse_number(n, arg->specifier);
	while (arg->flags->minus && (arg->width - temp++) > len)
		ft_putchar(' ');
}

void	arg_is_int(t_arg *arg, va_list list)
{
	print_llint(arg, list);
}

