/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 20:13:58 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/03 13:53:49 by kfu           ########   odam.nl         */
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
	new->next = NULL;
	return (new);
}

void	*node_addback(t_stack **stack, t_stack *new, t_stack **tail)
{
	t_stack *ptr;

	ptr = *stack;
	if (ptr != NULL)
	{
		while (ptr->next != *stack)
			ptr = ptr->next;
		ptr->next = new;
		new->next = *stack;
		*tail = new;
	}
	else
	{
		*stack = new;
		(*stack)->next = *stack;
	}
		
}