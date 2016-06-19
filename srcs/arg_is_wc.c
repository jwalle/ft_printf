/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_is_wc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 20:17:19 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/19 20:17:31 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putwchar(t_env *e, unsigned char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, &str[i], 1);
		e->ret++;
		i++;
	}
}

int				get_wchar_len(wchar_t c)
{
	unsigned int e;

	e = (unsigned int)c;
	if (e > 0 && e < 255)
		return (1);
	else if (e < 0x07FF)
		return (2);
	else if (e < 0xFFFF)
		return (3);
	else
		return (4);
}

unsigned char	*convert_wchar(unsigned char *str, wchar_t c, int len)
{
	if (len == 2)
	{
		str[0] = ((c >> 6) | 0xC0);
		str[1] = ((c & 0x3F) | 0x80);
	}
	else if (len == 3)
	{
		str[0] = ((c >> 12) | 0xE0);
		str[1] = (((c >> 6) & 0x3F) | 0x80);
		str[2] = ((c & 0x3F) | 0x80);
	}
	else if (len == 4)
	{
		str[0] = ((c >> 18) | 0xF0);
		str[1] = (((c >> 12) & 0x3F) | 0x80);
		str[2] = (((c >> 6) & 0x3F) | 0x80);
		str[3] = ((c & 0x3F) | 0x80);
	}
	str[4] = 0;
	return (str);
}

void			arg_is_wchar(t_env *e, wchar_t w)
{
	unsigned char	str[5];
	int				len;

	if (w >= 0 && w <= 255)
	{
		ft_putchar_ret(e, w);
		return ;
	}
	ft_bzero_ptf(str, 5);
	len = get_wchar_len(w);
	convert_wchar(str, w, len);
	ft_putwchar(e, str, len);
}
