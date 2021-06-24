/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   five-sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 21:06:06 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/20 13:59:34 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_max(t_game *game, int min, int max)
{
	while (game->size_b < 2)
	{
		if (game->stack_a->number == max || game->stack_a->number == min)
			pb(game);
		else if (game->tail_a->number == max || game->tail_a->number == min)
		{
			rra(game);
			pb(game);
		}
		else
		{
			ra(game);
			continue ;
		}
	}
}

void	five_sort(t_game *game)
{
	int		max;
	int		min;

	get_min_max(game->stack_a, &min, &max, game->size_a);
	push_min_max(game, min, max);
	three_sort(game);
	while (game->stack_b != NULL)
	{
		if (game->stack_b->number == max)
		{
			pa(game);
			ra(game);
		}
		else if (game->stack_b->number == min)
			pa(game);
	}
}
