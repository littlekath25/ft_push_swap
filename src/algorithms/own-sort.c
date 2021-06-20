/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   own-sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 16:44:09 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/20 14:33:25 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	rotate_till_min_top(t_game *game)
{
	int	min;
	int	max;

	get_min_max(game->stack_a, &min, &max, game->size_a);
	while (game->stack_a->number != min)
		ra(game);
}

void static	insert_correct_position(t_game *game)
{
	int max;
	int min;

	if (!game->stack_b)
		return ;
	get_min_max(game->stack_a, &min, &max, game->size_a);
	if (game->stack_b->number > max)
	{
		while (game->stack_a->number != max)
			ra(game);
		ra(game);
		pa(game);
	}
	else
	{
		if (game->stack_b->number < game->stack_a->number && game->stack_b->number < game->tail_a->number)
			rra(game);
		else if (game->stack_b->number > game->stack_a->number)
			ra(game);
		else if (game->stack_b->number < game->stack_a->number && game->stack_b->number > game->tail_a->number)
			pa(game);
	}
	insert_correct_position(game);
}

void	own_sort(t_game *game)
{
	while (check_if_sorted(game->stack_a, game->tail_a) == 0)
	{
		if (game->stack_a->next->number < game->stack_a->number)
			pb(game);
		ra(game);
	}
	insert_correct_position(game);
	rotate_till_min_top(game);
}
