/* == HEADER == */

#include "ft_printf.h"


int		ft_wstrlen_ptf(wchar_t *w)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	while (w[i])
		ret += get_wchar_len(w[i++]);
	return (ret);
}

void	print_wstr(t_env *e, wchar_t *w_str, t_arg *arg)
{
	int		len;
	int		temp;
	int		i;

	temp = 0;
	i = 0;
	w_str ? (len = ft_wstrlen_ptf(w_str)) : (len = 6);
//	printf("len = %d\n", len);
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
	if (w_str)
	{
		if (arg->precision && (arg->precision < (int)ft_wstrlen_ptf(w_str)))
		{
			while (arg->precision > i)
				arg_is_wchar(e, w_str[i++]);
		}
		else
			arg_is_wstr(e, w_str);
	}
	else
		ft_putstr_ret(e, "(null)");
	while (arg->flags->minus && (arg->width >= (len + temp++)))
		ft_putchar_ret(e, ' ');
}

void	print_str(t_env *e, char *str, t_arg *arg)
{
	int		len;
	int		temp;
	int		i;

	temp = 0;
	i = 0;
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

void	arg_is_string(t_env *e, t_arg *arg, va_list list)
{
	wchar_t *w_str;
	char		*str;

	if (arg->length->l || arg->specifier == 'S')
	{
		w_str = va_arg(list, wchar_t*);
		/*if (w_str == NULL)
		{
			ft_putstr_ret(e, "(null)");
			return ;
		}*/
		print_wstr(e, w_str, arg);
	}
	else
	{
		str = va_arg(list, char*);
		print_str(e, str, arg);
	}
}
