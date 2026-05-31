/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:40:48 by user              #+#    #+#             */
/*   Updated: 2026/05/31 20:42:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static int	parse_arguments(int argc, char **argv, int **temp_out)
{
	int	*temp;
	int	i;

	temp = malloc(sizeof(int) * (argc - 1));
	if (!temp)
	{
		print_error();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!parse_int(argv[i], &temp[i - 1]))
		{
			free(temp);
			print_error();
			return (0);
		}
		i++;
	}
	*temp_out = temp;
	return (1);
}

static int	check_duplicates(int *temp, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (temp[i] == temp[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static t_stack	*build_stack_from_temp(int *temp, int size)
{
	t_stack	*a;
	int		j;

	a = init_stack(size);
	if (!a)
		return (NULL);
	j = 0;
	while (j < size)
	{
		a->arr[a->size++] = temp[j];
		j++;
	}
	return (a);
}

static int	init_and_sort(int *temp, int size)
{
	t_stack	*a;
	t_stack	*b;

	a = build_stack_from_temp(temp, size);
	if (!a)
		return (0);
	b = init_stack(size);
	if (!b)
	{
		free_stack(a);
		return (0);
	}
	sort_push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return (1);
}

int	main(int argc, char **argv)
{
	int	*temp;

	if (argc < 2)
		return (0);
	if (!parse_arguments(argc, argv, &temp))
		return (1);
	if (!check_duplicates(temp, argc - 1))
	{
		free(temp);
		print_error();
		return (1);
	}
	if (!init_and_sort(temp, argc - 1))
	{
		free(temp);
		print_error();
		return (1);
	}
	free(temp);
	return (0);
}
