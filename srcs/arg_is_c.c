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
	{
		if (arg->flags->zero)
	ft_putchar_ret(e, '0');
		else
			ft_putchar_ret(e, ' ');
	}
	ft_putchar_ret(e, c);
	while (arg->flags->minus && (arg->width >= (len + temp++)))
		ft_putchar_ret(e, ' ');
}

unsigned char *convert_wchar(unsigned char *str, wchar_t c, int len)
{
	if (len == 2)
	{
		str[0] = ((c >> 6) | 0xC0);
		str[1] = ((c & 0x3F) | 0x80);
	}
	else if (len == 3)
	{
		str[0] = ((c >> 12) | 0xE0);
		str[1] = (((c >> 6) & 0x3F) | 0x80);
		str[2] = ((c & 0x3F) | 0x80);
	}
	else if (len == 4)
	{
		str[0] = ((c >> 18) | 0xF0);
		str[1] = (((c >> 12) & 0x3F) | 0x80);
		str[2] = (((c >> 6) & 0x3F) | 0x80);
		str[3] = ((c & 0x3F) | 0x80);
	}
	str[4] = 0;
	return (str);
}

void ft_putwchar(t_env *e, unsigned char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, &str[i], 1);
		e->ret++;
		i++;
	}
}

int get_wchar_len(wchar_t c)
{
	unsigned int e;

	e = (unsigned int)c;
	if (e > 0 && e < 255)
		return (1);
	else if (e < 0x07FF)
		return (2);
	else if (e < 0xFFFF)
		return (3);
	else
		return (4);
}

void	arg_is_wchar(t_env *e, wchar_t w)
{
	unsigned char	str[5];
	int						len;

	if (w >= 0 && w <= 255)
	{
		ft_putchar_ret(e, w);
		return ;
	}
	ft_bzero_ptf(str, 5);
	len = get_wchar_len(w);
	convert_wchar(str, w, len);
	ft_putwchar(e, str, len);
	// ft_putstr_ret(e, (const char*)str);
}

void	arg_is_c(t_env *e, t_arg *arg, va_list list)
{
	wchar_t w;

	w = 0;
	//puts("plop");
	if (arg->length->l || arg->specifier == 'C')
	{
		w = va_arg(list, wchar_t);
		arg_is_wchar(e, w);
	}
	else
		print_char(e, arg, va_arg(list, int));
}
