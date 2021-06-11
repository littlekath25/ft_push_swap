# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/06/11 14:00:38 by kfu           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap
CC		= 	gcc
RM		=	rm -f
#CFLAGS	= 	-Wall -Wextra -Werror

S_SRC	= 	push_swap.c
S_PATH	=	src/
S_OBJ	=	$(S_SRC:%.c=$(S_PATH)%.o)

O_SRC	= 	actions.c\
			push.c\
			rev_rotate.c\
			rotate.c\
			swap.c
O_PATH	=	src/operations/
O_OBJ	=	$(O_SRC:%.c=$(O_PATH)%.o)

U_SRC	= 	error.c\
			input_checker.c\
			stack_functions.c\
			helpers.c
U_PATH	=	utils/
U_OBJ	=	$(U_SRC:%.c=$(U_PATH)%.o)

OBJ_FILES = $(S_OBJ) $(O_OBJ) $(U_OBJ)

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
