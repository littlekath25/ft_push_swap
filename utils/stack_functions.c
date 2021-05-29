/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 20:13:58 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/29 19:37:48 by kfu           ########   odam.nl         */
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
	t_stack	*start;

	start = *stack;
	if (start != NULL)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new;
	}
	else
		*stack = new;
}