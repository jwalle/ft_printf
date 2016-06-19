/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:54:22 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/19 18:54:23 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_length(t_length *length)
{
	length->no = 1;
	length->h = 0;
	length->hh = 0;
	length->l = 0;
	length->ll = 0;
	length->z = 0;
	length->j = 0;
}

void	init_arg(t_arg *arg)
{
	arg->flags->minus = 0;
	arg->flags->plus = 0;
	arg->flags->zero = 0;
	arg->flags->htag = 0;
	arg->flags->space = 0;
	arg->width = 0;
	arg->precision = 0;
	arg->precision_null = 0;
	arg->specifier = 0;
	arg->hex = 0;
	arg->is_unsigned = 0;
}
