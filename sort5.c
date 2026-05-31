/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:08:19 by user              #+#    #+#             */
/*   Updated: 2026/05/31 20:52:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_insert_index(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (value < a->arr[i])
			break ;
		i++;
	}
	return (i);
}

static void	rotate_to_top(t_stack *a, int idx)
{
	int	up;
	int	down;

	up = idx;
	down = a->size - idx;
	if (up <= down)
	{
		while (up-- > 0)
			ra(a);
	}
	else
	{
		while (down-- > 0)
			rra(a);
	}
}

void	push_back(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->size > 0)
	{
		pos = find_insert_index(a, b->arr[0]);
		rotate_to_top(a, pos);
		pa(a, b);
	}
}

void	sort_push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
	{
		sa(a);
		return ;
	}
	else if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	else if (a->size == 5)
	{
		sort_five(a, b);
		return ;
	}
	pb(a, b);
	pb(a, b);
	push_all_but_three(a, b);
	sort_three(a);
	push_back(a, b);
}
