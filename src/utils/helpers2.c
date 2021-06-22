/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 14:57:17 by katherine     #+#    #+#                 */
/*   Updated: 2021/06/22 15:49:44 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_info(t_medium_info *info)
{
	info->chunk_number = 1;
	info->first_pos = -1;
	info->second_pos = -1;
}

void	calculate_chunk(t_medium_info *info, int total)
{
	info->chunk = (total / 5) * info->chunk_number;
	info->chunk_number++;
}
