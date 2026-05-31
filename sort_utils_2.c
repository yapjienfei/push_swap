/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:40:56 by user              #+#    #+#             */
/*   Updated: 2026/06/01 00:30:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_but_three(t_stack *a, t_stack *b)
{
	t_cost	cost;

	while (a->size > 3)
	{
		find_cheapest(a, b, &cost);
		execute_rotations(a, b, cost);
		pb(a, b);
	}
}

void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->arr[0];
	y = a->arr[1];
	z = a->arr[2];
	if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > z && z > y)
		ra(a);
	else if (y > x && x > z)
		rra(a);
	else if (y > z && z > x)
	{
		rra(a);
		sa(a);
	}
	else if (z > x && x > y)
		sa(a);
}

int	find_min_index(t_stack *s)
{
	int	i;
	int	min_idx;

	i = 1;
	min_idx = 0;
	while (i < s->size)
	{
		if (s->arr[i] < s->arr[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_idx;

	while (a->size > 3)
	{
		min_idx = find_min_index(a);
		if (min_idx == 0)
			pb(a, b);
		else if (min_idx <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
	sort_three(a);
	push_back(a, b);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
