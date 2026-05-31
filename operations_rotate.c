#include "push_swap.h"

void	ra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->size < 2)
		return ;
	tmp = a->arr[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->size - 1] = tmp;
	print_op("ra");
}

void	rb(t_stack *b)
{
	int	tmp;
	int	i;

	if (b->size < 2)
		return ;
	tmp = b->arr[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->size - 1] = tmp;
	print_op("rb");
}

void	rr(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	if (a->size >= 2)
	{
		tmp = a->arr[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->arr[i] = a->arr[i + 1];
			i++;
		}
		a->arr[a->size - 1] = tmp;
	}
	if (b->size >= 2)
	{
		tmp = b->arr[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->arr[i] = b->arr[i + 1];
			i++;
		}
		b->arr[b->size - 1] = tmp;
	}
	print_op("rr");
}
