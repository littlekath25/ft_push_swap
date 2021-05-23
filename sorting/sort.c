/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 15:52:36 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/23 18:56:24 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int		main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	if (argc > 1)
	{
		stack_a = input_checker_parser(argc, argv);
		stack_b = (int *)ft_calloc(argc, sizeof(int));
		exit(0);
	}
	error_and_exit();
}