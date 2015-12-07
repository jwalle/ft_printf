/* == HEADER == */

#include "ft_printf.h"

void	print_ptr(t_arg *arg, va_list list)
{
	int		len;
	int		temp;
	void	*ptr;

	temp = 0;
	ptr = va_arg(list, void*);
	if (ptr)
		len = ft_int_hex_len((unsigned long long)ptr);
	else
		len = 5;
	while (arg->precision > (len + temp++))
		ft_putchar('0');
	if (arg->flags->space)
	{
		ft_putchar(' ');
		temp++;
	}
	while (!arg->flags->minus && ((arg->width - temp++) >= len))
		ft_putchar(' ');
	if (ptr)
	{
		ft_putstr("0x");
		ft_putnbr_hexa((unsigned long long)ptr, 'x');
	}
	else
		ft_putstr("(nil)");
	while (arg->flags->minus && (arg->width >= (len - temp++)))
		ft_putchar(' ');
}


void	arg_is_p(t_arg *arg, va_list list)
{
	print_ptr(arg, list);
}