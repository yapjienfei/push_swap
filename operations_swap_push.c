#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
	print_op("sa");
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = tmp;
	print_op("sb");
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->size >= 2)
	{
		tmp = a->arr[0];
		a->arr[0] = a->arr[1];
		a->arr[1] = tmp;
	}
	if (b->size >= 2)
	{
		tmp = b->arr[0];
		b->arr[0] = b->arr[1];
		b->arr[1] = tmp;
	}
	print_op("ss");
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = b->arr[0];
	a->size++;
	i = 0;
	while (i < b->size - 1)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->size--;
	print_op("pa");
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[0] = a->arr[0];
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->size--;
	print_op("pb");
}
