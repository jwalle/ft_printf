/* == HEADER == */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"


int main(int ac, char **av)
{
	if (ac >= 2)
	{
		//ft_printf("%-+12.42llhd\n", av[1]);
		ft_printf("%d, %s\n", 12, "plop");
		//printf("%g, %-12s\n", atof(av[1]), av[2]);
		printf(" ----------------------------------------------------------------------------------------------\n");
		printf("|%9s|%84s|\n", " ", "specifiers");
		printf(" ----------------------------------------------------------------------------------------------\n");
		printf("|%9s|%13s|%22s|%10s|%15s|%20s|\n", "length", "d i", "u o x X", "c", "s", "p");
		printf(" ----------------------------------------------------------------------------------------------\n");
		printf("|lg %6s|%13d|%u %o %x %-11X|%10d|%15s|%20p|\n", "", (int)744, (unsigned int)234, (unsigned int)234, (unsigned int)234, (unsigned int)234, 111, "plopiplop", av);
		ft_printf("|ft %6s|%13d|%u %o %x %-11X|%10d|%15s|%20p|\n", "", (int)744, (unsigned int)234, (unsigned int)234, (unsigned int)234, (unsigned int)234, 111, "plopiplop", av);
		//ft_printf("|ft %6s|%13d|%22u|%10d|%15s|%20p|\n", "", (int)744, (unsigned int)234, 111, "plopiplop", av);
		printf(" -------------------------------------------------------------------------------------------\n");
		printf("|lg %6s|%13hhd|%hhu %hho %hhx %-12hhX|%10s|%15s|%20s|\n", "hh", (unsigned char)'a', (unsigned char)'a', (unsigned char)'a', (unsigned char)'a', (unsigned char)'a', "", "", "");
		ft_printf("|ft %6s|%13hhd|%hhu %hho %hhx %-12hhX|%10s|%15s|%20s|\n", "hh", (unsigned char)'a', (unsigned char)'a', (unsigned char)'a', (unsigned char)'a', (unsigned char)'a', "", "", "");
		printf(" -------------------------------------------------------------------------------------------\n");
		printf("|lg %6s|%13hd|%22hu|%10s|%15s|%20s|\n", "h", (short int)12, (unsigned short int)89, "", "", "");
		ft_printf("|ft %6s|%13hd|%22hu|%10s|%15s|%20s|\n", "h", (short int)12, (unsigned short int)89, "", "", "");
		printf(" -------------------------------------------------------------------------------------------\n");
		printf("|lg %6s|%13ld|%22lu|%10s|%15s|%20s|\n", "l", (long int)42, (unsigned long int)75675665, "", "", "");
		ft_printf("|ft %6s|%13ld|%22lu|%10s|%15s|%20s|\n", "l", (long int)42, (unsigned long int)75675665, "", "", "");
		printf(" -------------------------------------------------------------------------------------------\n");
		printf("|lg %6s|%13lld|%22llu|%10s|%15s|%20s|\n", "ll", (long long int)123, (unsigned long long int)75674, "", "", "");
		ft_printf("|ft %6s|%13lld|%22llu|%10s|%15s|%20s|\n", "ll", (long long int)123, (unsigned long long int)75674, "", "", "");
		printf(" -------------------------------------------------------------------------------------------\n");
		printf("|lg %6s|%13jd|%22ju|%10s|%15s|%20s|\n", "j", (intmax_t)131351365, (uintmax_t)54346467, "", "", "");
		ft_printf("|ft %6s|%13jd|%22ju|%10s|%15s|%20s|\n", "j", (intmax_t)131351365, (uintmax_t)54346467, "", "", "");
		printf(" -------------------------------------------------------------------------------------------\n");
		printf("|lg %6s|%13zd|%22zu|%10s|%15s|%20s|\n", "z", (size_t)65, (size_t)65, "", "", "");
		ft_printf("|ft %6s|%13zd|%22zu|%10s|%15s|%20s|\n", "z", (size_t)65, (size_t)65, "", "", "");
		printf(" -------------------------------------------------------------------------------------------\n");
	}
	return (0);
}
