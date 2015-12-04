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
