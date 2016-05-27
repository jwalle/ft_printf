/* == HEADER == */

#include "ft_printf.h"

void	print_str(t_env *e, t_arg *arg, va_list list)
{
	int		len;
	char	*str;
	int		temp;

	temp = 0;
	str = NULL;
	str = va_arg(list, char*);
	str ? (len = ft_strlen(str)) : (len = 6);
	while (arg->precision > (len + temp++))
		ft_putchar_ret(e, '0');
	if (arg->flags->space)
	{
		ft_putchar_ret(e, ' ');
		temp++;
	}
	while (!arg->flags->minus && ((arg->width - temp++) >= len))
		ft_putchar_ret(e, ' ');
	str ? ft_putstr_ret(e, str) : ft_putstr("(null)");				// valeur retour quand null ?
	while (arg->flags->minus && (arg->width >= (len + temp++)))
		ft_putchar_ret(e, ' ');
}

void	arg_is_string(t_env *e, t_arg *arg, va_list list)
{
	print_str(e, arg, list);
}