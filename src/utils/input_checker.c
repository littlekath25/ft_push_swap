/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checker.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 16:11:43 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/15 19:26:29 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(double *digits, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size_a)
	{
		node_addback(&game->stack_a, new_node(digits[i]), &game->tail_a);
		i++;
	}
}

static void	check_duplicates(double *stack, int len)
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

static void	is_all_digits(char *argv)
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

void	parse_and_check(char **argv, t_game *game)
{
	int		i;
	int		j;
	double	digits[game->size_a];

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
	check_duplicates(digits, game->size_a);
	init_stack(digits, game);
}
