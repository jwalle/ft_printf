/* == HEADER == */

#include "ft_printf.h"

void	ft_putllunbr(unsigned long long int n)
{
	// if (n == -2147483648)
	// {
	// 	ft_putstr("-214748364");
	// 	n = 8;
	// }
	if (n < 10)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putllnbr(n / 10);
		ft_putllnbr(n % 10);
	}
}

void	print_lluint(t_arg *arg, va_list list)
{
	int						len;
	unsigned long long int	n;
	int						temp;

	temp = 0;
	n = va_arg(list, unsigned long long int);
	len = ft_ll_intlen((int)n);
	while (arg->precision > (len + temp++))
		ft_putchar('0');
	if (arg->flags->plus)
	{
		ft_putchar('+');
		temp++;
	}
	else if (arg->flags->space)
	{
		ft_putchar(' ');
		temp++;
	}
	while (!arg->flags->minus && ((arg->width - temp++) > len))
		ft_putchar(' ');
	ft_putllunbr(n);
	while (arg->flags->minus && (arg->width > (len - temp++)))
		ft_putchar(' ');
}

void	print_uint(t_arg *arg, va_list list)
{
	int		len;
	int		n;
	int		temp;

	temp = 0;
	n = va_arg(list, unsigned int);
	len = ft_intlen((int)n);
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
	ft_putllunbr(n);
	while (arg->flags->minus && (arg->width > (len + temp++)))
		ft_putchar(' ');
}

void	arg_is_u(t_arg *arg, va_list list)
{
	if (arg->length->no || arg->length->h || arg->length->hh)
		print_uint(arg, list);
	else if ( arg->length->l || arg->length->ll ||
		arg->length->z || arg->length->j)
		print_lluint(arg, list);
}