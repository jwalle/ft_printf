/* == HEADER == */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"


int main()
{
	int i;

	i = 10;
	ft_putendl("\n----");
	ft_putnbr(printf("\n%s%%%c\n", "23", 48));
	ft_putendl("\n----");
	//ft_putnbr(ft_printf("\n%s%%%c\n", "23", 48));
	//ft_putendl("\n----");
	ft_putnbr(ft_printf("\n%s\n", "abc"));
	ft_putendl("\n----");
	ft_putnbr(printf("\n%s\n", "abc"));
	ft_putendl("\n----");
	ft_putnbr(ft_printf("\n111%s333\n", "222"));
	ft_putendl("\n----");
	ft_putnbr(printf("\n111%s333\n", "222"));
	ft_putendl("\n----");
	ft_putnbr(ft_printf("\n%s333\n", "222"));
	ft_putendl("\n----");
	ft_putnbr(printf("\n%s333\n", "222"));
	ft_putendl("\n----");
	ft_putnbr(ft_printf("\n111%s\n", "222"));
	ft_putendl("\n----");
	ft_putnbr(printf("\n111%s\n", "222"));
	ft_putendl("\n----");
	//ft_putnbr(ft_printf("\n{%s}\n", NULL));
	//ft_putendl("\n----");
	ft_putnbr(printf("\n{%s}\n", NULL));
	ft_putendl("\n----");
	ft_putnbr(ft_printf("\n{%s}\n", ""));
	ft_putendl("\n----");
	ft_putnbr(printf("\n{%s}\n", ""));
	// ft_putendl("\n----");
	// ft_putnbr(ft_printf("%"));
	// ft_putendl("\n----");
	// ft_putnbr(printf("%"));
	// ft_putendl("\n----");
	// ft_putnbr(ft_printf("{%}"));
	// ft_putendl("\n----");
	// ft_putnbr(printf("{%}"));
	// ft_putendl("\n----");
	// ft_putnbr(ft_printf("% Zoooo"));
	// ft_putendl("\n----");
	// ft_putnbr(printf("% Zoooo"));
	// ft_putendl("\n----");
	// ft_putnbr(ft_printf("{% %}"));
	// ft_putendl("\n----");
	// ft_putnbr(printf("{% %}"));
	ft_putendl("\n----");
	ft_putnbr(ft_printf("%d", 9999));
	ft_putendl("\n----");
	ft_putnbr(printf("%d", 9999));
	ft_putendl("\n----");
	ft_putnbr(ft_printf("%S", L"米\n"));
	ft_putendl("\n----");
	ft_putnbr(printf("%S", L"米\n"));
	ft_putendl("\n----");
	ft_putnbr(ft_printf("%p\n", &i));
	ft_putendl("\n----");
	ft_putnbr(printf("%p\n", &i));
	ft_putendl("\n----");
	ft_putnbr(ft_printf("%x\n", 970));
	ft_putendl("\n----");
	ft_putnbr(printf("%x\n", 970));
	ft_putendl("\n----");
	ft_putnbr(ft_printf("%S", L"米"));
	ft_putendl("\n----");
	ft_putnbr(printf("%S", L"米"));
	ft_putendl("\n----");
	ft_putnbr(ft_printf("%o\n", 970));
	ft_putendl("\n----");
	ft_putnbr(printf("%o\n", 970));
	ft_putendl("\n----");
	ft_putnbr(ft_printf("%C", L'猫'));
	ft_putendl("\n----");
	ft_putnbr(printf("%C", L'猫'));
	ft_putendl("\n----");
	// ft_putnbr(ft_printf("%U\n", 18446744073709551615));
	// ft_putendl("\n----");
	// ft_putnbr(printf("%U\n", 18446744073709551615));
	// ft_putendl("\n----");
}
