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
