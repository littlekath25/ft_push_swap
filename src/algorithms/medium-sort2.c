/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium-sort2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 15:51:35 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/22 16:49:42 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	search_first_second(t_stack *ptr, t_medium_info *info, t_game *game)
{
	int	i;

	i = 2;
	ptr = game->stack_a;
	if (ptr->number <= info->chunk)
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

int	get_first_second(t_stack *ptr, t_medium_info *info, t_game *game)
{
	info->first_pos = -1;
	info->second_pos = -1;
	search_first_second(ptr, info, game);
	if (info->first_pos == -1 && info->second_pos == -1)
		return (0);
	return (1);
}

void	determine_steps(t_medium_info *info, int *rotate_dir, int *steps, int total)
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
