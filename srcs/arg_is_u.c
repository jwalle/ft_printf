/* == HEADER == */

#include "ft_printf.h"

void	arg_is_u(t_arg *arg, va_list list)
{
	if (arg->length->no)
	{
		va_arg(list, unsigned int);
	}
	else if (arg->length->l)
		va_arg(list, unsigned int);
}