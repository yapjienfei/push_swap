/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:41:01 by user              #+#    #+#             */
/*   Updated: 2026/06/01 00:22:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

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

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void	print_op(char *op)
{
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);
}
