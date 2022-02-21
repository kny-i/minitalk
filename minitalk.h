#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <signal.h>

size_t	ft_strlen(char *str)；
int		ft_putchar_fd(char c, int fd)；
void	ft_putstr_fd(char *str, int fd)；
void	ft_putnbr_fd(int nbr, int fd)；
int		ft_atoi(const char *str)；

typedef struct s_signal
{
	pid_t	count_shift;
	pid_t	ans;
}	t_signal;

#endif