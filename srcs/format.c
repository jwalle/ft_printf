/* == HEADER == */

#include "ft_printf.h"

int		format_left_width(t_env *e, t_arg *arg, int len, int signe)
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
		ft_putchar_ret(e, ' ');
	}
	return (temp);
}

int		format_center(t_env *e, t_arg *arg, int signe)
{
	int		temp;

	temp = 0;
	if (!arg->flags->minus && arg->flags->plus && signe > 0)
	{
		ft_putchar_ret(e, '+');
		temp++;
	}
	else if (signe < 0)
	{
		ft_putchar_ret(e, '-');
		temp++;
	}
	else if (arg->flags->space && (arg->specifier == 'd' || arg->specifier == 'i'))
	{
		ft_putchar_ret(e, ' ');
		temp++;
	}
	return (temp);
}

int		format_output(t_env *e, int len, int signe, t_arg *arg)
{
	int temp;

	temp = 0;
	if (arg->precision > len && arg->flags->minus)
	{
		while (arg->precision > len + temp++)
			ft_putchar_ret(e, '0');
	}

	temp = format_left_width(e, arg, len, signe);
	temp += format_center(e, arg, signe);
	//printf("width = %d, len = %d, temp = %d\n", arg->width, len, temp);
	if (signe && arg->hex && arg->flags->htag)
		print_hex(e, arg->specifier);
	if (!arg->flags->minus)
	{
		while (arg->flags->zero && ((arg->width - len) > temp++))
			ft_putchar_ret(e, '0');
		while (arg->precision > (len + temp++))
			ft_putchar_ret(e, '0');
	}
	return (temp);
}