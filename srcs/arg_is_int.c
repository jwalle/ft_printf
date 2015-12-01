/* == HEADER == */

#include "ft_printf.h"

// int		find_int(t_arg *arg, va_list list)
// {

// }

void	print_llint(t_arg *arg, va_list list)
{
	int					len;
	long long int		n;
	int					temp;

	temp = 0;
	n = va_arg(list, long long int);
	len = ft_ll_intlen(n);
	len = ft_parse_len(n, arg->specifier);
	while (arg->precision > (len + temp++))
		ft_putchar('0');
	if (arg->flags->plus && n > 0)
	{
		ft_putchar('+');
		temp++;
	}
	else if (arg->flags->space && n > 0)
	{
		ft_putchar(' ');
		temp++;
	}
	while (!arg->flags->minus && ((arg->width - temp++) >= len))
		ft_putchar(' ');
	// ft_putllnbr(n);
	parse_number(n, arg->specifier);
	while (arg->flags->minus && (arg->width > (len - temp++)))
		ft_putchar(' ');
}

void	print_int(t_arg *arg, va_list list)
{
	int		len;
	int		n;
	int		temp;

	temp = 0;
	n = va_arg(list, int);
	len = ft_parse_len(n, arg->specifier);
	while (!arg->flags->minus && ((arg->width - temp++) > len))
		ft_putchar(' ');
	if (arg->flags->plus && n > 0)
	{
		ft_putchar('+');
		temp++;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		//temp++;
	}
	else if (arg->flags->space)
	{
		ft_putchar(' ');
		temp++;
	}
	while (arg->precision >= (len + temp++))
		ft_putchar('0');
	parse_number(n, arg->specifier);
	while (arg->flags->minus && (arg->width > (len - temp++)))
		ft_putchar(' ');
}

void	arg_is_int(t_arg *arg, va_list list)
{
	if (arg->length->no || arg->length->h || arg->length->hh)
		print_int(arg, list);
	else if ( arg->length->l || arg->length->ll ||
		arg->length->z || arg->length->j)
		print_llint(arg, list);
}

