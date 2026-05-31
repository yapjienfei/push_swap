/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:40:59 by user              #+#    #+#             */
/*   Updated: 2026/05/31 20:10:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
