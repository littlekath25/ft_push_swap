/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:12:34 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/03 14:36:38 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_game *game)
{
	ps_rev_rotate(&game->stack_a, &game->tail_a);
}

void	rrb(t_game *game)
{
	ps_rev_rotate(&game->stack_b, &game->tail_b);
}

void	rrr(t_game *game)
{
	ps_rev_rotate(&game->stack_a, &game->tail_a);
	ps_rev_rotate(&game->stack_b, &game->tail_b);
}