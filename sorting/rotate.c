/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:12:41 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/03 14:36:31 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_game *game)
{
	ps_rotate(&game->stack_a, &game->tail_a);	
}

void	rb(t_game *game)
{
	ps_rotate(&game->stack_b, &game->tail_b);	
}

void	rr(t_game *game)
{
	ps_rotate(&game->stack_a, &game->tail_a);
	ps_rotate(&game->stack_b, &game->tail_b);
}