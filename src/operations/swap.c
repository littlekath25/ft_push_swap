/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:12:59 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/27 12:39:36 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_game *game)
{
	ps_swap(&game->stack_a->number, &game->stack_a->next->number);
	if (game->print_operations)
		write(1, "sa\n", 3);
	game->operations++;
}

void	sb(t_game *game)
{
	ps_swap(&game->stack_b->number, &game->stack_b->next->number);
	if (game->print_operations)
		write(1, "sb\n", 3);
	game->operations++;
}

void	ss(t_game *game)
{
	ps_swap(&game->stack_a->number, &game->stack_a->next->number);
	ps_swap(&game->stack_b->number, &game->stack_b->next->number);
	if (game->print_operations)
		write(1, "ss\n", 3);
	game->operations++;
}
