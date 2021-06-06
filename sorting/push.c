/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:12:37 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/03 14:36:44 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_game *game)
{
	ps_push(&game->stack_b, &game->tail_b, &game->stack_a, &game->tail_a);
	game->size_a++;
	game->size_b--;
}

void	pb(t_game *game)
{
	ps_push(&game->stack_a, &game->tail_a, &game->stack_b, &game->tail_b);
	game->size_b++;
	game->size_a--;
}
