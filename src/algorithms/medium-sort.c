/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium-sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 12:20:39 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/21 15:33:42 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_first_second(t_stack *ptr, t_medium_info *info, t_game *game)
{
	int		i;

	i = 2;
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

static void	push_chunks_to_stack(t_game *game, t_medium_info *info, int total)
{
	t_stack	*ptr;

	ptr = game->stack_a;
	if (ptr == NULL)
		return ;
	calculate_cunk(info, total);
	get_first_second(ptr, info, game);
	printf("FIRST: %i - %i\n", info->first, info->first_pos);
	printf("SECOND: %i - %i\n", info->second, info->second_pos);
}

void	medium_sort(t_game *game)
{
	int				total;
	t_medium_info	*info;

	info = (t_medium_info *)ft_calloc(1, sizeof(t_medium_info));
	total = game->size_a;
	init_info(info);
	push_chunks_to_stack(game, info, total);
	free(info);
}
