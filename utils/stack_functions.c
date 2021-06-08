/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 20:13:58 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/08 12:53:19 by kfu           ########   odam.nl         */
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

void	*node_addfront(t_stack **stack, t_stack *new, t_stack **tail)
{
	t_stack	*ptr;

	ptr = *stack;
	if (ptr != NULL)
	{
		new->next = *stack;
		*stack = new;
		if (!*tail)
			*tail = ptr;
		else
			*stack = new;
		(*tail)->next = *stack;
	}
	else
		*stack = new;
}
