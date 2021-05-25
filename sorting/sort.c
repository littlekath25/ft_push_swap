/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 15:52:36 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/25 22:00:56 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	init_game(t_game *game)
{
	game->size = 0;
	game->stack_a = NULL;
	game->stack_b = NULL;
	game->tail = NULL;
}

int		main(int argc, char **argv)
{
	t_game *game;

	if (argc > 1)
	{
		game = (t_game *)ft_calloc(1, sizeof(t_game));
		game->size = argc - 1;
		parse_and_check(argv, game);
		exit(0);
	}
	error_and_exit();
}