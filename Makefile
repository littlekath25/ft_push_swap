# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/06/28 15:29:11 by katherine     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CHECKER =	checker
PUSH	= 	push_swap
CC		= 	gcc -g -fsanitize=address
RM		=	rm -f
CFLAGS	= 	-Wall -Wextra -Werror

S_SRC	= 	push_swap.c
S_PATH	=	src/
S_OBJ	=	$(S_SRC:%.c=$(S_PATH)%.o)

A_SRC	= 	small-sort/small-sort.c\
			three-sort/three-sort.c\
			five-sort/five-sort.c\
			medium-big-sort/medium-big-sort.c\
			medium-big-sort/medium-big-sort2.c\
			medium-big-sort/medium-big-sort3.c
A_PATH	=	src/algorithms/
A_OBJ	=	$(A_SRC:%.c=$(A_PATH)%.o)

O_SRC	= 	actions.c\
			push.c\
			rev_rotate.c\
			rotate.c\
			swap.c
O_PATH	=	src/operations/
O_OBJ	=	$(O_SRC:%.c=$(O_PATH)%.o)

U_SRC	= 	parse_and_check.c\
			stack_functions.c\
			helpers.c\
			init.c\
			get_next_line.c
U_PATH	=	src/utils/
U_OBJ	=	$(U_SRC:%.c=$(U_PATH)%.o)

C_SRC	= 	checker.c
C_PATH	=	src/checker/
C_OBJ	=	$(C_SRC:%.c=$(C_PATH)%.o)

OBJ_FILES = $(S_OBJ) $(A_OBJ) $(O_OBJ) $(U_OBJ)
CHECKER_FILES = $(C_OBJ) $(U_OBJ) $(O_OBJ)

all: $(PUSH) $(CHECKER)

$(PUSH): $(OBJ_FILES)
	make -C libft
	$(CC) $(OBJ_FILES) -Llibft -lft -o $(PUSH)

 $(CHECKER) : $(CHECKER_FILES)
	$(CC) $(CHECKER_FILES) -Llibft -lft -o $(CHECKER)

%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $< -I includes/

clean:
	$(RM) $(OBJ_FILES) $(C_OBJ)

fclean: clean
	$(RM) $(PUSH) $(CHECKER)
	make -C libft fclean

re: fclean all
