/* == HEADER == */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <string.h>
#include "test.h"


/*#define assert_printf(...) \
	printf(msg, ##__VA_ARGS__); \
	ft_printf(msg, ##__VA_ARGS__); \
	ft_printf("\n"); \
	printf("\n")
*/

void test_3()
{
	assert_printf("%ld%ld", 0, 42);
	assert_printf("%ld", (long)INT_MAX + 1);
	assert_printf("%ld", (long)INT_MIN - 1);
	assert_printf("%ld", LONG_MAX);
	assert_printf("%ld", LONG_MIN);
	assert_printf("%li%li", 0, 42);
	assert_printf("%li", (long)INT_MAX + 1);
	assert_printf("%li", (long)INT_MIN - 1);
	assert_printf("%li", LONG_MAX);
	assert_printf("%li", LONG_MIN);
	assert_printf("%lu, %lu", 0, ULONG_MAX);
	assert_printf("%lo, %lo", 0, ULONG_MAX);
	assert_printf("%lx, %lx", 0, ULONG_MAX);
	assert_printf("%lX, %lX", 0, ULONG_MAX);
	assert_printf("%lc, %lc", L'暖', L'ح');
	assert_printf("%ls, %ls", L"暖炉", L"لحم خنزير");
	assert_printf("%lO, %lO", 0, USHRT_MAX);
	assert_printf("%lU, %lU", 0, USHRT_MAX);
	assert_printf("%lD, %lD", 0, USHRT_MAX);
}

void test_2()
{
	assert_printf("%i", 42);
	assert_printf("%i", -42);
	assert_printf("before %i after", 42);
	assert_printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
	assert_printf("a%ib%ic%id", 1, -2, 3);
	printf("\noctal : \n");
	assert_printf("%o", 42);
	assert_printf("before %o after", 42);
	assert_printf("%o%o%o%o%o", 1, 100, 999, 42, 999988888);
	assert_printf("a%ob%oc%od", 0, 55555, 100000);
	printf("\nunsigned : \n");
	assert_printf("%u", 42);
	assert_printf("before %u after", 42);
	assert_printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888);
	assert_printf("a%ub%uc%ud", 0, 55555, 100000);
	assert_printf("%u", UINT_MAX);
	printf("\nHexa : \n");
	assert_printf("%x", 42);
	assert_printf("before %x after", 42);
	assert_printf("%x%x%x%x%x", 1, 100, 999, 42, 999988888);
	assert_printf("a%xb%xc%xd", 0, 55555, 100000);
	assert_printf("%x, %x", 0, UINT_MAX);
	assert_printf("%X", 42);
	assert_printf("before %X after", 42);
	assert_printf("%X%X%X%X%X", 1, 100, 999, 42, 999988888);
	assert_printf("a%Xb%Xc%Xd", 0, 55555, 100000);
	assert_printf("%X, %X", 0, UINT_MAX);
	printf("\nChar: \n");
	assert_printf("%c", 'c');
	assert_printf("%c%c", '4', '2');
	assert_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	assert_printf("%c", 0);
}

void test_1()
{
	printf("no conv :\n");
	assert_printf("This is a simple test.");
	assert_printf("This is a simple test.\nSecond sentence.\n");
	assert_printf("");
	assert_printf("\n");

	printf("\nsimple conv :\n");
	assert_printf("%s", "abc");
	assert_printf("111%s333", "222");
	assert_printf("%s333", "222");
	assert_printf("111%s", "222");
	//assert_printf("{%s}", 0);
	assert_printf("{%s}", "");

	printf("\nmulti conv :\n");
	
	assert_printf("111%s333%s555", "222", "444");
	assert_printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	assert_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");

	printf("\nconv_d :\n");
	assert_printf("%d", 42);
	assert_printf("%d", -42);
	assert_printf("before %d after", 42);
	assert_printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
	assert_printf("a%db%dc%dd", 1, -2, 3);
	assert_printf("%d", INT_MAX);
	assert_printf("%d", INT_MIN);

	printf("\nconv_p :\n");
	int	i;
	unsigned long l;
	char *str;
	assert_printf("%p", &i);
	assert_printf("%p", &l);
	assert_printf("%p", &str);
	assert_printf("%p", &strlen);
	assert_printf("%p", 0);

	printf("\npercent escape :\n");
	assert_printf("%%");
	assert_printf("aa%%bb");
	assert_printf("%%%%%%%%%%");
	assert_printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	//assert_printf("%");
	//assert_printf("% Zoooo");
	//assert_printf("{%}");
	//assert_printf("{% %}");

	printf("\nmix sdp percent :\n");
	assert_printf("s: %s, p: %p, d:%d", "a string", &test_1, 42);
	assert_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
}

/*
void	ft_assert(char *printf_out, char *ft_printf_out, int printf_ret, int ft_printf_ret)
{
	//fprintf(stderr, "print1 = %s\nprint2 = %s\n\n", printf_out, ft_printf_out); \
	if (!memcmp(printf_out, ft_printf_out, strlen(printf_out) + 1))
		fprintf(stderr, "OK\n");
	else
		fprintf(stderr, "PAS OK\n");
}*/
//mt_assert_msg(memcmp(printf_out, ft_printf_out, strlen(printf_out) + 1) == 0, PRINTF_CASE_MSG(#__VA_ARGS__)); \
//mt_assert_msg(printf_ret == ft_printf_ret, PRINTF_CASE_MSG(#__VA_ARGS__)); \


int main()
{

	int debug = 0;
	
	//name = "test1";

	printf("test 1 :\n");
	
	printf("->111 %s 333 |%s| 555\n", "222", "444");
	ft_printf("->111 %s 333 |%s| 555\n", "222", "444");


	test_1();
	printf("\ntest 2 :\n");
	test_2();
	printf("\ntest 3 :\n");
	test_3();
	//wprintf("wprintf = %c, %lc", L'暖', L'ح');
	
	return (0);
}