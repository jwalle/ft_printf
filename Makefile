# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/05 11:39:59 by jwalle            #+#    #+#              #
#    Updated: 2016/06/25 16:57:29 by jwalle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Werror -Wextra
SRCDIR = ./srcs/

SRCO = $(SRC:.c=.o)

ODIR = ./objs/

INC = -I./includes -I./libft/includes
LINK_P = -L. -lftprintf
BLU = tput setaf 4
RED = tput setaf 3
GRN = tput setaf 11
WHT = tput setaf 7
RESET = tput sgr 0

SRC =			ft_printf.c \
				ft_parse.c \
				ft_parse_two.c \
				ft_atoi_hex.c \
				arg_is_int.c \
				arg_is_u.c \
				arg_is_c.c \
				arg_is_wc.c \
				arg_is_string.c \
				arg_is_wstring.c \
				arg_is_p.c \
				ft_init.c \
				ft_intlen.c \
				print_number.c \
				format.c \
				misc.c \
				lib_one.c \
				lib_two.c \

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME) : $(OBJS)
	@$(RED)
	@echo "Making $(NAME)..."
	@$(GRN)
	ar rc $(NAME) $(addprefix $(ODIR), $(OBJ))
	ranlib $(NAME)
	@$(RED)
	@echo "Done !"
	@$(RESET)

$(ODIR)%.o : $(SRCDIR)%.c
		@mkdir -p $(ODIR)
		@$(GRN)
		@#echo "making objects..."
		$(CC) $(CFLAGS) -c $^ $(INC) -o $@
		@$(RED)
		@echo "Done !"
		@$(RESET)

clean:
	/bin/rm -f $(addprefix $(ODIR), $(OBJ))
	/bin/rm -rf $(ODIR)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
