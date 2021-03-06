/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 15:52:36 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/28 15:43:35 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_game *game)
{
	if (check_if_sorted(game->stack_a) == 1)
		exit(0);
	else if (game->size_a == 2)
		sa(game);
	else if (game->size_a == 3)
		three_sort(game);
	else if (game->size_a <= 5)
		five_sort(game);
	else if (game->size_a < 501)
		medium_big_sort(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_and_exit();
	init_game(game, argc);
	if (argc == 2)
		is_all_digits(argv[1]);
	if (argc > 2)
	{
		game->print_operations = 1;
		parse_and_check(argv, game);
		push_swap(game);
	}
	exit (0);
}
