/* == HEADER == */

#include "ft_printf.h"
#include "libft.h"

int main(int ac, char **av)
{
	if (ac == 2)
		ft_printf(av[1]);
	return (0);
}
