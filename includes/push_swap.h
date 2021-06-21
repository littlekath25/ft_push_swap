/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 16:01:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/21 14:58:32 by katherine     ########   odam.nl         */
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
	int		operations;
	int		size_a;
	int		size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tail_a;
	t_stack	*tail_b;
}	t_game;

typedef struct s_medium_uinfo
{
	int	first;
	int	second;
	int	first_pos;
	int	second_pos;
	int	chunk;
	int	chunk_number;
}	t_medium_info;

/* UTILS */
void	error_and_exit(void);
void	print_stack(t_game *game);
int		check_if_sorted(t_stack *stack, t_stack *tail);
void	is_all_digits(char *argv);
void	get_min_max(t_stack *stack, int *min, int *max, int size);

/* STACK UTILS */
t_stack	*new_node(int number);
void	*node_addback(t_stack **stack, t_stack *new, t_stack **tail);

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

// ACTIONS
void	ps_swap(int *a, int *b);
void	ps_push(t_stack **src, t_stack **s_tail, t_stack **dest, t_stack **d_tail);
void	ps_rotate(t_stack **stack, t_stack **tail);
void	ps_rev_rotate(t_stack **stack, t_stack **tail);

// OTHER
void	parse_and_check(char **argv, t_game *game);
void	init_info(t_medium_info *info);
void	calculate_cunk(t_medium_info *info, int total);

// ALGORITHMS
void	three_sort(t_game *game);
void	five_sort(t_game *game);
void	small_sort(t_game *game);
void	medium_sort(t_game *game);

#endif