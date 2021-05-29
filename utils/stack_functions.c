/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 20:13:58 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/29 16:37:11 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->number = number;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	node_addback(t_stack **stack, t_stack *new, t_game *game)
{
	t_stack	*node;

	node = *stack;
	if (node != NULL)
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
		new->previous = node;
	}
	else
		*stack = new;
}
