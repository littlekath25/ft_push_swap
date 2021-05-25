/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 16:01:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/25 21:59:45 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct s_game
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tail;
	int		size;
}	t_game;


/* UTILS */
void	error_and_exit(void);

/* STACK UTILS */
t_stack	*new_node(int number);
void	node_addback(t_stack **stack, t_stack *new, t_game *game);

/* OPERATIONS */
// void	swap(t_stack *stack);
// void	push(t_stack *stack_a, t_stack *stack_b);
// void	rotate(t_stack *stack);
// void	rev_rotate(t_stack *stack);

void	parse_and_check(char **argv, t_game *game);

#endif