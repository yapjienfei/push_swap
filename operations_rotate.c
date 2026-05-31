/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:40:43 by user              #+#    #+#             */
/*   Updated: 2026/05/31 21:51:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size < 2)
		return ;
	tmp = s->arr[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->arr[i] = s->arr[i + 1];
		i++;
	}
	s->arr[s->size - 1] = tmp;
}

void	ra(t_stack *a)
{
	rotate_stack(a);
	print_op("ra");
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	print_op("rb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	print_op("rr");
}
