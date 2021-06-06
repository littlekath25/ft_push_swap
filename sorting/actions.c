/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:10:23 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/03 14:53:15 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ps_push(t_stack **src, t_stack **s_tail, t_stack **dest, t_stack **d_tail)
{
	t_stack *tmp;

	if (*src == NULL)
		return ;
	if (*dest == NULL)
	{
		tmp = *src;
		*src = (*src)->next;
		(*s_tail)->next = *src;
		*dest = tmp;
		tmp->next = NULL;
		*d_tail = tmp;
	}
	else
	{
		tmp = *src;
		*src = (*src)->next;
		(*s_tail)->next = *src;
		tmp->next = *dest;
		*dest = tmp;
		(*d_tail)->next = tmp;
	}
}

void	ps_rotate(t_stack **stack, t_stack **tail)
{
	*stack = (*stack)->next;
	*tail = (*tail)->next;
}

void	ps_rev_rotate(t_stack **stack, t_stack **tail)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->next == *tail)
			break;
		tmp = tmp->next;
	}
	*stack = *tail;
	*tail = tmp;
}