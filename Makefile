# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/05 11:39:59 by jwalle            #+#    #+#              #
#    Updated: 2016/05/31 17:42:39 by jwalle           ###   ########.fr        #
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
GRN = tput setaf 2
WHT = tput setaf 7
RESET = tput sgr 0

SRC_PRINTF =	ft_printf.o \
				ft_parse.o \
				ft_atoi_hex.o \
				arg_is_int.o \
				arg_is_u.o \
				arg_is_c.o \
				arg_is_wc.o \
				arg_is_string.o \
				arg_is_p.o \
				ft_init.o \
				ft_intlen.o \
				print_number.o \
				format.o \
				misc.o \
				lib_one.o \
				lib_two.o \

all: $(NAME)

$(NAME) : $(SRC_PRINTF)
	@$(BLU)
	@echo "Making $(NAME)..."
	#$(CC) -c $(CFLAGS) $(SRCS) $(INC)
	mv $(SRC_PRINTF) $(ODIR)
	ar rc $(NAME) $(addprefix $(ODIR), $(SRC_PRINTF))
	ranlib $(NAME)
	@$(GRN)
	@echo "Done !"
	@$(RESET)

$(SRC_PRINTF) : %.o : $(SRCDIR)%.c
		mkdir -p $(ODIR)
		@$(BLU)
		@echo "making objects..."
		@$(CC) $(CFLAGS) -c $(INC) $< -o $@
		@$(GRN)
		@echo "Done !"
		@$(RESET)

clean:
	/bin/rm -f $(addprefix $(ODIR), $(OBJ))

fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf test

re: fclean all

test: re
	clang ./tests/test.c ./tests/capture.c -o test $(LINK_P) -I./tests
	#./test X 10

valtest: re
	gcc -fPIC $(CFLAGS) -o test test.c $(LINK) $(NAME) $(INC) -g
	valgrind ./test X 420
