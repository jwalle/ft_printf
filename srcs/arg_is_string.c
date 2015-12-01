/* == HEADER == */

#include "ft_printf.h"

void	print_str(t_arg *arg, va_list list)
{
	int		len;
	char	*str;
	int		temp;

	temp = 0;
	str = NULL;
	str = va_arg(list, char*);
	str ? (len = ft_strlen(str)) : (len = 6);
	while (arg->precision > (len + temp++))
		ft_putchar('0');
	if (arg->flags->space)
	{
		ft_putchar(' ');
		temp++;
	}
	while (!arg->flags->minus && ((arg->width - temp++) >= len))
		ft_putchar(' ');
	str ? ft_putstr(str) : ft_putstr("(null)");
	while (arg->flags->minus && (arg->width > (len - temp++)))
		ft_putchar(' ');
}

void	arg_is_string(t_arg *arg, va_list list)
{
	print_str(arg, list);
	//if (arg->length->no)
}