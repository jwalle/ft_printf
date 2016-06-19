/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:06:55 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/19 18:14:00 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	w_str ? len = ft_wstrlen_ptf(w_str) : 6;
	if ((arg->precision && (arg->precision < len)) || arg->precision_null)
	{
		len = 0;
		while (len + get_wchar_len(w_str[i]) <= arg->precision)
			len += get_wchar_len(w_str[i++]);
	}
	i = 0;
	while (!arg->flags->minus && ((arg->width - temp) > len))
	{
		if (arg->flags->zero)
			ft_putchar_ret(e, '0');
		else
			ft_putchar_ret(e, ' ');
		temp++;
	}
	// printf("\ntemp = %d, precision = %d, len = %d, width = %d\n", temp, arg->precision, len, arg->width);
	temp = 0;
	if (w_str && !arg->precision_null)
	{
		if (arg->precision && (arg->precision < ft_wstrlen_ptf(w_str)))
		{
			while (w_str[i] && arg->precision >= temp + get_wchar_len(w_str[i]))
			{
				arg_is_wchar(e, w_str[i]);
				temp += get_wchar_len(w_str[i]);
				i++;
			}
		}
		else
			arg_is_wstr(e, w_str);
	}
	else if (!w_str && !arg->precision_null)
		ft_putstr_ret(e, "(null)");
	while (arg->flags->minus && (arg->width > (len + temp++)))
		ft_putchar_ret(e, ' ');
}

void	print_str(t_env *e, char *str, t_arg *arg)
{
	int		len;
	int		temp;
	int		i;

	temp = 0;
	i = 0;
	str ? len = ft_strlen_ptf(str) : 6;
	if (!str || arg->precision_null)
		len = 0;
	if (arg->precision && (len > arg->precision))
		len = arg->precision;
	while (!arg->flags->minus && ((arg->width - temp++) > len))
	{
		if (arg->flags->zero)
			ft_putchar_ret(e, '0');
		else
			ft_putchar_ret(e, ' ');
	}
	if (str && !arg->precision_null)
	{
		if (arg->precision && (arg->precision < (int)ft_strlen_ptf(str)))
		{
			while (arg->precision > i)
				ft_putchar_ret(e, str[i++]);
		}
		else
			ft_putstr_ret(e, str);
	}
	else if (!arg->precision_null)
		ft_putstr_ret(e, "(null)");
	while (arg->flags->minus && (arg->width >= (len + temp++)))
		ft_putchar_ret(e, ' ');
}

void	arg_is_wstr(t_env *e, wchar_t *w_str)
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
	char	*str;

	if (arg->length->l || arg->specifier == 'S')
	{
		w_str = va_arg(list, wchar_t*);
		print_wstr(e, w_str, arg);
	}
	else
	{
		str = va_arg(list, char*);
		print_str(e, str, arg);
	}
}
