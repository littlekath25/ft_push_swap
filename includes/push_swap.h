/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/23 16:01:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/23 19:11:37 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

/* UTILS */
void	error_and_exit(void);
int		*input_checker_parser(int argc, char **argv);

/* OPERATIONS */
void	swap(int *stack);
void	swap_both(int *stack_a, int *stack_b);
void	push(int *stack_a, int *stack_b);
void	rotate(int *stack);
void	rotate_both(int *stack_a, int *stack_b);
void	rev_rotate(int *stack);
void	rev_rotate_both(int *stack_a, int *stack_b);


#endif