/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 18:52:14 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/29 19:24:19 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int *tmp;

	*tmp = *a;
	*a = *b;
	*b = *tmp;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack *tmp;

	if (*src == NULL)
		return ;
	else if (*dest == NULL)
	{
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = NULL;
	}
	else 
	{
		tmp = *dest;
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = tmp;
	}
}

// void	rotate(t_game *game, char c)
// {
	
// }

// void	rev_rotate(t_stack **stack)
// {
// 	t_stack *tail;
// }
