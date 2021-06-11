/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/29 17:15:12 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/11 17:17:21 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_game *game)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	ptr_a = game->stack_a;
	ptr_b = game->stack_b;
	while (ptr_a)
	{
		if (ptr_a == game->tail_a)
		{
			printf("T: %i\n", game->tail_a->number);
			break ;
		}
		printf("N: %i\n", ptr_a->number);
		ptr_a = ptr_a->next;
	}
	printf("--------------\n");
	while (ptr_b)
	{
		if (ptr_b == game->tail_b)
		{
			printf("T: %i\n", game->tail_b->number);
			break ;
		}
		printf("N: %i\n", ptr_b->number);
		ptr_b = ptr_b->next;
	}
}
