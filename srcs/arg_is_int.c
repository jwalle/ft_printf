/* == HEADER == */

#include "ft_printf.h"

void	arg_is_int(t_arg *arg, t_spe *spe, va_list list)
{
	if (arg->length->no)
		spe->integer = va_arg(list, int);
	else if (arg->length->h)
		spe->s_char = va_arg(list, int);
}

