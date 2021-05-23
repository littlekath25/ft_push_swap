/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checker.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 16:11:43 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/23 19:39:56 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_duplicates(int *stack, int len)
{
	int i;
	int j;

	i = 0;
	while(i < len)
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

static void	is_all_digits(char *argv)
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

void	input_checker_parser(int argc, char **argv, t_game *game)
{
	int		i;
	int		j;
	double 	digits[argc];

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
	game->stack_a = (int *)ft_calloc(argc, sizeof(int));
	game->stack_a = fill_stack(game->stack_a, digits, game->size);
	check_duplicates(game->stack_a, game->size);
}