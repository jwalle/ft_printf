/* == HEADER == */

#include "ft_printf.h"

void	arg_is_string(t_arg *arg, t_spe *spe, va_list list)
{
	if (arg->length == NULL)
	{
		spe->string = ft_strdup(va_arg(list, char*));
	}
	else if (!ft_strcmp(arg->length, "hh"))
		spe->s_char = va_arg(list, int);
}