/* == HEADER == */

#include "ft_printf.h"

void	arg_is_int(t_arg *arg, t_spe *spe, va_list list)
{
	if (arg->length == NULL)
	{
		spe->integer = va_arg(list, int);
	}
	else if (!ft_strcmp(arg->length, "hh"))
		spe->s_char = va_arg(list, int);
	else if (!ft_strcmp(arg->length, "h"))
		spe->s_integer = va_arg(list, int);
	else if (!ft_strcmp(arg->length, "l"))
		spe->l_integer = va_arg(list, long int);
	else if (!ft_strcmp(arg->length, "ll"))
		spe->ll_integer = va_arg(list, long long int);
	else if (!ft_strcmp(arg->length, "j"))
		spe->max_integer = va_arg(list, intmax_t);
	else if (!ft_strcmp(arg->length, "z"))
		spe->size_t_integer = va_arg(list, size_t);
}

