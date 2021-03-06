/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_and_check.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 16:11:43 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/28 14:39:18 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stacka(double *digits, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size_a)
	{
		node_addback(&game->stack_a, new_node(digits[i]), &game->tail_a);
		i++;
	}
}

void	check_duplicates(double *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (stack[i] == stack[j] && i != j)
				error_and_exit();
			j++;
		}
		i++;
	}
}

void	parse_and_check(char **argv, t_game *game)
{
	int		i;
	int		j;
	double	*digits;

	i = 1;
	j = 0;
	digits = (double *)ft_calloc(sizeof(double), game->size_a);
	if (!digits)
		error_and_exit();
	while (argv[i])
	{
		if (!*argv[i])
			error_and_exit();
		is_all_digits(argv[i]);
		digits[j] = ft_atof(argv[i]);
		if (digits[j] > INT_MAX || digits[j] < INT_MIN)
			error_and_exit();
		i++;
		j++;
	}
	check_duplicates(digits, game->size_a);
	create_stacka(digits, game);
	free(digits);
}
