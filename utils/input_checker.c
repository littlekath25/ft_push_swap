/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checker.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 16:11:43 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/23 17:31:32 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

static int		*fill_stack(int *dest, double *src, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dest[i] = (int)src[i];
		i++;
	}
	return (dest);
}

static void		is_all_digits(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (!(ft_isdigit(argv[i])))
		{
			if (i == 0 && argv[i] == '-' && ft_isdigit(argv[1]))
			{
				i++;
				continue;
			}
			error_and_exit();
		}
		i++;
	}
	return ;
}

int		*input_checker_parser(int argc, char **argv)
{
	int		i;
	int		j;
	int		*stack_a;
	double 	digits[argc - 1];

	i = 1;
	j = 0;
	while (argv[i])
	{
		is_all_digits(argv[i]);
		digits[j] = ft_atof(argv[i]);
		if (digits[j] > INT_MAX || digits[j] < INT_MIN)
			error_and_exit();
		i++;
		j++;
	}
	stack_a = (int *)ft_calloc(argc, sizeof(int));
	stack_a = fill_stack(stack_a, digits, (argc - 1));
	return (stack_a);
}