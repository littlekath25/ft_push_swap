/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 16:01:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/08 17:47:06 by kfu           ########   odam.nl         */
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
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct s_game
{
	int		size_a;
	int		size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tail_a;
	t_stack	*tail_b;
}	t_game;

/* UTILS */
void	error_and_exit(void);
void	print_stack(t_game *game);

/* STACK UTILS */
t_stack	*new_node(int number);
void	*node_addfront(t_stack **stack, t_stack *new, t_stack **tail);

/* OPERATIONS */
void	sa(t_game *game);
void	sb(t_game *game);
void	ss(t_game *game);
void	pa(t_game *game);
void	pb(t_game *game);
void	ra(t_game *game);
void	rb(t_game *game);
void	rr(t_game *game);
void	rra(t_game *game);
void	rrb(t_game *game);
void	rrr(t_game *game);

/* ACTIONS */
void	ps_swap(int *a, int *b);
void	ps_push(t_stack **src, t_stack **s_tail, \
t_stack **dest, t_stack **d_tail);
void	ps_rotate(t_stack **stack, t_stack **tail);
void	ps_rev_rotate(t_stack **stack, t_stack **tail);

void	parse_and_check(char **argv, t_game *game);

#endif