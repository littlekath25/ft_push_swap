/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:12:41 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/15 23:22:53 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_game *game)
{
	ps_rotate(&game->stack_a, &game->tail_a);
	write(1, "ra\n", 3);
	game->operations++;
}

void	rb(t_game *game)
{
	ps_rotate(&game->stack_b, &game->tail_b);
	write(1, "rb\n", 3);
	game->operations++;
}

void	rr(t_game *game)
{
	ps_rotate(&game->stack_a, &game->tail_a);
	ps_rotate(&game->stack_b, &game->tail_b);
	write(1, "rr\n", 3);
	game->operations++;
}
