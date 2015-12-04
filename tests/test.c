/* == HEADER == */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

#define DEC -123
#define INT 255
#define UNS (~0)

void test(void)
{
	int i, j, k, l;
	char buf[7];
	char *prefix = buf;
	char tp[20];
	i = 0;

	puts("\nFormatted output test printf");
	printf("prefix	   6d      6o      6x      6X      6u\n");
	strcpy(prefix, "%");
	while (i < 2)
	{
	  	j = 0;
	    while (j < 2)
	    {
	    	k = 0;
	    	while (k < 2)
			{
				l = 0;
				while (l < 2)
				{
		  			strcpy(prefix, "%");
		  			if (i == 0) strcat(prefix, "-");
		  			if (j == 0)
		  				strcat(prefix, "+");
					if (k == 0)
						strcat(prefix, "#");
					if (l == 0)
						strcat(prefix, "0");
					printf("%5s |", prefix);
					strcpy(tp, prefix);
					strcat(tp, "6d |");
					printf(tp, DEC);
					strcpy(tp, prefix);
					strcat(tp, "6o |");
					printf(tp, INT);
					strcpy(tp, prefix);
					strcat(tp, "6x |");
					printf(tp, INT);
					strcpy(tp, prefix);
					strcat(tp, "6X |");
					printf(tp, INT);
					strcpy(tp, prefix);
					strcat(tp, "6u |");
					printf(tp, UNS);
					printf("\n");
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}


	printf("\nlong long max :\n");


	printf("%lld\n", LLONG_MAX);
	ft_printf("%lld\n", LLONG_MAX);

	printf("\nlong max :\n");
	
	printf("%ld\n", LONG_MAX);
	ft_printf("%ld\n", LONG_MAX);


	printf("\n%hhd\n", 150);
	ft_printf("%hhd\n", 150);

	printf("\n%lld\n", LLONG_MIN);
	ft_printf("\n%lld\n", LLONG_MIN);

	printf("short int = %hi\n", 300000);
	ft_printf("short int = %hi\n", 300000);
	printf("signed char = %hhi\n", 42);

	printf("signed char bites = %d\n", CHAR_MAX);

	printf("\nintmax_t :\n");

	printf("%jd , %jd , %jd\n", 0, -42, LLONG_MAX);
	ft_printf("%jd , %jd , %jd\n", 0, -42, LLONG_MAX);

	printf("\nsize_t :\n");

	printf("%zd , %zd , %zd\n", 0, -42, LLONG_MAX);
	ft_printf("%zd , %zd , %zd\n", 0, -42, LLONG_MAX);

	printf(" --------------------------------- unsigned :\n");

	printf("\nunsigned long long max :\n");

	printf("%llu, %llu\n", 0, ULLONG_MAX);
	ft_printf("%llu, %llu\n", 0, ULLONG_MAX);

	printf("\n%llu , %llu\n", 0, 42);
	ft_printf("%llu , %llu\n", 0, 42);

	printf("\nunsigned long max :\n");
	
	printf("%lu\n", ULONG_MAX);
	ft_printf("%lu\n", ULONG_MAX);


	printf("\n%hhu\n", 350);
	ft_printf("%hhu\n", 350);

	printf("\nULLONG -100 : \n");

	printf("%llu\n", -100);
	ft_printf("%llu\n", -100);

	printf("\nunsigned short int = %hu\n", 300000);
	ft_printf("unsigned short int = %hu\n", 300000);
	
	printf("\nunsigned char = %hhu\n", 42);
	ft_printf("unsigned char = %hhu\n", 42);

	printf("unsigned char bites = %u\n", UCHAR_MAX);

	printf("\nintmax_t ju :\n");

	printf("%ju , %ju , %ju\n", 0, -42, ULLONG_MAX);
	ft_printf("%ju , %ju , %ju\n", 0, -42, ULLONG_MAX);

	printf("\nintmax_t ju :\n");

	printf("%jo , %jo , %jo\n", 0, -42, ULLONG_MAX);
	ft_printf("%jo , %jo , %jo\n", 0, -42, ULLONG_MAX);

	printf("\nintmax_t jx :\n");

	printf("%jx , %jx , %jx\n", 0, -42, ULLONG_MAX);
	ft_printf("%jx , %jx , %jx\n", 0, -42, ULLONG_MAX);

	printf("\nintmax_t #jX :\n");

	printf("%#jX , %#jX , %#jX\n", 0, -42, ULLONG_MAX);
	ft_printf("%#jX , %#jX , %#jX\n", 0, -42, ULLONG_MAX);

	printf("\nsize_t :\n");

	printf("%zu , %zu , %zu\n", 0, -42, ULLONG_MAX);
	ft_printf("%zu , %zu , %zu\n", 0, -42, ULLONG_MAX);

	printf("%#0.12lc\n", (wchar_t)150);


 // printf("%10s\n", (char *) NULL);
 // printf("%-10s\n", (char *) NULL);
}

void ft_test(void)
{
	int i, j, k, l;
	char buf[7];
	char *prefix = buf;
	char tp[20];
	i = 0;

	puts("\nFormatted output test FT_PRINTF");
	ft_printf("prefix	   6d      6o      6x      6X      6u\n");
	strcpy(prefix, "%");
	while (i < 2)
	{
	  	j = 0;
	    while (j < 2)
	    {
	    	k = 0;
	    	while (k < 2)
			{
				l = 0;
				while (l < 2)
				{
		  			strcpy(prefix, "%");
		  			if (i == 0) strcat(prefix, "-");
		  			if (j == 0)
		  				strcat(prefix, "+");
					if (k == 0)
						strcat(prefix, "#");
					if (l == 0)
						strcat(prefix, "0");
					ft_printf("%5s |", prefix);
					strcpy(tp, prefix);
					strcat(tp, "6d |");
					//printf("PLOP = {%s}\n", tp);

					ft_printf(tp, DEC);
					strcpy(tp, prefix);
					strcat(tp, "6o |");
					ft_printf(tp, INT);
					strcpy(tp, prefix);
					strcat(tp, "6x |");
					ft_printf(tp, INT);
					strcpy(tp, prefix);
					strcat(tp, "6X |");
					ft_printf(tp, INT);
					strcpy(tp, prefix);
					strcat(tp, "6u |");
					ft_printf(tp, UNS);
					ft_printf("\n");
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
  printf("%10s\n", (char *) NULL);
  printf("%-10s\n", (char *) NULL);
}


int main(int ac, char **av)
{
	ft_test();

	test();
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
		ft_printf("|ft %6s|%13d|%u %o %x %-11X|%10d|%15s|%20p|\n", "", (int)744, (unsigned int)234, (unsigned int)234, (unsigned int)234, (unsigned int)234, 111, "", av);
		//ft_printf("|ft %6s|%13d|%22u|%10d|%15s|%20p|\n", "", (int)744, (unsigned int)234, 111, "plopiplop", av);
		printf(" -------------------------------------------------------------------------------------------\n");
		printf("|lg %6s|%13hhd|%hhu %hho %hhx %-12hhX|%10s|%15s|%20s|\n", "hh", (signed char)'a', (unsigned char)'a', (unsigned char)'a', (unsigned char)'a', (unsigned char)'a', "", "", "");
		ft_printf("|ft %6s|%13hhd|%hhu %hho %hhx %-12hhX|%10s|%15s|%20s|\n", "hh", (signed char)'a', (unsigned char)'a', (unsigned char)'a', (unsigned char)'a', (unsigned char)'a', "", "", "");
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
	

	printf("%%u | %% u | %%+u | %%.10u | %%.10u :\n");
	unsigned int a = 212672;
	printf("%u | % u | %+u | %.10u\n", a, a, a, a);
	ft_printf("%u | % u | %+u | %.10u\n", a, a, a, a);
	printf("\n");

	printf("%%d      |     %% d | %%+d | %%.10d | %%-d | %%0d | %% .10d | %%+.10d :\n");
	int b = -987824;
	printf("%d | % d | %+d | %.10d | %-d | %0d | % .10d | %+.10d\n", b, -b, b, b, b, b, b, b, b);
	ft_printf("%d | % d | %+d | %.10d | %-d | %0d | % .10d | %+.10d\n", b, -b, b, b, b, b, b, b, b);
	printf("\n");

	printf("%%llu :\n");
	long long unsigned int c = 2855454212672;
	printf("%llu\n", c);
	ft_printf("%llu\n", c);
	printf("\n");

	printf("%%lld :\n");
	long long int d = 2855454212672;
	printf("%lld\n", d);
	ft_printf("%lld\n", d);
	printf("\n");

	printf("%%c :\n");
	char e = '*';
	printf("%c\n", e);
	ft_printf("%c\n", e);
	printf("\n");
	
	printf("%%s :\n");
	char *f = "oui-oui";
	printf("%s\n", f);
	ft_printf("%s\n", f);
	printf("\n");

	printf("%%p :\n");
	printf("%p\n", &f);
	ft_printf("%p\n", &f);
	printf("\n");
	}

	return (0);
}
