/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:12:34 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/27 12:39:26 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_game *game)
{
	ps_rev_rotate(&game->stack_a, &game->tail_a);
	if (game->print_operations)
		write(1, "rra\n", 4);
	game->operations++;
}

void	rrb(t_game *game)
{
	ps_rev_rotate(&game->stack_b, &game->tail_b);
	if (game->print_operations)
		write(1, "rrb\n", 4);
	game->operations++;
}

void	rrr(t_game *game)
{
	ps_rev_rotate(&game->stack_a, &game->tail_a);
	ps_rev_rotate(&game->stack_b, &game->tail_b);
	if (game->print_operations)
		write(1, "rrr\n", 4);
	game->operations++;
}
