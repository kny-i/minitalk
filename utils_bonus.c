#include "minitalk_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

void	ft_putstr_fd(char *str, int fd)
{
	ssize_t	i;

	if (!str)
		return ;
	i = write(fd, str, ft_strlen(str));
	if (i == -1)
		return ;
}

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == INT_MIN)
		ft_putstr_fd("-2147483648", fd);
	else if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	res;

	num = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
					|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		num = -1;
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (*str && '0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * num);
}
