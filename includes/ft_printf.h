#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include "../libft/libft.h"

#define FLAGS "-+ #"
#define LENGTH "hljz"
#define SPECIFIER "dsS"

typedef	struct		s_arg
{
	char			*flags;		// -+ #0
	int				width;		// number
	int				precision;  // number
	char			*length;		// hh, l, ...
	char			*specifier; // sS...
}					t_arg;

typedef struct		s_spe
{
	char			*str;
	int				integer;
	unsigned int	u_integer;
	double			dble;
	char			character;
	void			*pointer;
	
}					t_spe;

int		ft_printf(const char *format, ...);
char	*ft_strndup(char *str, int i);
int		parse(const char *format, t_arg *arg);
int		parse_two(const char *format, t_arg *arg, int n);

#endif
