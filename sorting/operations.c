/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 18:52:14 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/26 15:01:49 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(t_stack *stack)
{
	int	tmp;
	
	tmp = stack->next->number;
	stack->next->number = stack->number;
	stack->number = tmp;
}

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (*stack_1 == NULL)
		return ;
	if (*stack_2 == NULL)
	{
		*stack_2 = *stack_1;
		*stack_1 = (*stack_1)->next;
		(*stack_2)->next = NULL;
	}
	else
	{
		tmp = *stack_2;
		*stack_2 = *stack_1;
		*stack_1 = (*stack_1)->next;
		(*stack_2)->next = tmp;
	}
}

// void	rotate(t_stack *stack)
// {
	
// }

// void	rev_rotate(t_stack *stack)
// {
	
// }