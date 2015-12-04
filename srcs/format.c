/* == HEADER == */

#include "ft_printf.h"

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