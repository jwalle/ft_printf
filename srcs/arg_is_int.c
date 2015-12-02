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

int		format_left_width(t_arg *arg, int len, int signe)
{
	int temp;

	temp = 0;
 	if (arg->flags->htag)
 	{
 		if (arg->specifier == 'x' || arg->specifier == 'X')
 			temp = 2;
 		else if (arg->specifier == 'o')
 			temp = 1;
 	}
 	if (signe < 0)
 		len++;
	while (!arg->flags->zero && !arg->flags->minus && ((arg->width - temp) > len))
	{
		temp++;
		ft_putchar(' ');
	}
	return (temp);
}

int		format_output(int len, int signe, t_arg *arg)
{
	int temp;

	//temp = 0;
	/*while (!arg->flags->zero && !arg->flags->minus && ((arg->width - temp++) > len))
	{
		temp++;
		ft_putchar(' ');
	}*/
	temp = format_left_width(arg, len, signe);
	if (!arg->flags->plus && arg->flags->plus && signe > 0)
	{
		ft_putchar('+');
		temp++;
	}
	else if (signe < 0)
	{
		ft_putchar('-');
		temp++;
	}
	else if (arg->flags->space)
	{
		ft_putchar(' ');
		temp++;
	}
	//printf("width = %d, len = %d, temp = %d\n", arg->width, len, temp);
	if (arg->hex && arg->flags->htag)
		print_hex(arg->specifier);
	while (arg->flags->zero && ((arg->width - len) > temp++))
		ft_putchar('0');
	while (arg->precision >= (len + temp++))
		ft_putchar('0');
	return (temp);
}

void	print_int(t_arg *arg, va_list list)
{
	int		len;
	int		n;
	int		temp;
	int		signe;

	n = va_arg(list, int);
	(n < 0) ? (signe = -1) : (signe = 1);
	len = ft_parse_len(n, arg->specifier);
	temp = format_output(len, signe, arg);
	(n < 0) ? (n *= -1) : (n *= 1);
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

