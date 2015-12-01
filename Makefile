# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/05 11:39:59 by jwalle            #+#    #+#              #
#    Updated: 2015/09/15 17:18:54 by jwalle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Werror -Wextra
SRCDIR = ./srcs/
SRCO = $(SRC:.c=.o)
ODIR = ./objs/
LIB = ./libft/libft.a
INC = -I./includes -I./libft/includes
LINK = -Llibft -lft
LINK_P = -L. -lftprintf
BLU = tput setaf 4
GRN = tput setaf 2
WHT = tput setaf 7
RESET = tput sgr 0

SRC =	ft_printf.c \
		ft_parse.c \
		ft_atoi_hex.c \
		arg_is_int.c \
		arg_is_u.c \
		arg_is_c.c \
		arg_is_string.c \
		arg_is_p.c \
		ft_init.c \
		ft_intlen.c \
		print_number.c \

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(ODIR), $(OBJ))
SRCS = $(addprefix $(SRCDIR), $(SRC))

# all: $(NAME)

# $(NAME):
# 	gcc -Wall -Wextra -Werror -c $(SRCS) $(INC)
# 	ar rc $(NAME) $(OBJ)

all: $(LIB) $(NAME)

$(NAME) :
	@$(BLU)
	@echo "Making $(NAME)..."
	$(CC) -c $(CFLAGS) $(SRCS) $(INC)
	mv $(OBJ) $(ODIR)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	@$(GRN)
	@echo "Done !"
	@$(RESET)

$(ODIR)%.o : $(SRCDIR)%.c
	mkdir -p $(ODIR)
	@$(BLU)
	@echo "making objects..."
	$(CC) $(CFLAGS) -c $^ $(INC) -o $@
	@$(GRN)
	@echo "Done !"
	@$(RESET)

$(LIB): 
	@$(BLU)
	@echo "Compiling libft..."
	@make -C libft
	@$(GRN)
	@echo "Done !"
	@$(RESET)

clean:
	/bin/rm -f $(addprefix $(ODIR), $(OBJ)) 
	make -C ./libft clean

fclean: clean
	make -C ./libft fclean
	/bin/rm -rf $(NAME)
	/bin/rm -rf test

re: fclean all

test: re
	clang ./tests/test.c -o test $(LINK_P) $(LINK) 
	#./test X 10

valtest: re
	gcc -fPIC $(CFLAGS) -o test test.c $(LINK) $(NAME) $(INC) -g
	valgrind ./test X 420
