/* == HEADER == */

#include "ft_printf.h"

int		ft_int_octal_len(unsigned long long n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 8;
		i++;
	}
	//printf("n = %d, i = %d\n", n , i);
	return (i);
}

int		ft_int_hex_len(unsigned long long n)
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


int		ft_ll_intlen(unsigned long long n)
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

int		ft_parse_len(unsigned long long n, char spe)
{
	if (n == 0)
		return (1);
	if (spe == 'o')
		return (ft_int_octal_len(n));
	if (spe == 'x' || spe == 'X')
		return (ft_int_hex_len(n));
	return (ft_ll_intlen(n));
}