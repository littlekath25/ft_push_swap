/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium-sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 12:20:39 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/22 16:49:51 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_stack(t_game *game)
{
	int	min;
	int	max;

	pb(game);
}

static void	push_to_top(t_medium_info *info, int total, t_game *game)
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

static void	push_chunks_to_stack(t_game *game, t_medium_info *info, int total)
{
	t_stack	*ptr;
	int		ret;

	ptr = game->stack_a;
	if (ptr == NULL)
		return ;
	calculate_chunk(info, total);
	ret = get_first_second(ptr, info, game);
	push_to_top(info, total, game);
	push_to_stack(game);
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
