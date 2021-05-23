/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 15:52:36 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/23 19:43:10 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static void	init_game(t_game *game)
{
	game->size = 0;
	game->stack_a = NULL;
	game->stack_b = NULL;
}

int		main(int argc, char **argv)
{
	t_game *game;
	int i;

	i = 0;
	if (argc > 1)
	{
		game = (t_game *)ft_calloc(1, sizeof(t_game));
		game->size = argc - 1;
		input_checker_parser(argc, argv, game);
		game->stack_b = (int *)ft_calloc(argc, sizeof(int));
		while (i < game->size)
		{
			printf("STACK: %i\n", game->stack_a[i]);
			i++;
		}
		exit(0);
	}
	error_and_exit();
}