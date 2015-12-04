/* == HEADER == */

#include "ft_printf.h"

void	ft_putllunbr(unsigned long long int n)
{
	if (n < 10)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putllunbr(n / 10);
		ft_putllunbr(n % 10);
	}
}

void	ft_putnbr_octal(unsigned long long number)
{
	char				*octal;
	int					i;

	if (number == 0)
	{
		ft_putchar('0');
		return ;
	}
	i = ft_int_octal_len(number);
	octal = ft_strnew(i);
	ft_bzero(octal, i + 1);
	while (number)
	{
		octal[--i] = number % 8 + '0';
		number = number / 8;
	}
	ft_putstr(octal);
}

void	ft_putnbr_hexa(unsigned long long number, char spe)
{
	char				*base;
	char				*hex;
	int					i;


	if (number == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (spe == 'x')
		base = HEXA;
	if (spe == 'X')
		base = HEXA_MAJ;
	i = ft_int_hex_len(number);
	hex = ft_strnew(i);
	ft_bzero(hex, i + 1);
	while (number)
	{
		hex[--i] = base[number % 16];
		number = number / 16;
	}
	ft_putstr(hex);
}
