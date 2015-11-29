/* == HEADER == */

#include "ft_printf.h"

void	arg_is_u(t_arg *arg, t_spe *spe, va_list list)
{
	if (arg->length == NULL)
	{
		spe->u_integer = va_arg(list, unsigned int);
	}
	else if (!ft_strcmp(arg->length, "hh"))
		spe->us_char = va_arg(list, unsigned int);
	else if (!ft_strcmp(arg->length, "h"))
		spe->us_integer = va_arg(list, unsigned int);
	else if (!ft_strcmp(arg->length, "l"))
		spe->ul_integer = va_arg(list, unsigned long int);
	else if (!ft_strcmp(arg->length, "ll"))
		spe->ull_integer = va_arg(list, unsigned long long int);
	else if (!ft_strcmp(arg->length, "j"))
		spe->umax_integer = va_arg(list, uintmax_t);
	else if (!ft_strcmp(arg->length, "z"))
		spe->size_t_integer = va_arg(list, size_t);
}