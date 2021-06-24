/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium-big-sort2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 15:51:35 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/24 22:30:48 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_correct_position(t_game *game)
{
	int	min;
	int	max;

	if (game->stack_b == NULL)
		pb(game);
	else
	{
		get_min_max(game->stack_b, &min, &max, game->size_b);
		if (game->stack_a->number > max)
		{
			while (game->stack_b->number != min)
				rb(game);
			pb(game);
		}
		else if (game->stack_a->number < min)
		{
			pb(game);
			rrb(game);
		}
		else
			pb(game);
	}
}

void	get_max(t_game *game, t_final *final)
{
	t_stack	*ptr;
	int		i;
	int		min;

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

void	calculate_chunk(t_info *info, int max)
{
	info->chunk = (max / info->num_of_chunks) * info->chunk_number;
	info->chunk_number++;
}
