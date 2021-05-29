/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 18:52:14 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/29 16:30:54 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(t_game *game, char c)
{
	t_stack *first;
	t_stack *second;

	if (c == 'a' || c == 'b')
	{
		if (c == 'a')
			first = game->stack_a;
		if (c == 'b')
			first = game->stack_b;
		second = first->next;
		first->previous = second;
		first->next = first->next->next;
		second->previous = NULL;
		second->next = first;
		game->stack_a = second;
	}
}

void	push(t_game *game, char c)
{
	
}

void	rotate(t_game *game, char c)
{

}
