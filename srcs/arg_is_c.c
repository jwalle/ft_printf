/* == HEADER == */

#include "ft_printf.h"

void	arg_is_c(t_arg *arg, va_list list)
{
	(void)arg;
	ft_putchar(va_arg(list, int));
}