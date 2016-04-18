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
LIB_DIR = ./libft/
LIB_INC = -I ./libft/includes
INC = -I./includes -I./libft/includes
LINK = -Llibft -lft
LINK_P = -L. -lftprintf
BLU = tput setaf 4
GRN = tput setaf 2
WHT = tput setaf 7
RESET = tput sgr 0

SRC_LIB = ft_putchar.o\
		ft_bzero.o\
		ft_isalpha.o\
		ft_memset.o\
		ft_strlen.o\
		ft_strcpy.o\
		ft_strncpy.o\
		ft_strcat.o\
		ft_strncat.o\
		ft_strlcat.o\
		ft_strchr.o\
		ft_strcmp.o\
		ft_strstr.o\
		ft_strnstr.o\
		ft_strncmp.o\
		ft_strrchr.o\
		ft_memcpy.o\
		ft_memccpy.o\
		ft_memmove.o\
		ft_strdup.o\
		ft_isdigit.o\
		ft_isalnum.o\
		ft_isascii.o\
		ft_isprint.o\
		ft_toupper.o\
		ft_tolower.o\
		ft_atoi.o\
		ft_memchr.o\
		ft_memcmp.o\
		ft_memalloc.o\
		ft_memdel.o\
		ft_strnew.o\
		ft_strdel.o\
		ft_strclr.o\
		ft_striter.o\
		ft_striteri.o\
		ft_strmap.o\
		ft_strmapi.o\
		ft_strequ.o\
		ft_strnequ.o\
		ft_strsub.o\
		ft_strjoin.o\
		ft_strtrim.o\
		ft_strsplit.o\
		ft_putnbr.o\
		ft_itoa.o\
		ft_putendl.o\
		ft_putstr.o\
		ft_putstr_fd.o\
		ft_putchar_fd.o\
		ft_putnbr_fd.o\
		ft_putendl_fd.o\
		ft_lstnew.o\
		ft_lstdelone.o\
		ft_lstadd.o\
		ft_lstmap.o\
		ft_lstiter.o\
		ft_lstdel.o\
		ft_lst_foreach.o\
		ft_lst_rec_free.o\
		ft_lst_push.o\

SRC_PRINTF =	ft_printf.o \
				ft_parse.o \
				ft_atoi_hex.o \
				arg_is_int.o \
				arg_is_u.o \
				arg_is_c.o \
				arg_is_string.o \
				arg_is_p.o \
				ft_init.o \
				ft_intlen.o \
				print_number.o \
				format.o \

COMPIL_OBJS = $(SRC_LIB) $(SRC_PRINTF)

# all: $(NAME)

# $(NAME):
# 	gcc -Wall -Wextra -Werror -c $(SRCS) $(INC)
# 	ar rc $(NAME) $(OBJ)

all: $(NAME)

$(NAME) : $(COMPIL_OBJS)
	@$(BLU)
	@echo "Making $(NAME)..."
	#$(CC) -c $(CFLAGS) $(SRCS) $(INC)
	mv $(COMPIL_OBJS) $(ODIR)
	ar rc $(NAME) $(addprefix $(ODIR), $(COMPIL_OBJS))
	ranlib $(NAME)
	@$(GRN)
	@echo "Done !"
	@$(RESET)

$(SRC_PRINTF) : %.o : $(SRCDIR)%.c
		mkdir -p $(ODIR)
		#@$(BLU)
		@echo "making objects..."
		@$(CC) $(CFLAGS) -c $(INC) $< -o $@
		@$(GRN)
		@echo "Done !"
		@$(RESET)

$(SRC_LIB) : %.o : $(LIB_DIR)%.c
	@$(BLU)
	@$(RESET)
	@echo "Compiling libft..."
	@$(CC) -c $(CFLAGS) $(LIB_INC) $< -o $@
	@$(GRN)
	@echo "Done !"
	@$(RESET)

clean:
	/bin/rm -f $(addprefix $(ODIR), $(OBJ)) 

fclean: clean
	#make -C ./libft fclean
	/bin/rm -rf $(NAME)
	/bin/rm -rf test

re: fclean all

test: re
	clang ./tests/test.c ./tests/capture.c -o test $(LINK_P) -I./tests
	#./test X 10

valtest: re
	gcc -fPIC $(CFLAGS) -o test test.c $(LINK) $(NAME) $(INC) -g
	valgrind ./test X 420
