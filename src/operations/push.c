/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:12:37 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/07 18:56:28 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_game *game)
{
	ps_push(&game->stack_b, &game->tail_b, &game->stack_a, &game->tail_a);
	game->size_a++;
	game->size_b--;
	write(1, "pa\n", 3);
}

void	pb(t_game *game)
{
	ps_push(&game->stack_a, &game->tail_a, &game->stack_b, &game->tail_b);
	game->size_b++;
	game->size_a--;
	write(1, "pb\n", 3);
}
