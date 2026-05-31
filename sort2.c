/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:40:54 by user              #+#    #+#             */
/*   Updated: 2026/05/31 19:58:21 by user             ###   ########.fr       */
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

void	execute_case_up(t_stack *a, t_stack *b, t_cost cost)
{
	int	common_rot;

	common_rot = cost.rot_b;
	if (cost.rot_a < cost.rot_b)
		common_rot = cost.rot_a;
	while (common_rot--)
		rr(a, b);
	while (cost.rot_a-- > common_rot)
		ra(a);
	while (cost.rot_b-- > common_rot)
		rb(b);
}

static void	execute_case_down(t_stack *a, t_stack *b, t_cost cost)
{
	int	rot_a;
	int	rot_b;
	int	common_rot;

	rot_a = -cost.rot_a;
	rot_b = -cost.rot_b;
	common_rot = rot_b;
	if (rot_a < rot_b)
		common_rot = rot_a;
	while (common_rot--)
		rrr(a, b);
	rot_a -= common_rot;
	rot_b -= common_rot;
	while (rot_a--)
		rra(a);
	while (rot_b--)
		rrb(b);
}

void	execute_rotations(t_stack *a, t_stack *b, t_cost cost)
{
	if (cost.method == CASE_UP_TOGETHER)
		execute_case_up(a, b, cost);
	else if (cost.method == CASE_DOWN_TOGETHER)
		execute_case_down(a, b, cost);
	else
	{
		while (cost.rot_a-- > 0)
			ra(a);
		while (cost.rot_a++ < 0)
			rra(a);
		while (cost.rot_b-- > 0)
			rb(b);
		while (cost.rot_b++ < 0)
			rrb(b);
	}
}
