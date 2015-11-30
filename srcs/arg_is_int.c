/* == HEADER == */

#include "ft_printf.h"

// int		find_int(t_arg *arg, va_list list)
// {

// }

void	print_int(t_arg *arg, va_list list)
{
	int		len;
	int		n;
	int		temp;
	//n = find_int(arg, list);
	temp = 0;
	n = va_arg(list, int);
	printf("%d", n);
	len = ft_intlen(n);
	while (arg->precision > (len + temp++))
		ft_putchar('0');
	if (arg->flags->plus && n > 0) {
		ft_putchar('+'); temp++; }
	else if (arg->flags->space && n > 0) {
		ft_putchar(' '); temp++;
	}
	while (!arg->flags->minus && ((arg->width - temp++) > len))
		ft_putchar(' ');
	ft_putnbr(n);
	while (arg->flags->minus && (arg->width-- > (len - temp)))
		ft_putchar(' ');
}

void	arg_is_int(t_arg *arg, va_list list)
{
	if (arg->length->no || arg->length->h)
		print_int(arg, list);
}

