#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int		*arr;
	int		size;
	int		capacity;
}	t_stack;

//Initialization and utils
t_stack	*init_stack(int capacity);
void	free_stack(t_stack *s);
int		is_sorted(t_stack *a);
void	print_error(void);
long	parse_int(const char *str, int *out);
int     has_duplicate(t_stack *a, int value);

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

#endif
