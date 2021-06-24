/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small-sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 16:44:09 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/21 12:17:26 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_game *game)
{
	if (check_if_sorted(game->stack_a, game->tail_a))
		return ;
	while (game->stack_a != NULL)
	{
		if (game->stack_a->number > game->stack_a->next->number)
			sa(game);
		if (game->stack_a->number > game->tail_a->number)
			rra(game);
		pb(game);
	}
	while (game->stack_b != NULL)
	{
		if (game->stack_b->number < game->stack_b->next->number)
			sb(game);
		if (game->stack_b->number < game->tail_b->number)
			rb(game);
		pa(game);
	}
	small_sort(game);
}
