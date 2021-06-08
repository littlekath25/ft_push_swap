/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:10:23 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/08 19:32:01 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ps_push(t_stack **src, t_stack **s_tail, \
t_stack **dest, t_stack **d_tail)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	else if ((*src)->next == NULL)
	{
		(*src)->next = *dest;
		*dest = *src;
		*src = NULL;
		*s_tail = NULL;
		return ;
	}
	tmp = *src;
	*src = (*src)->next;
	(*s_tail)->next = *src;
	if (*dest == NULL)
	{
		*dest = tmp;
		tmp->next = NULL;
		*d_tail = tmp;
		return ;
	}
	tmp->next = *dest;
	*dest = tmp;
	(*d_tail)->next = tmp;
}

void	ps_rotate(t_stack **stack, t_stack **tail)
{
	*stack = (*stack)->next;
	*tail = (*tail)->next;
}

void	ps_rev_rotate(t_stack **stack, t_stack **tail)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->next == *tail)
			break ;
		tmp = tmp->next;
	}
	*stack = *tail;
	*tail = tmp;
}
