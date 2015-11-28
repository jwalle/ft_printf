#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include "../libft/libft.h"

#define FLAGS "%-"
#define TYPE "sS"

typedef	struct		s_arg
{
	char			*flags;
	char			*types;
}					t_arg;

int	ft_printf(const char *format, ...);

#endif
