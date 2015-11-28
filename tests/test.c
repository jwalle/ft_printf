/* == HEADER == */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int main(int ac, char **av)
{
	if (ac == 2)
		ft_printf("%-+12.42llhs\n", av[1]);
	return (0);
}
