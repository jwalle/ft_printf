/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:01:26 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/27 16:41:53 by jwalle           ###   ########.fr       */
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

	int i = 1;
	int ret;
	//while (i < 100000)
	//{
		i =945; 
		ret = ft_printf("{g}ft-->%c<-- | i = %d{eoc}\n", 42, i); 
		printf("ret = %d\n", ret);
		ret = printf("un-->%c<-- | i = %d\n", 42, i); 
		printf("ret = %d\n", ret);
	//	i++;
	//}
	return (0);
}
