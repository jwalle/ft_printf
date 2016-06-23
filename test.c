/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:01:26 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/19 05:01:25 by jwalle           ###   ########.fr       */
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

	//	ft_printf("ft->%#08x\n", 42);
	//	printf("un->%#08x\n", 42);

	//	ft_printf("ft->%4.1S<-\n", L"Jambon");
	//	printf("un->%4.1S<-\n", L"Jambon");
		//ft_printf("ft-->%S<--\n", NULL);
	//	ft_printf("ft{%015.4S}\n", L"我是一只猫。");
	//	printf("un{%015.4S}\n", L"我是一只猫。");
	//	printf("un-->%#.3o<--\n", 1);
	//	ft_printf("ft{%04.15S}\n", L"我是一只猫。");
	//	printf("un{%04.15S}\n", L"我是一只猫。");
	//	ft_printf("ft-->%#.3o<--\n", 1);
	//	printf("un-->%4.s<--\n", "42");
//	ft_printf("ft-->%.4S<--\n", L"我是一只猫。");
//	printf("un-->%.4S<--\n", L"我是一只猫。");

//	ft_printf("ft{%-30S}\n", L"我是一只猫。");
//	printf("un{%-30S}\n", L"我是一只猫。");
//	printf("un-->%s<--\n", "");
	
    ft_printf("ft-->%3*d<--\n",10 ,42);
	printf("un-->%3*d<--\n", 10, 42);
	
    ft_printf("ft-->%*3d<--\n", 10, 42);
	printf("un-->%*3d<--\n", 10, 42);
	//ft_printf("ft-->%.*d<--\n", -5, 42);
	//printf("un-->%.*d<--\n", -5, 42);
	
    //printf("un-->%C<--\n", 13040);

	//printf("%C\n", 63743);

	//ft_printf("ft-->%C<--\n", 130);
	//printf("un-->%C<--\n", 130);

	// precision of 0 >> nothing printed if value == 0.
	return (0);
}
