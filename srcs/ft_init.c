/* == HEADER == */

#include "ft_printf.h"

void	init_spe(t_spe *spe)
{
	spe->integer = 0;
	spe->s_char = 0;
	spe->s_integer = 0;
	spe->l_integer = 0;
	spe->ll_integer = 0;
	spe->max_integer = 0;
	spe->size_t_integer = 0;
	spe->u_integer = 0;
	spe->us_char = 0;
	spe->us_integer = 0;
	spe->ul_integer = 0;
	spe->ull_integer = 0;
	spe->umax_integer = 0;
	spe->character = 0;
	spe->w_integer = 0;
	spe->string = NULL;
	spe->w_string = NULL;
	spe->pointer = NULL;
}

void	init_length(t_arg *arg)
{
	arg->length->no = 0;
	arg->length->h = 0;
	arg->length->hh = 0;
	arg->length->l = 0;
	arg->length->ll = 0;
	arg->length->z = 0;
	arg->length->j = 0;
}

void	init_arg(t_arg *arg)
{
	arg->flags->minus = 0;
	arg->flags->plus = 0;
	arg->flags->zero = 0;
	arg->flags->htag = 0;
	arg->flags->space = 0;
	arg->width = 0;
	arg->precision = 0;
	arg->length = NULL;
	arg->specifier = 0;
}
