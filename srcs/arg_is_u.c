/* == HEADER == */

#include "ft_printf.h"


void	print_hex(char spe)
{
	if (spe == 'o')
		ft_putchar('0');
	else if (spe == 'x')
		ft_putstr("0x");
	else if (spe == 'X')
		ft_putstr("0X");
}

void		parse_uns(unsigned int number, char spe)
{
	if (spe == 'o')
	{
		ft_putnbr_octal(number);
		return ;
	}
	else if (spe == 'x' || spe == 'X')
	{
		ft_putnbr_hexa(number, spe);
		return ;
	}
	ft_putllunbr(number);
}




void	print_lluint(t_arg *arg, va_list list)
{
	int						len;
	unsigned long long int	n;
	int						temp;

	temp = 0;
	n = va_arg(list, unsigned long long int);
	len = ft_parse_len(n, arg->specifier);
	while (arg->precision > (len + temp++))
		ft_putchar('0');
	while ((arg->width - temp++) >= len)
		ft_putchar(' ');
	parse_number(n, arg->specifier);
	while (arg->width >= (len + temp++))
		ft_putchar(' ');
}

void	print_uint(t_arg *arg, va_list list)
{
	int				len;
	unsigned int	n;
	int				temp;

	n = va_arg(list, unsigned int);
	len = ft_parse_len(n, arg->specifier);
	//printf("spe = %c, n = %d , len = %d\n", arg->specifier ,n , len);
	temp = format_output(len, 1, arg);
	parse_uns(n, arg->specifier);
	while (arg->flags->minus && (arg->width > (len - temp++)))
		ft_putchar(' ');
}

void	arg_is_u(t_arg *arg, va_list list)
{
	if (arg->length->no || arg->length->h || arg->length->hh)
		print_uint(arg, list);
	else if ( arg->length->l || arg->length->ll ||
		arg->length->z || arg->length->j)
		print_lluint(arg, list);
}