/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:40:51 by user              #+#    #+#             */
/*   Updated: 2026/05/31 20:41:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	case_up_together(int a_up, int b_up)
{
	t_cost	cost;

	cost.rot_a = a_up;
	cost.rot_b = b_up;
	cost.total = b_up + 1;
	if (a_up > b_up)
		cost.total = a_up + 1;
	cost.method = CASE_UP_TOGETHER;
	return (cost);
}

t_cost	case_down_together(int a_down, int b_down)
{
	t_cost	cost;

	cost.rot_a = -a_down;
	cost.rot_b = -b_down;
	cost.total = b_down + 1;
	if (a_down > b_down)
		cost.total = a_down + 1;
	cost.method = CASE_DOWN_TOGETHER;
	return (cost);
}

t_cost	case_independent(int a_up, int a_down, int b_up, int b_down)
{
	t_cost	cost;

	cost.total = 0;
	if (a_up <= a_down)
	{
		cost.rot_a = a_up;
		cost.total += a_up;
	}
	else
	{
		cost.rot_a = -a_down;
		cost.total += a_down;
	}
	if (b_up <= b_down)
	{
		cost.rot_b = b_up;
		cost.total += b_up;
	}
	else
	{
		cost.rot_b = -b_down;
		cost.total += b_down;
	}
	cost.method = CASE_INDEPENDENT;
	return (cost);
}
