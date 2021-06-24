/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium-big-sort3.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/24 22:10:08 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/24 22:21:44 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	determine_steps(t_info *info, int *rotate_dir, int *steps, int total)
{
	info->first_steps_to_top = info->first_pos - 1;
	info->second_steps_to_top = (total + 1) - info->second_pos;
	*steps = info->first_steps_to_top;
	*rotate_dir = 1;
	if (info->second_steps_to_top < info->first_steps_to_top)
	{
		*steps = info->second_steps_to_top;
		*rotate_dir = 0;
	}
}

void	push_min_to_top(t_info *info, int total, t_game *game)
{
	int	i;
	int	steps;
	int	rotate_dir;

	if (info->second_pos == total)
		rra(game);
	else if (info->first_pos != 1)
	{
		i = 0;
		determine_steps(info, &rotate_dir, &steps, total);
		while (i < steps)
		{
			if (rotate_dir == 1)
				ra(game);
			else
				rra(game);
			i++;
		}
	}
}

void	push_max_to_top(t_final *final, int total, t_game *game)
{
	int	i;
	int	steps;
	int	rotate_dir;

	if (final->max_pos == 1 || final->max_pos == total)
	{
		if (final->max_pos == total)
			rrb(game);
		pa(game);
	}
	else
	{
		i = 0;
		if (final->max_pos > (total / 2))
		{
			rotate_dir = 0;
			steps = (total + 1) - final->max_pos;
		}
		else
		{
			rotate_dir = 1;
			steps = final->max_pos - 1;
		}
		while (i < steps)
		{
			if (rotate_dir == 1)
				rb(game);
			else
				rrb(game);
			i++;
		}
		pa(game);
	}
}
