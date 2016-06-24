/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:55:50 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/19 19:02:59 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_length(t_arg *arg, char *len_parse)
{
	if (!len_parse)
	{
		arg->length->no = 1;
		return ;
	}
	arg->length->no = 0;
	if (!ft_strcmp_ptf(len_parse, "hh"))
		arg->length->hh = 1;
	else if (!ft_strcmp_ptf(len_parse, "h"))
		arg->length->h = 1;
	else if (!ft_strcmp_ptf(len_parse, "l"))
		arg->length->l = 1;
	else if (!ft_strcmp_ptf(len_parse, "ll"))
		arg->length->ll = 1;
	else if (!ft_strcmp_ptf(len_parse, "j"))
		arg->length->j = 1;
	else if (!ft_strcmp_ptf(len_parse, "z"))
		arg->length->z = 1;
}

int		is_hex(char spe)
{
	if (spe == 'o' || spe == 'O')
		return (1);
	else if (spe == 'x' || spe == 'X')
		return (2);
	return (0);
}

int		parse_two(const char *format, t_arg *arg, int n)
{
	int		i;
	char	*len_parse;

	i = 0;
	init_length(arg->length);
	if (ft_strchr_ptf(LENGTH, format[i + n]))
	{
		while (ft_strchr_ptf(LENGTH, format[i + n]))
			i++;
		len_parse = ft_strndup((char *)format + n, i);
		n += i;
		parse_length(arg, len_parse);
		free(len_parse);
	}
	arg->specifier = format[n++];
	arg->hex = is_hex(arg->specifier);
	return (n);
}

int		parse_zero(const char *format, t_arg *arg)
{
	int	i;

	i = 0;
	while (ft_strchr_ptf(FLAGS, format[i]))
	{
		if (format[i] == '-')
			arg->flags->minus = 1;
		if (format[i] == '+')
			arg->flags->plus = 1;
		if (format[i] == '0')
			arg->flags->zero = 1;
		if (format[i] == '#')
			arg->flags->htag = 1;
		if (format[i] == ' ')
			arg->flags->space = 1;
		i++;
	}
	return (i);
}

int parse_width(const char *format, t_arg *arg, va_list list, int n)
{
	int i;

	i = 0;
	while (ft_isdigit_ptf(format[i + n]) || format[i + n] == '*')
	{
		while (ft_isdigit_ptf(format[i + n]))
			i++;
		if (format[n + i] == '*')
		{
			arg->width = va_arg(list, int);
			n += i + 1;
			i = 0;
		}
	}
	if (i)
		arg->width = ft_atoi_ptf((char *)format + n);
	if (arg->width < 0)
	{
		arg->width *= -1;
		arg->flags->minus = 1;
	}
	return (n + i);
}

int parse_precision(const char *format, t_arg *arg, va_list list, int n)
{
	int	i;

	i = 0;
	while (ft_isdigit_ptf(format[i + n]) || format[i + n] == '*')
	{
		while (ft_isdigit_ptf(format[i + n]))
			i++;
		if (format[n + i] == '*')
		{
			arg->precision = va_arg(list, int);
			n += i + 1;
			i = 0;
		}
	}
	if (i)
		arg->precision = ft_atoi_ptf((char *)format + n);
	arg->precision == 0 ? arg->precision_null = 1 : 0;
	return (n + i);
}

int		parse(const char *format, t_arg *arg, va_list list)
{
	int		n;

	n = parse_zero(format, arg);	
	n = parse_width(format, arg, list, n);
	if (format[n] == '.')
	{
		n = parse_precision(format, arg, list, n + 1);
		if (arg->precision < 0)
		{
			arg->precision = 0;
				return (parse_two(format, arg, n));
		}
	}
	return (parse_two(format, arg, n));
}
