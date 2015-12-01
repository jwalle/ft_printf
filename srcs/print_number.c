/* == HEADER == */

#include "ft_printf.h"

void	ft_putllunbr(unsigned long long int n)
{
	// if (n == -2147483648)
	// {
	// 	ft_putstr("-214748364");
	// 	n = 8;
	// }
	if (n < 10)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putllnbr(n / 10);
		ft_putllnbr(n % 10);
	}
}

void	ft_putllnbr(long long int n)
{
	// if (n == -2147483648)
	// {
	// 	ft_putstr("-214748364");
	// 	n = 8;
	// }
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n < 10)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putllnbr(n / 10);
		ft_putllnbr(n % 10);
	}
}