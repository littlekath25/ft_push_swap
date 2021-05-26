/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 15:52:36 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/26 15:03:31 by kfu           ########   odam.nl         */
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
	game->tail = NULL;
}

int		main(int argc, char **argv)
{
	t_game *game;

	if (argc > 1)
	{
		game = (t_game *)ft_calloc(1, sizeof(t_game));
		game->size_a = argc - 1;
		parse_and_check(argv, game);
		push(&game->stack_a, &game->stack_b);
		while (game->stack_a != NULL)
		{
			printf("%i\n", game->stack_a->number);
			game->stack_a = game->stack_a->next;
		}
		printf("S2: %i\n", game->stack_b->number);
		exit(0);
	}
	error_and_exit();
}
