/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:13:19 by user              #+#    #+#             */
/*   Updated: 2026/05/31 20:43:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_and_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || **str == '\t' || **str == '\n')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	parse_digits(const char **str, int sign, long *num)
{
	int	digit;

	*num = 0;
	if (!(**str >= '0' && **str <= '9'))
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		digit = **str - '0';
		if (sign == 1)
		{
			if (*num > (INT_MAX - digit) / 10)
				return (0);
			*num = *num * 10 + digit;
		}
		else
		{
			if (-*num < (INT_MIN + digit) / 10)
				return (0);
			*num = *num * 10 + digit;
		}
		(*str)++;
	}
	return (1);
}

int	parse_int(const char *str, int *out)
{
	int		sign;
	long	num;

	sign = skip_and_sign(&str);
	if (!parse_digits(&str, sign, &num))
		return (0);
	if (*str != '\0')
		return (0);
	num *= sign;
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (out)
		*out = (int)num;
	return (1);
}

int	error_and_free(int *temp)
{
	free(temp);
	print_error();
	return (1);
}
