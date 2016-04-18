/* == HEADER == */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include "test.h"

#define DEC -123
#define INT 255
#define UNS (~0)

int test_max(void)
{

	//printf("\nlong long max :\n");


	assert_printf("%lld\n", LLONG_MAX);

	//printf("\nlong max :\n");
	
	assert_printf("%ld\n", LONG_MAX);


	assert_printf("\n%hhd\n", 150);

	assert_printf("\n%lld\n", LLONG_MIN);

	assert_printf("short int = %hi\n", 300000);

	assert_printf("signed char = %hhi\n", 42);

	assert_printf("signed char bites = %d\n", CHAR_MAX);

	assert_printf("\nintmax_t :\n");

	assert_printf("%jd , %jd , %jd\n", 0, -42, LLONG_MAX);

	assert_printf("\nsize_t :\n");

	assert_printf("%zd , %zd , %zd\n", 0, -42, LLONG_MAX);

	assert_printf(" --------------------------------- unsigned :\n");

	assert_printf("\nunsigned long long max :\n");

	assert_printf("%llu, %llu\n", 0, ULLONG_MAX);

	assert_printf("\n%llu , %llu\n", 0, 42);

	assert_printf("\nunsigned long max :\n");
	
	assert_printf("%lu\n", ULONG_MAX);

	assert_printf("\n%hhu\n", 350);

	assert_printf("\nULLONG -100 : \n");

	assert_printf("%llu\n", -100);

	assert_printf("\nunsigned short int = %hu\n", 300000);
	
	assert_printf("\nunsigned char = %hhu\n", 42);

	assert_printf("unsigned char bites = %u\n", UCHAR_MAX);

	assert_printf("\nintmax_t ju :\n");

	assert_printf("%ju , %ju , %ju\n", 0, -42, ULLONG_MAX);

	assert_printf("\nintmax_t ju :\n");

	assert_printf("%jo , %jo , %jo\n", 0, -42, ULLONG_MAX);

	assert_printf("\nintmax_t jx :\n");

	assert_printf("%jx , %jx , %jx\n", 0, -42, ULLONG_MAX);

	assert_printf("\nintmax_t #jX :\n");

	assert_printf("%#jX , %#jX , %#jX\n", 0, -42, ULLONG_MAX);

	assert_printf("\nsize_t :\n");

	assert_printf("%zu , %zu , %zu\n", 0, -42, ULLONG_MAX);

	assert_printf("%#0.12lc\n", (wchar_t)150);

}

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

					assert_printf(tp, DEC);
					strcpy(tp, prefix);
					strcat(tp, "6o |");
					assert_printf(tp, INT);
					strcpy(tp, prefix);
					strcat(tp, "6x |");
					assert_printf(tp, INT);
					strcpy(tp, prefix);
					strcat(tp, "6X |");
					assert_printf(tp, INT);
					strcpy(tp, prefix);
					strcat(tp, "6u |");
					assert_printf(tp, UNS);
					ft_printf("\n");
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}


  assert_printf("%10s\n", (char *) NULL);
  assert_printf("%-10s\n", (char *) NULL);
}



int main(int ac, char **av)
{
	ft_test();

	test_max();

	//test();
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

	// printf("->111 %s 333 %d 555\n", "222", 444);
	// ft_printf("->111 %d 333 %d 555\n", 222, 444);


	return (0);
}
