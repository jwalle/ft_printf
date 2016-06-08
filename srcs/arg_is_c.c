/* == HEADER == */

#include "ft_printf.h"

void print_char(t_env *e, t_arg *arg, char c)
{
	int		len;
	int		temp;
	int		i;

	temp = 0;
	i = 0;
	len = 1;
	if (arg->precision)
		len = arg->precision;
	while (arg->precision > (len + temp++) && len > temp)
		ft_putchar_ret(e, '0');
	while (!arg->flags->minus && (arg->width - temp++) >= len)
		ft_putchar_ret(e, ' ');
	ft_putchar_ret(e, c);
	while (arg->flags->minus && (arg->width >= (len + temp++)))
		ft_putchar_ret(e, ' ');
}

unsigned char *convert_wchar(wchar_t c)
{
	static unsigned char w_static[5];
	unsigned char *str;

	str = w_static;
	if (c<(1<<7))
		*str++ = (unsigned char)(c);
	else if (c<(1<<11))
	{
		*str++ = (unsigned char)((c>>6)|0xC0);
		*str++ = (unsigned char)((c&0x3F)|0x80);
	}
	else if (c<(1<<16))
	{
		*str++ = (unsigned char)((c>>12)|0xE0);
		*str++ = (unsigned char)(((c>>6)&0x3F)|0xE0);
		*str++ = (unsigned char)((c&0x3F)|0x80);
	}
	else if (c<(1<<21))
	{
		*str++ = (unsigned char)((c>>18)|0xE0);
		*str++ = (unsigned char)(((c>>12)&0x3F)|0xE0);
		*str++ = (unsigned char)(((c>>6)&0x3F)|0xE0);
		*str++ = (unsigned char)((c&0x3F)|0x80);
	}
	*str = 0;
	return (str);
}

void	arg_is_wchar(t_env *e, t_arg *arg, va_list list)
{
	wchar_t			w;
	unsigned char	*str;

	(void)arg;
	w = va_arg(list, wchar_t);
	str = convert_wchar(w);
	ft_putstr_ret(e, (const char*)str);
}

void	arg_is_c(t_env *e, t_arg *arg, va_list list)
{
	if (arg->length->l)
		arg_is_wchar(e, arg, list);
	print_char(e, arg, va_arg(list, int));
}
