# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/05/22 20:48:47 by kfu           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap
CC		= 	gcc
RM		=	rm -f
#CFLAGS	= 	-Wall -Wextra -Werror

M_SRC	= 	main.c
M_OBJ	=	$(M_SRC:%.c=%.o)

OBJ_FILES = $(M_OBJ)

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
