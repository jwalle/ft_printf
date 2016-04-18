/* == HEADER == */

#include "ft_printf.h"

char *ft_strndup(char *str, int i)
{
	char	*ret;

	if ((ret = (char *)malloc(sizeof(char) * i)) == NULL)
		return NULL;
	ret = ft_strncpy(ret, str, i);
	return (ret);
}

void	parse_length(t_arg *arg, char *len_parse)
{
	if (!len_parse)
	{
		arg->length->no = 1;
		return ;
	}
	arg->length->no = 0;
	if (!ft_strcmp(len_parse, "hh"))
		arg->length->hh = 1;
	else if (!ft_strcmp(len_parse, "h"))
		arg->length->h = 1;
	else if (!ft_strcmp(len_parse, "l"))
		arg->length->l = 1;
	else if (!ft_strcmp(len_parse, "ll"))
		arg->length->ll = 1;
	else if (!ft_strcmp(len_parse, "j"))
		arg->length->j = 1;
	else if (!ft_strcmp(len_parse, "z"))
		arg->length->z = 1;
	else
		//error_length(arg->length);
		printf("ERROR PARSE LENGTH\n");
}

int	is_hex(char spe)
{
	if (spe == 'x' || spe == 'X' || spe == 'o')
		return (1);
	return (0);
}

int parse_two(const char *format, t_arg *arg, int n)
{
	int 	i;
	char	*len_parse;

	i = 0;	
	init_length(arg->length);
	if (ft_strchr(LENGTH, format[i + n]))
	{
		while (ft_strchr(LENGTH, format[i + n]))
			i++;
		len_parse = ft_strndup((char *)format + n, i);
		n += i;
		parse_length(arg, len_parse);
		free(len_parse);
	}
	i = 0;
	if (ft_strchr(SPECIFIER, format[i + n]))
		arg->specifier = format[i++ + n];
	else
	{
		ft_putstr("No specifier specified.\n");
		exit (1);
	}
	n += i;
	arg->hex = is_hex(arg->specifier);
	//printf("flags = %s, width = %d, precision = %d, length = %s,  specifier = %c\n",
	//arg->flags, arg->width, arg->precision, arg->length, arg->specifier);
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