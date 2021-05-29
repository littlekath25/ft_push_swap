/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 16:01:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/29 19:05:34 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	struct s_stack	*previous;
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct s_game
{
	int		size_a;
	int		size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_game;


/* UTILS */
void	error_and_exit(void);
void	print_stack(t_stack *stack);

/* STACK UTILS */
t_stack	*new_node(int number);
void	node_addback(t_stack **stack, t_stack *new, t_game *game);

/* OPERATIONS */
void	swap(int *a, int *b);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_game *game, char c);
// void	rev_rotate(t_stack *stack);

void	parse_and_check(char **argv, t_game *game);

#endif