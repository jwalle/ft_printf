/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 22:01:26 by jwalle            #+#    #+#             */
/*   Updated: 2016/06/06 19:02:14 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
	//printf("test 1 : -->%5c<-- , -->%5d<--\n", 42, 42);

//	printf("TEST =%%.o, -42\n");

//	ft_printf("-->% hZ<--\n");
//	printf("-->% hZ<--\n");
	printf("%s", 42);

	// precision of 0 >> nothing printed if value == 0.
	return (0);
}
