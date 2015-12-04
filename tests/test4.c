/* == HEADER == */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <string.h>

#define assert_printf(msg, ...) \
	printf(msg, ##__VA_ARGS__); \
	ft_printf(msg, ##__VA_ARGS__); \
	ft_printf("\n"); \
	printf("\n")


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
	int i;
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

int main()
{
	printf("\n");

	//assert_printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	test_1();
	return (0);
}