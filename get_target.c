/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:08:17 by user              #+#    #+#             */
/*   Updated: 2026/06/01 00:28:40 by user             ###   ########.fr       */
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

t_cost	calculate_cost(t_stack *a, t_stack *b, int a_idx, int target)
{
	int		a_down;
	int		b_down;
	t_cost	best;
	t_cost	cur;

	a_down = a->size - a_idx;
	b_down = b->size - target;
	best = case_up_together(a_idx, target);
	cur = case_down_together(a_down, b_down);
	if (cur.total < best.total)
		best = cur;
	cur = case_independent(a_idx, a_down, target, b_down);
	if (cur.total < best.total)
		best = cur;
	return (best);
}

int	find_cheapest(t_stack *a, t_stack *b, t_cost *best_cost)
{
	int		i;
	int		target;
	t_cost	cost;
	int		best_idx;

	i = 0;
	best_idx = -1;
	best_cost->total = INT_MAX;
	while (i < a->size)
	{
		target = get_target_in_b(b, a->arr[i]);
		cost = calculate_cost(a, b, i, target);
		if (cost.total < best_cost->total)
		{
			*best_cost = cost;
			best_idx = i;
		}
		i++;
	}
	return (best_idx);
}
