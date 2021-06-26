/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   three-sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 16:46:58 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/26 13:43:03 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_three_sort(int first, int second, int third, t_game *game)
{
	if (first < second)
	{
		if (first < third)
		{
			sa(game);
			ra(game);
		}
		else if (first > third)
			rra(game);
	}
	else if (first > second)
	{
		if (second > third)
		{
			sa(game);
			rra(game);
		}
		else if (second < third)
		{
			if (first < third)
				sa(game);
			else
				ra(game);
		}
	}
}

void	three_sort(t_game *game)
{
	int	first;
	int	second;
	int	third;

	if (check_if_sorted(game->stack_a) == 1)
		return ;
	first = game->stack_a->number;
	second = game->stack_a->next->number;
	third = game->tail_a->number;
	solve_three_sort(first, second, third, game);
}
