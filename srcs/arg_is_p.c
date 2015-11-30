/* == HEADER == */

#include "ft_printf.h"

void	arg_is_p(t_arg *arg, va_list list)
{
	if (arg->length->no)
	{
		va_arg(list, void*);
	}
	else if (arg->length->hh)
		va_arg(list, int);
}