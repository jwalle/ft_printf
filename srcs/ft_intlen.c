/* == HEADER == */

#include "ft_printf.h"

int		ft_int_octal_len(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 8;
		i++;
	}
	return (i);
}

int		ft_int_hex_len(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int		ft_intlen(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_parse_len(int n, char spe)
{
	if (spe == 'o')
		return (ft_int_octal_len(n));
	if (spe == 'x' || spe == 'X')
		return (ft_int_hex_len(n));
	return (ft_intlen(n));
}