/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium-sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 12:20:39 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/24 14:09:53 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_stack(t_game *game)
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

static void	push_min_to_top(t_medium_info *info, int total, t_game *game)
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

static void	push_max_to_top(t_medium_max *final, int total, t_game *game)
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
}

static void	push_back_final(t_game *game, int total)
{
	int				max_pos;
	t_medium_max	*final;

	if (game->stack_b == NULL)
		return ;
	final = (t_medium_max *)ft_calloc(1, sizeof(t_medium_max));
	total = game->size_b;
	get_max(game, final);
	push_max_to_top(final, total, game);
	free(final);
	push_back_final(game, total);
}

static void	push_chunks_to_stack(t_game *game, t_medium_info *info, int total, int max)
{
	t_stack	*ptr;
	int		ret;

	ptr = game->stack_a;
	if (ptr == NULL)
		return ;
	if (game->size_a == 1)
	{
		push_to_stack(game);
		return ;
	}
	calculate_chunk(info, max);
	ret = get_first_second(ptr, info, game);
	while (ret)
	{
		push_min_to_top(info, total, game);
		push_to_stack(game);
		ret = get_first_second(ptr, info, game);
	}
	push_chunks_to_stack(game, info, total, max);
}

void	medium_sort(t_game *game)
{
	int				total;
	int				min;
	int				max;
	t_medium_info	*info;

	info = (t_medium_info *)ft_calloc(1, sizeof(t_medium_info));
	get_min_max(game->stack_a, &min, &max, game->size_a);
	total = game->size_a;
	init_info(info);
	push_chunks_to_stack(game, info, total, max);
	push_back_final(game, total);
	free(info);
}
