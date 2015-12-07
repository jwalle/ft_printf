/* == HEADER == */

#ifndef TEST_H
# define TEST_H

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <string.h>
#include <sys/shm.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#define MAX_LEN 42000
#define BUF_SIZE MAX_LEN + 1
#define NO_FD_OPENED -1
#define PRINTF_CASE_MSG(msg) "printf("msg")"

int				out_pipe[2];
char			out_buffer[10 * 1000];
char			*name;

typedef struct	s_cap_stdout
{
	int			target_fd;
	int 		saved_fd;
	int 		out_pipe[2];
	char 		buffer[10000];

}				t_cap_stdout;

int				debug;
t_cap_stdout	cap;
char			*printf_out;
int				printf_ret;
char			*ft_printf_out;
int				ft_printf_ret;

#define assert_printf(...) \
	capture_stdout(); \
  	printf_ret = printf(__VA_ARGS__); \
	printf_out = strdup(capture_stdout_get_buffer()); \
	if (debug) \
	{ \
		fprintf(stderr, "\nTEST: %s\n", name); \
		fprintf(stderr, "=====   printf_out  =====\nret: %d\n%s\n", printf_ret, printf_out); \
		fprintf(stderr,   "=========================\n"); \
	} \
  	ft_printf_ret = ft_printf(__VA_ARGS__); \
	ft_printf_out = strdup(capture_stdout_get_buffer()); \
	capture_stdout_destroy(); \
	if (debug) \
	{ \
		fprintf(stderr,   "\n===== ft_printf_out =====\nret: %d\n%s\n", ft_printf_ret, ft_printf_out); \
		fprintf(stderr,   "=========================\n"); \
	} \
	fprintf(stderr, "print1 = %s, print2 = %s\n", printf_out, ft_printf_out);
	//mt_assert_msg(memcmp(printf_out, ft_printf_out, strlen(printf_out) + 1) == 0, PRINTF_CASE_MSG(#__VA_ARGS__)); \
	//mt_assert_msg(printf_ret == ft_printf_ret, PRINTF_CASE_MSG(#__VA_ARGS__)); \
	free(printf_out); \
	free(ft_printf_out)

void		capture_stdout_destroy(void);
char		*capture_stdout_get_buffer(void);
static void	capture_unblock_fd(int fd);
void		capture_stdout(void);
void		capture_close_saved_stdout(void);

#endif