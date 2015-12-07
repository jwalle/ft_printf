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

#define RED     "\x1b[35m"
#define GREEN   "\x1b[34m"
#define RESET   "\x1b[0m"
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

void		ft_assert(char *printf_out, char *ft_printf_out, int printf_ret, int ft_printf_ret);

#define assert_printf(...) \
	capture_stdout(); \
  	printf_ret = printf(__VA_ARGS__); \
	printf_out = strdup(capture_stdout_get_buffer()); \
  	ft_printf_ret = ft_printf(__VA_ARGS__); \
	ft_printf_out = strdup(capture_stdout_get_buffer()); \
	capture_stdout_destroy(); \
	name = PRINTF_CASE_MSG(#__VA_ARGS__); \
	if (!memcmp(printf_out, ft_printf_out, strlen(printf_out) + 1)) \
	{ \
		fprintf(stderr, "%sOK --> %s", GREEN, RESET); \
	} \
	else \
	{ \
		fprintf(stderr, "\n\nTEST: %s%s;%s\n", RED, name, RESET); \
		fprintf(stderr, "\n=====   printf_out  =====\nret: %d\n%s\n", printf_ret, printf_out); \
		fprintf(stderr,   "=========================\n"); \
		fprintf(stderr,   "\n===== ft_printf_out =====\nret: %d\n%s\n", ft_printf_ret, ft_printf_out); \
		fprintf(stderr,   "=========================\n\n\n\n"); \
	} \
	//ft_assert(printf_out, ft_printf_out, printf_ret, ft_printf_ret); \
	free(printf_out); \
	free(ft_printf_out)

void		capture_stdout_destroy(void);
char		*capture_stdout_get_buffer(void);
static void	capture_unblock_fd(int fd);
void		capture_stdout(void);
void		capture_close_saved_stdout(void);

#endif