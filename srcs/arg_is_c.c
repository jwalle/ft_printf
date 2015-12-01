/* == HEADER == */

#include "ft_printf.h"

void	arg_is_c(t_arg *arg, va_list list)
{
	/*if (arg->length->z)
	{
		va_arg(list, int);
	}
	else if (arg->length->j)*/
	(void)arg;
	ft_putchar(va_arg(list, int));
}