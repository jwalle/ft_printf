/* == HEADER == */

#include "ft_printf.h"

// int		find_int(t_arg *arg, va_list list)
// {

// }

void	ft_putllnbr(long long int n)
{
	// if (n == -2147483648)
	// {
	// 	ft_putstr("-214748364");
	// 	n = 8;
	// }
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n < 10)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putllnbr(n / 10);
		ft_putllnbr(n % 10);
	}
}

void	print_llint(t_arg *arg, va_list list)
{
	int					len;
	long long int		n;
	int					temp;

	temp = 0;
	n = va_arg(list, long long int);
	len = ft_ll_intlen(n);
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
	while (!arg->flags->minus && ((arg->width - temp++) > len))
		ft_putchar(' ');
	ft_putllnbr(n);
	while (arg->flags->minus && (arg->width > (len - temp++)))
		ft_putchar(' ');
}

void	print_int(t_arg *arg, va_list list, char spe)
{
	int		len;
	int		n;
	int		temp;

	temp = 0;
	n = va_arg(list, int);
	//len = ft_intlen(n);
	len = ft_parse_len(n, spe);
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
	while (!arg->flags->minus && ((arg->width - temp++) > len))
		ft_putchar(' ');
	ft_putnbr(n);
	while (arg->flags->minus && (arg->width > (len - temp++)))
		ft_putchar(' ');
}

void	arg_is_int(t_arg *arg, va_list list)
{
	if (arg->length->no || arg->length->h || arg->length->hh)
		print_int(arg, list, arg->specifier);
	else if ( arg->length->l || arg->length->ll ||
		arg->length->z || arg->length->j)
		print_llint(arg, list);
}

