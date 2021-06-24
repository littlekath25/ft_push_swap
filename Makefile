# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/06/24 21:01:23 by katherine     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap
CC		= 	gcc
RM		=	rm -f
#CFLAGS	= 	-Wall -Wextra -Werror

S_SRC	= 	push_swap.c
S_PATH	=	src/
S_OBJ	=	$(S_SRC:%.c=$(S_PATH)%.o)

A_SRC	= 	small-sort.c\
			three-sort.c\
			five-sort.c\
			medium-sort.c\
			medium-sort2.c
A_PATH	=	src/algorithms/
A_OBJ	=	$(A_SRC:%.c=$(A_PATH)%.o)

O_SRC	= 	actions.c\
			push.c\
			rev_rotate.c\
			rotate.c\
			swap.c
O_PATH	=	src/operations/
O_OBJ	=	$(O_SRC:%.c=$(O_PATH)%.o)

U_SRC	= 	error.c\
			parse_and_check.c\
			stack_functions.c\
			helpers.c\
			init.c
U_PATH	=	src/utils/
U_OBJ	=	$(U_SRC:%.c=$(U_PATH)%.o)

OBJ_FILES = $(S_OBJ) $(A_OBJ) $(O_OBJ) $(U_OBJ)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	cd libft && make
	$(CC) $(OBJ_FILES) -Llibft -lft -o $(NAME) -fsanitize=address

%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $< -I includes/ -fsanitize=address

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
