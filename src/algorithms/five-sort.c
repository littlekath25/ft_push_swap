/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   five-sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 21:06:06 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/15 23:20:53 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_min_max(t_game *game, int *min, int *max)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	*min = game->stack_a->number;
	*max = game->stack_a->number;
	ptr = game->stack_a;
	while (i < game->size_a)
	{
		if (ptr->number > *max)
			*max = ptr->number;
		if (ptr->number < *min)
			*min = ptr->number;
		ptr = ptr->next;
		i++;
	}
}

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

	get_min_max(game, &min, &max);
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
