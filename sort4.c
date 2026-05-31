/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:08:17 by user              #+#    #+#             */
/*   Updated: 2026/05/31 23:16:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_largest_smaller(t_stack *b, int val, int *index)
{
	int	i;
	int	best_diff;
	int	found;

	found = 0;
	best_diff = INT_MAX;
	i = 0;
	while (i < b->size)
	{
		if (b->arr[i] < val && (val - b->arr[i]) < best_diff)
		{
			best_diff = val - b->arr[i];
			*index = i;
			found = 1;
		}
		i++;
	}
	return (found);
}

static int	find_largest_overall(t_stack *b)
{
	int	i;
	int	max_idx;

	max_idx = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->arr[i] > b->arr[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

int	get_target_in_b(t_stack *b, int val)
{
	int	idx;

	if (b->size == 0)
		return (-1);
	if (find_largest_smaller(b, val, &idx))
		return (idx);
	return (find_largest_overall(b));
}
