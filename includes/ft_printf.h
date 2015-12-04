#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <wchar.h>
#include "../libft/libft.h"

#define HEXA "0123456789abcdef"
#define HEXA_MAJ "0123456789ABCDEF"
#define OCTAL "0x000000000000"
#define FLAGS "-+ #0"
#define LENGTH "hljz"
// #define LENGTH "hh h l ll j z"
#define SPECIFIER "sSpdDioOuUxXcC%"

// D = ld, O = lo, U = lu.

typedef	struct		s_flags
{
	int				minus;
	int				plus;
	int				zero;
	int				htag;
	int				space;
}					t_flags;

typedef	struct		s_length
{
	int				no;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				j;
	int				z;
}					t_length;

typedef	struct		s_arg
{
	t_flags			*flags;		// -+ #0
	t_length		*length;		// hh, l, ...
	int				width;		// number
	int				precision;  // number
	char			specifier; // sS...
	int				hex;
}					t_arg;

int		ft_printf(const char *format, ...);
char	*ft_strndup(char *str, int i);
int		parse(const char *format, t_arg *arg);
int		parse_two(const char *format, t_arg *arg, int n);
void	ft_atoi_hex(void *ptr);
void	arg_is_int(t_arg *arg, va_list list);
void	arg_is_u(t_arg *arg, va_list list);
void	arg_is_c(t_arg *arg, va_list list);
void	arg_is_string(t_arg *arg, va_list list);
void	arg_is_p(t_arg *arg, va_list list);
void	init_length(t_length *length);
void	init_arg(t_arg *arg);
int		ft_int_octal_len(unsigned long long n);
int		ft_int_hex_len(unsigned long long n);
int		ft_intlen(int n);
int		ft_ll_intlen(unsigned long long n);
int		ft_parse_len(unsigned long long n, char spe);
void	ft_putllnbr(long long int n);
void	parse_number(long long number, char spe);
int		format_output(int len, int signe, t_arg *arg);
void	print_hex(char spe);
void	ft_putnbr_octal(unsigned long long number);
void	ft_putnbr_hexa(unsigned long long number, char spe);
void	ft_putllunbr(unsigned long long int n);

#endif
