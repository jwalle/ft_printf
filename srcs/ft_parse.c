/* == HEADER == */

#include "ft_printf.h"
#include <stdio.h> // PRINTF PLOPLPOPLPO

char *ft_strndup(char *str, int i)
{
	//int		n;
	char	*ret;

	//n = 0;
	if ((ret = (char *)malloc(sizeof(char) * i)) == NULL)
		return NULL;
	ret = ft_strncpy(ret, str, i);
	return (ret);
}

int parse_two(const char *format, t_arg *arg, int n)
{
	int i;

	i = 0;
	if (ft_strchr(LENGTH, format[i + n]))
	{
		while (ft_strchr(LENGTH, format[i + n]))
			i++;
		arg->length = ft_strndup((char *)format + n, i);
		n += i;
	}
	i = 0;
	if (ft_strchr(SPECIFIER, format[i + n]))
		arg->specifier = format[i++ + n];
	else
	{
		ft_putstr("No specifier apecified.\n");
		exit (1);
	}
	n += i;
	//printf("flags = %s, width = %d, precision = %d, length = %s,  specifier = %c\n",
	//	arg->flags, arg->width, arg->precision, arg->length, arg->specifier);
	return (n);
}

int	parse(const char *format, t_arg *arg)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (ft_strchr(FLAGS, format[i + n]))
	{
		if (format[i + n] == '-')
			arg->flags->minus = 1;
		if (format[i + n] == '+')
			arg->flags->plus = 1;
		if (format[i + n] == '0')
			arg->flags->zero = 1;
		if (format[i + n] == '#')
			arg->flags->htag = 1;
		if (format[i + n] == ' ')
			arg->flags->space = 1;
		i++;
	}
	n += i;
	i = 0;
	while (ft_isdigit(format[i + n]))
		i++;
	arg->width = ft_atoi((char *)format + n);
	n += i;
	i = 0;
	if (format[i + n] == '.')
	{
		i++;
		while (ft_isdigit(format[i + n]))
			i++;
		arg->precision = ft_atoi((char *)format + n + 1);
	}
	return (parse_two(format, arg, n + i));
}