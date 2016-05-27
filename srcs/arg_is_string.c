/* == HEADER == */

#include "ft_printf.h"

void	print_str(t_env *e, t_arg *arg, va_list list)
{
	int		len;
	char	*str;
	int		temp;
	int		i;

	temp = 0;
	str = NULL;
	i = 0;
	str = va_arg(list, char*);
	str ? (len = ft_strlen(str)) : (len = 6);
	if (arg->precision && (arg->precision < len))
		len = arg->precision;
	while (arg->precision > (len + temp++) && len > temp)
		ft_putchar_ret(e, '0');
	if (arg->flags->space)
	{
		ft_putchar_ret(e, ' ');
		temp++;
	}
	while (!arg->flags->minus && ((arg->width - temp++) >= len))
		ft_putchar_ret(e, ' ');
	if (str)
	{
		if (arg->precision && (arg->precision < (int)ft_strlen(str)))
		{
			//len = arg->precision;
			while (arg->precision > i)
				ft_putchar_ret(e, str[i++]);
		}
		else
			ft_putstr_ret(e, str);
	}
	else
		ft_putstr("(null)");		// valeur retour quand null ?
	while (arg->flags->minus && (arg->width >= (len + temp++)))
		ft_putchar_ret(e, ' ');
}

void	arg_is_string(t_env *e, t_arg *arg, va_list list)
{
	print_str(e, arg, list);
}