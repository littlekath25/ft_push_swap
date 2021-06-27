/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:12:37 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/27 12:39:19 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_game *game)
{
	if (game->size_b == 0)
		return ;
	ps_push(&game->stack_b, &game->tail_b, &game->stack_a, &game->tail_a);
	game->size_a++;
	game->size_b--;
	if (game->print_operations)
		write(1, "pa\n", 3);
	if (game->size_b == 0)
	{
		game->stack_b = NULL;
		game->tail_b = NULL;
	}
	game->operations++;
}

void	pb(t_game *game)
{
	if (game->size_a == 0)
		return ;
	ps_push(&game->stack_a, &game->tail_a, &game->stack_b, &game->tail_b);
	game->size_b++;
	game->size_a--;
	if (game->size_a == 0)
	{
		game->stack_a = NULL;
		game->tail_a = NULL;
	}
	if (game->print_operations)
		write(1, "pb\n", 3);
	game->operations++;
}
