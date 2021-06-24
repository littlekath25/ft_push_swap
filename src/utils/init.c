/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/24 20:57:34 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/24 20:57:53 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_game(t_game *game, int argc)
{
	game->operations = 0;
	game->size_a = argc - 1;
	game->size_b = 0;
	game->stack_a = NULL;
	game->stack_b = NULL;
	game->tail_a = NULL;
	game->tail_b = NULL;
}

void	init_info(t_info *info)
{
	info->chunk_number = 1;
	info->first_pos = -1;
	info->second_pos = -1;
}
