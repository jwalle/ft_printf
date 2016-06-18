/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:01:26 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/18 21:04:52 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	(void)s;
	return (10);
}

int main()
{
	char *l = setlocale(LC_ALL, "");
	if (l == NULL)
		printf("local not set\n");
	else
		printf("--> local set to = %s\n\n\n", l);


		//ft_printf("ft-->%S<--\n", NULL);
		//ft_printf("{%30S}\n", L"我是一只猫。");
		//printf("{%30S}\n", L"我是一只猫。");
	ft_printf("ft-->%.5p<--\n", 0);
	//ft_printf("ft-->%s<--\n", 43);
	//printf("un-->%.5p<--\n", 0);
	//printf("un-->%C<--\n", 13040);

	//printf("%C\n", 63743);

	//ft_printf("ft-->%C<--\n", 130);
	//printf("un-->%C<--\n", 130);

	// precision of 0 >> nothing printed if value == 0.
	return (0);
}
