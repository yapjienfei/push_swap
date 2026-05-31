/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:40:54 by user              #+#    #+#             */
/*   Updated: 2026/05/31 23:50:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_case_up(t_stack *a, t_stack *b, t_cost cost)
{
	int	common_rot;
	int	remaining_a;
	int	remaining_b;

	common_rot = cost.rot_b;
	if (cost.rot_a < cost.rot_b)
		common_rot = cost.rot_a;
	remaining_a = cost.rot_a - common_rot;
	remaining_b = cost.rot_b - common_rot;
	while (common_rot-- > 0)
		rr(a, b);
	while (remaining_a-- > 0)
		ra(a);
	while (remaining_b-- > 0)
		rb(b);
}

static void	execute_case_down(t_stack *a, t_stack *b, t_cost cost)
{
	int	rot_a;
	int	rot_b;
	int	common_rot;
	int	remaining_a;
	int	remaining_b;

	rot_a = -cost.rot_a;
	rot_b = -cost.rot_b;
	common_rot = rot_b;
	if (rot_a < rot_b)
		common_rot = rot_a;
	remaining_a = rot_a - common_rot;
	remaining_b = rot_b - common_rot;
	while (common_rot-- > 0)
		rrr(a, b);
	while (remaining_a-- > 0)
		rra(a);
	while (remaining_b-- > 0)
		rrb(b);
}

static void	execute_case_independent(t_stack *a, t_stack *b, t_cost cost)
{
	if (cost.rot_a > 0)
	{
		while (cost.rot_a-- > 0)
			ra(a);
	}
	else
	{
		while (cost.rot_a++ < 0)
			rra(a);
	}
	if (cost.rot_b > 0)
	{
		while (cost.rot_b-- > 0)
			rb(b);
	}
	else
	{
		while (cost.rot_b++ < 0)
			rrb(b);
	}
}

void	execute_rotations(t_stack *a, t_stack *b, t_cost cost)
{
	if (cost.method == CASE_UP_TOGETHER)
		execute_case_up(a, b, cost);
	else if (cost.method == CASE_DOWN_TOGETHER)
		execute_case_down(a, b, cost);
	else
		execute_case_independent(a, b, cost);
}
