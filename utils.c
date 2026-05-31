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

int	parse_int(const char *str, int *out)
{
	long        num;
	int			sign;
	int			digit;

	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	// Must have at least one digit
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		// Check overflow before multiplying (using INT_MAX/10 and INT_MIN/10)
		if (sign == 1)
		{
			if (num > (INT_MAX - digit) / 10)
				return (0);
			num = num * 10 + digit;
		}
		else
		{
			if (-num < (INT_MIN + digit) / 10)
				return (0);
			num = num * 10 + digit;
		}
		str++;
	}
	// No extra characters allowed
	if (*str != '\0')
		return (0);
	num *= sign;
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (out)
		*out = (int)num;
	return (1);
}

int	has_duplicate(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}