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
	str ? (len = ft_strlen_ptf(str)) : (len = 6);
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
		if (arg->precision && (arg->precision < (int)ft_strlen_ptf(str)))
		{
			while (arg->precision > i)
				ft_putchar_ret(e, str[i++]);
		}
		else
			ft_putstr_ret(e, str);
	}
	else
		ft_putstr_ret(e, "(null)");
	while (arg->flags->minus && (arg->width >= (len + temp++)))
		ft_putchar_ret(e, ' ');
}

void arg_is_wstr(t_env *e, wchar_t *w_str)
{
	int i;

	i = 0;
	while (w_str[i])
	{
		arg_is_wchar(e, w_str[i++]);
	}
}

#include <string.h>

void	arg_is_string(t_env *e, t_arg *arg, va_list list)
{
	wchar_t *w_str;


	if (arg->length->l || arg->specifier == 'S')
	{
		w_str = va_arg(list, wchar_t*);
		if (w_str == NULL)
			memcpy(w_str, "(null)", 6);
		arg_is_wstr(e, w_str);
	}
	else
		print_str(e, arg, list);
}
