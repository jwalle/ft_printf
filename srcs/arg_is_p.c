/* == HEADER == */

#include "ft_printf.h"

void	print_ptr(t_env *e, t_arg *arg, va_list list)
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
		ft_putchar_ret(e, '0');
	if (arg->flags->space)
	{
		ft_putchar_ret(e, ' ');
		temp++;
	}
	while (!arg->flags->minus && ((arg->width - temp++) >= len))
		ft_putchar_ret(e, ' ');
	if (ptr)
	{
		ft_putstr_ret(e, "0x");
		ft_putnbr_hexa(e, (unsigned long long)ptr, 'x');
	}
	else
		ft_putstr_ret(e, "(nil)");
	while (arg->flags->minus && (arg->width >= (len - temp++)))
		ft_putchar_ret(e, ' ');
}


void	arg_is_p(t_env *e, t_arg *arg, va_list list)
{
	print_ptr(e, arg, list);
}