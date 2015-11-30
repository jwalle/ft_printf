/* == HEADER == */

#include "ft_printf.h"

void	arg_is_string(t_arg *arg, t_spe *spe, va_list list)
{
	if (arg->length->no)
	{
		spe->string = ft_strdup(va_arg(list, char*));
	}
	else if (arg->length->hh)
		spe->s_char = va_arg(list, int);
}