/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 15:35:04 by jwalle            #+#    #+#             */
/*   Updated: 2015/08/07 14:47:15 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_atoi_hex(void *ptr)
{
	char				*base;
	unsigned long long	address;
	char				hex[12];
	int					i;

	base = HEXA;
	address = (unsigned long long)ptr;
	ft_bzero(hex, 12);
	i = 11;
	while (address)
	{
		hex[i] = base[address % 16];
		address = address / 16;
		i--;
	}
	ft_putstr("0x");
	ft_putstr(hex);
}
