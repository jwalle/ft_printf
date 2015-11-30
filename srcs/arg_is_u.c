/* == HEADER == */

#include "ft_printf.h"

void	arg_is_u(t_arg *arg, t_spe *spe, va_list list)
{
	if (arg->length->no)
	{
		spe->u_integer = va_arg(list, unsigned int);
	}
	else if (arg->length->l)
		spe->us_char = va_arg(list, unsigned int);
}