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

void		parse_uns(unsigned long long number, char spe)
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

unsigned long long check_unsigned(unsigned long long n, t_length *length)
{
	if (length->hh)
		return ((unsigned char)n);
	else if (length->h)
		return ((unsigned short int)n);
	else if (length->l)
		return ((unsigned long)n);
	else if (length->no)
		return ((unsigned int)n);
	return (n);
}


void	print_lluint(t_arg *arg, va_list list)
{
	int						len;
	unsigned long long int	n;
	int						temp;

	//n = va_arg(list, unsigned long long int);
	n = check_unsigned(va_arg(list, unsigned long long int), arg->length);
	len = ft_parse_len(n, arg->specifier);
	temp = format_output(len, 1, arg);
	parse_number(n, arg->specifier);
	while (arg->flags->minus && (arg->width > (len + temp++)))
		ft_putchar(' ');
}

/*
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
}*/

void	arg_is_u(t_arg *arg, va_list list)
{
	//if (arg->length->no || arg->length->h || arg->length->hh)
	//	print_uint(arg, list);
	//else if ( arg->length->l || arg->length->ll ||
	//	arg->length->z || arg->length->j)
		print_lluint(arg, list);
}