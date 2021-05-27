/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 15:52:36 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/27 20:34:09 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	init_game(t_game *game)
{
	game->size_a = 0;
	game->size_b = 0;
	game->stack_a = NULL;
	game->stack_b = NULL;
	game->tail_a = NULL;
	game->tail_b = NULL;
}

int		main(int argc, char **argv)
{
	t_game *game;

	if (argc > 1)
	{
		game = (t_game *)ft_calloc(1, sizeof(t_game));
		game->size_a = argc - 1;
		parse_and_check(argv, game);
		rotate(game, 'a');
		rotate(game, 'a');
		rotate(game, 'a');
		while (game->stack_a != NULL)
		{
			printf("%i\n", game->stack_a->number);
			game->stack_a = game->stack_a->next;
		}
		exit(0);
	}
	error_and_exit();
}
