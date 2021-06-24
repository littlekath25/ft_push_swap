/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium-sort2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 15:51:35 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/24 20:49:27 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max(t_game *game, t_final *final)
{
	t_stack			*ptr;
	int				i;
	int				min;

	get_min_max(game->stack_b, &min, &final->max, game->size_b);
	ptr = game->stack_b;
	if (ptr->number == final->max)
	{
		final->max_pos = 1;
		return ;
	}
	ptr = ptr->next;
	i = 2;
	while (ptr != game->stack_b)
	{
		if (ptr->number == final->max)
		{
			final->max_pos = i;
			break ;
		}
		ptr = ptr->next;
		i++;
	}
}

void	search_first_second(t_stack *ptr, t_info *info, t_game *game)
{
	int	i;

	i = 2;
	ptr = game->stack_a;
	if (ptr->number < info->chunk)
	{
		info->first = ptr->number;
		info->first_pos = 1;
	}
	ptr = ptr->next;
	while (ptr != game->stack_a)
	{
		if (info->first_pos == -1 && ptr->number <= info->chunk)
		{
			info->first = ptr->number;
			info->first_pos = i;
		}
		if (ptr->number <= info->chunk)
		{
			info->second = ptr->number;
			info->second_pos = i;
		}
		ptr = ptr->next;
		i++;
	}
}

int	get_first_second(t_stack *ptr, t_info *info, t_game *game)
{
	info->first_pos = -1;
	info->second_pos = -1;
	search_first_second(ptr, info, game);
	if (info->first_pos == -1 && info->second_pos == -1)
		return (0);
	return (1);
}

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

void	calculate_chunk(t_info *info, int max)
{
	info->chunk = (max / 5) * info->chunk_number;
	info->chunk_number++;
}
