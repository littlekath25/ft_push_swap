/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 15:52:36 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/11 18:15:55 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_game(t_game *game, int argc)
{
	game->size_a = argc - 1;
	game->size_b = 0;
	game->stack_a = NULL;
	game->stack_b = NULL;
	game->tail_a = NULL;
	game->tail_b = NULL;
}

int	check_if_sorted(t_stack *stack, t_stack *tail)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr->number > ptr->next->number)
	{
		ptr = ptr->next;
		if (ptr->next == stack)
			return (1);
	}
	return (0);
}

void	push_swap(t_game *game)
{
	t_stack *stacka;
	t_stack *stackb;

	stacka = game->stack_a;
	stackb = game->stack_b;
	push_swap(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

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
