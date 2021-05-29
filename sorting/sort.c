/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 15:52:36 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/29 16:32:22 by kfu           ########   odam.nl         */
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
}

int		main(int argc, char **argv)
{
	t_game *game;
	t_stack *ptr;

	if (argc > 1)
	{
		game = (t_game *)ft_calloc(1, sizeof(t_game));
		init_game(game);
		parse_and_check(argv, game);
		ptr = game->stack_a;
		while (ptr != NULL)
		{
			printf("S: %i\n", ptr->number);
			ptr = ptr->next;
		}
		exit(0);
	}
	error_and_exit();
}
