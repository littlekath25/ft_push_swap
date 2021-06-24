/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 15:52:36 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/24 14:13:17 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_game(t_game *game, int argc)
{
	game->operations = 0;
	game->size_a = argc - 1;
	game->size_b = 0;
	game->stack_a = NULL;
	game->stack_b = NULL;
	game->tail_a = NULL;
	game->tail_b = NULL;
}

void	push_swap(t_game *game)
{
	if (check_if_sorted(game->stack_a, game->tail_a) == 1)
		exit(0);
	if (game->size_a == 2)
		sa(game);
	if (game->size_a == 3)
		three_sort(game);
	if (game->size_a == 5)
		five_sort(game);
	if (game->size_a > 5 && game->size_a < 101)
		medium_sort(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		is_all_digits(argv[1]);
		exit (0);
	}
	if (argc > 2)
	{
		game = (t_game *)ft_calloc(1, sizeof(t_game));
		init_game(game, argc);
		parse_and_check(argv, game);
		push_swap(game);
		print_stack(game);
		exit(0);
	}
	error_and_exit();
}
