# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/05/25 21:06:23 by kfu           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap
CC		= 	gcc
RM		=	rm -f
#CFLAGS	= 	-Wall -Wextra -Werror

P_SRC	= 	sort.c\
			operations.c
P_PATH	=	sorting/
P_OBJ	=	$(P_SRC:%.c=$(P_PATH)%.o)

U_SRC	= 	error.c\
			input_checker.c\
			stack_functions.c
U_PATH	=	utils/
U_OBJ	=	$(U_SRC:%.c=$(U_PATH)%.o)

OBJ_FILES = $(P_OBJ) $(U_OBJ)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	cd libft && make
	$(CC) $(OBJ_FILES) -Llibft -lft -o $(NAME) -g3 -fsanitize=leak

%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $< -I includes/ -g3 -fsanitize=leak

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
