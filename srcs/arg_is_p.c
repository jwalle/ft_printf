/* == HEADER == */

#include "ft_printf.h"

void	print_ptr(t_arg *arg, va_list list)
{
	int		len;
	int		temp;

	temp = 0;
	len = 14;
	while (arg->precision > (len + temp++))
		ft_putchar('0');
	if (arg->flags->space)
	{
		ft_putchar(' ');
		temp++;
	}
	while (!arg->flags->minus && ((arg->width - temp++) >= len))
		ft_putchar(' ');
	ft_atoi_hex(va_arg(list, void*));
	while (arg->flags->minus && (arg->width >= (len - temp++)))
		ft_putchar(' ');
}


void	arg_is_p(t_arg *arg, va_list list)
{

	//if (arg->length->no)
	print_ptr(arg, list);
	//(void)arg;
	//	ft_atoi_hex(va_arg(list, void*));
	/*	va_arg(list, void*);
	else if (arg->length->j)
		va_arg(list, int);*/
}