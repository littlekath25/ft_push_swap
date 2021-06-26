/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 16:01:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/26 13:42:21 by katherine     ########   odam.nl         */
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
	int		min;
	int		max;
	int		size_a;
	int		size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tail_a;
	t_stack	*tail_b;
}	t_game;

typedef struct s_info
{
	int	first;
	int	second;
	int	first_pos;
	int	second_pos;
	int	chunk;
	int	chunk_size;
	int	num_of_chunks;
	int	chunk_number;
	int	first_steps_to_top;
	int	second_steps_to_top;
}	t_info;

typedef struct s_final
{
	int	max;
	int	max_pos;
	int	steps_to_top;
	int	direction;
}	t_final;

void	parse_and_check(char **argv, t_game *game);

/* UTILS */
void	error_and_exit(void);
void	print_stack(t_game *game);
int		check_if_sorted(t_stack *stack);
void	is_all_digits(char *argv);
void	get_min_max(t_stack *stack, int *min, int *max, int size);

// INITIALIZE STRUCTS
void	init_game(t_game *game, int argc);
void	init_info(t_info *info);

// STACK FUNCTIONS
t_stack	*new_node(int number);
void	node_addback(t_stack **stack, t_stack *new, t_stack **tail);

// OPERATIONS
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
void	ps_push(t_stack **src, t_stack **s_tail, \
t_stack **dest, t_stack **d_tail);
void	ps_rotate(t_stack **stack, t_stack **tail);
void	ps_rev_rotate(t_stack **stack, t_stack **tail);

// ALGORITHMS
void	three_sort(t_game *game);
void	five_sort(t_game *game);
void	small_sort(t_game *game);
void	medium_big_sort(t_game *game);

// ALGORITHMS FUNCTIONS
void	calculate_chunk(t_info *info, int min);
void	determine_steps(t_info *info, int *rotate_dir, int *steps, int total);
int		get_first_second(t_stack *ptr, t_info *info, t_game *game);
void	get_max(t_game *game, t_final *final);
void	push_correct_position(t_game *game);
void	push_min_to_top(t_info *info, int total, t_game *game);
void	push_max_to_top(t_final *final, int total, t_game *game);

#endif