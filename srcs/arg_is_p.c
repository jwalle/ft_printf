/* == HEADER == */

#include "ft_printf.h"

void	arg_is_p(t_arg *arg, t_spe *spe, va_list list)
{
	if (arg->length->no)
	{
		spe->pointer = va_arg(list, void*);
	}
	else if (arg->length->hh)
		spe->s_char = va_arg(list, int);
}