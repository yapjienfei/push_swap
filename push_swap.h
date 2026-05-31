/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:43:06 by user              #+#    #+#             */
/*   Updated: 2026/05/31 23:16:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	capacity;
}	t_stack;

typedef enum e_case
{
	CASE_UP_TOGETHER,
	CASE_DOWN_TOGETHER,
	CASE_INDEPENDENT
}	t_case;

typedef struct s_cost
{
	int		rot_a;
	int		rot_b;
	int		total;
	t_case	method;
}	t_cost;

//Initialization and utils
t_stack	*init_stack(int capacity);
void	free_stack(t_stack *s);
int		is_sorted(t_stack *a);
void	print_error(void);
int		parse_int(const char *str, int *out);
int		has_duplicate(t_stack *a, int value);

//Operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//Sort Utils
int		get_target_in_b(t_stack *b, int val);
t_cost	case_up_together(int a_up, int b_up);
t_cost	case_down_together(int a_up, int b_up);
t_cost	case_independent(int a_up, int a_down, int b_up, int b_down);
t_cost	calculate_cost(t_stack *a, t_stack *b, int a_idx, int target);
int		find_cheapest(t_stack *a, t_stack *b, t_cost *best_cost);
void	push_all_but_three(t_stack *a, t_stack *b);

int		error_and_free(int *temp);
void	sort_push_swap(t_stack *a, t_stack *b);
void	print_op(char *op);
void	execute_rotations(t_stack *a, t_stack *b, t_cost cost);
void	push_back(t_stack *a, t_stack *b);
int		find_min_index(t_stack *s);

void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

#endif
