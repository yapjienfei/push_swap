/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:51:10 by user              #+#    #+#             */
/*   Updated: 2026/05/31 23:51:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
