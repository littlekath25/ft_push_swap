/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/26 22:40:25 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/28 10:26:25 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_operation(t_game *game, char *operation)
{
	if (!(ft_strcmp(operation, "sa")))
		sa(game);
	else if (!(ft_strcmp(operation, "sb")))
		sb(game);
	else if (!(ft_strcmp(operation, "ss")))
		ss(game);
	else if (!(ft_strcmp(operation, "pa")))
		pa(game);
	else if (!(ft_strcmp(operation, "pb")))
		pb(game);
	else if (!(ft_strcmp(operation, "ra")))
		ra(game);
	else if (!(ft_strcmp(operation, "rb")))
		rb(game);
	else if (!(ft_strcmp(operation, "rr")))
		rr(game);
	else if (!(ft_strcmp(operation, "rra")))
		rra(game);
	else if (!(ft_strcmp(operation, "rrb")))
		rrb(game);
	else if (!(ft_strcmp(operation, "rrr")))
		rrr(game);
	else
		error_and_exit();
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*operation;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	init_game(game, argc);
	if (argc == 2)
		is_all_digits(argv[1]);
	if (argc > 2)
	{
		parse_and_check(argv, game);
		while (get_next_line(STDIN_FILENO, &operation))
		{
			execute_operation(game, operation);
			free(operation);
		}
		if (game->stack_b == NULL && check_if_sorted(game->stack_a) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free(game);
	exit (0);
}
