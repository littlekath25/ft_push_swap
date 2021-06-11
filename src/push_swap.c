/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 15:52:36 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/11 17:59:57 by kfu           ########   odam.nl         */
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
	while (ptr->number < ptr->next->number)
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
	if (stacka == NULL)
		return ;
	if (stacka->number < stacka->next->number)
		sa(game);
	if (stacka->number < game->tail_a->number)
		ra(game);
	pb(game);
	if (game->size_b > 1)
	{
		if (stackb->number < stackb->next->number)
			sb(game);
		if (game->tail_b->number < stackb->number)
			rrb(game);
	}
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
