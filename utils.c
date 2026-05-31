/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:41:01 by user              #+#    #+#             */
/*   Updated: 2026/05/31 20:12:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_stack	*init_stack(int capacity)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->arr = malloc(sizeof(int) * capacity);
	if (!s->arr)
	{
		free(s);
		return (NULL);
	}
	s->size = 0;
	s->capacity = capacity;
	return (s);
}

void	free_stack(t_stack *s)
{
	if (s)
	{
		if (s->arr)
			free(s->arr);
		free(s);
	}
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
