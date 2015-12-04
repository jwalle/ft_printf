#ifndef TEST_H
# define TEST_H

# include <fw.h>
# include <capture.h>
# include <unistd.h>
# include <string.h>

int				ft_printf(const char *format, ...);
char			*ft_printf_to_str(char *format, ...);
char			*printf_to_str(char *format, ...);

int				debug;
t_cap_stdout	cap;
char			*printf_out;
int				printf_ret;
char			*ft_printf_out;
int				ft_printf_ret;

#define PRINTF_CASE_MSG(msg) "printf("msg")"

#define assert_printf(...) \
	capture_stdout(); \
  	printf_ret = printf(__VA_ARGS__); \
	printf_out = strdup(capture_stdout_get_buffer()); \
	if (test->debug) \
	{ \
		fprintf(stderr, "\nTEST: %s\n", test->name); \
		fprintf(stderr, "=====   printf_out  =====\nret: %d\n%s\n", printf_ret, printf_out); \
		fprintf(stderr,   "=========================\n"); \
	} \
  	ft_printf_ret = ft_printf(__VA_ARGS__); \
	ft_printf_out = strdup(capture_stdout_get_buffer()); \
	capture_stdout_destroy(); \
	if (test->debug) \
	{ \
		fprintf(stderr,   "\n===== ft_printf_out =====\nret: %d\n%s\n", ft_printf_ret, ft_printf_out); \
		fprintf(stderr,   "=========================\n"); \
	} \
	mt_assert_msg(memcmp(printf_out, ft_printf_out, strlen(printf_out) + 1) == 0, PRINTF_CASE_MSG(#__VA_ARGS__)); \
	mt_assert_msg(printf_ret == ft_printf_ret, PRINTF_CASE_MSG(#__VA_ARGS__)); \
	free(printf_out); \
	free(ft_printf_out)

#endif