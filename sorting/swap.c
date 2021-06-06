/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:12:59 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/03 14:49:02 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_game *game)
{
	ps_swap(&game->stack_a->number, &game->stack_a->next->number);
}

void	sb(t_game *game)
{
	ps_swap(&game->stack_b->number, &game->stack_b->next->number);
}

void	ss(t_game *game)
{
	ps_swap(&game->stack_a->number, &game->stack_a->next->number);
	ps_swap(&game->stack_b->number, &game->stack_b->next->number);
}
