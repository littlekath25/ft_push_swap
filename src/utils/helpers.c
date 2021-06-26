/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/29 17:15:12 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/26 13:41:56 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_all_digits(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(ft_isdigit(argv[i])))
		{
			if (i == 0 && argv[i] == '-' && ft_isdigit(argv[1]))
			{
				i++;
				continue ;
			}
			error_and_exit();
		}
		i++;
	}
	return ;
}

int	check_if_sorted(t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr->number < ptr->next->number)
	{
		ptr = ptr->next;
		if (ptr->next == stack)
			return (1);
	}
	return (0);
}

void	get_min_max(t_stack *stack, int *min, int *max, int size)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	*min = stack->number;
	*max = stack->number;
	ptr = stack;
	while (i < size)
	{
		if (ptr->number > *max)
			*max = ptr->number;
		if (ptr->number < *min)
			*min = ptr->number;
		ptr = ptr->next;
		i++;
	}
}
